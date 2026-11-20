// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb___024root.h"

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__67(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__67\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__reset) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_112 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_86 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_200 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_202 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_96 = 0ULL;
    } else if (vlSelfRef.tb__DOT__io_resetStats) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_112 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_86 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_200 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_202 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_96 = 0ULL;
    } else if (vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) {
        if (vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_112 
                = ((0x70U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1617);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_86 
                = ((0x56U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1539);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_200 
                = ((0xc8U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1881);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_202 
                = ((0xcaU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1887);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_96 
                = ((0x60U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1569);
        } else {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_112 
                = ((0x70U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1617);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_86 
                = ((0x56U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1539);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_200 
                = ((0xc8U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1881);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_202 
                = ((0xcaU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1887);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_96 
                = ((0x60U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1569);
        }
    } else {
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_112) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_112 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_86) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_86 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_200) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_200 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_202) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_202 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_96) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_96 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__68(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__68\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__reset) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_210 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_0 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_212 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_2 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_106 = 0ULL;
    } else if (vlSelfRef.tb__DOT__io_resetStats) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_210 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_0 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_212 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_2 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_106 = 0ULL;
    } else if (vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) {
        if (vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_210 
                = ((0xd2U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1911);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_0 
                = ((0U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1281);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_212 
                = ((0xd4U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1917);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_2 
                = ((2U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1287);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_106 
                = ((0x6aU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1599);
        } else {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_210 
                = ((0xd2U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1911);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_0 
                = ((0U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1281);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_212 
                = ((0xd4U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1917);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_2 
                = ((2U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1287);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_106 
                = ((0x6aU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1599);
        }
    } else {
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_210) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_210 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_0) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_0 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_212) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_212 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_2) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_2 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_106) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_106 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__69(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__69\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__reset) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_220 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_10 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_222 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_12 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_116 = 0ULL;
    } else if (vlSelfRef.tb__DOT__io_resetStats) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_220 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_10 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_222 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_12 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_116 = 0ULL;
    } else if (vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) {
        if (vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_220 
                = ((0xdcU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1941);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_10 
                = ((0xaU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1311);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_222 
                = ((0xdeU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1947);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_12 
                = ((0xcU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1317);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_116 
                = ((0x74U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1629);
        } else {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_220 
                = ((0xdcU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1941);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_10 
                = ((0xaU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1311);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_222 
                = ((0xdeU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1947);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_12 
                = ((0xcU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1317);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_116 
                = ((0x74U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1629);
        }
    } else {
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_220) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_220 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_10) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_10 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_222) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_222 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_12) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_12 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_116) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_116 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__70(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__70\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__reset) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_230 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_20 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_232 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_22 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_119 = 0ULL;
    } else if (vlSelfRef.tb__DOT__io_resetStats) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_230 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_20 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_232 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_22 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_119 = 0ULL;
    } else if (vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) {
        if (vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_230 
                = ((0xe6U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1971);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_20 
                = ((0x14U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1341);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_232 
                = ((0xe8U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1977);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_22 
                = ((0x16U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1347);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_119 
                = ((0x77U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1638);
        } else {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_230 
                = ((0xe6U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1971);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_20 
                = ((0x14U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1341);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_232 
                = ((0xe8U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1977);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_22 
                = ((0x16U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1347);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_119 
                = ((0x77U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1638);
        }
    } else {
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_230) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_230 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_20) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_20 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_232) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_232 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_22) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_22 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_119) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_119 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__71(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__71\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__reset) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_120 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_122 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_124 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_129 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_130 = 0ULL;
    } else if (vlSelfRef.tb__DOT__io_resetStats) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_120 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_122 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_124 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_129 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_130 = 0ULL;
    } else if (vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) {
        if (vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_120 
                = ((0x78U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1641);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_122 
                = ((0x7aU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1647);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_124 
                = ((0x7cU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1653);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_129 
                = ((0x81U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1668);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_130 
                = ((0x82U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1671);
        } else {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_120 
                = ((0x78U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1641);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_122 
                = ((0x7aU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1647);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_124 
                = ((0x7cU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1653);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_129 
                = ((0x81U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1668);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_130 
                = ((0x82U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1671);
        }
    } else {
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_120) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_120 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_122) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_122 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_124) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_124 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_129) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_129 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_130) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_130 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__72(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__72\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__reset) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_132 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_134 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_139 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_140 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_142 = 0ULL;
    } else if (vlSelfRef.tb__DOT__io_resetStats) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_132 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_134 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_139 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_140 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_142 = 0ULL;
    } else if (vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) {
        if (vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_132 
                = ((0x84U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1677);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_134 
                = ((0x86U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1683);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_139 
                = ((0x8bU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1698);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_140 
                = ((0x8cU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1701);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_142 
                = ((0x8eU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1707);
        } else {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_132 
                = ((0x84U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1677);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_134 
                = ((0x86U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1683);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_139 
                = ((0x8bU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1698);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_140 
                = ((0x8cU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1701);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_142 
                = ((0x8eU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1707);
        }
    } else {
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_132) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_132 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_134) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_134 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_139) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_139 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_140) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_140 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_142) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_142 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__73(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__73\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__reset) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_144 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_149 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_150 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_152 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_154 = 0ULL;
    } else if (vlSelfRef.tb__DOT__io_resetStats) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_144 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_149 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_150 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_152 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_154 = 0ULL;
    } else if (vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) {
        if (vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_144 
                = ((0x90U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1713);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_149 
                = ((0x95U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1728);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_150 
                = ((0x96U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1731);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_152 
                = ((0x98U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1737);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_154 
                = ((0x9aU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1743);
        } else {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_144 
                = ((0x90U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1713);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_149 
                = ((0x95U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1728);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_150 
                = ((0x96U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1731);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_152 
                = ((0x98U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1737);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_154 
                = ((0x9aU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1743);
        }
    } else {
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_144) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_144 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_149) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_149 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_150) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_150 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_152) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_152 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_154) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_154 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__74(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__74\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__reset) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_159 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_160 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_162 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_3 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_5 = 0ULL;
    } else if (vlSelfRef.tb__DOT__io_resetStats) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_159 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_160 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_162 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_3 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_5 = 0ULL;
    } else if (vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) {
        if (vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_159 
                = ((0x9fU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1758);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_160 
                = ((0xa0U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1761);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_162 
                = ((0xa2U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1767);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_3 
                = ((3U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1290);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_5 
                = ((5U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1296);
        } else {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_159 
                = ((0x9fU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1758);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_160 
                = ((0xa0U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1761);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_162 
                = ((0xa2U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1767);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_3 
                = ((3U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1290);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_5 
                = ((5U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1296);
        }
    } else {
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_159) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_159 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_160) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_160 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_162) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_162 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_3) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_3 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_5) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_5 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__75(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__75\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__reset) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_6 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_8 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_13 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_15 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_16 = 0ULL;
    } else if (vlSelfRef.tb__DOT__io_resetStats) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_6 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_8 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_13 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_15 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_16 = 0ULL;
    } else if (vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) {
        if (vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_6 
                = ((6U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1299);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_8 
                = ((8U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1305);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_13 
                = ((0xdU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1320);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_15 
                = ((0xfU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1326);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_16 
                = ((0x10U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1329);
        } else {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_6 
                = ((6U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1299);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_8 
                = ((8U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1305);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_13 
                = ((0xdU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1320);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_15 
                = ((0xfU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1326);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_16 
                = ((0x10U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1329);
        }
    } else {
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_6) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_6 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_8) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_8 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_13) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_13 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_15) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_15 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_16) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_16 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__76(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__76\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__reset) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_17 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_18 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_23 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_25 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_26 = 0ULL;
    } else if (vlSelfRef.tb__DOT__io_resetStats) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_17 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_18 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_23 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_25 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_26 = 0ULL;
    } else if (vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) {
        if (vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_17 
                = ((0x11U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1332);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_18 
                = ((0x12U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1335);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_23 
                = ((0x17U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1350);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_25 
                = ((0x19U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1356);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_26 
                = ((0x1aU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1359);
        } else {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_17 
                = ((0x11U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1332);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_18 
                = ((0x12U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1335);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_23 
                = ((0x17U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1350);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_25 
                = ((0x19U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1356);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_26 
                = ((0x1aU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1359);
        }
    } else {
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_17) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_17 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_18) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_18 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_23) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_23 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_25) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_25 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_26) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_26 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__77(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__77\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__reset) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_27 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_28 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_33 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_35 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_36 = 0ULL;
    } else if (vlSelfRef.tb__DOT__io_resetStats) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_27 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_28 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_33 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_35 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_36 = 0ULL;
    } else if (vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) {
        if (vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_27 
                = ((0x1bU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1362);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_28 
                = ((0x1cU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1365);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_33 
                = ((0x21U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1380);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_35 
                = ((0x23U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1386);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_36 
                = ((0x24U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1389);
        } else {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_27 
                = ((0x1bU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1362);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_28 
                = ((0x1cU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1365);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_33 
                = ((0x21U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1380);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_35 
                = ((0x23U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1386);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_36 
                = ((0x24U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1389);
        }
    } else {
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_27) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_27 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_28) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_28 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_33) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_33 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_35) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_35 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_36) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_36 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__78(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__78\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__reset) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_37 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_38 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_43 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_45 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_46 = 0ULL;
    } else if (vlSelfRef.tb__DOT__io_resetStats) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_37 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_38 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_43 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_45 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_46 = 0ULL;
    } else if (vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) {
        if (vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_37 
                = ((0x25U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1392);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_38 
                = ((0x26U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1395);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_43 
                = ((0x2bU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1410);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_45 
                = ((0x2dU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1416);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_46 
                = ((0x2eU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1419);
        } else {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_37 
                = ((0x25U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1392);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_38 
                = ((0x26U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1395);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_43 
                = ((0x2bU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1410);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_45 
                = ((0x2dU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1416);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_46 
                = ((0x2eU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1419);
        }
    } else {
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_37) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_37 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_38) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_38 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_43) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_43 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_45) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_45 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_46) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_46 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__79(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__79\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__reset) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_47 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_48 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_53 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_55 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_56 = 0ULL;
    } else if (vlSelfRef.tb__DOT__io_resetStats) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_47 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_48 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_53 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_55 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_56 = 0ULL;
    } else if (vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) {
        if (vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_47 
                = ((0x2fU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1422);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_48 
                = ((0x30U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1425);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_53 
                = ((0x35U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1440);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_55 
                = ((0x37U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1446);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_56 
                = ((0x38U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1449);
        } else {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_47 
                = ((0x2fU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1422);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_48 
                = ((0x30U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1425);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_53 
                = ((0x35U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1440);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_55 
                = ((0x37U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1446);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_56 
                = ((0x38U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1449);
        }
    } else {
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_47) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_47 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_48) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_48 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_53) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_53 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_55) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_55 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_56) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_56 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__80(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__80\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__reset) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_57 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_58 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_63 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_65 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_66 = 0ULL;
    } else if (vlSelfRef.tb__DOT__io_resetStats) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_57 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_58 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_63 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_65 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_66 = 0ULL;
    } else if (vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) {
        if (vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_57 
                = ((0x39U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1452);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_58 
                = ((0x3aU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1455);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_63 
                = ((0x3fU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1470);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_65 
                = ((0x41U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1476);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_66 
                = ((0x42U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1479);
        } else {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_57 
                = ((0x39U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1452);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_58 
                = ((0x3aU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1455);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_63 
                = ((0x3fU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1470);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_65 
                = ((0x41U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1476);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_66 
                = ((0x42U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1479);
        }
    } else {
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_57) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_57 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_58) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_58 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_63) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_63 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_65) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_65 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_66) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_66 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__81(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__81\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__reset) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_67 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_68 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_73 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_75 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_77 = 0ULL;
    } else if (vlSelfRef.tb__DOT__io_resetStats) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_67 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_68 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_73 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_75 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_77 = 0ULL;
    } else if (vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) {
        if (vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_67 
                = ((0x43U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1482);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_68 
                = ((0x44U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1485);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_73 
                = ((0x49U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1500);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_75 
                = ((0x4bU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1506);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_77 
                = ((0x4dU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1512);
        } else {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_67 
                = ((0x43U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1482);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_68 
                = ((0x44U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1485);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_73 
                = ((0x49U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1500);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_75 
                = ((0x4bU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1506);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_77 
                = ((0x4dU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1512);
        }
    } else {
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_67) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_67 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_68) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_68 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_73) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_73 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_75) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_75 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_77) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_77 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__82(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__82\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__reset) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_78 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_83 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_85 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_87 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_88 = 0ULL;
    } else if (vlSelfRef.tb__DOT__io_resetStats) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_78 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_83 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_85 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_87 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_88 = 0ULL;
    } else if (vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) {
        if (vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_78 
                = ((0x4eU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1515);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_83 
                = ((0x53U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1530);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_85 
                = ((0x55U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1536);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_87 
                = ((0x57U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1542);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_88 
                = ((0x58U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1545);
        } else {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_78 
                = ((0x4eU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1515);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_83 
                = ((0x53U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1530);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_85 
                = ((0x55U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1536);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_87 
                = ((0x57U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1542);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_88 
                = ((0x58U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1545);
        }
    } else {
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_78) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_78 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_83) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_83 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_85) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_85 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_87) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_87 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_88) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_88 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__83(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__83\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__reset) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_93 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_95 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_97 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_98 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_103 = 0ULL;
    } else if (vlSelfRef.tb__DOT__io_resetStats) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_93 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_95 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_97 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_98 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_103 = 0ULL;
    } else if (vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) {
        if (vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_93 
                = ((0x5dU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1560);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_95 
                = ((0x5fU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1566);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_97 
                = ((0x61U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1572);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_98 
                = ((0x62U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1575);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_103 
                = ((0x67U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1590);
        } else {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_93 
                = ((0x5dU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1560);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_95 
                = ((0x5fU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1566);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_97 
                = ((0x61U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1572);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_98 
                = ((0x62U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1575);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_103 
                = ((0x67U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1590);
        }
    } else {
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_93) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_93 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_95) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_95 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_97) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_97 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_98) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_98 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_103) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_103 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__84(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__84\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__reset) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_105 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_107 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_108 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_113 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_115 = 0ULL;
    } else if (vlSelfRef.tb__DOT__io_resetStats) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_105 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_107 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_108 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_113 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_115 = 0ULL;
    } else if (vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) {
        if (vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_105 
                = ((0x69U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1596);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_107 
                = ((0x6bU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1602);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_108 
                = ((0x6cU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1605);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_113 
                = ((0x71U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1620);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_115 
                = ((0x73U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1626);
        } else {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_105 
                = ((0x69U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1596);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_107 
                = ((0x6bU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1602);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_108 
                = ((0x6cU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1605);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_113 
                = ((0x71U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1620);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_115 
                = ((0x73U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1626);
        }
    } else {
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_105) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_105 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_107) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_107 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_108) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_108 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_113) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_113 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_115) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_115 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__85(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__85\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__reset) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_117 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_118 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_123 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_125 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_127 = 0ULL;
    } else if (vlSelfRef.tb__DOT__io_resetStats) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_117 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_118 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_123 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_125 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_127 = 0ULL;
    } else if (vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) {
        if (vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_117 
                = ((0x75U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1632);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_118 
                = ((0x76U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1635);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_123 
                = ((0x7bU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1650);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_125 
                = ((0x7dU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1656);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_127 
                = ((0x7fU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1662);
        } else {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_117 
                = ((0x75U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1632);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_118 
                = ((0x76U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1635);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_123 
                = ((0x7bU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1650);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_125 
                = ((0x7dU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1656);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_127 
                = ((0x7fU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1662);
        }
    } else {
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_117) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_117 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_118) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_118 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_123) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_123 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_125) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_125 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_127) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_127 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__86(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__86\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__reset) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_128 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_133 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_135 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_137 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_138 = 0ULL;
    } else if (vlSelfRef.tb__DOT__io_resetStats) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_128 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_133 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_135 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_137 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_138 = 0ULL;
    } else if (vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) {
        if (vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_128 
                = ((0x80U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1665);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_133 
                = ((0x85U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1680);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_135 
                = ((0x87U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1686);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_137 
                = ((0x89U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1692);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_138 
                = ((0x8aU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1695);
        } else {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_128 
                = ((0x80U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1665);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_133 
                = ((0x85U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1680);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_135 
                = ((0x87U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1686);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_137 
                = ((0x89U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1692);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_138 
                = ((0x8aU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1695);
        }
    } else {
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_128) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_128 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_133) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_133 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_135) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_135 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_137) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_137 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_138) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_138 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__87(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__87\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__reset) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_143 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_145 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_147 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_148 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_153 = 0ULL;
    } else if (vlSelfRef.tb__DOT__io_resetStats) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_143 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_145 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_147 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_148 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_153 = 0ULL;
    } else if (vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) {
        if (vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_143 
                = ((0x8fU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1710);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_145 
                = ((0x91U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1716);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_147 
                = ((0x93U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1722);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_148 
                = ((0x94U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1725);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_153 
                = ((0x99U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1740);
        } else {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_143 
                = ((0x8fU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1710);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_145 
                = ((0x91U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1716);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_147 
                = ((0x93U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1722);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_148 
                = ((0x94U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1725);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_153 
                = ((0x99U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1740);
        }
    } else {
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_143) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_143 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_145) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_145 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_147) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_147 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_148) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_148 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_153) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_153 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__88(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__88\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb__DOT__reset) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_155 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_157 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_158 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_163 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_7 = 0ULL;
    } else if (vlSelfRef.tb__DOT__io_resetStats) {
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_155 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_157 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_158 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_163 = 0ULL;
        vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_7 = 0ULL;
    } else if (vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted) {
        if (vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_155 
                = ((0x9bU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1746);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_157 
                = ((0x9dU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1752);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_158 
                = ((0x9eU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1755);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_163 
                = ((0xa3U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1770);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_7 
                = ((7U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? 1ULL : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1302);
        } else {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_155 
                = ((0x9bU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1746);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_157 
                = ((0x9dU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1752);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_158 
                = ((0x9eU == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1755);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_163 
                = ((0xa3U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1770);
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_7 
                = ((7U == (0xffU & vlSelfRef.tb__DOT__io_event_bits))
                    ? (1ULL + vlSelfRef.tb__DOT__dutReference__DOT___GEN_1023)
                    : vlSelfRef.tb__DOT__dutReference__DOT___GEN_1302);
        }
    } else {
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_155) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_155 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_157) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_157 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_158) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_158 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_163) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_163 = 0ULL;
        }
        if (vlSelfRef.tb__DOT__dutReference__DOT__bucketResolve_7) {
            vlSelfRef.tb__DOT__dutReference__DOT__buckets_count_7 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__89(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__89\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_124 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x7cU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1652))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1652))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1652))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_122 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x7aU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1646))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1646))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1646))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_116 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x74U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1628))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1628))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1628))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_110 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x6eU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1610))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1610))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1610))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_106 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x6aU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1598))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1598))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1598))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_104 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x68U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1592))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1592))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1592))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_102 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x66U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1586))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1586))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1586))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_100 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x64U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1580))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1580))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1580))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_98 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x62U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1574))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1574))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1574))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_96 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x60U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1568))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1568))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1568))));
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__90(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__90\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_90 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x5aU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1550))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1550))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1550))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_84 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x54U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1532))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1532))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1532))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_80 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x50U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1520))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1520))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1520))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_78 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x4eU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1514))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1514))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1514))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_76 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x4cU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1508))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1508))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1508))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_74 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x4aU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1502))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1502))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1502))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_72 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x48U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1496))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1496))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1496))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_70 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x46U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1490))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1490))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1490))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_64 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x40U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1472))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1472))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1472))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_58 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x3aU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1454))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1454))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1454))));
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__91(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__91\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_54 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x36U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1442))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1442))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1442))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_52 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x34U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1436))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1436))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1436))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_50 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x32U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1430))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1430))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1430))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_48 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x30U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1424))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1424))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1424))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_46 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x2eU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1418))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1418))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1418))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_44 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x2cU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1412))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1412))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1412))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_38 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x26U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1394))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1394))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1394))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_32 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x20U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1376))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1376))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1376))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_28 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x1cU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1364))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1364))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1364))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_26 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x1aU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1358))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1358))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1358))));
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__92(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__92\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_24 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x18U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1352))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1352))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1352))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_22 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x16U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1346))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1346))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1346))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_20 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x14U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1340))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1340))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1340))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_18 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x12U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1334))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1334))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1334))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_12 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xcU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1316))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1316))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1316))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_6 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((6U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1298))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1298))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1298))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_2 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((2U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1286))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1286))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1286))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_40 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x28U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1400))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1400))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1400))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_255 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xffU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2045))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2045))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2045))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_254 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xfeU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2042))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2042))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2042))));
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__93(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__93\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_253 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xfdU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2039))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2039))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2039))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_252 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xfcU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2036))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2036))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2036))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_36 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x24U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1388))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1388))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1388))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_251 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xfbU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2033))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2033))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2033))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_250 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xfaU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2030))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2030))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2030))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_34 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x22U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1382))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1382))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1382))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_249 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xf9U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2027))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2027))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2027))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_248 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xf8U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2024))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2024))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2024))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_247 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xf7U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2021))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2021))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2021))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_246 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xf6U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2018))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2018))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2018))));
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__94(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__94\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_30 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x1eU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1370))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1370))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1370))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_245 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xf5U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2015))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2015))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2015))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_244 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xf4U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2012))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2012))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2012))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_243 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xf3U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2009))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2009))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2009))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_242 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xf2U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2006))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2006))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2006))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_241 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xf1U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2003))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2003))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2003))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_240 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xf0U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2000))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2000))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_2000))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_239 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xefU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1997))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1997))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1997))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_238 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xeeU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1994))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1994))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1994))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_237 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xedU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1991))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1991))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1991))));
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__95(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__95\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_236 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xecU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1988))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1988))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1988))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_235 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xebU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1985))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1985))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1985))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_234 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xeaU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1982))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1982))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1982))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_233 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xe9U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1979))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1979))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1979))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_232 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xe8U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1976))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1976))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1976))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_16 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x10U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1328))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1328))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1328))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_231 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xe7U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1973))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1973))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1973))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_230 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xe6U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1970))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1970))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1970))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_14 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xeU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1322))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1322))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1322))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_229 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xe5U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1967))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1967))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1967))));
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__96(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__96\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_228 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xe4U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1964))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1964))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1964))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_227 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xe3U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1961))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1961))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1961))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_226 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xe2U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1958))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1958))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1958))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_10 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xaU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1310))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1310))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1310))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_225 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xe1U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1955))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1955))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1955))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_224 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xe0U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1952))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1952))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1952))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_8 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((8U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1304))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1304))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1304))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_223 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xdfU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1949))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1949))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1949))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_222 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xdeU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1946))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1946))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1946))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_220 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xdcU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1940))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1940))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1940))));
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__97(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__97\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_4 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((4U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1292))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1292))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1292))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_219 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xdbU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1937))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1937))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1937))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_218 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xdaU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1934))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1934))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1934))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_217 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xd9U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1931))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1931))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1931))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_216 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xd8U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1928))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1928))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1928))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_215 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xd7U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1925))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1925))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1925))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_214 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xd6U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1922))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1922))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1922))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_213 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xd5U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1919))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1919))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1919))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_212 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xd4U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1916))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1916))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1916))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_211 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xd3U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1913))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1913))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1913))));
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__98(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__98\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_210 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xd2U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1910))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1910))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1910))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_209 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xd1U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1907))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1907))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1907))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_208 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xd0U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1904))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1904))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1904))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_207 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xcfU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1901))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1901))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1901))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_206 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xceU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1898))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1898))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1898))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_205 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xcdU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1895))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1895))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1895))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_204 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xccU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1892))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1892))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1892))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_203 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xcbU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1889))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1889))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1889))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_202 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xcaU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1886))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1886))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1886))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_201 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xc9U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1883))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1883))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1883))));
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__99(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__99\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_200 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xc8U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1880))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1880))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1880))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_199 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xc7U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1877))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1877))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1877))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_198 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xc6U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1874))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1874))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1874))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_197 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xc5U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1871))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1871))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1871))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_196 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xc4U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1868))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1868))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1868))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_195 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xc3U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1865))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1865))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1865))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_194 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xc2U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1862))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1862))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1862))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_193 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xc1U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1859))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1859))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1859))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_192 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xc0U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1856))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1856))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1856))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_191 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xbfU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1853))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1853))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1853))));
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__100(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__100\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_190 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xbeU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1850))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1850))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1850))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_189 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xbdU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1847))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1847))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1847))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_188 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xbcU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1844))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1844))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1844))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_187 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xbbU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1841))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1841))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1841))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_186 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xbaU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1838))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1838))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1838))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_185 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xb9U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1835))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1835))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1835))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_184 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xb8U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1832))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1832))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1832))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_183 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xb7U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1829))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1829))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1829))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_182 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xb6U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1826))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1826))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1826))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_181 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xb5U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1823))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1823))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1823))));
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__101(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__101\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_180 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xb4U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1820))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1820))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1820))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_179 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xb3U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1817))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1817))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1817))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_178 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xb2U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1814))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1814))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1814))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_176 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xb0U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1808))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1808))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1808))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_175 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xafU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1805))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1805))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1805))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_174 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xaeU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1802))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1802))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1802))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_171 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xabU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1793))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1793))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1793))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_169 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xa9U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1787))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1787))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1787))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_168 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xa8U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1784))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1784))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1784))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_167 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xa7U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1781))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1781))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1781))));
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__102(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__102\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_165 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xa5U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1775))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1775))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1775))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_163 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xa3U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1769))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1769))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1769))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_162 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xa2U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1766))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1766))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1766))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_161 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xa1U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1763))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1763))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1763))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_158 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x9eU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1754))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1754))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1754))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_156 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x9cU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1748))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1748))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1748))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_155 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x9bU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1745))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1745))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1745))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_154 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x9aU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1742))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1742))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1742))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_152 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x98U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1736))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1736))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1736))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_150 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x96U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1730))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1730))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1730))));
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__103(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__103\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_149 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x95U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1727))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1727))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1727))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_148 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x94U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1724))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1724))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1724))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_142 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x8eU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1706))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1706))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1706))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_136 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x88U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1688))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1688))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1688))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_132 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x84U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1676))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1676))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1676))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_130 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x82U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1670))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1670))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1670))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_128 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x80U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1664))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1664))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1664))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_33 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x21U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1379))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1379))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1379))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_31 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x1fU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1373))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1373))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1373))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_9 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((9U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1307))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1307))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1307))));
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__104(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__104\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_5 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((5U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1295))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1295))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1295))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_11 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xbU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1313))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1313))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1313))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_13 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xdU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1319))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1319))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1319))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_15 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xfU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1325))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1325))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1325))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_19 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x13U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1337))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1337))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1337))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_25 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x19U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1355))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1355))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1355))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_221 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0xddU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1943))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1943))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1943))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_0 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1280))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1280))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1280))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_126 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x7eU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1658))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1658))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1658))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_35 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x23U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1385))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1385))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1385))));
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__105(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__105\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_42 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x2aU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1406))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1406))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1406))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_37 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x25U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1391))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1391))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1391))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_39 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x27U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1397))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1397))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1397))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_41 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x29U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1403))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1403))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1403))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_45 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x2dU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1415))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1415))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1415))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_51 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x33U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1433))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1433))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1433))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_57 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x39U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1451))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1451))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1451))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_59 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x3bU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1457))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1457))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1457))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_61 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x3dU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1463))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1463))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1463))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_63 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x3fU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1469))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1469))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1469))));
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__106(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__106\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_65 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x41U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1475))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1475))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1475))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_67 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x43U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1481))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1481))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1481))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_71 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x47U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1493))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1493))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1493))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_77 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x4dU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1511))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1511))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1511))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_83 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x53U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1529))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1529))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1529))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_85 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x55U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1535))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1535))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1535))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_87 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x57U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1541))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1541))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1541))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_89 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x59U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1547))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1547))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1547))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_91 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x5bU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1553))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1553))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1553))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_93 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x5dU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1559))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1559))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1559))));
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__107(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__107\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_97 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x61U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1571))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1571))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1571))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_103 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x67U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1589))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1589))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1589))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_109 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x6dU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1607))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1607))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1607))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_111 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x6fU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1613))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1613))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1613))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_113 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x71U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1619))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1619))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1619))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_115 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x73U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1625))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1625))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1625))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_117 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x75U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1631))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1631))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1631))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_119 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x77U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1637))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1637))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1637))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_123 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x7bU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1649))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1649))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1649))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_129 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x81U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1667))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1667))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1667))));
}

VL_INLINE_OPT void Vtb___024root___nba_sequent__TOP__108(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_sequent__TOP__108\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_135 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x87U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1685))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1685))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1685))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_137 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x89U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1691))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1691))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1691))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_139 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x8bU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1697))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1697))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1697))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_141 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x8dU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1703))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1703))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1703))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_143 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x8fU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1709))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1709))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1709))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_145 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x91U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1715))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1715))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1715))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_56 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x38U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1448))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1448))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1448))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_60 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x3cU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1460))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1460))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1460))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_62 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x3eU == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1466))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1466))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1466))));
    vlSelfRef.tb__DOT__dutReference__DOT__buckets_valid_66 
        = ((1U & (~ (IData)(vlSelfRef.tb__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelfRef.tb__DOT__io_resetStats))) 
               && ((IData)(vlSelfRef.tb__DOT__dutReference__DOT__eventAccepted)
                    ? ((IData)(vlSelfRef.tb__DOT__dutReference__DOT___eventBucketAvailable_T_1)
                        ? ((0x42U == (0xffU & vlSelfRef.tb__DOT__io_event_bits)) 
                           | (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1478))
                        : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1478))
                    : (IData)(vlSelfRef.tb__DOT__dutReference__DOT___GEN_1478))));
}
