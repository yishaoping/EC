// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_ReferenceBank.h"
#include "Vtb__Syms.h"

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__175(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__175\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4220 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4656 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5092 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5528 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5964 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6400 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6836 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStoreFirstDelta_same_3) {
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_209 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_174) 
                        + (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_205)));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_221 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_176) 
                     + (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_217)));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_227 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_177) 
                     + (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_223)));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_234 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_175) 
                     + (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_211)));
    } else {
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_209 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_205));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_221 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_217));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_227 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_223));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_234 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_211));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2747 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7211 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11675 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16139 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20603 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25067 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29531 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_33995 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38459 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42923 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47387 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__176(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__176\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51851 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56315 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60779 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65243 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69707 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2741 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7205 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11669 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16133 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20597 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25061 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29525 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_33989 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38453 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42917 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47381 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51845 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56309 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60773 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65237 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69701 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2744 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7208 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__177(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__177\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11672 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16136 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20600 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25064 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29528 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_33992 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38456 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42920 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47384 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51848 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56312 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60776 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65240 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69704 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_72 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_37) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_68)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_84 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_39) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_80)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_90 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_40) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_86)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_97 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_74)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_72 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_68));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_84 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_80));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_90 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_86));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_97 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_74));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2765 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7229 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11693 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16157 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__178(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__178\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20621 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25085 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29549 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34013 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38477 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42941 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47405 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51869 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56333 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60797 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65261 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69725 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2759 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7223 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11687 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16151 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20615 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25079 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29543 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34007 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38471 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42935 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47399 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__179(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__179\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51863 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56327 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60791 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65255 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69719 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2762 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7226 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11690 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16154 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20618 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25082 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29546 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34010 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38474 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42938 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47402 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51866 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56330 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60794 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65258 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69722 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_3) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_209 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_174) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_205)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_221 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_176) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_217)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_209 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_205));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_221 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_217));
    }
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__180(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__180\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_3) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_227 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_177) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_223)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_234 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_175) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_211)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_227 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_223));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_234 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_211));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2783 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7247 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11711 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16175 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20639 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25103 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29567 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34031 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38495 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42959 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47423 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51887 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56351 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60815 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65279 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69743 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2777 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7241 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11705 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16169 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__181(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__181\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20633 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25097 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29561 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34025 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38489 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42953 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47417 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51881 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56345 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60809 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65273 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69737 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2780 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7244 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11708 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16172 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20636 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25100 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29564 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34028 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38492 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42956 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47420 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__182(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__182\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51884 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56348 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60812 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65276 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69740 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_6) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_346 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_311) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_342)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_358 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_313) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_354)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_364 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_314) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_360)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_371 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_312) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_348)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_346 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_342));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_358 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_354));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_364 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_360));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_371 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_348));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2801 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7265 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11729 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16193 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20657 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25121 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29585 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34049 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38513 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42977 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47441 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51905 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56369 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__183(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__183\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60833 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65297 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69761 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2795 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7259 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11723 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16187 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20651 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25115 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29579 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34043 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38507 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42971 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47435 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51899 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56363 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60827 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65291 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69755 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2798 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7262 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11726 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16190 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__184(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__184\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20654 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25118 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29582 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34046 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38510 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42974 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47438 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51902 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56366 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60830 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65294 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69758 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_9) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_483 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_448) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_479)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_495 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_450) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_491)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_501 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_451) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_497)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_508 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_449) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_485)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_483 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_479));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_495 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_491));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_501 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_497));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_508 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_485));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2819 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7283 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11747 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16211 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20675 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25139 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__185(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__185\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29603 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34067 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38531 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42995 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47459 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51923 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56387 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60851 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65315 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69779 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2813 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7277 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11741 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16205 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20669 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25133 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29597 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34061 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38525 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42989 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47453 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51917 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56381 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__186(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__186\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60845 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65309 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69773 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2816 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7280 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11744 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16208 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20672 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25136 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29600 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34064 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38528 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42992 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47456 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51920 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56384 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60848 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65312 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69776 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_12) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_620 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_585) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_616)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_632 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_587) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_628)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_638 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_588) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_634)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_645 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_586) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_622)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_620 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_616));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_632 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_628));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_638 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_634));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_645 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_622));
    }
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__187(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__187\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2837 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7301 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11765 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16229 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20693 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25157 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29621 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34085 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38549 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43013 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47477 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51941 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56405 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60869 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65333 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69797 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2831 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7295 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11759 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16223 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20687 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25151 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29615 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__188(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__188\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34079 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38543 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43007 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47471 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51935 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56399 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60863 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65327 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69791 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2834 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7298 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11762 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16226 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20690 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25154 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29618 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34082 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38546 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43010 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47474 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51938 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56402 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60866 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__189(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__189\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65330 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69794 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_15) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_757 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_722) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_753)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_769 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_724) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_765)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_775 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_725) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_771)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_782 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_723) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_759)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_757 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_753));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_769 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_765));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_775 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_771));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_782 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_759));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2855 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7319 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11783 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16247 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20711 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25175 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29639 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34103 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38567 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43031 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47495 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51959 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56423 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60887 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65351 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69815 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__190(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__190\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2849 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7313 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11777 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16241 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20705 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25169 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29633 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34097 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38561 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43025 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47489 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51953 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56417 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60881 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65345 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69809 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2852 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7316 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11780 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16244 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20708 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25172 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29636 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__191(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__191\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34100 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38564 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43028 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47492 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51956 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56420 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60884 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65348 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69812 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_18) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_894 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_859) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_890)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_906 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_861) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_902)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_912 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_862) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_908)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_919 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_860) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_896)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_894 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_890));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_906 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_902));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_912 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_908));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_919 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_896));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2873 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7337 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11801 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16265 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20729 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25193 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29657 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34121 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38585 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__192(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__192\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43049 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47513 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51977 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56441 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60905 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65369 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69833 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2867 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7331 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11795 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16259 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20723 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25187 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29651 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34115 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38579 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43043 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47507 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51971 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56435 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60899 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65363 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69827 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__193(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__193\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2870 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7334 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11798 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16262 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20726 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25190 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29654 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34118 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38582 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43046 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47510 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51974 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56438 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60902 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65366 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69830 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_21) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1031 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_996) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1027)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1043 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_998) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1039)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1049 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_999) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1045)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1056 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_997) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1033)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1031 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1027));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1043 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1039));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1049 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1045));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1056 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1033));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2891 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7355 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__194(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__194\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11819 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16283 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20747 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25211 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29675 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34139 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38603 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43067 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47531 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51995 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56459 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60923 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65387 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69851 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2885 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7349 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11813 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16277 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20741 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25205 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29669 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34133 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38597 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__195(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__195\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43061 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47525 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51989 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56453 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60917 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65381 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69845 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2888 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7352 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11816 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16280 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20744 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25208 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29672 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34136 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38600 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43064 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47528 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51992 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56456 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60920 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65384 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69848 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__196(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__196\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_24) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1168 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1133) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1164)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1180 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1135) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1176)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1186 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1136) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1182)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1193 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1134) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1170)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1168 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1164));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1180 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1176));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1186 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1182));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1193 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1170));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2909 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7373 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11837 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16301 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20765 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25229 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29693 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34157 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38621 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43085 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47549 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52013 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56477 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60941 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65405 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69869 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2903 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7367 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__197(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__197\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11831 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16295 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20759 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25223 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29687 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34151 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38615 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43079 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47543 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52007 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56471 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60935 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65399 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69863 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2906 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7370 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11834 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16298 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20762 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25226 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29690 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34154 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38618 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__198(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__198\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43082 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47546 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52010 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56474 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60938 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65402 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69866 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_27) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1305 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1270) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1301)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1317 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1272) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1313)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1323 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1273) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1319)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1330 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1271) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1307)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1305 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1301));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1317 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1313));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1323 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1319));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1330 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1307));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2927 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7391 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11855 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16319 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20783 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25247 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29711 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34175 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38639 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43103 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47567 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__199(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__199\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52031 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56495 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60959 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65423 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69887 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2921 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7385 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11849 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16313 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20777 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25241 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29705 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34169 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38633 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43097 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47561 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52025 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56489 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60953 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65417 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69881 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2924 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7388 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__200(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__200\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11852 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16316 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20780 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25244 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29708 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34172 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38636 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43100 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47564 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52028 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56492 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60956 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65420 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69884 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_30) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1442 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1407) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1438)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1454 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1409) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1450)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1460 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1410) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1456)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1467 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1408) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1444)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1442 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1438));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1454 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1450));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1460 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1456));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1467 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1444));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2945 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7409 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11873 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16337 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__201(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__201\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20801 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25265 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29729 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34193 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38657 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43121 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47585 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52049 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56513 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60977 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65441 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69905 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2939 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7403 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11867 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16331 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20795 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25259 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29723 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34187 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38651 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43115 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47579 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__202(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__202\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52043 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56507 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60971 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65435 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69899 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2942 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7406 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11870 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16334 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20798 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25262 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29726 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34190 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38654 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43118 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47582 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52046 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56510 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60974 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65438 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69902 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_33) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1579 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1544) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1575)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1591 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1546) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1587)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1579 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1575));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1591 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1587));
    }
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__203(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__203\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_33) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1597 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1547) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1593)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1604 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1545) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1581)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1597 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1593));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1604 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1581));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2963 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7427 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11891 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16355 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20819 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25283 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29747 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34211 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38675 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43139 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47603 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52067 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56531 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60995 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65459 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69923 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2957 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7421 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11885 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16349 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__204(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__204\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20813 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25277 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29741 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34205 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38669 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43133 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47597 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52061 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56525 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60989 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65453 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69917 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2960 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1735) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1700) 
              == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7424 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1735) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1700) 
              == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11888 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1735) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1700) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16352 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1735) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1700) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20816 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1735) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1700) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25280 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1735) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1700) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29744 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1735) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1700) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34208 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1735) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1700) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38672 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1735) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1700) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43136 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1735) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1700) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47600 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1735) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1700) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}
