// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_ReferenceBank.h"
#include "Vtb__Syms.h"

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__141(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__141\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5969 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6405 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6841 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketLoadFirstDelta_ordered_9 
        = ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_183) 
           <= (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_178));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_283 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
         == (IData)(vlSymsp->TOP.tb__DOT__io_base));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_719 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
         == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1155 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1591 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2027 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2463 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2899 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3335 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3771 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4207 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4643 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5079 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5515 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5951 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6387 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6823 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStoreFirstDelta_ordered_4 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_46) 
           <= (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_41));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_301 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
         == (IData)(vlSymsp->TOP.tb__DOT__io_base));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_737 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
         == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1173 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1609 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2045 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2481 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2917 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3353 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3789 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__142(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__142\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4225 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4661 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5097 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5533 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5969 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6405 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6841 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStoreFirstDelta_ordered_9 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_183) 
           <= (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_178));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2749 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (IData)(vlSymsp->TOP.tb__DOT__io_base));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7213 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11677 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16141 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20605 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25069 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29533 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_33997 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38461 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42925 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47389 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51853 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56317 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60781 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65245 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69709 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_4 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_46) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_41));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2767 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (IData)(vlSymsp->TOP.tb__DOT__io_base));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7231 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11695 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16159 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20623 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__143(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__143\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25087 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29551 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34015 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38479 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42943 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47407 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51871 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56335 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60799 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65263 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69727 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_9 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_183) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_178));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2785 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (IData)(vlSymsp->TOP.tb__DOT__io_base));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7249 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11713 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16177 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20641 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25105 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29569 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34033 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38497 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42961 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47425 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51889 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56353 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60817 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65281 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69745 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_14 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_320) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_315));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2803 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (IData)(vlSymsp->TOP.tb__DOT__io_base));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__144(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__144\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7267 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11731 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16195 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20659 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25123 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29587 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34051 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38515 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42979 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47443 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51907 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56371 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60835 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65299 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69763 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_19 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_457) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_452));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2821 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (IData)(vlSymsp->TOP.tb__DOT__io_base));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7285 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11749 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16213 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20677 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25141 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29605 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34069 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38533 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42997 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47461 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51925 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56389 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__145(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__145\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60853 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65317 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69781 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_24 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_594) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_589));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2839 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (IData)(vlSymsp->TOP.tb__DOT__io_base));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7303 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11767 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16231 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20695 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25159 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29623 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34087 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38551 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43015 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47479 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51943 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56407 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60871 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65335 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69799 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_29 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_731) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_726));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2857 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (IData)(vlSymsp->TOP.tb__DOT__io_base));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7321 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11785 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16249 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20713 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25177 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29641 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34105 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38569 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__146(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__146\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43033 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47497 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51961 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56425 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60889 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65353 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69817 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_34 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_868) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_863));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2875 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (IData)(vlSymsp->TOP.tb__DOT__io_base));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7339 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11803 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16267 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20731 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25195 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29659 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34123 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38587 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43051 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47515 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51979 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56443 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60907 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65371 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69835 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_39 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1005) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1000));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2893 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (IData)(vlSymsp->TOP.tb__DOT__io_base));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7357 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11821 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16285 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20749 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__147(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__147\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25213 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29677 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34141 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38605 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43069 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47533 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51997 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56461 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60925 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65389 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69853 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_44 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1142) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1137));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2911 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (IData)(vlSymsp->TOP.tb__DOT__io_base));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7375 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11839 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16303 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20767 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25231 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29695 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34159 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38623 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43087 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47551 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52015 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56479 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60943 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65407 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69871 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_49 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1279) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1274));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2929 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (IData)(vlSymsp->TOP.tb__DOT__io_base));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__148(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__148\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7393 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11857 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16321 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20785 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25249 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29713 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34177 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38641 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43105 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47569 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52033 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56497 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60961 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65425 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69889 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_54 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1416) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1411));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2947 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (IData)(vlSymsp->TOP.tb__DOT__io_base));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7411 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11875 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16339 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20803 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25267 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29731 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34195 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38659 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43123 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47587 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52051 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56515 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__149(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__149\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60979 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65443 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69907 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_59 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1553) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1548));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2965 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (IData)(vlSymsp->TOP.tb__DOT__io_base));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7429 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11893 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16357 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20821 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25285 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29749 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34213 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38677 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43141 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47605 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52069 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56533 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60997 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65461 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69925 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_64 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1690) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1685));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2983 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (IData)(vlSymsp->TOP.tb__DOT__io_base));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7447 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11911 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16375 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20839 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25303 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29767 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34231 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38695 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__150(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__150\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43159 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47623 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52087 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56551 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61015 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65479 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69943 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_69 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1827) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1822));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3001 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (IData)(vlSymsp->TOP.tb__DOT__io_base));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7465 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11929 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16393 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20857 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25321 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29785 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34249 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38713 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43177 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47641 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52105 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56569 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61033 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65497 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69961 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_74 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1964) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1959));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3019 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (IData)(vlSymsp->TOP.tb__DOT__io_base));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7483 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11947 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16411 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20875 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__151(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__151\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25339 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29803 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34267 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38731 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43195 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47659 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52123 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56587 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61051 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65515 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69979 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_79 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2101) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2096));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3037 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (IData)(vlSymsp->TOP.tb__DOT__io_base));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7501 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11965 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16429 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20893 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25357 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29821 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34285 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38749 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43213 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47677 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52141 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56605 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61069 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65533 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69997 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_84 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2238) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2233));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3055 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (IData)(vlSymsp->TOP.tb__DOT__io_base));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__152(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__152\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7519 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11983 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16447 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20911 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25375 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29839 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34303 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38767 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43231 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47695 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52159 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56623 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61087 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65551 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_70015 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_89 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2375) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2370));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3073 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (IData)(vlSymsp->TOP.tb__DOT__io_base));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7537 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12001 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16465 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20929 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25393 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29857 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34321 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38785 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43249 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47713 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52177 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56641 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__153(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__153\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61105 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65569 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_70033 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_94 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2512) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2507));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3091 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (IData)(vlSymsp->TOP.tb__DOT__io_base));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7555 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12019 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16483 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20947 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25411 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29875 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34339 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38803 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43267 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47731 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52195 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56659 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61123 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65587 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_70051 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_99 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2649) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2644));
    vlSelfRef.io_barrierCycleOverflow = (((IData)(vlSelfRef.__PVT___countOverflow_15_T_2) 
                                          & (vlSelfRef.buckets_requestCycleSum_15 
                                             > (0xffffffffffffffffULL 
                                                - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                         | (((IData)(vlSelfRef.__PVT___countOverflow_14_T_2) 
                                             & (vlSelfRef.__PVT__buckets_requestCycleSum_14 
                                                > (0xffffffffffffffffULL 
                                                   - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                            | (((IData)(vlSelfRef.__PVT___countOverflow_13_T_2) 
                                                & (vlSelfRef.__PVT__buckets_requestCycleSum_13 
                                                   > 
                                                   (0xffffffffffffffffULL 
                                                    - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                               | (((IData)(vlSelfRef.__PVT___countOverflow_12_T_2) 
                                                   & (vlSelfRef.__PVT__buckets_requestCycleSum_12 
                                                      > 
                                                      (0xffffffffffffffffULL 
                                                       - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                  | (((IData)(vlSelfRef.__PVT___countOverflow_11_T_2) 
                                                      & (vlSelfRef.__PVT__buckets_requestCycleSum_11 
                                                         > 
                                                         (0xffffffffffffffffULL 
                                                          - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                     | (((IData)(vlSelfRef.__PVT___countOverflow_10_T_2) 
                                                         & (vlSelfRef.__PVT__buckets_requestCycleSum_10 
                                                            > 
                                                            (0xffffffffffffffffULL 
                                                             - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                        | (((IData)(vlSelfRef.__PVT___countOverflow_9_T_2) 
                                                            & (vlSelfRef.__PVT__buckets_requestCycleSum_9 
                                                               > 
                                                               (0xffffffffffffffffULL 
                                                                - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                           | (((IData)(vlSelfRef.__PVT___countOverflow_8_T_2) 
                                                               & (vlSelfRef.__PVT__buckets_requestCycleSum_8 
                                                                  > 
                                                                  (0xffffffffffffffffULL 
                                                                   - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                              | (((IData)(vlSelfRef.__PVT___countOverflow_7_T_2) 
                                                                  & (vlSelfRef.__PVT__buckets_requestCycleSum_7 
                                                                     > 
                                                                     (0xffffffffffffffffULL 
                                                                      - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                                 | (((IData)(vlSelfRef.__PVT___countOverflow_6_T_2) 
                                                                     & (vlSelfRef.__PVT__buckets_requestCycleSum_6 
                                                                        > 
                                                                        (0xffffffffffffffffULL 
                                                                         - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                                    | (((IData)(vlSelfRef.__PVT___countOverflow_5_T_2) 
                                                                        & (vlSelfRef.__PVT__buckets_requestCycleSum_5 
                                                                           > 
                                                                           (0xffffffffffffffffULL 
                                                                            - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                                       | (((IData)(vlSelfRef.__PVT___countOverflow_4_T_2) 
                                                                           & (vlSelfRef.__PVT__buckets_requestCycleSum_4 
                                                                              > 
                                                                              (0xffffffffffffffffULL 
                                                                               - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                                          | (((IData)(vlSelfRef.__PVT___countOverflow_3_T_2) 
                                                                              & (vlSelfRef.__PVT__buckets_requestCycleSum_3 
                                                                                > 
                                                                                (0xffffffffffffffffULL 
                                                                                - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                                             | (((IData)(vlSelfRef.__PVT___countOverflow_2_T_2) 
                                                                                & (vlSelfRef.__PVT__buckets_requestCycleSum_2 
                                                                                > 
                                                                                (0xffffffffffffffffULL 
                                                                                - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                                                | (((IData)(vlSelfRef.__PVT___countOverflow_1_T_2) 
                                                                                & (vlSelfRef.__PVT__buckets_requestCycleSum_1 
                                                                                > 
                                                                                (0xffffffffffffffffULL 
                                                                                - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                                                | ((IData)(vlSelfRef.__PVT___countOverflow_0_T_2) 
                                                                                & (vlSelfRef.buckets_requestCycleSum_0 
                                                                                > 
                                                                                (0xffffffffffffffffULL 
                                                                                - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))))))))))))))))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__165(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__165\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_50 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2253) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2305 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2253) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2258 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2228) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2248));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2283 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2248) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2253));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_49 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2248) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2253));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_48 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2228) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2248));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_53 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2390) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2442 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2390) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2395 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2365) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2385));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2420 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2385) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2390));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_52 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2385) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2390));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_51 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2365) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2385));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_56 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2527) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2579 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2527) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2532 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2502) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2522));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2557 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2522) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2527));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_55 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2522) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2527));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_54 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2502) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2522));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_59 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2664) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2716 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2664) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2669 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2639) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2659));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2694 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2659) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2664));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_58 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2659) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2664));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_57 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2639) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2659));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_281 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_717 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1153 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1589 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2025 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2461 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2897 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3333 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3769 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__166(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__166\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4205 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4641 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5077 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5513 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5949 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6385 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6821 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_275 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_711 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1147 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1583 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2019 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2455 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2891 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3327 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3763 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4199 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4635 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5071 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5507 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5943 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6379 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6815 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__167(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__167\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_278 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_714 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1150 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1586 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2022 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2458 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2894 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3330 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3766 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4202 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4638 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5074 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5510 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5946 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6382 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6818 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketLoadFirstDelta_same) {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_72 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_37) 
                        + (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_68)));
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_84 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_39) 
                     + (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_80)));
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_90 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_40) 
                     + (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_86)));
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_97 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_38) 
                     + (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_74)));
    } else {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_72 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_68));
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_84 
            = (7U & (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_80));
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_90 
            = (3U & (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_86));
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_97 
            = (7U & (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_74));
    }
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_299 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_735 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1171 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__168(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__168\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1607 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2043 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2479 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2915 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3351 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3787 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4223 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4659 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5095 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5531 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5967 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6403 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6839 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_293 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_729 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1165 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1601 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2037 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2473 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2909 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3345 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3781 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4217 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__169(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__169\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4653 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5089 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5525 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5961 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6397 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6833 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_296 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_732 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1168 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1604 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2040 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2476 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2912 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3348 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3784 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4220 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4656 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5092 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5528 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5964 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6400 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6836 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_209 = 
        (0x1fU & ((IData)(vlSelfRef.__PVT__bucketLoadFirstDelta_same_3)
                   ? ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_174) 
                      + (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_205))
                   : (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_205)));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__170(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__170\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketLoadFirstDelta_same_3) {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_221 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_176) 
                     + (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_217)));
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_227 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_177) 
                     + (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_223)));
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_234 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_175) 
                     + (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_211)));
    } else {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_221 
            = (7U & (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_217));
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_227 
            = (3U & (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_223));
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_234 
            = (7U & (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_211));
    }
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_281 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
            == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_717 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
            == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1153 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1589 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2025 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2461 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2897 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3333 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3769 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4205 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4641 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5077 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5513 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5949 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6385 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6821 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_275 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
            == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_711 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
            == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1147 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1583 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__171(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__171\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2019 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2455 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2891 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3327 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3763 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4199 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4635 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5071 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5507 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5943 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6379 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6815 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_278 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
            == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_714 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
            == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1150 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1586 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2022 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2458 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2894 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3330 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3766 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4202 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4638 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__172(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__172\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5074 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5510 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5946 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6382 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6818 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStoreFirstDelta_same) {
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_72 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_37) 
                        + (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_68)));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_84 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_39) 
                     + (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_80)));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_90 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_40) 
                     + (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_86)));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_97 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_38) 
                     + (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_74)));
    } else {
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_72 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_68));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_84 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_80));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_90 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_86));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_97 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_74));
    }
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_299 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
            == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_735 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
            == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1171 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1607 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2043 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2479 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2915 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3351 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3787 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4223 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4659 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5095 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5531 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5967 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__173(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__173\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6403 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6839 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_293 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
            == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_729 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
            == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1165 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1601 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2037 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2473 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2909 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3345 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3781 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4217 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4653 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5089 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5525 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5961 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6397 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6833 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_296 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
            == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_732 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
            == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1168 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1604 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2040 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__174(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__174\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2476 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2912 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3348 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3784 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4220 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4656 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5092 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5528 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5964 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6400 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6836 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
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
              == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7211 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11675 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16139 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20603 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25067 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29531 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_33995 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__175(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__175\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38459 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42923 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47387 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51851 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56315 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60779 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65243 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69707 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2741 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7205 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11669 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16133 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20597 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25061 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29525 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_33989 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38453 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42917 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47381 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51845 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56309 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60773 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65237 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__176(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__176\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69701 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2744 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7208 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11672 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16136 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20600 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25064 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29528 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_33992 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38456 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42920 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47384 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51848 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56312 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60776 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65240 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69704 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
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
              == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7229 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__177(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__177\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11693 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16157 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20621 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25085 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29549 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34013 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38477 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42941 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47405 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51869 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56333 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60797 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65261 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69725 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2759 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7223 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11687 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16151 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20615 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25079 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29543 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34007 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38471 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__178(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__178\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42935 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47399 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51863 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56327 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60791 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65255 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69719 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2762 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7226 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11690 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16154 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20618 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25082 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29546 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34010 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38474 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42938 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47402 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51866 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56330 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60794 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65258 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69722 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__179(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__179\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_3) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_209 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_174) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_205)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_221 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_176) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_217)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_227 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_177) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_223)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_234 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_175) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_211)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_209 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_205));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_221 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_217));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_227 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_223));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_234 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_211));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2783 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7247 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11711 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16175 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20639 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25103 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29567 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34031 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38495 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42959 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47423 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51887 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56351 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60815 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65279 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69743 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2777 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7241 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11705 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__180(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__180\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16169 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20633 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25097 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29561 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34025 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38489 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42953 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47417 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51881 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56345 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60809 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65273 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69737 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2780 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7244 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11708 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16172 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20636 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25100 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29564 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34028 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38492 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42956 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__181(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__181\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47420 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51884 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56348 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60812 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0xdU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65276 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0xeU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69740 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0xfU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
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
              == (IData)(vlSymsp->TOP.tb__DOT__io_base)));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7265 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(1U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11729 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(2U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16193 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(3U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20657 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(4U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25121 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(5U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29585 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(6U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34049 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(7U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38513 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(8U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42977 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(9U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47441 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0xaU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51905 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0xbU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56369 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0xcU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}
