// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_ReferenceBank.h"
#include "Vtb__Syms.h"

VL_ATTR_COLD void Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__12(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__12\n"); );
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
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_14)
                              ? vlSelfRef.__PVT__bucketFirstStore_14_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_14)
                               ? vlSelfRef.__PVT__bucketFirstStore_14_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__currentFirstStoreNextWide_56[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_56[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_56[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_14)
                              ? vlSelfRef.__PVT__bucketFirstStore_14_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_14)
                               ? vlSelfRef.__PVT__bucketFirstStore_14_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__currentFirstStoreNextWide_57[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_57[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_57[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_14)
                               ? vlSelfRef.__PVT__bucketFirstStore_14_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_14)
                                ? vlSelfRef.__PVT__bucketFirstStore_14_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__currentFirstStoreNextWide_58[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_58[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_58[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_14)
                               ? vlSelfRef.__PVT__bucketFirstStore_14_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_14)
                                ? vlSelfRef.__PVT__bucketFirstStore_14_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__currentFirstStoreNextWide_59[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_59[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_59[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.bucketValid_15)
                               ? vlSelfRef.bucketFirstStore_15_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.bucketValid_15)
                                ? vlSelfRef.bucketFirstStore_15_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__currentFirstStoreNextWide_60[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_60[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_60[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.bucketValid_15)
                               ? vlSelfRef.bucketFirstStore_15_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.bucketValid_15)
                                ? vlSelfRef.bucketFirstStore_15_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__currentFirstStoreNextWide_61[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_61[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_61[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.bucketValid_15)
                               ? vlSelfRef.bucketFirstStore_15_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.bucketValid_15)
                                ? vlSelfRef.bucketFirstStore_15_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__currentFirstStoreNextWide_62[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_62[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_62[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.bucketValid_15)
                               ? vlSelfRef.bucketFirstStore_15_3
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.bucketValid_15)
                                ? vlSelfRef.bucketFirstStore_15_3
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__currentFirstStoreNextWide_63[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_63[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_63[2U] 
        = (1U & __Vtemp_32[2U]);
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
}

VL_ATTR_COLD void Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__13(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__13\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

VL_ATTR_COLD void Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__14(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__14\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

VL_ATTR_COLD void Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__15(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__15\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

VL_ATTR_COLD void Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__16(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__16\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
