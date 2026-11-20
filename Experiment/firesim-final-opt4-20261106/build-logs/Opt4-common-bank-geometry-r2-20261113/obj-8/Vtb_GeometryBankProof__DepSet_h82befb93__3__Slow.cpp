// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_GeometryBankProof.h"
#include "Vtb__Syms.h"

VL_ATTR_COLD void Vtb_GeometryBankProof___stl_sequent__TOP__tb__DOT__dut__DOT__candidate_2__8(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___stl_sequent__TOP__tb__DOT__dut__DOT__candidate_2__8\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                              ? vlSelfRef.__PVT__bucketFirstStore_6_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketFirstStore_6_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__currentFirstStoreNextWide_24[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_24[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_24[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                              ? vlSelfRef.__PVT__bucketFirstStore_6_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketFirstStore_6_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__currentFirstStoreNextWide_25[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_25[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_25[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketFirstStore_6_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                                ? vlSelfRef.__PVT__bucketFirstStore_6_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__currentFirstStoreNextWide_26[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_26[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_26[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketFirstStore_6_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                                ? vlSelfRef.__PVT__bucketFirstStore_6_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__currentFirstStoreNextWide_27[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_27[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_27[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketFirstStore_7_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketFirstStore_7_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__currentFirstStoreNextWide_28[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_28[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_28[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketFirstStore_7_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketFirstStore_7_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__currentFirstStoreNextWide_29[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_29[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_29[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketFirstStore_7_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketFirstStore_7_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__currentFirstStoreNextWide_30[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_30[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_30[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketFirstStore_7_3
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketFirstStore_7_3
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__currentFirstStoreNextWide_31[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_31[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_31[2U] 
        = (1U & __Vtemp_32[2U]);
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
}

VL_ATTR_COLD void Vtb_GeometryBankProof___stl_sequent__TOP__tb__DOT__dut__DOT__candidate_2__9(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___stl_sequent__TOP__tb__DOT__dut__DOT__candidate_2__9\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__resolving_7 = ((IData)(vlSelfRef.buckets_valid_7) 
                                    & (vlSelfRef.buckets_seq_7 
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
}

VL_ATTR_COLD void Vtb_GeometryBankProof___stl_sequent__TOP__tb__DOT__dut__DOT__candidate_3__0(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___stl_sequent__TOP__tb__DOT__dut__DOT__candidate_3__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___buckets_count_0_T_1 = (1ULL + vlSelfRef.buckets_count_0);
    vlSelfRef.__PVT___buckets_count_1_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_1);
    vlSelfRef.__PVT___buckets_count_2_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_2);
    vlSelfRef.__PVT___buckets_count_3_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_3);
    vlSelfRef.__PVT___buckets_count_4_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_4);
    vlSelfRef.__PVT___buckets_count_5_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_5);
    vlSelfRef.__PVT___buckets_count_6_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_6);
    vlSelfRef.__PVT___buckets_count_7_T_1 = (1ULL + vlSelfRef.buckets_count_7);
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
                                   == (0xffU & ((IData)(0x18U) 
                                                + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_1 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(0x19U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_2 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(0x1aU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_3 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(0x1bU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_4 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(0x1cU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_5 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(0x1dU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_6 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(0x1eU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_7 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(0x1fU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__VdfgRegularize_h883887c0_0_634 = ((~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError)) 
                                                  & (IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance));
    vlSelfRef.__PVT__io_queryMatch_0_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_0 
                                                  - 
                                                  ((IData)(0x18U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_1_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_1 
                                                  - 
                                                  ((IData)(0x18U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_2_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_2 
                                                  - 
                                                  ((IData)(0x18U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_3_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_3 
                                                  - 
                                                  ((IData)(0x18U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_ATTR_COLD void Vtb_GeometryBankProof___stl_sequent__TOP__tb__DOT__dut__DOT__candidate_3__1(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___stl_sequent__TOP__tb__DOT__dut__DOT__candidate_3__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__io_queryMatch_4_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_4 
                                                  - 
                                                  ((IData)(0x18U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_5_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_5 
                                                  - 
                                                  ((IData)(0x18U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_6_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_6 
                                                  - 
                                                  ((IData)(0x18U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_7_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_7 
                                                  - 
                                                  ((IData)(0x18U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_8_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_8 
                                                  - 
                                                  ((IData)(0x18U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_9_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_9 
                                                  - 
                                                  ((IData)(0x18U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_10_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_10 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_11_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_11 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_12_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_12 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_13_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_13 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_14_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_14 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_15_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_15 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_16_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_16 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_17_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_17 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_18_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_18 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_19_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_19 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_20_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_20 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_21_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_21 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_22_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_22 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_23_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_23 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_ATTR_COLD void Vtb_GeometryBankProof___stl_sequent__TOP__tb__DOT__dut__DOT__candidate_3__2(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___stl_sequent__TOP__tb__DOT__dut__DOT__candidate_3__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__io_queryMatch_24_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_24 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_25_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_25 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_26_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_26 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_27_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_27 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_28_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_28 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_29_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_29 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_30_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_30 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_31_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_31 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_32_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_32 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_33_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_33 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_34_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_34 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_35_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_35 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_36_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_36 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_37_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_37 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_38_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_38 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_39_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_39 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_40_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_40 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_41_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_41 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_42_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_42 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_43_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_43 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_ATTR_COLD void Vtb_GeometryBankProof___stl_sequent__TOP__tb__DOT__dut__DOT__candidate_3__3(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___stl_sequent__TOP__tb__DOT__dut__DOT__candidate_3__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__io_queryMatch_44_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_44 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_45_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_45 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_46_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_46 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_47_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_47 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_48_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_48 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_49_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_49 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_50_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_50 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_51_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_51 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_52_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_52 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_53_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_53 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_54_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_54 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_55_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_55 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_56_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_56 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_57_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_57 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_58_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_58 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_59_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_59 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_60_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_60 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_61_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_61 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_62_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_62 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_63_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_63 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_ATTR_COLD void Vtb_GeometryBankProof___stl_sequent__TOP__tb__DOT__dut__DOT__candidate_3__4(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___stl_sequent__TOP__tb__DOT__dut__DOT__candidate_3__4\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__io_queryMatch_64_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_64 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_65_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_65 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_66_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_66 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_67_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_67 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_68_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_68 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_69_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_69 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_70_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_70 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_71_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_71 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_72_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_72 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_73_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_73 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_74_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_74 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_75_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_75 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_76_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_76 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_77_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_77 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_78_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_78 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_79_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_79 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
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
}

VL_ATTR_COLD void Vtb_GeometryBankProof___stl_sequent__TOP__tb__DOT__dut__DOT__candidate_3__5(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___stl_sequent__TOP__tb__DOT__dut__DOT__candidate_3__5\n"); );
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
    // Body
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
}

VL_ATTR_COLD void Vtb_GeometryBankProof___stl_sequent__TOP__tb__DOT__dut__DOT__candidate_3__8(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___stl_sequent__TOP__tb__DOT__dut__DOT__candidate_3__8\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                              ? vlSelfRef.__PVT__bucketFirstStore_6_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketFirstStore_6_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__currentFirstStoreNextWide_24[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_24[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_24[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                              ? vlSelfRef.__PVT__bucketFirstStore_6_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketFirstStore_6_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__currentFirstStoreNextWide_25[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_25[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_25[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketFirstStore_6_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                                ? vlSelfRef.__PVT__bucketFirstStore_6_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__currentFirstStoreNextWide_26[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_26[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_26[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketFirstStore_6_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                                ? vlSelfRef.__PVT__bucketFirstStore_6_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__currentFirstStoreNextWide_27[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_27[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_27[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketFirstStore_7_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketFirstStore_7_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__currentFirstStoreNextWide_28[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_28[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_28[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketFirstStore_7_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketFirstStore_7_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__currentFirstStoreNextWide_29[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_29[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_29[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketFirstStore_7_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketFirstStore_7_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__currentFirstStoreNextWide_30[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_30[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_30[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketFirstStore_7_3
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketFirstStore_7_3
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__currentFirstStoreNextWide_31[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_31[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_31[2U] 
        = (1U & __Vtemp_32[2U]);
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
    vlSelfRef.__PVT__isCurrent = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                  == (0xffU & ((IData)(0x18U) 
                                               + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_1 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(0x19U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_2 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(0x1aU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_3 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(0x1bU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_ATTR_COLD void Vtb_GeometryBankProof___stl_sequent__TOP__tb__DOT__dut__DOT__candidate_3__9(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___stl_sequent__TOP__tb__DOT__dut__DOT__candidate_3__9\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_4 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(0x1cU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_5 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(0x1dU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_6 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(0x1eU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_7 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(0x1fU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
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
    vlSelfRef.__PVT__resolving_7 = ((IData)(vlSelfRef.buckets_valid_7) 
                                    & (vlSelfRef.buckets_seq_7 
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
}
