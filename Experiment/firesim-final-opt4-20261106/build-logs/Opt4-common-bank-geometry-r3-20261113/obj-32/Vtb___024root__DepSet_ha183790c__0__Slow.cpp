// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb___024root.h"

VL_ATTR_COLD void Vtb___024root___eval_static__TOP(Vtb___024root* vlSelf);

VL_ATTR_COLD void Vtb___024root___eval_static(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vtb___024root___eval_static__TOP(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_static__TOP\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__rng = 0xc831873933ea45bdULL;
}

VL_ATTR_COLD void Vtb___024root___eval_initial__TOP(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_0_0__VforceEn = 0ULL;
}

VL_ATTR_COLD void Vtb___024root___eval_final(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__stl(Vtb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb___024root___eval_phase__stl(Vtb___024root* vlSelf);

VL_ATTR_COLD void Vtb___024root___eval_settle(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_settle\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-common-bank-geometry-r3-20261113/tb-32.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__stl(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___dump_triggers__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb___024root___eval_stl__0(Vtb___024root* vlSelf);
VL_ATTR_COLD void Vtb___024root___eval_stl__1(Vtb___024root* vlSelf);

VL_ATTR_COLD void Vtb___024root___eval_stl(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb___024root___eval_stl__0(vlSelf);
    Vtb___024root___eval_stl__1(vlSelf);
}

VL_ATTR_COLD void Vtb___024root___stl_sequent__TOP__0(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___stl_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_0_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_0);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_1_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_1);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_2_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_2);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_3_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_4_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_4);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_5_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_5);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_6_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_6);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_7_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_8_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_8);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_9_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_9);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_10_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_10);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_11_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_12_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_12);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_13_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_13);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_14_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_14);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_15_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_16_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_16);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_17_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_17);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_18_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_18);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_19_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_20_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_20);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_21_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_21);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_22_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_22);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_23_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_24_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_24);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_25_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_25);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_26_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_26);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_27_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_28_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_28);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_29_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_29);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_30_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_30);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_count_31_T_1 
        = (1ULL + vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_count_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_0_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_0 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_1_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_1 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_2_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_2 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_3_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_3 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_4_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_4 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_5_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_5 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_6_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_6 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_7_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_7 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
}

VL_ATTR_COLD void Vtb___024root___stl_sequent__TOP__1(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___stl_sequent__TOP__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_8_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_8 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_9_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_9 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_10_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_10 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_11_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_11 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_12_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_12 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_13_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_13 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_14_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_14 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_15_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_15 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_16_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_16 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_17_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_17 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_18_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_18 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_19_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_19 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_20_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_20 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_21_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_21 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_22_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_22 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_23_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_23 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_24_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_24 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_25_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_25 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_26_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_26 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_27_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_27 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_28_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_28 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_29_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_29 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_30_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_30 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___buckets_requestCycleSum_31_T_1 
        = (vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__buckets_requestCycleSum_31 
           + vlSelfRef.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (IData)(vlSelfRef.tb__DOT__io_base));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_1 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(1U) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_2 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(2U) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_3 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(3U) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_4 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(4U) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_5 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(5U) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_6 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(6U) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_7 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(7U) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_8 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(8U) + (IData)(vlSelfRef.tb__DOT__io_base))));
}

VL_ATTR_COLD void Vtb___024root___stl_sequent__TOP__2(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___stl_sequent__TOP__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_9 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(9U) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_10 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_11 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_12 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_13 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_14 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_15 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_16 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(0x10U) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_17 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(0x11U) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_18 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_19 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_20 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_21 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_22 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_23 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_24 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_25 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_26 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_27 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_28 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSelfRef.tb__DOT__io_base))));
}

VL_ATTR_COLD void Vtb___024root___stl_sequent__TOP__3(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___stl_sequent__TOP__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_29 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_30 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_31 
        = ((0xffU & vlSelfRef.tb__DOT__io_retiringSeq) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSelfRef.tb__DOT__io_base))));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770 
        = ((~ (IData)(vlSelfRef.tb__DOT__io_safeError)) 
           & (IData)(vlSelfRef.tb__DOT__io_safeAdvance));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_0 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_1_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_1 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_2_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_2 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_3_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_3 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_4_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_4 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_5_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_5 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_6_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_6 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_7_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_7 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_8_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_8 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_9_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_9 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_10_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_10 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_11_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_11 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_12_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_12 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_13_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_13 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_14_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_14 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_15_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_15 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_16_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_16 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_17_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_17 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_18_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_18 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_19_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_19 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_20_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_20 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
}

VL_ATTR_COLD void Vtb___024root___stl_sequent__TOP__4(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___stl_sequent__TOP__4\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_21_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_21 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_22_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_22 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_23_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_23 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_24_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_24 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_25_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_25 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_26_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_26 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_27_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_27 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_28_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_28 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_29_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_29 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_30_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_30 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_31_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_31 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_32_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_32 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_33_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_33 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_34_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_34 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_35_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_35 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_36_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_36 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_37_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_37 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_38_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_38 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_39_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_39 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_40_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_40 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_41_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_41 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_42_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_42 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_43_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_43 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_44_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_44 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_45_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_45 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
}

