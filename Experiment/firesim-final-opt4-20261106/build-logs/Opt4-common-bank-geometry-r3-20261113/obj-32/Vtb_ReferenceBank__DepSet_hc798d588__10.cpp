// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_ReferenceBank.h"
#include "Vtb__Syms.h"

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__175(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__175\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketStrictWriteRead_8_0 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_8_1 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_8_2 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_8_3 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_8_0 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_8_1 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_8_2 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring_8)) 
                & (IData)(vlSelfRef.__PVT__bucketValid_8))) {
        vlSelfRef.__PVT__bucketStrictWriteRead_8_0 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_8_1 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_8_2 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_8_3 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_8_0 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_8_1 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_8_2 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (((IData)(vlSelfRef.__PVT__isCurrent_8) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38886)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_8_0 
                = ((IData)(vlSelfRef.__PVT__allocate_8)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38886))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_32[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_32[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_8) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_39302)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_8_1 
                = ((IData)(vlSelfRef.__PVT__allocate_8)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_39302))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_33[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_33[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_8) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_39738)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_8_2 
                = ((IData)(vlSelfRef.__PVT__allocate_8)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_39738))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_34[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_34[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_8) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_40174)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_8_3 
                = ((IData)(vlSelfRef.__PVT__allocate_8)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_40174))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_35[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_35[0U]))));
        }
        if (vlSelfRef.__PVT__isCurrent_8) {
            vlSelfRef.__PVT__bucketFirstStore_8_0 = 
                (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_32[1U])) 
                  << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_32[0U])));
            vlSelfRef.__PVT__bucketFirstStore_8_1 = 
                (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_33[1U])) 
                  << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_33[0U])));
            vlSelfRef.__PVT__bucketFirstStore_8_2 = 
                (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_34[1U])) 
                  << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_34[0U])));
        }
    }
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__176(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__176\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketFirstStore_8_3 = 0ULL;
        vlSelfRef.__PVT__bucketStore_1_0 = 0ULL;
        vlSelfRef.__PVT__bucketStore_1_1 = 0ULL;
        vlSelfRef.__PVT__bucketStore_1_2 = 0ULL;
        vlSelfRef.__PVT__bucketStore_1_3 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_1_0 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_1_1 = 0ULL;
    } else {
        if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
               & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
              & (IData)(vlSelfRef.__PVT__isRetiring_8)) 
             & (IData)(vlSelfRef.__PVT__bucketValid_8))) {
            vlSelfRef.__PVT__bucketFirstStore_8_3 = 0ULL;
        } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
            if (vlSelfRef.__PVT__isCurrent_8) {
                vlSelfRef.__PVT__bucketFirstStore_8_3 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_35[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_35[0U])));
            }
        }
        if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
               & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
              & (IData)(vlSelfRef.__PVT__isRetiring_1)) 
             & (IData)(vlSelfRef.__PVT__bucketValid_1))) {
            vlSelfRef.__PVT__bucketStore_1_0 = 0ULL;
            vlSelfRef.__PVT__bucketStore_1_1 = 0ULL;
            vlSelfRef.__PVT__bucketStore_1_2 = 0ULL;
            vlSelfRef.__PVT__bucketStore_1_3 = 0ULL;
            vlSelfRef.__PVT__bucketLoadFirst_1_0 = 0ULL;
            vlSelfRef.__PVT__bucketLoadFirst_1_1 = 0ULL;
        } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
            if (vlSelfRef.__PVT__isCurrent_1) {
                vlSelfRef.__PVT__bucketStore_1_0 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_4[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_4[0U])));
                vlSelfRef.__PVT__bucketStore_1_1 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_5[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_5[0U])));
                vlSelfRef.__PVT__bucketStore_1_2 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_6[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_6[0U])));
                vlSelfRef.__PVT__bucketStore_1_3 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_7[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_7[0U])));
            }
            if (((IData)(vlSelfRef.__PVT__isCurrent_1) 
                 | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_749)))) {
                vlSelfRef.__PVT__bucketLoadFirst_1_0 
                    = ((IData)(vlSelfRef.__PVT__allocate_1)
                        ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_749))
                        : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_4[1U])) 
                            << 0x20U) | (QData)((IData)(
                                                        vlSelfRef.__PVT__loadFirstNextWide_4[0U]))));
            }
            if (((IData)(vlSelfRef.__PVT__isCurrent_1) 
                 | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_788)))) {
                vlSelfRef.__PVT__bucketLoadFirst_1_1 
                    = ((IData)(vlSelfRef.__PVT__allocate_1)
                        ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_788))
                        : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_5[1U])) 
                            << 0x20U) | (QData)((IData)(
                                                        vlSelfRef.__PVT__loadFirstNextWide_5[0U]))));
            }
        }
    }
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__177(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__177\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketLoadFirst_1_2 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_1_3 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_1_0 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_1_1 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_1_2 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_1_3 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring_1)) 
                & (IData)(vlSelfRef.__PVT__bucketValid_1))) {
        vlSelfRef.__PVT__bucketLoadFirst_1_2 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_1_3 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_1_0 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_1_1 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_1_2 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_1_3 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (((IData)(vlSelfRef.__PVT__isCurrent_1) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_829)))) {
            vlSelfRef.__PVT__bucketLoadFirst_1_2 = 
                ((IData)(vlSelfRef.__PVT__allocate_1)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_829))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_6[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_6[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_1) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_870)))) {
            vlSelfRef.__PVT__bucketLoadFirst_1_3 = 
                ((IData)(vlSelfRef.__PVT__allocate_1)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_870))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_7[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_7[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_1) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_749)))) {
            vlSelfRef.__PVT__bucketStoreFirst_1_0 = 
                ((IData)(vlSelfRef.__PVT__allocate_1)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_749))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_4[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_4[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_1) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_788)))) {
            vlSelfRef.__PVT__bucketStoreFirst_1_1 = 
                ((IData)(vlSelfRef.__PVT__allocate_1)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_788))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_5[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_5[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_1) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_829)))) {
            vlSelfRef.__PVT__bucketStoreFirst_1_2 = 
                ((IData)(vlSelfRef.__PVT__allocate_1)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_829))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_6[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_6[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_1) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_870)))) {
            vlSelfRef.__PVT__bucketStoreFirst_1_3 = 
                ((IData)(vlSelfRef.__PVT__allocate_1)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_870))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_7[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_7[0U]))));
        }
    }
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__178(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__178\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketStrictWriteRead_1_0 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_1_1 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_1_2 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_1_3 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_1_0 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_1_1 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_1_2 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring_1)) 
                & (IData)(vlSelfRef.__PVT__bucketValid_1))) {
        vlSelfRef.__PVT__bucketStrictWriteRead_1_0 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_1_1 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_1_2 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_1_3 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_1_0 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_1_1 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_1_2 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (((IData)(vlSelfRef.__PVT__isCurrent_1) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7638)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_1_0 
                = ((IData)(vlSelfRef.__PVT__allocate_1)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7638))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_4[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_4[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_1) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_8054)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_1_1 
                = ((IData)(vlSelfRef.__PVT__allocate_1)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_8054))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_5[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_5[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_1) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_8490)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_1_2 
                = ((IData)(vlSelfRef.__PVT__allocate_1)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_8490))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_6[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_6[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_1) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_8926)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_1_3 
                = ((IData)(vlSelfRef.__PVT__allocate_1)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_8926))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_7[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_7[0U]))));
        }
        if (vlSelfRef.__PVT__isCurrent_1) {
            vlSelfRef.__PVT__bucketFirstStore_1_0 = 
                (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_4[1U])) 
                  << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_4[0U])));
            vlSelfRef.__PVT__bucketFirstStore_1_1 = 
                (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_5[1U])) 
                  << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_5[0U])));
            vlSelfRef.__PVT__bucketFirstStore_1_2 = 
                (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_6[1U])) 
                  << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_6[0U])));
        }
    }
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__179(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__179\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketFirstStore_1_3 = 0ULL;
        vlSelfRef.__PVT__bucketStore_10_0 = 0ULL;
        vlSelfRef.__PVT__bucketStore_10_1 = 0ULL;
        vlSelfRef.__PVT__bucketStore_10_2 = 0ULL;
        vlSelfRef.__PVT__bucketStore_10_3 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_10_0 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_10_1 = 0ULL;
    } else {
        if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
               & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
              & (IData)(vlSelfRef.__PVT__isRetiring_1)) 
             & (IData)(vlSelfRef.__PVT__bucketValid_1))) {
            vlSelfRef.__PVT__bucketFirstStore_1_3 = 0ULL;
        } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
            if (vlSelfRef.__PVT__isCurrent_1) {
                vlSelfRef.__PVT__bucketFirstStore_1_3 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_7[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_7[0U])));
            }
        }
        if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
               & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
              & (IData)(vlSelfRef.__PVT__isRetiring_10)) 
             & (IData)(vlSelfRef.__PVT__bucketValid_10))) {
            vlSelfRef.__PVT__bucketStore_10_0 = 0ULL;
            vlSelfRef.__PVT__bucketStore_10_1 = 0ULL;
            vlSelfRef.__PVT__bucketStore_10_2 = 0ULL;
            vlSelfRef.__PVT__bucketStore_10_3 = 0ULL;
            vlSelfRef.__PVT__bucketLoadFirst_10_0 = 0ULL;
            vlSelfRef.__PVT__bucketLoadFirst_10_1 = 0ULL;
        } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
            if (vlSelfRef.__PVT__isCurrent_10) {
                vlSelfRef.__PVT__bucketStore_10_0 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_40[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_40[0U])));
                vlSelfRef.__PVT__bucketStore_10_1 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_41[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_41[0U])));
                vlSelfRef.__PVT__bucketStore_10_2 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_42[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_42[0U])));
                vlSelfRef.__PVT__bucketStore_10_3 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_43[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_43[0U])));
            }
            if (((IData)(vlSelfRef.__PVT__isCurrent_10) 
                 | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4673)))) {
                vlSelfRef.__PVT__bucketLoadFirst_10_0 
                    = ((IData)(vlSelfRef.__PVT__allocate_10)
                        ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4673))
                        : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_40[1U])) 
                            << 0x20U) | (QData)((IData)(
                                                        vlSelfRef.__PVT__loadFirstNextWide_40[0U]))));
            }
            if (((IData)(vlSelfRef.__PVT__isCurrent_10) 
                 | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4712)))) {
                vlSelfRef.__PVT__bucketLoadFirst_10_1 
                    = ((IData)(vlSelfRef.__PVT__allocate_10)
                        ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4712))
                        : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_41[1U])) 
                            << 0x20U) | (QData)((IData)(
                                                        vlSelfRef.__PVT__loadFirstNextWide_41[0U]))));
            }
        }
    }
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__180(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__180\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketLoadFirst_10_2 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_10_3 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_10_0 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_10_1 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_10_2 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_10_3 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring_10)) 
                & (IData)(vlSelfRef.__PVT__bucketValid_10))) {
        vlSelfRef.__PVT__bucketLoadFirst_10_2 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_10_3 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_10_0 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_10_1 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_10_2 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_10_3 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (((IData)(vlSelfRef.__PVT__isCurrent_10) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4753)))) {
            vlSelfRef.__PVT__bucketLoadFirst_10_2 = 
                ((IData)(vlSelfRef.__PVT__allocate_10)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4753))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_42[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_42[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_10) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4794)))) {
            vlSelfRef.__PVT__bucketLoadFirst_10_3 = 
                ((IData)(vlSelfRef.__PVT__allocate_10)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4794))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_43[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_43[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_10) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_4673)))) {
            vlSelfRef.__PVT__bucketStoreFirst_10_0 
                = ((IData)(vlSelfRef.__PVT__allocate_10)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_4673))
                    : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_40[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__storeFirstNextWide_40[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_10) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_4712)))) {
            vlSelfRef.__PVT__bucketStoreFirst_10_1 
                = ((IData)(vlSelfRef.__PVT__allocate_10)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_4712))
                    : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_41[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__storeFirstNextWide_41[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_10) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_4753)))) {
            vlSelfRef.__PVT__bucketStoreFirst_10_2 
                = ((IData)(vlSelfRef.__PVT__allocate_10)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_4753))
                    : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_42[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__storeFirstNextWide_42[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_10) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_4794)))) {
            vlSelfRef.__PVT__bucketStoreFirst_10_3 
                = ((IData)(vlSelfRef.__PVT__allocate_10)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_4794))
                    : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_43[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__storeFirstNextWide_43[0U]))));
        }
    }
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__181(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__181\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketStrictWriteRead_10_0 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_10_1 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_10_2 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_10_3 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_10_0 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_10_1 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_10_2 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring_10)) 
                & (IData)(vlSelfRef.__PVT__bucketValid_10))) {
        vlSelfRef.__PVT__bucketStrictWriteRead_10_0 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_10_1 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_10_2 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_10_3 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_10_0 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_10_1 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_10_2 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (((IData)(vlSelfRef.__PVT__isCurrent_10) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47814)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_10_0 
                = ((IData)(vlSelfRef.__PVT__allocate_10)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47814))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_40[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_40[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_10) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_48230)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_10_1 
                = ((IData)(vlSelfRef.__PVT__allocate_10)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_48230))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_41[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_41[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_10) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_48666)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_10_2 
                = ((IData)(vlSelfRef.__PVT__allocate_10)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_48666))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_42[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_42[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_10) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_49102)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_10_3 
                = ((IData)(vlSelfRef.__PVT__allocate_10)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_49102))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_43[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_43[0U]))));
        }
        if (vlSelfRef.__PVT__isCurrent_10) {
            vlSelfRef.__PVT__bucketFirstStore_10_0 
                = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_40[1U])) 
                    << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_40[0U])));
            vlSelfRef.__PVT__bucketFirstStore_10_1 
                = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_41[1U])) 
                    << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_41[0U])));
            vlSelfRef.__PVT__bucketFirstStore_10_2 
                = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_42[1U])) 
                    << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_42[0U])));
        }
    }
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__182(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__182\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketFirstStore_10_3 = 0ULL;
        vlSelfRef.__PVT__bucketStore_12_0 = 0ULL;
        vlSelfRef.__PVT__bucketStore_12_1 = 0ULL;
        vlSelfRef.__PVT__bucketStore_12_2 = 0ULL;
        vlSelfRef.__PVT__bucketStore_12_3 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_12_0 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_12_1 = 0ULL;
    } else {
        if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
               & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
              & (IData)(vlSelfRef.__PVT__isRetiring_10)) 
             & (IData)(vlSelfRef.__PVT__bucketValid_10))) {
            vlSelfRef.__PVT__bucketFirstStore_10_3 = 0ULL;
        } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
            if (vlSelfRef.__PVT__isCurrent_10) {
                vlSelfRef.__PVT__bucketFirstStore_10_3 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_43[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_43[0U])));
            }
        }
        if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
               & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
              & (IData)(vlSelfRef.__PVT__isRetiring_12)) 
             & (IData)(vlSelfRef.__PVT__bucketValid_12))) {
            vlSelfRef.__PVT__bucketStore_12_0 = 0ULL;
            vlSelfRef.__PVT__bucketStore_12_1 = 0ULL;
            vlSelfRef.__PVT__bucketStore_12_2 = 0ULL;
            vlSelfRef.__PVT__bucketStore_12_3 = 0ULL;
            vlSelfRef.__PVT__bucketLoadFirst_12_0 = 0ULL;
            vlSelfRef.__PVT__bucketLoadFirst_12_1 = 0ULL;
        } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
            if (vlSelfRef.__PVT__isCurrent_12) {
                vlSelfRef.__PVT__bucketStore_12_0 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_48[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_48[0U])));
                vlSelfRef.__PVT__bucketStore_12_1 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_49[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_49[0U])));
                vlSelfRef.__PVT__bucketStore_12_2 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_50[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_50[0U])));
                vlSelfRef.__PVT__bucketStore_12_3 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_51[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_51[0U])));
            }
            if (((IData)(vlSelfRef.__PVT__isCurrent_12) 
                 | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5545)))) {
                vlSelfRef.__PVT__bucketLoadFirst_12_0 
                    = ((IData)(vlSelfRef.__PVT__allocate_12)
                        ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5545))
                        : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_48[1U])) 
                            << 0x20U) | (QData)((IData)(
                                                        vlSelfRef.__PVT__loadFirstNextWide_48[0U]))));
            }
            if (((IData)(vlSelfRef.__PVT__isCurrent_12) 
                 | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5584)))) {
                vlSelfRef.__PVT__bucketLoadFirst_12_1 
                    = ((IData)(vlSelfRef.__PVT__allocate_12)
                        ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5584))
                        : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_49[1U])) 
                            << 0x20U) | (QData)((IData)(
                                                        vlSelfRef.__PVT__loadFirstNextWide_49[0U]))));
            }
        }
    }
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__183(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__183\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketLoadFirst_12_2 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_12_3 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_12_0 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_12_1 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_12_2 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_12_3 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring_12)) 
                & (IData)(vlSelfRef.__PVT__bucketValid_12))) {
        vlSelfRef.__PVT__bucketLoadFirst_12_2 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_12_3 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_12_0 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_12_1 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_12_2 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_12_3 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (((IData)(vlSelfRef.__PVT__isCurrent_12) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5625)))) {
            vlSelfRef.__PVT__bucketLoadFirst_12_2 = 
                ((IData)(vlSelfRef.__PVT__allocate_12)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5625))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_50[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_50[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_12) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5666)))) {
            vlSelfRef.__PVT__bucketLoadFirst_12_3 = 
                ((IData)(vlSelfRef.__PVT__allocate_12)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5666))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_51[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_51[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_12) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_5545)))) {
            vlSelfRef.__PVT__bucketStoreFirst_12_0 
                = ((IData)(vlSelfRef.__PVT__allocate_12)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_5545))
                    : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_48[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__storeFirstNextWide_48[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_12) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_5584)))) {
            vlSelfRef.__PVT__bucketStoreFirst_12_1 
                = ((IData)(vlSelfRef.__PVT__allocate_12)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_5584))
                    : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_49[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__storeFirstNextWide_49[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_12) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_5625)))) {
            vlSelfRef.__PVT__bucketStoreFirst_12_2 
                = ((IData)(vlSelfRef.__PVT__allocate_12)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_5625))
                    : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_50[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__storeFirstNextWide_50[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_12) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_5666)))) {
            vlSelfRef.__PVT__bucketStoreFirst_12_3 
                = ((IData)(vlSelfRef.__PVT__allocate_12)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_5666))
                    : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_51[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__storeFirstNextWide_51[0U]))));
        }
    }
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__184(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__184\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketStrictWriteRead_12_0 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_12_1 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_12_2 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_12_3 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_12_0 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_12_1 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_12_2 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring_12)) 
                & (IData)(vlSelfRef.__PVT__bucketValid_12))) {
        vlSelfRef.__PVT__bucketStrictWriteRead_12_0 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_12_1 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_12_2 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_12_3 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_12_0 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_12_1 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_12_2 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (((IData)(vlSelfRef.__PVT__isCurrent_12) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56742)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_12_0 
                = ((IData)(vlSelfRef.__PVT__allocate_12)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56742))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_48[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_48[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_12) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_57158)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_12_1 
                = ((IData)(vlSelfRef.__PVT__allocate_12)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_57158))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_49[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_49[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_12) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_57594)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_12_2 
                = ((IData)(vlSelfRef.__PVT__allocate_12)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_57594))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_50[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_50[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_12) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_58030)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_12_3 
                = ((IData)(vlSelfRef.__PVT__allocate_12)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_58030))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_51[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_51[0U]))));
        }
        if (vlSelfRef.__PVT__isCurrent_12) {
            vlSelfRef.__PVT__bucketFirstStore_12_0 
                = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_48[1U])) 
                    << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_48[0U])));
            vlSelfRef.__PVT__bucketFirstStore_12_1 
                = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_49[1U])) 
                    << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_49[0U])));
            vlSelfRef.__PVT__bucketFirstStore_12_2 
                = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_50[1U])) 
                    << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_50[0U])));
        }
    }
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__185(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__185\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketFirstStore_12_3 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring_12)) 
                & (IData)(vlSelfRef.__PVT__bucketValid_12))) {
        vlSelfRef.__PVT__bucketFirstStore_12_3 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (vlSelfRef.__PVT__isCurrent_12) {
            vlSelfRef.__PVT__bucketFirstStore_12_3 
                = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_51[1U])) 
                    << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_51[0U])));
        }
    }
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__191(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__191\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___buckets_count_11_T_1 = (1ULL 
                                              + vlSelfRef.__PVT__buckets_count_11);
    vlSelfRef.__PVT___buckets_count_10_T_1 = (1ULL 
                                              + vlSelfRef.__PVT__buckets_count_10);
    vlSelfRef.__PVT___buckets_count_9_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_9);
    vlSelfRef.__PVT___buckets_count_4_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_4);
    vlSelfRef.__PVT___buckets_count_2_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_2);
    vlSelfRef.__PVT___buckets_count_1_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_1);
    vlSelfRef.__PVT___buckets_count_8_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_8);
    vlSelfRef.__PVT___buckets_count_7_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_7);
    vlSelfRef.__PVT___buckets_count_3_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_3);
    vlSelfRef.__PVT___buckets_count_14_T_1 = (1ULL 
                                              + vlSelfRef.__PVT__buckets_count_14);
    vlSelfRef.__PVT___buckets_count_13_T_1 = (1ULL 
                                              + vlSelfRef.__PVT__buckets_count_13);
    vlSelfRef.__PVT___buckets_count_5_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_5);
    vlSelfRef.__PVT___buckets_count_15_T_1 = (1ULL 
                                              + vlSelfRef.buckets_count_15);
    vlSelfRef.__PVT___buckets_count_6_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_6);
    vlSelfRef.__PVT___buckets_count_12_T_1 = (1ULL 
                                              + vlSelfRef.__PVT__buckets_count_12);
    vlSelfRef.__PVT__bucketValid_11 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                                       && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                           && ((1U 
                                                & (~ (IData)(vlSelfRef.__PVT___T_819))) 
                                               && (IData)(vlSelfRef.__PVT___GEN_1015))));
    vlSelfRef.bucketValid_15 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                                && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                    && ((1U & (~ (IData)(vlSelfRef.__PVT___T_1111))) 
                                        && (IData)(vlSelfRef.__PVT___GEN_1355))));
    vlSelfRef.__PVT__bucketValid_4 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                                      && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                          && ((1U & 
                                               (~ (IData)(vlSelfRef.__PVT___T_308))) 
                                              && (IData)(vlSelfRef.__PVT___GEN_420))));
    vlSelfRef.__PVT__bucketValid_9 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                                      && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                          && ((1U & 
                                               (~ (IData)(vlSelfRef.__PVT___T_673))) 
                                              && (IData)(vlSelfRef.__PVT___GEN_845))));
    vlSelfRef.__PVT__bucketValid_7 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                                      && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                          && ((1U & 
                                               (~ (IData)(vlSelfRef.__PVT___T_527))) 
                                              && (IData)(vlSelfRef.__PVT___GEN_675))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__192(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__192\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__bucketValid_5 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                                      && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                          && ((1U & 
                                               (~ (IData)(vlSelfRef.__PVT___T_381))) 
                                              && (IData)(vlSelfRef.__PVT___GEN_505))));
    vlSelfRef.__PVT__bucketValid_3 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                                      && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                          && ((1U & 
                                               (~ (IData)(vlSelfRef.__PVT___T_235))) 
                                              && (IData)(vlSelfRef.__PVT___GEN_335))));
    vlSelfRef.bucketValid_0 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                               && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                   && ((1U & (~ (IData)(vlSelfRef.__PVT___T_16))) 
                                       && (IData)(vlSelfRef.__PVT___GEN_80))));
    vlSelfRef.__PVT__bucketValid_14 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                                       && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                           && ((1U 
                                                & (~ (IData)(vlSelfRef.__PVT___T_1038))) 
                                               && (IData)(vlSelfRef.__PVT___GEN_1270))));
    vlSelfRef.__PVT__bucketValid_13 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                                       && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                           && ((1U 
                                                & (~ (IData)(vlSelfRef.__PVT___T_965))) 
                                               && (IData)(vlSelfRef.__PVT___GEN_1185))));
    vlSelfRef.__PVT__bucketValid_2 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                                      && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                          && ((1U & 
                                               (~ (IData)(vlSelfRef.__PVT___T_162))) 
                                              && (IData)(vlSelfRef.__PVT___GEN_250))));
    vlSelfRef.__PVT__bucketValid_6 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                                      && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                          && ((1U & 
                                               (~ (IData)(vlSelfRef.__PVT___T_454))) 
                                              && (IData)(vlSelfRef.__PVT___GEN_590))));
    vlSelfRef.__PVT__bucketValid_8 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                                      && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                          && ((1U & 
                                               (~ (IData)(vlSelfRef.__PVT___T_600))) 
                                              && (IData)(vlSelfRef.__PVT___GEN_760))));
    vlSelfRef.__PVT__bucketValid_1 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                                      && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                          && ((1U & 
                                               (~ (IData)(vlSelfRef.__PVT___T_89))) 
                                              && (IData)(vlSelfRef.__PVT___GEN_165))));
    vlSelfRef.__PVT__bucketValid_10 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                                       && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                           && ((1U 
                                                & (~ (IData)(vlSelfRef.__PVT___T_746))) 
                                               && (IData)(vlSelfRef.__PVT___GEN_930))));
    vlSelfRef.__PVT__bucketValid_12 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                                       && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                           && ((1U 
                                                & (~ (IData)(vlSelfRef.__PVT___T_892))) 
                                               && (IData)(vlSelfRef.__PVT___GEN_1100))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__193(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__193\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isRetiring_11 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                      == (0xffU & ((IData)(0xbU) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5109 = 
        (0x7fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5071)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_37)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5074)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_72)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5077)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_114)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5079)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_119)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5089)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_174)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5092)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_209)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5095)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_251)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5097)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_256)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5148 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5071)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_38)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5074)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_97)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5077)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_102)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5079)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_124)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5089)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_175)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5092)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_234)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5095)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_239)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5097)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_261)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5189 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5071)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_39)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5074)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_84)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5077)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_125)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5079)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_130)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5089)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_176)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5092)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_221)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5095)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_262)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5097)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_267)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5230 = 
        (0xfU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5071)
                     ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_40)
                     : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5074)
                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_90)
                               : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5077)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_131)
                                           : 0U) | 
                                         ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5079)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_136)
                                           : 0U))) 
                 + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5089)
                       ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_177)
                       : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5092)
                                 ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_227)
                                 : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5095)
                                             ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_268)
                                             : 0U) 
                                           | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5097)
                                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_273)
                                               : 0U)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5109 
        = (0x7fU & (((((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_5071)
                        ? (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_37)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_5074)
                                  ? (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_72)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_5077)
                                              ? (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_114)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_5079)
                                                ? (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_119)
                                                : 0U))) 
                    + ((((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_5089)
                          ? (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_174)
                          : 0U) | ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_5092)
                                    ? (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_209)
                                    : 0U)) | (((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_5095)
                                                ? (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_251)
                                                : 0U) 
                                              | ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_5097)
                                                  ? (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_256)
                                                  : 0U)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__198(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__198\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_11 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                     == (0xffU & ((IData)(0xbU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_15 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                      == (0xffU & ((IData)(0xfU) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6853 = 
        (0x7fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6815)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_37)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6818)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_72)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6821)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_114)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6823)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_119)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6833)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_174)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6836)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_209)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6839)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_251)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6841)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_256)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6892 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6815)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_38)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6818)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_97)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6821)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_102)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6823)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_124)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6833)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_175)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6836)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_234)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6839)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_239)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6841)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_261)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6933 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6815)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_39)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6818)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_84)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6821)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_125)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6823)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_130)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6833)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_176)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6836)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_221)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6839)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_262)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6841)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_267)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6974 = 
        (0xfU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6815)
                     ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_40)
                     : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6818)
                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_90)
                               : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6821)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_131)
                                           : 0U) | 
                                         ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6823)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_136)
                                           : 0U))) 
                 + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6833)
                       ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_177)
                       : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6836)
                                 ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_227)
                                 : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6839)
                                             ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_268)
                                             : 0U) 
                                           | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6841)
                                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_273)
                                               : 0U)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__203(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__203\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_15 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                     == (0xffU & ((IData)(0xfU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_4 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(4U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2057 = 
        (0x7fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2019)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_37)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2022)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_72)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2025)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_114)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2027)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_119)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2037)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_174)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2040)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_209)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2043)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_251)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2045)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_256)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2096 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2019)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_38)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2022)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_97)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2025)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_102)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2027)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_124)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2037)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_175)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2040)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_234)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2043)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_239)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2045)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_261)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2137 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2019)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_39)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2022)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_84)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2025)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_125)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2027)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_130)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2037)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_176)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2040)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_221)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2043)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_262)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2045)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_267)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2178 = 
        (0xfU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2019)
                     ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_40)
                     : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2022)
                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_90)
                               : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2025)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_131)
                                           : 0U) | 
                                         ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2027)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_136)
                                           : 0U))) 
                 + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2037)
                       ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_177)
                       : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2040)
                                 ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_227)
                                 : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2043)
                                             ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_268)
                                             : 0U) 
                                           | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2045)
                                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_273)
                                               : 0U)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__208(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__208\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_4 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(4U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_9 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(9U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4237 = 
        (0x7fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4199)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_37)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4202)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_72)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4205)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_114)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4207)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_119)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4217)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_174)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4220)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_209)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4223)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_251)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4225)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_256)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4276 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4199)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_38)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4202)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_97)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4205)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_102)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4207)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_124)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4217)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_175)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4220)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_234)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4223)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_239)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4225)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_261)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4317 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4199)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_39)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4202)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_84)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4205)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_125)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4207)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_130)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4217)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_176)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4220)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_221)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4223)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_262)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4225)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_267)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4358 = 
        (0xfU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4199)
                     ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_40)
                     : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4202)
                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_90)
                               : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4205)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_131)
                                           : 0U) | 
                                         ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4207)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_136)
                                           : 0U))) 
                 + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4217)
                       ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_177)
                       : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4220)
                                 ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_227)
                                 : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4223)
                                             ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_268)
                                             : 0U) 
                                           | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4225)
                                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_273)
                                               : 0U)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__213(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__213\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_9 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(9U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_7 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(7U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3365 = 
        (0x7fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3327)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_37)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3330)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_72)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3333)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_114)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3335)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_119)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3345)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_174)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3348)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_209)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3351)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_251)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3353)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_256)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3404 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3327)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_38)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3330)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_97)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3333)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_102)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3335)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_124)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3345)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_175)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3348)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_234)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3351)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_239)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3353)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_261)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3445 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3327)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_39)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3330)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_84)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3333)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_125)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3335)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_130)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3345)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_176)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3348)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_221)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3351)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_262)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3353)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_267)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3486 = 
        (0xfU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3327)
                     ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_40)
                     : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3330)
                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_90)
                               : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3333)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_131)
                                           : 0U) | 
                                         ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3335)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_136)
                                           : 0U))) 
                 + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3345)
                       ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_177)
                       : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3348)
                                 ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_227)
                                 : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3351)
                                             ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_268)
                                             : 0U) 
                                           | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3353)
                                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_273)
                                               : 0U)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__218(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__218\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_7 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(7U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_5 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(5U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2493 = 
        (0x7fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2455)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_37)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2458)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_72)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2461)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_114)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2463)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_119)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2473)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_174)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2476)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_209)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2479)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_251)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2481)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_256)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2532 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2455)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_38)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2458)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_97)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2461)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_102)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2463)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_124)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2473)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_175)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2476)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_234)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2479)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_239)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2481)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_261)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2573 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2455)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_39)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2458)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_84)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2461)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_125)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2463)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_130)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2473)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_176)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2476)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_221)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2479)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_262)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2481)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_267)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2614 = 
        (0xfU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2455)
                     ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_40)
                     : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2458)
                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_90)
                               : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2461)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_131)
                                           : 0U) | 
                                         ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2463)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_136)
                                           : 0U))) 
                 + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2473)
                       ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_177)
                       : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2476)
                                 ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_227)
                                 : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2479)
                                             ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_268)
                                             : 0U) 
                                           | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2481)
                                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_273)
                                               : 0U)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__223(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__223\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_5 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(5U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_3 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(3U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1621 = 
        (0x7fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1583)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_37)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1586)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_72)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1589)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_114)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1591)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_119)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1601)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_174)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1604)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_209)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1607)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_251)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1609)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_256)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1660 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1583)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_38)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1586)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_97)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1589)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_102)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1591)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_124)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1601)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_175)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1604)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_234)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1607)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_239)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1609)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_261)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1701 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1583)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_39)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1586)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_84)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1589)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_125)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1591)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_130)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1601)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_176)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1604)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_221)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1607)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_262)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1609)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_267)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1742 = 
        (0xfU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1583)
                     ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_40)
                     : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1586)
                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_90)
                               : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1589)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_131)
                                           : 0U) | 
                                         ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1591)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_136)
                                           : 0U))) 
                 + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1601)
                       ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_177)
                       : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1604)
                                 ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_227)
                                 : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1607)
                                             ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_268)
                                             : 0U) 
                                           | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1609)
                                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_273)
                                               : 0U)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__228(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__228\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_3 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(3U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                   == (IData)(vlSymsp->TOP.tb__DOT__io_base));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_313 = 
        (0x7fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_275)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_37)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_278)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_72)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_281)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_114)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_283)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_119)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_293)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_174)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_296)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_209)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_299)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_251)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_301)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_256)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_352 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_275)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_38)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_278)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_97)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_281)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_102)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_283)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_124)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_293)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_175)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_296)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_234)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_299)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_239)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_301)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_261)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_393 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_275)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_39)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_278)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_84)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_281)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_125)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_283)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_130)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_293)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_176)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_296)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_221)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_299)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_262)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_301)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_267)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_434 = 
        (0xfU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_275)
                     ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_40)
                     : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_278)
                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_90)
                               : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_281)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_131)
                                           : 0U) | 
                                         ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_283)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_136)
                                           : 0U))) 
                 + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_293)
                       ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_177)
                       : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_296)
                                 ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_227)
                                 : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_299)
                                             ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_268)
                                             : 0U) 
                                           | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_301)
                                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_273)
                                               : 0U)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__233(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__233\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                  == (IData)(vlSymsp->TOP.tb__DOT__io_base));
    vlSelfRef.__PVT__isRetiring_14 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                      == (0xffU & ((IData)(0xeU) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6417 = 
        (0x7fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6379)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_37)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6382)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_72)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6385)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_114)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6387)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_119)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6397)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_174)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6400)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_209)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6403)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_251)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6405)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_256)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6456 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6379)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_38)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6382)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_97)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6385)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_102)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6387)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_124)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6397)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_175)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6400)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_234)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6403)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_239)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6405)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_261)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6497 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6379)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_39)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6382)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_84)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6385)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_125)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6387)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_130)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6397)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_176)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6400)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_221)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6403)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_262)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6405)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_267)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6538 = 
        (0xfU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6379)
                     ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_40)
                     : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6382)
                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_90)
                               : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6385)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_131)
                                           : 0U) | 
                                         ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6387)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_136)
                                           : 0U))) 
                 + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6397)
                       ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_177)
                       : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6400)
                                 ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_227)
                                 : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6403)
                                             ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_268)
                                             : 0U) 
                                           | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_6405)
                                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_273)
                                               : 0U)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__238(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__238\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_14 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                     == (0xffU & ((IData)(0xeU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_13 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                      == (0xffU & ((IData)(0xdU) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5981 = 
        (0x7fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5943)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_37)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5946)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_72)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5949)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_114)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5951)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_119)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5961)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_174)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5964)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_209)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5967)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_251)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5969)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_256)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6020 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5943)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_38)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5946)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_97)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5949)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_102)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5951)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_124)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5961)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_175)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5964)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_234)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5967)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_239)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5969)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_261)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6061 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5943)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_39)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5946)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_84)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5949)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_125)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5951)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_130)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5961)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_176)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5964)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_221)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5967)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_262)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5969)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_267)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6102 = 
        (0xfU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5943)
                     ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_40)
                     : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5946)
                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_90)
                               : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5949)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_131)
                                           : 0U) | 
                                         ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5951)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_136)
                                           : 0U))) 
                 + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5961)
                       ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_177)
                       : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5964)
                                 ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_227)
                                 : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5967)
                                             ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_268)
                                             : 0U) 
                                           | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5969)
                                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_273)
                                               : 0U)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__243(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__243\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_13 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                     == (0xffU & ((IData)(0xdU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_2 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(2U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1185 = 
        (0x7fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1147)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_37)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1150)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_72)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1153)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_114)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1155)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_119)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1165)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_174)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1168)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_209)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1171)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_251)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1173)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_256)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1224 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1147)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_38)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1150)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_97)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1153)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_102)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1155)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_124)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1165)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_175)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1168)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_234)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1171)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_239)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1173)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_261)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1265 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1147)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_39)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1150)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_84)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1153)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_125)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1155)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_130)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1165)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_176)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1168)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_221)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1171)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_262)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1173)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_267)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1306 = 
        (0xfU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1147)
                     ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_40)
                     : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1150)
                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_90)
                               : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1153)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_131)
                                           : 0U) | 
                                         ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1155)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_136)
                                           : 0U))) 
                 + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1165)
                       ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_177)
                       : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1168)
                                 ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_227)
                                 : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1171)
                                             ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_268)
                                             : 0U) 
                                           | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1173)
                                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_273)
                                               : 0U)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__248(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__248\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_2 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(2U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_6 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(6U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2929 = 
        (0x7fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2891)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_37)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2894)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_72)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2897)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_114)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2899)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_119)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2909)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_174)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2912)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_209)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2915)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_251)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2917)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_256)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2968 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2891)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_38)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2894)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_97)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2897)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_102)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2899)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_124)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2909)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_175)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2912)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_234)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2915)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_239)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2917)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_261)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3009 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2891)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_39)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2894)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_84)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2897)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_125)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2899)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_130)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2909)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_176)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2912)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_221)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2915)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_262)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2917)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_267)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3050 = 
        (0xfU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2891)
                     ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_40)
                     : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2894)
                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_90)
                               : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2897)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_131)
                                           : 0U) | 
                                         ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2899)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_136)
                                           : 0U))) 
                 + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2909)
                       ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_177)
                       : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2912)
                                 ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_227)
                                 : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2915)
                                             ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_268)
                                             : 0U) 
                                           | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2917)
                                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_273)
                                               : 0U)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__253(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__253\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_6 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(6U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_8 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(8U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3801 = 
        (0x7fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3763)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_37)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3766)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_72)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3769)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_114)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3771)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_119)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3781)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_174)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3784)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_209)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3787)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_251)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3789)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_256)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3840 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3763)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_38)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3766)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_97)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3769)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_102)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3771)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_124)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3781)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_175)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3784)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_234)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3787)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_239)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3789)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_261)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3881 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3763)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_39)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3766)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_84)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3769)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_125)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3771)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_130)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3781)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_176)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3784)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_221)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3787)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_262)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3789)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_267)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3922 = 
        (0xfU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3763)
                     ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_40)
                     : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3766)
                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_90)
                               : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3769)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_131)
                                           : 0U) | 
                                         ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3771)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_136)
                                           : 0U))) 
                 + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3781)
                       ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_177)
                       : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3784)
                                 ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_227)
                                 : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3787)
                                             ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_268)
                                             : 0U) 
                                           | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3789)
                                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_273)
                                               : 0U)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__258(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__258\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_8 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(8U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_1 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(1U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_749 = 
        (0x7fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_711)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_37)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_714)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_72)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_717)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_114)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_719)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_119)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_729)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_174)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_732)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_209)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_735)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_251)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_737)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_256)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_788 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_711)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_38)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_714)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_97)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_717)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_102)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_719)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_124)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_729)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_175)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_732)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_234)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_735)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_239)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_737)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_261)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_829 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_711)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_39)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_714)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_84)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_717)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_125)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_719)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_130)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_729)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_176)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_732)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_221)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_735)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_262)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_737)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_267)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_870 = 
        (0xfU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_711)
                     ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_40)
                     : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_714)
                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_90)
                               : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_717)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_131)
                                           : 0U) | 
                                         ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_719)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_136)
                                           : 0U))) 
                 + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_729)
                       ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_177)
                       : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_732)
                                 ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_227)
                                 : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_735)
                                             ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_268)
                                             : 0U) 
                                           | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_737)
                                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_273)
                                               : 0U)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__263(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__263\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_1 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(1U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_10 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                      == (0xffU & ((IData)(0xaU) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4673 = 
        (0x7fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4635)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_37)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4638)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_72)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4641)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_114)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4643)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_119)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4653)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_174)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4656)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_209)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4659)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_251)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4661)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_256)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4712 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4635)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_38)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4638)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_97)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4641)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_102)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4643)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_124)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4653)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_175)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4656)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_234)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4659)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_239)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4661)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_261)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4753 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4635)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_39)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4638)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_84)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4641)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_125)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4643)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_130)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4653)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_176)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4656)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_221)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4659)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_262)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4661)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_267)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4794 = 
        (0xfU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4635)
                     ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_40)
                     : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4638)
                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_90)
                               : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4641)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_131)
                                           : 0U) | 
                                         ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4643)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_136)
                                           : 0U))) 
                 + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4653)
                       ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_177)
                       : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4656)
                                 ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_227)
                                 : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4659)
                                             ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_268)
                                             : 0U) 
                                           | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_4661)
                                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_273)
                                               : 0U)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__268(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__268\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_10 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                     == (0xffU & ((IData)(0xaU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_12 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                      == (0xffU & ((IData)(0xcU) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5545 = 
        (0x7fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5507)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_37)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5510)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_72)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5513)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_114)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5515)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_119)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5525)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_174)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5528)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_209)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5531)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_251)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5533)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_256)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5584 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5507)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_38)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5510)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_97)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5513)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_102)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5515)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_124)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5525)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_175)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5528)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_234)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5531)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_239)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5533)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_261)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5625 = 
        (0x1fU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5507)
                      ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_39)
                      : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5510)
                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_84)
                                : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5513)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_125)
                                            : 0U) | 
                                          ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5515)
                                            ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_130)
                                            : 0U))) 
                  + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5525)
                        ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_176)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5528)
                                  ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_221)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5531)
                                              ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_262)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5533)
                                                ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_267)
                                                : 0U)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5666 = 
        (0xfU & (((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5507)
                     ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_40)
                     : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5510)
                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_90)
                               : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5513)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_131)
                                           : 0U) | 
                                         ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5515)
                                           ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_136)
                                           : 0U))) 
                 + ((((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5525)
                       ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_177)
                       : 0U) | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5528)
                                 ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_227)
                                 : 0U)) | (((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5531)
                                             ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_268)
                                             : 0U) 
                                           | ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_5533)
                                               ? (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_273)
                                               : 0U)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__273(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__273\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_12 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                     == (0xffU & ((IData)(0xcU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_comb__TOP__tb__DOT__dut__DOT__reference_0__0(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_comb__TOP__tb__DOT__dut__DOT__reference_0__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    // Body
    vlSelfRef.__PVT___buckets_count_0_T_1 = (1ULL + vlSelfRef.buckets_count_0);
    vlSelfRef.__PVT___buckets_requestCycleSum_15_T_1 
        = (vlSelfRef.buckets_requestCycleSum_15 + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_14_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_14 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_13_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_13 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_12_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_12 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_11_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_11 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_10_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_10 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_9_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_9 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_8_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_8 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_7_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_7 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_6_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_6 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_5_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_5 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_4_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_4 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_3_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_3 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_2_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_2 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_1_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_1 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_0_T_1 
        = (vlSelfRef.buckets_requestCycleSum_0 + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT__resolving_15 = ((IData)(vlSelfRef.buckets_valid_15) 
                                     & (vlSelfRef.buckets_seq_15 
                                        <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_10 = ((IData)(vlSelfRef.__PVT__buckets_valid_10) 
                                     & (vlSelfRef.__PVT__buckets_seq_10 
                                        <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_14 = ((IData)(vlSelfRef.__PVT__buckets_valid_14) 
                                     & (vlSelfRef.__PVT__buckets_seq_14 
                                        <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_2 = ((IData)(vlSelfRef.__PVT__buckets_valid_2) 
                                    & (vlSelfRef.__PVT__buckets_seq_2 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_6 = ((IData)(vlSelfRef.__PVT__buckets_valid_6) 
                                    & (vlSelfRef.__PVT__buckets_seq_6 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_0 = ((IData)(vlSelfRef.buckets_valid_0) 
                                    & (vlSelfRef.buckets_seq_0 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_5 = ((IData)(vlSelfRef.__PVT__buckets_valid_5) 
                                    & (vlSelfRef.__PVT__buckets_seq_5 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_7 = ((IData)(vlSelfRef.__PVT__buckets_valid_7) 
                                    & (vlSelfRef.__PVT__buckets_seq_7 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_11 = ((IData)(vlSelfRef.__PVT__buckets_valid_11) 
                                     & (vlSelfRef.__PVT__buckets_seq_11 
                                        <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_8 = ((IData)(vlSelfRef.__PVT__buckets_valid_8) 
                                    & (vlSelfRef.__PVT__buckets_seq_8 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_1 = ((IData)(vlSelfRef.__PVT__buckets_valid_1) 
                                    & (vlSelfRef.__PVT__buckets_seq_1 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_3 = ((IData)(vlSelfRef.__PVT__buckets_valid_3) 
                                    & (vlSelfRef.__PVT__buckets_seq_3 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_4 = ((IData)(vlSelfRef.__PVT__buckets_valid_4) 
                                    & (vlSelfRef.__PVT__buckets_seq_4 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_9 = ((IData)(vlSelfRef.__PVT__buckets_valid_9) 
                                    & (vlSelfRef.__PVT__buckets_seq_9 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_12 = ((IData)(vlSelfRef.__PVT__buckets_valid_12) 
                                     & (vlSelfRef.__PVT__buckets_seq_12 
                                        <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_13 = ((IData)(vlSelfRef.__PVT__buckets_valid_13) 
                                     & (vlSelfRef.__PVT__buckets_seq_13 
                                        <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_11)
                              ? vlSelfRef.__PVT__bucketStore_11_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_11)
                               ? vlSelfRef.__PVT__bucketStore_11_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__currentStoreNextWide_44[0U] = 
        __Vtemp_4[0U];
    vlSelfRef.__PVT__currentStoreNextWide_44[1U] = 
        __Vtemp_4[1U];
    vlSelfRef.__PVT__currentStoreNextWide_44[2U] = 
        (1U & __Vtemp_4[2U]);
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_comb__TOP__tb__DOT__dut__DOT__reference_0__1(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_comb__TOP__tb__DOT__dut__DOT__reference_0__1\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_11)
                              ? vlSelfRef.__PVT__bucketStore_11_1
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_11)
                               ? vlSelfRef.__PVT__bucketStore_11_1
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__currentStoreNextWide_45[0U] = 
        __Vtemp_4[0U];
    vlSelfRef.__PVT__currentStoreNextWide_45[1U] = 
        __Vtemp_4[1U];
    vlSelfRef.__PVT__currentStoreNextWide_45[2U] = 
        (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_11)
                              ? vlSelfRef.__PVT__bucketStore_11_2
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_11)
                               ? vlSelfRef.__PVT__bucketStore_11_2
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__currentStoreNextWide_46[0U] = 
        __Vtemp_8[0U];
    vlSelfRef.__PVT__currentStoreNextWide_46[1U] = 
        __Vtemp_8[1U];
    vlSelfRef.__PVT__currentStoreNextWide_46[2U] = 
        (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_11)
                               ? vlSelfRef.__PVT__bucketStore_11_3
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_11)
                                ? vlSelfRef.__PVT__bucketStore_11_3
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__currentStoreNextWide_47[0U] = 
        __Vtemp_12[0U];
    vlSelfRef.__PVT__currentStoreNextWide_47[1U] = 
        __Vtemp_12[1U];
    vlSelfRef.__PVT__currentStoreNextWide_47[2U] = 
        (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_11)
                               ? vlSelfRef.__PVT__bucketFirstStore_11_0
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_11)
                                ? vlSelfRef.__PVT__bucketFirstStore_11_0
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__currentFirstStoreNextWide_44[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_44[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_44[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_11)
                               ? vlSelfRef.__PVT__bucketFirstStore_11_1
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_11)
                                ? vlSelfRef.__PVT__bucketFirstStore_11_1
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__currentFirstStoreNextWide_45[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_45[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_45[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_11)
                               ? vlSelfRef.__PVT__bucketFirstStore_11_2
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_11)
                                ? vlSelfRef.__PVT__bucketFirstStore_11_2
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__currentFirstStoreNextWide_46[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_46[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_46[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_11)
                               ? vlSelfRef.__PVT__bucketFirstStore_11_3
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_11)
                                ? vlSelfRef.__PVT__bucketFirstStore_11_3
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__currentFirstStoreNextWide_47[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_47[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_47[2U] 
        = (1U & __Vtemp_28[2U]);
    vlSelfRef.__PVT___io_retiringValid_T_11 = ((IData)(vlSelfRef.__PVT__retireSelect_11) 
                                               & (IData)(vlSelfRef.__PVT__bucketValid_11));
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.bucketValid_15)
                               ? vlSelfRef.bucketStore_15_0
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.bucketValid_15)
                                ? vlSelfRef.bucketStore_15_0
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__currentStoreNextWide_60[0U] = 
        __Vtemp_32[0U];
    vlSelfRef.__PVT__currentStoreNextWide_60[1U] = 
        __Vtemp_32[1U];
    vlSelfRef.__PVT__currentStoreNextWide_60[2U] = 
        (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.bucketValid_15)
                               ? vlSelfRef.bucketStore_15_1
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.bucketValid_15)
                                ? vlSelfRef.bucketStore_15_1
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__currentStoreNextWide_61[0U] = 
        __Vtemp_36[0U];
    vlSelfRef.__PVT__currentStoreNextWide_61[1U] = 
        __Vtemp_36[1U];
    vlSelfRef.__PVT__currentStoreNextWide_61[2U] = 
        (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.bucketValid_15)
                               ? vlSelfRef.bucketStore_15_2
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.bucketValid_15)
                                ? vlSelfRef.bucketStore_15_2
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__currentStoreNextWide_62[0U] = 
        __Vtemp_40[0U];
    vlSelfRef.__PVT__currentStoreNextWide_62[1U] = 
        __Vtemp_40[1U];
    vlSelfRef.__PVT__currentStoreNextWide_62[2U] = 
        (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.bucketValid_15)
                               ? vlSelfRef.bucketStore_15_3
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.bucketValid_15)
                                ? vlSelfRef.bucketStore_15_3
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__currentStoreNextWide_63[0U] = 
        __Vtemp_44[0U];
    vlSelfRef.__PVT__currentStoreNextWide_63[1U] = 
        __Vtemp_44[1U];
    vlSelfRef.__PVT__currentStoreNextWide_63[2U] = 
        (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.bucketValid_15)
                               ? vlSelfRef.bucketFirstStore_15_0
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.bucketValid_15)
                                ? vlSelfRef.bucketFirstStore_15_0
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__currentFirstStoreNextWide_60[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_60[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_60[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.bucketValid_15)
                               ? vlSelfRef.bucketFirstStore_15_1
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.bucketValid_15)
                                ? vlSelfRef.bucketFirstStore_15_1
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__currentFirstStoreNextWide_61[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_61[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_61[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.bucketValid_15)
                               ? vlSelfRef.bucketFirstStore_15_2
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.bucketValid_15)
                                ? vlSelfRef.bucketFirstStore_15_2
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__currentFirstStoreNextWide_62[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_62[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_62[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.bucketValid_15)
                               ? vlSelfRef.bucketFirstStore_15_3
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.bucketValid_15)
                                ? vlSelfRef.bucketFirstStore_15_3
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__currentFirstStoreNextWide_63[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_63[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_63[2U] 
        = (1U & __Vtemp_60[2U]);
    vlSelfRef.__PVT___io_retiringValid_T_15 = ((IData)(vlSelfRef.__PVT__retireSelect_15) 
                                               & (IData)(vlSelfRef.bucketValid_15));
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketStore_4_0
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                                ? vlSelfRef.__PVT__bucketStore_4_0
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__currentStoreNextWide_16[0U] = 
        __Vtemp_64[0U];
    vlSelfRef.__PVT__currentStoreNextWide_16[1U] = 
        __Vtemp_64[1U];
    vlSelfRef.__PVT__currentStoreNextWide_16[2U] = 
        (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketStore_4_1
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                                ? vlSelfRef.__PVT__bucketStore_4_1
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__currentStoreNextWide_17[0U] = 
        __Vtemp_68[0U];
    vlSelfRef.__PVT__currentStoreNextWide_17[1U] = 
        __Vtemp_68[1U];
    vlSelfRef.__PVT__currentStoreNextWide_17[2U] = 
        (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketStore_4_2
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                                ? vlSelfRef.__PVT__bucketStore_4_2
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__currentStoreNextWide_18[0U] = 
        __Vtemp_72[0U];
    vlSelfRef.__PVT__currentStoreNextWide_18[1U] = 
        __Vtemp_72[1U];
    vlSelfRef.__PVT__currentStoreNextWide_18[2U] = 
        (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketStore_4_3
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                                ? vlSelfRef.__PVT__bucketStore_4_3
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__currentStoreNextWide_19[0U] = 
        __Vtemp_76[0U];
    vlSelfRef.__PVT__currentStoreNextWide_19[1U] = 
        __Vtemp_76[1U];
    vlSelfRef.__PVT__currentStoreNextWide_19[2U] = 
        (1U & __Vtemp_76[2U]);
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_comb__TOP__tb__DOT__dut__DOT__reference_0__2(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_comb__TOP__tb__DOT__dut__DOT__reference_0__2\n"); );
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
    vlSelfRef.__PVT___io_retiringValid_T_4 = ((IData)(vlSelfRef.__PVT__retireSelect_4) 
                                              & (IData)(vlSelfRef.__PVT__bucketValid_4));
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_9)
                               ? vlSelfRef.__PVT__bucketStore_9_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_9)
                                ? vlSelfRef.__PVT__bucketStore_9_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__currentStoreNextWide_36[0U] = 
        __Vtemp_20[0U];
    vlSelfRef.__PVT__currentStoreNextWide_36[1U] = 
        __Vtemp_20[1U];
    vlSelfRef.__PVT__currentStoreNextWide_36[2U] = 
        (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_9)
                               ? vlSelfRef.__PVT__bucketStore_9_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_9)
                                ? vlSelfRef.__PVT__bucketStore_9_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__currentStoreNextWide_37[0U] = 
        __Vtemp_24[0U];
    vlSelfRef.__PVT__currentStoreNextWide_37[1U] = 
        __Vtemp_24[1U];
    vlSelfRef.__PVT__currentStoreNextWide_37[2U] = 
        (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_9)
                               ? vlSelfRef.__PVT__bucketStore_9_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_9)
                                ? vlSelfRef.__PVT__bucketStore_9_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__currentStoreNextWide_38[0U] = 
        __Vtemp_28[0U];
    vlSelfRef.__PVT__currentStoreNextWide_38[1U] = 
        __Vtemp_28[1U];
    vlSelfRef.__PVT__currentStoreNextWide_38[2U] = 
        (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_9)
                               ? vlSelfRef.__PVT__bucketStore_9_3
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_9)
                                ? vlSelfRef.__PVT__bucketStore_9_3
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__currentStoreNextWide_39[0U] = 
        __Vtemp_32[0U];
    vlSelfRef.__PVT__currentStoreNextWide_39[1U] = 
        __Vtemp_32[1U];
    vlSelfRef.__PVT__currentStoreNextWide_39[2U] = 
        (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_9)
                               ? vlSelfRef.__PVT__bucketFirstStore_9_0
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_9)
                                ? vlSelfRef.__PVT__bucketFirstStore_9_0
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__currentFirstStoreNextWide_36[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_36[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_36[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_9)
                               ? vlSelfRef.__PVT__bucketFirstStore_9_1
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_9)
                                ? vlSelfRef.__PVT__bucketFirstStore_9_1
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__currentFirstStoreNextWide_37[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_37[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_37[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_9)
                               ? vlSelfRef.__PVT__bucketFirstStore_9_2
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_9)
                                ? vlSelfRef.__PVT__bucketFirstStore_9_2
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__currentFirstStoreNextWide_38[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_38[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_38[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_9)
                               ? vlSelfRef.__PVT__bucketFirstStore_9_3
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_9)
                                ? vlSelfRef.__PVT__bucketFirstStore_9_3
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__currentFirstStoreNextWide_39[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_39[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_39[2U] 
        = (1U & __Vtemp_48[2U]);
    vlSelfRef.__PVT___io_retiringValid_T_9 = ((IData)(vlSelfRef.__PVT__retireSelect_9) 
                                              & (IData)(vlSelfRef.__PVT__bucketValid_9));
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_7)
                               ? vlSelfRef.__PVT__bucketStore_7_0
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_7)
                                ? vlSelfRef.__PVT__bucketStore_7_0
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__currentStoreNextWide_28[0U] = 
        __Vtemp_52[0U];
    vlSelfRef.__PVT__currentStoreNextWide_28[1U] = 
        __Vtemp_52[1U];
    vlSelfRef.__PVT__currentStoreNextWide_28[2U] = 
        (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_7)
                               ? vlSelfRef.__PVT__bucketStore_7_1
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_7)
                                ? vlSelfRef.__PVT__bucketStore_7_1
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__currentStoreNextWide_29[0U] = 
        __Vtemp_56[0U];
    vlSelfRef.__PVT__currentStoreNextWide_29[1U] = 
        __Vtemp_56[1U];
    vlSelfRef.__PVT__currentStoreNextWide_29[2U] = 
        (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_7)
                               ? vlSelfRef.__PVT__bucketStore_7_2
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_7)
                                ? vlSelfRef.__PVT__bucketStore_7_2
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__currentStoreNextWide_30[0U] = 
        __Vtemp_60[0U];
    vlSelfRef.__PVT__currentStoreNextWide_30[1U] = 
        __Vtemp_60[1U];
    vlSelfRef.__PVT__currentStoreNextWide_30[2U] = 
        (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_7)
                               ? vlSelfRef.__PVT__bucketStore_7_3
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_7)
                                ? vlSelfRef.__PVT__bucketStore_7_3
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__currentStoreNextWide_31[0U] = 
        __Vtemp_64[0U];
    vlSelfRef.__PVT__currentStoreNextWide_31[1U] = 
        __Vtemp_64[1U];
    vlSelfRef.__PVT__currentStoreNextWide_31[2U] = 
        (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_7)
                               ? vlSelfRef.__PVT__bucketFirstStore_7_0
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_7)
                                ? vlSelfRef.__PVT__bucketFirstStore_7_0
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__currentFirstStoreNextWide_28[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_28[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_28[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_7)
                               ? vlSelfRef.__PVT__bucketFirstStore_7_1
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_7)
                                ? vlSelfRef.__PVT__bucketFirstStore_7_1
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__currentFirstStoreNextWide_29[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_29[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_29[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_7)
                               ? vlSelfRef.__PVT__bucketFirstStore_7_2
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_7)
                                ? vlSelfRef.__PVT__bucketFirstStore_7_2
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__currentFirstStoreNextWide_30[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_30[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_30[2U] 
        = (1U & __Vtemp_76[2U]);
}
