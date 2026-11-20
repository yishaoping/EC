// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_GeometryBankProof.h"
#include "Vtb__Syms.h"

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__80(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__80\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29831 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2395) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2365) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34295 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2395) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2365) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3050 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2420) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2385) 
              == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7514 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2420) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2385) 
              == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11978 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2420) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2385) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16442 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2420) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2385) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20906 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2420) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2385) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25370 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2420) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2385) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29834 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2420) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2385) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34298 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2420) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2385) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_51) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2401 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2366) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2397)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2413 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2368) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2409)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2419 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2369) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2415)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2426 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2367) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2403)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2401 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2397));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2413 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2409));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2419 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2415));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2426 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2403));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3071 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2579) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2527) 
              == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7535 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2579) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2527) 
              == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11999 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2579) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2527) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16463 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2579) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2527) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20927 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2579) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2527) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25391 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2579) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2527) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29855 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2579) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2527) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34319 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2579) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2527) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3065 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2532) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2502) 
              == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__81(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__81\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7529 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2532) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2502) 
              == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11993 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2532) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2502) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16457 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2532) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2502) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20921 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2532) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2502) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25385 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2532) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2502) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29849 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2532) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2502) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34313 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2532) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2502) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3068 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2557) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2522) 
              == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7532 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2557) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2522) 
              == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11996 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2557) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2522) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16460 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2557) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2522) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20924 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2557) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2522) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25388 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2557) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2522) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29852 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2557) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2522) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34316 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2557) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2522) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_54) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2538 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2503) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2534)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2550 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2505) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2546)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2556 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2506) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2552)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2563 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2504) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2540)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2538 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2534));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2550 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2546));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2556 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2552));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2563 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2540));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3089 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2716) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2664) 
              == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7553 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2716) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2664) 
              == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12017 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2716) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2664) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16481 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2716) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2664) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__82(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__82\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20945 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2716) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2664) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25409 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2716) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2664) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29873 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2716) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2664) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34337 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2716) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2664) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3083 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2669) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2639) 
              == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7547 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2669) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2639) 
              == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12011 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2669) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2639) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16475 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2669) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2639) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20939 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2669) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2639) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25403 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2669) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2639) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29867 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2669) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2639) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34331 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2669) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2639) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3086 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2694) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2659) 
              == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7550 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2694) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2659) 
              == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12014 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2694) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2659) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16478 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2694) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2659) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20942 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2694) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2659) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25406 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2694) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2659) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29870 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2694) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2659) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34334 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2694) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2659) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_57) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2675 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2640) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2671)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2687 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2642) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2683)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2693 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2643) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2689)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2675 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2671));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2687 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2683));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2693 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2689));
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__94(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__94\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__reset) {
        vlSelfRef.buckets_count_7 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_barrierResetStats) {
        vlSelfRef.buckets_count_7 = 0ULL;
    } else if (vlSelfRef.__PVT__accepted_7) {
        vlSelfRef.buckets_count_7 = ((IData)(vlSelfRef.__PVT___canAccept_T_22)
                                      ? 1ULL : vlSelfRef.__PVT___buckets_count_7_T_1);
    } else if (vlSelfRef.__PVT__resolving_7) {
        vlSelfRef.buckets_count_7 = 0ULL;
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__95(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__95\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__reset) {
        vlSelfRef.__PVT__buckets_count_6 = 0ULL;
        vlSelfRef.__PVT__buckets_count_5 = 0ULL;
        vlSelfRef.__PVT__buckets_count_4 = 0ULL;
        vlSelfRef.__PVT__buckets_count_3 = 0ULL;
        vlSelfRef.__PVT__buckets_count_2 = 0ULL;
        vlSelfRef.__PVT__buckets_count_1 = 0ULL;
        vlSelfRef.buckets_count_0 = 0ULL;
        vlSelfRef.buckets_requestCycleSum_7 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_6 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_barrierResetStats) {
        vlSelfRef.__PVT__buckets_count_6 = 0ULL;
        vlSelfRef.__PVT__buckets_count_5 = 0ULL;
        vlSelfRef.__PVT__buckets_count_4 = 0ULL;
        vlSelfRef.__PVT__buckets_count_3 = 0ULL;
        vlSelfRef.__PVT__buckets_count_2 = 0ULL;
        vlSelfRef.__PVT__buckets_count_1 = 0ULL;
        vlSelfRef.buckets_count_0 = 0ULL;
        vlSelfRef.buckets_requestCycleSum_7 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_6 = 0ULL;
    } else {
        if (vlSelfRef.__PVT__accepted_6) {
            if (vlSelfRef.__PVT___canAccept_T_19) {
                vlSelfRef.__PVT__buckets_count_6 = 1ULL;
                vlSelfRef.__PVT__buckets_requestCycleSum_6 
                    = vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle;
            } else {
                vlSelfRef.__PVT__buckets_count_6 = vlSelfRef.__PVT___buckets_count_6_T_1;
                vlSelfRef.__PVT__buckets_requestCycleSum_6 
                    = vlSelfRef.__PVT___buckets_requestCycleSum_6_T_1;
            }
        } else if (vlSelfRef.__PVT__resolving_6) {
            vlSelfRef.__PVT__buckets_count_6 = 0ULL;
            vlSelfRef.__PVT__buckets_requestCycleSum_6 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_5) {
            vlSelfRef.__PVT__buckets_count_5 = ((IData)(vlSelfRef.__PVT___canAccept_T_16)
                                                 ? 1ULL
                                                 : vlSelfRef.__PVT___buckets_count_5_T_1);
        } else if (vlSelfRef.__PVT__resolving_5) {
            vlSelfRef.__PVT__buckets_count_5 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_4) {
            vlSelfRef.__PVT__buckets_count_4 = ((IData)(vlSelfRef.__PVT___canAccept_T_13)
                                                 ? 1ULL
                                                 : vlSelfRef.__PVT___buckets_count_4_T_1);
        } else if (vlSelfRef.__PVT__resolving_4) {
            vlSelfRef.__PVT__buckets_count_4 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_3) {
            vlSelfRef.__PVT__buckets_count_3 = ((IData)(vlSelfRef.__PVT___canAccept_T_10)
                                                 ? 1ULL
                                                 : vlSelfRef.__PVT___buckets_count_3_T_1);
        } else if (vlSelfRef.__PVT__resolving_3) {
            vlSelfRef.__PVT__buckets_count_3 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_2) {
            vlSelfRef.__PVT__buckets_count_2 = ((IData)(vlSelfRef.__PVT___canAccept_T_7)
                                                 ? 1ULL
                                                 : vlSelfRef.__PVT___buckets_count_2_T_1);
        } else if (vlSelfRef.__PVT__resolving_2) {
            vlSelfRef.__PVT__buckets_count_2 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_1) {
            vlSelfRef.__PVT__buckets_count_1 = ((IData)(vlSelfRef.__PVT___canAccept_T_4)
                                                 ? 1ULL
                                                 : vlSelfRef.__PVT___buckets_count_1_T_1);
        } else if (vlSelfRef.__PVT__resolving_1) {
            vlSelfRef.__PVT__buckets_count_1 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted) {
            vlSelfRef.buckets_count_0 = ((IData)(vlSelfRef.__PVT___canAccept_T_1)
                                          ? 1ULL : vlSelfRef.__PVT___buckets_count_0_T_1);
        } else if (vlSelfRef.__PVT__resolving_0) {
            vlSelfRef.buckets_count_0 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_7) {
            vlSelfRef.buckets_requestCycleSum_7 = ((IData)(vlSelfRef.__PVT___canAccept_T_22)
                                                    ? vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle
                                                    : vlSelfRef.__PVT___buckets_requestCycleSum_7_T_1);
        } else if (vlSelfRef.__PVT__resolving_7) {
            vlSelfRef.buckets_requestCycleSum_7 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__96(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__96\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__reset) {
        vlSelfRef.__PVT__buckets_requestCycleSum_5 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_4 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_3 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_2 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_1 = 0ULL;
        vlSelfRef.buckets_requestCycleSum_0 = 0ULL;
        vlSelfRef.buckets_seq_7 = 0U;
        vlSelfRef.__PVT__buckets_seq_6 = 0U;
        vlSelfRef.__PVT__buckets_seq_3 = 0U;
        vlSelfRef.__PVT__buckets_seq_2 = 0U;
    } else if (vlSymsp->TOP.tb__DOT__io_barrierResetStats) {
        vlSelfRef.__PVT__buckets_requestCycleSum_5 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_4 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_3 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_2 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_1 = 0ULL;
        vlSelfRef.buckets_requestCycleSum_0 = 0ULL;
        vlSelfRef.buckets_seq_7 = 0U;
        vlSelfRef.__PVT__buckets_seq_6 = 0U;
        vlSelfRef.__PVT__buckets_seq_3 = 0U;
        vlSelfRef.__PVT__buckets_seq_2 = 0U;
    } else {
        if (vlSelfRef.__PVT__accepted_5) {
            vlSelfRef.__PVT__buckets_requestCycleSum_5 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_16)
                    ? vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_5_T_1);
        } else if (vlSelfRef.__PVT__resolving_5) {
            vlSelfRef.__PVT__buckets_requestCycleSum_5 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_4) {
            vlSelfRef.__PVT__buckets_requestCycleSum_4 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_13)
                    ? vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_4_T_1);
        } else if (vlSelfRef.__PVT__resolving_4) {
            vlSelfRef.__PVT__buckets_requestCycleSum_4 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_3) {
            if (vlSelfRef.__PVT___canAccept_T_10) {
                vlSelfRef.__PVT__buckets_requestCycleSum_3 
                    = vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle;
                vlSelfRef.__PVT__buckets_seq_3 = vlSymsp->TOP.tb__DOT__io_barrierEvent_bits;
            } else {
                vlSelfRef.__PVT__buckets_requestCycleSum_3 
                    = vlSelfRef.__PVT___buckets_requestCycleSum_3_T_1;
            }
        } else if (vlSelfRef.__PVT__resolving_3) {
            vlSelfRef.__PVT__buckets_requestCycleSum_3 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_2) {
            if (vlSelfRef.__PVT___canAccept_T_7) {
                vlSelfRef.__PVT__buckets_requestCycleSum_2 
                    = vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle;
                vlSelfRef.__PVT__buckets_seq_2 = vlSymsp->TOP.tb__DOT__io_barrierEvent_bits;
            } else {
                vlSelfRef.__PVT__buckets_requestCycleSum_2 
                    = vlSelfRef.__PVT___buckets_requestCycleSum_2_T_1;
            }
        } else if (vlSelfRef.__PVT__resolving_2) {
            vlSelfRef.__PVT__buckets_requestCycleSum_2 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_1) {
            vlSelfRef.__PVT__buckets_requestCycleSum_1 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_4)
                    ? vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_1_T_1);
        } else if (vlSelfRef.__PVT__resolving_1) {
            vlSelfRef.__PVT__buckets_requestCycleSum_1 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted) {
            vlSelfRef.buckets_requestCycleSum_0 = ((IData)(vlSelfRef.__PVT___canAccept_T_1)
                                                    ? vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle
                                                    : vlSelfRef.__PVT___buckets_requestCycleSum_0_T_1);
        } else if (vlSelfRef.__PVT__resolving_0) {
            vlSelfRef.buckets_requestCycleSum_0 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_7) {
            if (vlSelfRef.__PVT___canAccept_T_22) {
                vlSelfRef.buckets_seq_7 = vlSymsp->TOP.tb__DOT__io_barrierEvent_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_6) {
            if (vlSelfRef.__PVT___canAccept_T_19) {
                vlSelfRef.__PVT__buckets_seq_6 = vlSymsp->TOP.tb__DOT__io_barrierEvent_bits;
            }
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__97(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__97\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__reset) {
        vlSelfRef.__PVT__buckets_seq_1 = 0U;
        vlSelfRef.buckets_seq_0 = 0U;
        vlSelfRef.__PVT__buckets_seq_4 = 0U;
        vlSelfRef.__PVT__buckets_seq_5 = 0U;
        vlSelfRef.buckets_valid_7 = 0U;
        vlSelfRef.__PVT__buckets_valid_5 = 0U;
        vlSelfRef.__PVT__buckets_valid_4 = 0U;
        vlSelfRef.__PVT__buckets_valid_6 = 0U;
        vlSelfRef.buckets_valid_0 = 0U;
        vlSelfRef.__PVT__buckets_valid_2 = 0U;
    } else if (vlSymsp->TOP.tb__DOT__io_barrierResetStats) {
        vlSelfRef.__PVT__buckets_seq_1 = 0U;
        vlSelfRef.buckets_seq_0 = 0U;
        vlSelfRef.__PVT__buckets_seq_4 = 0U;
        vlSelfRef.__PVT__buckets_seq_5 = 0U;
        vlSelfRef.buckets_valid_7 = 0U;
        vlSelfRef.__PVT__buckets_valid_5 = 0U;
        vlSelfRef.__PVT__buckets_valid_4 = 0U;
        vlSelfRef.__PVT__buckets_valid_6 = 0U;
        vlSelfRef.buckets_valid_0 = 0U;
        vlSelfRef.__PVT__buckets_valid_2 = 0U;
    } else {
        if (vlSelfRef.__PVT__accepted_1) {
            if (vlSelfRef.__PVT___canAccept_T_4) {
                vlSelfRef.__PVT__buckets_seq_1 = vlSymsp->TOP.tb__DOT__io_barrierEvent_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted) {
            if (vlSelfRef.__PVT___canAccept_T_1) {
                vlSelfRef.buckets_seq_0 = vlSymsp->TOP.tb__DOT__io_barrierEvent_bits;
            }
            vlSelfRef.buckets_valid_0 = ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                         | (IData)(vlSelfRef.__PVT___GEN_2088));
        } else if (vlSelfRef.__PVT__resolving_0) {
            vlSelfRef.buckets_valid_0 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_4) {
            if (vlSelfRef.__PVT___canAccept_T_13) {
                vlSelfRef.__PVT__buckets_seq_4 = vlSymsp->TOP.tb__DOT__io_barrierEvent_bits;
            }
            vlSelfRef.__PVT__buckets_valid_4 = ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                                | (IData)(vlSelfRef.__PVT___GEN_2148));
        } else if (vlSelfRef.__PVT__resolving_4) {
            vlSelfRef.__PVT__buckets_valid_4 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_5) {
            if (vlSelfRef.__PVT___canAccept_T_16) {
                vlSelfRef.__PVT__buckets_seq_5 = vlSymsp->TOP.tb__DOT__io_barrierEvent_bits;
            }
            vlSelfRef.__PVT__buckets_valid_5 = ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                                | (IData)(vlSelfRef.__PVT___GEN_2163));
        } else if (vlSelfRef.__PVT__resolving_5) {
            vlSelfRef.__PVT__buckets_valid_5 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_7) {
            vlSelfRef.buckets_valid_7 = ((IData)(vlSelfRef.__PVT___canAccept_T_22) 
                                         | (IData)(vlSelfRef.__PVT___GEN_2193));
        } else if (vlSelfRef.__PVT__resolving_7) {
            vlSelfRef.buckets_valid_7 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_6) {
            vlSelfRef.__PVT__buckets_valid_6 = ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                                | (IData)(vlSelfRef.__PVT___GEN_2178));
        } else if (vlSelfRef.__PVT__resolving_6) {
            vlSelfRef.__PVT__buckets_valid_6 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_2) {
            vlSelfRef.__PVT__buckets_valid_2 = ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                                | (IData)(vlSelfRef.__PVT___GEN_2118));
        } else if (vlSelfRef.__PVT__resolving_2) {
            vlSelfRef.__PVT__buckets_valid_2 = 0U;
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__98(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__98\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__reset) {
        vlSelfRef.__PVT__buckets_valid_3 = 0U;
        vlSelfRef.__PVT__buckets_valid_1 = 0U;
    } else if (vlSymsp->TOP.tb__DOT__io_barrierResetStats) {
        vlSelfRef.__PVT__buckets_valid_3 = 0U;
        vlSelfRef.__PVT__buckets_valid_1 = 0U;
    } else {
        if (vlSelfRef.__PVT__accepted_3) {
            vlSelfRef.__PVT__buckets_valid_3 = ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                                | (IData)(vlSelfRef.__PVT___GEN_2133));
        } else if (vlSelfRef.__PVT__resolving_3) {
            vlSelfRef.__PVT__buckets_valid_3 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_1) {
            vlSelfRef.__PVT__buckets_valid_1 = ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                                | (IData)(vlSelfRef.__PVT___GEN_2103));
        } else if (vlSelfRef.__PVT__resolving_1) {
            vlSelfRef.__PVT__buckets_valid_1 = 0U;
        }
    }
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.bucketSeq_7 = 0U;
        vlSelfRef.__PVT__bucketSeq_3 = 0U;
        vlSelfRef.__PVT__bucketSeq_1 = 0U;
        vlSelfRef.__PVT__bucketSeq_2 = 0U;
        vlSelfRef.__PVT__bucketSeq_4 = 0U;
        vlSelfRef.bucketSeq_0 = 0U;
        vlSelfRef.__PVT__bucketSeq_5 = 0U;
        vlSelfRef.__PVT__bucketSeq_6 = 0U;
        vlSelfRef.__PVT__bucketStore_2_0 = 0ULL;
        vlSelfRef.__PVT__bucketStore_2_1 = 0ULL;
        vlSelfRef.__PVT__bucketStore_2_2 = 0ULL;
    } else {
        if (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
             & (IData)(vlSelfRef.__PVT__isCurrent_7))) {
            vlSelfRef.bucketSeq_7 = vlSymsp->TOP.tb__DOT__io_processSeq;
        }
        if (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
             & (IData)(vlSelfRef.__PVT__isCurrent_3))) {
            vlSelfRef.__PVT__bucketSeq_3 = vlSymsp->TOP.tb__DOT__io_processSeq;
        }
        if (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
             & (IData)(vlSelfRef.__PVT__isCurrent_1))) {
            vlSelfRef.__PVT__bucketSeq_1 = vlSymsp->TOP.tb__DOT__io_processSeq;
        }
        if (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
             & (IData)(vlSelfRef.__PVT__isCurrent_2))) {
            vlSelfRef.__PVT__bucketSeq_2 = vlSymsp->TOP.tb__DOT__io_processSeq;
        }
        if (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
             & (IData)(vlSelfRef.__PVT__isCurrent_4))) {
            vlSelfRef.__PVT__bucketSeq_4 = vlSymsp->TOP.tb__DOT__io_processSeq;
        }
        if (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
             & (IData)(vlSelfRef.__PVT__isCurrent))) {
            vlSelfRef.bucketSeq_0 = vlSymsp->TOP.tb__DOT__io_processSeq;
        }
        if (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
             & (IData)(vlSelfRef.__PVT__isCurrent_5))) {
            vlSelfRef.__PVT__bucketSeq_5 = vlSymsp->TOP.tb__DOT__io_processSeq;
        }
        if (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
             & (IData)(vlSelfRef.__PVT__isCurrent_6))) {
            vlSelfRef.__PVT__bucketSeq_6 = vlSymsp->TOP.tb__DOT__io_processSeq;
        }
        if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
               & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
              & (IData)(vlSelfRef.__PVT__isRetiring_2)) 
             & (IData)(vlSelfRef.__PVT__bucketValid_2))) {
            vlSelfRef.__PVT__bucketStore_2_0 = 0ULL;
            vlSelfRef.__PVT__bucketStore_2_1 = 0ULL;
            vlSelfRef.__PVT__bucketStore_2_2 = 0ULL;
        } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
            if (vlSelfRef.__PVT__isCurrent_2) {
                vlSelfRef.__PVT__bucketStore_2_0 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_8[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_8[0U])));
                vlSelfRef.__PVT__bucketStore_2_1 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_9[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_9[0U])));
                vlSelfRef.__PVT__bucketStore_2_2 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_10[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_10[0U])));
            }
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__99(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__99\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketStore_2_3 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_2_0 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_2_1 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_2_2 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_2_3 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_2_0 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_2_1 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring_2)) 
                & (IData)(vlSelfRef.__PVT__bucketValid_2))) {
        vlSelfRef.__PVT__bucketStore_2_3 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_2_0 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_2_1 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_2_2 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_2_3 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_2_0 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_2_1 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (vlSelfRef.__PVT__isCurrent_2) {
            vlSelfRef.__PVT__bucketStore_2_3 = (((QData)((IData)(
                                                                 vlSelfRef.__PVT__currentStoreNextWide_11[1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelfRef.__PVT__currentStoreNextWide_11[0U])));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_2) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1185)))) {
            vlSelfRef.__PVT__bucketLoadFirst_2_0 = 
                ((IData)(vlSelfRef.__PVT__allocate_2)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1185))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_8[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_8[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_2) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1224)))) {
            vlSelfRef.__PVT__bucketLoadFirst_2_1 = 
                ((IData)(vlSelfRef.__PVT__allocate_2)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1224))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_9[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_9[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_2) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1265)))) {
            vlSelfRef.__PVT__bucketLoadFirst_2_2 = 
                ((IData)(vlSelfRef.__PVT__allocate_2)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1265))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_10[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_10[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_2) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1306)))) {
            vlSelfRef.__PVT__bucketLoadFirst_2_3 = 
                ((IData)(vlSelfRef.__PVT__allocate_2)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1306))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_11[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_11[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_2) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1185)))) {
            vlSelfRef.__PVT__bucketStoreFirst_2_0 = 
                ((IData)(vlSelfRef.__PVT__allocate_2)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1185))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_8[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_8[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_2) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1224)))) {
            vlSelfRef.__PVT__bucketStoreFirst_2_1 = 
                ((IData)(vlSelfRef.__PVT__allocate_2)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1224))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_9[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_9[0U]))));
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__100(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__100\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketStoreFirst_2_2 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_2_3 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_2_0 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_2_1 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_2_2 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_2_3 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring_2)) 
                & (IData)(vlSelfRef.__PVT__bucketValid_2))) {
        vlSelfRef.__PVT__bucketStoreFirst_2_2 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_2_3 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_2_0 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_2_1 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_2_2 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_2_3 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (((IData)(vlSelfRef.__PVT__isCurrent_2) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1265)))) {
            vlSelfRef.__PVT__bucketStoreFirst_2_2 = 
                ((IData)(vlSelfRef.__PVT__allocate_2)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1265))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_10[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_10[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_2) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1306)))) {
            vlSelfRef.__PVT__bucketStoreFirst_2_3 = 
                ((IData)(vlSelfRef.__PVT__allocate_2)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1306))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_11[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_11[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_2) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12102)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_2_0 
                = ((IData)(vlSelfRef.__PVT__allocate_2)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12102))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_8[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_8[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_2) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12518)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_2_1 
                = ((IData)(vlSelfRef.__PVT__allocate_2)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12518))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_9[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_9[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_2) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12954)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_2_2 
                = ((IData)(vlSelfRef.__PVT__allocate_2)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12954))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_10[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_10[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_2) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_13390)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_2_3 
                = ((IData)(vlSelfRef.__PVT__allocate_2)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_13390))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_11[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_11[0U]))));
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__101(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__101\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketFirstStore_2_0 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_2_1 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_2_2 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_2_3 = 0ULL;
        vlSelfRef.__PVT__bucketStore_4_0 = 0ULL;
        vlSelfRef.__PVT__bucketStore_4_1 = 0ULL;
        vlSelfRef.__PVT__bucketStore_4_2 = 0ULL;
        vlSelfRef.__PVT__bucketStore_4_3 = 0ULL;
    } else {
        if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
               & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
              & (IData)(vlSelfRef.__PVT__isRetiring_2)) 
             & (IData)(vlSelfRef.__PVT__bucketValid_2))) {
            vlSelfRef.__PVT__bucketFirstStore_2_0 = 0ULL;
            vlSelfRef.__PVT__bucketFirstStore_2_1 = 0ULL;
            vlSelfRef.__PVT__bucketFirstStore_2_2 = 0ULL;
            vlSelfRef.__PVT__bucketFirstStore_2_3 = 0ULL;
        } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
            if (vlSelfRef.__PVT__isCurrent_2) {
                vlSelfRef.__PVT__bucketFirstStore_2_0 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_8[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_8[0U])));
                vlSelfRef.__PVT__bucketFirstStore_2_1 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_9[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_9[0U])));
                vlSelfRef.__PVT__bucketFirstStore_2_2 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_10[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_10[0U])));
                vlSelfRef.__PVT__bucketFirstStore_2_3 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_11[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_11[0U])));
            }
        }
        if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
               & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
              & (IData)(vlSelfRef.__PVT__isRetiring_4)) 
             & (IData)(vlSelfRef.__PVT__bucketValid_4))) {
            vlSelfRef.__PVT__bucketStore_4_0 = 0ULL;
            vlSelfRef.__PVT__bucketStore_4_1 = 0ULL;
            vlSelfRef.__PVT__bucketStore_4_2 = 0ULL;
            vlSelfRef.__PVT__bucketStore_4_3 = 0ULL;
        } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
            if (vlSelfRef.__PVT__isCurrent_4) {
                vlSelfRef.__PVT__bucketStore_4_0 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_16[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_16[0U])));
                vlSelfRef.__PVT__bucketStore_4_1 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_17[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_17[0U])));
                vlSelfRef.__PVT__bucketStore_4_2 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_18[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_18[0U])));
                vlSelfRef.__PVT__bucketStore_4_3 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_19[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_19[0U])));
            }
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__102(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__102\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketLoadFirst_4_0 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_4_1 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_4_2 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_4_3 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_4_0 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_4_1 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring_4)) 
                & (IData)(vlSelfRef.__PVT__bucketValid_4))) {
        vlSelfRef.__PVT__bucketLoadFirst_4_0 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_4_1 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_4_2 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_4_3 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_4_0 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_4_1 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (((IData)(vlSelfRef.__PVT__isCurrent_4) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2057)))) {
            vlSelfRef.__PVT__bucketLoadFirst_4_0 = 
                ((IData)(vlSelfRef.__PVT__allocate_4)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2057))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_16[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_16[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_4) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2096)))) {
            vlSelfRef.__PVT__bucketLoadFirst_4_1 = 
                ((IData)(vlSelfRef.__PVT__allocate_4)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2096))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_17[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_17[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_4) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2137)))) {
            vlSelfRef.__PVT__bucketLoadFirst_4_2 = 
                ((IData)(vlSelfRef.__PVT__allocate_4)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2137))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_18[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_18[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_4) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2178)))) {
            vlSelfRef.__PVT__bucketLoadFirst_4_3 = 
                ((IData)(vlSelfRef.__PVT__allocate_4)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2178))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_19[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_19[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_4) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_2057)))) {
            vlSelfRef.__PVT__bucketStoreFirst_4_0 = 
                ((IData)(vlSelfRef.__PVT__allocate_4)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_2057))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_16[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_16[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_4) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_2096)))) {
            vlSelfRef.__PVT__bucketStoreFirst_4_1 = 
                ((IData)(vlSelfRef.__PVT__allocate_4)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_2096))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_17[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_17[0U]))));
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__103(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__103\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketStoreFirst_4_2 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_4_3 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_4_0 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_4_1 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_4_2 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_4_3 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring_4)) 
                & (IData)(vlSelfRef.__PVT__bucketValid_4))) {
        vlSelfRef.__PVT__bucketStoreFirst_4_2 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_4_3 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_4_0 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_4_1 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_4_2 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_4_3 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (((IData)(vlSelfRef.__PVT__isCurrent_4) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_2137)))) {
            vlSelfRef.__PVT__bucketStoreFirst_4_2 = 
                ((IData)(vlSelfRef.__PVT__allocate_4)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_2137))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_18[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_18[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_4) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_2178)))) {
            vlSelfRef.__PVT__bucketStoreFirst_4_3 = 
                ((IData)(vlSelfRef.__PVT__allocate_4)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_2178))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_19[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_19[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_4) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_21030)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_4_0 
                = ((IData)(vlSelfRef.__PVT__allocate_4)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_21030))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_16[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_16[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_4) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_21446)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_4_1 
                = ((IData)(vlSelfRef.__PVT__allocate_4)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_21446))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_17[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_17[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_4) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_21882)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_4_2 
                = ((IData)(vlSelfRef.__PVT__allocate_4)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_21882))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_18[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_18[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_4) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_22318)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_4_3 
                = ((IData)(vlSelfRef.__PVT__allocate_4)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_22318))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_19[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_19[0U]))));
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__104(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__104\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketFirstStore_4_0 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_4_1 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_4_2 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_4_3 = 0ULL;
        vlSelfRef.__PVT__bucketStore_5_0 = 0ULL;
        vlSelfRef.__PVT__bucketStore_5_1 = 0ULL;
        vlSelfRef.__PVT__bucketStore_5_2 = 0ULL;
        vlSelfRef.__PVT__bucketStore_5_3 = 0ULL;
    } else {
        if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
               & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
              & (IData)(vlSelfRef.__PVT__isRetiring_4)) 
             & (IData)(vlSelfRef.__PVT__bucketValid_4))) {
            vlSelfRef.__PVT__bucketFirstStore_4_0 = 0ULL;
            vlSelfRef.__PVT__bucketFirstStore_4_1 = 0ULL;
            vlSelfRef.__PVT__bucketFirstStore_4_2 = 0ULL;
            vlSelfRef.__PVT__bucketFirstStore_4_3 = 0ULL;
        } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
            if (vlSelfRef.__PVT__isCurrent_4) {
                vlSelfRef.__PVT__bucketFirstStore_4_0 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_16[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_16[0U])));
                vlSelfRef.__PVT__bucketFirstStore_4_1 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_17[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_17[0U])));
                vlSelfRef.__PVT__bucketFirstStore_4_2 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_18[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_18[0U])));
                vlSelfRef.__PVT__bucketFirstStore_4_3 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_19[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_19[0U])));
            }
        }
        if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
               & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
              & (IData)(vlSelfRef.__PVT__isRetiring_5)) 
             & (IData)(vlSelfRef.__PVT__bucketValid_5))) {
            vlSelfRef.__PVT__bucketStore_5_0 = 0ULL;
            vlSelfRef.__PVT__bucketStore_5_1 = 0ULL;
            vlSelfRef.__PVT__bucketStore_5_2 = 0ULL;
            vlSelfRef.__PVT__bucketStore_5_3 = 0ULL;
        } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
            if (vlSelfRef.__PVT__isCurrent_5) {
                vlSelfRef.__PVT__bucketStore_5_0 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_20[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_20[0U])));
                vlSelfRef.__PVT__bucketStore_5_1 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_21[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_21[0U])));
                vlSelfRef.__PVT__bucketStore_5_2 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_22[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_22[0U])));
                vlSelfRef.__PVT__bucketStore_5_3 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_23[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_23[0U])));
            }
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__105(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__105\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketLoadFirst_5_0 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_5_1 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_5_2 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_5_3 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_5_0 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_5_1 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring_5)) 
                & (IData)(vlSelfRef.__PVT__bucketValid_5))) {
        vlSelfRef.__PVT__bucketLoadFirst_5_0 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_5_1 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_5_2 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_5_3 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_5_0 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_5_1 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (((IData)(vlSelfRef.__PVT__isCurrent_5) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2493)))) {
            vlSelfRef.__PVT__bucketLoadFirst_5_0 = 
                ((IData)(vlSelfRef.__PVT__allocate_5)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2493))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_20[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_20[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_5) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2532)))) {
            vlSelfRef.__PVT__bucketLoadFirst_5_1 = 
                ((IData)(vlSelfRef.__PVT__allocate_5)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2532))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_21[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_21[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_5) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2573)))) {
            vlSelfRef.__PVT__bucketLoadFirst_5_2 = 
                ((IData)(vlSelfRef.__PVT__allocate_5)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2573))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_22[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_22[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_5) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2614)))) {
            vlSelfRef.__PVT__bucketLoadFirst_5_3 = 
                ((IData)(vlSelfRef.__PVT__allocate_5)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2614))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_23[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_23[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_5) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_2493)))) {
            vlSelfRef.__PVT__bucketStoreFirst_5_0 = 
                ((IData)(vlSelfRef.__PVT__allocate_5)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_2493))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_20[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_20[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_5) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_2532)))) {
            vlSelfRef.__PVT__bucketStoreFirst_5_1 = 
                ((IData)(vlSelfRef.__PVT__allocate_5)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_2532))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_21[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_21[0U]))));
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__106(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__106\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketStoreFirst_5_2 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_5_3 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_5_0 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_5_1 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_5_2 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_5_3 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring_5)) 
                & (IData)(vlSelfRef.__PVT__bucketValid_5))) {
        vlSelfRef.__PVT__bucketStoreFirst_5_2 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_5_3 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_5_0 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_5_1 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_5_2 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_5_3 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (((IData)(vlSelfRef.__PVT__isCurrent_5) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_2573)))) {
            vlSelfRef.__PVT__bucketStoreFirst_5_2 = 
                ((IData)(vlSelfRef.__PVT__allocate_5)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_2573))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_22[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_22[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_5) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_2614)))) {
            vlSelfRef.__PVT__bucketStoreFirst_5_3 = 
                ((IData)(vlSelfRef.__PVT__allocate_5)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_2614))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_23[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_23[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_5) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25494)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_5_0 
                = ((IData)(vlSelfRef.__PVT__allocate_5)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25494))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_20[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_20[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_5) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25910)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_5_1 
                = ((IData)(vlSelfRef.__PVT__allocate_5)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25910))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_21[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_21[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_5) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_26346)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_5_2 
                = ((IData)(vlSelfRef.__PVT__allocate_5)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_26346))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_22[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_22[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_5) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_26782)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_5_3 
                = ((IData)(vlSelfRef.__PVT__allocate_5)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_26782))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_23[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_23[0U]))));
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__107(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__107\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketFirstStore_5_0 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_5_1 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_5_2 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_5_3 = 0ULL;
        vlSelfRef.__PVT__bucketStore_1_0 = 0ULL;
        vlSelfRef.__PVT__bucketStore_1_1 = 0ULL;
        vlSelfRef.__PVT__bucketStore_1_2 = 0ULL;
        vlSelfRef.__PVT__bucketStore_1_3 = 0ULL;
    } else {
        if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
               & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
              & (IData)(vlSelfRef.__PVT__isRetiring_5)) 
             & (IData)(vlSelfRef.__PVT__bucketValid_5))) {
            vlSelfRef.__PVT__bucketFirstStore_5_0 = 0ULL;
            vlSelfRef.__PVT__bucketFirstStore_5_1 = 0ULL;
            vlSelfRef.__PVT__bucketFirstStore_5_2 = 0ULL;
            vlSelfRef.__PVT__bucketFirstStore_5_3 = 0ULL;
        } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
            if (vlSelfRef.__PVT__isCurrent_5) {
                vlSelfRef.__PVT__bucketFirstStore_5_0 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_20[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_20[0U])));
                vlSelfRef.__PVT__bucketFirstStore_5_1 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_21[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_21[0U])));
                vlSelfRef.__PVT__bucketFirstStore_5_2 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_22[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_22[0U])));
                vlSelfRef.__PVT__bucketFirstStore_5_3 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_23[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_23[0U])));
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
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__108(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__108\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketLoadFirst_1_0 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_1_1 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_1_2 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_1_3 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_1_0 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_1_1 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring_1)) 
                & (IData)(vlSelfRef.__PVT__bucketValid_1))) {
        vlSelfRef.__PVT__bucketLoadFirst_1_0 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_1_1 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_1_2 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_1_3 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_1_0 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_1_1 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (((IData)(vlSelfRef.__PVT__isCurrent_1) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_749)))) {
            vlSelfRef.__PVT__bucketLoadFirst_1_0 = 
                ((IData)(vlSelfRef.__PVT__allocate_1)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_749))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_4[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_4[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_1) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_788)))) {
            vlSelfRef.__PVT__bucketLoadFirst_1_1 = 
                ((IData)(vlSelfRef.__PVT__allocate_1)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_788))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_5[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_5[0U]))));
        }
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
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__109(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__109\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketStoreFirst_1_2 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_1_3 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_1_0 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_1_1 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_1_2 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_1_3 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring_1)) 
                & (IData)(vlSelfRef.__PVT__bucketValid_1))) {
        vlSelfRef.__PVT__bucketStoreFirst_1_2 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_1_3 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_1_0 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_1_1 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_1_2 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_1_3 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
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
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__110(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__110\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketFirstStore_1_0 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_1_1 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_1_2 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_1_3 = 0ULL;
        vlSelfRef.bucketStore_7_0 = 0ULL;
        vlSelfRef.bucketStore_7_1 = 0ULL;
        vlSelfRef.bucketStore_7_2 = 0ULL;
        vlSelfRef.bucketStore_7_3 = 0ULL;
    } else {
        if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
               & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
              & (IData)(vlSelfRef.__PVT__isRetiring_1)) 
             & (IData)(vlSelfRef.__PVT__bucketValid_1))) {
            vlSelfRef.__PVT__bucketFirstStore_1_0 = 0ULL;
            vlSelfRef.__PVT__bucketFirstStore_1_1 = 0ULL;
            vlSelfRef.__PVT__bucketFirstStore_1_2 = 0ULL;
            vlSelfRef.__PVT__bucketFirstStore_1_3 = 0ULL;
        } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
            if (vlSelfRef.__PVT__isCurrent_1) {
                vlSelfRef.__PVT__bucketFirstStore_1_0 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_4[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_4[0U])));
                vlSelfRef.__PVT__bucketFirstStore_1_1 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_5[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_5[0U])));
                vlSelfRef.__PVT__bucketFirstStore_1_2 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_6[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_6[0U])));
                vlSelfRef.__PVT__bucketFirstStore_1_3 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_7[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_7[0U])));
            }
        }
        if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
               & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
              & (IData)(vlSelfRef.__PVT__isRetiring_7)) 
             & (IData)(vlSelfRef.bucketValid_7))) {
            vlSelfRef.bucketStore_7_0 = 0ULL;
            vlSelfRef.bucketStore_7_1 = 0ULL;
            vlSelfRef.bucketStore_7_2 = 0ULL;
            vlSelfRef.bucketStore_7_3 = 0ULL;
        } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
            if (vlSelfRef.__PVT__isCurrent_7) {
                vlSelfRef.bucketStore_7_0 = (((QData)((IData)(
                                                              vlSelfRef.__PVT__currentStoreNextWide_28[1U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSelfRef.__PVT__currentStoreNextWide_28[0U])));
                vlSelfRef.bucketStore_7_1 = (((QData)((IData)(
                                                              vlSelfRef.__PVT__currentStoreNextWide_29[1U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSelfRef.__PVT__currentStoreNextWide_29[0U])));
                vlSelfRef.bucketStore_7_2 = (((QData)((IData)(
                                                              vlSelfRef.__PVT__currentStoreNextWide_30[1U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSelfRef.__PVT__currentStoreNextWide_30[0U])));
                vlSelfRef.bucketStore_7_3 = (((QData)((IData)(
                                                              vlSelfRef.__PVT__currentStoreNextWide_31[1U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSelfRef.__PVT__currentStoreNextWide_31[0U])));
            }
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__111(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__111\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.bucketLoadFirst_7_0 = 0ULL;
        vlSelfRef.bucketLoadFirst_7_1 = 0ULL;
        vlSelfRef.bucketLoadFirst_7_2 = 0ULL;
        vlSelfRef.bucketLoadFirst_7_3 = 0ULL;
        vlSelfRef.bucketStoreFirst_7_0 = 0ULL;
        vlSelfRef.bucketStoreFirst_7_1 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring_7)) 
                & (IData)(vlSelfRef.bucketValid_7))) {
        vlSelfRef.bucketLoadFirst_7_0 = 0ULL;
        vlSelfRef.bucketLoadFirst_7_1 = 0ULL;
        vlSelfRef.bucketLoadFirst_7_2 = 0ULL;
        vlSelfRef.bucketLoadFirst_7_3 = 0ULL;
        vlSelfRef.bucketStoreFirst_7_0 = 0ULL;
        vlSelfRef.bucketStoreFirst_7_1 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (((IData)(vlSelfRef.__PVT__isCurrent_7) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3365)))) {
            vlSelfRef.bucketLoadFirst_7_0 = ((IData)(vlSelfRef.__PVT__allocate_7)
                                              ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3365))
                                              : (((QData)((IData)(
                                                                  vlSelfRef.__PVT__loadFirstNextWide_28[1U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelfRef.__PVT__loadFirstNextWide_28[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_7) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3404)))) {
            vlSelfRef.bucketLoadFirst_7_1 = ((IData)(vlSelfRef.__PVT__allocate_7)
                                              ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3404))
                                              : (((QData)((IData)(
                                                                  vlSelfRef.__PVT__loadFirstNextWide_29[1U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelfRef.__PVT__loadFirstNextWide_29[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_7) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3445)))) {
            vlSelfRef.bucketLoadFirst_7_2 = ((IData)(vlSelfRef.__PVT__allocate_7)
                                              ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3445))
                                              : (((QData)((IData)(
                                                                  vlSelfRef.__PVT__loadFirstNextWide_30[1U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelfRef.__PVT__loadFirstNextWide_30[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_7) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3486)))) {
            vlSelfRef.bucketLoadFirst_7_3 = ((IData)(vlSelfRef.__PVT__allocate_7)
                                              ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3486))
                                              : (((QData)((IData)(
                                                                  vlSelfRef.__PVT__loadFirstNextWide_31[1U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelfRef.__PVT__loadFirstNextWide_31[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_7) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_3365)))) {
            vlSelfRef.bucketStoreFirst_7_0 = ((IData)(vlSelfRef.__PVT__allocate_7)
                                               ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_3365))
                                               : (((QData)((IData)(
                                                                   vlSelfRef.__PVT__storeFirstNextWide_28[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.__PVT__storeFirstNextWide_28[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_7) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_3404)))) {
            vlSelfRef.bucketStoreFirst_7_1 = ((IData)(vlSelfRef.__PVT__allocate_7)
                                               ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_3404))
                                               : (((QData)((IData)(
                                                                   vlSelfRef.__PVT__storeFirstNextWide_29[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.__PVT__storeFirstNextWide_29[0U]))));
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__112(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__112\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.bucketStoreFirst_7_2 = 0ULL;
        vlSelfRef.bucketStoreFirst_7_3 = 0ULL;
        vlSelfRef.bucketStrictWriteRead_7_0 = 0ULL;
        vlSelfRef.bucketStrictWriteRead_7_1 = 0ULL;
        vlSelfRef.bucketStrictWriteRead_7_2 = 0ULL;
        vlSelfRef.bucketStrictWriteRead_7_3 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring_7)) 
                & (IData)(vlSelfRef.bucketValid_7))) {
        vlSelfRef.bucketStoreFirst_7_2 = 0ULL;
        vlSelfRef.bucketStoreFirst_7_3 = 0ULL;
        vlSelfRef.bucketStrictWriteRead_7_0 = 0ULL;
        vlSelfRef.bucketStrictWriteRead_7_1 = 0ULL;
        vlSelfRef.bucketStrictWriteRead_7_2 = 0ULL;
        vlSelfRef.bucketStrictWriteRead_7_3 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (((IData)(vlSelfRef.__PVT__isCurrent_7) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_3445)))) {
            vlSelfRef.bucketStoreFirst_7_2 = ((IData)(vlSelfRef.__PVT__allocate_7)
                                               ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_3445))
                                               : (((QData)((IData)(
                                                                   vlSelfRef.__PVT__storeFirstNextWide_30[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.__PVT__storeFirstNextWide_30[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_7) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_3486)))) {
            vlSelfRef.bucketStoreFirst_7_3 = ((IData)(vlSelfRef.__PVT__allocate_7)
                                               ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_3486))
                                               : (((QData)((IData)(
                                                                   vlSelfRef.__PVT__storeFirstNextWide_31[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.__PVT__storeFirstNextWide_31[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_7) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34422)))) {
            vlSelfRef.bucketStrictWriteRead_7_0 = ((IData)(vlSelfRef.__PVT__allocate_7)
                                                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34422))
                                                    : 
                                                   (((QData)((IData)(
                                                                     vlSelfRef.__PVT__strictWriteReadNextWide_28[1U])) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      vlSelfRef.__PVT__strictWriteReadNextWide_28[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_7) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34838)))) {
            vlSelfRef.bucketStrictWriteRead_7_1 = ((IData)(vlSelfRef.__PVT__allocate_7)
                                                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34838))
                                                    : 
                                                   (((QData)((IData)(
                                                                     vlSelfRef.__PVT__strictWriteReadNextWide_29[1U])) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      vlSelfRef.__PVT__strictWriteReadNextWide_29[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_7) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_35274)))) {
            vlSelfRef.bucketStrictWriteRead_7_2 = ((IData)(vlSelfRef.__PVT__allocate_7)
                                                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_35274))
                                                    : 
                                                   (((QData)((IData)(
                                                                     vlSelfRef.__PVT__strictWriteReadNextWide_30[1U])) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      vlSelfRef.__PVT__strictWriteReadNextWide_30[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_7) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_35710)))) {
            vlSelfRef.bucketStrictWriteRead_7_3 = ((IData)(vlSelfRef.__PVT__allocate_7)
                                                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_35710))
                                                    : 
                                                   (((QData)((IData)(
                                                                     vlSelfRef.__PVT__strictWriteReadNextWide_31[1U])) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      vlSelfRef.__PVT__strictWriteReadNextWide_31[0U]))));
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__113(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__113\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.bucketFirstStore_7_0 = 0ULL;
        vlSelfRef.bucketFirstStore_7_1 = 0ULL;
        vlSelfRef.bucketFirstStore_7_2 = 0ULL;
        vlSelfRef.bucketFirstStore_7_3 = 0ULL;
        vlSelfRef.__PVT__bucketStore_6_0 = 0ULL;
        vlSelfRef.__PVT__bucketStore_6_1 = 0ULL;
        vlSelfRef.__PVT__bucketStore_6_2 = 0ULL;
        vlSelfRef.__PVT__bucketStore_6_3 = 0ULL;
    } else {
        if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
               & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
              & (IData)(vlSelfRef.__PVT__isRetiring_7)) 
             & (IData)(vlSelfRef.bucketValid_7))) {
            vlSelfRef.bucketFirstStore_7_0 = 0ULL;
            vlSelfRef.bucketFirstStore_7_1 = 0ULL;
            vlSelfRef.bucketFirstStore_7_2 = 0ULL;
            vlSelfRef.bucketFirstStore_7_3 = 0ULL;
        } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
            if (vlSelfRef.__PVT__isCurrent_7) {
                vlSelfRef.bucketFirstStore_7_0 = (((QData)((IData)(
                                                                   vlSelfRef.__PVT__currentFirstStoreNextWide_28[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_28[0U])));
                vlSelfRef.bucketFirstStore_7_1 = (((QData)((IData)(
                                                                   vlSelfRef.__PVT__currentFirstStoreNextWide_29[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_29[0U])));
                vlSelfRef.bucketFirstStore_7_2 = (((QData)((IData)(
                                                                   vlSelfRef.__PVT__currentFirstStoreNextWide_30[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_30[0U])));
                vlSelfRef.bucketFirstStore_7_3 = (((QData)((IData)(
                                                                   vlSelfRef.__PVT__currentFirstStoreNextWide_31[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_31[0U])));
            }
        }
        if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
               & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
              & (IData)(vlSelfRef.__PVT__isRetiring_6)) 
             & (IData)(vlSelfRef.__PVT__bucketValid_6))) {
            vlSelfRef.__PVT__bucketStore_6_0 = 0ULL;
            vlSelfRef.__PVT__bucketStore_6_1 = 0ULL;
            vlSelfRef.__PVT__bucketStore_6_2 = 0ULL;
            vlSelfRef.__PVT__bucketStore_6_3 = 0ULL;
        } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
            if (vlSelfRef.__PVT__isCurrent_6) {
                vlSelfRef.__PVT__bucketStore_6_0 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_24[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_24[0U])));
                vlSelfRef.__PVT__bucketStore_6_1 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_25[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_25[0U])));
                vlSelfRef.__PVT__bucketStore_6_2 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_26[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_26[0U])));
                vlSelfRef.__PVT__bucketStore_6_3 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_27[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_27[0U])));
            }
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__114(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__114\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketLoadFirst_6_0 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_6_1 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_6_2 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_6_3 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_6_0 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_6_1 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring_6)) 
                & (IData)(vlSelfRef.__PVT__bucketValid_6))) {
        vlSelfRef.__PVT__bucketLoadFirst_6_0 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_6_1 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_6_2 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_6_3 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_6_0 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_6_1 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (((IData)(vlSelfRef.__PVT__isCurrent_6) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2929)))) {
            vlSelfRef.__PVT__bucketLoadFirst_6_0 = 
                ((IData)(vlSelfRef.__PVT__allocate_6)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2929))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_24[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_24[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_6) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2968)))) {
            vlSelfRef.__PVT__bucketLoadFirst_6_1 = 
                ((IData)(vlSelfRef.__PVT__allocate_6)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_2968))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_25[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_25[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_6) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3009)))) {
            vlSelfRef.__PVT__bucketLoadFirst_6_2 = 
                ((IData)(vlSelfRef.__PVT__allocate_6)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3009))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_26[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_26[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_6) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3050)))) {
            vlSelfRef.__PVT__bucketLoadFirst_6_3 = 
                ((IData)(vlSelfRef.__PVT__allocate_6)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_3050))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_27[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_27[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_6) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_2929)))) {
            vlSelfRef.__PVT__bucketStoreFirst_6_0 = 
                ((IData)(vlSelfRef.__PVT__allocate_6)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_2929))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_24[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_24[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_6) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_2968)))) {
            vlSelfRef.__PVT__bucketStoreFirst_6_1 = 
                ((IData)(vlSelfRef.__PVT__allocate_6)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_2968))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_25[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_25[0U]))));
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__115(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__115\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketStoreFirst_6_2 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_6_3 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_6_0 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_6_1 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_6_2 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_6_3 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring_6)) 
                & (IData)(vlSelfRef.__PVT__bucketValid_6))) {
        vlSelfRef.__PVT__bucketStoreFirst_6_2 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_6_3 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_6_0 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_6_1 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_6_2 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_6_3 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (((IData)(vlSelfRef.__PVT__isCurrent_6) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_3009)))) {
            vlSelfRef.__PVT__bucketStoreFirst_6_2 = 
                ((IData)(vlSelfRef.__PVT__allocate_6)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_3009))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_26[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_26[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_6) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_3050)))) {
            vlSelfRef.__PVT__bucketStoreFirst_6_3 = 
                ((IData)(vlSelfRef.__PVT__allocate_6)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_3050))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_27[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_27[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_6) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29958)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_6_0 
                = ((IData)(vlSelfRef.__PVT__allocate_6)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29958))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_24[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_24[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_6) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_30374)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_6_1 
                = ((IData)(vlSelfRef.__PVT__allocate_6)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_30374))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_25[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_25[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_6) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_30810)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_6_2 
                = ((IData)(vlSelfRef.__PVT__allocate_6)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_30810))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_26[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_26[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_6) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_31246)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_6_3 
                = ((IData)(vlSelfRef.__PVT__allocate_6)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_31246))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_27[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_27[0U]))));
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__116(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__116\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketFirstStore_6_0 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_6_1 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_6_2 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_6_3 = 0ULL;
        vlSelfRef.__PVT__bucketStore_3_0 = 0ULL;
        vlSelfRef.__PVT__bucketStore_3_1 = 0ULL;
        vlSelfRef.__PVT__bucketStore_3_2 = 0ULL;
        vlSelfRef.__PVT__bucketStore_3_3 = 0ULL;
    } else {
        if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
               & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
              & (IData)(vlSelfRef.__PVT__isRetiring_6)) 
             & (IData)(vlSelfRef.__PVT__bucketValid_6))) {
            vlSelfRef.__PVT__bucketFirstStore_6_0 = 0ULL;
            vlSelfRef.__PVT__bucketFirstStore_6_1 = 0ULL;
            vlSelfRef.__PVT__bucketFirstStore_6_2 = 0ULL;
            vlSelfRef.__PVT__bucketFirstStore_6_3 = 0ULL;
        } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
            if (vlSelfRef.__PVT__isCurrent_6) {
                vlSelfRef.__PVT__bucketFirstStore_6_0 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_24[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_24[0U])));
                vlSelfRef.__PVT__bucketFirstStore_6_1 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_25[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_25[0U])));
                vlSelfRef.__PVT__bucketFirstStore_6_2 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_26[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_26[0U])));
                vlSelfRef.__PVT__bucketFirstStore_6_3 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_27[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_27[0U])));
            }
        }
        if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
               & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
              & (IData)(vlSelfRef.__PVT__isRetiring_3)) 
             & (IData)(vlSelfRef.__PVT__bucketValid_3))) {
            vlSelfRef.__PVT__bucketStore_3_0 = 0ULL;
            vlSelfRef.__PVT__bucketStore_3_1 = 0ULL;
            vlSelfRef.__PVT__bucketStore_3_2 = 0ULL;
            vlSelfRef.__PVT__bucketStore_3_3 = 0ULL;
        } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
            if (vlSelfRef.__PVT__isCurrent_3) {
                vlSelfRef.__PVT__bucketStore_3_0 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_12[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_12[0U])));
                vlSelfRef.__PVT__bucketStore_3_1 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_13[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_13[0U])));
                vlSelfRef.__PVT__bucketStore_3_2 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_14[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_14[0U])));
                vlSelfRef.__PVT__bucketStore_3_3 = 
                    (((QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_15[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__currentStoreNextWide_15[0U])));
            }
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__117(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__117\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketLoadFirst_3_0 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_3_1 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_3_2 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_3_3 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_3_0 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_3_1 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring_3)) 
                & (IData)(vlSelfRef.__PVT__bucketValid_3))) {
        vlSelfRef.__PVT__bucketLoadFirst_3_0 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_3_1 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_3_2 = 0ULL;
        vlSelfRef.__PVT__bucketLoadFirst_3_3 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_3_0 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_3_1 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (((IData)(vlSelfRef.__PVT__isCurrent_3) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1621)))) {
            vlSelfRef.__PVT__bucketLoadFirst_3_0 = 
                ((IData)(vlSelfRef.__PVT__allocate_3)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1621))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_12[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_12[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_3) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1660)))) {
            vlSelfRef.__PVT__bucketLoadFirst_3_1 = 
                ((IData)(vlSelfRef.__PVT__allocate_3)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1660))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_13[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_13[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_3) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1701)))) {
            vlSelfRef.__PVT__bucketLoadFirst_3_2 = 
                ((IData)(vlSelfRef.__PVT__allocate_3)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1701))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_14[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_14[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_3) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1742)))) {
            vlSelfRef.__PVT__bucketLoadFirst_3_3 = 
                ((IData)(vlSelfRef.__PVT__allocate_3)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_1742))
                  : (((QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_15[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__loadFirstNextWide_15[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_3) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1621)))) {
            vlSelfRef.__PVT__bucketStoreFirst_3_0 = 
                ((IData)(vlSelfRef.__PVT__allocate_3)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1621))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_12[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_12[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_3) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1660)))) {
            vlSelfRef.__PVT__bucketStoreFirst_3_1 = 
                ((IData)(vlSelfRef.__PVT__allocate_3)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1660))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_13[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_13[0U]))));
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__118(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__118\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketStoreFirst_3_2 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_3_3 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_3_0 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_3_1 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_3_2 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_3_3 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring_3)) 
                & (IData)(vlSelfRef.__PVT__bucketValid_3))) {
        vlSelfRef.__PVT__bucketStoreFirst_3_2 = 0ULL;
        vlSelfRef.__PVT__bucketStoreFirst_3_3 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_3_0 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_3_1 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_3_2 = 0ULL;
        vlSelfRef.__PVT__bucketStrictWriteRead_3_3 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (((IData)(vlSelfRef.__PVT__isCurrent_3) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1701)))) {
            vlSelfRef.__PVT__bucketStoreFirst_3_2 = 
                ((IData)(vlSelfRef.__PVT__allocate_3)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1701))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_14[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_14[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_3) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1742)))) {
            vlSelfRef.__PVT__bucketStoreFirst_3_3 = 
                ((IData)(vlSelfRef.__PVT__allocate_3)
                  ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1742))
                  : (((QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_15[1U])) 
                      << 0x20U) | (QData)((IData)(vlSelfRef.__PVT__storeFirstNextWide_15[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_3) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16566)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_3_0 
                = ((IData)(vlSelfRef.__PVT__allocate_3)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16566))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_12[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_12[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_3) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16982)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_3_1 
                = ((IData)(vlSelfRef.__PVT__allocate_3)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16982))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_13[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_13[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_3) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_17418)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_3_2 
                = ((IData)(vlSelfRef.__PVT__allocate_3)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_17418))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_14[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_14[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent_3) 
             | (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_17854)))) {
            vlSelfRef.__PVT__bucketStrictWriteRead_3_3 
                = ((IData)(vlSelfRef.__PVT__allocate_3)
                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_17854))
                    : (((QData)((IData)(vlSelfRef.__PVT__strictWriteReadNextWide_15[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__strictWriteReadNextWide_15[0U]))));
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__119(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__119\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__bucketFirstStore_3_0 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_3_1 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_3_2 = 0ULL;
        vlSelfRef.__PVT__bucketFirstStore_3_3 = 0ULL;
        vlSelfRef.bucketStore_0_0 = 0ULL;
        vlSelfRef.bucketStore_0_1 = 0ULL;
        vlSelfRef.bucketStore_0_2 = 0ULL;
        vlSelfRef.bucketStore_0_3 = 0ULL;
    } else {
        if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
               & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
              & (IData)(vlSelfRef.__PVT__isRetiring_3)) 
             & (IData)(vlSelfRef.__PVT__bucketValid_3))) {
            vlSelfRef.__PVT__bucketFirstStore_3_0 = 0ULL;
            vlSelfRef.__PVT__bucketFirstStore_3_1 = 0ULL;
            vlSelfRef.__PVT__bucketFirstStore_3_2 = 0ULL;
            vlSelfRef.__PVT__bucketFirstStore_3_3 = 0ULL;
        } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
            if (vlSelfRef.__PVT__isCurrent_3) {
                vlSelfRef.__PVT__bucketFirstStore_3_0 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_12[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_12[0U])));
                vlSelfRef.__PVT__bucketFirstStore_3_1 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_13[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_13[0U])));
                vlSelfRef.__PVT__bucketFirstStore_3_2 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_14[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_14[0U])));
                vlSelfRef.__PVT__bucketFirstStore_3_3 
                    = (((QData)((IData)(vlSelfRef.__PVT__currentFirstStoreNextWide_15[1U])) 
                        << 0x20U) | (QData)((IData)(
                                                    vlSelfRef.__PVT__currentFirstStoreNextWide_15[0U])));
            }
        }
        if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
               & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
              & (IData)(vlSelfRef.__PVT__isRetiring)) 
             & (IData)(vlSelfRef.bucketValid_0))) {
            vlSelfRef.bucketStore_0_0 = 0ULL;
            vlSelfRef.bucketStore_0_1 = 0ULL;
            vlSelfRef.bucketStore_0_2 = 0ULL;
            vlSelfRef.bucketStore_0_3 = 0ULL;
        } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
            if (vlSelfRef.__PVT__isCurrent) {
                vlSelfRef.bucketStore_0_0 = (((QData)((IData)(
                                                              vlSelfRef.__PVT__currentStoreNextWide[1U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSelfRef.__PVT__currentStoreNextWide[0U])));
                vlSelfRef.bucketStore_0_1 = (((QData)((IData)(
                                                              vlSelfRef.__PVT__currentStoreNextWide_1[1U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSelfRef.__PVT__currentStoreNextWide_1[0U])));
                vlSelfRef.bucketStore_0_2 = (((QData)((IData)(
                                                              vlSelfRef.__PVT__currentStoreNextWide_2[1U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSelfRef.__PVT__currentStoreNextWide_2[0U])));
                vlSelfRef.bucketStore_0_3 = (((QData)((IData)(
                                                              vlSelfRef.__PVT__currentStoreNextWide_3[1U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSelfRef.__PVT__currentStoreNextWide_3[0U])));
            }
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__120(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__120\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.bucketLoadFirst_0_0 = 0ULL;
        vlSelfRef.bucketLoadFirst_0_1 = 0ULL;
        vlSelfRef.bucketLoadFirst_0_2 = 0ULL;
        vlSelfRef.bucketLoadFirst_0_3 = 0ULL;
        vlSelfRef.bucketStoreFirst_0_0 = 0ULL;
        vlSelfRef.bucketStoreFirst_0_1 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring)) 
                & (IData)(vlSelfRef.bucketValid_0))) {
        vlSelfRef.bucketLoadFirst_0_0 = 0ULL;
        vlSelfRef.bucketLoadFirst_0_1 = 0ULL;
        vlSelfRef.bucketLoadFirst_0_2 = 0ULL;
        vlSelfRef.bucketLoadFirst_0_3 = 0ULL;
        vlSelfRef.bucketStoreFirst_0_0 = 0ULL;
        vlSelfRef.bucketStoreFirst_0_1 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (((IData)(vlSelfRef.__PVT__isCurrent) | 
             (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_313)))) {
            vlSelfRef.bucketLoadFirst_0_0 = ((IData)(vlSelfRef.__PVT__allocate)
                                              ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_313))
                                              : (((QData)((IData)(
                                                                  vlSelfRef.__PVT__loadFirstNextWide[1U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelfRef.__PVT__loadFirstNextWide[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent) | 
             (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_352)))) {
            vlSelfRef.bucketLoadFirst_0_1 = ((IData)(vlSelfRef.__PVT__allocate)
                                              ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_352))
                                              : (((QData)((IData)(
                                                                  vlSelfRef.__PVT__loadFirstNextWide_1[1U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelfRef.__PVT__loadFirstNextWide_1[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent) | 
             (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_393)))) {
            vlSelfRef.bucketLoadFirst_0_2 = ((IData)(vlSelfRef.__PVT__allocate)
                                              ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_393))
                                              : (((QData)((IData)(
                                                                  vlSelfRef.__PVT__loadFirstNextWide_2[1U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelfRef.__PVT__loadFirstNextWide_2[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent) | 
             (0U != (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_434)))) {
            vlSelfRef.bucketLoadFirst_0_3 = ((IData)(vlSelfRef.__PVT__allocate)
                                              ? (QData)((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_434))
                                              : (((QData)((IData)(
                                                                  vlSelfRef.__PVT__loadFirstNextWide_3[1U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelfRef.__PVT__loadFirstNextWide_3[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent) | 
             (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_313)))) {
            vlSelfRef.bucketStoreFirst_0_0 = ((IData)(vlSelfRef.__PVT__allocate)
                                               ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_313))
                                               : (((QData)((IData)(
                                                                   vlSelfRef.__PVT__storeFirstNextWide[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.__PVT__storeFirstNextWide[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent) | 
             (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_352)))) {
            vlSelfRef.bucketStoreFirst_0_1 = ((IData)(vlSelfRef.__PVT__allocate)
                                               ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_352))
                                               : (((QData)((IData)(
                                                                   vlSelfRef.__PVT__storeFirstNextWide_1[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.__PVT__storeFirstNextWide_1[0U]))));
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__121(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__121\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.bucketStoreFirst_0_2 = 0ULL;
        vlSelfRef.bucketStoreFirst_0_3 = 0ULL;
        vlSelfRef.bucketStrictWriteRead_0_0 = 0ULL;
        vlSelfRef.bucketStrictWriteRead_0_1 = 0ULL;
        vlSelfRef.bucketStrictWriteRead_0_2 = 0ULL;
        vlSelfRef.bucketStrictWriteRead_0_3 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring)) 
                & (IData)(vlSelfRef.bucketValid_0))) {
        vlSelfRef.bucketStoreFirst_0_2 = 0ULL;
        vlSelfRef.bucketStoreFirst_0_3 = 0ULL;
        vlSelfRef.bucketStrictWriteRead_0_0 = 0ULL;
        vlSelfRef.bucketStrictWriteRead_0_1 = 0ULL;
        vlSelfRef.bucketStrictWriteRead_0_2 = 0ULL;
        vlSelfRef.bucketStrictWriteRead_0_3 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (((IData)(vlSelfRef.__PVT__isCurrent) | 
             (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_393)))) {
            vlSelfRef.bucketStoreFirst_0_2 = ((IData)(vlSelfRef.__PVT__allocate)
                                               ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_393))
                                               : (((QData)((IData)(
                                                                   vlSelfRef.__PVT__storeFirstNextWide_2[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.__PVT__storeFirstNextWide_2[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent) | 
             (0U != (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_434)))) {
            vlSelfRef.bucketStoreFirst_0_3 = ((IData)(vlSelfRef.__PVT__allocate)
                                               ? (QData)((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_434))
                                               : (((QData)((IData)(
                                                                   vlSelfRef.__PVT__storeFirstNextWide_3[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelfRef.__PVT__storeFirstNextWide_3[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent) | 
             (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3174)))) {
            vlSelfRef.bucketStrictWriteRead_0_0 = ((IData)(vlSelfRef.__PVT__allocate)
                                                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3174))
                                                    : 
                                                   (((QData)((IData)(
                                                                     vlSelfRef.__PVT__strictWriteReadNextWide[1U])) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      vlSelfRef.__PVT__strictWriteReadNextWide[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent) | 
             (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3590)))) {
            vlSelfRef.bucketStrictWriteRead_0_1 = ((IData)(vlSelfRef.__PVT__allocate)
                                                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3590))
                                                    : 
                                                   (((QData)((IData)(
                                                                     vlSelfRef.__PVT__strictWriteReadNextWide_1[1U])) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      vlSelfRef.__PVT__strictWriteReadNextWide_1[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent) | 
             (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_4026)))) {
            vlSelfRef.bucketStrictWriteRead_0_2 = ((IData)(vlSelfRef.__PVT__allocate)
                                                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_4026))
                                                    : 
                                                   (((QData)((IData)(
                                                                     vlSelfRef.__PVT__strictWriteReadNextWide_2[1U])) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      vlSelfRef.__PVT__strictWriteReadNextWide_2[0U]))));
        }
        if (((IData)(vlSelfRef.__PVT__isCurrent) | 
             (0U != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_4462)))) {
            vlSelfRef.bucketStrictWriteRead_0_3 = ((IData)(vlSelfRef.__PVT__allocate)
                                                    ? (QData)((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_4462))
                                                    : 
                                                   (((QData)((IData)(
                                                                     vlSelfRef.__PVT__strictWriteReadNextWide_3[1U])) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      vlSelfRef.__PVT__strictWriteReadNextWide_3[0U]))));
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__122(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__122\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.bucketFirstStore_0_0 = 0ULL;
        vlSelfRef.bucketFirstStore_0_1 = 0ULL;
        vlSelfRef.bucketFirstStore_0_2 = 0ULL;
        vlSelfRef.bucketFirstStore_0_3 = 0ULL;
    } else if (((((IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance) 
                  & (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError))) 
                 & (IData)(vlSelfRef.__PVT__isRetiring)) 
                & (IData)(vlSelfRef.bucketValid_0))) {
        vlSelfRef.bucketFirstStore_0_0 = 0ULL;
        vlSelfRef.bucketFirstStore_0_1 = 0ULL;
        vlSelfRef.bucketFirstStore_0_2 = 0ULL;
        vlSelfRef.bucketFirstStore_0_3 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_processCommit) {
        if (vlSelfRef.__PVT__isCurrent) {
            vlSelfRef.bucketFirstStore_0_0 = (((QData)((IData)(
                                                               vlSelfRef.__PVT__currentFirstStoreNextWide[1U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlSelfRef.__PVT__currentFirstStoreNextWide[0U])));
            vlSelfRef.bucketFirstStore_0_1 = (((QData)((IData)(
                                                               vlSelfRef.__PVT__currentFirstStoreNextWide_1[1U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlSelfRef.__PVT__currentFirstStoreNextWide_1[0U])));
            vlSelfRef.bucketFirstStore_0_2 = (((QData)((IData)(
                                                               vlSelfRef.__PVT__currentFirstStoreNextWide_2[1U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlSelfRef.__PVT__currentFirstStoreNextWide_2[0U])));
            vlSelfRef.bucketFirstStore_0_3 = (((QData)((IData)(
                                                               vlSelfRef.__PVT__currentFirstStoreNextWide_3[1U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlSelfRef.__PVT__currentFirstStoreNextWide_3[0U])));
        }
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__125(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__125\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___buckets_count_7_T_1 = (1ULL + vlSelfRef.buckets_count_7);
    vlSelfRef.__PVT___buckets_count_6_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_6);
    vlSelfRef.__PVT___buckets_count_5_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_5);
    vlSelfRef.__PVT___buckets_count_4_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_4);
    vlSelfRef.__PVT___buckets_count_3_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_3);
    vlSelfRef.__PVT___buckets_count_2_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_2);
    vlSelfRef.__PVT___buckets_count_1_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_1);
    vlSelfRef.__PVT__bucketValid_2 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                                      && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                          && ((1U & 
                                               (~ (IData)(vlSelfRef.__PVT___T_162))) 
                                              && (IData)(vlSelfRef.__PVT___GEN_250))));
    vlSelfRef.__PVT__bucketValid_4 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                                      && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                          && ((1U & 
                                               (~ (IData)(vlSelfRef.__PVT___T_308))) 
                                              && (IData)(vlSelfRef.__PVT___GEN_420))));
    vlSelfRef.__PVT__bucketValid_5 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                                      && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                          && ((1U & 
                                               (~ (IData)(vlSelfRef.__PVT___T_381))) 
                                              && (IData)(vlSelfRef.__PVT___GEN_505))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__126(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__126\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__bucketValid_1 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                                      && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                          && ((1U & 
                                               (~ (IData)(vlSelfRef.__PVT___T_89))) 
                                              && (IData)(vlSelfRef.__PVT___GEN_165))));
    vlSelfRef.bucketValid_7 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                               && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                   && ((1U & (~ (IData)(vlSelfRef.__PVT___T_527))) 
                                       && (IData)(vlSelfRef.__PVT___GEN_675))));
    vlSelfRef.__PVT__bucketValid_6 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                                      && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                          && ((1U & 
                                               (~ (IData)(vlSelfRef.__PVT___T_454))) 
                                              && (IData)(vlSelfRef.__PVT___GEN_590))));
    vlSelfRef.__PVT__bucketValid_3 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                                      && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                          && ((1U & 
                                               (~ (IData)(vlSelfRef.__PVT___T_235))) 
                                              && (IData)(vlSelfRef.__PVT___GEN_335))));
    vlSelfRef.bucketValid_0 = ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__reset))) 
                               && ((1U & (~ (IData)(vlSymsp->TOP.tb__DOT__io_resetStats))) 
                                   && ((1U & (~ (IData)(vlSelfRef.__PVT___T_16))) 
                                       && (IData)(vlSelfRef.__PVT___GEN_80))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__127(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__127\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1185 
        = (0x7fU & (((((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1147)
                        ? (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_37)
                        : 0U) | ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1150)
                                  ? (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_72)
                                  : 0U)) | (((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1153)
                                              ? (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_114)
                                              : 0U) 
                                            | ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1155)
                                                ? (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_119)
                                                : 0U))) 
                    + ((((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1165)
                          ? (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_174)
                          : 0U) | ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1168)
                                    ? (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_209)
                                    : 0U)) | (((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1171)
                                                ? (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_251)
                                                : 0U) 
                                              | ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_1173)
                                                  ? (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_256)
                                                  : 0U)))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__132(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__132\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_2 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(2U) 
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

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__137(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__137\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_4 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(4U) 
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

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__142(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__142\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_5 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(5U) 
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

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__147(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__147\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_1 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(1U) 
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

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__152(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__152\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_7 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(7U) 
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

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__157(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__157\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_6 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(6U) 
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

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__162(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__162\n"); );
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

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__167(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_0__167\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                  == (IData)(vlSymsp->TOP.tb__DOT__io_base));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_0__0(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_0__0\n"); );
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
    vlSelfRef.__PVT___buckets_count_0_T_1 = (1ULL + vlSelfRef.buckets_count_0);
    vlSelfRef.__PVT___buckets_requestCycleSum_7_T_1 
        = (vlSelfRef.buckets_requestCycleSum_7 + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
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
    vlSelfRef.__PVT__resolving_7 = ((IData)(vlSelfRef.buckets_valid_7) 
                                    & (vlSelfRef.buckets_seq_7 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_5 = ((IData)(vlSelfRef.__PVT__buckets_valid_5) 
                                    & (vlSelfRef.__PVT__buckets_seq_5 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_4 = ((IData)(vlSelfRef.__PVT__buckets_valid_4) 
                                    & (vlSelfRef.__PVT__buckets_seq_4 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_6 = ((IData)(vlSelfRef.__PVT__buckets_valid_6) 
                                    & (vlSelfRef.__PVT__buckets_seq_6 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_0 = ((IData)(vlSelfRef.buckets_valid_0) 
                                    & (vlSelfRef.buckets_seq_0 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_2 = ((IData)(vlSelfRef.__PVT__buckets_valid_2) 
                                    & (vlSelfRef.__PVT__buckets_seq_2 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_3 = ((IData)(vlSelfRef.__PVT__buckets_valid_3) 
                                    & (vlSelfRef.__PVT__buckets_seq_3 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_1 = ((IData)(vlSelfRef.__PVT__buckets_valid_1) 
                                    & (vlSelfRef.__PVT__buckets_seq_1 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.bucketStore_0_0__VforceRd = ((vlSelfRef.bucketStore_0_0__VforceEn 
                                            & vlSelfRef.bucketStore_0_0__VforceVal) 
                                           | ((~ vlSelfRef.bucketStore_0_0__VforceEn) 
                                              & vlSelfRef.bucketStore_0_0));
    vlSelfRef.__PVT___io_retiringValid_T_2 = ((IData)(vlSelfRef.__PVT__retireSelect_2) 
                                              & (IData)(vlSelfRef.__PVT__bucketValid_2));
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_2)
                              ? vlSelfRef.__PVT__bucketStore_2_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_2)
                               ? vlSelfRef.__PVT__bucketStore_2_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__currentStoreNextWide_8[0U] = __Vtemp_4[0U];
    vlSelfRef.__PVT__currentStoreNextWide_8[1U] = __Vtemp_4[1U];
    vlSelfRef.__PVT__currentStoreNextWide_8[2U] = (1U 
                                                   & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_2)
                              ? vlSelfRef.__PVT__bucketStore_2_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_2)
                               ? vlSelfRef.__PVT__bucketStore_2_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__currentStoreNextWide_9[0U] = __Vtemp_8[0U];
    vlSelfRef.__PVT__currentStoreNextWide_9[1U] = __Vtemp_8[1U];
    vlSelfRef.__PVT__currentStoreNextWide_9[2U] = (1U 
                                                   & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_2)
                               ? vlSelfRef.__PVT__bucketStore_2_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_2)
                                ? vlSelfRef.__PVT__bucketStore_2_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__currentStoreNextWide_10[0U] = 
        __Vtemp_12[0U];
    vlSelfRef.__PVT__currentStoreNextWide_10[1U] = 
        __Vtemp_12[1U];
    vlSelfRef.__PVT__currentStoreNextWide_10[2U] = 
        (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_2)
                               ? vlSelfRef.__PVT__bucketStore_2_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_2)
                                ? vlSelfRef.__PVT__bucketStore_2_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__currentStoreNextWide_11[0U] = 
        __Vtemp_16[0U];
    vlSelfRef.__PVT__currentStoreNextWide_11[1U] = 
        __Vtemp_16[1U];
    vlSelfRef.__PVT__currentStoreNextWide_11[2U] = 
        (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_2)
                               ? vlSelfRef.__PVT__bucketFirstStore_2_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_2)
                                ? vlSelfRef.__PVT__bucketFirstStore_2_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__currentFirstStoreNextWide_8[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_8[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_8[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_2)
                               ? vlSelfRef.__PVT__bucketFirstStore_2_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_2)
                                ? vlSelfRef.__PVT__bucketFirstStore_2_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__currentFirstStoreNextWide_9[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_9[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_9[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_2)
                               ? vlSelfRef.__PVT__bucketFirstStore_2_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_2)
                                ? vlSelfRef.__PVT__bucketFirstStore_2_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__currentFirstStoreNextWide_10[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_10[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_10[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_2)
                               ? vlSelfRef.__PVT__bucketFirstStore_2_3
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_2)
                                ? vlSelfRef.__PVT__bucketFirstStore_2_3
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__currentFirstStoreNextWide_11[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_11[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_11[2U] 
        = (1U & __Vtemp_32[2U]);
    vlSelfRef.__PVT___io_retiringValid_T_4 = ((IData)(vlSelfRef.__PVT__retireSelect_4) 
                                              & (IData)(vlSelfRef.__PVT__bucketValid_4));
}
