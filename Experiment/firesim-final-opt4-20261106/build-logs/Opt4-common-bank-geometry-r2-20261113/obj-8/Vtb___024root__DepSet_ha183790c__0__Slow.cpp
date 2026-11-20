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
            VL_FATAL_MT("/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-common-bank-geometry-r2-20261113/tb-8.v", 1, "", "Settle region did not converge.");
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

VL_ATTR_COLD void Vtb___024root___eval_stl__0(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_stl__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb___024root___eval_triggers__stl(Vtb___024root* vlSelf);

VL_ATTR_COLD bool Vtb___024root___eval_phase__stl(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__act(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb.clock)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__nba(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb.clock)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb___024root___ctor_var_reset_0(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___ctor_var_reset_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->tb__DOT__cycle = 0;
    vlSelf->tb__DOT__rng = 0;
    vlSelf->tb__DOT__io_same = 0;
    vlSelf->tb__DOT__clock = 0;
    vlSelf->tb__DOT__reset = 0;
    vlSelf->tb__DOT__io_barrierBase = 0;
    vlSelf->tb__DOT__io_barrierResetStats = 0;
    vlSelf->tb__DOT__io_barrierEvent_valid = 0;
    vlSelf->tb__DOT__io_barrierEvent_bits = 0;
    vlSelf->tb__DOT__io_barrierSafeWatermark = 0;
    vlSelf->tb__DOT__io_barrierCurrentCycle = 0;
    vlSelf->tb__DOT__io_base = 0;
    vlSelf->tb__DOT__io_loadSources_0_key = 0;
    vlSelf->tb__DOT__io_loadSources_0_counts_bytes = 0;
    vlSelf->tb__DOT__io_loadSources_0_counts_words4 = 0;
    vlSelf->tb__DOT__io_loadSources_0_counts_words8 = 0;
    vlSelf->tb__DOT__io_loadSources_0_counts_lines = 0;
    vlSelf->tb__DOT__io_loadSources_1_key = 0;
    vlSelf->tb__DOT__io_loadSources_1_counts_bytes = 0;
    vlSelf->tb__DOT__io_loadSources_1_counts_words4 = 0;
    vlSelf->tb__DOT__io_loadSources_1_counts_words8 = 0;
    vlSelf->tb__DOT__io_loadSources_1_counts_lines = 0;
    vlSelf->tb__DOT__io_loadSources_2_key = 0;
    vlSelf->tb__DOT__io_loadSources_2_counts_bytes = 0;
    vlSelf->tb__DOT__io_loadSources_2_counts_words4 = 0;
    vlSelf->tb__DOT__io_loadSources_2_counts_words8 = 0;
    vlSelf->tb__DOT__io_loadSources_2_counts_lines = 0;
    vlSelf->tb__DOT__io_loadSources_3_key = 0;
    vlSelf->tb__DOT__io_loadSources_3_counts_bytes = 0;
    vlSelf->tb__DOT__io_loadSources_3_counts_words4 = 0;
    vlSelf->tb__DOT__io_loadSources_3_counts_words8 = 0;
    vlSelf->tb__DOT__io_loadSources_3_counts_lines = 0;
    vlSelf->tb__DOT__io_loadSources_4_key = 0;
    vlSelf->tb__DOT__io_loadSources_4_counts_bytes = 0;
    vlSelf->tb__DOT__io_loadSources_4_counts_words4 = 0;
    vlSelf->tb__DOT__io_loadSources_4_counts_words8 = 0;
    vlSelf->tb__DOT__io_loadSources_4_counts_lines = 0;
    vlSelf->tb__DOT__io_loadSources_5_key = 0;
    vlSelf->tb__DOT__io_loadSources_5_counts_bytes = 0;
    vlSelf->tb__DOT__io_loadSources_5_counts_words4 = 0;
    vlSelf->tb__DOT__io_loadSources_5_counts_words8 = 0;
    vlSelf->tb__DOT__io_loadSources_5_counts_lines = 0;
    vlSelf->tb__DOT__io_loadSources_6_key = 0;
    vlSelf->tb__DOT__io_loadSources_6_counts_bytes = 0;
    vlSelf->tb__DOT__io_loadSources_6_counts_words4 = 0;
    vlSelf->tb__DOT__io_loadSources_6_counts_words8 = 0;
    vlSelf->tb__DOT__io_loadSources_6_counts_lines = 0;
    vlSelf->tb__DOT__io_loadSources_7_key = 0;
    vlSelf->tb__DOT__io_loadSources_7_counts_bytes = 0;
    vlSelf->tb__DOT__io_loadSources_7_counts_words4 = 0;
    vlSelf->tb__DOT__io_loadSources_7_counts_words8 = 0;
    vlSelf->tb__DOT__io_loadSources_7_counts_lines = 0;
    vlSelf->tb__DOT__io_storeSources_0_key = 0;
    vlSelf->tb__DOT__io_storeSources_0_counts_bytes = 0;
    vlSelf->tb__DOT__io_storeSources_0_counts_words4 = 0;
    vlSelf->tb__DOT__io_storeSources_0_counts_words8 = 0;
    vlSelf->tb__DOT__io_storeSources_0_counts_lines = 0;
    vlSelf->tb__DOT__io_storeSources_1_key = 0;
    vlSelf->tb__DOT__io_storeSources_1_counts_bytes = 0;
    vlSelf->tb__DOT__io_storeSources_1_counts_words4 = 0;
    vlSelf->tb__DOT__io_storeSources_1_counts_words8 = 0;
    vlSelf->tb__DOT__io_storeSources_1_counts_lines = 0;
    vlSelf->tb__DOT__io_storeSources_2_key = 0;
    vlSelf->tb__DOT__io_storeSources_2_counts_bytes = 0;
    vlSelf->tb__DOT__io_storeSources_2_counts_words4 = 0;
    vlSelf->tb__DOT__io_storeSources_2_counts_words8 = 0;
    vlSelf->tb__DOT__io_storeSources_2_counts_lines = 0;
    vlSelf->tb__DOT__io_storeSources_3_key = 0;
    vlSelf->tb__DOT__io_storeSources_3_counts_bytes = 0;
    vlSelf->tb__DOT__io_storeSources_3_counts_words4 = 0;
    vlSelf->tb__DOT__io_storeSources_3_counts_words8 = 0;
    vlSelf->tb__DOT__io_storeSources_3_counts_lines = 0;
    vlSelf->tb__DOT__io_storeSources_4_key = 0;
    vlSelf->tb__DOT__io_storeSources_4_counts_bytes = 0;
    vlSelf->tb__DOT__io_storeSources_4_counts_words4 = 0;
    vlSelf->tb__DOT__io_storeSources_4_counts_words8 = 0;
    vlSelf->tb__DOT__io_storeSources_4_counts_lines = 0;
    vlSelf->tb__DOT__io_storeSources_5_key = 0;
    vlSelf->tb__DOT__io_storeSources_5_counts_bytes = 0;
    vlSelf->tb__DOT__io_storeSources_5_counts_words4 = 0;
    vlSelf->tb__DOT__io_storeSources_5_counts_words8 = 0;
    vlSelf->tb__DOT__io_storeSources_5_counts_lines = 0;
    vlSelf->tb__DOT__io_storeSources_6_key = 0;
    vlSelf->tb__DOT__io_storeSources_6_counts_bytes = 0;
    vlSelf->tb__DOT__io_storeSources_6_counts_words4 = 0;
    vlSelf->tb__DOT__io_storeSources_6_counts_words8 = 0;
    vlSelf->tb__DOT__io_storeSources_6_counts_lines = 0;
    vlSelf->tb__DOT__io_storeSources_7_key = 0;
    vlSelf->tb__DOT__io_storeSources_7_counts_bytes = 0;
    vlSelf->tb__DOT__io_storeSources_7_counts_words4 = 0;
    vlSelf->tb__DOT__io_storeSources_7_counts_words8 = 0;
    vlSelf->tb__DOT__io_storeSources_7_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_0_key = 0;
    vlSelf->tb__DOT__io_strictSources_0_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_0_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_0_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_0_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_1_key = 0;
    vlSelf->tb__DOT__io_strictSources_1_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_1_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_1_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_1_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_2_key = 0;
    vlSelf->tb__DOT__io_strictSources_2_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_2_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_2_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_2_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_3_key = 0;
    vlSelf->tb__DOT__io_strictSources_3_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_3_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_3_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_3_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_4_key = 0;
    vlSelf->tb__DOT__io_strictSources_4_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_4_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_4_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_4_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_5_key = 0;
    vlSelf->tb__DOT__io_strictSources_5_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_5_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_5_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_5_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_6_key = 0;
    vlSelf->tb__DOT__io_strictSources_6_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_6_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_6_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_6_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_7_key = 0;
    vlSelf->tb__DOT__io_strictSources_7_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_7_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_7_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_7_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_8_key = 0;
    vlSelf->tb__DOT__io_strictSources_8_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_8_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_8_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_8_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_9_key = 0;
    vlSelf->tb__DOT__io_strictSources_9_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_9_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_9_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_9_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_10_key = 0;
    vlSelf->tb__DOT__io_strictSources_10_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_10_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_10_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_10_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_11_key = 0;
    vlSelf->tb__DOT__io_strictSources_11_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_11_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_11_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_11_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_12_key = 0;
    vlSelf->tb__DOT__io_strictSources_12_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_12_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_12_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_12_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_13_key = 0;
    vlSelf->tb__DOT__io_strictSources_13_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_13_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_13_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_13_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_14_key = 0;
    vlSelf->tb__DOT__io_strictSources_14_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_14_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_14_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_14_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_15_key = 0;
    vlSelf->tb__DOT__io_strictSources_15_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_15_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_15_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_15_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_16_key = 0;
    vlSelf->tb__DOT__io_strictSources_16_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_16_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_16_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_16_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_17_key = 0;
    vlSelf->tb__DOT__io_strictSources_17_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_17_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_17_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_17_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_18_key = 0;
    vlSelf->tb__DOT__io_strictSources_18_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_18_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_18_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_18_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_19_key = 0;
    vlSelf->tb__DOT__io_strictSources_19_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_19_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_19_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_19_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_20_key = 0;
    vlSelf->tb__DOT__io_strictSources_20_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_20_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_20_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_20_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_21_key = 0;
    vlSelf->tb__DOT__io_strictSources_21_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_21_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_21_counts_words8 = 0;
}

VL_ATTR_COLD void Vtb___024root___ctor_var_reset_1(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___ctor_var_reset_1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->tb__DOT__io_strictSources_21_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_22_key = 0;
    vlSelf->tb__DOT__io_strictSources_22_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_22_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_22_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_22_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_23_key = 0;
    vlSelf->tb__DOT__io_strictSources_23_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_23_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_23_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_23_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_24_key = 0;
    vlSelf->tb__DOT__io_strictSources_24_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_24_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_24_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_24_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_25_key = 0;
    vlSelf->tb__DOT__io_strictSources_25_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_25_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_25_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_25_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_26_key = 0;
    vlSelf->tb__DOT__io_strictSources_26_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_26_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_26_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_26_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_27_key = 0;
    vlSelf->tb__DOT__io_strictSources_27_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_27_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_27_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_27_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_28_key = 0;
    vlSelf->tb__DOT__io_strictSources_28_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_28_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_28_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_28_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_29_key = 0;
    vlSelf->tb__DOT__io_strictSources_29_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_29_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_29_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_29_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_30_key = 0;
    vlSelf->tb__DOT__io_strictSources_30_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_30_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_30_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_30_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_31_key = 0;
    vlSelf->tb__DOT__io_strictSources_31_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_31_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_31_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_31_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_32_key = 0;
    vlSelf->tb__DOT__io_strictSources_32_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_32_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_32_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_32_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_33_key = 0;
    vlSelf->tb__DOT__io_strictSources_33_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_33_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_33_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_33_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_34_key = 0;
    vlSelf->tb__DOT__io_strictSources_34_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_34_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_34_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_34_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_35_key = 0;
    vlSelf->tb__DOT__io_strictSources_35_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_35_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_35_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_35_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_36_key = 0;
    vlSelf->tb__DOT__io_strictSources_36_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_36_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_36_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_36_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_37_key = 0;
    vlSelf->tb__DOT__io_strictSources_37_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_37_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_37_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_37_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_38_key = 0;
    vlSelf->tb__DOT__io_strictSources_38_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_38_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_38_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_38_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_39_key = 0;
    vlSelf->tb__DOT__io_strictSources_39_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_39_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_39_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_39_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_40_key = 0;
    vlSelf->tb__DOT__io_strictSources_40_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_40_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_40_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_40_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_41_key = 0;
    vlSelf->tb__DOT__io_strictSources_41_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_41_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_41_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_41_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_42_key = 0;
    vlSelf->tb__DOT__io_strictSources_42_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_42_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_42_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_42_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_43_key = 0;
    vlSelf->tb__DOT__io_strictSources_43_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_43_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_43_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_43_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_44_key = 0;
    vlSelf->tb__DOT__io_strictSources_44_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_44_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_44_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_44_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_45_key = 0;
    vlSelf->tb__DOT__io_strictSources_45_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_45_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_45_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_45_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_46_key = 0;
    vlSelf->tb__DOT__io_strictSources_46_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_46_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_46_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_46_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_47_key = 0;
    vlSelf->tb__DOT__io_strictSources_47_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_47_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_47_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_47_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_48_key = 0;
    vlSelf->tb__DOT__io_strictSources_48_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_48_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_48_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_48_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_49_key = 0;
    vlSelf->tb__DOT__io_strictSources_49_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_49_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_49_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_49_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_50_key = 0;
    vlSelf->tb__DOT__io_strictSources_50_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_50_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_50_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_50_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_51_key = 0;
    vlSelf->tb__DOT__io_strictSources_51_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_51_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_51_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_51_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_52_key = 0;
    vlSelf->tb__DOT__io_strictSources_52_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_52_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_52_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_52_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_53_key = 0;
    vlSelf->tb__DOT__io_strictSources_53_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_53_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_53_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_53_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_54_key = 0;
    vlSelf->tb__DOT__io_strictSources_54_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_54_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_54_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_54_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_55_key = 0;
    vlSelf->tb__DOT__io_strictSources_55_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_55_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_55_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_55_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_56_key = 0;
    vlSelf->tb__DOT__io_strictSources_56_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_56_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_56_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_56_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_57_key = 0;
    vlSelf->tb__DOT__io_strictSources_57_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_57_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_57_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_57_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_58_key = 0;
    vlSelf->tb__DOT__io_strictSources_58_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_58_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_58_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_58_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_59_key = 0;
    vlSelf->tb__DOT__io_strictSources_59_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_59_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_59_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_59_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_60_key = 0;
    vlSelf->tb__DOT__io_strictSources_60_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_60_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_60_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_60_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_61_key = 0;
    vlSelf->tb__DOT__io_strictSources_61_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_61_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_61_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_61_counts_lines = 0;
}

VL_ATTR_COLD void Vtb___024root___ctor_var_reset_2(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___ctor_var_reset_2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->tb__DOT__io_strictSources_62_key = 0;
    vlSelf->tb__DOT__io_strictSources_62_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_62_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_62_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_62_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_63_key = 0;
    vlSelf->tb__DOT__io_strictSources_63_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_63_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_63_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_63_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_64_key = 0;
    vlSelf->tb__DOT__io_strictSources_64_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_64_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_64_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_64_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_65_key = 0;
    vlSelf->tb__DOT__io_strictSources_65_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_65_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_65_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_65_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_66_key = 0;
    vlSelf->tb__DOT__io_strictSources_66_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_66_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_66_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_66_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_67_key = 0;
    vlSelf->tb__DOT__io_strictSources_67_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_67_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_67_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_67_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_68_key = 0;
    vlSelf->tb__DOT__io_strictSources_68_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_68_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_68_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_68_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_69_key = 0;
    vlSelf->tb__DOT__io_strictSources_69_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_69_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_69_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_69_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_70_key = 0;
    vlSelf->tb__DOT__io_strictSources_70_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_70_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_70_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_70_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_71_key = 0;
    vlSelf->tb__DOT__io_strictSources_71_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_71_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_71_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_71_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_72_key = 0;
    vlSelf->tb__DOT__io_strictSources_72_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_72_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_72_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_72_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_73_key = 0;
    vlSelf->tb__DOT__io_strictSources_73_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_73_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_73_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_73_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_74_key = 0;
    vlSelf->tb__DOT__io_strictSources_74_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_74_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_74_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_74_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_75_key = 0;
    vlSelf->tb__DOT__io_strictSources_75_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_75_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_75_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_75_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_76_key = 0;
    vlSelf->tb__DOT__io_strictSources_76_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_76_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_76_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_76_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_77_key = 0;
    vlSelf->tb__DOT__io_strictSources_77_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_77_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_77_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_77_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_78_key = 0;
    vlSelf->tb__DOT__io_strictSources_78_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_78_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_78_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_78_counts_lines = 0;
    vlSelf->tb__DOT__io_strictSources_79_key = 0;
    vlSelf->tb__DOT__io_strictSources_79_counts_bytes = 0;
    vlSelf->tb__DOT__io_strictSources_79_counts_words4 = 0;
    vlSelf->tb__DOT__io_strictSources_79_counts_words8 = 0;
    vlSelf->tb__DOT__io_strictSources_79_counts_lines = 0;
    vlSelf->tb__DOT__io_newStore_bytes = 0;
    vlSelf->tb__DOT__io_newStore_words4 = 0;
    vlSelf->tb__DOT__io_newStore_words8 = 0;
    vlSelf->tb__DOT__io_newStore_lines = 0;
    vlSelf->tb__DOT__io_newFirstStore_bytes = 0;
    vlSelf->tb__DOT__io_newFirstStore_words4 = 0;
    vlSelf->tb__DOT__io_newFirstStore_words8 = 0;
    vlSelf->tb__DOT__io_newFirstStore_lines = 0;
    vlSelf->tb__DOT__io_processSeq = 0;
    vlSelf->tb__DOT__io_retiringSeq = 0;
    vlSelf->tb__DOT__io_processCommit = 0;
    vlSelf->tb__DOT__io_safeAdvance = 0;
    vlSelf->tb__DOT__io_safeError = 0;
    vlSelf->tb__DOT__io_resetStats = 0;
    vlSelf->tb__DOT__io_querySeq_0 = 0;
    vlSelf->tb__DOT__io_querySeq_1 = 0;
    vlSelf->tb__DOT__io_querySeq_2 = 0;
    vlSelf->tb__DOT__io_querySeq_3 = 0;
    vlSelf->tb__DOT__io_querySeq_4 = 0;
    vlSelf->tb__DOT__io_querySeq_5 = 0;
    vlSelf->tb__DOT__io_querySeq_6 = 0;
    vlSelf->tb__DOT__io_querySeq_7 = 0;
    vlSelf->tb__DOT__io_querySeq_8 = 0;
    vlSelf->tb__DOT__io_querySeq_9 = 0;
    vlSelf->tb__DOT__io_querySeq_10 = 0;
    vlSelf->tb__DOT__io_querySeq_11 = 0;
    vlSelf->tb__DOT__io_querySeq_12 = 0;
    vlSelf->tb__DOT__io_querySeq_13 = 0;
    vlSelf->tb__DOT__io_querySeq_14 = 0;
    vlSelf->tb__DOT__io_querySeq_15 = 0;
    vlSelf->tb__DOT__io_querySeq_16 = 0;
    vlSelf->tb__DOT__io_querySeq_17 = 0;
    vlSelf->tb__DOT__io_querySeq_18 = 0;
    vlSelf->tb__DOT__io_querySeq_19 = 0;
    vlSelf->tb__DOT__io_querySeq_20 = 0;
    vlSelf->tb__DOT__io_querySeq_21 = 0;
    vlSelf->tb__DOT__io_querySeq_22 = 0;
    vlSelf->tb__DOT__io_querySeq_23 = 0;
    vlSelf->tb__DOT__io_querySeq_24 = 0;
    vlSelf->tb__DOT__io_querySeq_25 = 0;
    vlSelf->tb__DOT__io_querySeq_26 = 0;
    vlSelf->tb__DOT__io_querySeq_27 = 0;
    vlSelf->tb__DOT__io_querySeq_28 = 0;
    vlSelf->tb__DOT__io_querySeq_29 = 0;
    vlSelf->tb__DOT__io_querySeq_30 = 0;
    vlSelf->tb__DOT__io_querySeq_31 = 0;
    vlSelf->tb__DOT__io_querySeq_32 = 0;
    vlSelf->tb__DOT__io_querySeq_33 = 0;
    vlSelf->tb__DOT__io_querySeq_34 = 0;
    vlSelf->tb__DOT__io_querySeq_35 = 0;
    vlSelf->tb__DOT__io_querySeq_36 = 0;
    vlSelf->tb__DOT__io_querySeq_37 = 0;
    vlSelf->tb__DOT__io_querySeq_38 = 0;
    vlSelf->tb__DOT__io_querySeq_39 = 0;
    vlSelf->tb__DOT__io_querySeq_40 = 0;
    vlSelf->tb__DOT__io_querySeq_41 = 0;
    vlSelf->tb__DOT__io_querySeq_42 = 0;
    vlSelf->tb__DOT__io_querySeq_43 = 0;
    vlSelf->tb__DOT__io_querySeq_44 = 0;
    vlSelf->tb__DOT__io_querySeq_45 = 0;
    vlSelf->tb__DOT__io_querySeq_46 = 0;
    vlSelf->tb__DOT__io_querySeq_47 = 0;
    vlSelf->tb__DOT__io_querySeq_48 = 0;
    vlSelf->tb__DOT__io_querySeq_49 = 0;
    vlSelf->tb__DOT__io_querySeq_50 = 0;
    vlSelf->tb__DOT__io_querySeq_51 = 0;
    vlSelf->tb__DOT__io_querySeq_52 = 0;
    vlSelf->tb__DOT__io_querySeq_53 = 0;
    vlSelf->tb__DOT__io_querySeq_54 = 0;
    vlSelf->tb__DOT__io_querySeq_55 = 0;
    vlSelf->tb__DOT__io_querySeq_56 = 0;
    vlSelf->tb__DOT__io_querySeq_57 = 0;
    vlSelf->tb__DOT__io_querySeq_58 = 0;
    vlSelf->tb__DOT__io_querySeq_59 = 0;
    vlSelf->tb__DOT__io_querySeq_60 = 0;
    vlSelf->tb__DOT__io_querySeq_61 = 0;
    vlSelf->tb__DOT__io_querySeq_62 = 0;
    vlSelf->tb__DOT__io_querySeq_63 = 0;
    vlSelf->tb__DOT__io_querySeq_64 = 0;
    vlSelf->tb__DOT__io_querySeq_65 = 0;
    vlSelf->tb__DOT__io_querySeq_66 = 0;
    vlSelf->tb__DOT__io_querySeq_67 = 0;
    vlSelf->tb__DOT__io_querySeq_68 = 0;
    vlSelf->tb__DOT__io_querySeq_69 = 0;
    vlSelf->tb__DOT__io_querySeq_70 = 0;
    vlSelf->tb__DOT__io_querySeq_71 = 0;
    vlSelf->tb__DOT__io_querySeq_72 = 0;
    vlSelf->tb__DOT__io_querySeq_73 = 0;
    vlSelf->tb__DOT__io_querySeq_74 = 0;
    vlSelf->tb__DOT__io_querySeq_75 = 0;
    vlSelf->tb__DOT__io_querySeq_76 = 0;
    vlSelf->tb__DOT__io_querySeq_77 = 0;
    vlSelf->tb__DOT__io_querySeq_78 = 0;
    vlSelf->tb__DOT__io_querySeq_79 = 0;
    vlSelf->tb__DOT__io_querySeq_80 = 0;
    vlSelf->tb__DOT__io_querySeq_81 = 0;
    vlSelf->tb__DOT__io_querySeq_82 = 0;
    vlSelf->tb__DOT__io_querySeq_83 = 0;
    vlSelf->tb__DOT__io_querySeq_84 = 0;
    vlSelf->tb__DOT__io_querySeq_85 = 0;
    vlSelf->tb__DOT__io_querySeq_86 = 0;
    vlSelf->tb__DOT__io_querySeq_87 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb__DOT__clock__0 = 0;
}

VL_ATTR_COLD void Vtb___024root___ctor_var_reset(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb___024root___ctor_var_reset_0(vlSelf);
    Vtb___024root___ctor_var_reset_1(vlSelf);
    Vtb___024root___ctor_var_reset_2(vlSelf);
}
