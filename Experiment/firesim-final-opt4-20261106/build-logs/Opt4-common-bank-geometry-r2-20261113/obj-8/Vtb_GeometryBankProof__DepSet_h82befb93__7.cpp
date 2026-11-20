// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_GeometryBankProof.h"
#include "Vtb__Syms.h"

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_0__52(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_0__52\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_8;
    // Body
    __Vtemp_2[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_0_2);
    __Vtemp_2[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_0_2 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_4026;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__strictWriteReadNextWide_2[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_2[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_2[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_0_3);
    __Vtemp_6[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_0_3 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_4462;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__strictWriteReadNextWide_3[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_3[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_3[2U] 
        = (1U & __Vtemp_8[2U]);
    vlSelfRef.__PVT__allocate = ((~ (IData)(vlSelfRef.bucketValid_0)) 
                                 & (IData)(vlSelfRef.__PVT__isCurrent));
    vlSelfRef.__PVT___GEN_80 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                 & (IData)(vlSelfRef.__PVT__isCurrent)) 
                                | (IData)(vlSelfRef.bucketValid_0));
    vlSelfRef.io_currentCollision = (((IData)(vlSelfRef.__PVT__isCurrent) 
                                      & ((IData)(vlSelfRef.bucketValid_0) 
                                         & ((vlSelfRef.bucketSeq_0 
                                             >> 8U) 
                                            != (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                >> 8U)))) 
                                     | (((IData)(vlSelfRef.__PVT__isCurrent_1) 
                                         & ((IData)(vlSelfRef.__PVT__bucketValid_1) 
                                            & ((vlSelfRef.__PVT__bucketSeq_1 
                                                >> 8U) 
                                               != (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                   >> 8U)))) 
                                        | (((IData)(vlSelfRef.__PVT__isCurrent_2) 
                                            & ((IData)(vlSelfRef.__PVT__bucketValid_2) 
                                               & ((vlSelfRef.__PVT__bucketSeq_2 
                                                   >> 8U) 
                                                  != 
                                                  (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                   >> 8U)))) 
                                           | (((IData)(vlSelfRef.__PVT__isCurrent_3) 
                                               & ((IData)(vlSelfRef.__PVT__bucketValid_3) 
                                                  & ((vlSelfRef.__PVT__bucketSeq_3 
                                                      >> 8U) 
                                                     != 
                                                     (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                      >> 8U)))) 
                                              | (((IData)(vlSelfRef.__PVT__isCurrent_4) 
                                                  & ((IData)(vlSelfRef.__PVT__bucketValid_4) 
                                                     & ((vlSelfRef.__PVT__bucketSeq_4 
                                                         >> 8U) 
                                                        != 
                                                        (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                         >> 8U)))) 
                                                 | (((IData)(vlSelfRef.__PVT__isCurrent_5) 
                                                     & ((IData)(vlSelfRef.__PVT__bucketValid_5) 
                                                        & ((vlSelfRef.__PVT__bucketSeq_5 
                                                            >> 8U) 
                                                           != 
                                                           (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                            >> 8U)))) 
                                                    | (((IData)(vlSelfRef.__PVT__isCurrent_6) 
                                                        & ((IData)(vlSelfRef.__PVT__bucketValid_6) 
                                                           & ((vlSelfRef.__PVT__bucketSeq_6 
                                                               >> 8U) 
                                                              != 
                                                              (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                               >> 8U)))) 
                                                       | ((IData)(vlSelfRef.__PVT__isCurrent_7) 
                                                          & ((IData)(vlSelfRef.bucketValid_7) 
                                                             & ((vlSelfRef.bucketSeq_7 
                                                                 >> 8U) 
                                                                != 
                                                                (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                                 >> 8U)))))))))));
    vlSelfRef.__PVT___GEN_2193 = ((~ (IData)(vlSelfRef.__PVT__resolving_7)) 
                                  & (IData)(vlSelfRef.buckets_valid_7));
    vlSelfRef.__PVT___canAccept_T_22 = (1U & ((~ (IData)(vlSelfRef.buckets_valid_7)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_7)));
    vlSelfRef.__PVT___GEN_2163 = ((~ (IData)(vlSelfRef.__PVT__resolving_5)) 
                                  & (IData)(vlSelfRef.__PVT__buckets_valid_5));
    vlSelfRef.__PVT___canAccept_T_16 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_5)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_5)));
    vlSelfRef.__PVT___GEN_2148 = ((~ (IData)(vlSelfRef.__PVT__resolving_4)) 
                                  & (IData)(vlSelfRef.__PVT__buckets_valid_4));
    vlSelfRef.__PVT___canAccept_T_13 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_4)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_4)));
    vlSelfRef.__PVT___GEN_2178 = ((~ (IData)(vlSelfRef.__PVT__resolving_6)) 
                                  & (IData)(vlSelfRef.__PVT__buckets_valid_6));
    vlSelfRef.__PVT___canAccept_T_19 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_6)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_6)));
    vlSelfRef.__PVT___GEN_2088 = ((~ (IData)(vlSelfRef.__PVT__resolving_0)) 
                                  & (IData)(vlSelfRef.buckets_valid_0));
    vlSelfRef.__PVT___canAccept_T_1 = (1U & ((~ (IData)(vlSelfRef.buckets_valid_0)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_0)));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_0__53(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_0__53\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    // Body
    vlSelfRef.__PVT___GEN_2118 = ((~ (IData)(vlSelfRef.__PVT__resolving_2)) 
                                  & (IData)(vlSelfRef.__PVT__buckets_valid_2));
    vlSelfRef.__PVT___canAccept_T_7 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_2)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_2)));
    vlSelfRef.__PVT___GEN_2133 = ((~ (IData)(vlSelfRef.__PVT__resolving_3)) 
                                  & (IData)(vlSelfRef.__PVT__buckets_valid_3));
    vlSelfRef.__PVT___canAccept_T_10 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_3)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_3)));
    vlSelfRef.__PVT___GEN_2103 = ((~ (IData)(vlSelfRef.__PVT__resolving_1)) 
                                  & (IData)(vlSelfRef.__PVT__buckets_valid_1));
    vlSelfRef.__PVT___canAccept_T_4 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_1)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_1)));
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.bucketValid_0)
                              ? vlSelfRef.bucketStore_0_0__VforceRd
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.bucketValid_0)
                               ? vlSelfRef.bucketStore_0_0__VforceRd
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
    vlSelfRef.__PVT__available_7 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(7U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_22) 
                                       | (vlSelfRef.buckets_seq_7 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_5 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(5U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_4 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(4U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_6 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(6U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_0 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_2 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(2U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_3 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(3U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_1 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(1U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.io_overflow = (1U & ((vlSelfRef.__PVT__loadFirstNextWide_28[2U] 
                                    | (vlSelfRef.__PVT__storeFirstNextWide_28[2U] 
                                       | (vlSelfRef.__PVT__strictWriteReadNextWide_28[2U] 
                                          | (((IData)(vlSelfRef.__PVT__isCurrent_7) 
                                              & vlSelfRef.__PVT__currentStoreNextWide_28[2U]) 
                                             | (((IData)(vlSelfRef.__PVT__isCurrent_7) 
                                                 & vlSelfRef.__PVT__currentFirstStoreNextWide_28[2U]) 
                                                | (vlSelfRef.__PVT__loadFirstNextWide_29[2U] 
                                                   | (vlSelfRef.__PVT__storeFirstNextWide_29[2U] 
                                                      | (vlSelfRef.__PVT__strictWriteReadNextWide_29[2U] 
                                                         | (((IData)(vlSelfRef.__PVT__isCurrent_7) 
                                                             & vlSelfRef.__PVT__currentStoreNextWide_29[2U]) 
                                                            | (((IData)(vlSelfRef.__PVT__isCurrent_7) 
                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_29[2U]) 
                                                               | (vlSelfRef.__PVT__loadFirstNextWide_30[2U] 
                                                                  | (vlSelfRef.__PVT__storeFirstNextWide_30[2U] 
                                                                     | (vlSelfRef.__PVT__strictWriteReadNextWide_30[2U] 
                                                                        | (((IData)(vlSelfRef.__PVT__isCurrent_7) 
                                                                            & vlSelfRef.__PVT__currentStoreNextWide_30[2U]) 
                                                                           | (((IData)(vlSelfRef.__PVT__isCurrent_7) 
                                                                               & vlSelfRef.__PVT__currentFirstStoreNextWide_30[2U]) 
                                                                              | (vlSelfRef.__PVT__loadFirstNextWide_31[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_31[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_31[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent_7) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_31[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_31[2U])))))))))))))))))))) 
                                   | ((vlSelfRef.__PVT__loadFirstNextWide_24[2U] 
                                       | (vlSelfRef.__PVT__storeFirstNextWide_24[2U] 
                                          | (vlSelfRef.__PVT__strictWriteReadNextWide_24[2U] 
                                             | (((IData)(vlSelfRef.__PVT__isCurrent_6) 
                                                 & vlSelfRef.__PVT__currentStoreNextWide_24[2U]) 
                                                | (((IData)(vlSelfRef.__PVT__isCurrent_6) 
                                                    & vlSelfRef.__PVT__currentFirstStoreNextWide_24[2U]) 
                                                   | (vlSelfRef.__PVT__loadFirstNextWide_25[2U] 
                                                      | (vlSelfRef.__PVT__storeFirstNextWide_25[2U] 
                                                         | (vlSelfRef.__PVT__strictWriteReadNextWide_25[2U] 
                                                            | (((IData)(vlSelfRef.__PVT__isCurrent_6) 
                                                                & vlSelfRef.__PVT__currentStoreNextWide_25[2U]) 
                                                               | (((IData)(vlSelfRef.__PVT__isCurrent_6) 
                                                                   & vlSelfRef.__PVT__currentFirstStoreNextWide_25[2U]) 
                                                                  | (vlSelfRef.__PVT__loadFirstNextWide_26[2U] 
                                                                     | (vlSelfRef.__PVT__storeFirstNextWide_26[2U] 
                                                                        | (vlSelfRef.__PVT__strictWriteReadNextWide_26[2U] 
                                                                           | (((IData)(vlSelfRef.__PVT__isCurrent_6) 
                                                                               & vlSelfRef.__PVT__currentStoreNextWide_26[2U]) 
                                                                              | (((IData)(vlSelfRef.__PVT__isCurrent_6) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_26[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_27[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_27[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_27[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent_6) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_27[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_27[2U])))))))))))))))))))) 
                                      | ((vlSelfRef.__PVT__loadFirstNextWide_20[2U] 
                                          | (vlSelfRef.__PVT__storeFirstNextWide_20[2U] 
                                             | (vlSelfRef.__PVT__strictWriteReadNextWide_20[2U] 
                                                | (((IData)(vlSelfRef.__PVT__isCurrent_5) 
                                                    & vlSelfRef.__PVT__currentStoreNextWide_20[2U]) 
                                                   | (((IData)(vlSelfRef.__PVT__isCurrent_5) 
                                                       & vlSelfRef.__PVT__currentFirstStoreNextWide_20[2U]) 
                                                      | (vlSelfRef.__PVT__loadFirstNextWide_21[2U] 
                                                         | (vlSelfRef.__PVT__storeFirstNextWide_21[2U] 
                                                            | (vlSelfRef.__PVT__strictWriteReadNextWide_21[2U] 
                                                               | (((IData)(vlSelfRef.__PVT__isCurrent_5) 
                                                                   & vlSelfRef.__PVT__currentStoreNextWide_21[2U]) 
                                                                  | (((IData)(vlSelfRef.__PVT__isCurrent_5) 
                                                                      & vlSelfRef.__PVT__currentFirstStoreNextWide_21[2U]) 
                                                                     | (vlSelfRef.__PVT__loadFirstNextWide_22[2U] 
                                                                        | (vlSelfRef.__PVT__storeFirstNextWide_22[2U] 
                                                                           | (vlSelfRef.__PVT__strictWriteReadNextWide_22[2U] 
                                                                              | (((IData)(vlSelfRef.__PVT__isCurrent_5) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_22[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_5) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_22[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_23[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_23[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_23[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent_5) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_23[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_23[2U])))))))))))))))))))) 
                                         | ((vlSelfRef.__PVT__loadFirstNextWide_16[2U] 
                                             | (vlSelfRef.__PVT__storeFirstNextWide_16[2U] 
                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_16[2U] 
                                                   | (((IData)(vlSelfRef.__PVT__isCurrent_4) 
                                                       & vlSelfRef.__PVT__currentStoreNextWide_16[2U]) 
                                                      | (((IData)(vlSelfRef.__PVT__isCurrent_4) 
                                                          & vlSelfRef.__PVT__currentFirstStoreNextWide_16[2U]) 
                                                         | (vlSelfRef.__PVT__loadFirstNextWide_17[2U] 
                                                            | (vlSelfRef.__PVT__storeFirstNextWide_17[2U] 
                                                               | (vlSelfRef.__PVT__strictWriteReadNextWide_17[2U] 
                                                                  | (((IData)(vlSelfRef.__PVT__isCurrent_4) 
                                                                      & vlSelfRef.__PVT__currentStoreNextWide_17[2U]) 
                                                                     | (((IData)(vlSelfRef.__PVT__isCurrent_4) 
                                                                         & vlSelfRef.__PVT__currentFirstStoreNextWide_17[2U]) 
                                                                        | (vlSelfRef.__PVT__loadFirstNextWide_18[2U] 
                                                                           | (vlSelfRef.__PVT__storeFirstNextWide_18[2U] 
                                                                              | (vlSelfRef.__PVT__strictWriteReadNextWide_18[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_4) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_18[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_4) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_18[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_19[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_19[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_19[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent_4) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_19[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_19[2U])))))))))))))))))))) 
                                            | ((vlSelfRef.__PVT__loadFirstNextWide_12[2U] 
                                                | (vlSelfRef.__PVT__storeFirstNextWide_12[2U] 
                                                   | (vlSelfRef.__PVT__strictWriteReadNextWide_12[2U] 
                                                      | (((IData)(vlSelfRef.__PVT__isCurrent_3) 
                                                          & vlSelfRef.__PVT__currentStoreNextWide_12[2U]) 
                                                         | (((IData)(vlSelfRef.__PVT__isCurrent_3) 
                                                             & vlSelfRef.__PVT__currentFirstStoreNextWide_12[2U]) 
                                                            | (vlSelfRef.__PVT__loadFirstNextWide_13[2U] 
                                                               | (vlSelfRef.__PVT__storeFirstNextWide_13[2U] 
                                                                  | (vlSelfRef.__PVT__strictWriteReadNextWide_13[2U] 
                                                                     | (((IData)(vlSelfRef.__PVT__isCurrent_3) 
                                                                         & vlSelfRef.__PVT__currentStoreNextWide_13[2U]) 
                                                                        | (((IData)(vlSelfRef.__PVT__isCurrent_3) 
                                                                            & vlSelfRef.__PVT__currentFirstStoreNextWide_13[2U]) 
                                                                           | (vlSelfRef.__PVT__loadFirstNextWide_14[2U] 
                                                                              | (vlSelfRef.__PVT__storeFirstNextWide_14[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_14[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_3) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_14[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_3) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_14[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_15[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_15[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_15[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent_3) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_15[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_15[2U])))))))))))))))))))) 
                                               | ((vlSelfRef.__PVT__loadFirstNextWide_8[2U] 
                                                   | (vlSelfRef.__PVT__storeFirstNextWide_8[2U] 
                                                      | (vlSelfRef.__PVT__strictWriteReadNextWide_8[2U] 
                                                         | (((IData)(vlSelfRef.__PVT__isCurrent_2) 
                                                             & vlSelfRef.__PVT__currentStoreNextWide_8[2U]) 
                                                            | (((IData)(vlSelfRef.__PVT__isCurrent_2) 
                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_8[2U]) 
                                                               | (vlSelfRef.__PVT__loadFirstNextWide_9[2U] 
                                                                  | (vlSelfRef.__PVT__storeFirstNextWide_9[2U] 
                                                                     | (vlSelfRef.__PVT__strictWriteReadNextWide_9[2U] 
                                                                        | (((IData)(vlSelfRef.__PVT__isCurrent_2) 
                                                                            & vlSelfRef.__PVT__currentStoreNextWide_9[2U]) 
                                                                           | (((IData)(vlSelfRef.__PVT__isCurrent_2) 
                                                                               & vlSelfRef.__PVT__currentFirstStoreNextWide_9[2U]) 
                                                                              | (vlSelfRef.__PVT__loadFirstNextWide_10[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_10[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_10[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_2) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_10[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_2) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_10[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_11[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_11[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_11[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent_2) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_11[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_11[2U])))))))))))))))))))) 
                                                  | ((vlSelfRef.__PVT__loadFirstNextWide_4[2U] 
                                                      | (vlSelfRef.__PVT__storeFirstNextWide_4[2U] 
                                                         | (vlSelfRef.__PVT__strictWriteReadNextWide_4[2U] 
                                                            | (((IData)(vlSelfRef.__PVT__isCurrent_1) 
                                                                & vlSelfRef.__PVT__currentStoreNextWide_4[2U]) 
                                                               | (((IData)(vlSelfRef.__PVT__isCurrent_1) 
                                                                   & vlSelfRef.__PVT__currentFirstStoreNextWide_4[2U]) 
                                                                  | (vlSelfRef.__PVT__loadFirstNextWide_5[2U] 
                                                                     | (vlSelfRef.__PVT__storeFirstNextWide_5[2U] 
                                                                        | (vlSelfRef.__PVT__strictWriteReadNextWide_5[2U] 
                                                                           | (((IData)(vlSelfRef.__PVT__isCurrent_1) 
                                                                               & vlSelfRef.__PVT__currentStoreNextWide_5[2U]) 
                                                                              | (((IData)(vlSelfRef.__PVT__isCurrent_1) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_5[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_6[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_6[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_6[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_1) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_6[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_1) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_6[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_7[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_7[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_7[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent_1) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_7[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_7[2U])))))))))))))))))))) 
                                                     | (vlSelfRef.__PVT__loadFirstNextWide[2U] 
                                                        | (vlSelfRef.__PVT__storeFirstNextWide[2U] 
                                                           | (vlSelfRef.__PVT__strictWriteReadNextWide[2U] 
                                                              | (((IData)(vlSelfRef.__PVT__isCurrent) 
                                                                  & vlSelfRef.__PVT__currentStoreNextWide[2U]) 
                                                                 | (((IData)(vlSelfRef.__PVT__isCurrent) 
                                                                     & vlSelfRef.__PVT__currentFirstStoreNextWide[2U]) 
                                                                    | (vlSelfRef.__PVT__loadFirstNextWide_1[2U] 
                                                                       | (vlSelfRef.__PVT__storeFirstNextWide_1[2U] 
                                                                          | (vlSelfRef.__PVT__strictWriteReadNextWide_1[2U] 
                                                                             | (((IData)(vlSelfRef.__PVT__isCurrent) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_1[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_1[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_2[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_2[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_2[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_2[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_2[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_3[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_3[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_3[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_3[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_3[2U]))))))))))))))))))))))))))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__0(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
                                   == (0xffU & ((IData)(8U) 
                                                + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_1 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(9U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_2 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(0xaU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_3 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(0xbU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_4 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(0xcU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_5 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(0xdU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_6 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(0xeU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_7 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(0xfU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__VdfgRegularize_h883887c0_0_634 = ((~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError)) 
                                                  & (IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance));
    vlSelfRef.__PVT__io_queryMatch_0_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_0 
                                                  - 
                                                  ((IData)(8U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_1_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_1 
                                                  - 
                                                  ((IData)(8U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_2_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_2 
                                                  - 
                                                  ((IData)(8U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_3_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_3 
                                                  - 
                                                  ((IData)(8U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_4_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_4 
                                                  - 
                                                  ((IData)(8U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_5_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_5 
                                                  - 
                                                  ((IData)(8U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_6_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_6 
                                                  - 
                                                  ((IData)(8U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_7_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_7 
                                                  - 
                                                  ((IData)(8U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__1(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__io_queryMatch_8_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_8 
                                                  - 
                                                  ((IData)(8U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_9_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_9 
                                                  - 
                                                  ((IData)(8U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_10_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_10 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_11_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_11 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_12_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_12 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_13_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_13 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_14_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_14 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_15_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_15 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_16_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_16 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_17_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_17 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_18_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_18 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_19_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_19 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_20_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_20 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_21_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_21 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_22_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_22 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_23_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_23 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_24_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_24 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_25_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_25 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_26_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_26 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_27_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_27 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__2(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__io_queryMatch_28_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_28 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_29_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_29 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_30_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_30 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_31_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_31 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_32_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_32 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_33_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_33 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_34_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_34 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_35_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_35 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_36_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_36 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_37_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_37 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_38_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_38 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_39_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_39 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_40_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_40 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_41_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_41 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_42_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_42 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_43_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_43 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_44_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_44 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_45_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_45 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_46_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_46 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_47_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_47 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__3(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__io_queryMatch_48_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_48 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_49_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_49 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_50_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_50 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_51_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_51 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_52_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_52 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_53_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_53 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_54_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_54 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_55_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_55 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_56_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_56 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_57_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_57 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_58_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_58 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_59_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_59 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_60_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_60 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_61_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_61 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_62_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_62 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_63_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_63 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_64_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_64 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_65_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_65 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_66_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_66 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_67_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_67 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__4(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__4\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__io_queryMatch_68_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_68 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_69_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_69 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_70_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_70 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_71_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_71 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_72_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_72 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_73_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_73 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_74_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_74 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_75_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_75 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_76_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_76 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_77_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_77 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_78_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_78 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_79_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_79 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_80_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_80 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_81_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_81 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_82_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_82 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_83_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_83 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_84_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_84 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_85_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_85 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_86_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_86 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_87_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_87 
                                                   - 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__5(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__5\n"); );
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

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__6(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__6\n"); );
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
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketStore_7_0
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketStore_7_0
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
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketStore_7_1
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketStore_7_1
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
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketStore_7_2
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketStore_7_2
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
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketStore_7_3
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketStore_7_3
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
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.bucketValid_0)
                               ? vlSelfRef.bucketFirstStore_0_0
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.bucketValid_0)
                                ? vlSelfRef.bucketFirstStore_0_0
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__currentFirstStoreNextWide[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.bucketValid_0)
                               ? vlSelfRef.bucketFirstStore_0_1
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.bucketValid_0)
                                ? vlSelfRef.bucketFirstStore_0_1
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__currentFirstStoreNextWide_1[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_1[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_1[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.bucketValid_0)
                               ? vlSelfRef.bucketFirstStore_0_2
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.bucketValid_0)
                                ? vlSelfRef.bucketFirstStore_0_2
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__currentFirstStoreNextWide_2[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_2[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_2[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.bucketValid_0)
                               ? vlSelfRef.bucketFirstStore_0_3
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.bucketValid_0)
                                ? vlSelfRef.bucketFirstStore_0_3
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__currentFirstStoreNextWide_3[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_3[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_3[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_1)
                               ? vlSelfRef.__PVT__bucketFirstStore_1_0
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_1)
                                ? vlSelfRef.__PVT__bucketFirstStore_1_0
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__currentFirstStoreNextWide_4[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_4[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_4[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_1)
                               ? vlSelfRef.__PVT__bucketFirstStore_1_1
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_1)
                                ? vlSelfRef.__PVT__bucketFirstStore_1_1
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__currentFirstStoreNextWide_5[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_5[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_5[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_1)
                               ? vlSelfRef.__PVT__bucketFirstStore_1_2
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_1)
                                ? vlSelfRef.__PVT__bucketFirstStore_1_2
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__currentFirstStoreNextWide_6[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_6[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_6[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_1)
                               ? vlSelfRef.__PVT__bucketFirstStore_1_3
                               : 0ULL));
    __Vtemp_78[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_1)
                                ? vlSelfRef.__PVT__bucketFirstStore_1_3
                                : 0ULL) >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__currentFirstStoreNextWide_7[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_7[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_7[2U] 
        = (1U & __Vtemp_80[2U]);
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__7(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__7\n"); );
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
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_2)
                              ? vlSelfRef.__PVT__bucketFirstStore_2_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_2)
                               ? vlSelfRef.__PVT__bucketFirstStore_2_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__currentFirstStoreNextWide_8[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_8[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_8[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_2)
                              ? vlSelfRef.__PVT__bucketFirstStore_2_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_2)
                               ? vlSelfRef.__PVT__bucketFirstStore_2_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__currentFirstStoreNextWide_9[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_9[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_9[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_2)
                               ? vlSelfRef.__PVT__bucketFirstStore_2_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_2)
                                ? vlSelfRef.__PVT__bucketFirstStore_2_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__currentFirstStoreNextWide_10[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_10[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_10[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_2)
                               ? vlSelfRef.__PVT__bucketFirstStore_2_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_2)
                                ? vlSelfRef.__PVT__bucketFirstStore_2_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__currentFirstStoreNextWide_11[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_11[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_11[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketFirstStore_3_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketFirstStore_3_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__currentFirstStoreNextWide_12[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_12[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_12[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketFirstStore_3_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketFirstStore_3_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__currentFirstStoreNextWide_13[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_13[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_13[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketFirstStore_3_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketFirstStore_3_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__currentFirstStoreNextWide_14[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_14[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_14[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketFirstStore_3_3
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketFirstStore_3_3
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__currentFirstStoreNextWide_15[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_15[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_15[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketFirstStore_4_0
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                                ? vlSelfRef.__PVT__bucketFirstStore_4_0
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__currentFirstStoreNextWide_16[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_16[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_16[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketFirstStore_4_1
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                                ? vlSelfRef.__PVT__bucketFirstStore_4_1
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__currentFirstStoreNextWide_17[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_17[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_17[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketFirstStore_4_2
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                                ? vlSelfRef.__PVT__bucketFirstStore_4_2
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__currentFirstStoreNextWide_18[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_18[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_18[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketFirstStore_4_3
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                                ? vlSelfRef.__PVT__bucketFirstStore_4_3
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__currentFirstStoreNextWide_19[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_19[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_19[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_5)
                               ? vlSelfRef.__PVT__bucketFirstStore_5_0
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_5)
                                ? vlSelfRef.__PVT__bucketFirstStore_5_0
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__currentFirstStoreNextWide_20[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_20[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_20[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_5)
                               ? vlSelfRef.__PVT__bucketFirstStore_5_1
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_5)
                                ? vlSelfRef.__PVT__bucketFirstStore_5_1
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__currentFirstStoreNextWide_21[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_21[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_21[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_5)
                               ? vlSelfRef.__PVT__bucketFirstStore_5_2
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_5)
                                ? vlSelfRef.__PVT__bucketFirstStore_5_2
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__currentFirstStoreNextWide_22[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_22[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_22[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_5)
                               ? vlSelfRef.__PVT__bucketFirstStore_5_3
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_5)
                                ? vlSelfRef.__PVT__bucketFirstStore_5_3
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__currentFirstStoreNextWide_23[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_23[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_23[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketFirstStore_6_0
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                                ? vlSelfRef.__PVT__bucketFirstStore_6_0
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__currentFirstStoreNextWide_24[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_24[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_24[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketFirstStore_6_1
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                                ? vlSelfRef.__PVT__bucketFirstStore_6_1
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__currentFirstStoreNextWide_25[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_25[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_25[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketFirstStore_6_2
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                                ? vlSelfRef.__PVT__bucketFirstStore_6_2
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__currentFirstStoreNextWide_26[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_26[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_26[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketFirstStore_6_3
                               : 0ULL));
    __Vtemp_78[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                                ? vlSelfRef.__PVT__bucketFirstStore_6_3
                                : 0ULL) >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__currentFirstStoreNextWide_27[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_27[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_27[2U] 
        = (1U & __Vtemp_80[2U]);
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__8(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__8\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                              ? vlSelfRef.bucketFirstStore_7_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketFirstStore_7_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__currentFirstStoreNextWide_28[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_28[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_28[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                              ? vlSelfRef.bucketFirstStore_7_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketFirstStore_7_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__currentFirstStoreNextWide_29[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_29[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_29[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketFirstStore_7_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketFirstStore_7_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__currentFirstStoreNextWide_30[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_30[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_30[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketFirstStore_7_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketFirstStore_7_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__currentFirstStoreNextWide_31[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_31[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_31[2U] 
        = (1U & __Vtemp_16[2U]);
    vlSelfRef.__PVT__retireSelect_0 = ((0xffU & ((IData)(8U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_1 = ((0xffU & ((IData)(9U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_2 = ((0xffU & ((IData)(0xaU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_3 = ((0xffU & ((IData)(0xbU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_4 = ((0xffU & ((IData)(0xcU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_5 = ((0xffU & ((IData)(0xdU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_6 = ((0xffU & ((IData)(0xeU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_7 = ((0xffU & ((IData)(0xfU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__isCurrent = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                  == (0xffU & ((IData)(8U) 
                                               + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_1 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(9U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_2 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(0xaU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_3 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(0xbU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_4 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(0xcU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_5 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(0xdU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_6 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(0xeU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_7 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(0xfU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__9(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__9\n"); );
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
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__10(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__10\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT___T_16 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                              & ((IData)(vlSelfRef.__PVT__isRetiring) 
                                 & (IData)(vlSelfRef.bucketValid_0)));
    vlSelfRef.__PVT___T_89 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                              & ((IData)(vlSelfRef.__PVT__isRetiring_1) 
                                 & (IData)(vlSelfRef.__PVT__bucketValid_1)));
    vlSelfRef.__PVT___T_162 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_2) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_2)));
    vlSelfRef.__PVT___T_235 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_3) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_3)));
    vlSelfRef.__PVT___T_308 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_4) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_4)));
    vlSelfRef.__PVT___T_381 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_5) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_5)));
    vlSelfRef.__PVT___T_454 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_6) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_6)));
    vlSelfRef.__PVT___T_527 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_7) 
                                  & (IData)(vlSelfRef.bucketValid_7)));
    vlSelfRef.io_queryMatch_0 = (IData)(((0U == (0xf8U 
                                                 & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset))) 
                                         & (((7U == 
                                              (7U & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                              ? (IData)(vlSelfRef.bucketValid_7)
                                              : ((6U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                  ? (IData)(vlSelfRef.__PVT__bucketValid_6)
                                                  : 
                                                 ((5U 
                                                   == 
                                                   (7U 
                                                    & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                   ? (IData)(vlSelfRef.__PVT__bucketValid_5)
                                                   : 
                                                  ((4U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                    ? (IData)(vlSelfRef.__PVT__bucketValid_4)
                                                    : 
                                                   ((3U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                     ? (IData)(vlSelfRef.__PVT__bucketValid_3)
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                      ? (IData)(vlSelfRef.__PVT__bucketValid_2)
                                                      : 
                                                     ((1U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                       ? (IData)(vlSelfRef.__PVT__bucketValid_1)
                                                       : (IData)(vlSelfRef.bucketValid_0)))))))) 
                                            & ((((7U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                  ? vlSelfRef.bucketSeq_7
                                                  : 
                                                 ((6U 
                                                   == 
                                                   (7U 
                                                    & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                   ? vlSelfRef.__PVT__bucketSeq_6
                                                   : 
                                                  ((5U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                    ? vlSelfRef.__PVT__bucketSeq_5
                                                    : 
                                                   ((4U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                     ? vlSelfRef.__PVT__bucketSeq_4
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                      ? vlSelfRef.__PVT__bucketSeq_3
                                                      : 
                                                     ((2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                       ? vlSelfRef.__PVT__bucketSeq_2
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (7U 
                                                         & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                        ? vlSelfRef.__PVT__bucketSeq_1
                                                        : vlSelfRef.bucketSeq_0))))))) 
                                                >> 8U) 
                                               == (vlSymsp->TOP.tb__DOT__io_querySeq_0 
                                                   >> 8U)))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__54(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__54\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.io_queryMatch_87 = (IData)(((0U == (0xf8U 
                                                  & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset))) 
                                          & (((7U == 
                                               (7U 
                                                & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                               ? (IData)(vlSelfRef.bucketValid_7)
                                               : ((6U 
                                                   == 
                                                   (7U 
                                                    & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                   ? (IData)(vlSelfRef.__PVT__bucketValid_6)
                                                   : 
                                                  ((5U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                    ? (IData)(vlSelfRef.__PVT__bucketValid_5)
                                                    : 
                                                   ((4U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                     ? (IData)(vlSelfRef.__PVT__bucketValid_4)
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                      ? (IData)(vlSelfRef.__PVT__bucketValid_3)
                                                      : 
                                                     ((2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                       ? (IData)(vlSelfRef.__PVT__bucketValid_2)
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (7U 
                                                         & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                        ? (IData)(vlSelfRef.__PVT__bucketValid_1)
                                                        : (IData)(vlSelfRef.bucketValid_0)))))))) 
                                             & ((((7U 
                                                   == 
                                                   (7U 
                                                    & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                   ? vlSelfRef.bucketSeq_7
                                                   : 
                                                  ((6U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                    ? vlSelfRef.__PVT__bucketSeq_6
                                                    : 
                                                   ((5U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                     ? vlSelfRef.__PVT__bucketSeq_5
                                                     : 
                                                    ((4U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                      ? vlSelfRef.__PVT__bucketSeq_4
                                                      : 
                                                     ((3U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                       ? vlSelfRef.__PVT__bucketSeq_3
                                                       : 
                                                      ((2U 
                                                        == 
                                                        (7U 
                                                         & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                        ? vlSelfRef.__PVT__bucketSeq_2
                                                        : 
                                                       ((1U 
                                                         == 
                                                         (7U 
                                                          & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                         ? vlSelfRef.__PVT__bucketSeq_1
                                                         : vlSelfRef.bucketSeq_0))))))) 
                                                 >> 8U) 
                                                == 
                                                (vlSymsp->TOP.tb__DOT__io_querySeq_87 
                                                 >> 8U)))));
    vlSelfRef.__PVT___io_retiringValid_T = ((IData)(vlSelfRef.__PVT__retireSelect_0) 
                                            & (IData)(vlSelfRef.bucketValid_0));
    vlSelfRef.__PVT___io_retiringValid_T_1 = ((IData)(vlSelfRef.__PVT__retireSelect_1) 
                                              & (IData)(vlSelfRef.__PVT__bucketValid_1));
    vlSelfRef.__PVT___io_retiringValid_T_2 = ((IData)(vlSelfRef.__PVT__retireSelect_2) 
                                              & (IData)(vlSelfRef.__PVT__bucketValid_2));
    vlSelfRef.__PVT___io_retiringValid_T_3 = ((IData)(vlSelfRef.__PVT__retireSelect_3) 
                                              & (IData)(vlSelfRef.__PVT__bucketValid_3));
    vlSelfRef.__PVT___io_retiringValid_T_4 = ((IData)(vlSelfRef.__PVT__retireSelect_4) 
                                              & (IData)(vlSelfRef.__PVT__bucketValid_4));
    vlSelfRef.__PVT___io_retiringValid_T_5 = ((IData)(vlSelfRef.__PVT__retireSelect_5) 
                                              & (IData)(vlSelfRef.__PVT__bucketValid_5));
    vlSelfRef.__PVT___io_retiringValid_T_6 = ((IData)(vlSelfRef.__PVT__retireSelect_6) 
                                              & (IData)(vlSelfRef.__PVT__bucketValid_6));
    vlSelfRef.__PVT___io_retiringValid_T_7 = ((IData)(vlSelfRef.__PVT__retireSelect_7) 
                                              & (IData)(vlSelfRef.bucketValid_7));
    vlSelfRef.__PVT__allocate = ((~ (IData)(vlSelfRef.bucketValid_0)) 
                                 & (IData)(vlSelfRef.__PVT__isCurrent));
    vlSelfRef.__PVT___GEN_80 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                 & (IData)(vlSelfRef.__PVT__isCurrent)) 
                                | (IData)(vlSelfRef.bucketValid_0));
    vlSelfRef.__PVT__allocate_1 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_1)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_1));
    vlSelfRef.__PVT___GEN_165 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_1)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_1));
    vlSelfRef.__PVT__allocate_2 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_2)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_2));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__55(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__55\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___GEN_250 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_2)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_2));
    vlSelfRef.__PVT__allocate_3 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_3)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_3));
    vlSelfRef.__PVT___GEN_335 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_3)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_3));
    vlSelfRef.__PVT__allocate_4 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_4)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_4));
    vlSelfRef.__PVT___GEN_420 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_4)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_4));
    vlSelfRef.__PVT__allocate_5 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_5)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_5));
    vlSelfRef.__PVT___GEN_505 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_5)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_5));
    vlSelfRef.__PVT__allocate_6 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_6)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_6));
    vlSelfRef.__PVT___GEN_590 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_6)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_6));
    vlSelfRef.__PVT__allocate_7 = ((~ (IData)(vlSelfRef.bucketValid_7)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_7));
    vlSelfRef.__PVT___GEN_675 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_7)) 
                                 | (IData)(vlSelfRef.bucketValid_7));
    vlSelfRef.io_currentCollision = (((IData)(vlSelfRef.__PVT__isCurrent) 
                                      & ((IData)(vlSelfRef.bucketValid_0) 
                                         & ((vlSelfRef.bucketSeq_0 
                                             >> 8U) 
                                            != (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                >> 8U)))) 
                                     | (((IData)(vlSelfRef.__PVT__isCurrent_1) 
                                         & ((IData)(vlSelfRef.__PVT__bucketValid_1) 
                                            & ((vlSelfRef.__PVT__bucketSeq_1 
                                                >> 8U) 
                                               != (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                   >> 8U)))) 
                                        | (((IData)(vlSelfRef.__PVT__isCurrent_2) 
                                            & ((IData)(vlSelfRef.__PVT__bucketValid_2) 
                                               & ((vlSelfRef.__PVT__bucketSeq_2 
                                                   >> 8U) 
                                                  != 
                                                  (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                   >> 8U)))) 
                                           | (((IData)(vlSelfRef.__PVT__isCurrent_3) 
                                               & ((IData)(vlSelfRef.__PVT__bucketValid_3) 
                                                  & ((vlSelfRef.__PVT__bucketSeq_3 
                                                      >> 8U) 
                                                     != 
                                                     (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                      >> 8U)))) 
                                              | (((IData)(vlSelfRef.__PVT__isCurrent_4) 
                                                  & ((IData)(vlSelfRef.__PVT__bucketValid_4) 
                                                     & ((vlSelfRef.__PVT__bucketSeq_4 
                                                         >> 8U) 
                                                        != 
                                                        (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                         >> 8U)))) 
                                                 | (((IData)(vlSelfRef.__PVT__isCurrent_5) 
                                                     & ((IData)(vlSelfRef.__PVT__bucketValid_5) 
                                                        & ((vlSelfRef.__PVT__bucketSeq_5 
                                                            >> 8U) 
                                                           != 
                                                           (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                            >> 8U)))) 
                                                    | (((IData)(vlSelfRef.__PVT__isCurrent_6) 
                                                        & ((IData)(vlSelfRef.__PVT__bucketValid_6) 
                                                           & ((vlSelfRef.__PVT__bucketSeq_6 
                                                               >> 8U) 
                                                              != 
                                                              (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                               >> 8U)))) 
                                                       | ((IData)(vlSelfRef.__PVT__isCurrent_7) 
                                                          & ((IData)(vlSelfRef.bucketValid_7) 
                                                             & ((vlSelfRef.bucketSeq_7 
                                                                 >> 8U) 
                                                                != 
                                                                (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                                 >> 8U)))))))))));
    vlSelfRef.__PVT___GEN_2088 = ((~ (IData)(vlSelfRef.__PVT__resolving_0)) 
                                  & (IData)(vlSelfRef.buckets_valid_0));
    vlSelfRef.__PVT___canAccept_T_1 = (1U & ((~ (IData)(vlSelfRef.buckets_valid_0)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_0)));
    vlSelfRef.__PVT___GEN_2103 = ((~ (IData)(vlSelfRef.__PVT__resolving_1)) 
                                  & (IData)(vlSelfRef.__PVT__buckets_valid_1));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__56(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__56\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___canAccept_T_4 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_1)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_1)));
    vlSelfRef.__PVT___GEN_2118 = ((~ (IData)(vlSelfRef.__PVT__resolving_2)) 
                                  & (IData)(vlSelfRef.__PVT__buckets_valid_2));
    vlSelfRef.__PVT___canAccept_T_7 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_2)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_2)));
    vlSelfRef.__PVT___GEN_2133 = ((~ (IData)(vlSelfRef.__PVT__resolving_3)) 
                                  & (IData)(vlSelfRef.__PVT__buckets_valid_3));
    vlSelfRef.__PVT___canAccept_T_10 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_3)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_3)));
    vlSelfRef.__PVT___GEN_2148 = ((~ (IData)(vlSelfRef.__PVT__resolving_4)) 
                                  & (IData)(vlSelfRef.__PVT__buckets_valid_4));
    vlSelfRef.__PVT___canAccept_T_13 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_4)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_4)));
    vlSelfRef.__PVT___GEN_2163 = ((~ (IData)(vlSelfRef.__PVT__resolving_5)) 
                                  & (IData)(vlSelfRef.__PVT__buckets_valid_5));
    vlSelfRef.__PVT___canAccept_T_16 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_5)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_5)));
    vlSelfRef.__PVT___GEN_2178 = ((~ (IData)(vlSelfRef.__PVT__resolving_6)) 
                                  & (IData)(vlSelfRef.__PVT__buckets_valid_6));
    vlSelfRef.__PVT___canAccept_T_19 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_6)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_6)));
    vlSelfRef.__PVT___GEN_2193 = ((~ (IData)(vlSelfRef.__PVT__resolving_7)) 
                                  & (IData)(vlSelfRef.buckets_valid_7));
    vlSelfRef.__PVT___canAccept_T_22 = (1U & ((~ (IData)(vlSelfRef.buckets_valid_7)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_7)));
    if (vlSelfRef.__PVT__bucketLoadFirstDelta_ordered) {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_22 
            = vlSymsp->TOP.tb__DOT__io_loadSources_1_counts_bytes;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_23 
            = vlSymsp->TOP.tb__DOT__io_loadSources_1_counts_words4;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_24 
            = vlSymsp->TOP.tb__DOT__io_loadSources_1_counts_words8;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_25 
            = vlSymsp->TOP.tb__DOT__io_loadSources_1_counts_lines;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_17 
            = vlSymsp->TOP.tb__DOT__io_loadSources_0_counts_bytes;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_18 
            = vlSymsp->TOP.tb__DOT__io_loadSources_0_counts_words4;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_19 
            = vlSymsp->TOP.tb__DOT__io_loadSources_0_counts_words8;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_20 
            = vlSymsp->TOP.tb__DOT__io_loadSources_0_counts_lines;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_21 
            = vlSymsp->TOP.tb__DOT__io_loadSources_1_key;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_16 
            = vlSymsp->TOP.tb__DOT__io_loadSources_0_key;
    } else {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_22 
            = vlSymsp->TOP.tb__DOT__io_loadSources_0_counts_bytes;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_23 
            = vlSymsp->TOP.tb__DOT__io_loadSources_0_counts_words4;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_24 
            = vlSymsp->TOP.tb__DOT__io_loadSources_0_counts_words8;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_25 
            = vlSymsp->TOP.tb__DOT__io_loadSources_0_counts_lines;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_17 
            = vlSymsp->TOP.tb__DOT__io_loadSources_1_counts_bytes;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_18 
            = vlSymsp->TOP.tb__DOT__io_loadSources_1_counts_words4;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_19 
            = vlSymsp->TOP.tb__DOT__io_loadSources_1_counts_words8;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_20 
            = vlSymsp->TOP.tb__DOT__io_loadSources_1_counts_lines;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_21 
            = vlSymsp->TOP.tb__DOT__io_loadSources_0_key;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_16 
            = vlSymsp->TOP.tb__DOT__io_loadSources_1_key;
    }
    if (vlSelfRef.__PVT__bucketLoadFirstDelta_ordered_1) {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_32 
            = vlSymsp->TOP.tb__DOT__io_loadSources_3_counts_bytes;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_33 
            = vlSymsp->TOP.tb__DOT__io_loadSources_3_counts_words4;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_34 
            = vlSymsp->TOP.tb__DOT__io_loadSources_3_counts_words8;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_35 
            = vlSymsp->TOP.tb__DOT__io_loadSources_3_counts_lines;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_27 
            = vlSymsp->TOP.tb__DOT__io_loadSources_2_counts_bytes;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_28 
            = vlSymsp->TOP.tb__DOT__io_loadSources_2_counts_words4;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_29 
            = vlSymsp->TOP.tb__DOT__io_loadSources_2_counts_words8;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_30 
            = vlSymsp->TOP.tb__DOT__io_loadSources_2_counts_lines;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_31 
            = vlSymsp->TOP.tb__DOT__io_loadSources_3_key;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_26 
            = vlSymsp->TOP.tb__DOT__io_loadSources_2_key;
    } else {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_32 
            = vlSymsp->TOP.tb__DOT__io_loadSources_2_counts_bytes;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_33 
            = vlSymsp->TOP.tb__DOT__io_loadSources_2_counts_words4;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_34 
            = vlSymsp->TOP.tb__DOT__io_loadSources_2_counts_words8;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_35 
            = vlSymsp->TOP.tb__DOT__io_loadSources_2_counts_lines;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_27 
            = vlSymsp->TOP.tb__DOT__io_loadSources_3_counts_bytes;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_28 
            = vlSymsp->TOP.tb__DOT__io_loadSources_3_counts_words4;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_29 
            = vlSymsp->TOP.tb__DOT__io_loadSources_3_counts_words8;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_30 
            = vlSymsp->TOP.tb__DOT__io_loadSources_3_counts_lines;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_31 
            = vlSymsp->TOP.tb__DOT__io_loadSources_2_key;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_26 
            = vlSymsp->TOP.tb__DOT__io_loadSources_3_key;
    }
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_159 = 
        ((IData)(vlSelfRef.__PVT__bucketLoadFirstDelta_ordered_5)
          ? (IData)(vlSymsp->TOP.tb__DOT__io_loadSources_5_counts_bytes)
          : (IData)(vlSymsp->TOP.tb__DOT__io_loadSources_4_counts_bytes));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__57(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__57\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketLoadFirstDelta_ordered_5) {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_160 
            = vlSymsp->TOP.tb__DOT__io_loadSources_5_counts_words4;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_161 
            = vlSymsp->TOP.tb__DOT__io_loadSources_5_counts_words8;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_162 
            = vlSymsp->TOP.tb__DOT__io_loadSources_5_counts_lines;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_154 
            = vlSymsp->TOP.tb__DOT__io_loadSources_4_counts_bytes;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_155 
            = vlSymsp->TOP.tb__DOT__io_loadSources_4_counts_words4;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_156 
            = vlSymsp->TOP.tb__DOT__io_loadSources_4_counts_words8;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_157 
            = vlSymsp->TOP.tb__DOT__io_loadSources_4_counts_lines;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_158 
            = vlSymsp->TOP.tb__DOT__io_loadSources_5_key;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_153 
            = vlSymsp->TOP.tb__DOT__io_loadSources_4_key;
    } else {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_160 
            = vlSymsp->TOP.tb__DOT__io_loadSources_4_counts_words4;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_161 
            = vlSymsp->TOP.tb__DOT__io_loadSources_4_counts_words8;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_162 
            = vlSymsp->TOP.tb__DOT__io_loadSources_4_counts_lines;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_154 
            = vlSymsp->TOP.tb__DOT__io_loadSources_5_counts_bytes;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_155 
            = vlSymsp->TOP.tb__DOT__io_loadSources_5_counts_words4;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_156 
            = vlSymsp->TOP.tb__DOT__io_loadSources_5_counts_words8;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_157 
            = vlSymsp->TOP.tb__DOT__io_loadSources_5_counts_lines;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_158 
            = vlSymsp->TOP.tb__DOT__io_loadSources_4_key;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_153 
            = vlSymsp->TOP.tb__DOT__io_loadSources_5_key;
    }
    if (vlSelfRef.__PVT__bucketLoadFirstDelta_ordered_6) {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_169 
            = vlSymsp->TOP.tb__DOT__io_loadSources_7_counts_bytes;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_170 
            = vlSymsp->TOP.tb__DOT__io_loadSources_7_counts_words4;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_171 
            = vlSymsp->TOP.tb__DOT__io_loadSources_7_counts_words8;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_172 
            = vlSymsp->TOP.tb__DOT__io_loadSources_7_counts_lines;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_164 
            = vlSymsp->TOP.tb__DOT__io_loadSources_6_counts_bytes;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_165 
            = vlSymsp->TOP.tb__DOT__io_loadSources_6_counts_words4;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_166 
            = vlSymsp->TOP.tb__DOT__io_loadSources_6_counts_words8;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_167 
            = vlSymsp->TOP.tb__DOT__io_loadSources_6_counts_lines;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_168 
            = vlSymsp->TOP.tb__DOT__io_loadSources_7_key;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_163 
            = vlSymsp->TOP.tb__DOT__io_loadSources_6_key;
    } else {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_169 
            = vlSymsp->TOP.tb__DOT__io_loadSources_6_counts_bytes;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_170 
            = vlSymsp->TOP.tb__DOT__io_loadSources_6_counts_words4;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_171 
            = vlSymsp->TOP.tb__DOT__io_loadSources_6_counts_words8;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_172 
            = vlSymsp->TOP.tb__DOT__io_loadSources_6_counts_lines;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_164 
            = vlSymsp->TOP.tb__DOT__io_loadSources_7_counts_bytes;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_165 
            = vlSymsp->TOP.tb__DOT__io_loadSources_7_counts_words4;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_166 
            = vlSymsp->TOP.tb__DOT__io_loadSources_7_counts_words8;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_167 
            = vlSymsp->TOP.tb__DOT__io_loadSources_7_counts_lines;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_168 
            = vlSymsp->TOP.tb__DOT__io_loadSources_6_key;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_163 
            = vlSymsp->TOP.tb__DOT__io_loadSources_7_key;
    }
    if (vlSelfRef.__PVT__bucketStoreFirstDelta_ordered) {
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_22 
            = vlSymsp->TOP.tb__DOT__io_storeSources_1_counts_bytes;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_23 
            = vlSymsp->TOP.tb__DOT__io_storeSources_1_counts_words4;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_24 
            = vlSymsp->TOP.tb__DOT__io_storeSources_1_counts_words8;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_25 
            = vlSymsp->TOP.tb__DOT__io_storeSources_1_counts_lines;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_17 
            = vlSymsp->TOP.tb__DOT__io_storeSources_0_counts_bytes;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_18 
            = vlSymsp->TOP.tb__DOT__io_storeSources_0_counts_words4;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_19 
            = vlSymsp->TOP.tb__DOT__io_storeSources_0_counts_words8;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_20 
            = vlSymsp->TOP.tb__DOT__io_storeSources_0_counts_lines;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_21 
            = vlSymsp->TOP.tb__DOT__io_storeSources_1_key;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_16 
            = vlSymsp->TOP.tb__DOT__io_storeSources_0_key;
    } else {
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_22 
            = vlSymsp->TOP.tb__DOT__io_storeSources_0_counts_bytes;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_23 
            = vlSymsp->TOP.tb__DOT__io_storeSources_0_counts_words4;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_24 
            = vlSymsp->TOP.tb__DOT__io_storeSources_0_counts_words8;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_25 
            = vlSymsp->TOP.tb__DOT__io_storeSources_0_counts_lines;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_17 
            = vlSymsp->TOP.tb__DOT__io_storeSources_1_counts_bytes;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_18 
            = vlSymsp->TOP.tb__DOT__io_storeSources_1_counts_words4;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_19 
            = vlSymsp->TOP.tb__DOT__io_storeSources_1_counts_words8;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_20 
            = vlSymsp->TOP.tb__DOT__io_storeSources_1_counts_lines;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_21 
            = vlSymsp->TOP.tb__DOT__io_storeSources_0_key;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_16 
            = vlSymsp->TOP.tb__DOT__io_storeSources_1_key;
    }
    if (vlSelfRef.__PVT__bucketStoreFirstDelta_ordered_1) {
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_32 
            = vlSymsp->TOP.tb__DOT__io_storeSources_3_counts_bytes;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_33 
            = vlSymsp->TOP.tb__DOT__io_storeSources_3_counts_words4;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_34 
            = vlSymsp->TOP.tb__DOT__io_storeSources_3_counts_words8;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_35 
            = vlSymsp->TOP.tb__DOT__io_storeSources_3_counts_lines;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_27 
            = vlSymsp->TOP.tb__DOT__io_storeSources_2_counts_bytes;
    } else {
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_32 
            = vlSymsp->TOP.tb__DOT__io_storeSources_2_counts_bytes;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_33 
            = vlSymsp->TOP.tb__DOT__io_storeSources_2_counts_words4;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_34 
            = vlSymsp->TOP.tb__DOT__io_storeSources_2_counts_words8;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_35 
            = vlSymsp->TOP.tb__DOT__io_storeSources_2_counts_lines;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_27 
            = vlSymsp->TOP.tb__DOT__io_storeSources_3_counts_bytes;
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__58(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__58\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketStoreFirstDelta_ordered_1) {
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_28 
            = vlSymsp->TOP.tb__DOT__io_storeSources_2_counts_words4;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_29 
            = vlSymsp->TOP.tb__DOT__io_storeSources_2_counts_words8;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_30 
            = vlSymsp->TOP.tb__DOT__io_storeSources_2_counts_lines;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_31 
            = vlSymsp->TOP.tb__DOT__io_storeSources_3_key;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_26 
            = vlSymsp->TOP.tb__DOT__io_storeSources_2_key;
    } else {
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_28 
            = vlSymsp->TOP.tb__DOT__io_storeSources_3_counts_words4;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_29 
            = vlSymsp->TOP.tb__DOT__io_storeSources_3_counts_words8;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_30 
            = vlSymsp->TOP.tb__DOT__io_storeSources_3_counts_lines;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_31 
            = vlSymsp->TOP.tb__DOT__io_storeSources_2_key;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_26 
            = vlSymsp->TOP.tb__DOT__io_storeSources_3_key;
    }
    if (vlSelfRef.__PVT__bucketStoreFirstDelta_ordered_5) {
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_159 
            = vlSymsp->TOP.tb__DOT__io_storeSources_5_counts_bytes;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_160 
            = vlSymsp->TOP.tb__DOT__io_storeSources_5_counts_words4;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_161 
            = vlSymsp->TOP.tb__DOT__io_storeSources_5_counts_words8;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_162 
            = vlSymsp->TOP.tb__DOT__io_storeSources_5_counts_lines;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_154 
            = vlSymsp->TOP.tb__DOT__io_storeSources_4_counts_bytes;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_155 
            = vlSymsp->TOP.tb__DOT__io_storeSources_4_counts_words4;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_156 
            = vlSymsp->TOP.tb__DOT__io_storeSources_4_counts_words8;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_157 
            = vlSymsp->TOP.tb__DOT__io_storeSources_4_counts_lines;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_158 
            = vlSymsp->TOP.tb__DOT__io_storeSources_5_key;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_153 
            = vlSymsp->TOP.tb__DOT__io_storeSources_4_key;
    } else {
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_159 
            = vlSymsp->TOP.tb__DOT__io_storeSources_4_counts_bytes;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_160 
            = vlSymsp->TOP.tb__DOT__io_storeSources_4_counts_words4;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_161 
            = vlSymsp->TOP.tb__DOT__io_storeSources_4_counts_words8;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_162 
            = vlSymsp->TOP.tb__DOT__io_storeSources_4_counts_lines;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_154 
            = vlSymsp->TOP.tb__DOT__io_storeSources_5_counts_bytes;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_155 
            = vlSymsp->TOP.tb__DOT__io_storeSources_5_counts_words4;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_156 
            = vlSymsp->TOP.tb__DOT__io_storeSources_5_counts_words8;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_157 
            = vlSymsp->TOP.tb__DOT__io_storeSources_5_counts_lines;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_158 
            = vlSymsp->TOP.tb__DOT__io_storeSources_4_key;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_153 
            = vlSymsp->TOP.tb__DOT__io_storeSources_5_key;
    }
    if (vlSelfRef.__PVT__bucketStoreFirstDelta_ordered_6) {
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_169 
            = vlSymsp->TOP.tb__DOT__io_storeSources_7_counts_bytes;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_170 
            = vlSymsp->TOP.tb__DOT__io_storeSources_7_counts_words4;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_171 
            = vlSymsp->TOP.tb__DOT__io_storeSources_7_counts_words8;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_172 
            = vlSymsp->TOP.tb__DOT__io_storeSources_7_counts_lines;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_164 
            = vlSymsp->TOP.tb__DOT__io_storeSources_6_counts_bytes;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_165 
            = vlSymsp->TOP.tb__DOT__io_storeSources_6_counts_words4;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_166 
            = vlSymsp->TOP.tb__DOT__io_storeSources_6_counts_words8;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_167 
            = vlSymsp->TOP.tb__DOT__io_storeSources_6_counts_lines;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_168 
            = vlSymsp->TOP.tb__DOT__io_storeSources_7_key;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_163 
            = vlSymsp->TOP.tb__DOT__io_storeSources_6_key;
    } else {
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_169 
            = vlSymsp->TOP.tb__DOT__io_storeSources_6_counts_bytes;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_170 
            = vlSymsp->TOP.tb__DOT__io_storeSources_6_counts_words4;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_171 
            = vlSymsp->TOP.tb__DOT__io_storeSources_6_counts_words8;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_172 
            = vlSymsp->TOP.tb__DOT__io_storeSources_6_counts_lines;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_164 
            = vlSymsp->TOP.tb__DOT__io_storeSources_7_counts_bytes;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_165 
            = vlSymsp->TOP.tb__DOT__io_storeSources_7_counts_words4;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_166 
            = vlSymsp->TOP.tb__DOT__io_storeSources_7_counts_words8;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_167 
            = vlSymsp->TOP.tb__DOT__io_storeSources_7_counts_lines;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_168 
            = vlSymsp->TOP.tb__DOT__io_storeSources_6_key;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_163 
            = vlSymsp->TOP.tb__DOT__io_storeSources_7_key;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_22 
            = vlSymsp->TOP.tb__DOT__io_strictSources_1_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_23 
            = vlSymsp->TOP.tb__DOT__io_strictSources_1_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_24 
            = vlSymsp->TOP.tb__DOT__io_strictSources_1_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25 
            = vlSymsp->TOP.tb__DOT__io_strictSources_1_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_17 
            = vlSymsp->TOP.tb__DOT__io_strictSources_0_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_18 
            = vlSymsp->TOP.tb__DOT__io_strictSources_0_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_19 
            = vlSymsp->TOP.tb__DOT__io_strictSources_0_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20 
            = vlSymsp->TOP.tb__DOT__io_strictSources_0_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_21 
            = vlSymsp->TOP.tb__DOT__io_strictSources_1_key;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_22 
            = vlSymsp->TOP.tb__DOT__io_strictSources_0_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_23 
            = vlSymsp->TOP.tb__DOT__io_strictSources_0_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_24 
            = vlSymsp->TOP.tb__DOT__io_strictSources_0_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25 
            = vlSymsp->TOP.tb__DOT__io_strictSources_0_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_17 
            = vlSymsp->TOP.tb__DOT__io_strictSources_1_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_18 
            = vlSymsp->TOP.tb__DOT__io_strictSources_1_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_19 
            = vlSymsp->TOP.tb__DOT__io_strictSources_1_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20 
            = vlSymsp->TOP.tb__DOT__io_strictSources_1_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_21 
            = vlSymsp->TOP.tb__DOT__io_strictSources_0_key;
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__59(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__59\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16 
        = ((IData)(vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered)
            ? (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_0_key)
            : (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_1_key));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_1) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_32 
            = vlSymsp->TOP.tb__DOT__io_strictSources_3_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_33 
            = vlSymsp->TOP.tb__DOT__io_strictSources_3_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34 
            = vlSymsp->TOP.tb__DOT__io_strictSources_3_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_35 
            = vlSymsp->TOP.tb__DOT__io_strictSources_3_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_27 
            = vlSymsp->TOP.tb__DOT__io_strictSources_2_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_28 
            = vlSymsp->TOP.tb__DOT__io_strictSources_2_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29 
            = vlSymsp->TOP.tb__DOT__io_strictSources_2_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_30 
            = vlSymsp->TOP.tb__DOT__io_strictSources_2_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_31 
            = vlSymsp->TOP.tb__DOT__io_strictSources_3_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_26 
            = vlSymsp->TOP.tb__DOT__io_strictSources_2_key;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_32 
            = vlSymsp->TOP.tb__DOT__io_strictSources_2_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_33 
            = vlSymsp->TOP.tb__DOT__io_strictSources_2_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34 
            = vlSymsp->TOP.tb__DOT__io_strictSources_2_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_35 
            = vlSymsp->TOP.tb__DOT__io_strictSources_2_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_27 
            = vlSymsp->TOP.tb__DOT__io_strictSources_3_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_28 
            = vlSymsp->TOP.tb__DOT__io_strictSources_3_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29 
            = vlSymsp->TOP.tb__DOT__io_strictSources_3_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_30 
            = vlSymsp->TOP.tb__DOT__io_strictSources_3_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_31 
            = vlSymsp->TOP.tb__DOT__io_strictSources_2_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_26 
            = vlSymsp->TOP.tb__DOT__io_strictSources_3_key;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_5) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_159 
            = vlSymsp->TOP.tb__DOT__io_strictSources_5_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_160 
            = vlSymsp->TOP.tb__DOT__io_strictSources_5_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_161 
            = vlSymsp->TOP.tb__DOT__io_strictSources_5_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_162 
            = vlSymsp->TOP.tb__DOT__io_strictSources_5_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_154 
            = vlSymsp->TOP.tb__DOT__io_strictSources_4_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_155 
            = vlSymsp->TOP.tb__DOT__io_strictSources_4_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_156 
            = vlSymsp->TOP.tb__DOT__io_strictSources_4_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_157 
            = vlSymsp->TOP.tb__DOT__io_strictSources_4_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_158 
            = vlSymsp->TOP.tb__DOT__io_strictSources_5_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_153 
            = vlSymsp->TOP.tb__DOT__io_strictSources_4_key;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_159 
            = vlSymsp->TOP.tb__DOT__io_strictSources_4_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_160 
            = vlSymsp->TOP.tb__DOT__io_strictSources_4_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_161 
            = vlSymsp->TOP.tb__DOT__io_strictSources_4_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_162 
            = vlSymsp->TOP.tb__DOT__io_strictSources_4_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_154 
            = vlSymsp->TOP.tb__DOT__io_strictSources_5_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_155 
            = vlSymsp->TOP.tb__DOT__io_strictSources_5_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_156 
            = vlSymsp->TOP.tb__DOT__io_strictSources_5_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_157 
            = vlSymsp->TOP.tb__DOT__io_strictSources_5_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_158 
            = vlSymsp->TOP.tb__DOT__io_strictSources_4_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_153 
            = vlSymsp->TOP.tb__DOT__io_strictSources_5_key;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_6) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_169 
            = vlSymsp->TOP.tb__DOT__io_strictSources_7_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_170 
            = vlSymsp->TOP.tb__DOT__io_strictSources_7_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_171 
            = vlSymsp->TOP.tb__DOT__io_strictSources_7_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_172 
            = vlSymsp->TOP.tb__DOT__io_strictSources_7_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_164 
            = vlSymsp->TOP.tb__DOT__io_strictSources_6_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_165 
            = vlSymsp->TOP.tb__DOT__io_strictSources_6_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_166 
            = vlSymsp->TOP.tb__DOT__io_strictSources_6_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_167 
            = vlSymsp->TOP.tb__DOT__io_strictSources_6_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_168 
            = vlSymsp->TOP.tb__DOT__io_strictSources_7_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_163 
            = vlSymsp->TOP.tb__DOT__io_strictSources_6_key;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_169 
            = vlSymsp->TOP.tb__DOT__io_strictSources_6_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_170 
            = vlSymsp->TOP.tb__DOT__io_strictSources_6_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_171 
            = vlSymsp->TOP.tb__DOT__io_strictSources_6_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_172 
            = vlSymsp->TOP.tb__DOT__io_strictSources_6_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_164 
            = vlSymsp->TOP.tb__DOT__io_strictSources_7_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_165 
            = vlSymsp->TOP.tb__DOT__io_strictSources_7_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_166 
            = vlSymsp->TOP.tb__DOT__io_strictSources_7_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_167 
            = vlSymsp->TOP.tb__DOT__io_strictSources_7_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_168 
            = vlSymsp->TOP.tb__DOT__io_strictSources_6_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_163 
            = vlSymsp->TOP.tb__DOT__io_strictSources_7_key;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_10) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_296 
            = vlSymsp->TOP.tb__DOT__io_strictSources_9_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_297 
            = vlSymsp->TOP.tb__DOT__io_strictSources_9_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_298 
            = vlSymsp->TOP.tb__DOT__io_strictSources_9_counts_words8;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_296 
            = vlSymsp->TOP.tb__DOT__io_strictSources_8_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_297 
            = vlSymsp->TOP.tb__DOT__io_strictSources_8_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_298 
            = vlSymsp->TOP.tb__DOT__io_strictSources_8_counts_words8;
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__60(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__60\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_10) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_299 
            = vlSymsp->TOP.tb__DOT__io_strictSources_9_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_291 
            = vlSymsp->TOP.tb__DOT__io_strictSources_8_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_292 
            = vlSymsp->TOP.tb__DOT__io_strictSources_8_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_293 
            = vlSymsp->TOP.tb__DOT__io_strictSources_8_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_294 
            = vlSymsp->TOP.tb__DOT__io_strictSources_8_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_295 
            = vlSymsp->TOP.tb__DOT__io_strictSources_9_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_290 
            = vlSymsp->TOP.tb__DOT__io_strictSources_8_key;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_299 
            = vlSymsp->TOP.tb__DOT__io_strictSources_8_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_291 
            = vlSymsp->TOP.tb__DOT__io_strictSources_9_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_292 
            = vlSymsp->TOP.tb__DOT__io_strictSources_9_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_293 
            = vlSymsp->TOP.tb__DOT__io_strictSources_9_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_294 
            = vlSymsp->TOP.tb__DOT__io_strictSources_9_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_295 
            = vlSymsp->TOP.tb__DOT__io_strictSources_8_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_290 
            = vlSymsp->TOP.tb__DOT__io_strictSources_9_key;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_11) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_306 
            = vlSymsp->TOP.tb__DOT__io_strictSources_11_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_307 
            = vlSymsp->TOP.tb__DOT__io_strictSources_11_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_308 
            = vlSymsp->TOP.tb__DOT__io_strictSources_11_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_309 
            = vlSymsp->TOP.tb__DOT__io_strictSources_11_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_301 
            = vlSymsp->TOP.tb__DOT__io_strictSources_10_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_302 
            = vlSymsp->TOP.tb__DOT__io_strictSources_10_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_303 
            = vlSymsp->TOP.tb__DOT__io_strictSources_10_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_304 
            = vlSymsp->TOP.tb__DOT__io_strictSources_10_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_305 
            = vlSymsp->TOP.tb__DOT__io_strictSources_11_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_300 
            = vlSymsp->TOP.tb__DOT__io_strictSources_10_key;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_306 
            = vlSymsp->TOP.tb__DOT__io_strictSources_10_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_307 
            = vlSymsp->TOP.tb__DOT__io_strictSources_10_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_308 
            = vlSymsp->TOP.tb__DOT__io_strictSources_10_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_309 
            = vlSymsp->TOP.tb__DOT__io_strictSources_10_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_301 
            = vlSymsp->TOP.tb__DOT__io_strictSources_11_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_302 
            = vlSymsp->TOP.tb__DOT__io_strictSources_11_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_303 
            = vlSymsp->TOP.tb__DOT__io_strictSources_11_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_304 
            = vlSymsp->TOP.tb__DOT__io_strictSources_11_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_305 
            = vlSymsp->TOP.tb__DOT__io_strictSources_10_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_300 
            = vlSymsp->TOP.tb__DOT__io_strictSources_11_key;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_15) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_433 
            = vlSymsp->TOP.tb__DOT__io_strictSources_13_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_434 
            = vlSymsp->TOP.tb__DOT__io_strictSources_13_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_435 
            = vlSymsp->TOP.tb__DOT__io_strictSources_13_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_436 
            = vlSymsp->TOP.tb__DOT__io_strictSources_13_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_428 
            = vlSymsp->TOP.tb__DOT__io_strictSources_12_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_429 
            = vlSymsp->TOP.tb__DOT__io_strictSources_12_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_430 
            = vlSymsp->TOP.tb__DOT__io_strictSources_12_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_431 
            = vlSymsp->TOP.tb__DOT__io_strictSources_12_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_432 
            = vlSymsp->TOP.tb__DOT__io_strictSources_13_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_427 
            = vlSymsp->TOP.tb__DOT__io_strictSources_12_key;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_433 
            = vlSymsp->TOP.tb__DOT__io_strictSources_12_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_434 
            = vlSymsp->TOP.tb__DOT__io_strictSources_12_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_435 
            = vlSymsp->TOP.tb__DOT__io_strictSources_12_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_436 
            = vlSymsp->TOP.tb__DOT__io_strictSources_12_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_428 
            = vlSymsp->TOP.tb__DOT__io_strictSources_13_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_429 
            = vlSymsp->TOP.tb__DOT__io_strictSources_13_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_430 
            = vlSymsp->TOP.tb__DOT__io_strictSources_13_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_431 
            = vlSymsp->TOP.tb__DOT__io_strictSources_13_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_432 
            = vlSymsp->TOP.tb__DOT__io_strictSources_12_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_427 
            = vlSymsp->TOP.tb__DOT__io_strictSources_13_key;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_16) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_443 
            = vlSymsp->TOP.tb__DOT__io_strictSources_15_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_444 
            = vlSymsp->TOP.tb__DOT__io_strictSources_15_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_445 
            = vlSymsp->TOP.tb__DOT__io_strictSources_15_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_446 
            = vlSymsp->TOP.tb__DOT__io_strictSources_15_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_438 
            = vlSymsp->TOP.tb__DOT__io_strictSources_14_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_439 
            = vlSymsp->TOP.tb__DOT__io_strictSources_14_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_440 
            = vlSymsp->TOP.tb__DOT__io_strictSources_14_counts_words8;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_443 
            = vlSymsp->TOP.tb__DOT__io_strictSources_14_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_444 
            = vlSymsp->TOP.tb__DOT__io_strictSources_14_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_445 
            = vlSymsp->TOP.tb__DOT__io_strictSources_14_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_446 
            = vlSymsp->TOP.tb__DOT__io_strictSources_14_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_438 
            = vlSymsp->TOP.tb__DOT__io_strictSources_15_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_439 
            = vlSymsp->TOP.tb__DOT__io_strictSources_15_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_440 
            = vlSymsp->TOP.tb__DOT__io_strictSources_15_counts_words8;
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__61(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__61\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_16) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_441 
            = vlSymsp->TOP.tb__DOT__io_strictSources_14_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_442 
            = vlSymsp->TOP.tb__DOT__io_strictSources_15_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_437 
            = vlSymsp->TOP.tb__DOT__io_strictSources_14_key;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_441 
            = vlSymsp->TOP.tb__DOT__io_strictSources_15_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_442 
            = vlSymsp->TOP.tb__DOT__io_strictSources_14_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_437 
            = vlSymsp->TOP.tb__DOT__io_strictSources_15_key;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_20) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_570 
            = vlSymsp->TOP.tb__DOT__io_strictSources_17_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_571 
            = vlSymsp->TOP.tb__DOT__io_strictSources_17_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_572 
            = vlSymsp->TOP.tb__DOT__io_strictSources_17_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_573 
            = vlSymsp->TOP.tb__DOT__io_strictSources_17_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_565 
            = vlSymsp->TOP.tb__DOT__io_strictSources_16_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_566 
            = vlSymsp->TOP.tb__DOT__io_strictSources_16_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_567 
            = vlSymsp->TOP.tb__DOT__io_strictSources_16_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_568 
            = vlSymsp->TOP.tb__DOT__io_strictSources_16_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_569 
            = vlSymsp->TOP.tb__DOT__io_strictSources_17_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_564 
            = vlSymsp->TOP.tb__DOT__io_strictSources_16_key;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_570 
            = vlSymsp->TOP.tb__DOT__io_strictSources_16_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_571 
            = vlSymsp->TOP.tb__DOT__io_strictSources_16_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_572 
            = vlSymsp->TOP.tb__DOT__io_strictSources_16_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_573 
            = vlSymsp->TOP.tb__DOT__io_strictSources_16_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_565 
            = vlSymsp->TOP.tb__DOT__io_strictSources_17_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_566 
            = vlSymsp->TOP.tb__DOT__io_strictSources_17_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_567 
            = vlSymsp->TOP.tb__DOT__io_strictSources_17_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_568 
            = vlSymsp->TOP.tb__DOT__io_strictSources_17_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_569 
            = vlSymsp->TOP.tb__DOT__io_strictSources_16_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_564 
            = vlSymsp->TOP.tb__DOT__io_strictSources_17_key;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_21) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_580 
            = vlSymsp->TOP.tb__DOT__io_strictSources_19_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_581 
            = vlSymsp->TOP.tb__DOT__io_strictSources_19_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_582 
            = vlSymsp->TOP.tb__DOT__io_strictSources_19_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_583 
            = vlSymsp->TOP.tb__DOT__io_strictSources_19_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_575 
            = vlSymsp->TOP.tb__DOT__io_strictSources_18_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_576 
            = vlSymsp->TOP.tb__DOT__io_strictSources_18_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_577 
            = vlSymsp->TOP.tb__DOT__io_strictSources_18_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_578 
            = vlSymsp->TOP.tb__DOT__io_strictSources_18_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_579 
            = vlSymsp->TOP.tb__DOT__io_strictSources_19_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_574 
            = vlSymsp->TOP.tb__DOT__io_strictSources_18_key;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_580 
            = vlSymsp->TOP.tb__DOT__io_strictSources_18_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_581 
            = vlSymsp->TOP.tb__DOT__io_strictSources_18_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_582 
            = vlSymsp->TOP.tb__DOT__io_strictSources_18_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_583 
            = vlSymsp->TOP.tb__DOT__io_strictSources_18_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_575 
            = vlSymsp->TOP.tb__DOT__io_strictSources_19_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_576 
            = vlSymsp->TOP.tb__DOT__io_strictSources_19_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_577 
            = vlSymsp->TOP.tb__DOT__io_strictSources_19_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_578 
            = vlSymsp->TOP.tb__DOT__io_strictSources_19_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_579 
            = vlSymsp->TOP.tb__DOT__io_strictSources_18_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_574 
            = vlSymsp->TOP.tb__DOT__io_strictSources_19_key;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_25) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_707 
            = vlSymsp->TOP.tb__DOT__io_strictSources_21_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_708 
            = vlSymsp->TOP.tb__DOT__io_strictSources_21_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_709 
            = vlSymsp->TOP.tb__DOT__io_strictSources_21_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_710 
            = vlSymsp->TOP.tb__DOT__io_strictSources_21_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_702 
            = vlSymsp->TOP.tb__DOT__io_strictSources_20_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_703 
            = vlSymsp->TOP.tb__DOT__io_strictSources_20_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_704 
            = vlSymsp->TOP.tb__DOT__io_strictSources_20_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_705 
            = vlSymsp->TOP.tb__DOT__io_strictSources_20_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_706 
            = vlSymsp->TOP.tb__DOT__io_strictSources_21_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_701 
            = vlSymsp->TOP.tb__DOT__io_strictSources_20_key;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_707 
            = vlSymsp->TOP.tb__DOT__io_strictSources_20_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_708 
            = vlSymsp->TOP.tb__DOT__io_strictSources_20_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_709 
            = vlSymsp->TOP.tb__DOT__io_strictSources_20_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_710 
            = vlSymsp->TOP.tb__DOT__io_strictSources_20_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_702 
            = vlSymsp->TOP.tb__DOT__io_strictSources_21_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_703 
            = vlSymsp->TOP.tb__DOT__io_strictSources_21_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_704 
            = vlSymsp->TOP.tb__DOT__io_strictSources_21_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_705 
            = vlSymsp->TOP.tb__DOT__io_strictSources_21_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_706 
            = vlSymsp->TOP.tb__DOT__io_strictSources_20_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_701 
            = vlSymsp->TOP.tb__DOT__io_strictSources_21_key;
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_717 
        = ((IData)(vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_26)
            ? (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_23_counts_bytes)
            : (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_22_counts_bytes));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__62(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_1__62\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_26) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_718 
            = vlSymsp->TOP.tb__DOT__io_strictSources_23_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_719 
            = vlSymsp->TOP.tb__DOT__io_strictSources_23_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_720 
            = vlSymsp->TOP.tb__DOT__io_strictSources_23_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_712 
            = vlSymsp->TOP.tb__DOT__io_strictSources_22_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_713 
            = vlSymsp->TOP.tb__DOT__io_strictSources_22_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_714 
            = vlSymsp->TOP.tb__DOT__io_strictSources_22_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_715 
            = vlSymsp->TOP.tb__DOT__io_strictSources_22_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_716 
            = vlSymsp->TOP.tb__DOT__io_strictSources_23_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_711 
            = vlSymsp->TOP.tb__DOT__io_strictSources_22_key;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_718 
            = vlSymsp->TOP.tb__DOT__io_strictSources_22_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_719 
            = vlSymsp->TOP.tb__DOT__io_strictSources_22_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_720 
            = vlSymsp->TOP.tb__DOT__io_strictSources_22_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_712 
            = vlSymsp->TOP.tb__DOT__io_strictSources_23_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_713 
            = vlSymsp->TOP.tb__DOT__io_strictSources_23_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_714 
            = vlSymsp->TOP.tb__DOT__io_strictSources_23_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_715 
            = vlSymsp->TOP.tb__DOT__io_strictSources_23_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_716 
            = vlSymsp->TOP.tb__DOT__io_strictSources_22_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_711 
            = vlSymsp->TOP.tb__DOT__io_strictSources_23_key;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_30) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_844 
            = vlSymsp->TOP.tb__DOT__io_strictSources_25_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_845 
            = vlSymsp->TOP.tb__DOT__io_strictSources_25_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_846 
            = vlSymsp->TOP.tb__DOT__io_strictSources_25_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_847 
            = vlSymsp->TOP.tb__DOT__io_strictSources_25_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_839 
            = vlSymsp->TOP.tb__DOT__io_strictSources_24_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_840 
            = vlSymsp->TOP.tb__DOT__io_strictSources_24_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_841 
            = vlSymsp->TOP.tb__DOT__io_strictSources_24_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_842 
            = vlSymsp->TOP.tb__DOT__io_strictSources_24_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_843 
            = vlSymsp->TOP.tb__DOT__io_strictSources_25_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_838 
            = vlSymsp->TOP.tb__DOT__io_strictSources_24_key;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_844 
            = vlSymsp->TOP.tb__DOT__io_strictSources_24_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_845 
            = vlSymsp->TOP.tb__DOT__io_strictSources_24_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_846 
            = vlSymsp->TOP.tb__DOT__io_strictSources_24_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_847 
            = vlSymsp->TOP.tb__DOT__io_strictSources_24_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_839 
            = vlSymsp->TOP.tb__DOT__io_strictSources_25_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_840 
            = vlSymsp->TOP.tb__DOT__io_strictSources_25_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_841 
            = vlSymsp->TOP.tb__DOT__io_strictSources_25_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_842 
            = vlSymsp->TOP.tb__DOT__io_strictSources_25_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_843 
            = vlSymsp->TOP.tb__DOT__io_strictSources_24_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_838 
            = vlSymsp->TOP.tb__DOT__io_strictSources_25_key;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_31) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_854 
            = vlSymsp->TOP.tb__DOT__io_strictSources_27_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_855 
            = vlSymsp->TOP.tb__DOT__io_strictSources_27_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_856 
            = vlSymsp->TOP.tb__DOT__io_strictSources_27_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_857 
            = vlSymsp->TOP.tb__DOT__io_strictSources_27_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_849 
            = vlSymsp->TOP.tb__DOT__io_strictSources_26_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_850 
            = vlSymsp->TOP.tb__DOT__io_strictSources_26_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_851 
            = vlSymsp->TOP.tb__DOT__io_strictSources_26_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_852 
            = vlSymsp->TOP.tb__DOT__io_strictSources_26_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_853 
            = vlSymsp->TOP.tb__DOT__io_strictSources_27_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_848 
            = vlSymsp->TOP.tb__DOT__io_strictSources_26_key;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_854 
            = vlSymsp->TOP.tb__DOT__io_strictSources_26_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_855 
            = vlSymsp->TOP.tb__DOT__io_strictSources_26_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_856 
            = vlSymsp->TOP.tb__DOT__io_strictSources_26_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_857 
            = vlSymsp->TOP.tb__DOT__io_strictSources_26_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_849 
            = vlSymsp->TOP.tb__DOT__io_strictSources_27_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_850 
            = vlSymsp->TOP.tb__DOT__io_strictSources_27_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_851 
            = vlSymsp->TOP.tb__DOT__io_strictSources_27_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_852 
            = vlSymsp->TOP.tb__DOT__io_strictSources_27_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_853 
            = vlSymsp->TOP.tb__DOT__io_strictSources_26_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_848 
            = vlSymsp->TOP.tb__DOT__io_strictSources_27_key;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_35) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_981 
            = vlSymsp->TOP.tb__DOT__io_strictSources_29_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_982 
            = vlSymsp->TOP.tb__DOT__io_strictSources_29_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_983 
            = vlSymsp->TOP.tb__DOT__io_strictSources_29_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_984 
            = vlSymsp->TOP.tb__DOT__io_strictSources_29_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_976 
            = vlSymsp->TOP.tb__DOT__io_strictSources_28_counts_bytes;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_981 
            = vlSymsp->TOP.tb__DOT__io_strictSources_28_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_982 
            = vlSymsp->TOP.tb__DOT__io_strictSources_28_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_983 
            = vlSymsp->TOP.tb__DOT__io_strictSources_28_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_984 
            = vlSymsp->TOP.tb__DOT__io_strictSources_28_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_976 
            = vlSymsp->TOP.tb__DOT__io_strictSources_29_counts_bytes;
    }
}