VL_ATTR_COLD void Vtb___024root___stl_sequent__TOP__5(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___stl_sequent__TOP__5\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_46_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_46 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_47_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_47 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_48_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_48 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_49_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_49 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_50_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_50 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_51_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_51 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_52_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_52 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_53_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_53 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_54_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_54 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_55_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_55 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_56_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_56 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_57_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_57 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_58_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_58 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_59_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_59 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_60_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_60 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_61_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_61 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_62_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_62 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_63_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_63 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_64_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_64 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_65_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_65 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_66_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_66 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_67_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_67 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_68_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_68 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_69_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_69 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_70_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_70 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
}

VL_ATTR_COLD void Vtb___024root___stl_sequent__TOP__6(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___stl_sequent__TOP__6\n"); );
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
    // Body
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_71_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_71 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_72_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_72 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_73_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_73 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_74_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_74 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_75_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_75 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_76_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_76 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_77_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_77 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_78_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_78 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_79_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_79 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_80_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_80 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_81_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_81 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_82_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_82 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_83_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_83 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_84_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_84 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_85_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_85 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_86_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_86 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset 
        = (0xffU & (vlSelfRef.tb__DOT__io_querySeq_87 
                    - (IData)(vlSelfRef.tb__DOT__io_base)));
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_0_1
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_0_1
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_1[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_1[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_1[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_0_2
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_0_2
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_2[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_2[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_2[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_0_3
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_0_3
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_3[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_3[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_3[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_1_0
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_1_0
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_4[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_4[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_4[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_1_1
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_1_1
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_5[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_5[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_5[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_1_2
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_1_2
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_6[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_6[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_6[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_1_3
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_1_3
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_7[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_7[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_7[2U] 
        = (1U & __Vtemp_28[2U]);
}

VL_ATTR_COLD void Vtb___024root___stl_sequent__TOP__7(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___stl_sequent__TOP__7\n"); );
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
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_2_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_2_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_8[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_8[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_8[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_2_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_2_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_9[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_9[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_9[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_2_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_2_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_10[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_10[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_10[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_2_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_2_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_11[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_11[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_11[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_3_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_3_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_12[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_12[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_12[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_3_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_3_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_13[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_13[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_13[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_3_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_3_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_14[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_14[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_14[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_3_3
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_3_3
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_15[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_15[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_15[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_4_0
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_4_0
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_16[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_16[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_16[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_4_1
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_4_1
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_17[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_17[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_17[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_4_2
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_4_2
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_18[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_18[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_18[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_4_3
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_4_3
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_19[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_19[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_19[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_5_0
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_5_0
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_20[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_20[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_20[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_5_1
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_5_1
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_21[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_21[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_21[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_5_2
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_5_2
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_22[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_22[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_22[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_5_3
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_5_3
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_23[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_23[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_23[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_6_0
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_6_0
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_24[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_24[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_24[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_6_1
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_6_1
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_25[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_25[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_25[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_6_2
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_6_2
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_26[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_26[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_26[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_6_3
                               : 0ULL));
    __Vtemp_78[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_6_3
                                : 0ULL) >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_27[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_27[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_27[2U] 
        = (1U & __Vtemp_80[2U]);
}

VL_ATTR_COLD void Vtb___024root___stl_sequent__TOP__8(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___stl_sequent__TOP__8\n"); );
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
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_7_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_7_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_28[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_28[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_28[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_7_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_7_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_29[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_29[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_29[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_7_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_7_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_30[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_30[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_30[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_7_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_7_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_31[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_31[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_31[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_8_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_8_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_32[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_32[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_32[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_8_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_8_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_33[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_33[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_33[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_8_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_8_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_34[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_34[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_34[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_8_3
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_8_3
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_35[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_35[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_35[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_9_0
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_9_0
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_36[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_36[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_36[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_9_1
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_9_1
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_37[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_37[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_37[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_9_2
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_9_2
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_38[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_38[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_38[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_9_3
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_9_3
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_39[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_39[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_39[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_10_0
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_10_0
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_40[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_40[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_40[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_10_1
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_10_1
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_41[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_41[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_41[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_10_2
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_10_2
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_42[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_42[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_42[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_10_3
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_10_3
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_43[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_43[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_43[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_11_0
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_11_0
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_44[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_44[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_44[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_11_1
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_11_1
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_45[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_45[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_45[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_11_2
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_11_2
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_46[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_46[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_46[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_11_3
                               : 0ULL));
    __Vtemp_78[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_11_3
                                : 0ULL) >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_47[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_47[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_47[2U] 
        = (1U & __Vtemp_80[2U]);
}

VL_ATTR_COLD void Vtb___024root___stl_sequent__TOP__9(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___stl_sequent__TOP__9\n"); );
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
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_12_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_12_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_48[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_48[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_48[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_12_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_12_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_49[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_49[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_49[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_12_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_12_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_50[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_50[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_50[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_12_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_12_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_51[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_51[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_51[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_13_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_13_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_52[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_52[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_52[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_13_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_13_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_53[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_53[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_53[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_13_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_13_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_54[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_54[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_54[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_13_3
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_13_3
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_55[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_55[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_55[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_14_0
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_14_0
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_56[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_56[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_56[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_14_1
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_14_1
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_57[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_57[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_57[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_14_2
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_14_2
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_58[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_58[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_58[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_14_3
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_14_3
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_59[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_59[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_59[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_15_0
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_15_0
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_60[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_60[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_60[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_15_1
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_15_1
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_61[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_61[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_61[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_15_2
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_15_2
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_62[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_62[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_62[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_15_3
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_15_3
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_63[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_63[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_63[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_16_0
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_16_0
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_64[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_64[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_64[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_16_1
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_16_1
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_65[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_65[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_65[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_16_2
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_16_2
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_66[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_66[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_66[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_16_3
                               : 0ULL));
    __Vtemp_78[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_16_3
                                : 0ULL) >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_67[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_67[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_67[2U] 
        = (1U & __Vtemp_80[2U]);
}

VL_ATTR_COLD void Vtb___024root___stl_sequent__TOP__10(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___stl_sequent__TOP__10\n"); );
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
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_17_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_17_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_68[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_68[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_68[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_17_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_17_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_69[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_69[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_69[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_17_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_17_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_70[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_70[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_70[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_17_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_17_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_71[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_71[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_71[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_18_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_18_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_72[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_72[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_72[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_18_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_18_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_73[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_73[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_73[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_18_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_18_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_74[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_74[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_74[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_18_3
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_18_3
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_75[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_75[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_75[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_19)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_19_0
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_19)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_19_0
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_76[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_76[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_76[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_19)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_19_1
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_19)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_19_1
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_77[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_77[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_77[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_19)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_19_2
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_19)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_19_2
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_78[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_78[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_78[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_19)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_19_3
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_19)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_19_3
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_79[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_79[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_79[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_20_0
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_20_0
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_80[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_80[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_80[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_20_1
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_20_1
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_81[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_81[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_81[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_20_2
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_20_2
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_82[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_82[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_82[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_20_3
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_20_3
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_83[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_83[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_83[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_21_0
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_21_0
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_84[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_84[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_84[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_21_1
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_21_1
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_85[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_85[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_85[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_21_2
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_21_2
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_86[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_86[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_86[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_21_3
                               : 0ULL));
    __Vtemp_78[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_21_3
                                : 0ULL) >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_87[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_87[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_87[2U] 
        = (1U & __Vtemp_80[2U]);
}

VL_ATTR_COLD void Vtb___024root___stl_sequent__TOP__11(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___stl_sequent__TOP__11\n"); );
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
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_22)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_22_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_22)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_22_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_88[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_88[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_88[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_22)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_22_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_22)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_22_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_89[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_89[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_89[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_22)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_22_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_22)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_22_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_90[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_90[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_90[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_22)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_22_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_22)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_22_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_91[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_91[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_91[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_23_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_23_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_92[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_92[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_92[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_23_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_23_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_93[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_93[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_93[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_23_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_23_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_94[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_94[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_94[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_23_3
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_23_3
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_95[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_95[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_95[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_24_0
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_24_0
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_96[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_96[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_96[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_24_1
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_24_1
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_97[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_97[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_97[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_24_2
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_24_2
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_98[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_98[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_98[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_24_3
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_24_3
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_99[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_99[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_99[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_25_0
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_25_0
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_100[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_100[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_100[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_25_1
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_25_1
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_101[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_101[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_101[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_25_2
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_25_2
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_102[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_102[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_102[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_25_3
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_25_3
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_103[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_103[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_103[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_0
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_0
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_104[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_104[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_104[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_1
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_1
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_105[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_105[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_105[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_2
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_2
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_106[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_106[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_106[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_3
                               : 0ULL));
    __Vtemp_78[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_3
                                : 0ULL) >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_107[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_107[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_107[2U] 
        = (1U & __Vtemp_80[2U]);
}

VL_ATTR_COLD void Vtb___024root___stl_sequent__TOP__12(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___stl_sequent__TOP__12\n"); );
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
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_108[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_108[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_108[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_109[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_109[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_109[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_110[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_110[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_110[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_111[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_111[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_111[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_112[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_112[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_112[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_113[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_113[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_113[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_114[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_114[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_114[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_3
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_3
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_115[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_115[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_115[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_0
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_0
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_116[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_116[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_116[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_1
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_1
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_117[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_117[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_117[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_2
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_2
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_118[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_118[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_118[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_3
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_3
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_119[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_119[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_119[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_0
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_0
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_120[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_120[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_120[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_1
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_1
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_121[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_121[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_121[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_2
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_2
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_122[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_122[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_122[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_3
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_3
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_123[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_123[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_123[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_0
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_0
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_124[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_124[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_124[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_1
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_1
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_125[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_125[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_125[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_2
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_2
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_126[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_126[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_126[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_3
                               : 0ULL));
    __Vtemp_78[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_3
                                : 0ULL) >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_127[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_127[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_127[2U] 
        = (1U & __Vtemp_80[2U]);
}
