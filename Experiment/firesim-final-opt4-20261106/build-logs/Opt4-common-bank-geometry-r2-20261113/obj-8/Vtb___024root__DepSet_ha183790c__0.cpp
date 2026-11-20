// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb___024root.h"

void Vtb___024root___eval_initial__TOP__Vtiming__0__0(Vtb___024root* vlSelf);
void Vtb___024root___eval_initial__TOP__Vtiming__0__1(Vtb___024root* vlSelf);
void Vtb___024root___eval_initial__TOP__Vtiming__0__2(Vtb___024root* vlSelf);
void Vtb___024root___eval_initial__TOP__Vtiming__0__3(Vtb___024root* vlSelf);
void Vtb___024root___eval_initial__TOP__Vtiming__0__4(Vtb___024root* vlSelf);
void Vtb___024root___eval_initial__TOP__Vtiming__0__5(Vtb___024root* vlSelf);
void Vtb___024root___eval_initial__TOP__Vtiming__0__6(Vtb___024root* vlSelf);
void Vtb___024root___eval_initial__TOP__Vtiming__0__7(Vtb___024root* vlSelf);
void Vtb___024root___eval_initial__TOP__Vtiming__0__8(Vtb___024root* vlSelf);
VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__0__9(Vtb___024root* vlSelf);
VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__0__10(Vtb___024root* vlSelf);
void Vtb___024root___eval_initial__TOP__Vtiming__0__11(Vtb___024root* vlSelf);

