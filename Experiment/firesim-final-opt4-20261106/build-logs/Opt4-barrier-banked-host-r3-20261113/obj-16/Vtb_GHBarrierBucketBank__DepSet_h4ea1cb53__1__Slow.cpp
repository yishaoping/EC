// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_GHBarrierBucketBank.h"
#include "Vtb__Syms.h"

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_15__3(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_15__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___canAccept_T_46 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_15)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_15)));
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
    vlSelfRef.__PVT__available_8 = ((0xf8U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_25) 
                                       | (vlSelfRef.__PVT__buckets_seq_8 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_9 = ((0xf9U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_28) 
                                       | (vlSelfRef.__PVT__buckets_seq_9 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_10 = ((0xfaU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_31) 
                                        | (vlSelfRef.__PVT__buckets_seq_10 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_11 = ((0xfbU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_34) 
                                        | (vlSelfRef.__PVT__buckets_seq_11 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_12 = ((0xfcU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_37) 
                                        | (vlSelfRef.__PVT__buckets_seq_12 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_13 = ((0xfdU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_40) 
                                        | (vlSelfRef.__PVT__buckets_seq_13 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_15__4(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_15__4\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__available_14 = ((0xfeU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_43) 
                                        | (vlSelfRef.__PVT__buckets_seq_14 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_15 = ((0xffU == (0xffU 
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
    vlSelfRef.__PVT__accepted_12 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_12));
    vlSelfRef.__PVT__accepted_13 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_13));
    vlSelfRef.__PVT__accepted_14 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_14));
    vlSelfRef.__PVT__accepted_15 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_15));
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
    vlSelfRef.__PVT___countOverflow_8_T_2 = ((IData)(vlSelfRef.__PVT__accepted_8) 
                                             & (IData)(vlSelfRef.__PVT___GEN_120));
    vlSelfRef.__PVT___countOverflow_9_T_2 = ((IData)(vlSelfRef.__PVT__accepted_9) 
                                             & (IData)(vlSelfRef.__PVT___GEN_135));
    vlSelfRef.__PVT___countOverflow_10_T_2 = ((IData)(vlSelfRef.__PVT__accepted_10) 
                                              & (IData)(vlSelfRef.__PVT___GEN_150));
    vlSelfRef.__PVT___countOverflow_11_T_2 = ((IData)(vlSelfRef.__PVT__accepted_11) 
                                              & (IData)(vlSelfRef.__PVT___GEN_165));
    vlSelfRef.__PVT___countOverflow_12_T_2 = ((IData)(vlSelfRef.__PVT__accepted_12) 
                                              & (IData)(vlSelfRef.__PVT___GEN_180));
    vlSelfRef.__PVT___countOverflow_13_T_2 = ((IData)(vlSelfRef.__PVT__accepted_13) 
                                              & (IData)(vlSelfRef.__PVT___GEN_195));
    vlSelfRef.__PVT___countOverflow_14_T_2 = ((IData)(vlSelfRef.__PVT__accepted_14) 
                                              & (IData)(vlSelfRef.__PVT___GEN_210));
    vlSelfRef.__PVT___countOverflow_15_T_2 = ((IData)(vlSelfRef.__PVT__accepted_15) 
                                              & (IData)(vlSelfRef.__PVT___GEN_225));
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
