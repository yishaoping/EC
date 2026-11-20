// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_GHBarrierBucketBank.h"
#include "Vtb__Syms.h"

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__3(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__available_13 = ((0x1dU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_40) 
                                        | (vlSelfRef.__PVT__buckets_seq_13 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_14 = ((0x1eU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_43) 
                                        | (vlSelfRef.__PVT__buckets_seq_14 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_11 = ((0x1bU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_34) 
                                        | (vlSelfRef.__PVT__buckets_seq_11 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_12 = ((0x1cU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_37) 
                                        | (vlSelfRef.__PVT__buckets_seq_12 
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
    vlSelfRef.__PVT__available_8 = ((0x18U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_25) 
                                       | (vlSelfRef.__PVT__buckets_seq_8 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
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
    vlSelfRef.__PVT__accepted_5 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_5));
    vlSelfRef.__PVT__accepted_4 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_4));
    vlSelfRef.__PVT__accepted_15 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_15));
    vlSelfRef.__PVT__accepted_3 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_3));
    vlSelfRef.__PVT__accepted_9 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_9));
    vlSelfRef.__PVT__accepted_10 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_10));
    vlSelfRef.__PVT__accepted_13 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_13));
    vlSelfRef.__PVT__accepted_14 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_14));
    vlSelfRef.__PVT__accepted_11 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_11));
    vlSelfRef.__PVT__accepted_12 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_12));
    vlSelfRef.__PVT__accepted_6 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_6));
    vlSelfRef.__PVT__accepted_7 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_7));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__4(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__4\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__accepted_8 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_8));
    vlSelfRef.__PVT__accepted = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                 & (IData)(vlSelfRef.__PVT__available_0));
    vlSelfRef.__PVT__accepted_1 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_1));
    vlSelfRef.__PVT__accepted_2 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_2));
    vlSelfRef.__PVT___countOverflow_5_T_2 = ((IData)(vlSelfRef.__PVT__accepted_5) 
                                             & (IData)(vlSelfRef.__PVT___GEN_75));
    vlSelfRef.__PVT___countOverflow_4_T_2 = ((IData)(vlSelfRef.__PVT__accepted_4) 
                                             & (IData)(vlSelfRef.__PVT___GEN_60));
    vlSelfRef.__PVT___countOverflow_15_T_2 = ((IData)(vlSelfRef.__PVT__accepted_15) 
                                              & (IData)(vlSelfRef.__PVT___GEN_225));
    vlSelfRef.__PVT___countOverflow_3_T_2 = ((IData)(vlSelfRef.__PVT__accepted_3) 
                                             & (IData)(vlSelfRef.__PVT___GEN_45));
    vlSelfRef.__PVT___countOverflow_9_T_2 = ((IData)(vlSelfRef.__PVT__accepted_9) 
                                             & (IData)(vlSelfRef.__PVT___GEN_135));
    vlSelfRef.__PVT___countOverflow_10_T_2 = ((IData)(vlSelfRef.__PVT__accepted_10) 
                                              & (IData)(vlSelfRef.__PVT___GEN_150));
    vlSelfRef.__PVT___countOverflow_13_T_2 = ((IData)(vlSelfRef.__PVT__accepted_13) 
                                              & (IData)(vlSelfRef.__PVT___GEN_195));
    vlSelfRef.__PVT___countOverflow_14_T_2 = ((IData)(vlSelfRef.__PVT__accepted_14) 
                                              & (IData)(vlSelfRef.__PVT___GEN_210));
    vlSelfRef.__PVT___countOverflow_11_T_2 = ((IData)(vlSelfRef.__PVT__accepted_11) 
                                              & (IData)(vlSelfRef.__PVT___GEN_165));
    vlSelfRef.__PVT___countOverflow_12_T_2 = ((IData)(vlSelfRef.__PVT__accepted_12) 
                                              & (IData)(vlSelfRef.__PVT___GEN_180));
    vlSelfRef.__PVT___countOverflow_6_T_2 = ((IData)(vlSelfRef.__PVT__accepted_6) 
                                             & (IData)(vlSelfRef.__PVT___GEN_90));
    vlSelfRef.__PVT___countOverflow_7_T_2 = ((IData)(vlSelfRef.__PVT__accepted_7) 
                                             & (IData)(vlSelfRef.__PVT___GEN_105));
    vlSelfRef.__PVT___countOverflow_8_T_2 = ((IData)(vlSelfRef.__PVT__accepted_8) 
                                             & (IData)(vlSelfRef.__PVT___GEN_120));
    vlSelfRef.__PVT___countOverflow_0_T_2 = ((IData)(vlSelfRef.__PVT__accepted) 
                                             & (IData)(vlSelfRef.__PVT___GEN_0));
    vlSelfRef.__PVT___countOverflow_1_T_2 = ((IData)(vlSelfRef.__PVT__accepted_1) 
                                             & (IData)(vlSelfRef.__PVT___GEN_15));
    vlSelfRef.__PVT___countOverflow_2_T_2 = ((IData)(vlSelfRef.__PVT__accepted_2) 
                                             & (IData)(vlSelfRef.__PVT___GEN_30));
    vlSelfRef.io_cycleOverflow = (((IData)(vlSelfRef.__PVT___countOverflow_15_T_2) 
                                   & (vlSelfRef.__PVT__buckets_requestCycleSum_15 
                                      > (0xffffffffffffffffULL 
                                         - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                  | (((IData)(vlSelfRef.__PVT___countOverflow_14_T_2) 
                                      & (vlSelfRef.__PVT__buckets_requestCycleSum_14 
                                         > (0xffffffffffffffffULL 
                                            - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                     | (((IData)(vlSelfRef.__PVT___countOverflow_13_T_2) 
                                         & (vlSelfRef.__PVT__buckets_requestCycleSum_13 
                                            > (0xffffffffffffffffULL 
                                               - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                        | (((IData)(vlSelfRef.__PVT___countOverflow_12_T_2) 
                                            & (vlSelfRef.__PVT__buckets_requestCycleSum_12 
                                               > (0xffffffffffffffffULL 
                                                  - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                           | (((IData)(vlSelfRef.__PVT___countOverflow_11_T_2) 
                                               & (vlSelfRef.__PVT__buckets_requestCycleSum_11 
                                                  > 
                                                  (0xffffffffffffffffULL 
                                                   - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                              | (((IData)(vlSelfRef.__PVT___countOverflow_10_T_2) 
                                                  & (vlSelfRef.__PVT__buckets_requestCycleSum_10 
                                                     > 
                                                     (0xffffffffffffffffULL 
                                                      - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                 | (((IData)(vlSelfRef.__PVT___countOverflow_9_T_2) 
                                                     & (vlSelfRef.__PVT__buckets_requestCycleSum_9 
                                                        > 
                                                        (0xffffffffffffffffULL 
                                                         - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                    | (((IData)(vlSelfRef.__PVT___countOverflow_8_T_2) 
                                                        & (vlSelfRef.__PVT__buckets_requestCycleSum_8 
                                                           > 
                                                           (0xffffffffffffffffULL 
                                                            - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                       | (((IData)(vlSelfRef.__PVT___countOverflow_7_T_2) 
                                                           & (vlSelfRef.buckets_requestCycleSum_7 
                                                              > 
                                                              (0xffffffffffffffffULL 
                                                               - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                          | (((IData)(vlSelfRef.__PVT___countOverflow_6_T_2) 
                                                              & (vlSelfRef.__PVT__buckets_requestCycleSum_6 
                                                                 > 
                                                                 (0xffffffffffffffffULL 
                                                                  - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                             | (((IData)(vlSelfRef.__PVT___countOverflow_5_T_2) 
                                                                 & (vlSelfRef.__PVT__buckets_requestCycleSum_5 
                                                                    > 
                                                                    (0xffffffffffffffffULL 
                                                                     - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                                | (((IData)(vlSelfRef.__PVT___countOverflow_4_T_2) 
                                                                    & (vlSelfRef.__PVT__buckets_requestCycleSum_4 
                                                                       > 
                                                                       (0xffffffffffffffffULL 
                                                                        - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                                   | (((IData)(vlSelfRef.__PVT___countOverflow_3_T_2) 
                                                                       & (vlSelfRef.__PVT__buckets_requestCycleSum_3 
                                                                          > 
                                                                          (0xffffffffffffffffULL 
                                                                           - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                                      | (((IData)(vlSelfRef.__PVT___countOverflow_2_T_2) 
                                                                          & (vlSelfRef.__PVT__buckets_requestCycleSum_2 
                                                                             > 
                                                                             (0xffffffffffffffffULL 
                                                                              - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                                         | (((IData)(vlSelfRef.__PVT___countOverflow_1_T_2) 
                                                                             & (vlSelfRef.__PVT__buckets_requestCycleSum_1 
                                                                                > 
                                                                                (0xffffffffffffffffULL 
                                                                                - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                                            | ((IData)(vlSelfRef.__PVT___countOverflow_0_T_2) 
                                                                               & (vlSelfRef.__PVT__buckets_requestCycleSum_0 
                                                                                > 
                                                                                (0xffffffffffffffffULL 
                                                                                - vlSymsp->TOP.tb__DOT__io_currentCycle))))))))))))))))));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_2__2(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_2__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_9;
    VlWide<3>/*95:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_13;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_21;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_25;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_29;
    VlWide<3>/*95:0*/ __Vtemp_31;
    VlWide<3>/*95:0*/ __Vtemp_32;
    VlWide<3>/*95:0*/ __Vtemp_34;
    VlWide<3>/*95:0*/ __Vtemp_35;
    VlWide<3>/*95:0*/ __Vtemp_37;
    VlWide<3>/*95:0*/ __Vtemp_41;
    VlWide<3>/*95:0*/ __Vtemp_42;
    VlWide<3>/*95:0*/ __Vtemp_43;
    VlWide<3>/*95:0*/ __Vtemp_45;
    VlWide<3>/*95:0*/ __Vtemp_47;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_49;
    VlWide<3>/*95:0*/ __Vtemp_51;
    VlWide<3>/*95:0*/ __Vtemp_52;
    VlWide<3>/*95:0*/ __Vtemp_54;
    VlWide<3>/*95:0*/ __Vtemp_57;
    VlWide<3>/*95:0*/ __Vtemp_58;
    VlWide<3>/*95:0*/ __Vtemp_59;
    VlWide<3>/*95:0*/ __Vtemp_61;
    VlWide<3>/*95:0*/ __Vtemp_63;
    VlWide<3>/*95:0*/ __Vtemp_64;
    VlWide<3>/*95:0*/ __Vtemp_65;
    VlWide<3>/*95:0*/ __Vtemp_67;
    VlWide<3>/*95:0*/ __Vtemp_68;
    VlWide<3>/*95:0*/ __Vtemp_70;
    VlWide<3>/*95:0*/ __Vtemp_71;
    VlWide<3>/*95:0*/ __Vtemp_73;
    VlWide<3>/*95:0*/ __Vtemp_74;
    // Body
    vlSelfRef.__PVT___GEN_225 = ((~ (IData)(vlSelfRef.__PVT__resolving_15)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_15));
    __Vtemp_5[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_0)
                              ? vlSelfRef.__PVT__buckets_count_0
                              : 0ULL));
    __Vtemp_5[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_0)
                               ? vlSelfRef.__PVT__buckets_count_0
                               : 0ULL) >> 0x20U));
    __Vtemp_5[2U] = 0U;
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_1)
                              ? vlSelfRef.__PVT__buckets_count_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_1)
                               ? vlSelfRef.__PVT__buckets_count_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    VL_ADD_W(3, __Vtemp_7, __Vtemp_5, __Vtemp_6);
    __Vtemp_9[0U] = __Vtemp_7[0U];
    __Vtemp_9[1U] = __Vtemp_7[1U];
    __Vtemp_9[2U] = (1U & __Vtemp_7[2U]);
    __Vtemp_11[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_2)
                               ? vlSelfRef.__PVT__buckets_count_2
                               : 0ULL));
    __Vtemp_11[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_2)
                                ? vlSelfRef.__PVT__buckets_count_2
                                : 0ULL) >> 0x20U));
    __Vtemp_11[2U] = 0U;
    __Vtemp_12[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_3)
                               ? vlSelfRef.__PVT__buckets_count_3
                               : 0ULL));
    __Vtemp_12[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_3)
                                ? vlSelfRef.__PVT__buckets_count_3
                                : 0ULL) >> 0x20U));
    __Vtemp_12[2U] = 0U;
    VL_ADD_W(3, __Vtemp_13, __Vtemp_11, __Vtemp_12);
    __Vtemp_15[0U] = __Vtemp_13[0U];
    __Vtemp_15[1U] = __Vtemp_13[1U];
    __Vtemp_15[2U] = (1U & __Vtemp_13[2U]);
    VL_ADD_W(3, __Vtemp_16, __Vtemp_9, __Vtemp_15);
    __Vtemp_18[0U] = __Vtemp_16[0U];
    __Vtemp_18[1U] = __Vtemp_16[1U];
    __Vtemp_18[2U] = (3U & __Vtemp_16[2U]);
    __Vtemp_21[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_4)
                               ? vlSelfRef.__PVT__buckets_count_4
                               : 0ULL));
    __Vtemp_21[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_4)
                                ? vlSelfRef.__PVT__buckets_count_4
                                : 0ULL) >> 0x20U));
    __Vtemp_21[2U] = 0U;
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_5)
                               ? vlSelfRef.__PVT__buckets_count_5
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_5)
                                ? vlSelfRef.__PVT__buckets_count_5
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    VL_ADD_W(3, __Vtemp_23, __Vtemp_21, __Vtemp_22);
    __Vtemp_25[0U] = __Vtemp_23[0U];
    __Vtemp_25[1U] = __Vtemp_23[1U];
    __Vtemp_25[2U] = (1U & __Vtemp_23[2U]);
    __Vtemp_27[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_6)
                               ? vlSelfRef.__PVT__buckets_count_6
                               : 0ULL));
    __Vtemp_27[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_6)
                                ? vlSelfRef.__PVT__buckets_count_6
                                : 0ULL) >> 0x20U));
    __Vtemp_27[2U] = 0U;
    __Vtemp_28[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_7)
                               ? vlSelfRef.buckets_count_7
                               : 0ULL));
    __Vtemp_28[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_7)
                                ? vlSelfRef.buckets_count_7
                                : 0ULL) >> 0x20U));
    __Vtemp_28[2U] = 0U;
    VL_ADD_W(3, __Vtemp_29, __Vtemp_27, __Vtemp_28);
    __Vtemp_31[0U] = __Vtemp_29[0U];
    __Vtemp_31[1U] = __Vtemp_29[1U];
    __Vtemp_31[2U] = (1U & __Vtemp_29[2U]);
    VL_ADD_W(3, __Vtemp_32, __Vtemp_25, __Vtemp_31);
    __Vtemp_34[0U] = __Vtemp_32[0U];
    __Vtemp_34[1U] = __Vtemp_32[1U];
    __Vtemp_34[2U] = (3U & __Vtemp_32[2U]);
    VL_ADD_W(3, __Vtemp_35, __Vtemp_18, __Vtemp_34);
    __Vtemp_37[0U] = __Vtemp_35[0U];
    __Vtemp_37[1U] = __Vtemp_35[1U];
    __Vtemp_37[2U] = (7U & __Vtemp_35[2U]);
    __Vtemp_41[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_8)
                               ? vlSelfRef.__PVT__buckets_count_8
                               : 0ULL));
    __Vtemp_41[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_8)
                                ? vlSelfRef.__PVT__buckets_count_8
                                : 0ULL) >> 0x20U));
    __Vtemp_41[2U] = 0U;
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_9)
                               ? vlSelfRef.__PVT__buckets_count_9
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_9)
                                ? vlSelfRef.__PVT__buckets_count_9
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    VL_ADD_W(3, __Vtemp_43, __Vtemp_41, __Vtemp_42);
    __Vtemp_45[0U] = __Vtemp_43[0U];
    __Vtemp_45[1U] = __Vtemp_43[1U];
    __Vtemp_45[2U] = (1U & __Vtemp_43[2U]);
    __Vtemp_47[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_10)
                               ? vlSelfRef.__PVT__buckets_count_10
                               : 0ULL));
    __Vtemp_47[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_10)
                                ? vlSelfRef.__PVT__buckets_count_10
                                : 0ULL) >> 0x20U));
    __Vtemp_47[2U] = 0U;
    __Vtemp_48[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_11)
                               ? vlSelfRef.__PVT__buckets_count_11
                               : 0ULL));
    __Vtemp_48[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_11)
                                ? vlSelfRef.__PVT__buckets_count_11
                                : 0ULL) >> 0x20U));
    __Vtemp_48[2U] = 0U;
    VL_ADD_W(3, __Vtemp_49, __Vtemp_47, __Vtemp_48);
    __Vtemp_51[0U] = __Vtemp_49[0U];
    __Vtemp_51[1U] = __Vtemp_49[1U];
    __Vtemp_51[2U] = (1U & __Vtemp_49[2U]);
    VL_ADD_W(3, __Vtemp_52, __Vtemp_45, __Vtemp_51);
    __Vtemp_54[0U] = __Vtemp_52[0U];
    __Vtemp_54[1U] = __Vtemp_52[1U];
    __Vtemp_54[2U] = (3U & __Vtemp_52[2U]);
    __Vtemp_57[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_12)
                               ? vlSelfRef.__PVT__buckets_count_12
                               : 0ULL));
    __Vtemp_57[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_12)
                                ? vlSelfRef.__PVT__buckets_count_12
                                : 0ULL) >> 0x20U));
    __Vtemp_57[2U] = 0U;
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_13)
                               ? vlSelfRef.__PVT__buckets_count_13
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_13)
                                ? vlSelfRef.__PVT__buckets_count_13
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    VL_ADD_W(3, __Vtemp_59, __Vtemp_57, __Vtemp_58);
    __Vtemp_61[0U] = __Vtemp_59[0U];
    __Vtemp_61[1U] = __Vtemp_59[1U];
    __Vtemp_61[2U] = (1U & __Vtemp_59[2U]);
    __Vtemp_63[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_14)
                               ? vlSelfRef.__PVT__buckets_count_14
                               : 0ULL));
    __Vtemp_63[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_14)
                                ? vlSelfRef.__PVT__buckets_count_14
                                : 0ULL) >> 0x20U));
    __Vtemp_63[2U] = 0U;
    __Vtemp_64[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_15)
                               ? vlSelfRef.__PVT__buckets_count_15
                               : 0ULL));
    __Vtemp_64[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_15)
                                ? vlSelfRef.__PVT__buckets_count_15
                                : 0ULL) >> 0x20U));
    __Vtemp_64[2U] = 0U;
    VL_ADD_W(3, __Vtemp_65, __Vtemp_63, __Vtemp_64);
    __Vtemp_67[0U] = __Vtemp_65[0U];
    __Vtemp_67[1U] = __Vtemp_65[1U];
    __Vtemp_67[2U] = (1U & __Vtemp_65[2U]);
    VL_ADD_W(3, __Vtemp_68, __Vtemp_61, __Vtemp_67);
    __Vtemp_70[0U] = __Vtemp_68[0U];
    __Vtemp_70[1U] = __Vtemp_68[1U];
    __Vtemp_70[2U] = (3U & __Vtemp_68[2U]);
    VL_ADD_W(3, __Vtemp_71, __Vtemp_54, __Vtemp_70);
    __Vtemp_73[0U] = __Vtemp_71[0U];
    __Vtemp_73[1U] = __Vtemp_71[1U];
    __Vtemp_73[2U] = (7U & __Vtemp_71[2U]);
    VL_ADD_W(3, __Vtemp_74, __Vtemp_37, __Vtemp_73);
    vlSelfRef.io_resolvedCount[0U] = __Vtemp_74[0U];
    vlSelfRef.io_resolvedCount[1U] = __Vtemp_74[1U];
    vlSelfRef.io_resolvedCount[2U] = (0xfU & __Vtemp_74[2U]);
    vlSelfRef.__PVT___canAccept_T_46 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_15)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_15)));
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
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_2__3(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_2__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_8 = ((0x28U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_25) 
                                       | (vlSelfRef.__PVT__buckets_seq_8 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_9 = ((0x29U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_28) 
                                       | (vlSelfRef.__PVT__buckets_seq_9 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_10 = ((0x2aU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_31) 
                                        | (vlSelfRef.__PVT__buckets_seq_10 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_11 = ((0x2bU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_34) 
                                        | (vlSelfRef.__PVT__buckets_seq_11 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_12 = ((0x2cU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_37) 
                                        | (vlSelfRef.__PVT__buckets_seq_12 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_13 = ((0x2dU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_40) 
                                        | (vlSelfRef.__PVT__buckets_seq_13 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_14 = ((0x2eU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_43) 
                                        | (vlSelfRef.__PVT__buckets_seq_14 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_15 = ((0x2fU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_46) 
                                        | (vlSelfRef.__PVT__buckets_seq_15 
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
    vlSelfRef.__PVT__accepted_8 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_8));
    vlSelfRef.__PVT__accepted_9 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_9));
    vlSelfRef.__PVT__accepted_10 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_10));
    vlSelfRef.__PVT__accepted_11 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_11));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_2__2(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_2__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_9;
    VlWide<3>/*95:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_13;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_21;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_25;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_29;
    VlWide<3>/*95:0*/ __Vtemp_31;
    VlWide<3>/*95:0*/ __Vtemp_32;
    VlWide<3>/*95:0*/ __Vtemp_34;
    VlWide<3>/*95:0*/ __Vtemp_35;
    VlWide<3>/*95:0*/ __Vtemp_37;
    VlWide<3>/*95:0*/ __Vtemp_41;
    VlWide<3>/*95:0*/ __Vtemp_42;
    VlWide<3>/*95:0*/ __Vtemp_43;
    VlWide<3>/*95:0*/ __Vtemp_45;
    VlWide<3>/*95:0*/ __Vtemp_47;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_49;
    VlWide<3>/*95:0*/ __Vtemp_51;
    VlWide<3>/*95:0*/ __Vtemp_52;
    VlWide<3>/*95:0*/ __Vtemp_54;
    VlWide<3>/*95:0*/ __Vtemp_57;
    VlWide<3>/*95:0*/ __Vtemp_58;
    VlWide<3>/*95:0*/ __Vtemp_59;
    VlWide<3>/*95:0*/ __Vtemp_61;
    VlWide<3>/*95:0*/ __Vtemp_63;
    VlWide<3>/*95:0*/ __Vtemp_64;
    VlWide<3>/*95:0*/ __Vtemp_65;
    VlWide<3>/*95:0*/ __Vtemp_67;
    VlWide<3>/*95:0*/ __Vtemp_68;
    VlWide<3>/*95:0*/ __Vtemp_70;
    VlWide<3>/*95:0*/ __Vtemp_71;
    VlWide<3>/*95:0*/ __Vtemp_73;
    VlWide<3>/*95:0*/ __Vtemp_74;
    // Body
    vlSelfRef.__PVT___GEN_30 = ((~ (IData)(vlSelfRef.__PVT__resolving_2)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_2));
    __Vtemp_5[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_0)
                              ? vlSelfRef.__PVT__buckets_count_0
                              : 0ULL));
    __Vtemp_5[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_0)
                               ? vlSelfRef.__PVT__buckets_count_0
                               : 0ULL) >> 0x20U));
    __Vtemp_5[2U] = 0U;
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_1)
                              ? vlSelfRef.__PVT__buckets_count_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_1)
                               ? vlSelfRef.__PVT__buckets_count_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    VL_ADD_W(3, __Vtemp_7, __Vtemp_5, __Vtemp_6);
    __Vtemp_9[0U] = __Vtemp_7[0U];
    __Vtemp_9[1U] = __Vtemp_7[1U];
    __Vtemp_9[2U] = (1U & __Vtemp_7[2U]);
    __Vtemp_11[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_2)
                               ? vlSelfRef.__PVT__buckets_count_2
                               : 0ULL));
    __Vtemp_11[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_2)
                                ? vlSelfRef.__PVT__buckets_count_2
                                : 0ULL) >> 0x20U));
    __Vtemp_11[2U] = 0U;
    __Vtemp_12[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_3)
                               ? vlSelfRef.__PVT__buckets_count_3
                               : 0ULL));
    __Vtemp_12[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_3)
                                ? vlSelfRef.__PVT__buckets_count_3
                                : 0ULL) >> 0x20U));
    __Vtemp_12[2U] = 0U;
    VL_ADD_W(3, __Vtemp_13, __Vtemp_11, __Vtemp_12);
    __Vtemp_15[0U] = __Vtemp_13[0U];
    __Vtemp_15[1U] = __Vtemp_13[1U];
    __Vtemp_15[2U] = (1U & __Vtemp_13[2U]);
    VL_ADD_W(3, __Vtemp_16, __Vtemp_9, __Vtemp_15);
    __Vtemp_18[0U] = __Vtemp_16[0U];
    __Vtemp_18[1U] = __Vtemp_16[1U];
    __Vtemp_18[2U] = (3U & __Vtemp_16[2U]);
    __Vtemp_21[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_4)
                               ? vlSelfRef.__PVT__buckets_count_4
                               : 0ULL));
    __Vtemp_21[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_4)
                                ? vlSelfRef.__PVT__buckets_count_4
                                : 0ULL) >> 0x20U));
    __Vtemp_21[2U] = 0U;
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_5)
                               ? vlSelfRef.__PVT__buckets_count_5
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_5)
                                ? vlSelfRef.__PVT__buckets_count_5
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    VL_ADD_W(3, __Vtemp_23, __Vtemp_21, __Vtemp_22);
    __Vtemp_25[0U] = __Vtemp_23[0U];
    __Vtemp_25[1U] = __Vtemp_23[1U];
    __Vtemp_25[2U] = (1U & __Vtemp_23[2U]);
    __Vtemp_27[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_6)
                               ? vlSelfRef.__PVT__buckets_count_6
                               : 0ULL));
    __Vtemp_27[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_6)
                                ? vlSelfRef.__PVT__buckets_count_6
                                : 0ULL) >> 0x20U));
    __Vtemp_27[2U] = 0U;
    __Vtemp_28[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_7)
                               ? vlSelfRef.buckets_count_7
                               : 0ULL));
    __Vtemp_28[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_7)
                                ? vlSelfRef.buckets_count_7
                                : 0ULL) >> 0x20U));
    __Vtemp_28[2U] = 0U;
    VL_ADD_W(3, __Vtemp_29, __Vtemp_27, __Vtemp_28);
    __Vtemp_31[0U] = __Vtemp_29[0U];
    __Vtemp_31[1U] = __Vtemp_29[1U];
    __Vtemp_31[2U] = (1U & __Vtemp_29[2U]);
    VL_ADD_W(3, __Vtemp_32, __Vtemp_25, __Vtemp_31);
    __Vtemp_34[0U] = __Vtemp_32[0U];
    __Vtemp_34[1U] = __Vtemp_32[1U];
    __Vtemp_34[2U] = (3U & __Vtemp_32[2U]);
    VL_ADD_W(3, __Vtemp_35, __Vtemp_18, __Vtemp_34);
    __Vtemp_37[0U] = __Vtemp_35[0U];
    __Vtemp_37[1U] = __Vtemp_35[1U];
    __Vtemp_37[2U] = (7U & __Vtemp_35[2U]);
    __Vtemp_41[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_8)
                               ? vlSelfRef.__PVT__buckets_count_8
                               : 0ULL));
    __Vtemp_41[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_8)
                                ? vlSelfRef.__PVT__buckets_count_8
                                : 0ULL) >> 0x20U));
    __Vtemp_41[2U] = 0U;
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_9)
                               ? vlSelfRef.__PVT__buckets_count_9
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_9)
                                ? vlSelfRef.__PVT__buckets_count_9
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    VL_ADD_W(3, __Vtemp_43, __Vtemp_41, __Vtemp_42);
    __Vtemp_45[0U] = __Vtemp_43[0U];
    __Vtemp_45[1U] = __Vtemp_43[1U];
    __Vtemp_45[2U] = (1U & __Vtemp_43[2U]);
    __Vtemp_47[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_10)
                               ? vlSelfRef.__PVT__buckets_count_10
                               : 0ULL));
    __Vtemp_47[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_10)
                                ? vlSelfRef.__PVT__buckets_count_10
                                : 0ULL) >> 0x20U));
    __Vtemp_47[2U] = 0U;
    __Vtemp_48[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_11)
                               ? vlSelfRef.__PVT__buckets_count_11
                               : 0ULL));
    __Vtemp_48[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_11)
                                ? vlSelfRef.__PVT__buckets_count_11
                                : 0ULL) >> 0x20U));
    __Vtemp_48[2U] = 0U;
    VL_ADD_W(3, __Vtemp_49, __Vtemp_47, __Vtemp_48);
    __Vtemp_51[0U] = __Vtemp_49[0U];
    __Vtemp_51[1U] = __Vtemp_49[1U];
    __Vtemp_51[2U] = (1U & __Vtemp_49[2U]);
    VL_ADD_W(3, __Vtemp_52, __Vtemp_45, __Vtemp_51);
    __Vtemp_54[0U] = __Vtemp_52[0U];
    __Vtemp_54[1U] = __Vtemp_52[1U];
    __Vtemp_54[2U] = (3U & __Vtemp_52[2U]);
    __Vtemp_57[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_12)
                               ? vlSelfRef.__PVT__buckets_count_12
                               : 0ULL));
    __Vtemp_57[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_12)
                                ? vlSelfRef.__PVT__buckets_count_12
                                : 0ULL) >> 0x20U));
    __Vtemp_57[2U] = 0U;
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_13)
                               ? vlSelfRef.__PVT__buckets_count_13
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_13)
                                ? vlSelfRef.__PVT__buckets_count_13
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    VL_ADD_W(3, __Vtemp_59, __Vtemp_57, __Vtemp_58);
    __Vtemp_61[0U] = __Vtemp_59[0U];
    __Vtemp_61[1U] = __Vtemp_59[1U];
    __Vtemp_61[2U] = (1U & __Vtemp_59[2U]);
    __Vtemp_63[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_14)
                               ? vlSelfRef.__PVT__buckets_count_14
                               : 0ULL));
    __Vtemp_63[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_14)
                                ? vlSelfRef.__PVT__buckets_count_14
                                : 0ULL) >> 0x20U));
    __Vtemp_63[2U] = 0U;
    __Vtemp_64[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_15)
                               ? vlSelfRef.__PVT__buckets_count_15
                               : 0ULL));
    __Vtemp_64[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_15)
                                ? vlSelfRef.__PVT__buckets_count_15
                                : 0ULL) >> 0x20U));
    __Vtemp_64[2U] = 0U;
    VL_ADD_W(3, __Vtemp_65, __Vtemp_63, __Vtemp_64);
    __Vtemp_67[0U] = __Vtemp_65[0U];
    __Vtemp_67[1U] = __Vtemp_65[1U];
    __Vtemp_67[2U] = (1U & __Vtemp_65[2U]);
    VL_ADD_W(3, __Vtemp_68, __Vtemp_61, __Vtemp_67);
    __Vtemp_70[0U] = __Vtemp_68[0U];
    __Vtemp_70[1U] = __Vtemp_68[1U];
    __Vtemp_70[2U] = (3U & __Vtemp_68[2U]);
    VL_ADD_W(3, __Vtemp_71, __Vtemp_54, __Vtemp_70);
    __Vtemp_73[0U] = __Vtemp_71[0U];
    __Vtemp_73[1U] = __Vtemp_71[1U];
    __Vtemp_73[2U] = (7U & __Vtemp_71[2U]);
    VL_ADD_W(3, __Vtemp_74, __Vtemp_37, __Vtemp_73);
    vlSelfRef.io_resolvedCount[0U] = __Vtemp_74[0U];
    vlSelfRef.io_resolvedCount[1U] = __Vtemp_74[1U];
    vlSelfRef.io_resolvedCount[2U] = (0xfU & __Vtemp_74[2U]);
    vlSelfRef.__PVT___canAccept_T_7 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_2)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_2)));
    vlSelfRef.__PVT__available_5 = ((0x25U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x24U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_15 = ((0x2fU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_46) 
                                        | (vlSelfRef.__PVT__buckets_seq_15 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x23U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_9 = ((0x29U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_28) 
                                       | (vlSelfRef.__PVT__buckets_seq_9 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_10 = ((0x2aU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_31) 
                                        | (vlSelfRef.__PVT__buckets_seq_10 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_2__3(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_2__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__available_13 = ((0x2dU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_40) 
                                        | (vlSelfRef.__PVT__buckets_seq_13 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_14 = ((0x2eU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_43) 
                                        | (vlSelfRef.__PVT__buckets_seq_14 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_11 = ((0x2bU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_34) 
                                        | (vlSelfRef.__PVT__buckets_seq_11 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_12 = ((0x2cU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_37) 
                                        | (vlSelfRef.__PVT__buckets_seq_12 
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
    vlSelfRef.__PVT__available_8 = ((0x28U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_25) 
                                       | (vlSelfRef.__PVT__buckets_seq_8 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
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
    vlSelfRef.__PVT__accepted_5 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_5));
    vlSelfRef.__PVT__accepted_4 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_4));
    vlSelfRef.__PVT__accepted_15 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_15));
    vlSelfRef.__PVT__accepted_3 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_3));
    vlSelfRef.__PVT__accepted_9 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_9));
    vlSelfRef.__PVT__accepted_10 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_10));
    vlSelfRef.__PVT__accepted_13 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_13));
    vlSelfRef.__PVT__accepted_14 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_14));
    vlSelfRef.__PVT__accepted_11 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_11));
    vlSelfRef.__PVT__accepted_12 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_12));
    vlSelfRef.__PVT__accepted_6 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_6));
    vlSelfRef.__PVT__accepted_7 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_7));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_3__2(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_3__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_9;
    VlWide<3>/*95:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_13;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_21;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_25;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_29;
    VlWide<3>/*95:0*/ __Vtemp_31;
    VlWide<3>/*95:0*/ __Vtemp_32;
    VlWide<3>/*95:0*/ __Vtemp_34;
    VlWide<3>/*95:0*/ __Vtemp_35;
    VlWide<3>/*95:0*/ __Vtemp_37;
    VlWide<3>/*95:0*/ __Vtemp_41;
    VlWide<3>/*95:0*/ __Vtemp_42;
    VlWide<3>/*95:0*/ __Vtemp_43;
    VlWide<3>/*95:0*/ __Vtemp_45;
    VlWide<3>/*95:0*/ __Vtemp_47;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_49;
    VlWide<3>/*95:0*/ __Vtemp_51;
    VlWide<3>/*95:0*/ __Vtemp_52;
    VlWide<3>/*95:0*/ __Vtemp_54;
    VlWide<3>/*95:0*/ __Vtemp_57;
    VlWide<3>/*95:0*/ __Vtemp_58;
    VlWide<3>/*95:0*/ __Vtemp_59;
    VlWide<3>/*95:0*/ __Vtemp_61;
    VlWide<3>/*95:0*/ __Vtemp_63;
    VlWide<3>/*95:0*/ __Vtemp_64;
    VlWide<3>/*95:0*/ __Vtemp_65;
    VlWide<3>/*95:0*/ __Vtemp_67;
    VlWide<3>/*95:0*/ __Vtemp_68;
    VlWide<3>/*95:0*/ __Vtemp_70;
    VlWide<3>/*95:0*/ __Vtemp_71;
    VlWide<3>/*95:0*/ __Vtemp_73;
    VlWide<3>/*95:0*/ __Vtemp_74;
    // Body
    vlSelfRef.__PVT___GEN_225 = ((~ (IData)(vlSelfRef.__PVT__resolving_15)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_15));
    __Vtemp_5[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_0)
                              ? vlSelfRef.__PVT__buckets_count_0
                              : 0ULL));
    __Vtemp_5[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_0)
                               ? vlSelfRef.__PVT__buckets_count_0
                               : 0ULL) >> 0x20U));
    __Vtemp_5[2U] = 0U;
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_1)
                              ? vlSelfRef.__PVT__buckets_count_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_1)
                               ? vlSelfRef.__PVT__buckets_count_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    VL_ADD_W(3, __Vtemp_7, __Vtemp_5, __Vtemp_6);
    __Vtemp_9[0U] = __Vtemp_7[0U];
    __Vtemp_9[1U] = __Vtemp_7[1U];
    __Vtemp_9[2U] = (1U & __Vtemp_7[2U]);
    __Vtemp_11[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_2)
                               ? vlSelfRef.__PVT__buckets_count_2
                               : 0ULL));
    __Vtemp_11[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_2)
                                ? vlSelfRef.__PVT__buckets_count_2
                                : 0ULL) >> 0x20U));
    __Vtemp_11[2U] = 0U;
    __Vtemp_12[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_3)
                               ? vlSelfRef.__PVT__buckets_count_3
                               : 0ULL));
    __Vtemp_12[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_3)
                                ? vlSelfRef.__PVT__buckets_count_3
                                : 0ULL) >> 0x20U));
    __Vtemp_12[2U] = 0U;
    VL_ADD_W(3, __Vtemp_13, __Vtemp_11, __Vtemp_12);
    __Vtemp_15[0U] = __Vtemp_13[0U];
    __Vtemp_15[1U] = __Vtemp_13[1U];
    __Vtemp_15[2U] = (1U & __Vtemp_13[2U]);
    VL_ADD_W(3, __Vtemp_16, __Vtemp_9, __Vtemp_15);
    __Vtemp_18[0U] = __Vtemp_16[0U];
    __Vtemp_18[1U] = __Vtemp_16[1U];
    __Vtemp_18[2U] = (3U & __Vtemp_16[2U]);
    __Vtemp_21[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_4)
                               ? vlSelfRef.__PVT__buckets_count_4
                               : 0ULL));
    __Vtemp_21[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_4)
                                ? vlSelfRef.__PVT__buckets_count_4
                                : 0ULL) >> 0x20U));
    __Vtemp_21[2U] = 0U;
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_5)
                               ? vlSelfRef.__PVT__buckets_count_5
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_5)
                                ? vlSelfRef.__PVT__buckets_count_5
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    VL_ADD_W(3, __Vtemp_23, __Vtemp_21, __Vtemp_22);
    __Vtemp_25[0U] = __Vtemp_23[0U];
    __Vtemp_25[1U] = __Vtemp_23[1U];
    __Vtemp_25[2U] = (1U & __Vtemp_23[2U]);
    __Vtemp_27[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_6)
                               ? vlSelfRef.__PVT__buckets_count_6
                               : 0ULL));
    __Vtemp_27[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_6)
                                ? vlSelfRef.__PVT__buckets_count_6
                                : 0ULL) >> 0x20U));
    __Vtemp_27[2U] = 0U;
    __Vtemp_28[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_7)
                               ? vlSelfRef.buckets_count_7
                               : 0ULL));
    __Vtemp_28[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_7)
                                ? vlSelfRef.buckets_count_7
                                : 0ULL) >> 0x20U));
    __Vtemp_28[2U] = 0U;
    VL_ADD_W(3, __Vtemp_29, __Vtemp_27, __Vtemp_28);
    __Vtemp_31[0U] = __Vtemp_29[0U];
    __Vtemp_31[1U] = __Vtemp_29[1U];
    __Vtemp_31[2U] = (1U & __Vtemp_29[2U]);
    VL_ADD_W(3, __Vtemp_32, __Vtemp_25, __Vtemp_31);
    __Vtemp_34[0U] = __Vtemp_32[0U];
    __Vtemp_34[1U] = __Vtemp_32[1U];
    __Vtemp_34[2U] = (3U & __Vtemp_32[2U]);
    VL_ADD_W(3, __Vtemp_35, __Vtemp_18, __Vtemp_34);
    __Vtemp_37[0U] = __Vtemp_35[0U];
    __Vtemp_37[1U] = __Vtemp_35[1U];
    __Vtemp_37[2U] = (7U & __Vtemp_35[2U]);
    __Vtemp_41[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_8)
                               ? vlSelfRef.__PVT__buckets_count_8
                               : 0ULL));
    __Vtemp_41[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_8)
                                ? vlSelfRef.__PVT__buckets_count_8
                                : 0ULL) >> 0x20U));
    __Vtemp_41[2U] = 0U;
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_9)
                               ? vlSelfRef.__PVT__buckets_count_9
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_9)
                                ? vlSelfRef.__PVT__buckets_count_9
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    VL_ADD_W(3, __Vtemp_43, __Vtemp_41, __Vtemp_42);
    __Vtemp_45[0U] = __Vtemp_43[0U];
    __Vtemp_45[1U] = __Vtemp_43[1U];
    __Vtemp_45[2U] = (1U & __Vtemp_43[2U]);
    __Vtemp_47[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_10)
                               ? vlSelfRef.__PVT__buckets_count_10
                               : 0ULL));
    __Vtemp_47[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_10)
                                ? vlSelfRef.__PVT__buckets_count_10
                                : 0ULL) >> 0x20U));
    __Vtemp_47[2U] = 0U;
    __Vtemp_48[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_11)
                               ? vlSelfRef.__PVT__buckets_count_11
                               : 0ULL));
    __Vtemp_48[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_11)
                                ? vlSelfRef.__PVT__buckets_count_11
                                : 0ULL) >> 0x20U));
    __Vtemp_48[2U] = 0U;
    VL_ADD_W(3, __Vtemp_49, __Vtemp_47, __Vtemp_48);
    __Vtemp_51[0U] = __Vtemp_49[0U];
    __Vtemp_51[1U] = __Vtemp_49[1U];
    __Vtemp_51[2U] = (1U & __Vtemp_49[2U]);
    VL_ADD_W(3, __Vtemp_52, __Vtemp_45, __Vtemp_51);
    __Vtemp_54[0U] = __Vtemp_52[0U];
    __Vtemp_54[1U] = __Vtemp_52[1U];
    __Vtemp_54[2U] = (3U & __Vtemp_52[2U]);
    __Vtemp_57[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_12)
                               ? vlSelfRef.__PVT__buckets_count_12
                               : 0ULL));
    __Vtemp_57[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_12)
                                ? vlSelfRef.__PVT__buckets_count_12
                                : 0ULL) >> 0x20U));
    __Vtemp_57[2U] = 0U;
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_13)
                               ? vlSelfRef.__PVT__buckets_count_13
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_13)
                                ? vlSelfRef.__PVT__buckets_count_13
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    VL_ADD_W(3, __Vtemp_59, __Vtemp_57, __Vtemp_58);
    __Vtemp_61[0U] = __Vtemp_59[0U];
    __Vtemp_61[1U] = __Vtemp_59[1U];
    __Vtemp_61[2U] = (1U & __Vtemp_59[2U]);
    __Vtemp_63[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_14)
                               ? vlSelfRef.__PVT__buckets_count_14
                               : 0ULL));
    __Vtemp_63[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_14)
                                ? vlSelfRef.__PVT__buckets_count_14
                                : 0ULL) >> 0x20U));
    __Vtemp_63[2U] = 0U;
    __Vtemp_64[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_15)
                               ? vlSelfRef.__PVT__buckets_count_15
                               : 0ULL));
    __Vtemp_64[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_15)
                                ? vlSelfRef.__PVT__buckets_count_15
                                : 0ULL) >> 0x20U));
    __Vtemp_64[2U] = 0U;
    VL_ADD_W(3, __Vtemp_65, __Vtemp_63, __Vtemp_64);
    __Vtemp_67[0U] = __Vtemp_65[0U];
    __Vtemp_67[1U] = __Vtemp_65[1U];
    __Vtemp_67[2U] = (1U & __Vtemp_65[2U]);
    VL_ADD_W(3, __Vtemp_68, __Vtemp_61, __Vtemp_67);
    __Vtemp_70[0U] = __Vtemp_68[0U];
    __Vtemp_70[1U] = __Vtemp_68[1U];
    __Vtemp_70[2U] = (3U & __Vtemp_68[2U]);
    VL_ADD_W(3, __Vtemp_71, __Vtemp_54, __Vtemp_70);
    __Vtemp_73[0U] = __Vtemp_71[0U];
    __Vtemp_73[1U] = __Vtemp_71[1U];
    __Vtemp_73[2U] = (7U & __Vtemp_71[2U]);
    VL_ADD_W(3, __Vtemp_74, __Vtemp_37, __Vtemp_73);
    vlSelfRef.io_resolvedCount[0U] = __Vtemp_74[0U];
    vlSelfRef.io_resolvedCount[1U] = __Vtemp_74[1U];
    vlSelfRef.io_resolvedCount[2U] = (0xfU & __Vtemp_74[2U]);
    vlSelfRef.__PVT___canAccept_T_46 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_15)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_15)));
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
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_3__3(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_3__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_8 = ((0x38U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_25) 
                                       | (vlSelfRef.__PVT__buckets_seq_8 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_9 = ((0x39U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_28) 
                                       | (vlSelfRef.__PVT__buckets_seq_9 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_10 = ((0x3aU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_31) 
                                        | (vlSelfRef.__PVT__buckets_seq_10 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_11 = ((0x3bU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_34) 
                                        | (vlSelfRef.__PVT__buckets_seq_11 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_12 = ((0x3cU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_37) 
                                        | (vlSelfRef.__PVT__buckets_seq_12 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_13 = ((0x3dU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_40) 
                                        | (vlSelfRef.__PVT__buckets_seq_13 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_14 = ((0x3eU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_43) 
                                        | (vlSelfRef.__PVT__buckets_seq_14 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_15 = ((0x3fU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_46) 
                                        | (vlSelfRef.__PVT__buckets_seq_15 
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
    vlSelfRef.__PVT__accepted_8 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_8));
    vlSelfRef.__PVT__accepted_9 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_9));
    vlSelfRef.__PVT__accepted_10 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_10));
    vlSelfRef.__PVT__accepted_11 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_11));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_3__2(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_3__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_9;
    VlWide<3>/*95:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_13;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_21;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_25;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_29;
    VlWide<3>/*95:0*/ __Vtemp_31;
    VlWide<3>/*95:0*/ __Vtemp_32;
    VlWide<3>/*95:0*/ __Vtemp_34;
    VlWide<3>/*95:0*/ __Vtemp_35;
    VlWide<3>/*95:0*/ __Vtemp_37;
    VlWide<3>/*95:0*/ __Vtemp_41;
    VlWide<3>/*95:0*/ __Vtemp_42;
    VlWide<3>/*95:0*/ __Vtemp_43;
    VlWide<3>/*95:0*/ __Vtemp_45;
    VlWide<3>/*95:0*/ __Vtemp_47;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_49;
    VlWide<3>/*95:0*/ __Vtemp_51;
    VlWide<3>/*95:0*/ __Vtemp_52;
    VlWide<3>/*95:0*/ __Vtemp_54;
    VlWide<3>/*95:0*/ __Vtemp_57;
    VlWide<3>/*95:0*/ __Vtemp_58;
    VlWide<3>/*95:0*/ __Vtemp_59;
    VlWide<3>/*95:0*/ __Vtemp_61;
    VlWide<3>/*95:0*/ __Vtemp_63;
    VlWide<3>/*95:0*/ __Vtemp_64;
    VlWide<3>/*95:0*/ __Vtemp_65;
    VlWide<3>/*95:0*/ __Vtemp_67;
    VlWide<3>/*95:0*/ __Vtemp_68;
    VlWide<3>/*95:0*/ __Vtemp_70;
    VlWide<3>/*95:0*/ __Vtemp_71;
    VlWide<3>/*95:0*/ __Vtemp_73;
    VlWide<3>/*95:0*/ __Vtemp_74;
    // Body
    vlSelfRef.__PVT___GEN_30 = ((~ (IData)(vlSelfRef.__PVT__resolving_2)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_2));
    __Vtemp_5[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_0)
                              ? vlSelfRef.__PVT__buckets_count_0
                              : 0ULL));
    __Vtemp_5[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_0)
                               ? vlSelfRef.__PVT__buckets_count_0
                               : 0ULL) >> 0x20U));
    __Vtemp_5[2U] = 0U;
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_1)
                              ? vlSelfRef.__PVT__buckets_count_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_1)
                               ? vlSelfRef.__PVT__buckets_count_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    VL_ADD_W(3, __Vtemp_7, __Vtemp_5, __Vtemp_6);
    __Vtemp_9[0U] = __Vtemp_7[0U];
    __Vtemp_9[1U] = __Vtemp_7[1U];
    __Vtemp_9[2U] = (1U & __Vtemp_7[2U]);
    __Vtemp_11[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_2)
                               ? vlSelfRef.__PVT__buckets_count_2
                               : 0ULL));
    __Vtemp_11[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_2)
                                ? vlSelfRef.__PVT__buckets_count_2
                                : 0ULL) >> 0x20U));
    __Vtemp_11[2U] = 0U;
    __Vtemp_12[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_3)
                               ? vlSelfRef.__PVT__buckets_count_3
                               : 0ULL));
    __Vtemp_12[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_3)
                                ? vlSelfRef.__PVT__buckets_count_3
                                : 0ULL) >> 0x20U));
    __Vtemp_12[2U] = 0U;
    VL_ADD_W(3, __Vtemp_13, __Vtemp_11, __Vtemp_12);
    __Vtemp_15[0U] = __Vtemp_13[0U];
    __Vtemp_15[1U] = __Vtemp_13[1U];
    __Vtemp_15[2U] = (1U & __Vtemp_13[2U]);
    VL_ADD_W(3, __Vtemp_16, __Vtemp_9, __Vtemp_15);
    __Vtemp_18[0U] = __Vtemp_16[0U];
    __Vtemp_18[1U] = __Vtemp_16[1U];
    __Vtemp_18[2U] = (3U & __Vtemp_16[2U]);
    __Vtemp_21[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_4)
                               ? vlSelfRef.__PVT__buckets_count_4
                               : 0ULL));
    __Vtemp_21[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_4)
                                ? vlSelfRef.__PVT__buckets_count_4
                                : 0ULL) >> 0x20U));
    __Vtemp_21[2U] = 0U;
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_5)
                               ? vlSelfRef.__PVT__buckets_count_5
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_5)
                                ? vlSelfRef.__PVT__buckets_count_5
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    VL_ADD_W(3, __Vtemp_23, __Vtemp_21, __Vtemp_22);
    __Vtemp_25[0U] = __Vtemp_23[0U];
    __Vtemp_25[1U] = __Vtemp_23[1U];
    __Vtemp_25[2U] = (1U & __Vtemp_23[2U]);
    __Vtemp_27[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_6)
                               ? vlSelfRef.__PVT__buckets_count_6
                               : 0ULL));
    __Vtemp_27[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_6)
                                ? vlSelfRef.__PVT__buckets_count_6
                                : 0ULL) >> 0x20U));
    __Vtemp_27[2U] = 0U;
    __Vtemp_28[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_7)
                               ? vlSelfRef.buckets_count_7
                               : 0ULL));
    __Vtemp_28[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_7)
                                ? vlSelfRef.buckets_count_7
                                : 0ULL) >> 0x20U));
    __Vtemp_28[2U] = 0U;
    VL_ADD_W(3, __Vtemp_29, __Vtemp_27, __Vtemp_28);
    __Vtemp_31[0U] = __Vtemp_29[0U];
    __Vtemp_31[1U] = __Vtemp_29[1U];
    __Vtemp_31[2U] = (1U & __Vtemp_29[2U]);
    VL_ADD_W(3, __Vtemp_32, __Vtemp_25, __Vtemp_31);
    __Vtemp_34[0U] = __Vtemp_32[0U];
    __Vtemp_34[1U] = __Vtemp_32[1U];
    __Vtemp_34[2U] = (3U & __Vtemp_32[2U]);
    VL_ADD_W(3, __Vtemp_35, __Vtemp_18, __Vtemp_34);
    __Vtemp_37[0U] = __Vtemp_35[0U];
    __Vtemp_37[1U] = __Vtemp_35[1U];
    __Vtemp_37[2U] = (7U & __Vtemp_35[2U]);
    __Vtemp_41[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_8)
                               ? vlSelfRef.__PVT__buckets_count_8
                               : 0ULL));
    __Vtemp_41[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_8)
                                ? vlSelfRef.__PVT__buckets_count_8
                                : 0ULL) >> 0x20U));
    __Vtemp_41[2U] = 0U;
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_9)
                               ? vlSelfRef.__PVT__buckets_count_9
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_9)
                                ? vlSelfRef.__PVT__buckets_count_9
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    VL_ADD_W(3, __Vtemp_43, __Vtemp_41, __Vtemp_42);
    __Vtemp_45[0U] = __Vtemp_43[0U];
    __Vtemp_45[1U] = __Vtemp_43[1U];
    __Vtemp_45[2U] = (1U & __Vtemp_43[2U]);
    __Vtemp_47[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_10)
                               ? vlSelfRef.__PVT__buckets_count_10
                               : 0ULL));
    __Vtemp_47[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_10)
                                ? vlSelfRef.__PVT__buckets_count_10
                                : 0ULL) >> 0x20U));
    __Vtemp_47[2U] = 0U;
    __Vtemp_48[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_11)
                               ? vlSelfRef.__PVT__buckets_count_11
                               : 0ULL));
    __Vtemp_48[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_11)
                                ? vlSelfRef.__PVT__buckets_count_11
                                : 0ULL) >> 0x20U));
    __Vtemp_48[2U] = 0U;
    VL_ADD_W(3, __Vtemp_49, __Vtemp_47, __Vtemp_48);
    __Vtemp_51[0U] = __Vtemp_49[0U];
    __Vtemp_51[1U] = __Vtemp_49[1U];
    __Vtemp_51[2U] = (1U & __Vtemp_49[2U]);
    VL_ADD_W(3, __Vtemp_52, __Vtemp_45, __Vtemp_51);
    __Vtemp_54[0U] = __Vtemp_52[0U];
    __Vtemp_54[1U] = __Vtemp_52[1U];
    __Vtemp_54[2U] = (3U & __Vtemp_52[2U]);
    __Vtemp_57[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_12)
                               ? vlSelfRef.__PVT__buckets_count_12
                               : 0ULL));
    __Vtemp_57[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_12)
                                ? vlSelfRef.__PVT__buckets_count_12
                                : 0ULL) >> 0x20U));
    __Vtemp_57[2U] = 0U;
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_13)
                               ? vlSelfRef.__PVT__buckets_count_13
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_13)
                                ? vlSelfRef.__PVT__buckets_count_13
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    VL_ADD_W(3, __Vtemp_59, __Vtemp_57, __Vtemp_58);
    __Vtemp_61[0U] = __Vtemp_59[0U];
    __Vtemp_61[1U] = __Vtemp_59[1U];
    __Vtemp_61[2U] = (1U & __Vtemp_59[2U]);
    __Vtemp_63[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_14)
                               ? vlSelfRef.__PVT__buckets_count_14
                               : 0ULL));
    __Vtemp_63[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_14)
                                ? vlSelfRef.__PVT__buckets_count_14
                                : 0ULL) >> 0x20U));
    __Vtemp_63[2U] = 0U;
    __Vtemp_64[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_15)
                               ? vlSelfRef.__PVT__buckets_count_15
                               : 0ULL));
    __Vtemp_64[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_15)
                                ? vlSelfRef.__PVT__buckets_count_15
                                : 0ULL) >> 0x20U));
    __Vtemp_64[2U] = 0U;
    VL_ADD_W(3, __Vtemp_65, __Vtemp_63, __Vtemp_64);
    __Vtemp_67[0U] = __Vtemp_65[0U];
    __Vtemp_67[1U] = __Vtemp_65[1U];
    __Vtemp_67[2U] = (1U & __Vtemp_65[2U]);
    VL_ADD_W(3, __Vtemp_68, __Vtemp_61, __Vtemp_67);
    __Vtemp_70[0U] = __Vtemp_68[0U];
    __Vtemp_70[1U] = __Vtemp_68[1U];
    __Vtemp_70[2U] = (3U & __Vtemp_68[2U]);
    VL_ADD_W(3, __Vtemp_71, __Vtemp_54, __Vtemp_70);
    __Vtemp_73[0U] = __Vtemp_71[0U];
    __Vtemp_73[1U] = __Vtemp_71[1U];
    __Vtemp_73[2U] = (7U & __Vtemp_71[2U]);
    VL_ADD_W(3, __Vtemp_74, __Vtemp_37, __Vtemp_73);
    vlSelfRef.io_resolvedCount[0U] = __Vtemp_74[0U];
    vlSelfRef.io_resolvedCount[1U] = __Vtemp_74[1U];
    vlSelfRef.io_resolvedCount[2U] = (0xfU & __Vtemp_74[2U]);
    vlSelfRef.__PVT___canAccept_T_7 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_2)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_2)));
    vlSelfRef.__PVT__available_5 = ((0x35U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x34U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_15 = ((0x3fU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_46) 
                                        | (vlSelfRef.__PVT__buckets_seq_15 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x33U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_9 = ((0x39U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_28) 
                                       | (vlSelfRef.__PVT__buckets_seq_9 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_10 = ((0x3aU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_31) 
                                        | (vlSelfRef.__PVT__buckets_seq_10 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_3__3(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_3__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__available_13 = ((0x3dU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_40) 
                                        | (vlSelfRef.__PVT__buckets_seq_13 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_14 = ((0x3eU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_43) 
                                        | (vlSelfRef.__PVT__buckets_seq_14 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_11 = ((0x3bU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_34) 
                                        | (vlSelfRef.__PVT__buckets_seq_11 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_12 = ((0x3cU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_37) 
                                        | (vlSelfRef.__PVT__buckets_seq_12 
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
    vlSelfRef.__PVT__available_8 = ((0x38U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_25) 
                                       | (vlSelfRef.__PVT__buckets_seq_8 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
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
    vlSelfRef.__PVT__accepted_5 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_5));
    vlSelfRef.__PVT__accepted_4 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_4));
    vlSelfRef.__PVT__accepted_15 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_15));
    vlSelfRef.__PVT__accepted_3 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_3));
    vlSelfRef.__PVT__accepted_9 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_9));
    vlSelfRef.__PVT__accepted_10 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_10));
    vlSelfRef.__PVT__accepted_13 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_13));
    vlSelfRef.__PVT__accepted_14 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_14));
    vlSelfRef.__PVT__accepted_11 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_11));
    vlSelfRef.__PVT__accepted_12 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_12));
    vlSelfRef.__PVT__accepted_6 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_6));
    vlSelfRef.__PVT__accepted_7 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_7));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_4__2(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_4__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_9;
    VlWide<3>/*95:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_13;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_21;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_25;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_29;
    VlWide<3>/*95:0*/ __Vtemp_31;
    VlWide<3>/*95:0*/ __Vtemp_32;
    VlWide<3>/*95:0*/ __Vtemp_34;
    VlWide<3>/*95:0*/ __Vtemp_35;
    VlWide<3>/*95:0*/ __Vtemp_37;
    VlWide<3>/*95:0*/ __Vtemp_41;
    VlWide<3>/*95:0*/ __Vtemp_42;
    VlWide<3>/*95:0*/ __Vtemp_43;
    VlWide<3>/*95:0*/ __Vtemp_45;
    VlWide<3>/*95:0*/ __Vtemp_47;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_49;
    VlWide<3>/*95:0*/ __Vtemp_51;
    VlWide<3>/*95:0*/ __Vtemp_52;
    VlWide<3>/*95:0*/ __Vtemp_54;
    VlWide<3>/*95:0*/ __Vtemp_57;
    VlWide<3>/*95:0*/ __Vtemp_58;
    VlWide<3>/*95:0*/ __Vtemp_59;
    VlWide<3>/*95:0*/ __Vtemp_61;
    VlWide<3>/*95:0*/ __Vtemp_63;
    VlWide<3>/*95:0*/ __Vtemp_64;
    VlWide<3>/*95:0*/ __Vtemp_65;
    VlWide<3>/*95:0*/ __Vtemp_67;
    VlWide<3>/*95:0*/ __Vtemp_68;
    VlWide<3>/*95:0*/ __Vtemp_70;
    VlWide<3>/*95:0*/ __Vtemp_71;
    VlWide<3>/*95:0*/ __Vtemp_73;
    VlWide<3>/*95:0*/ __Vtemp_74;
    // Body
    vlSelfRef.__PVT___GEN_225 = ((~ (IData)(vlSelfRef.__PVT__resolving_15)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_15));
    __Vtemp_5[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_0)
                              ? vlSelfRef.__PVT__buckets_count_0
                              : 0ULL));
    __Vtemp_5[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_0)
                               ? vlSelfRef.__PVT__buckets_count_0
                               : 0ULL) >> 0x20U));
    __Vtemp_5[2U] = 0U;
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_1)
                              ? vlSelfRef.__PVT__buckets_count_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_1)
                               ? vlSelfRef.__PVT__buckets_count_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    VL_ADD_W(3, __Vtemp_7, __Vtemp_5, __Vtemp_6);
    __Vtemp_9[0U] = __Vtemp_7[0U];
    __Vtemp_9[1U] = __Vtemp_7[1U];
    __Vtemp_9[2U] = (1U & __Vtemp_7[2U]);
    __Vtemp_11[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_2)
                               ? vlSelfRef.__PVT__buckets_count_2
                               : 0ULL));
    __Vtemp_11[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_2)
                                ? vlSelfRef.__PVT__buckets_count_2
                                : 0ULL) >> 0x20U));
    __Vtemp_11[2U] = 0U;
    __Vtemp_12[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_3)
                               ? vlSelfRef.__PVT__buckets_count_3
                               : 0ULL));
    __Vtemp_12[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_3)
                                ? vlSelfRef.__PVT__buckets_count_3
                                : 0ULL) >> 0x20U));
    __Vtemp_12[2U] = 0U;
    VL_ADD_W(3, __Vtemp_13, __Vtemp_11, __Vtemp_12);
    __Vtemp_15[0U] = __Vtemp_13[0U];
    __Vtemp_15[1U] = __Vtemp_13[1U];
    __Vtemp_15[2U] = (1U & __Vtemp_13[2U]);
    VL_ADD_W(3, __Vtemp_16, __Vtemp_9, __Vtemp_15);
    __Vtemp_18[0U] = __Vtemp_16[0U];
    __Vtemp_18[1U] = __Vtemp_16[1U];
    __Vtemp_18[2U] = (3U & __Vtemp_16[2U]);
    __Vtemp_21[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_4)
                               ? vlSelfRef.__PVT__buckets_count_4
                               : 0ULL));
    __Vtemp_21[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_4)
                                ? vlSelfRef.__PVT__buckets_count_4
                                : 0ULL) >> 0x20U));
    __Vtemp_21[2U] = 0U;
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_5)
                               ? vlSelfRef.__PVT__buckets_count_5
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_5)
                                ? vlSelfRef.__PVT__buckets_count_5
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    VL_ADD_W(3, __Vtemp_23, __Vtemp_21, __Vtemp_22);
    __Vtemp_25[0U] = __Vtemp_23[0U];
    __Vtemp_25[1U] = __Vtemp_23[1U];
    __Vtemp_25[2U] = (1U & __Vtemp_23[2U]);
    __Vtemp_27[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_6)
                               ? vlSelfRef.__PVT__buckets_count_6
                               : 0ULL));
    __Vtemp_27[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_6)
                                ? vlSelfRef.__PVT__buckets_count_6
                                : 0ULL) >> 0x20U));
    __Vtemp_27[2U] = 0U;
    __Vtemp_28[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_7)
                               ? vlSelfRef.buckets_count_7
                               : 0ULL));
    __Vtemp_28[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_7)
                                ? vlSelfRef.buckets_count_7
                                : 0ULL) >> 0x20U));
    __Vtemp_28[2U] = 0U;
    VL_ADD_W(3, __Vtemp_29, __Vtemp_27, __Vtemp_28);
    __Vtemp_31[0U] = __Vtemp_29[0U];
    __Vtemp_31[1U] = __Vtemp_29[1U];
    __Vtemp_31[2U] = (1U & __Vtemp_29[2U]);
    VL_ADD_W(3, __Vtemp_32, __Vtemp_25, __Vtemp_31);
    __Vtemp_34[0U] = __Vtemp_32[0U];
    __Vtemp_34[1U] = __Vtemp_32[1U];
    __Vtemp_34[2U] = (3U & __Vtemp_32[2U]);
    VL_ADD_W(3, __Vtemp_35, __Vtemp_18, __Vtemp_34);
    __Vtemp_37[0U] = __Vtemp_35[0U];
    __Vtemp_37[1U] = __Vtemp_35[1U];
    __Vtemp_37[2U] = (7U & __Vtemp_35[2U]);
    __Vtemp_41[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_8)
                               ? vlSelfRef.__PVT__buckets_count_8
                               : 0ULL));
    __Vtemp_41[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_8)
                                ? vlSelfRef.__PVT__buckets_count_8
                                : 0ULL) >> 0x20U));
    __Vtemp_41[2U] = 0U;
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_9)
                               ? vlSelfRef.__PVT__buckets_count_9
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_9)
                                ? vlSelfRef.__PVT__buckets_count_9
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    VL_ADD_W(3, __Vtemp_43, __Vtemp_41, __Vtemp_42);
    __Vtemp_45[0U] = __Vtemp_43[0U];
    __Vtemp_45[1U] = __Vtemp_43[1U];
    __Vtemp_45[2U] = (1U & __Vtemp_43[2U]);
    __Vtemp_47[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_10)
                               ? vlSelfRef.__PVT__buckets_count_10
                               : 0ULL));
    __Vtemp_47[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_10)
                                ? vlSelfRef.__PVT__buckets_count_10
                                : 0ULL) >> 0x20U));
    __Vtemp_47[2U] = 0U;
    __Vtemp_48[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_11)
                               ? vlSelfRef.__PVT__buckets_count_11
                               : 0ULL));
    __Vtemp_48[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_11)
                                ? vlSelfRef.__PVT__buckets_count_11
                                : 0ULL) >> 0x20U));
    __Vtemp_48[2U] = 0U;
    VL_ADD_W(3, __Vtemp_49, __Vtemp_47, __Vtemp_48);
    __Vtemp_51[0U] = __Vtemp_49[0U];
    __Vtemp_51[1U] = __Vtemp_49[1U];
    __Vtemp_51[2U] = (1U & __Vtemp_49[2U]);
    VL_ADD_W(3, __Vtemp_52, __Vtemp_45, __Vtemp_51);
    __Vtemp_54[0U] = __Vtemp_52[0U];
    __Vtemp_54[1U] = __Vtemp_52[1U];
    __Vtemp_54[2U] = (3U & __Vtemp_52[2U]);
    __Vtemp_57[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_12)
                               ? vlSelfRef.__PVT__buckets_count_12
                               : 0ULL));
    __Vtemp_57[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_12)
                                ? vlSelfRef.__PVT__buckets_count_12
                                : 0ULL) >> 0x20U));
    __Vtemp_57[2U] = 0U;
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_13)
                               ? vlSelfRef.__PVT__buckets_count_13
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_13)
                                ? vlSelfRef.__PVT__buckets_count_13
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    VL_ADD_W(3, __Vtemp_59, __Vtemp_57, __Vtemp_58);
    __Vtemp_61[0U] = __Vtemp_59[0U];
    __Vtemp_61[1U] = __Vtemp_59[1U];
    __Vtemp_61[2U] = (1U & __Vtemp_59[2U]);
    __Vtemp_63[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_14)
                               ? vlSelfRef.__PVT__buckets_count_14
                               : 0ULL));
    __Vtemp_63[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_14)
                                ? vlSelfRef.__PVT__buckets_count_14
                                : 0ULL) >> 0x20U));
    __Vtemp_63[2U] = 0U;
    __Vtemp_64[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_15)
                               ? vlSelfRef.__PVT__buckets_count_15
                               : 0ULL));
    __Vtemp_64[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_15)
                                ? vlSelfRef.__PVT__buckets_count_15
                                : 0ULL) >> 0x20U));
    __Vtemp_64[2U] = 0U;
    VL_ADD_W(3, __Vtemp_65, __Vtemp_63, __Vtemp_64);
    __Vtemp_67[0U] = __Vtemp_65[0U];
    __Vtemp_67[1U] = __Vtemp_65[1U];
    __Vtemp_67[2U] = (1U & __Vtemp_65[2U]);
    VL_ADD_W(3, __Vtemp_68, __Vtemp_61, __Vtemp_67);
    __Vtemp_70[0U] = __Vtemp_68[0U];
    __Vtemp_70[1U] = __Vtemp_68[1U];
    __Vtemp_70[2U] = (3U & __Vtemp_68[2U]);
    VL_ADD_W(3, __Vtemp_71, __Vtemp_54, __Vtemp_70);
    __Vtemp_73[0U] = __Vtemp_71[0U];
    __Vtemp_73[1U] = __Vtemp_71[1U];
    __Vtemp_73[2U] = (7U & __Vtemp_71[2U]);
    VL_ADD_W(3, __Vtemp_74, __Vtemp_37, __Vtemp_73);
    vlSelfRef.io_resolvedCount[0U] = __Vtemp_74[0U];
    vlSelfRef.io_resolvedCount[1U] = __Vtemp_74[1U];
    vlSelfRef.io_resolvedCount[2U] = (0xfU & __Vtemp_74[2U]);
    vlSelfRef.__PVT___canAccept_T_46 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_15)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_15)));
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
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_4__3(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_4__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_8 = ((0x48U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_25) 
                                       | (vlSelfRef.__PVT__buckets_seq_8 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_9 = ((0x49U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_28) 
                                       | (vlSelfRef.__PVT__buckets_seq_9 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_10 = ((0x4aU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_31) 
                                        | (vlSelfRef.__PVT__buckets_seq_10 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_11 = ((0x4bU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_34) 
                                        | (vlSelfRef.__PVT__buckets_seq_11 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_12 = ((0x4cU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_37) 
                                        | (vlSelfRef.__PVT__buckets_seq_12 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_13 = ((0x4dU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_40) 
                                        | (vlSelfRef.__PVT__buckets_seq_13 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_14 = ((0x4eU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_43) 
                                        | (vlSelfRef.__PVT__buckets_seq_14 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_15 = ((0x4fU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_46) 
                                        | (vlSelfRef.__PVT__buckets_seq_15 
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
    vlSelfRef.__PVT__accepted_8 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_8));
    vlSelfRef.__PVT__accepted_9 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_9));
    vlSelfRef.__PVT__accepted_10 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_10));
    vlSelfRef.__PVT__accepted_11 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_11));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_4__2(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_4__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_9;
    VlWide<3>/*95:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_13;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_21;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_25;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_29;
    VlWide<3>/*95:0*/ __Vtemp_31;
    VlWide<3>/*95:0*/ __Vtemp_32;
    VlWide<3>/*95:0*/ __Vtemp_34;
    VlWide<3>/*95:0*/ __Vtemp_35;
    VlWide<3>/*95:0*/ __Vtemp_37;
    VlWide<3>/*95:0*/ __Vtemp_41;
    VlWide<3>/*95:0*/ __Vtemp_42;
    VlWide<3>/*95:0*/ __Vtemp_43;
    VlWide<3>/*95:0*/ __Vtemp_45;
    VlWide<3>/*95:0*/ __Vtemp_47;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_49;
    VlWide<3>/*95:0*/ __Vtemp_51;
    VlWide<3>/*95:0*/ __Vtemp_52;
    VlWide<3>/*95:0*/ __Vtemp_54;
    VlWide<3>/*95:0*/ __Vtemp_57;
    VlWide<3>/*95:0*/ __Vtemp_58;
    VlWide<3>/*95:0*/ __Vtemp_59;
    VlWide<3>/*95:0*/ __Vtemp_61;
    VlWide<3>/*95:0*/ __Vtemp_63;
    VlWide<3>/*95:0*/ __Vtemp_64;
    VlWide<3>/*95:0*/ __Vtemp_65;
    VlWide<3>/*95:0*/ __Vtemp_67;
    VlWide<3>/*95:0*/ __Vtemp_68;
    VlWide<3>/*95:0*/ __Vtemp_70;
    VlWide<3>/*95:0*/ __Vtemp_71;
    VlWide<3>/*95:0*/ __Vtemp_73;
    VlWide<3>/*95:0*/ __Vtemp_74;
    // Body
    vlSelfRef.__PVT___GEN_30 = ((~ (IData)(vlSelfRef.__PVT__resolving_2)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_2));
    __Vtemp_5[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_0)
                              ? vlSelfRef.__PVT__buckets_count_0
                              : 0ULL));
    __Vtemp_5[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_0)
                               ? vlSelfRef.__PVT__buckets_count_0
                               : 0ULL) >> 0x20U));
    __Vtemp_5[2U] = 0U;
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_1)
                              ? vlSelfRef.__PVT__buckets_count_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_1)
                               ? vlSelfRef.__PVT__buckets_count_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    VL_ADD_W(3, __Vtemp_7, __Vtemp_5, __Vtemp_6);
    __Vtemp_9[0U] = __Vtemp_7[0U];
    __Vtemp_9[1U] = __Vtemp_7[1U];
    __Vtemp_9[2U] = (1U & __Vtemp_7[2U]);
    __Vtemp_11[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_2)
                               ? vlSelfRef.__PVT__buckets_count_2
                               : 0ULL));
    __Vtemp_11[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_2)
                                ? vlSelfRef.__PVT__buckets_count_2
                                : 0ULL) >> 0x20U));
    __Vtemp_11[2U] = 0U;
    __Vtemp_12[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_3)
                               ? vlSelfRef.__PVT__buckets_count_3
                               : 0ULL));
    __Vtemp_12[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_3)
                                ? vlSelfRef.__PVT__buckets_count_3
                                : 0ULL) >> 0x20U));
    __Vtemp_12[2U] = 0U;
    VL_ADD_W(3, __Vtemp_13, __Vtemp_11, __Vtemp_12);
    __Vtemp_15[0U] = __Vtemp_13[0U];
    __Vtemp_15[1U] = __Vtemp_13[1U];
    __Vtemp_15[2U] = (1U & __Vtemp_13[2U]);
    VL_ADD_W(3, __Vtemp_16, __Vtemp_9, __Vtemp_15);
    __Vtemp_18[0U] = __Vtemp_16[0U];
    __Vtemp_18[1U] = __Vtemp_16[1U];
    __Vtemp_18[2U] = (3U & __Vtemp_16[2U]);
    __Vtemp_21[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_4)
                               ? vlSelfRef.__PVT__buckets_count_4
                               : 0ULL));
    __Vtemp_21[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_4)
                                ? vlSelfRef.__PVT__buckets_count_4
                                : 0ULL) >> 0x20U));
    __Vtemp_21[2U] = 0U;
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_5)
                               ? vlSelfRef.__PVT__buckets_count_5
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_5)
                                ? vlSelfRef.__PVT__buckets_count_5
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    VL_ADD_W(3, __Vtemp_23, __Vtemp_21, __Vtemp_22);
    __Vtemp_25[0U] = __Vtemp_23[0U];
    __Vtemp_25[1U] = __Vtemp_23[1U];
    __Vtemp_25[2U] = (1U & __Vtemp_23[2U]);
    __Vtemp_27[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_6)
                               ? vlSelfRef.__PVT__buckets_count_6
                               : 0ULL));
    __Vtemp_27[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_6)
                                ? vlSelfRef.__PVT__buckets_count_6
                                : 0ULL) >> 0x20U));
    __Vtemp_27[2U] = 0U;
    __Vtemp_28[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_7)
                               ? vlSelfRef.buckets_count_7
                               : 0ULL));
    __Vtemp_28[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_7)
                                ? vlSelfRef.buckets_count_7
                                : 0ULL) >> 0x20U));
    __Vtemp_28[2U] = 0U;
    VL_ADD_W(3, __Vtemp_29, __Vtemp_27, __Vtemp_28);
    __Vtemp_31[0U] = __Vtemp_29[0U];
    __Vtemp_31[1U] = __Vtemp_29[1U];
    __Vtemp_31[2U] = (1U & __Vtemp_29[2U]);
    VL_ADD_W(3, __Vtemp_32, __Vtemp_25, __Vtemp_31);
    __Vtemp_34[0U] = __Vtemp_32[0U];
    __Vtemp_34[1U] = __Vtemp_32[1U];
    __Vtemp_34[2U] = (3U & __Vtemp_32[2U]);
    VL_ADD_W(3, __Vtemp_35, __Vtemp_18, __Vtemp_34);
    __Vtemp_37[0U] = __Vtemp_35[0U];
    __Vtemp_37[1U] = __Vtemp_35[1U];
    __Vtemp_37[2U] = (7U & __Vtemp_35[2U]);
    __Vtemp_41[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_8)
                               ? vlSelfRef.__PVT__buckets_count_8
                               : 0ULL));
    __Vtemp_41[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_8)
                                ? vlSelfRef.__PVT__buckets_count_8
                                : 0ULL) >> 0x20U));
    __Vtemp_41[2U] = 0U;
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_9)
                               ? vlSelfRef.__PVT__buckets_count_9
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_9)
                                ? vlSelfRef.__PVT__buckets_count_9
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    VL_ADD_W(3, __Vtemp_43, __Vtemp_41, __Vtemp_42);
    __Vtemp_45[0U] = __Vtemp_43[0U];
    __Vtemp_45[1U] = __Vtemp_43[1U];
    __Vtemp_45[2U] = (1U & __Vtemp_43[2U]);
    __Vtemp_47[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_10)
                               ? vlSelfRef.__PVT__buckets_count_10
                               : 0ULL));
    __Vtemp_47[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_10)
                                ? vlSelfRef.__PVT__buckets_count_10
                                : 0ULL) >> 0x20U));
    __Vtemp_47[2U] = 0U;
    __Vtemp_48[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_11)
                               ? vlSelfRef.__PVT__buckets_count_11
                               : 0ULL));
    __Vtemp_48[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_11)
                                ? vlSelfRef.__PVT__buckets_count_11
                                : 0ULL) >> 0x20U));
    __Vtemp_48[2U] = 0U;
    VL_ADD_W(3, __Vtemp_49, __Vtemp_47, __Vtemp_48);
    __Vtemp_51[0U] = __Vtemp_49[0U];
    __Vtemp_51[1U] = __Vtemp_49[1U];
    __Vtemp_51[2U] = (1U & __Vtemp_49[2U]);
    VL_ADD_W(3, __Vtemp_52, __Vtemp_45, __Vtemp_51);
    __Vtemp_54[0U] = __Vtemp_52[0U];
    __Vtemp_54[1U] = __Vtemp_52[1U];
    __Vtemp_54[2U] = (3U & __Vtemp_52[2U]);
    __Vtemp_57[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_12)
                               ? vlSelfRef.__PVT__buckets_count_12
                               : 0ULL));
    __Vtemp_57[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_12)
                                ? vlSelfRef.__PVT__buckets_count_12
                                : 0ULL) >> 0x20U));
    __Vtemp_57[2U] = 0U;
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_13)
                               ? vlSelfRef.__PVT__buckets_count_13
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_13)
                                ? vlSelfRef.__PVT__buckets_count_13
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    VL_ADD_W(3, __Vtemp_59, __Vtemp_57, __Vtemp_58);
    __Vtemp_61[0U] = __Vtemp_59[0U];
    __Vtemp_61[1U] = __Vtemp_59[1U];
    __Vtemp_61[2U] = (1U & __Vtemp_59[2U]);
    __Vtemp_63[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_14)
                               ? vlSelfRef.__PVT__buckets_count_14
                               : 0ULL));
    __Vtemp_63[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_14)
                                ? vlSelfRef.__PVT__buckets_count_14
                                : 0ULL) >> 0x20U));
    __Vtemp_63[2U] = 0U;
    __Vtemp_64[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_15)
                               ? vlSelfRef.__PVT__buckets_count_15
                               : 0ULL));
    __Vtemp_64[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_15)
                                ? vlSelfRef.__PVT__buckets_count_15
                                : 0ULL) >> 0x20U));
    __Vtemp_64[2U] = 0U;
    VL_ADD_W(3, __Vtemp_65, __Vtemp_63, __Vtemp_64);
    __Vtemp_67[0U] = __Vtemp_65[0U];
    __Vtemp_67[1U] = __Vtemp_65[1U];
    __Vtemp_67[2U] = (1U & __Vtemp_65[2U]);
    VL_ADD_W(3, __Vtemp_68, __Vtemp_61, __Vtemp_67);
    __Vtemp_70[0U] = __Vtemp_68[0U];
    __Vtemp_70[1U] = __Vtemp_68[1U];
    __Vtemp_70[2U] = (3U & __Vtemp_68[2U]);
    VL_ADD_W(3, __Vtemp_71, __Vtemp_54, __Vtemp_70);
    __Vtemp_73[0U] = __Vtemp_71[0U];
    __Vtemp_73[1U] = __Vtemp_71[1U];
    __Vtemp_73[2U] = (7U & __Vtemp_71[2U]);
    VL_ADD_W(3, __Vtemp_74, __Vtemp_37, __Vtemp_73);
    vlSelfRef.io_resolvedCount[0U] = __Vtemp_74[0U];
    vlSelfRef.io_resolvedCount[1U] = __Vtemp_74[1U];
    vlSelfRef.io_resolvedCount[2U] = (0xfU & __Vtemp_74[2U]);
    vlSelfRef.__PVT___canAccept_T_7 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_2)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_2)));
    vlSelfRef.__PVT__available_5 = ((0x45U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x44U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_15 = ((0x4fU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_46) 
                                        | (vlSelfRef.__PVT__buckets_seq_15 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x43U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_9 = ((0x49U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_28) 
                                       | (vlSelfRef.__PVT__buckets_seq_9 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_10 = ((0x4aU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_31) 
                                        | (vlSelfRef.__PVT__buckets_seq_10 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_4__3(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_4__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__available_13 = ((0x4dU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_40) 
                                        | (vlSelfRef.__PVT__buckets_seq_13 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_14 = ((0x4eU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_43) 
                                        | (vlSelfRef.__PVT__buckets_seq_14 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_11 = ((0x4bU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_34) 
                                        | (vlSelfRef.__PVT__buckets_seq_11 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_12 = ((0x4cU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_37) 
                                        | (vlSelfRef.__PVT__buckets_seq_12 
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
    vlSelfRef.__PVT__available_8 = ((0x48U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_25) 
                                       | (vlSelfRef.__PVT__buckets_seq_8 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
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
    vlSelfRef.__PVT__accepted_5 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_5));
    vlSelfRef.__PVT__accepted_4 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_4));
    vlSelfRef.__PVT__accepted_15 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_15));
    vlSelfRef.__PVT__accepted_3 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_3));
    vlSelfRef.__PVT__accepted_9 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_9));
    vlSelfRef.__PVT__accepted_10 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_10));
    vlSelfRef.__PVT__accepted_13 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_13));
    vlSelfRef.__PVT__accepted_14 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_14));
    vlSelfRef.__PVT__accepted_11 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_11));
    vlSelfRef.__PVT__accepted_12 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_12));
    vlSelfRef.__PVT__accepted_6 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_6));
    vlSelfRef.__PVT__accepted_7 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_7));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_5__2(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_5__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_9;
    VlWide<3>/*95:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_13;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_21;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_25;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_29;
    VlWide<3>/*95:0*/ __Vtemp_31;
    VlWide<3>/*95:0*/ __Vtemp_32;
    VlWide<3>/*95:0*/ __Vtemp_34;
    VlWide<3>/*95:0*/ __Vtemp_35;
    VlWide<3>/*95:0*/ __Vtemp_37;
    VlWide<3>/*95:0*/ __Vtemp_41;
    VlWide<3>/*95:0*/ __Vtemp_42;
    VlWide<3>/*95:0*/ __Vtemp_43;
    VlWide<3>/*95:0*/ __Vtemp_45;
    VlWide<3>/*95:0*/ __Vtemp_47;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_49;
    VlWide<3>/*95:0*/ __Vtemp_51;
    VlWide<3>/*95:0*/ __Vtemp_52;
    VlWide<3>/*95:0*/ __Vtemp_54;
    VlWide<3>/*95:0*/ __Vtemp_57;
    VlWide<3>/*95:0*/ __Vtemp_58;
    VlWide<3>/*95:0*/ __Vtemp_59;
    VlWide<3>/*95:0*/ __Vtemp_61;
    VlWide<3>/*95:0*/ __Vtemp_63;
    VlWide<3>/*95:0*/ __Vtemp_64;
    VlWide<3>/*95:0*/ __Vtemp_65;
    VlWide<3>/*95:0*/ __Vtemp_67;
    VlWide<3>/*95:0*/ __Vtemp_68;
    VlWide<3>/*95:0*/ __Vtemp_70;
    VlWide<3>/*95:0*/ __Vtemp_71;
    VlWide<3>/*95:0*/ __Vtemp_73;
    VlWide<3>/*95:0*/ __Vtemp_74;
    // Body
    vlSelfRef.__PVT___GEN_225 = ((~ (IData)(vlSelfRef.__PVT__resolving_15)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_15));
    __Vtemp_5[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_0)
                              ? vlSelfRef.__PVT__buckets_count_0
                              : 0ULL));
    __Vtemp_5[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_0)
                               ? vlSelfRef.__PVT__buckets_count_0
                               : 0ULL) >> 0x20U));
    __Vtemp_5[2U] = 0U;
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_1)
                              ? vlSelfRef.__PVT__buckets_count_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_1)
                               ? vlSelfRef.__PVT__buckets_count_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    VL_ADD_W(3, __Vtemp_7, __Vtemp_5, __Vtemp_6);
    __Vtemp_9[0U] = __Vtemp_7[0U];
    __Vtemp_9[1U] = __Vtemp_7[1U];
    __Vtemp_9[2U] = (1U & __Vtemp_7[2U]);
    __Vtemp_11[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_2)
                               ? vlSelfRef.__PVT__buckets_count_2
                               : 0ULL));
    __Vtemp_11[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_2)
                                ? vlSelfRef.__PVT__buckets_count_2
                                : 0ULL) >> 0x20U));
    __Vtemp_11[2U] = 0U;
    __Vtemp_12[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_3)
                               ? vlSelfRef.__PVT__buckets_count_3
                               : 0ULL));
    __Vtemp_12[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_3)
                                ? vlSelfRef.__PVT__buckets_count_3
                                : 0ULL) >> 0x20U));
    __Vtemp_12[2U] = 0U;
    VL_ADD_W(3, __Vtemp_13, __Vtemp_11, __Vtemp_12);
    __Vtemp_15[0U] = __Vtemp_13[0U];
    __Vtemp_15[1U] = __Vtemp_13[1U];
    __Vtemp_15[2U] = (1U & __Vtemp_13[2U]);
    VL_ADD_W(3, __Vtemp_16, __Vtemp_9, __Vtemp_15);
    __Vtemp_18[0U] = __Vtemp_16[0U];
    __Vtemp_18[1U] = __Vtemp_16[1U];
    __Vtemp_18[2U] = (3U & __Vtemp_16[2U]);
    __Vtemp_21[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_4)
                               ? vlSelfRef.__PVT__buckets_count_4
                               : 0ULL));
    __Vtemp_21[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_4)
                                ? vlSelfRef.__PVT__buckets_count_4
                                : 0ULL) >> 0x20U));
    __Vtemp_21[2U] = 0U;
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_5)
                               ? vlSelfRef.__PVT__buckets_count_5
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_5)
                                ? vlSelfRef.__PVT__buckets_count_5
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    VL_ADD_W(3, __Vtemp_23, __Vtemp_21, __Vtemp_22);
    __Vtemp_25[0U] = __Vtemp_23[0U];
    __Vtemp_25[1U] = __Vtemp_23[1U];
    __Vtemp_25[2U] = (1U & __Vtemp_23[2U]);
    __Vtemp_27[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_6)
                               ? vlSelfRef.__PVT__buckets_count_6
                               : 0ULL));
    __Vtemp_27[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_6)
                                ? vlSelfRef.__PVT__buckets_count_6
                                : 0ULL) >> 0x20U));
    __Vtemp_27[2U] = 0U;
    __Vtemp_28[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_7)
                               ? vlSelfRef.buckets_count_7
                               : 0ULL));
    __Vtemp_28[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_7)
                                ? vlSelfRef.buckets_count_7
                                : 0ULL) >> 0x20U));
    __Vtemp_28[2U] = 0U;
    VL_ADD_W(3, __Vtemp_29, __Vtemp_27, __Vtemp_28);
    __Vtemp_31[0U] = __Vtemp_29[0U];
    __Vtemp_31[1U] = __Vtemp_29[1U];
    __Vtemp_31[2U] = (1U & __Vtemp_29[2U]);
    VL_ADD_W(3, __Vtemp_32, __Vtemp_25, __Vtemp_31);
    __Vtemp_34[0U] = __Vtemp_32[0U];
    __Vtemp_34[1U] = __Vtemp_32[1U];
    __Vtemp_34[2U] = (3U & __Vtemp_32[2U]);
    VL_ADD_W(3, __Vtemp_35, __Vtemp_18, __Vtemp_34);
    __Vtemp_37[0U] = __Vtemp_35[0U];
    __Vtemp_37[1U] = __Vtemp_35[1U];
    __Vtemp_37[2U] = (7U & __Vtemp_35[2U]);
    __Vtemp_41[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_8)
                               ? vlSelfRef.__PVT__buckets_count_8
                               : 0ULL));
    __Vtemp_41[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_8)
                                ? vlSelfRef.__PVT__buckets_count_8
                                : 0ULL) >> 0x20U));
    __Vtemp_41[2U] = 0U;
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_9)
                               ? vlSelfRef.__PVT__buckets_count_9
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_9)
                                ? vlSelfRef.__PVT__buckets_count_9
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    VL_ADD_W(3, __Vtemp_43, __Vtemp_41, __Vtemp_42);
    __Vtemp_45[0U] = __Vtemp_43[0U];
    __Vtemp_45[1U] = __Vtemp_43[1U];
    __Vtemp_45[2U] = (1U & __Vtemp_43[2U]);
    __Vtemp_47[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_10)
                               ? vlSelfRef.__PVT__buckets_count_10
                               : 0ULL));
    __Vtemp_47[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_10)
                                ? vlSelfRef.__PVT__buckets_count_10
                                : 0ULL) >> 0x20U));
    __Vtemp_47[2U] = 0U;
    __Vtemp_48[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_11)
                               ? vlSelfRef.__PVT__buckets_count_11
                               : 0ULL));
    __Vtemp_48[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_11)
                                ? vlSelfRef.__PVT__buckets_count_11
                                : 0ULL) >> 0x20U));
    __Vtemp_48[2U] = 0U;
    VL_ADD_W(3, __Vtemp_49, __Vtemp_47, __Vtemp_48);
    __Vtemp_51[0U] = __Vtemp_49[0U];
    __Vtemp_51[1U] = __Vtemp_49[1U];
    __Vtemp_51[2U] = (1U & __Vtemp_49[2U]);
    VL_ADD_W(3, __Vtemp_52, __Vtemp_45, __Vtemp_51);
    __Vtemp_54[0U] = __Vtemp_52[0U];
    __Vtemp_54[1U] = __Vtemp_52[1U];
    __Vtemp_54[2U] = (3U & __Vtemp_52[2U]);
    __Vtemp_57[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_12)
                               ? vlSelfRef.__PVT__buckets_count_12
                               : 0ULL));
    __Vtemp_57[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_12)
                                ? vlSelfRef.__PVT__buckets_count_12
                                : 0ULL) >> 0x20U));
    __Vtemp_57[2U] = 0U;
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_13)
                               ? vlSelfRef.__PVT__buckets_count_13
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_13)
                                ? vlSelfRef.__PVT__buckets_count_13
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    VL_ADD_W(3, __Vtemp_59, __Vtemp_57, __Vtemp_58);
    __Vtemp_61[0U] = __Vtemp_59[0U];
    __Vtemp_61[1U] = __Vtemp_59[1U];
    __Vtemp_61[2U] = (1U & __Vtemp_59[2U]);
    __Vtemp_63[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_14)
                               ? vlSelfRef.__PVT__buckets_count_14
                               : 0ULL));
    __Vtemp_63[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_14)
                                ? vlSelfRef.__PVT__buckets_count_14
                                : 0ULL) >> 0x20U));
    __Vtemp_63[2U] = 0U;
    __Vtemp_64[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_15)
                               ? vlSelfRef.__PVT__buckets_count_15
                               : 0ULL));
    __Vtemp_64[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_15)
                                ? vlSelfRef.__PVT__buckets_count_15
                                : 0ULL) >> 0x20U));
    __Vtemp_64[2U] = 0U;
    VL_ADD_W(3, __Vtemp_65, __Vtemp_63, __Vtemp_64);
    __Vtemp_67[0U] = __Vtemp_65[0U];
    __Vtemp_67[1U] = __Vtemp_65[1U];
    __Vtemp_67[2U] = (1U & __Vtemp_65[2U]);
    VL_ADD_W(3, __Vtemp_68, __Vtemp_61, __Vtemp_67);
    __Vtemp_70[0U] = __Vtemp_68[0U];
    __Vtemp_70[1U] = __Vtemp_68[1U];
    __Vtemp_70[2U] = (3U & __Vtemp_68[2U]);
    VL_ADD_W(3, __Vtemp_71, __Vtemp_54, __Vtemp_70);
    __Vtemp_73[0U] = __Vtemp_71[0U];
    __Vtemp_73[1U] = __Vtemp_71[1U];
    __Vtemp_73[2U] = (7U & __Vtemp_71[2U]);
    VL_ADD_W(3, __Vtemp_74, __Vtemp_37, __Vtemp_73);
    vlSelfRef.io_resolvedCount[0U] = __Vtemp_74[0U];
    vlSelfRef.io_resolvedCount[1U] = __Vtemp_74[1U];
    vlSelfRef.io_resolvedCount[2U] = (0xfU & __Vtemp_74[2U]);
    vlSelfRef.__PVT___canAccept_T_46 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_15)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_15)));
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
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_5__3(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_5__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_8 = ((0x58U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_25) 
                                       | (vlSelfRef.__PVT__buckets_seq_8 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_9 = ((0x59U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_28) 
                                       | (vlSelfRef.__PVT__buckets_seq_9 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_10 = ((0x5aU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_31) 
                                        | (vlSelfRef.__PVT__buckets_seq_10 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_11 = ((0x5bU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_34) 
                                        | (vlSelfRef.__PVT__buckets_seq_11 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_12 = ((0x5cU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_37) 
                                        | (vlSelfRef.__PVT__buckets_seq_12 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_13 = ((0x5dU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_40) 
                                        | (vlSelfRef.__PVT__buckets_seq_13 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_14 = ((0x5eU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_43) 
                                        | (vlSelfRef.__PVT__buckets_seq_14 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_15 = ((0x5fU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_46) 
                                        | (vlSelfRef.__PVT__buckets_seq_15 
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
    vlSelfRef.__PVT__accepted_8 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_8));
    vlSelfRef.__PVT__accepted_9 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_9));
    vlSelfRef.__PVT__accepted_10 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_10));
    vlSelfRef.__PVT__accepted_11 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_11));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_5__2(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_5__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_9;
    VlWide<3>/*95:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_13;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_21;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_25;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_29;
    VlWide<3>/*95:0*/ __Vtemp_31;
    VlWide<3>/*95:0*/ __Vtemp_32;
    VlWide<3>/*95:0*/ __Vtemp_34;
    VlWide<3>/*95:0*/ __Vtemp_35;
    VlWide<3>/*95:0*/ __Vtemp_37;
    VlWide<3>/*95:0*/ __Vtemp_41;
    VlWide<3>/*95:0*/ __Vtemp_42;
    VlWide<3>/*95:0*/ __Vtemp_43;
    VlWide<3>/*95:0*/ __Vtemp_45;
    VlWide<3>/*95:0*/ __Vtemp_47;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_49;
    VlWide<3>/*95:0*/ __Vtemp_51;
    VlWide<3>/*95:0*/ __Vtemp_52;
    VlWide<3>/*95:0*/ __Vtemp_54;
    VlWide<3>/*95:0*/ __Vtemp_57;
    VlWide<3>/*95:0*/ __Vtemp_58;
    VlWide<3>/*95:0*/ __Vtemp_59;
    VlWide<3>/*95:0*/ __Vtemp_61;
    VlWide<3>/*95:0*/ __Vtemp_63;
    VlWide<3>/*95:0*/ __Vtemp_64;
    VlWide<3>/*95:0*/ __Vtemp_65;
    VlWide<3>/*95:0*/ __Vtemp_67;
    VlWide<3>/*95:0*/ __Vtemp_68;
    VlWide<3>/*95:0*/ __Vtemp_70;
    VlWide<3>/*95:0*/ __Vtemp_71;
    VlWide<3>/*95:0*/ __Vtemp_73;
    VlWide<3>/*95:0*/ __Vtemp_74;
    // Body
    vlSelfRef.__PVT___GEN_30 = ((~ (IData)(vlSelfRef.__PVT__resolving_2)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_2));
    __Vtemp_5[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_0)
                              ? vlSelfRef.__PVT__buckets_count_0
                              : 0ULL));
    __Vtemp_5[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_0)
                               ? vlSelfRef.__PVT__buckets_count_0
                               : 0ULL) >> 0x20U));
    __Vtemp_5[2U] = 0U;
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_1)
                              ? vlSelfRef.__PVT__buckets_count_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_1)
                               ? vlSelfRef.__PVT__buckets_count_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    VL_ADD_W(3, __Vtemp_7, __Vtemp_5, __Vtemp_6);
    __Vtemp_9[0U] = __Vtemp_7[0U];
    __Vtemp_9[1U] = __Vtemp_7[1U];
    __Vtemp_9[2U] = (1U & __Vtemp_7[2U]);
    __Vtemp_11[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_2)
                               ? vlSelfRef.__PVT__buckets_count_2
                               : 0ULL));
    __Vtemp_11[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_2)
                                ? vlSelfRef.__PVT__buckets_count_2
                                : 0ULL) >> 0x20U));
    __Vtemp_11[2U] = 0U;
    __Vtemp_12[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_3)
                               ? vlSelfRef.__PVT__buckets_count_3
                               : 0ULL));
    __Vtemp_12[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_3)
                                ? vlSelfRef.__PVT__buckets_count_3
                                : 0ULL) >> 0x20U));
    __Vtemp_12[2U] = 0U;
    VL_ADD_W(3, __Vtemp_13, __Vtemp_11, __Vtemp_12);
    __Vtemp_15[0U] = __Vtemp_13[0U];
    __Vtemp_15[1U] = __Vtemp_13[1U];
    __Vtemp_15[2U] = (1U & __Vtemp_13[2U]);
    VL_ADD_W(3, __Vtemp_16, __Vtemp_9, __Vtemp_15);
    __Vtemp_18[0U] = __Vtemp_16[0U];
    __Vtemp_18[1U] = __Vtemp_16[1U];
    __Vtemp_18[2U] = (3U & __Vtemp_16[2U]);
    __Vtemp_21[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_4)
                               ? vlSelfRef.__PVT__buckets_count_4
                               : 0ULL));
    __Vtemp_21[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_4)
                                ? vlSelfRef.__PVT__buckets_count_4
                                : 0ULL) >> 0x20U));
    __Vtemp_21[2U] = 0U;
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_5)
                               ? vlSelfRef.__PVT__buckets_count_5
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_5)
                                ? vlSelfRef.__PVT__buckets_count_5
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    VL_ADD_W(3, __Vtemp_23, __Vtemp_21, __Vtemp_22);
    __Vtemp_25[0U] = __Vtemp_23[0U];
    __Vtemp_25[1U] = __Vtemp_23[1U];
    __Vtemp_25[2U] = (1U & __Vtemp_23[2U]);
    __Vtemp_27[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_6)
                               ? vlSelfRef.__PVT__buckets_count_6
                               : 0ULL));
    __Vtemp_27[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_6)
                                ? vlSelfRef.__PVT__buckets_count_6
                                : 0ULL) >> 0x20U));
    __Vtemp_27[2U] = 0U;
    __Vtemp_28[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_7)
                               ? vlSelfRef.buckets_count_7
                               : 0ULL));
    __Vtemp_28[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_7)
                                ? vlSelfRef.buckets_count_7
                                : 0ULL) >> 0x20U));
    __Vtemp_28[2U] = 0U;
    VL_ADD_W(3, __Vtemp_29, __Vtemp_27, __Vtemp_28);
    __Vtemp_31[0U] = __Vtemp_29[0U];
    __Vtemp_31[1U] = __Vtemp_29[1U];
    __Vtemp_31[2U] = (1U & __Vtemp_29[2U]);
    VL_ADD_W(3, __Vtemp_32, __Vtemp_25, __Vtemp_31);
    __Vtemp_34[0U] = __Vtemp_32[0U];
    __Vtemp_34[1U] = __Vtemp_32[1U];
    __Vtemp_34[2U] = (3U & __Vtemp_32[2U]);
    VL_ADD_W(3, __Vtemp_35, __Vtemp_18, __Vtemp_34);
    __Vtemp_37[0U] = __Vtemp_35[0U];
    __Vtemp_37[1U] = __Vtemp_35[1U];
    __Vtemp_37[2U] = (7U & __Vtemp_35[2U]);
    __Vtemp_41[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_8)
                               ? vlSelfRef.__PVT__buckets_count_8
                               : 0ULL));
    __Vtemp_41[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_8)
                                ? vlSelfRef.__PVT__buckets_count_8
                                : 0ULL) >> 0x20U));
    __Vtemp_41[2U] = 0U;
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_9)
                               ? vlSelfRef.__PVT__buckets_count_9
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_9)
                                ? vlSelfRef.__PVT__buckets_count_9
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    VL_ADD_W(3, __Vtemp_43, __Vtemp_41, __Vtemp_42);
    __Vtemp_45[0U] = __Vtemp_43[0U];
    __Vtemp_45[1U] = __Vtemp_43[1U];
    __Vtemp_45[2U] = (1U & __Vtemp_43[2U]);
    __Vtemp_47[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_10)
                               ? vlSelfRef.__PVT__buckets_count_10
                               : 0ULL));
    __Vtemp_47[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_10)
                                ? vlSelfRef.__PVT__buckets_count_10
                                : 0ULL) >> 0x20U));
    __Vtemp_47[2U] = 0U;
    __Vtemp_48[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_11)
                               ? vlSelfRef.__PVT__buckets_count_11
                               : 0ULL));
    __Vtemp_48[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_11)
                                ? vlSelfRef.__PVT__buckets_count_11
                                : 0ULL) >> 0x20U));
    __Vtemp_48[2U] = 0U;
    VL_ADD_W(3, __Vtemp_49, __Vtemp_47, __Vtemp_48);
    __Vtemp_51[0U] = __Vtemp_49[0U];
    __Vtemp_51[1U] = __Vtemp_49[1U];
    __Vtemp_51[2U] = (1U & __Vtemp_49[2U]);
    VL_ADD_W(3, __Vtemp_52, __Vtemp_45, __Vtemp_51);
    __Vtemp_54[0U] = __Vtemp_52[0U];
    __Vtemp_54[1U] = __Vtemp_52[1U];
    __Vtemp_54[2U] = (3U & __Vtemp_52[2U]);
    __Vtemp_57[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_12)
                               ? vlSelfRef.__PVT__buckets_count_12
                               : 0ULL));
    __Vtemp_57[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_12)
                                ? vlSelfRef.__PVT__buckets_count_12
                                : 0ULL) >> 0x20U));
    __Vtemp_57[2U] = 0U;
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_13)
                               ? vlSelfRef.__PVT__buckets_count_13
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_13)
                                ? vlSelfRef.__PVT__buckets_count_13
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    VL_ADD_W(3, __Vtemp_59, __Vtemp_57, __Vtemp_58);
    __Vtemp_61[0U] = __Vtemp_59[0U];
    __Vtemp_61[1U] = __Vtemp_59[1U];
    __Vtemp_61[2U] = (1U & __Vtemp_59[2U]);
    __Vtemp_63[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_14)
                               ? vlSelfRef.__PVT__buckets_count_14
                               : 0ULL));
    __Vtemp_63[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_14)
                                ? vlSelfRef.__PVT__buckets_count_14
                                : 0ULL) >> 0x20U));
    __Vtemp_63[2U] = 0U;
    __Vtemp_64[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_15)
                               ? vlSelfRef.__PVT__buckets_count_15
                               : 0ULL));
    __Vtemp_64[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_15)
                                ? vlSelfRef.__PVT__buckets_count_15
                                : 0ULL) >> 0x20U));
    __Vtemp_64[2U] = 0U;
    VL_ADD_W(3, __Vtemp_65, __Vtemp_63, __Vtemp_64);
    __Vtemp_67[0U] = __Vtemp_65[0U];
    __Vtemp_67[1U] = __Vtemp_65[1U];
    __Vtemp_67[2U] = (1U & __Vtemp_65[2U]);
    VL_ADD_W(3, __Vtemp_68, __Vtemp_61, __Vtemp_67);
    __Vtemp_70[0U] = __Vtemp_68[0U];
    __Vtemp_70[1U] = __Vtemp_68[1U];
    __Vtemp_70[2U] = (3U & __Vtemp_68[2U]);
    VL_ADD_W(3, __Vtemp_71, __Vtemp_54, __Vtemp_70);
    __Vtemp_73[0U] = __Vtemp_71[0U];
    __Vtemp_73[1U] = __Vtemp_71[1U];
    __Vtemp_73[2U] = (7U & __Vtemp_71[2U]);
    VL_ADD_W(3, __Vtemp_74, __Vtemp_37, __Vtemp_73);
    vlSelfRef.io_resolvedCount[0U] = __Vtemp_74[0U];
    vlSelfRef.io_resolvedCount[1U] = __Vtemp_74[1U];
    vlSelfRef.io_resolvedCount[2U] = (0xfU & __Vtemp_74[2U]);
    vlSelfRef.__PVT___canAccept_T_7 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_2)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_2)));
    vlSelfRef.__PVT__available_5 = ((0x55U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x54U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_15 = ((0x5fU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_46) 
                                        | (vlSelfRef.__PVT__buckets_seq_15 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x53U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_9 = ((0x59U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_28) 
                                       | (vlSelfRef.__PVT__buckets_seq_9 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_10 = ((0x5aU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_31) 
                                        | (vlSelfRef.__PVT__buckets_seq_10 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
}