VL_INLINE_OPT VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__0(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb___024root___eval_initial__TOP__Vtiming__0__0(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__0__1(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__0__2(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__0__3(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__0__4(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__0__5(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__0__6(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__0__7(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__0__8(vlSelf);
    co_await Vtb___024root___eval_initial__TOP__Vtiming__0__9(vlSelf);
    co_await Vtb___024root___eval_initial__TOP__Vtiming__0__10(vlSelf);
    Vtb___024root___eval_initial__TOP__Vtiming__0__11(vlSelf);
}

void Vtb___024root___eval_initial__TOP__Vtiming__0__0(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__0__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__cycle = 0xffffffffU;
    vlSelfRef.tb__DOT__clock = 0U;
    vlSelfRef.tb__DOT__io_barrierBase = 0U;
    vlSelfRef.tb__DOT__io_barrierEvent_valid = 0U;
    vlSelfRef.tb__DOT__io_barrierEvent_bits = 0U;
    vlSelfRef.tb__DOT__io_barrierSafeWatermark = 0U;
    vlSelfRef.tb__DOT__io_barrierCurrentCycle = 0ULL;
    vlSelfRef.tb__DOT__io_base = 0U;
    vlSelfRef.tb__DOT__io_loadSources_0_key = 0U;
    vlSelfRef.tb__DOT__io_loadSources_0_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_loadSources_0_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_loadSources_0_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_loadSources_0_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_loadSources_1_key = 0U;
    vlSelfRef.tb__DOT__io_loadSources_1_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_loadSources_1_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_loadSources_1_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_loadSources_1_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_loadSources_2_key = 0U;
    vlSelfRef.tb__DOT__io_loadSources_2_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_loadSources_2_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_loadSources_2_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_loadSources_2_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_loadSources_3_key = 0U;
    vlSelfRef.tb__DOT__io_loadSources_3_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_loadSources_3_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_loadSources_3_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_loadSources_3_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_loadSources_4_key = 0U;
    vlSelfRef.tb__DOT__io_loadSources_4_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_loadSources_4_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_loadSources_4_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_loadSources_4_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_loadSources_5_key = 0U;
    vlSelfRef.tb__DOT__io_loadSources_5_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_loadSources_5_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_loadSources_5_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_loadSources_5_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_loadSources_6_key = 0U;
    vlSelfRef.tb__DOT__io_loadSources_6_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_loadSources_6_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_loadSources_6_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_loadSources_6_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_loadSources_7_key = 0U;
    vlSelfRef.tb__DOT__io_loadSources_7_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_loadSources_7_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_loadSources_7_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_loadSources_7_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_storeSources_0_key = 0U;
    vlSelfRef.tb__DOT__io_storeSources_0_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_storeSources_0_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_storeSources_0_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_storeSources_0_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_storeSources_1_key = 0U;
    vlSelfRef.tb__DOT__io_storeSources_1_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_storeSources_1_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_storeSources_1_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_storeSources_1_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_storeSources_2_key = 0U;
    vlSelfRef.tb__DOT__io_storeSources_2_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_storeSources_2_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_storeSources_2_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_storeSources_2_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_storeSources_3_key = 0U;
    vlSelfRef.tb__DOT__io_storeSources_3_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_storeSources_3_counts_words4 = 0U;
}

void Vtb___024root___eval_initial__TOP__Vtiming__0__1(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__0__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__io_storeSources_3_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_storeSources_3_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_storeSources_4_key = 0U;
    vlSelfRef.tb__DOT__io_storeSources_4_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_storeSources_4_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_storeSources_4_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_storeSources_4_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_storeSources_5_key = 0U;
    vlSelfRef.tb__DOT__io_storeSources_5_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_storeSources_5_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_storeSources_5_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_storeSources_5_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_storeSources_6_key = 0U;
    vlSelfRef.tb__DOT__io_storeSources_6_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_storeSources_6_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_storeSources_6_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_storeSources_6_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_storeSources_7_key = 0U;
    vlSelfRef.tb__DOT__io_storeSources_7_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_storeSources_7_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_storeSources_7_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_storeSources_7_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_0_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_0_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_0_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_0_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_0_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_1_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_1_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_1_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_1_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_1_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_2_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_2_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_2_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_2_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_2_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_3_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_3_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_3_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_3_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_3_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_4_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_4_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_4_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_4_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_4_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_5_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_5_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_5_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_5_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_5_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_6_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_6_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_6_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_6_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_6_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_7_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_7_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_7_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_7_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_7_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_8_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_8_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_8_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_8_counts_words8 = 0U;
}

void Vtb___024root___eval_initial__TOP__Vtiming__0__2(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__0__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__io_strictSources_8_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_9_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_9_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_9_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_9_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_9_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_10_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_10_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_10_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_10_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_10_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_11_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_11_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_11_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_11_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_11_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_12_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_12_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_12_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_12_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_12_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_13_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_13_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_13_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_13_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_13_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_14_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_14_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_14_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_14_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_14_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_15_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_15_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_15_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_15_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_15_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_16_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_16_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_16_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_16_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_16_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_17_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_17_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_17_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_17_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_17_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_18_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_18_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_18_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_18_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_18_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_19_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_19_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_19_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_19_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_19_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_20_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_20_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_20_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_20_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_20_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_21_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_21_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_21_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_21_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_21_counts_lines = 0U;
}

void Vtb___024root___eval_initial__TOP__Vtiming__0__3(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__0__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__io_strictSources_22_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_22_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_22_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_22_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_22_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_23_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_23_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_23_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_23_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_23_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_24_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_24_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_24_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_24_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_24_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_25_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_25_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_25_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_25_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_25_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_26_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_26_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_26_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_26_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_26_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_27_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_27_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_27_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_27_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_27_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_28_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_28_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_28_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_28_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_28_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_29_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_29_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_29_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_29_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_29_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_30_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_30_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_30_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_30_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_30_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_31_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_31_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_31_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_31_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_31_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_32_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_32_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_32_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_32_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_32_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_33_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_33_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_33_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_33_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_33_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_34_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_34_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_34_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_34_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_34_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_35_key = 0U;
}

void Vtb___024root___eval_initial__TOP__Vtiming__0__4(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__0__4\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__io_strictSources_35_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_35_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_35_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_35_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_36_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_36_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_36_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_36_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_36_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_37_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_37_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_37_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_37_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_37_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_38_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_38_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_38_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_38_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_38_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_39_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_39_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_39_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_39_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_39_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_40_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_40_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_40_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_40_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_40_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_41_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_41_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_41_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_41_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_41_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_42_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_42_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_42_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_42_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_42_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_43_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_43_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_43_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_43_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_43_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_44_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_44_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_44_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_44_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_44_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_45_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_45_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_45_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_45_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_45_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_46_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_46_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_46_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_46_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_46_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_47_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_47_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_47_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_47_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_47_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_48_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_48_counts_bytes = 0U;
}

void Vtb___024root___eval_initial__TOP__Vtiming__0__5(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__0__5\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__io_strictSources_48_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_48_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_48_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_49_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_49_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_49_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_49_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_49_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_50_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_50_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_50_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_50_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_50_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_51_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_51_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_51_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_51_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_51_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_52_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_52_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_52_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_52_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_52_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_53_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_53_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_53_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_53_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_53_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_54_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_54_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_54_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_54_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_54_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_55_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_55_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_55_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_55_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_55_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_56_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_56_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_56_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_56_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_56_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_57_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_57_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_57_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_57_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_57_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_58_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_58_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_58_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_58_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_58_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_59_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_59_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_59_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_59_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_59_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_60_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_60_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_60_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_60_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_60_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_61_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_61_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_61_counts_words4 = 0U;
}

void Vtb___024root___eval_initial__TOP__Vtiming__0__6(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__0__6\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__io_strictSources_61_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_61_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_62_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_62_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_62_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_62_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_62_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_63_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_63_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_63_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_63_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_63_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_64_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_64_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_64_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_64_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_64_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_65_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_65_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_65_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_65_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_65_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_66_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_66_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_66_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_66_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_66_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_67_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_67_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_67_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_67_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_67_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_68_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_68_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_68_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_68_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_68_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_69_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_69_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_69_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_69_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_69_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_70_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_70_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_70_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_70_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_70_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_71_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_71_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_71_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_71_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_71_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_72_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_72_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_72_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_72_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_72_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_73_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_73_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_73_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_73_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_73_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_74_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_74_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_74_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_74_counts_words8 = 0U;
}

void Vtb___024root___eval_initial__TOP__Vtiming__0__7(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__0__7\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__io_strictSources_74_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_75_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_75_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_75_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_75_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_75_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_76_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_76_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_76_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_76_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_76_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_77_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_77_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_77_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_77_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_77_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_78_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_78_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_78_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_78_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_78_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_strictSources_79_key = 0U;
    vlSelfRef.tb__DOT__io_strictSources_79_counts_bytes = 0U;
    vlSelfRef.tb__DOT__io_strictSources_79_counts_words4 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_79_counts_words8 = 0U;
    vlSelfRef.tb__DOT__io_strictSources_79_counts_lines = 0U;
    vlSelfRef.tb__DOT__io_newStore_bytes = 0U;
    vlSelfRef.tb__DOT__io_newStore_words4 = 0U;
    vlSelfRef.tb__DOT__io_newStore_words8 = 0U;
    vlSelfRef.tb__DOT__io_newStore_lines = 0U;
    vlSelfRef.tb__DOT__io_newFirstStore_bytes = 0U;
    vlSelfRef.tb__DOT__io_newFirstStore_words4 = 0U;
    vlSelfRef.tb__DOT__io_newFirstStore_words8 = 0U;
    vlSelfRef.tb__DOT__io_newFirstStore_lines = 0U;
    vlSelfRef.tb__DOT__io_processSeq = 0U;
    vlSelfRef.tb__DOT__io_retiringSeq = 0U;
    vlSelfRef.tb__DOT__io_processCommit = 0U;
    vlSelfRef.tb__DOT__io_safeAdvance = 0U;
    vlSelfRef.tb__DOT__io_safeError = 0U;
    vlSelfRef.tb__DOT__io_querySeq_0 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_1 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_2 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_3 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_4 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_5 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_6 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_7 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_8 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_9 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_10 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_11 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_12 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_13 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_14 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_15 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_16 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_17 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_18 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_19 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_20 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_21 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_22 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_23 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_24 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_25 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_26 = 0U;
}

void Vtb___024root___eval_initial__TOP__Vtiming__0__8(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__0__8\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__io_querySeq_27 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_28 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_29 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_30 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_31 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_32 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_33 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_34 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_35 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_36 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_37 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_38 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_39 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_40 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_41 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_42 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_43 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_44 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_45 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_46 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_47 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_48 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_49 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_50 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_51 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_52 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_53 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_54 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_55 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_56 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_57 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_58 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_59 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_60 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_61 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_62 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_63 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_64 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_65 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_66 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_67 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_68 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_69 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_70 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_71 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_72 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_73 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_74 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_75 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_76 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_77 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_78 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_79 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_80 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_81 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_82 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_83 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_84 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_85 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_86 = 0U;
    vlSelfRef.tb__DOT__io_querySeq_87 = 0U;
    vlSelfRef.tb__DOT__reset = 1U;
    vlSelfRef.tb__DOT__io_resetStats = 1U;
    vlSelfRef.tb__DOT__io_barrierResetStats = 1U;
}

VlCoroutine Vtb___024root___eval_initial__TOP__Vtiming__0__9(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__0__9\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-common-bank-geometry-r2-20261113/tb-8.v", 
                                         1191);
    vlSelfRef.tb__DOT__clock = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-common-bank-geometry-r2-20261113/tb-8.v", 
                                         1191);
    vlSelfRef.tb__DOT__clock = 0U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-common-bank-geometry-r2-20261113/tb-8.v", 
                                         1191);
    vlSelfRef.tb__DOT__cycle = 0U;
}

void Vtb___024root___eval_initial__TOP__Vtiming__0__11(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_initial__TOP__Vtiming__0__11\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_WRITEF_NX("GEOMETRY_FULL_STATE_PASS lanes=8 cycles=8192 state_bits=47168\n",0);
    VL_FINISH_MT("/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-common-bank-geometry-r2-20261113/tb-8.v", 2486, "");
}

void Vtb___024root___eval_act__0(Vtb___024root* vlSelf);
void Vtb___024root___eval_act__1(Vtb___024root* vlSelf);

void Vtb___024root___eval_act(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb___024root___eval_act__0(vlSelf);
    Vtb___024root___eval_act__1(vlSelf);
}

void Vtb___024root___eval_act__0(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_act__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vtb___024root___eval_nba__0(Vtb___024root* vlSelf);
void Vtb___024root___eval_nba__1(Vtb___024root* vlSelf);
void Vtb___024root___eval_nba__2(Vtb___024root* vlSelf);
void Vtb___024root___eval_nba__3(Vtb___024root* vlSelf);
void Vtb___024root___eval_nba__4(Vtb___024root* vlSelf);

void Vtb___024root___eval_nba(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb___024root___eval_nba__0(vlSelf);
    Vtb___024root___eval_nba__1(vlSelf);
    Vtb___024root___eval_nba__2(vlSelf);
    Vtb___024root___eval_nba__3(vlSelf);
    Vtb___024root___eval_nba__4(vlSelf);
}

void Vtb___024root___eval_nba__0(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_nba__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vtb___024root___timing_resume(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___timing_resume\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb___024root___eval_triggers__act(Vtb___024root* vlSelf);

bool Vtb___024root___eval_phase__act(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb___024root___timing_resume(vlSelf);
        Vtb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb___024root___eval_phase__nba(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__nba(Vtb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb___024root___dump_triggers__act(Vtb___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb___024root___eval(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-common-bank-geometry-r2-20261113/tb-8.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-common-bank-geometry-r2-20261113/tb-8.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb___024root___eval_debug_assertions(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
