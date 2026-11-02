// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTestHarness.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTestHarness___024root.h"

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__343(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__343\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_h8bf500b0__0;
    VlWide<4>/*127:0*/ __Vtemp_h9edaa68e__0;
    // Body
    if ((0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__gennum))) {
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aToggle_r 
            = vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__dToggle;
    }
    if (vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___T_1) {
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__saved_address 
            = (0x3ffffU & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address);
    }
    if (vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___T_1) {
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_address 
            = (0x1fffffffU & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address);
    }
    if (vlSelf->reset) {
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__beatsLeft = 0U;
        vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__maybe_full = 0U;
    } else {
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__beatsLeft 
            = (7U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__latch)
                      ? ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__winnerQual_0) 
                           & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])
                           ? (~ (0x3ffU & (((IData)(0x3fU) 
                                            << (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__bundleIn_0_d_bits_size)) 
                                           >> 3U)))
                           : 0U) | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__winnerQual_1)
                                     ? (~ (0x3ffU & 
                                           (((IData)(0x3fU) 
                                             << (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__bundleIn_0_d_bits_size)) 
                                            >> 3U)))
                                     : 0U)) : ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__beatsLeft) 
                                               - ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___outArb_io_in_1_ready) 
                                                  & (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_valid)))));
        if (((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_enq) 
             != (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_deq))) {
            vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__maybe_full 
                = vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_enq;
        }
    }
    if (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__do_enq) {
        __Vtemp_h8bf500b0__0[0U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_mask)) 
                                             << 0x2bU) 
                                            | (((QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_address)) 
                                                << 0xbU) 
                                               | (QData)((IData)(
                                                                 (((IData)(vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_size) 
                                                                   << 6U) 
                                                                  | ((7U 
                                                                      == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state))
                                                                      ? 1U
                                                                      : 4U)))))));
        __Vtemp_h8bf500b0__0[1U] = (((IData)(((7U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state))
                                               ? (((QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__body_1)) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__body_0)))
                                               : 0ULL)) 
                                     << 0x13U) | (IData)(
                                                         ((((QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_mask)) 
                                                            << 0x2bU) 
                                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_address)) 
                                                               << 0xbU) 
                                                              | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_size) 
                                                                                << 6U) 
                                                                                | ((7U 
                                                                                == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state))
                                                                                 ? 1U
                                                                                 : 4U)))))) 
                                                          >> 0x20U)));
        __Vtemp_h8bf500b0__0[2U] = (((IData)(((7U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state))
                                               ? (((QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__body_1)) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__body_0)))
                                               : 0ULL)) 
                                     >> 0xdU) | ((IData)(
                                                         (((7U 
                                                            == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state))
                                                            ? 
                                                           (((QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__body_1)) 
                                                             << 0x20U) 
                                                            | (QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__body_0)))
                                                            : 0ULL) 
                                                          >> 0x20U)) 
                                                 << 0x13U));
        __Vtemp_h8bf500b0__0[3U] = ((IData)((((7U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state))
                                               ? (((QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__body_1)) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__body_0)))
                                               : 0ULL) 
                                             >> 0x20U)) 
                                    >> 0xdU);
        VL_EXTEND_WW(116,115, __Vtemp_h9edaa68e__0, __Vtemp_h8bf500b0__0);
        vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0[0U] 
            = __Vtemp_h9edaa68e__0[0U];
        vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0[1U] 
            = __Vtemp_h9edaa68e__0[1U];
        vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0[2U] 
            = __Vtemp_h9edaa68e__0[2U];
        vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0[3U] 
            = __Vtemp_h9edaa68e__0[3U];
        vlSelf->__Vdlyvset__TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0 = 1U;
        vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__enq_ptr_value;
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__344(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__344\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h218a928d__0;
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__full 
        = ((~ (IData)(vlSelf->reset)) & ((~ (((IData)(vlSelf->TestHarness__DOT__ram__DOT___xbar_auto_out_1_d_ready) 
                                              & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_deq_valid_output)) 
                                             & (~ (IData)(
                                                          (0U 
                                                           != (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__old_gennum1)))))) 
                                         & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___T_1) 
                                            | (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__full))));
    if (vlSelf->reset) {
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value = 0U;
    } else if (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_enq) {
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value 
            = (1U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value) 
                     - (IData)(1U)));
    }
    if (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_enq) {
        VL_EXTEND_WQ(65,64, __Vtemp_h218a928d__0, ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_mux)
                                                    ? 
                                                   (((QData)((IData)(
                                                                     (((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_7) 
                                                                       << 0x18U) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_6) 
                                                                          << 0x10U) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_5) 
                                                                             << 8U) 
                                                                            | (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_4)))))) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      (((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_3) 
                                                                        << 0x18U) 
                                                                       | (((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_2) 
                                                                           << 0x10U) 
                                                                          | (((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_1) 
                                                                              << 8U) 
                                                                             | (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_0)))))))
                                                    : 
                                                   (((QData)((IData)(
                                                                     ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__REG)
                                                                         ? (IData)(
                                                                                (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata 
                                                                                >> 0x38U))
                                                                         : (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_7)) 
                                                                       << 0x18U) 
                                                                      | ((0xff0000U 
                                                                          & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__REG)
                                                                               ? (IData)(
                                                                                (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata 
                                                                                >> 0x30U))
                                                                               : (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_6)) 
                                                                             << 0x10U)) 
                                                                         | ((0xff00U 
                                                                             & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__REG)
                                                                                 ? (IData)(
                                                                                (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata 
                                                                                >> 0x28U))
                                                                                 : (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_5)) 
                                                                                << 8U)) 
                                                                            | (0xffU 
                                                                               & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__REG)
                                                                                 ? (IData)(
                                                                                (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata 
                                                                                >> 0x20U))
                                                                                 : (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_4)))))))) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__REG)
                                                                          ? (IData)(
                                                                                (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata 
                                                                                >> 0x18U))
                                                                          : (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_3)) 
                                                                        << 0x18U) 
                                                                       | ((0xff0000U 
                                                                           & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__REG)
                                                                                ? (IData)(
                                                                                (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata 
                                                                                >> 0x10U))
                                                                                : (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_2)) 
                                                                              << 0x10U)) 
                                                                          | ((0xff00U 
                                                                              & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__REG)
                                                                                 ? (IData)(
                                                                                (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata 
                                                                                >> 8U))
                                                                                 : (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_1)) 
                                                                                << 8U)) 
                                                                             | (0xffU 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__REG)
                                                                                 ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata)
                                                                                 : (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_0)))))))))));
        vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0[0U] 
            = ((__Vtemp_h218a928d__0[0U] << 0x11U) 
               | (((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__in_d_bits_source) 
                   << 7U) | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_mux)
                                ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_size)
                                : (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_size)) 
                              << 5U) | (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__in_d_bits_opcode))));
        vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0[1U] 
            = ((__Vtemp_h218a928d__0[0U] >> 0xfU) | 
               (__Vtemp_h218a928d__0[1U] << 0x11U));
        vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0[2U] 
            = ((__Vtemp_h218a928d__0[1U] >> 0xfU) | 
               (__Vtemp_h218a928d__0[2U] << 0x11U));
        vlSelf->__Vdlyvset__TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0 = 1U;
        vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value;
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__345(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__345\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_h781919af__0;
    VlWide<5>/*159:0*/ __Vtemp_h9ba2d8d2__0;
    VlWide<5>/*159:0*/ __Vtemp_h00fcbd75__0;
    VlWide<5>/*159:0*/ __Vtemp_h246ca6db__0;
    VlWide<5>/*159:0*/ __Vtemp_h7c30b3f9__0;
    VlWide<5>/*159:0*/ __Vtemp_h5b40d30a__0;
    VlWide<5>/*159:0*/ __Vtemp_h2da0a8a7__0;
    VlWide<5>/*159:0*/ __Vtemp_h4b068124__0;
    // Body
    if (vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___T_1) {
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__saved_opcode 
            = (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                     >> 0x15U));
    }
    if (vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___T_1) {
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_source 
            = (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                       >> 0xaU));
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_opcode 
            = (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                     >> 0x15U));
    }
    VL_EXTEND_WI(131,4, __Vtemp_h781919af__0, ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT___T_662)
                                                ? (1U 
                                                   | (0xeU 
                                                      & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                         >> 0xdU)))
                                                : 0U));
    VL_EXTEND_WI(129,4, __Vtemp_h9ba2d8d2__0, (0xfU 
                                               & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                  >> 0xaU)));
    __Vtemp_h00fcbd75__0[0U] = (__Vtemp_h9ba2d8d2__0[0U] 
                                << 2U);
    __Vtemp_h00fcbd75__0[1U] = ((__Vtemp_h9ba2d8d2__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__0[1U] 
                                              << 2U));
    __Vtemp_h00fcbd75__0[2U] = ((__Vtemp_h9ba2d8d2__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__0[2U] 
                                              << 2U));
    __Vtemp_h00fcbd75__0[3U] = ((__Vtemp_h9ba2d8d2__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__0[3U] 
                                              << 2U));
    __Vtemp_h00fcbd75__0[4U] = ((__Vtemp_h9ba2d8d2__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__0[4U] 
                                              << 2U));
    VL_SHIFTL_WWW(131,131,131, __Vtemp_h246ca6db__0, __Vtemp_h781919af__0, __Vtemp_h00fcbd75__0);
    __Vtemp_h7c30b3f9__0[0U] = 0xfU;
    __Vtemp_h7c30b3f9__0[1U] = 0U;
    __Vtemp_h7c30b3f9__0[2U] = 0U;
    __Vtemp_h7c30b3f9__0[3U] = 0U;
    __Vtemp_h7c30b3f9__0[4U] = 0U;
    VL_EXTEND_WI(141,4, __Vtemp_h5b40d30a__0, (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_source));
    __Vtemp_h2da0a8a7__0[0U] = (__Vtemp_h5b40d30a__0[0U] 
                                << 2U);
    __Vtemp_h2da0a8a7__0[1U] = ((__Vtemp_h5b40d30a__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h5b40d30a__0[1U] 
                                              << 2U));
    __Vtemp_h2da0a8a7__0[2U] = ((__Vtemp_h5b40d30a__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h5b40d30a__0[2U] 
                                              << 2U));
    __Vtemp_h2da0a8a7__0[3U] = ((__Vtemp_h5b40d30a__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h5b40d30a__0[3U] 
                                              << 2U));
    __Vtemp_h2da0a8a7__0[4U] = ((__Vtemp_h5b40d30a__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h5b40d30a__0[4U] 
                                              << 2U));
    VL_SHIFTL_WWW(143,143,143, __Vtemp_h4b068124__0, __Vtemp_h7c30b3f9__0, __Vtemp_h2da0a8a7__0);
    if (vlSelf->reset) {
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value = 0U;
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter_2 = 0U;
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__inflight_sizes = 0ULL;
    } else {
        if (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_deq) {
            vlSelf->__Vdly__TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value 
                = (1U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value) 
                         - (IData)(1U)));
        }
        if (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1347) {
            vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter_2 
                = (0x1ffU & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_2)
                              ? ((0x200000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)
                                  ? (~ (((0x1aU >= 
                                          (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                   >> 0xeU)))
                                          ? (0x7ffffffU 
                                             & ((IData)(0xfffU) 
                                                << 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                    >> 0xeU))))
                                          : 0U) >> 3U))
                                  : 0U) : ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter_2) 
                                           - (IData)(1U))));
        }
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__inflight_sizes 
            = (0xffffffffffULL & ((vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__inflight_sizes 
                                   | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT___T_662)
                                       ? (((QData)((IData)(
                                                           __Vtemp_h246ca6db__0[1U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            __Vtemp_h246ca6db__0[0U])))
                                       : 0ULL)) & (~ 
                                                   ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT___T_677)
                                                     ? 
                                                    (((QData)((IData)(
                                                                      __Vtemp_h4b068124__0[1U])) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       __Vtemp_h4b068124__0[0U])))
                                                     : 0ULL))));
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__346(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__346\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_ha9192de5__0;
    VlWide<5>/*159:0*/ __Vtemp_h9ba2d8d2__0;
    VlWide<5>/*159:0*/ __Vtemp_h00fcbd75__0;
    VlWide<5>/*159:0*/ __Vtemp_hbfb18001__0;
    VlWide<5>/*159:0*/ __Vtemp_h7c30b3f9__0;
    VlWide<5>/*159:0*/ __Vtemp_h5b40d30a__0;
    VlWide<5>/*159:0*/ __Vtemp_h2da0a8a7__0;
    VlWide<5>/*159:0*/ __Vtemp_h4b068124__0;
    // Body
    VL_EXTEND_WI(131,4, __Vtemp_ha9192de5__0, ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT___T_662)
                                                ? (1U 
                                                   | (0xeU 
                                                      & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                         >> 0x14U)))
                                                : 0U));
    VL_EXTEND_WI(129,4, __Vtemp_h9ba2d8d2__0, (0xfU 
                                               & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                  >> 0xaU)));
    __Vtemp_h00fcbd75__0[0U] = (__Vtemp_h9ba2d8d2__0[0U] 
                                << 2U);
    __Vtemp_h00fcbd75__0[1U] = ((__Vtemp_h9ba2d8d2__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__0[1U] 
                                              << 2U));
    __Vtemp_h00fcbd75__0[2U] = ((__Vtemp_h9ba2d8d2__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__0[2U] 
                                              << 2U));
    __Vtemp_h00fcbd75__0[3U] = ((__Vtemp_h9ba2d8d2__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__0[3U] 
                                              << 2U));
    __Vtemp_h00fcbd75__0[4U] = ((__Vtemp_h9ba2d8d2__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__0[4U] 
                                              << 2U));
    VL_SHIFTL_WWW(131,131,131, __Vtemp_hbfb18001__0, __Vtemp_ha9192de5__0, __Vtemp_h00fcbd75__0);
    __Vtemp_h7c30b3f9__0[0U] = 0xfU;
    __Vtemp_h7c30b3f9__0[1U] = 0U;
    __Vtemp_h7c30b3f9__0[2U] = 0U;
    __Vtemp_h7c30b3f9__0[3U] = 0U;
    __Vtemp_h7c30b3f9__0[4U] = 0U;
    VL_EXTEND_WI(141,4, __Vtemp_h5b40d30a__0, (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_source));
    __Vtemp_h2da0a8a7__0[0U] = (__Vtemp_h5b40d30a__0[0U] 
                                << 2U);
    __Vtemp_h2da0a8a7__0[1U] = ((__Vtemp_h5b40d30a__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h5b40d30a__0[1U] 
                                              << 2U));
    __Vtemp_h2da0a8a7__0[2U] = ((__Vtemp_h5b40d30a__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h5b40d30a__0[2U] 
                                              << 2U));
    __Vtemp_h2da0a8a7__0[3U] = ((__Vtemp_h5b40d30a__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h5b40d30a__0[3U] 
                                              << 2U));
    __Vtemp_h2da0a8a7__0[4U] = ((__Vtemp_h5b40d30a__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h5b40d30a__0[4U] 
                                              << 2U));
    VL_SHIFTL_WWW(143,143,143, __Vtemp_h4b068124__0, __Vtemp_h7c30b3f9__0, __Vtemp_h2da0a8a7__0);
    if (vlSelf->reset) {
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__inflight_opcodes = 0ULL;
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__inflight = 0U;
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__a_first_counter_1 = 0U;
    } else {
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__inflight_opcodes 
            = (0xffffffffffULL & ((vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__inflight_opcodes 
                                   | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT___T_662)
                                       ? (((QData)((IData)(
                                                           __Vtemp_hbfb18001__0[1U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            __Vtemp_hbfb18001__0[0U])))
                                       : 0ULL)) & (~ 
                                                   ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT___T_677)
                                                     ? 
                                                    (((QData)((IData)(
                                                                      __Vtemp_h4b068124__0[1U])) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       __Vtemp_h4b068124__0[0U])))
                                                     : 0ULL))));
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__inflight 
            = (0x3ffU & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__inflight) 
                          | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT___T_662)
                              ? (0xffffU & ((IData)(1U) 
                                            << (0xfU 
                                                & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                   >> 0xaU))))
                              : 0U)) & (~ ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT___T_677)
                                            ? (0xffffU 
                                               & ((IData)(1U) 
                                                  << (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_source)))
                                            : 0U))));
        if (vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT___T_731) {
            vlSelf->__Vdly__TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__a_first_counter_1 
                = (7U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__a_first_1)
                          ? ((0x800000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)
                              ? 0U : (~ (((0xcU >= 
                                           (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                  >> 0xeU)))
                                           ? (0x1fffU 
                                              & ((IData)(0x3fU) 
                                                 << 
                                                 (7U 
                                                  & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                     >> 0xeU))))
                                           : 0U) >> 3U)))
                          : ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__a_first_counter_1) 
                             - (IData)(1U))));
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__347(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__347\n"); );
    // Body
    if (vlSelf->reset) {
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter_1 = 0U;
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1 = 0U;
        vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__inflight_sizes = 0U;
    } else {
        if (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1347) {
            vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter_1 
                = (0x1ffU & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_1)
                              ? ((0x200000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)
                                  ? (~ (((0x1aU >= 
                                          (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                   >> 0xeU)))
                                          ? (0x7ffffffU 
                                             & ((IData)(0xfffU) 
                                                << 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                    >> 0xeU))))
                                          : 0U) >> 3U))
                                  : 0U) : ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter_1) 
                                           - (IData)(1U))));
        }
        if (vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_674) {
            vlSelf->__Vdly__TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1 
                = (7U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__a_first_1)
                          ? ((0x800000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)
                              ? 0U : (~ (((0xcU >= 
                                           (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                  >> 0xeU)))
                                           ? (0x1fffU 
                                              & ((IData)(0x3fU) 
                                                 << 
                                                 (7U 
                                                  & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                     >> 0xeU))))
                                           : 0U) >> 3U)))
                          : ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1) 
                             - (IData)(1U))));
        }
        vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__inflight_sizes 
            = (0xffU & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__inflight_sizes) 
                         | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1198)
                             ? ((0x13U >= (8U & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                 >> 7U)))
                                 ? (0xfffffU & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1198)
                                                  ? 
                                                 (1U 
                                                  | (0x1eU 
                                                     & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                        >> 5U)))
                                                  : 0U) 
                                                << 
                                                (8U 
                                                 & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 7U))))
                                 : 0U) : 0U)) & (~ 
                                                 ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1213)
                                                   ? 
                                                  ((0x1eU 
                                                    >= 
                                                    (8U 
                                                     & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                        >> 7U)))
                                                    ? 
                                                   (0x7fffffffU 
                                                    & ((IData)(0xffU) 
                                                       << 
                                                       (8U 
                                                        & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                           >> 7U))))
                                                    : 0U)
                                                   : 0U))));
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__348(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__348\n"); );
    // Body
    if (vlSelf->reset) {
        vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__inflight_opcodes = 0U;
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__inflight = 0U;
    } else {
        vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__inflight_opcodes 
            = (0xfU & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__inflight_opcodes) 
                        | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1198)
                            ? ((0x12U >= (4U & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 8U)))
                                ? (0x7ffffU & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1198)
                                                 ? 
                                                (1U 
                                                 | (0xeU 
                                                    & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       << 1U)))
                                                 : 0U) 
                                               << (4U 
                                                   & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 8U))))
                                : 0U) : 0U)) & (~ ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1213)
                                                    ? 
                                                   ((0x1eU 
                                                     >= 
                                                     (4U 
                                                      & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                         >> 8U)))
                                                     ? 
                                                    (0x7fffffffU 
                                                     & ((IData)(0xfU) 
                                                        << 
                                                        (4U 
                                                         & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                            >> 8U))))
                                                     : 0U)
                                                    : 0U))));
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__inflight 
            = (0x3ffU & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__inflight) 
                          | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__a_first_done)
                              ? (0xffffU & ((IData)(1U) 
                                            << (0xfU 
                                                & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                   >> 0xaU))))
                              : 0U)) & (~ ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT___T_605)
                                            ? (0xffffU 
                                               & ((IData)(1U) 
                                                  << 
                                                  (0xfU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_source) 
                                                      >> 4U))))
                                            : 0U))));
    }
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__inflight 
        = ((~ (IData)(vlSelf->reset)) & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__inflight) 
                                          | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1198) 
                                             & (~ (
                                                   vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)))) 
                                         & (~ ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1213) 
                                               & (~ 
                                                  (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                   >> 0xaU))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__349(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__349\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_h3ee849d2__0;
    VlWide<5>/*159:0*/ __Vtemp_h9ba2d8d2__0;
    VlWide<5>/*159:0*/ __Vtemp_h00fcbd75__0;
    VlWide<5>/*159:0*/ __Vtemp_h35534056__0;
    VlWide<5>/*159:0*/ __Vtemp_h7c30b3f9__0;
    VlWide<5>/*159:0*/ __Vtemp_h0a796e82__0;
    VlWide<5>/*159:0*/ __Vtemp_h04a14b88__0;
    VlWide<5>/*159:0*/ __Vtemp_hc42d0589__0;
    VlWide<5>/*159:0*/ __Vtemp_h1295ad74__0;
    VlWide<5>/*159:0*/ __Vtemp_h9ba2d8d2__1;
    VlWide<5>/*159:0*/ __Vtemp_hc6e8c5fe__0;
    VlWide<5>/*159:0*/ __Vtemp_hda9e8c26__0;
    VlWide<5>/*159:0*/ __Vtemp_h7c30b3f9__1;
    VlWide<5>/*159:0*/ __Vtemp_h0a796e82__1;
    VlWide<5>/*159:0*/ __Vtemp_h08bf3b9f__0;
    VlWide<5>/*159:0*/ __Vtemp_hd91f7bc1__0;
    // Body
    VL_EXTEND_WI(131,4, __Vtemp_h3ee849d2__0, ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__a_first_done)
                                                ? (1U 
                                                   | (0xeU 
                                                      & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                         >> 0x14U)))
                                                : 0U));
    VL_EXTEND_WI(129,4, __Vtemp_h9ba2d8d2__0, (0xfU 
                                               & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                  >> 0xaU)));
    __Vtemp_h00fcbd75__0[0U] = (__Vtemp_h9ba2d8d2__0[0U] 
                                << 2U);
    __Vtemp_h00fcbd75__0[1U] = ((__Vtemp_h9ba2d8d2__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__0[1U] 
                                              << 2U));
    __Vtemp_h00fcbd75__0[2U] = ((__Vtemp_h9ba2d8d2__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__0[2U] 
                                              << 2U));
    __Vtemp_h00fcbd75__0[3U] = ((__Vtemp_h9ba2d8d2__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__0[3U] 
                                              << 2U));
    __Vtemp_h00fcbd75__0[4U] = ((__Vtemp_h9ba2d8d2__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__0[4U] 
                                              << 2U));
    VL_SHIFTL_WWW(131,131,131, __Vtemp_h35534056__0, __Vtemp_h3ee849d2__0, __Vtemp_h00fcbd75__0);
    __Vtemp_h7c30b3f9__0[0U] = 0xfU;
    __Vtemp_h7c30b3f9__0[1U] = 0U;
    __Vtemp_h7c30b3f9__0[2U] = 0U;
    __Vtemp_h7c30b3f9__0[3U] = 0U;
    __Vtemp_h7c30b3f9__0[4U] = 0U;
    VL_EXTEND_WI(141,4, __Vtemp_h0a796e82__0, (0xfU 
                                               & ((IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_source) 
                                                  >> 4U)));
    __Vtemp_h04a14b88__0[0U] = (__Vtemp_h0a796e82__0[0U] 
                                << 2U);
    __Vtemp_h04a14b88__0[1U] = ((__Vtemp_h0a796e82__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h0a796e82__0[1U] 
                                              << 2U));
    __Vtemp_h04a14b88__0[2U] = ((__Vtemp_h0a796e82__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h0a796e82__0[2U] 
                                              << 2U));
    __Vtemp_h04a14b88__0[3U] = ((__Vtemp_h0a796e82__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h0a796e82__0[3U] 
                                              << 2U));
    __Vtemp_h04a14b88__0[4U] = ((__Vtemp_h0a796e82__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h0a796e82__0[4U] 
                                              << 2U));
    VL_SHIFTL_WWW(143,143,143, __Vtemp_hc42d0589__0, __Vtemp_h7c30b3f9__0, __Vtemp_h04a14b88__0);
    VL_EXTEND_WI(131,4, __Vtemp_h1295ad74__0, ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__a_first_done)
                                                ? (1U 
                                                   | (0xeU 
                                                      & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                         >> 0xdU)))
                                                : 0U));
    VL_EXTEND_WI(129,4, __Vtemp_h9ba2d8d2__1, (0xfU 
                                               & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                  >> 0xaU)));
    __Vtemp_hc6e8c5fe__0[0U] = (__Vtemp_h9ba2d8d2__1[0U] 
                                << 2U);
    __Vtemp_hc6e8c5fe__0[1U] = ((__Vtemp_h9ba2d8d2__1[0U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__1[1U] 
                                              << 2U));
    __Vtemp_hc6e8c5fe__0[2U] = ((__Vtemp_h9ba2d8d2__1[1U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__1[2U] 
                                              << 2U));
    __Vtemp_hc6e8c5fe__0[3U] = ((__Vtemp_h9ba2d8d2__1[2U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__1[3U] 
                                              << 2U));
    __Vtemp_hc6e8c5fe__0[4U] = ((__Vtemp_h9ba2d8d2__1[3U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__1[4U] 
                                              << 2U));
    VL_SHIFTL_WWW(131,131,131, __Vtemp_hda9e8c26__0, __Vtemp_h1295ad74__0, __Vtemp_hc6e8c5fe__0);
    __Vtemp_h7c30b3f9__1[0U] = 0xfU;
    __Vtemp_h7c30b3f9__1[1U] = 0U;
    __Vtemp_h7c30b3f9__1[2U] = 0U;
    __Vtemp_h7c30b3f9__1[3U] = 0U;
    __Vtemp_h7c30b3f9__1[4U] = 0U;
    VL_EXTEND_WI(141,4, __Vtemp_h0a796e82__1, (0xfU 
                                               & ((IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_source) 
                                                  >> 4U)));
    __Vtemp_h08bf3b9f__0[0U] = (__Vtemp_h0a796e82__1[0U] 
                                << 2U);
    __Vtemp_h08bf3b9f__0[1U] = ((__Vtemp_h0a796e82__1[0U] 
                                 >> 0x1eU) | (__Vtemp_h0a796e82__1[1U] 
                                              << 2U));
    __Vtemp_h08bf3b9f__0[2U] = ((__Vtemp_h0a796e82__1[1U] 
                                 >> 0x1eU) | (__Vtemp_h0a796e82__1[2U] 
                                              << 2U));
    __Vtemp_h08bf3b9f__0[3U] = ((__Vtemp_h0a796e82__1[2U] 
                                 >> 0x1eU) | (__Vtemp_h0a796e82__1[3U] 
                                              << 2U));
    __Vtemp_h08bf3b9f__0[4U] = ((__Vtemp_h0a796e82__1[3U] 
                                 >> 0x1eU) | (__Vtemp_h0a796e82__1[4U] 
                                              << 2U));
    VL_SHIFTL_WWW(143,143,143, __Vtemp_hd91f7bc1__0, __Vtemp_h7c30b3f9__1, __Vtemp_h08bf3b9f__0);
    if (vlSelf->reset) {
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__inflight_opcodes = 0ULL;
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__inflight_sizes = 0ULL;
    } else {
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__inflight_opcodes 
            = (0xffffffffffULL & ((vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__inflight_opcodes 
                                   | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__a_first_done)
                                       ? (((QData)((IData)(
                                                           __Vtemp_h35534056__0[1U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            __Vtemp_h35534056__0[0U])))
                                       : 0ULL)) & (~ 
                                                   ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT___T_605)
                                                     ? 
                                                    (((QData)((IData)(
                                                                      __Vtemp_hc42d0589__0[1U])) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       __Vtemp_hc42d0589__0[0U])))
                                                     : 0ULL))));
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__inflight_sizes 
            = (0xffffffffffULL & ((vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__inflight_sizes 
                                   | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__a_first_done)
                                       ? (((QData)((IData)(
                                                           __Vtemp_hda9e8c26__0[1U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            __Vtemp_hda9e8c26__0[0U])))
                                       : 0ULL)) & (~ 
                                                   ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT___T_605)
                                                     ? 
                                                    (((QData)((IData)(
                                                                      __Vtemp_hd91f7bc1__0[1U])) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       __Vtemp_hd91f7bc1__0[0U])))
                                                     : 0ULL))));
    }
    if (vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___T_1) {
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__saved_source 
            = (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                       >> 0xaU));
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__350(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__350\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_h028a790a__0;
    VlWide<5>/*159:0*/ __Vtemp_h9ba2d8d2__0;
    VlWide<5>/*159:0*/ __Vtemp_h00fcbd75__0;
    VlWide<5>/*159:0*/ __Vtemp_hf53c6003__0;
    VlWide<5>/*159:0*/ __Vtemp_h7c30b3f9__0;
    VlWide<5>/*159:0*/ __Vtemp_hf1ebcc8c__0;
    VlWide<5>/*159:0*/ __Vtemp_h3738e8b2__0;
    VlWide<5>/*159:0*/ __Vtemp_h04e5b3ec__0;
    VlWide<5>/*159:0*/ __Vtemp_h1c0420ac__0;
    VlWide<5>/*159:0*/ __Vtemp_h9ba2d8d2__1;
    VlWide<5>/*159:0*/ __Vtemp_hc6e8c5fe__0;
    VlWide<5>/*159:0*/ __Vtemp_h3085166a__0;
    VlWide<5>/*159:0*/ __Vtemp_h7c30b3f9__1;
    VlWide<5>/*159:0*/ __Vtemp_hf1ebcc8c__1;
    VlWide<5>/*159:0*/ __Vtemp_h9fcff81e__0;
    VlWide<5>/*159:0*/ __Vtemp_h07eb3160__0;
    // Body
    if (vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___T_1) {
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_size 
            = (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                     >> 0xeU));
    }
    if (vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___T_1) {
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__saved_size 
            = (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                     >> 0xeU));
    }
    VL_EXTEND_WI(131,4, __Vtemp_h028a790a__0, ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_598)
                                                ? (1U 
                                                   | (0xeU 
                                                      & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                         >> 0xdU)))
                                                : 0U));
    VL_EXTEND_WI(129,4, __Vtemp_h9ba2d8d2__0, (0xfU 
                                               & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                  >> 0xaU)));
    __Vtemp_h00fcbd75__0[0U] = (__Vtemp_h9ba2d8d2__0[0U] 
                                << 2U);
    __Vtemp_h00fcbd75__0[1U] = ((__Vtemp_h9ba2d8d2__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__0[1U] 
                                              << 2U));
    __Vtemp_h00fcbd75__0[2U] = ((__Vtemp_h9ba2d8d2__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__0[2U] 
                                              << 2U));
    __Vtemp_h00fcbd75__0[3U] = ((__Vtemp_h9ba2d8d2__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__0[3U] 
                                              << 2U));
    __Vtemp_h00fcbd75__0[4U] = ((__Vtemp_h9ba2d8d2__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__0[4U] 
                                              << 2U));
    VL_SHIFTL_WWW(131,131,131, __Vtemp_hf53c6003__0, __Vtemp_h028a790a__0, __Vtemp_h00fcbd75__0);
    __Vtemp_h7c30b3f9__0[0U] = 0xfU;
    __Vtemp_h7c30b3f9__0[1U] = 0U;
    __Vtemp_h7c30b3f9__0[2U] = 0U;
    __Vtemp_h7c30b3f9__0[3U] = 0U;
    __Vtemp_h7c30b3f9__0[4U] = 0U;
    VL_EXTEND_WI(141,4, __Vtemp_hf1ebcc8c__0, (0xfU 
                                               & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 0xbU)));
    __Vtemp_h3738e8b2__0[0U] = (__Vtemp_hf1ebcc8c__0[0U] 
                                << 2U);
    __Vtemp_h3738e8b2__0[1U] = ((__Vtemp_hf1ebcc8c__0[0U] 
                                 >> 0x1eU) | (__Vtemp_hf1ebcc8c__0[1U] 
                                              << 2U));
    __Vtemp_h3738e8b2__0[2U] = ((__Vtemp_hf1ebcc8c__0[1U] 
                                 >> 0x1eU) | (__Vtemp_hf1ebcc8c__0[2U] 
                                              << 2U));
    __Vtemp_h3738e8b2__0[3U] = ((__Vtemp_hf1ebcc8c__0[2U] 
                                 >> 0x1eU) | (__Vtemp_hf1ebcc8c__0[3U] 
                                              << 2U));
    __Vtemp_h3738e8b2__0[4U] = ((__Vtemp_hf1ebcc8c__0[3U] 
                                 >> 0x1eU) | (__Vtemp_hf1ebcc8c__0[4U] 
                                              << 2U));
    VL_SHIFTL_WWW(143,143,143, __Vtemp_h04e5b3ec__0, __Vtemp_h7c30b3f9__0, __Vtemp_h3738e8b2__0);
    VL_EXTEND_WI(131,4, __Vtemp_h1c0420ac__0, ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_598)
                                                ? (1U 
                                                   | (0xeU 
                                                      & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                         >> 0x14U)))
                                                : 0U));
    VL_EXTEND_WI(129,4, __Vtemp_h9ba2d8d2__1, (0xfU 
                                               & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                  >> 0xaU)));
    __Vtemp_hc6e8c5fe__0[0U] = (__Vtemp_h9ba2d8d2__1[0U] 
                                << 2U);
    __Vtemp_hc6e8c5fe__0[1U] = ((__Vtemp_h9ba2d8d2__1[0U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__1[1U] 
                                              << 2U));
    __Vtemp_hc6e8c5fe__0[2U] = ((__Vtemp_h9ba2d8d2__1[1U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__1[2U] 
                                              << 2U));
    __Vtemp_hc6e8c5fe__0[3U] = ((__Vtemp_h9ba2d8d2__1[2U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__1[3U] 
                                              << 2U));
    __Vtemp_hc6e8c5fe__0[4U] = ((__Vtemp_h9ba2d8d2__1[3U] 
                                 >> 0x1eU) | (__Vtemp_h9ba2d8d2__1[4U] 
                                              << 2U));
    VL_SHIFTL_WWW(131,131,131, __Vtemp_h3085166a__0, __Vtemp_h1c0420ac__0, __Vtemp_hc6e8c5fe__0);
    __Vtemp_h7c30b3f9__1[0U] = 0xfU;
    __Vtemp_h7c30b3f9__1[1U] = 0U;
    __Vtemp_h7c30b3f9__1[2U] = 0U;
    __Vtemp_h7c30b3f9__1[3U] = 0U;
    __Vtemp_h7c30b3f9__1[4U] = 0U;
    VL_EXTEND_WI(141,4, __Vtemp_hf1ebcc8c__1, (0xfU 
                                               & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 0xbU)));
    __Vtemp_h9fcff81e__0[0U] = (__Vtemp_hf1ebcc8c__1[0U] 
                                << 2U);
    __Vtemp_h9fcff81e__0[1U] = ((__Vtemp_hf1ebcc8c__1[0U] 
                                 >> 0x1eU) | (__Vtemp_hf1ebcc8c__1[1U] 
                                              << 2U));
    __Vtemp_h9fcff81e__0[2U] = ((__Vtemp_hf1ebcc8c__1[1U] 
                                 >> 0x1eU) | (__Vtemp_hf1ebcc8c__1[2U] 
                                              << 2U));
    __Vtemp_h9fcff81e__0[3U] = ((__Vtemp_hf1ebcc8c__1[2U] 
                                 >> 0x1eU) | (__Vtemp_hf1ebcc8c__1[3U] 
                                              << 2U));
    __Vtemp_h9fcff81e__0[4U] = ((__Vtemp_hf1ebcc8c__1[3U] 
                                 >> 0x1eU) | (__Vtemp_hf1ebcc8c__1[4U] 
                                              << 2U));
    VL_SHIFTL_WWW(143,143,143, __Vtemp_h07eb3160__0, __Vtemp_h7c30b3f9__1, __Vtemp_h9fcff81e__0);
    if (vlSelf->reset) {
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes = 0ULL;
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes = 0ULL;
    } else {
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes 
            = (0xffffffffffULL & ((vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes 
                                   | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_598)
                                       ? (((QData)((IData)(
                                                           __Vtemp_hf53c6003__0[1U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            __Vtemp_hf53c6003__0[0U])))
                                       : 0ULL)) & (~ 
                                                   ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_613)
                                                     ? 
                                                    (((QData)((IData)(
                                                                      __Vtemp_h04e5b3ec__0[1U])) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       __Vtemp_h04e5b3ec__0[0U])))
                                                     : 0ULL))));
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes 
            = (0xffffffffffULL & ((vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes 
                                   | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_598)
                                       ? (((QData)((IData)(
                                                           __Vtemp_h3085166a__0[1U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            __Vtemp_h3085166a__0[0U])))
                                       : 0ULL)) & (~ 
                                                   ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_613)
                                                     ? 
                                                    (((QData)((IData)(
                                                                      __Vtemp_h07eb3160__0[1U])) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       __Vtemp_h07eb3160__0[0U])))
                                                     : 0ULL))));
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__351(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__351\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__inflight 
        = ((IData)(vlSelf->reset) ? 0U : (0x3ffU & 
                                          (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__inflight) 
                                            | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_598)
                                                ? (
                                                   (0xfU 
                                                    >= 
                                                    (0xfU 
                                                     & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                        >> 0xaU)))
                                                    ? 
                                                   (0xffffU 
                                                    & ((IData)(1U) 
                                                       << 
                                                       (0xfU 
                                                        & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                           >> 0xaU))))
                                                    : 0U)
                                                : 0U)) 
                                           & (~ ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_613)
                                                  ? 
                                                 ((0xfU 
                                                   >= 
                                                   (0xfU 
                                                    & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 0xbU)))
                                                   ? 
                                                  (0xffffU 
                                                   & ((IData)(1U) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 0xbU))))
                                                   : 0U)
                                                  : 0U)))));
    if (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__do_enq) {
        vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0[0U] 
            = (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_data) 
                << 0xeU) | ((0x2000U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                                        << 0xcU)) | 
                            ((0x1c00U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                                         << 8U)) | 
                             ((0x200U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                         >> 1U)) | 
                              ((0x1e0U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                          >> 9U)) | 
                               ((0x18U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                          >> 0xfU)) 
                                | (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                         >> 0x15U))))))));
        vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0[1U] 
            = (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_data) 
                >> 0x12U) | ((IData)((vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_data 
                                      >> 0x20U)) << 0xeU));
        vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0[2U] 
            = ((0x4000U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                           << 5U)) | ((IData)((vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_data 
                                               >> 0x20U)) 
                                      >> 0x12U));
        vlSelf->__Vdlyvset__TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0 = 1U;
        vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__enq_ptr_value;
    }
    if (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__do_enq) {
        vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0[0U] 
            = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_mask)) 
                        << 0x2dU) | (((QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                      << 0x10U) | (QData)((IData)(
                                                                  (((IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_source) 
                                                                    << 8U) 
                                                                   | ((0xc0U 
                                                                       & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag) 
                                                                          << 6U)) 
                                                                      | ((0x38U 
                                                                          & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full)
                                                                               ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_param)
                                                                               : 
                                                                              (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                                               >> 0x12U)) 
                                                                             << 3U)) 
                                                                         | (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode)))))))));
        vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0[1U] 
            = (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_data) 
                << 0x15U) | (IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_mask)) 
                                       << 0x2dU) | 
                                      (((QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)) 
                                        << 0x10U) | (QData)((IData)(
                                                                    (((IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_source) 
                                                                      << 8U) 
                                                                     | ((0xc0U 
                                                                         & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag) 
                                                                            << 6U)) 
                                                                        | ((0x38U 
                                                                            & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full)
                                                                                 ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_param)
                                                                                 : 
                                                                                (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                                                >> 0x12U)) 
                                                                               << 3U)) 
                                                                           | (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode)))))))) 
                                     >> 0x20U)));
        vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0[2U] 
            = (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_data) 
                >> 0xbU) | ((IData)((vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_data 
                                     >> 0x20U)) << 0x15U));
        vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0[3U] 
            = ((0x200000U & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full)
                               ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_corrupt)
                               : (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                                  >> 9U)) << 0x15U)) 
               | ((IData)((vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_data 
                           >> 0x20U)) >> 0xbU));
        vlSelf->__Vdlyvset__TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0 = 1U;
        vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0 
            = vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value;
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__354(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__354\n"); );
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__dividerOnlyClockGen__DOT__x1_member_allClocks_tileClockGroup_tile_1_clock_ClockDivideBy2__DOT__genblk1__DOT__count) {
        vlSelf->TestHarness__DOT__chiptop__DOT__dividerOnlyClockGen__DOT___x1_member_allClocks_tileClockGroup_tile_1_clock_ClockDivideBy2_clk_out = 0U;
        vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__dividerOnlyClockGen__DOT__x1_member_allClocks_tileClockGroup_tile_1_clock_ClockDivideBy2__DOT__genblk1__DOT__count = 0U;
    } else {
        if ((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__dividerOnlyClockGen__DOT__x1_member_allClocks_tileClockGroup_tile_1_clock_ClockDivideBy2__DOT__genblk1__DOT__count)))) {
            vlSelf->TestHarness__DOT__chiptop__DOT__dividerOnlyClockGen__DOT___x1_member_allClocks_tileClockGroup_tile_1_clock_ClockDivideBy2_clk_out = 1U;
        }
        vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__dividerOnlyClockGen__DOT__x1_member_allClocks_tileClockGroup_tile_1_clock_ClockDivideBy2__DOT__genblk1__DOT__count 
            = (1U & ((IData)(1U) + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__dividerOnlyClockGen__DOT__x1_member_allClocks_tileClockGroup_tile_1_clock_ClockDivideBy2__DOT__genblk1__DOT__count)));
    }
    if (vlSelf->__Vdlyvset__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_0__DOT__ram__v0) {
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_0__DOT__ram[vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_0__DOT__ram__v0] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_0__DOT__ram__v0;
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__355(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__355\n"); );
    // Body
    if (vlSelf->__Vdlyvset__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_1__DOT__ram__v0) {
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_1__DOT__ram[vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_1__DOT__ram__v0] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_1__DOT__ram__v0;
    }
    if (vlSelf->__Vdlyvset__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_2__DOT__ram__v0) {
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_2__DOT__ram[vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_2__DOT__ram__v0] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_2__DOT__ram__v0;
    }
    if (vlSelf->__Vdlyvset__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_3__DOT__ram__v0) {
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_3__DOT__ram[vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_3__DOT__ram__v0] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_3__DOT__ram__v0;
    }
    if (vlSelf->__Vdlyvset__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_4__DOT__ram__v0) {
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_4__DOT__ram[vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_4__DOT__ram__v0] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_4__DOT__ram__v0;
    }
    if (vlSelf->__Vdlyvset__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_5__DOT__ram__v0) {
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_5__DOT__ram[vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_5__DOT__ram__v0] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_5__DOT__ram__v0;
    }
    if (vlSelf->__Vdlyvset__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_6__DOT__ram__v0) {
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_6__DOT__ram[vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_6__DOT__ram__v0] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_6__DOT__ram__v0;
    }
    if (vlSelf->__Vdlyvset__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_7__DOT__ram__v0) {
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_7__DOT__ram[vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_7__DOT__ram__v0] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_7__DOT__ram__v0;
    }
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxm__DOT__prescaler 
        = vlSelf->__Vdly__TestHarness__DOT__uart_sim_0__DOT__rxm__DOT__prescaler;
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxm__DOT__counter 
        = vlSelf->__Vdly__TestHarness__DOT__uart_sim_0__DOT__rxm__DOT__counter;
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__d_first_counter 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__d_first_counter;
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__d_first_counter_1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__356(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__356\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__txq__DOT__enq_ptr_value 
        = vlSelf->__Vdly__TestHarness__DOT__uart_sim_0__DOT__txq__DOT__enq_ptr_value;
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__merged_bits_last_counter_4 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__merged_bits_last_counter_4;
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__deq_ptr_value 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__deq_ptr_value;
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__acknum 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__fragmenter_1__DOT__acknum;
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__deq_ptr_value 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__deq_ptr_value;
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__sendCount 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__sendCount;
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__sending 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__sending;
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__merged_bits_last_counter_1 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__merged_bits_last_counter_1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__357(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__357\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value;
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__a_first_counter 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__a_first_counter;
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__acknum 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__fragmenter__DOT__acknum;
    if (vlSelf->__Vdlyvset__TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0][0U] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0[0U];
        vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0][1U] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0[1U];
        vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0][2U] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0[2U];
        vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0][3U] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0[3U];
    }
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__enq_ptr_value 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__enq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__358(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__358\n"); );
    // Body
    if (vlSelf->__Vdlyvset__TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0][0U] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0[0U];
        vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0][1U] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0[1U];
        vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0][2U] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0[2U];
    }
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value;
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value;
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__359(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__359\n"); );
    // Body
    if (vlSelf->__Vdlyvset__TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0][0U] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0[0U];
        vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0][1U] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0[1U];
        vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0][2U] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0[2U];
    }
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__enq_ptr_value 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__enq_ptr_value;
    if (vlSelf->__Vdlyvset__TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0][0U] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0[0U];
        vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0][1U] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0[1U];
        vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0][2U] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0[2U];
        vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0][3U] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0[3U];
    }
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value;
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full;
    vlSelf->TestHarness__DOT__SimJTAG__DOT__init_done_sticky 
        = vlSelf->__Vdly__TestHarness__DOT__SimJTAG__DOT__init_done_sticky;
    vlSelf->TestHarness__DOT__SimJTAG__DOT__tickCounterReg 
        = vlSelf->__Vdly__TestHarness__DOT__SimJTAG__DOT__tickCounterReg;
    if (vlSelf->reset) {
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__txq__DOT__maybe_full = 0U;
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__d_first_counter = 0U;
    } else {
        if (((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txq__DOT__do_enq) 
             != (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txq__DOT__do_deq))) {
            vlSelf->TestHarness__DOT__uart_sim_0__DOT__txq__DOT__maybe_full 
                = vlSelf->TestHarness__DOT__uart_sim_0__DOT__txq__DOT__do_enq;
        }
        if (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT___T_1347) {
            vlSelf->__Vdly__TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__d_first_counter 
                = (0x1ffU & ((0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__d_first_counter))
                              ? ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__d_first_counter) 
                                 - (IData)(1U)) : (
                                                   (1U 
                                                    & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])
                                                    ? 
                                                   (~ 
                                                    (((0x1aU 
                                                       >= 
                                                       (0xfU 
                                                        & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 5U)))
                                                       ? 
                                                      (0x7ffffffU 
                                                       & ((IData)(0xfffU) 
                                                          << 
                                                          (0xfU 
                                                           & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                              >> 5U))))
                                                       : 0U) 
                                                     >> 3U))
                                                    : 0U)));
        }
    }
    if (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT___T_1165) {
        vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__param = 0U;
        vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__size 
            = vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_size;
        vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__address 
            = vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_address;
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__361(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__361\n"); );
    // Body
    if (vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___T_1) {
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_mask 
            = (0xffU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                        >> 1U));
    }
    if (vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___T_1) {
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__saved_mask 
            = (0xffU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                        >> 1U));
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__saved_corrupt 
            = (1U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                     >> 9U));
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__saved_param 
            = (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                     >> 0x12U));
    }
    if (vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT___T_587) {
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__opcode_1 = 1U;
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__param_1 = 0U;
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__size_1 
            = vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__bundleIn_0_d_bits_size;
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__source_1 
            = (0xfU & ((IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_source) 
                       >> 4U));
    }
    if (vlSelf->reset) {
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__d_first_counter = 0U;
    } else if (vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT___T_799) {
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__d_first_counter 
            = (7U & ((0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__d_first_counter))
                      ? ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__d_first_counter) 
                         - (IData)(1U)) : ((1U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_opcode))
                                            ? (~ ((
                                                   (0xcU 
                                                    >= (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_size))
                                                    ? 
                                                   (0x1fffU 
                                                    & ((IData)(0x3fU) 
                                                       << (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_size)))
                                                    : 0U) 
                                                  >> 3U))
                                            : 0U)));
    }
    if (((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT___T_799) 
         & (~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__d_first_counter)))))) {
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__opcode_1 
            = vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_opcode;
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__param_1 
            = vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_param;
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__size_1 
            = vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_size;
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__source_1 
            = vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_source;
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__sink 
            = vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_sink;
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__denied 
            = vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_denied;
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__362(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__362\n"); );
    // Body
    if (vlSelf->reset) {
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__a_first_counter = 0U;
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__d_first_counter = 0U;
    } else {
        if (vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT___T_731) {
            vlSelf->__Vdly__TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__a_first_counter 
                = (7U & ((0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__a_first_counter))
                          ? ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__a_first_counter) 
                             - (IData)(1U)) : ((0x800000U 
                                                & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)
                                                ? 0U
                                                : (~ 
                                                   (((0xcU 
                                                      >= 
                                                      (7U 
                                                       & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                          >> 0xeU)))
                                                      ? 
                                                     (0x1fffU 
                                                      & ((IData)(0x3fU) 
                                                         << 
                                                         (7U 
                                                          & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                             >> 0xeU))))
                                                      : 0U) 
                                                    >> 3U)))));
        }
        if (vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_747) {
            vlSelf->__Vdly__TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__d_first_counter 
                = (7U & ((0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__d_first_counter))
                          ? ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__d_first_counter) 
                             - (IData)(1U)) : ((1U 
                                                & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])
                                                ? (~ 
                                                   (((0xcU 
                                                      >= (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__bundleIn_0_d_bits_size))
                                                      ? 
                                                     (0x1fffU 
                                                      & ((IData)(0x3fU) 
                                                         << (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__bundleIn_0_d_bits_size)))
                                                      : 0U) 
                                                    >> 3U))
                                                : 0U)));
        }
    }
    if (((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT___T_731) 
         & (~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__a_first_counter)))))) {
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__opcode 
            = (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                     >> 0x15U));
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__param 
            = (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                     >> 0x12U));
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__size 
            = (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                     >> 0xeU));
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__source 
            = (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                       >> 0xaU));
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__address 
            = (0x1fffffffU & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address);
    }
    if (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_747) 
         & (~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__d_first_counter)))))) {
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__opcode_1 
            = (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]);
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__param_1 
            = (3U & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                     >> 3U));
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__size_1 
            = vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__bundleIn_0_d_bits_size;
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__source_1 
            = (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                       >> 0xbU));
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__sink 
            = (1U & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                     >> 0xfU));
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__denied 
            = (1U & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                     >> 0x10U));
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__363(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__363\n"); );
    // Body
    if (vlSelf->reset) {
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__a_first_counter = 0U;
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__a_first_counter = 0U;
    } else {
        if (vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_674) {
            vlSelf->__Vdly__TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__a_first_counter 
                = (7U & ((0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__a_first_counter))
                          ? ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__a_first_counter) 
                             - (IData)(1U)) : ((0x800000U 
                                                & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)
                                                ? 0U
                                                : (~ 
                                                   (((0xcU 
                                                      >= 
                                                      (7U 
                                                       & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                          >> 0xeU)))
                                                      ? 
                                                     (0x1fffU 
                                                      & ((IData)(0x3fU) 
                                                         << 
                                                         (7U 
                                                          & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                             >> 0xeU))))
                                                      : 0U) 
                                                    >> 3U)))));
        }
        if (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1274) {
            vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__a_first_counter 
                = (0x1ffU & ((0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__a_first_counter))
                              ? ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__a_first_counter) 
                                 - (IData)(1U)) : (
                                                   (4U 
                                                    & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])
                                                    ? 0U
                                                    : 
                                                   (~ 
                                                    (((0x1aU 
                                                       >= 
                                                       (0xfU 
                                                        & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 6U)))
                                                       ? 
                                                      (0x7ffffffU 
                                                       & ((IData)(0xfffU) 
                                                          << 
                                                          (0xfU 
                                                           & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                              >> 6U))))
                                                       : 0U) 
                                                     >> 3U)))));
        }
    }
    if (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_674) 
         & (~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__a_first_counter)))))) {
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__opcode 
            = (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                     >> 0x15U));
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__param 
            = (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                     >> 0x12U));
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__size 
            = (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                     >> 0xeU));
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__source 
            = (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                       >> 0xaU));
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__address 
            = (0x1fffffffU & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address);
    }
    if (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1274) 
         & (~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__a_first_counter)))))) {
        vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__opcode 
            = (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]);
        vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__param 
            = (7U & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                     >> 3U));
        vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__size 
            = (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                       >> 6U));
        vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__source 
            = (1U & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                     >> 0xaU));
        vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__address 
            = ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                << 0x15U) | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                             >> 0xbU));
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__364(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__364\n"); );
    // Body
    if (vlSelf->reset) {
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter = 0U;
    } else if (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1347) {
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter 
            = (0x1ffU & ((0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter))
                          ? ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter) 
                             - (IData)(1U)) : ((0x200000U 
                                                & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)
                                                ? (~ 
                                                   (((0x1aU 
                                                      >= 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                          >> 0xeU)))
                                                      ? 
                                                     (0x7ffffffU 
                                                      & ((IData)(0xfffU) 
                                                         << 
                                                         (0xfU 
                                                          & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                             >> 0xeU))))
                                                      : 0U) 
                                                    >> 3U))
                                                : 0U)));
    }
    if (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1347) 
         & (~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter)))))) {
        vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__opcode_1 
            = (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                     >> 0x15U));
        vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__param_1 
            = (3U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                     >> 0x12U));
        vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__size_1 
            = (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                       >> 0xeU));
        vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__source_1 
            = (1U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                     >> 0xaU));
        vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__sink 
            = (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                     >> 2U));
        vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__denied 
            = (1U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                     >> 1U));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__dividerOnlyClockGen__DOT__x1_member_allClocks_tileClockGroup_tile_1_clock_ClockDivideBy2__DOT__genblk1__DOT__count 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__dividerOnlyClockGen__DOT__x1_member_allClocks_tileClockGroup_tile_1_clock_ClockDivideBy2__DOT__genblk1__DOT__count;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___prci_ctrl_domain_auto_tileClockGater_tile_clock_gater_out_member_allClocks_tileClockGroup_tile_1_clock 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__x1_member_allClocks_tileClockGroup_tile_1_clock_cg__DOT__en_latched) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__dividerOnlyClockGen__DOT___x1_member_allClocks_tileClockGroup_tile_1_clock_ClockDivideBy2_clk_out));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___prci_ctrl_domain_auto_tileClockGater_tile_clock_gater_out_member_allClocks_tileClockGroup_tile_2_clock 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__x1_member_allClocks_tileClockGroup_tile_2_clock_cg__DOT__en_latched) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__dividerOnlyClockGen__DOT___x1_member_allClocks_tileClockGroup_tile_1_clock_ClockDivideBy2_clk_out));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___prci_ctrl_domain_auto_tileClockGater_tile_clock_gater_out_member_allClocks_tileClockGroup_tile_3_clock 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__x1_member_allClocks_tileClockGroup_tile_3_clock_cg__DOT__en_latched) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__dividerOnlyClockGen__DOT___x1_member_allClocks_tileClockGroup_tile_1_clock_ClockDivideBy2_clk_out));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___prci_ctrl_domain_auto_tileClockGater_tile_clock_gater_out_member_allClocks_tileClockGroup_tile_4_clock 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__x1_member_allClocks_tileClockGroup_tile_4_clock_cg__DOT__en_latched) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__dividerOnlyClockGen__DOT___x1_member_allClocks_tileClockGroup_tile_1_clock_ClockDivideBy2_clk_out));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__d_first_2 
        = (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__d_first_counter_2));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__366(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__366\n"); );
    // Body
    if (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__a_fire) {
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_mask 
            = (0xffU & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                        >> 0xdU));
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_source 
            = (0xffU & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                        >> 8U));
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_read 
            = (4U == (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]));
    }
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__a_first_1 
        = (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__a_first_counter_1));
    if (vlSelf->reset) {
        vlSelf->__Vdly__TestHarness__DOT__uart_sim_0__DOT__txm__DOT__debounce = 0U;
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__valid = 0U;
        vlSelf->__Vdly__TestHarness__DOT__uart_sim_0__DOT__txm__DOT__state = 0U;
    } else {
        if ((1U & (~ (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__state)))) {
            if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txm__DOT__out) {
                if (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txm__DOT__out) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__debounce)))) {
                    vlSelf->__Vdly__TestHarness__DOT__uart_sim_0__DOT__txm__DOT__debounce 
                        = (3U & ((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__debounce) 
                                 - (IData)(1U)));
                }
            } else {
                vlSelf->__Vdly__TestHarness__DOT__uart_sim_0__DOT__txm__DOT__debounce 
                    = (3U & ((IData)(1U) + (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__debounce)));
            }
        }
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__valid 
            = (((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__state) 
                & (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT___GEN_3)) 
               & (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__data_last));
        vlSelf->__Vdly__TestHarness__DOT__uart_sim_0__DOT__txm__DOT__state 
            = ((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__state)
                ? ((~ ((((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__state) 
                         & (0U == (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__prescaler))) 
                        & (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__sample_mid)) 
                       & (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__data_last))) 
                   & (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__state))
                : (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT___GEN_1));
    }
    if (vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__state) {
        if (vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT___GEN_2) {
            vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__data_count 
                = (0xfU & ((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT___GEN) 
                           >> 4U));
            vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__sample_count 
                = (0xfU & (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT___GEN));
        }
    } else if (vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT___GEN_0) {
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__data_count = 9U;
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__sample_count = 0xfU;
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__367(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__367\n"); );
    // Body
    if (((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__state) 
         & (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT___GEN_2))) {
        vlSelf->__Vdly__TestHarness__DOT__uart_sim_0__DOT__txm__DOT__sample 
            = ((6U & ((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__sample) 
                      << 1U)) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txm__DOT__out));
    }
    if ((1U & (~ (((~ (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__state)) 
                   | (~ (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT___GEN_3))) 
                  | (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__data_last))))) {
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__shifter 
            = ((0x80U & ((((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__sample) 
                           & (IData)((0U != (6U & (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__sample))))) 
                          | (IData)((6U == (6U & (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__sample))))) 
                         << 7U)) | (0x7fU & ((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__shifter) 
                                             >> 1U)));
    }
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__dFirst 
        = (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__acknum));
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_mux 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_full) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_respond));
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_wb 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_full) 
           & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_sublane) 
              | (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_atomic)));
    if (vlSelf->reset) {
        vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outArb__DOT__locked = 0U;
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__dToggle = 0U;
    } else {
        if (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outArb__DOT___T) {
            vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outArb__DOT__locked 
                = (1U & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outArb__DOT___io_out_bits_last_output)));
        }
        if (vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT___GEN_1) {
            vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__dToggle 
                = (1U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_source) 
                         >> 3U));
        }
    }
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__a_first_1 
        = (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__a_first_counter_1));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__368(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__368\n"); );
    // Body
    if (vlSelf->reset) {
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__gennum = 0U;
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__gennum = 0U;
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__dToggle = 0U;
    } else {
        if (((IData)(vlSelf->TestHarness__DOT__ram__DOT___xbar_auto_out_1_d_ready) 
             & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_deq_valid_output))) {
            vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__gennum 
                = (7U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__aFirst)
                          ? (~ (0x3ffU & (((IData)(0x3fU) 
                                           << (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT___repeater_io_deq_bits_size)) 
                                          >> 3U))) : (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT___old_gennum1_T_2)));
        }
        if (((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__full)) 
             & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output))) {
            vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__gennum 
                = (7U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFirst)
                          ? (~ (0x3ffU & (((IData)(0x3fU) 
                                           << (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_size)) 
                                          >> 3U))) : (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___old_gennum1_T_2)));
        }
        if (vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___GEN_1) {
            vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__dToggle 
                = (1U & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                         >> 0xaU));
        }
    }
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__d_first_2 
        = (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__d_first_1 
        = (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__dFirst 
        = (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__acknum));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ptr_match 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__enq_ptr_value) 
           == (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__deq_ptr_value));
    if (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___T_17) {
        if (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__REG) {
            vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_0 
                = (0xffU & (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata));
            vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_1 
                = (0xffU & (IData)((vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata 
                                    >> 8U)));
            vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_2 
                = (0xffU & (IData)((vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata 
                                    >> 0x10U)));
            vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_3 
                = (0xffU & (IData)((vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata 
                                    >> 0x18U)));
            vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_4 
                = (0xffU & (IData)((vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata 
                                    >> 0x20U)));
            vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_5 
                = (0xffU & (IData)((vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata 
                                    >> 0x28U)));
            vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_6 
                = (0xffU & (IData)((vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata 
                                    >> 0x30U)));
            vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_7 
                = (0xffU & (IData)((vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata 
                                    >> 0x38U)));
        } else {
            vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_0 
                = vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_0;
            vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_1 
                = vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_1;
            vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_2 
                = vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_2;
            vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_3 
                = vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_3;
            vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_4 
                = vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_4;
            vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_5 
                = vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_5;
            vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_6 
                = vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_6;
            vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_7 
                = vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_7;
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__369(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__369\n"); );
    // Body
    if (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__REG) {
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_0 
            = (0xffU & (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata));
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_1 
            = (0xffU & (IData)((vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata 
                                >> 8U)));
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_2 
            = (0xffU & (IData)((vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata 
                                >> 0x10U)));
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_3 
            = (0xffU & (IData)((vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata 
                                >> 0x18U)));
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_4 
            = (0xffU & (IData)((vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata 
                                >> 0x20U)));
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_5 
            = (0xffU & (IData)((vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata 
                                >> 0x28U)));
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_6 
            = (0xffU & (IData)((vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata 
                                >> 0x30U)));
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_7 
            = (0xffU & (IData)((vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata 
                                >> 0x38U)));
    }
    if (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___T_17) {
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_size 
            = vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_size;
    }
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ptr_match 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value) 
           == (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_2 
        = (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter_2));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__a_first_1 
        = (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__a_first_counter_1));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_1 
        = (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter_1));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__a_first_1 
        = (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ptr_match 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__enq_ptr_value) 
           == (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__deq_ptr_value));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ptr_match 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value) 
           == (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value));
    if (vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___T_1) {
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_corrupt 
            = (1U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                     >> 9U));
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_param 
            = (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                     >> 0x12U));
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__370(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__370\n"); );
    // Body
    vlSelf->TestHarness__DOT__SimJTAG__DOT__tickCounterNxt 
        = ((0U == vlSelf->TestHarness__DOT__SimJTAG__DOT__tickCounterReg)
            ? 3U : (vlSelf->TestHarness__DOT__SimJTAG__DOT__tickCounterReg 
                    - (IData)(1U)));
    vlSelf->TestHarness__DOT__SimJTAG__DOT__r_reset 
        = vlSelf->reset;
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__d_first_counter 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__d_first_counter;
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__d_first_counter 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__d_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__371(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__371\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__a_first_counter 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__a_first_counter;
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__d_first_counter 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__d_first_counter;
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__a_first_counter 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__a_first_counter;
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__a_first_counter 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__a_first_counter;
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
        = vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
        [vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__deq_ptr_value][0U];
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
        = vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
        [vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__deq_ptr_value][1U];
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[2U] 
        = vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
        [vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__deq_ptr_value][2U];
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
        = vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
        [vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__deq_ptr_value][3U];
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__372(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__372\n"); );
    // Body
    if (vlSelf->__Vdlyvset__TestHarness__DOT__uart_sim_0__DOT__txq__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__txq__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__TestHarness__DOT__uart_sim_0__DOT__txq__DOT__ram_ext__DOT__Memory__v0] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__uart_sim_0__DOT__txq__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__txq__DOT__deq_ptr_value 
        = vlSelf->__Vdly__TestHarness__DOT__uart_sim_0__DOT__txq__DOT__deq_ptr_value;
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__enq_ptr_value 
        = vlSelf->__Vdly__TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__enq_ptr_value;
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__sample 
        = vlSelf->__Vdly__TestHarness__DOT__uart_sim_0__DOT__txm__DOT__sample;
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__prescaler 
        = vlSelf->__Vdly__TestHarness__DOT__uart_sim_0__DOT__txm__DOT__prescaler;
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__debounce 
        = vlSelf->__Vdly__TestHarness__DOT__uart_sim_0__DOT__txm__DOT__debounce;
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__state 
        = vlSelf->__Vdly__TestHarness__DOT__uart_sim_0__DOT__txm__DOT__state;
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__in_d_valid 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_mux) 
           | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_full) 
              & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_wb))));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
        = vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
        [vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value][0U];
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U] 
        = vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
        [vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value][1U];
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
        = vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
        [vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value][2U];
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ptr_match) 
           & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__maybe_full)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__373(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__373\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___mem_RW0_rdata 
        = (((QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_7__DOT__ram
                            [vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_7__DOT__ram_RW_0_r_addr_pipe_0])) 
            << 0x38U) | (((QData)((IData)(((vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_6__DOT__ram
                                            [vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_6__DOT__ram_RW_0_r_addr_pipe_0] 
                                            << 0x18U) 
                                           | ((vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_5__DOT__ram
                                               [vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_5__DOT__ram_RW_0_r_addr_pipe_0] 
                                               << 0x10U) 
                                              | ((vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_4__DOT__ram
                                                  [vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_4__DOT__ram_RW_0_r_addr_pipe_0] 
                                                  << 8U) 
                                                 | vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_3__DOT__ram
                                                 [vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_3__DOT__ram_RW_0_r_addr_pipe_0]))))) 
                          << 0x18U) | (QData)((IData)(
                                                      ((vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_2__DOT__ram
                                                        [vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_2__DOT__ram_RW_0_r_addr_pipe_0] 
                                                        << 0x10U) 
                                                       | ((vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_1__DOT__ram
                                                           [vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_1__DOT__ram_RW_0_r_addr_pipe_0] 
                                                           << 8U) 
                                                          | vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_0__DOT__ram
                                                          [vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem__DOT__mem_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0]))))));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ptr_match) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__maybe_full));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ptr_match) 
           & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__maybe_full)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__374(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__374\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__full 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ptr_match) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__maybe_full));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__empty 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ptr_match) 
           & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__maybe_full)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__empty 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ptr_match) 
           & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__maybe_full)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__full 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ptr_match) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__maybe_full));
    vlSelf->io_success = ((1U == vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fexit_reg) 
                          | (1U == vlSelf->TestHarness__DOT__SimJTAG__DOT_____05Fexit));
    if (((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN_5) 
         | (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_16))) {
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__adapter__DOT__addr 
            = vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN;
    } else if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_3) {
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__adapter__DOT__addr 
            = (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__addr 
               | (((QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___addr_T_2[1U])) 
                   << 0x20U) | (QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___addr_T_2[0U]))));
    } else if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_1) {
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__adapter__DOT__addr = 0ULL;
    }
    if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN_5) {
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__adapter__DOT__len 
            = (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__len 
               - 1ULL);
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__adapter__DOT__bodyValid = 0U;
    } else {
        if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_24) {
            vlSelf->__Vdly__TestHarness__DOT__ram__DOT__adapter__DOT__bodyValid 
                = (3U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__bodyValid) 
                         | ((IData)(1U) << (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__idx))));
        } else if ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_6) 
                     & (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__idx)) 
                    & (1U == vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__cmd))) {
            vlSelf->__Vdly__TestHarness__DOT__ram__DOT__adapter__DOT__bodyValid = 0U;
        }
        if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN_4) {
            if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_20) {
                vlSelf->__Vdly__TestHarness__DOT__ram__DOT__adapter__DOT__len 
                    = (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__len 
                       - 1ULL);
            } else if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_6) {
                vlSelf->__Vdly__TestHarness__DOT__ram__DOT__adapter__DOT__len 
                    = (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__len 
                       | (((QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___addr_T_2[1U])) 
                           << 0x20U) | (QData)((IData)(
                                                       vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___addr_T_2[0U]))));
            } else if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_1) {
                vlSelf->__Vdly__TestHarness__DOT__ram__DOT__adapter__DOT__len = 0ULL;
            }
        } else {
            vlSelf->__Vdly__TestHarness__DOT__ram__DOT__adapter__DOT__len 
                = (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__len 
                   - 1ULL);
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__375(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__375\n"); );
    // Body
    if (((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_24) 
         & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__idx)))) {
        vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__body_0 
            = vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fin_bits_reg;
    } else if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_16) {
        vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__body_0 
            = ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U] 
                << 0x12U) | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                             >> 0xeU));
    }
    if (((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_24) 
         & (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__idx))) {
        vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__body_1 
            = vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fin_bits_reg;
    } else if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_16) {
        vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__body_1 
            = ((vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                << 0x12U) | (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U] 
                             >> 0xeU));
    }
    vlSelf->__Vdly__TestHarness__DOT__ram__DOT__adapter__DOT__idx 
        = (1U & (((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_31)) 
                  | (~ (IData)((0U != vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__len)))) 
                 & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN_4)
                     ? ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_20)
                         ? ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__idx) 
                            - (IData)(1U)) : ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_16)
                                               ? (IData)(
                                                         (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__addr 
                                                          >> 2U))
                                               : ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_6)
                                                   ? 
                                                  ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__idx)
                                                    ? (IData)(
                                                              (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__addr 
                                                               >> 2U))
                                                    : 
                                                   ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__idx) 
                                                    - (IData)(1U)))
                                                   : 
                                                  ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_3)
                                                    ? 
                                                   ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__idx)) 
                                                    & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__idx) 
                                                       - (IData)(1U)))
                                                    : 
                                                   ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_1)) 
                                                    & (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__idx))))))
                     : ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__idx) 
                        - (IData)(1U)))));
    if (vlSelf->reset) {
        vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state = 0U;
    } else if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_31) {
        vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state 
            = ((0U != vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__len)
                ? 6U : 0U);
    } else if (((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_28) 
                & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__full)))) {
        vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state = 8U;
    } else if (((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_24) 
                & (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_27))) {
        vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state = 7U;
    } else if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_20) {
        if ((0U != vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__len)) {
            if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__idx) {
                vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state = 3U;
            } else if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_16) {
                vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state = 5U;
            } else if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_14) {
                vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state = 4U;
            } else if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN_1) {
                if ((1U == vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__cmd)) {
                    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state = 6U;
                } else if ((0U != vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__cmd)) {
                    if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN_6) {
                        vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state = 2U;
                    } else if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_1) {
                        vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state = 1U;
                    }
                } else {
                    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state = 3U;
                }
            } else if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN_6) {
                vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state = 2U;
            } else if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_1) {
                vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state = 1U;
            }
        } else {
            vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state = 0U;
        }
    } else if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_16) {
        vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state = 5U;
    } else if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_14) {
        vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state = 4U;
    } else if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN_1) {
        if ((1U == vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__cmd)) {
            vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state = 6U;
        } else if ((0U != vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__cmd)) {
            if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN_6) {
                vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state = 2U;
            } else if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_1) {
                vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state = 1U;
            }
        } else {
            vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state = 3U;
        }
    } else if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN_6) {
        vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state = 2U;
    } else if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_1) {
        vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state = 1U;
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__376(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__376\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_2 
        = (IData)((0U == (0x3000U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_3 
        = (IData)((0x1000U == (0x3000U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_4 
        = (IData)((0x2000U == (0x3000U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_5 
        = (IData)((0x3000U == (0x3000U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc 
        = ((2U < (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                          >> 6U))) | (IData)((0x80U 
                                              == (0x20c0U 
                                                  & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_1 
        = ((2U < (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                          >> 6U))) | (IData)((0x2080U 
                                              == (0x20c0U 
                                                  & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))));
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__txq__DOT__ptr_match 
        = ((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txq__DOT__enq_ptr_value) 
           == (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txq__DOT__deq_ptr_value));
    if (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_mux) {
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__in_d_bits_source 
            = vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_source;
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__in_d_bits_opcode 
            = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_read) 
               | (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_atomic));
    } else {
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__in_d_bits_source 
            = vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_source;
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__in_d_bits_opcode 
            = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_read) 
               | (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_atomic));
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__377(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__377\n"); );
    // Body
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__data_last 
        = (0U == (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__data_count));
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__sample_mid 
        = (7U == (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__sample_count));
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT___GEN 
        = (0xffU & ((((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__data_count) 
                      << 4U) | (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__sample_count)) 
                    - (IData)(1U)));
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT___GEN_2 
        = ((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__state) 
           & (0U == (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__prescaler)));
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT___GEN_3 
        = (((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__state) 
            & (0U == (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__prescaler))) 
           & (7U == (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__sample_count)));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__aFirst 
        = (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__gennum));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT___old_gennum1_T_2 
        = (7U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__gennum) 
                 - (IData)(1U)));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFirst 
        = (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__gennum));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___old_gennum1_T_2 
        = (7U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__gennum) 
                 - (IData)(1U)));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___GEN 
        = (((0x38U & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                      >> 4U)) | (7U & (~ (0x3fU & ((IData)(7U) 
                                                   << 
                                                   (3U 
                                                    & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 5U))))))) 
           & (0x20U | ((0x1cU & ((~ ((vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                      << 0x19U) | (
                                                   vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 7U))) 
                                 << 2U)) | (3U & (((IData)(7U) 
                                                   << 
                                                   (3U 
                                                    & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 5U))) 
                                                  >> 1U)))));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__drop 
        = ((~ vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]) 
           & (0U != (7U & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                           >> 7U))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__378(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__378\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___same_cycle_resp_T_1 
        = ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
           & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__a_first_counter_1)));
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__REG 
        = vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem_MPORT_en;
    if (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__a_fire) {
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_size 
            = (3U & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                     >> 6U));
    }
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_enq 
        = ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full)) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__in_d_valid));
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT__d_first_done 
        = ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full)) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__in_d_valid));
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_ready 
        = (1U & ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_respond)) 
                 | (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full))));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT___T_617 
        = ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
           & (6U != (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_enq_ready_output 
        = (1U & ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__full)) 
                 & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full))));
    if (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT___T_1) 
         & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__recvCount)))) {
        vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
            = vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg;
    }
    if (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT___T_1) 
         & (1U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__recvCount)))) {
        vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_1 
            = vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg;
    }
    if (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT___T_1) 
         & (2U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__recvCount)))) {
        vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_2 
            = vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg;
    }
    if (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT___T_1) 
         & (3U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__recvCount)))) {
        vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
            = vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg;
    }
    if (vlSelf->reset) {
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__receiving = 1U;
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__recvCount = 0U;
    } else {
        vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__receiving 
            = (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT____Vcellinp__inDes__io_out_ready) 
                & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__receiving))) 
               | ((~ ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT___T_1) 
                      & (3U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__recvCount)))) 
                  & (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__receiving)));
        if (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT___T_1) {
            vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__recvCount 
                = (3U & ((IData)(1U) + (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__recvCount)));
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__379(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__379\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__bodyValid 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__adapter__DOT__bodyValid;
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__idx 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__adapter__DOT__idx;
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
        = vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
        [vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__deq_ptr_value][0U];
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U] 
        = vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
        [vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__deq_ptr_value][1U];
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
        = vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
        [vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__deq_ptr_value][2U];
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__full 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__ptr_match) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__maybe_full));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__len 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__adapter__DOT__len;
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__addr 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__adapter__DOT__addr;
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_2 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc) 
           | (IData)(((0x40U == (0xc0U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])) 
                      & (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_2))));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_3 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc) 
           | (IData)(((0x40U == (0xc0U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])) 
                      & (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_3))));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_4 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_1) 
           | (IData)(((0x40U == (0xc0U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])) 
                      & (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_4))));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_5 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_acc_1) 
           | (IData)(((0x40U == (0xc0U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])) 
                      & (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__mask_eq_5))));
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__txq__DOT__do_enq 
        = ((~ ((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txq__DOT__ptr_match) 
               & (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txq__DOT__maybe_full))) 
           & (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__valid));
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__txq__DOT__empty 
        = ((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txq__DOT__ptr_match) 
           & (~ (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txq__DOT__maybe_full)));
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT___T_617 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__in_d_valid) 
           & (6U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__in_d_bits_opcode)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__380(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__380\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___GEN_0 
        = (7U & ((3U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___GEN) 
                        >> 4U)) | (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___GEN)));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__bundleIn_0_d_valid 
        = (1U & ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)) 
                 & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__drop))));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
        = vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
        [vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value][0U];
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
        = vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
        [vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value][1U];
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U] 
        = vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
        [vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value][2U];
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
        = vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
        [vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value][3U];
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT___T_613 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT__d_first_done) 
           & (6U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__in_d_bits_opcode)));
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_ready 
        = (1U & ((((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_wb)) 
                   & ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_full)) 
                      | (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_ready))) 
                  & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_mux))) 
                 & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full))));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__recvCount 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__recvCount;
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__receiving 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__receiving;
    if (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_1) {
        vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__cmd 
            = vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fin_bits_reg;
    }
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT___T_1217 
        = (((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__empty)) 
            & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__d_first_counter_1))) 
           & (6U != (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_28 
        = (7U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_14 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__full)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__381(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__381\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h2b1bc01c__0;
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_16 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__empty)));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_20 
        = ((5U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state)) 
           & (IData)(vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fout_ready_reg));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_6 
        = ((2U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state)) 
           & (IData)(vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fin_valid_reg));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_3 
        = ((1U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state)) 
           & (IData)(vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fin_valid_reg));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_24 
        = ((6U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state)) 
           & (IData)(vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fin_valid_reg));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_31 
        = ((8U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__empty)));
    vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_d_ready 
        = ((8U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state)) 
           | (4U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state)));
    vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_valid 
        = ((7U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state)) 
           | (3U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state)));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_27 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__idx) 
                 | (~ (IData)((0U != vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__len)))));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN 
        = ((QData)((IData)((0x1fffffffU & ((IData)(1U) 
                                           + (IData)(
                                                     (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__addr 
                                                      >> 3U)))))) 
           << 3U);
    VL_EXTEND_WQ(66,64, __Vtemp_h2b1bc01c__0, (((QData)((IData)(
                                                                (0x1fffffffU 
                                                                 & ((IData)(1U) 
                                                                    + (IData)(
                                                                              (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__addr 
                                                                               >> 3U)))))) 
                                                << 3U) 
                                               - vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__addr));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN_0[0U] 
        = __Vtemp_h2b1bc01c__0[0U];
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN_0[1U] 
        = __Vtemp_h2b1bc01c__0[1U];
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN_0[2U] 
        = __Vtemp_h2b1bc01c__0[2U];
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__txq__DOT__do_deq 
        = ((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__sim__DOT_____05Fout_ready_reg) 
           & (~ (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txq__DOT__empty)));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__dFirst_size 
        = (((IData)((0U != (7U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___GEN) 
                                  >> 3U)))) << 2U) 
           | (((IData)((0U != (3U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___GEN_0) 
                                     >> 1U)))) << 1U) 
              | (IData)((0U != (5U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___GEN_0))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__382(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__382\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_617 
        = (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__bundleIn_0_d_valid) 
            & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1))) 
           & (6U != (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])));
    if (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_wb) {
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT____Vcellinp__mem__RW0_wmask 
            = (0xffU & (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_mask));
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT____Vcellinp__mem__RW0_addr 
            = (0x1ffU & (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_address 
                         >> 3U));
    } else {
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT____Vcellinp__mem__RW0_wmask 
            = (0xffU & ((vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                         << 0x13U) | (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                      >> 0xdU)));
        vlSelf->TestHarness__DOT__ram__DOT__srams__DOT____Vcellinp__mem__RW0_addr 
            = (0x1ffU & ((vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                          << 0xdU) | (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                      >> 0x13U)));
    }
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT__same_cycle_resp 
        = ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__empty)) 
           & ((0xffU & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                        >> 8U)) == (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__in_d_bits_source)));
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT____Vcellinp__mem__RW0_wdata 
        = (((QData)((IData)(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_wb)
                                ? ((IData)((((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_mask) 
                                             >> 7U) 
                                            & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_read))))
                                    ? (IData)((vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_rmw_data 
                                               >> 0x38U))
                                    : (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_7))
                                : ((vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                    << 0x13U) | (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                                 >> 0xdU))) 
                              << 0x18U) | ((0xff0000U 
                                            & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_wb)
                                                 ? 
                                                ((1U 
                                                  & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_mask) 
                                                      >> 6U) 
                                                     & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_read))))
                                                  ? (IData)(
                                                            (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_rmw_data 
                                                             >> 0x30U))
                                                  : (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_6))
                                                 : 
                                                ((vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                                  << 0x1bU) 
                                                 | (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                                    >> 5U))) 
                                               << 0x10U)) 
                                           | ((0xff00U 
                                               & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_wb)
                                                    ? 
                                                   ((1U 
                                                     & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_mask) 
                                                         >> 5U) 
                                                        & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_read))))
                                                     ? (IData)(
                                                               (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_rmw_data 
                                                                >> 0x28U))
                                                     : (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_5))
                                                    : 
                                                   ((vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                                     << 3U) 
                                                    | (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U] 
                                                       >> 0x1dU))) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_wb)
                                                     ? 
                                                    ((1U 
                                                      & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_mask) 
                                                          >> 4U) 
                                                         & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_read))))
                                                      ? (IData)(
                                                                (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_rmw_data 
                                                                 >> 0x20U))
                                                      : (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_4))
                                                     : 
                                                    ((vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U] 
                                                      << 0xbU) 
                                                     | (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U] 
                                                        >> 0x15U))))))))) 
            << 0x20U) | (QData)((IData)(((((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_wb)
                                            ? ((1U 
                                                & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_mask) 
                                                    >> 3U) 
                                                   & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_read))))
                                                ? (IData)(
                                                          (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_rmw_data 
                                                           >> 0x18U))
                                                : (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_3))
                                            : ((vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U] 
                                                << 0x13U) 
                                               | (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U] 
                                                  >> 0xdU))) 
                                          << 0x18U) 
                                         | ((0xff0000U 
                                             & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_wb)
                                                  ? 
                                                 ((1U 
                                                   & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_mask) 
                                                       >> 2U) 
                                                      & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_read))))
                                                   ? (IData)(
                                                             (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_rmw_data 
                                                              >> 0x10U))
                                                   : (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_2))
                                                  : 
                                                 ((vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U] 
                                                   << 0x1bU) 
                                                  | (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U] 
                                                     >> 5U))) 
                                                << 0x10U)) 
                                            | ((0xff00U 
                                                & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_wb)
                                                     ? 
                                                    ((1U 
                                                      & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_mask) 
                                                          >> 1U) 
                                                         & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_read))))
                                                      ? (IData)(
                                                                (vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_rmw_data 
                                                                 >> 8U))
                                                      : (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_1))
                                                     : 
                                                    ((vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U] 
                                                      << 3U) 
                                                     | (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                        >> 0x1dU))) 
                                                   << 8U)) 
                                               | (0xffU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_wb)
                                                      ? 
                                                     ((1U 
                                                       & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_mask) 
                                                          & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_read))))
                                                       ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_rmw_data)
                                                       : (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_raw_data_0))
                                                      : 
                                                     ((vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                       << 0xbU) 
                                                      | (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                         >> 0x15U))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__383(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__383\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT__mask_eq_2 
        = (IData)((0U == (0x60000U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])));
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT__mask_eq_3 
        = (IData)((0x20000U == (0x60000U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])));
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT__mask_eq_4 
        = (IData)((0x40000U == (0x60000U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])));
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT__mask_eq_5 
        = (IData)((0x60000U == (0x60000U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])));
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT__mask_acc 
        = ((3U == (3U & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                         >> 6U))) | (IData)((0x80U 
                                             == (0x400c0U 
                                                 & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))));
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT__mask_acc_1 
        = ((3U == (3U & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                         >> 6U))) | (IData)((0x40080U 
                                             == (0x400c0U 
                                                 & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))));
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT___T_17 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_full) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_ready));
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__in_a_ready 
        = (1U & (((~ ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_full) 
                      & (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_wb))) 
                  & ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_full)) 
                     | (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_ready))) 
                 & ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_full)) 
                    | (~ ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_atomic) 
                          | (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__r_sublane))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__384(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__384\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_hf7f54520__0;
    // Body
    if (vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full) {
        vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_mask = 0xffU;
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode 
            = (7U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_opcode));
    } else {
        vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_mask 
            = (0xffU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                        >> 1U));
        vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode 
            = (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                     >> 0x15U));
    }
    if (vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__valid) {
        __Vtemp_hf7f54520__0[0U] = vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_0;
        __Vtemp_hf7f54520__0[1U] = vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_1;
        __Vtemp_hf7f54520__0[2U] = vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_2;
        __Vtemp_hf7f54520__0[3U] = vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_3;
        __Vtemp_hf7f54520__0[4U] = vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_4;
        __Vtemp_hf7f54520__0[5U] = vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_5;
        __Vtemp_hf7f54520__0[6U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_7)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_6))));
        __Vtemp_hf7f54520__0[7U] = (IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_7)) 
                                              << 0x20U) 
                                             | (QData)((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_6))) 
                                            >> 0x20U));
        vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
            = (((0U == (0x1fU & ((0xe0U & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx) 
                                           << 5U)) 
                                 ^ (0x80U & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx) 
                                             << 4U)))))
                 ? 0U : (__Vtemp_hf7f54520__0[(((IData)(0x1fU) 
                                                + (0xffU 
                                                   & ((0xe0U 
                                                       & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx) 
                                                          << 5U)) 
                                                      ^ 
                                                      (0x80U 
                                                       & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx) 
                                                          << 4U))))) 
                                               >> 5U)] 
                         << ((IData)(0x20U) - (0x1fU 
                                               & ((0xe0U 
                                                   & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx) 
                                                      << 5U)) 
                                                  ^ 
                                                  (0x80U 
                                                   & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx) 
                                                      << 4U))))))) 
               | (__Vtemp_hf7f54520__0[(7U & ((7U & (IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx)) 
                                              ^ (4U 
                                                 & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx) 
                                                    >> 1U))))] 
                  >> (0x1fU & ((0xe0U & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx) 
                                         << 5U)) ^ 
                               (0x80U & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__sink__DOT__ridx) 
                                         << 4U))))));
    }
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_data 
        = (((QData)((IData)((0x3ffU & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_2))) 
            << 0x36U) | (((QData)((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_1)) 
                          << 0x16U) | (QData)((IData)(
                                                      (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_0 
                                                       >> 0xaU)))));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__same_cycle_resp 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___same_cycle_resp_T_1) 
           & ((1U & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                     >> 0xaU)) == (1U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                                         >> 0xaU))));
    vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_opcode 
        = (7U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__full)
                  ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__saved_opcode)
                  : (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                     >> 0x15U)));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid 
        = ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__receiving)) 
           & (0x3000000U == (0x7000000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__385(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__385\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_size 
        = (7U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full)
                  ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_size)
                  : (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                     >> 0xeU)));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT___repeater_io_deq_bits_size 
        = (7U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__full)
                  ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__saved_size)
                  : (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                     >> 0xeU)));
    vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid 
        = ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__receiving)) 
           & (0U == (0x7000000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address 
        = ((vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
            << 0x16U) | (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_2 
                         >> 0xaU));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_1 
        = ((0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state)) 
           & (IData)(vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fin_valid_reg));
    vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fin_bits_reg 
        = vlSelf->__Vdly__TestHarness__DOT__success_exit_sim__DOT_____05Fin_bits_reg;
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN_1 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_6) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__idx));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN_6 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_3) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__idx));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN_5 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_31) 
           & (0U != vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__len));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__do_deq 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_d_ready) 
           & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__empty)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT___T_1347 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_d_ready) 
           & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__empty)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__do_enq 
        = ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__full)) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_valid));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__same_cycle_resp 
        = (((IData)(vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_valid) 
            & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__a_first_counter_1))) 
           & (~ (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                 >> 9U)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT___T_1274 
        = ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__full)) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_valid));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__386(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__386\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_hd38d9978__0;
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN_4 
        = (1U & ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_24)) 
                 | (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___T_27)));
    __Vtemp_hd38d9978__0[0U] = ((IData)((1ULL + vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__len)) 
                                << 2U);
    __Vtemp_hd38d9978__0[1U] = (((IData)((1ULL + vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__len)) 
                                 >> 0x1eU) | ((IData)(
                                                      ((1ULL 
                                                        + vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__len) 
                                                       >> 0x20U)) 
                                              << 2U));
    __Vtemp_hd38d9978__0[2U] = ((IData)(((1ULL + vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__len) 
                                         >> 0x20U)) 
                                >> 0x1eU);
    if (VL_LT_W(3, __Vtemp_hd38d9978__0, vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN_0)) {
        vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
            = ((IData)((1ULL + vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__len)) 
               << 2U);
        vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
            = (((IData)((1ULL + vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__len)) 
                >> 0x1eU) | ((IData)(((1ULL + vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__len) 
                                      >> 0x20U)) << 2U));
        vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[2U] 
            = ((IData)(((1ULL + vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__len) 
                        >> 0x20U)) >> 0x1eU);
    } else {
        vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
            = vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN_0[0U];
        vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
            = vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN_0[1U];
        vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[2U] 
            = vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___GEN_0[2U];
    }
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__bundleIn_0_d_bits_size 
        = ((0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__acknum))
            ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__dFirst_size)
            : (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__dOrig));
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT__mask_acc_2 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT__mask_acc) 
           | (IData)(((0x40U == (0xc0U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])) 
                      & (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT__mask_eq_2))));
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT__mask_acc_3 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT__mask_acc) 
           | (IData)(((0x40U == (0xc0U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])) 
                      & (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT__mask_eq_3))));
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT__mask_acc_4 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT__mask_acc_1) 
           | (IData)(((0x40U == (0xc0U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])) 
                      & (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT__mask_eq_4))));
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT__mask_acc_5 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT__mask_acc_1) 
           | (IData)(((0x40U == (0xc0U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])) 
                      & (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT__mask_eq_5))));
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__monitor__DOT__a_first_done 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__in_a_ready) 
           & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__empty)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__do_deq 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__in_a_ready) 
           & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__empty)));
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__a_fire 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__in_a_ready) 
           & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__empty)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__do_enq 
        = ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__full)) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__387(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__387\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1217 
        = (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid) 
            & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter_1))) 
           & (6U != (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                           >> 0x15U))));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1347 
        = ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__full)) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__manager_tl_d_valid));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__old_gennum1 
        = (7U & ((0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__gennum))
                  ? (~ (0x3ffU & (((IData)(0x3fU) << (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_size)) 
                                  >> 3U))) : ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__gennum) 
                                              - (IData)(1U))));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag 
        = ((4U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_size))
            ? 3U : (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_size));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__aFrag 
        = ((4U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT___repeater_io_deq_bits_size))
            ? 3U : (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT___repeater_io_deq_bits_size));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__old_gennum1 
        = (7U & ((0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__gennum))
                  ? (~ (0x3ffU & (((IData)(0x3fU) << (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT___repeater_io_deq_bits_size)) 
                                  >> 3U))) : ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__gennum) 
                                              - (IData)(1U))));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_2 
        = (IData)((0U == (6U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_3 
        = (IData)((2U == (6U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_4 
        = (IData)((4U == (6U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__388(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__388\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_5 
        = (IData)((6U == (6U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2 
        = (IData)((0U == (6U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3 
        = (IData)((2U == (6U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4 
        = (IData)((4U == (6U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5 
        = (IData)((6U == (6U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__mask_eq_2 
        = (IData)((0U == (6U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__mask_eq_3 
        = (IData)((2U == (6U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__mask_eq_4 
        = (IData)((4U == (6U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__mask_eq_5 
        = (IData)((6U == (6U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__389(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__389\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc 
        = ((2U < (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                        >> 0xeU))) | (IData)(((0x8000U 
                                               == (0xc000U 
                                                   & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)) 
                                              & (~ 
                                                 (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address 
                                                  >> 2U)))));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_1 
        = ((2U < (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                        >> 0xeU))) | (IData)(((0x8000U 
                                               == (0xc000U 
                                                   & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)) 
                                              & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address 
                                                 >> 2U))));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__mask_acc 
        = ((2U < (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                        >> 0xeU))) | (IData)(((0x8000U 
                                               == (0xc000U 
                                                   & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)) 
                                              & (~ 
                                                 (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address 
                                                  >> 2U)))));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__mask_acc_1 
        = ((2U < (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                        >> 0xeU))) | (IData)(((0x8000U 
                                               == (0xc000U 
                                                   & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)) 
                                              & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address 
                                                 >> 2U))));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__mask_acc 
        = ((2U < (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                        >> 0xeU))) | (IData)(((0x8000U 
                                               == (0xc000U 
                                                   & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)) 
                                              & (~ 
                                                 (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address 
                                                  >> 2U)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__390(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__390\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h11304ee4__0;
    VlWide<3>/*95:0*/ __Vtemp_h237b0f68__0;
    VlWide<3>/*95:0*/ __Vtemp_h18fe3df8__0;
    VlWide<3>/*95:0*/ __Vtemp_hea562f4d__0;
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__mask_acc_1 
        = ((2U < (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                        >> 0xeU))) | (IData)(((0x8000U 
                                               == (0xc000U 
                                                   & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)) 
                                              & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address 
                                                 >> 2U))));
    vlSelf->TestHarness__DOT__ram__DOT___xbar_auto_out_0_a_valid 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
           & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address 
              >> 0x1cU));
    vlSelf->TestHarness__DOT__ram__DOT___xbar_auto_out_1_a_valid 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
           & (~ (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address 
                 >> 0x1cU)));
    VL_EXTEND_WI(95,32, __Vtemp_h11304ee4__0, vlSelf->TestHarness__DOT__success_exit_sim__DOT_____05Fin_bits_reg);
    VL_EXTEND_WI(90,1, __Vtemp_h237b0f68__0, (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__idx));
    __Vtemp_h18fe3df8__0[0U] = (__Vtemp_h237b0f68__0[0U] 
                                << 5U);
    __Vtemp_h18fe3df8__0[1U] = ((__Vtemp_h237b0f68__0[0U] 
                                 >> 0x1bU) | (__Vtemp_h237b0f68__0[1U] 
                                              << 5U));
    __Vtemp_h18fe3df8__0[2U] = ((__Vtemp_h237b0f68__0[1U] 
                                 >> 0x1bU) | (__Vtemp_h237b0f68__0[2U] 
                                              << 5U));
    VL_SHIFTL_WWW(95,95,95, __Vtemp_hea562f4d__0, __Vtemp_h11304ee4__0, __Vtemp_h18fe3df8__0);
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___addr_T_2[0U] 
        = __Vtemp_hea562f4d__0[0U];
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___addr_T_2[1U] 
        = __Vtemp_hea562f4d__0[1U];
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT___addr_T_2[2U] 
        = (0x7fffffffU & __Vtemp_hea562f4d__0[2U]);
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT___T_1213 
        = (((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT___T_1347) 
            & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__d_first_counter_1))) 
           & (6U != (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__a_set 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT___T_1274) 
           & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__a_first_counter_1)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT___T_1165 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT___T_1274) 
           & (~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__a_first_counter)))));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__rsize 
        = ((0U == (((4U ^ vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U]) 
                    | vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U]) 
                   | vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[2U]))
            ? 2U : ((0U == (((2U ^ vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U]) 
                             | vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U]) 
                            | vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[2U]))
                     ? 1U : ((0U == (((1U ^ vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U]) 
                                      | vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U]) 
                                     | vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[2U]))
                              ? 0U : 3U)));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__pow2size 
        = (1U == (0x7fU & ((0x3fU & ((0x1fU & ((0xfU 
                                                & ((7U 
                                                    & ((3U 
                                                        & ((1U 
                                                            & vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U]) 
                                                           + 
                                                           (1U 
                                                            & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                               >> 1U)))) 
                                                       + 
                                                       (3U 
                                                        & ((1U 
                                                            & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                               >> 2U)) 
                                                           + 
                                                           (1U 
                                                            & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                               >> 3U)))))) 
                                                   + 
                                                   (7U 
                                                    & ((3U 
                                                        & ((1U 
                                                            & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                               >> 4U)) 
                                                           + 
                                                           (1U 
                                                            & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                               >> 5U)))) 
                                                       + 
                                                       (3U 
                                                        & ((1U 
                                                            & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                               >> 6U)) 
                                                           + 
                                                           (1U 
                                                            & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                               >> 7U)))))))) 
                                               + (0xfU 
                                                  & ((7U 
                                                      & ((3U 
                                                          & ((1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                 >> 8U)) 
                                                             + 
                                                             (1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                 >> 9U)))) 
                                                         + 
                                                         (3U 
                                                          & ((1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                 >> 0xaU)) 
                                                             + 
                                                             (1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                 >> 0xbU)))))) 
                                                     + 
                                                     (7U 
                                                      & ((3U 
                                                          & ((1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                 >> 0xcU)) 
                                                             + 
                                                             (1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                 >> 0xdU)))) 
                                                         + 
                                                         (3U 
                                                          & ((1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                 >> 0xeU)) 
                                                             + 
                                                             (1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                 >> 0xfU)))))))))) 
                                     + (0x1fU & ((0xfU 
                                                  & ((7U 
                                                      & ((3U 
                                                          & ((1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                 >> 0x10U)) 
                                                             + 
                                                             (1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                 >> 0x11U)))) 
                                                         + 
                                                         (3U 
                                                          & ((1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                 >> 0x12U)) 
                                                             + 
                                                             (1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                 >> 0x13U)))))) 
                                                     + 
                                                     (7U 
                                                      & ((3U 
                                                          & ((1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                 >> 0x14U)) 
                                                             + 
                                                             (1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                 >> 0x15U)))) 
                                                         + 
                                                         (3U 
                                                          & ((1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                 >> 0x16U)) 
                                                             + 
                                                             (1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                 >> 0x17U)))))))) 
                                                 + 
                                                 (0xfU 
                                                  & ((7U 
                                                      & ((3U 
                                                          & ((1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                 >> 0x18U)) 
                                                             + 
                                                             (1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                 >> 0x19U)))) 
                                                         + 
                                                         (3U 
                                                          & ((1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                 >> 0x1aU)) 
                                                             + 
                                                             (1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                 >> 0x1bU)))))) 
                                                     + 
                                                     (7U 
                                                      & ((3U 
                                                          & ((1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                 >> 0x1cU)) 
                                                             + 
                                                             (1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                 >> 0x1dU)))) 
                                                         + 
                                                         (3U 
                                                          & (((1U 
                                                               & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                                  >> 0x1eU)) 
                                                              + 
                                                              (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[0U] 
                                                               >> 0x1fU)) 
                                                             + 
                                                             (1U 
                                                              & vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U]))))))))))) 
                           + (0x3fU & ((0x1fU & ((0xfU 
                                                  & ((7U 
                                                      & ((3U 
                                                          & ((1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                 >> 1U)) 
                                                             + 
                                                             (1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                 >> 2U)))) 
                                                         + 
                                                         (3U 
                                                          & ((1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                 >> 3U)) 
                                                             + 
                                                             (1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                 >> 4U)))))) 
                                                     + 
                                                     (7U 
                                                      & ((3U 
                                                          & ((1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                 >> 5U)) 
                                                             + 
                                                             (1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                 >> 6U)))) 
                                                         + 
                                                         (3U 
                                                          & ((1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                 >> 7U)) 
                                                             + 
                                                             (1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                 >> 8U)))))))) 
                                                 + 
                                                 (0xfU 
                                                  & ((7U 
                                                      & ((3U 
                                                          & ((1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                 >> 9U)) 
                                                             + 
                                                             (1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                 >> 0xaU)))) 
                                                         + 
                                                         (3U 
                                                          & ((1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                 >> 0xbU)) 
                                                             + 
                                                             (1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                 >> 0xcU)))))) 
                                                     + 
                                                     (7U 
                                                      & ((3U 
                                                          & ((1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                 >> 0xdU)) 
                                                             + 
                                                             (1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                 >> 0xeU)))) 
                                                         + 
                                                         (3U 
                                                          & ((1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                 >> 0xfU)) 
                                                             + 
                                                             (1U 
                                                              & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                 >> 0x10U)))))))))) 
                                       + (0x1fU & (
                                                   (0xfU 
                                                    & ((7U 
                                                        & ((3U 
                                                            & ((1U 
                                                                & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                   >> 0x11U)) 
                                                               + 
                                                               (1U 
                                                                & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                   >> 0x12U)))) 
                                                           + 
                                                           (3U 
                                                            & ((1U 
                                                                & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                   >> 0x13U)) 
                                                               + 
                                                               (1U 
                                                                & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                   >> 0x14U)))))) 
                                                       + 
                                                       (7U 
                                                        & ((3U 
                                                            & ((1U 
                                                                & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                   >> 0x15U)) 
                                                               + 
                                                               (1U 
                                                                & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                   >> 0x16U)))) 
                                                           + 
                                                           (3U 
                                                            & ((1U 
                                                                & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                   >> 0x17U)) 
                                                               + 
                                                               (1U 
                                                                & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                   >> 0x18U)))))))) 
                                                   + 
                                                   (0xfU 
                                                    & ((7U 
                                                        & ((3U 
                                                            & ((1U 
                                                                & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                   >> 0x19U)) 
                                                               + 
                                                               (1U 
                                                                & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                   >> 0x1aU)))) 
                                                           + 
                                                           (3U 
                                                            & ((1U 
                                                                & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                   >> 0x1bU)) 
                                                               + 
                                                               (1U 
                                                                & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                   >> 0x1cU)))))) 
                                                       + 
                                                       (7U 
                                                        & ((3U 
                                                            & ((1U 
                                                                & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                   >> 0x1dU)) 
                                                               + 
                                                               (1U 
                                                                & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                   >> 0x1eU)))) 
                                                           + 
                                                           (3U 
                                                            & (((vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[1U] 
                                                                 >> 0x1fU) 
                                                                + 
                                                                (1U 
                                                                 & vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[2U])) 
                                                               + 
                                                               (1U 
                                                                & (vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__raw_size[2U] 
                                                                   >> 1U)))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__391(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__391\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem_MPORT_1_en 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__d_wb) 
           | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__a_fire) 
              & (4U != (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1213 
        = (((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1347) 
            & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__d_first_counter_1))) 
           & (6U != (7U & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                           >> 0x15U))));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT____Vcellinp__repeater__io_repeat 
        = (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode) 
            >> 2U) & (0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__old_gennum1)));
    vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_source 
        = ((0xf0U & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full)
                       ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_source)
                       : (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                          >> 0xaU)) << 4U)) | ((8U 
                                                & ((~ 
                                                    ((0U 
                                                      == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__gennum))
                                                      ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__dToggle)
                                                      : (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aToggle_r))) 
                                                   << 3U)) 
                                               | (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__old_gennum1)));
    vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address 
        = (0x1fffffffU & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full)
                            ? vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__saved_address
                            : vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address) 
                          | (0x3fU & (~ (7U | ((0x1fffU 
                                                & ((IData)(0x3fU) 
                                                   << (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___repeater_io_deq_bits_size))) 
                                               | (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__old_gennum1) 
                                                   << 3U) 
                                                  | (7U 
                                                     & (~ 
                                                        (0x3ffU 
                                                         & ((IData)(7U) 
                                                            << (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag))))))))))));
    vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_address 
        = (0x3ffffU & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__full)
                         ? vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__saved_address
                         : vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___inDes_io_out_bits_address) 
                       | (0x3fU & (~ (7U | ((0x1fffU 
                                             & ((IData)(0x3fU) 
                                                << (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT___repeater_io_deq_bits_size))) 
                                            | (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__old_gennum1) 
                                                << 3U) 
                                               | (7U 
                                                  & (~ 
                                                     (0x3ffU 
                                                      & ((IData)(7U) 
                                                         << (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__aFrag))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__392(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__392\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_source 
        = ((0xf0U & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__full)
                       ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__saved_source)
                       : (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                          >> 0xaU)) << 4U)) | ((8U 
                                                & ((~ 
                                                    ((0U 
                                                      == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__gennum))
                                                      ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__dToggle)
                                                      : (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__aToggle_r))) 
                                                   << 3U)) 
                                               | (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__old_gennum1)));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_2 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc) 
           | (IData)(((0x4000U == (0xc000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)) 
                      & (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_2))));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_3 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc) 
           | (IData)(((0x4000U == (0xc000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)) 
                      & (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_3))));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_4 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_1) 
           | (IData)(((0x4000U == (0xc000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)) 
                      & (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_4))));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_5 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_acc_1) 
           | (IData)(((0x4000U == (0xc000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)) 
                      & (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__mask_eq_5))));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__mask_acc) 
           | (IData)(((0x4000U == (0xc000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)) 
                      & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2))));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__mask_acc) 
           | (IData)(((0x4000U == (0xc000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)) 
                      & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3))));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__mask_acc_1) 
           | (IData)(((0x4000U == (0xc000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)) 
                      & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__393(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__393\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__mask_acc_1) 
           | (IData)(((0x4000U == (0xc000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)) 
                      & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5))));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__mask_acc_2 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__mask_acc) 
           | (IData)(((0x4000U == (0xc000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)) 
                      & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__mask_eq_2))));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__mask_acc_3 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__mask_acc) 
           | (IData)(((0x4000U == (0xc000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)) 
                      & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__mask_eq_3))));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__mask_acc_4 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__mask_acc_1) 
           | (IData)(((0x4000U == (0xc000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)) 
                      & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__mask_eq_4))));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__mask_acc_5 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__mask_acc_1) 
           | (IData)(((0x4000U == (0xc000U & vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3)) 
                      & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__mask_eq_5))));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_674 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_enq_ready_output) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT___xbar_auto_out_0_a_valid));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___same_cycle_resp_T_1 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT___xbar_auto_out_0_a_valid) 
           & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1)));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT___xbar_auto_out_0_a_valid) 
           | (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT__full));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_deq_valid_output 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT___xbar_auto_out_1_a_valid) 
           | (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__full));
    vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_size 
        = ((7U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state))
            ? 3U : (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__rsize));
    vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_address 
        = (((IData)((vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__addr 
                     >> 3U)) << 3U) | ((1U & ((7U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state)) 
                                              | (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__pow2size))))
                                        ? 0U : (7U 
                                                & (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__addr))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__394(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__394\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__byteAddr 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__pow2size)
            ? (7U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__addr))
            : 0U);
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem_MPORT_en 
        = ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem_MPORT_1_en)) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__a_fire));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___T_1 
        = (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_enq_ready_output) 
            & (IData)(vlSelf->TestHarness__DOT__ram__DOT___xbar_auto_out_0_a_valid)) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT____Vcellinp__repeater__io_repeat));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_2 
        = (IData)((0U == (6U & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_3 
        = (IData)((2U == (6U & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_4 
        = (IData)((4U == (6U & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_5 
        = (IData)((6U == (6U & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc 
        = ((3U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag))) 
           | ((2U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag))) 
              & (~ (vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address 
                    >> 2U))));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_1 
        = ((3U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag))) 
           | ((2U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag))) 
              & (vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_address 
                 >> 2U)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__395(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__395\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_eq_2 
        = (IData)((0U == (6U & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_address)));
    vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_eq_3 
        = (IData)((2U == (6U & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_address)));
    vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_eq_4 
        = (IData)((4U == (6U & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_address)));
    vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_eq_5 
        = (IData)((6U == (6U & vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_address)));
    vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_acc 
        = ((3U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__aFrag))) 
           | ((2U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__aFrag))) 
              & (~ (vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_address 
                    >> 2U))));
    vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_acc_1 
        = ((3U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__aFrag))) 
           | ((2U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__aFrag))) 
              & (vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_address 
                 >> 2U)));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__same_cycle_resp 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT___xbar_auto_out_1_a_valid) 
           & ((0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                       >> 0xaU)) == (0xfU & ((IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_source) 
                                             >> 4U))));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT___GEN 
        = (((0x38U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_source) 
                      << 3U)) | (7U & (~ (0x3fU & ((IData)(7U) 
                                                   << 
                                                   (3U 
                                                    & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__aFrag))))))) 
           & (0x20U | ((0x1cU & ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_source)) 
                                 << 2U)) | (3U & (((IData)(7U) 
                                                   << 
                                                   (3U 
                                                    & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__aFrag))) 
                                                  >> 1U)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__396(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__396\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_598 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_674) 
           & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1)));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__same_cycle_resp 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___same_cycle_resp_T_1) 
           & ((0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                       >> 0xaU)) == (0xfU & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xbU))));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__a_first_done 
        = ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__full)) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__do_enq 
        = ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__x1_a_q__DOT__full)) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__same_cycle_resp 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output) 
           & ((IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_auto_out_a_bits_source) 
              == (0xffU & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                           >> 7U))));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT___T_640 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_deq_valid_output) 
           & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT__d_first_counter_1)));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_valid 
        = ((0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__beatsLeft))
            ? ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__bundleIn_0_d_valid) 
               | (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_deq_valid_output))
            : (((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__state_0) 
                & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__bundleIn_0_d_valid)) 
               | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__state_1) 
                  & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_deq_valid_output))));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__readys_valid 
        = (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_deq_valid_output) 
            << 1U) | (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__bundleIn_0_d_valid));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__mask_eq_2 
        = (IData)((0U == (6U & vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_address)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__mask_eq_3 
        = (IData)((2U == (6U & vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_address)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__mask_eq_4 
        = (IData)((4U == (6U & vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_address)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__397(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__397\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__mask_eq_5 
        = (IData)((6U == (6U & vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_address)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__mask_acc 
        = ((2U < (IData)(vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_size)) 
           | ((2U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_size))) 
              & (~ (vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_address 
                    >> 2U))));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__mask_acc_1 
        = ((2U < (IData)(vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_size)) 
           | ((2U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_size))) 
              & (vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_address 
                 >> 2U)));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_eq_2 
        = (IData)((0U == (6U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__byteAddr))));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_eq_3 
        = (IData)((2U == (6U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__byteAddr))));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_eq_4 
        = (IData)((4U == (6U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__byteAddr))));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_eq_5 
        = (IData)((6U == (6U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__byteAddr))));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_acc 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__rsize)) 
           | ((2U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__rsize)) 
              & (~ ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__byteAddr) 
                    >> 2U))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__398(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__398\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_acc_1 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__rsize)) 
           | ((2U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__rsize)) 
              & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__byteAddr) 
                 >> 2U)));
    vlSelf->TestHarness__DOT__ram__DOT__srams__DOT____Vcellinp__mem__RW0_en 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem_MPORT_en) 
           | (IData)(vlSelf->TestHarness__DOT__ram__DOT__srams__DOT__mem_MPORT_1_en));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_2 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc) 
           | ((1U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag))) 
              & (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_2)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_3 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc) 
           | ((1U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag))) 
              & (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_3)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_4 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_1) 
           | ((1U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag))) 
              & (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_4)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_5 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_acc_1) 
           | ((1U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__aFrag))) 
              & (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__mask_eq_5)));
    vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_acc_2 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_acc) 
           | ((1U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__aFrag))) 
              & (IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_eq_2)));
    vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_acc_3 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_acc) 
           | ((1U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__aFrag))) 
              & (IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_eq_3)));
    vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_acc_4 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_acc_1) 
           | ((1U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__aFrag))) 
              & (IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_eq_4)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__399(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__399\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_acc_5 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_acc_1) 
           | ((1U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__aFrag))) 
              & (IData)(vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__mask_eq_5)));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT___GEN_0 
        = (7U & ((3U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT___GEN) 
                        >> 4U)) | (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT___GEN)));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outArb__DOT__chosen 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outArb__DOT__locked)
            ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outArb__DOT__lockIdx)
            : ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_valid)
                ? 1U : 4U));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT___readys_filter_T_1 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__readys_valid) 
           & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__readys_mask)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__mask_acc_2 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__mask_acc) 
           | ((1U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_size))) 
              & (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__mask_eq_2)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__mask_acc_3 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__mask_acc) 
           | ((1U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_size))) 
              & (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__mask_eq_3)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__mask_acc_4 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__mask_acc_1) 
           | ((1U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_size))) 
              & (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__mask_eq_4)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__mask_acc_5 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__mask_acc_1) 
           | ((1U == (3U & (IData)(vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_size))) 
              & (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__monitor__DOT__mask_eq_5)));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_acc_2 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_acc) 
           | ((1U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__rsize)) 
              & (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_eq_2)));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_acc_3 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_acc) 
           | ((1U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__rsize)) 
              & (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_eq_3)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__400(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__400\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_acc_4 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_acc_1) 
           | ((1U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__rsize)) 
              & (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_eq_4)));
    vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_acc_5 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_acc_1) 
           | ((1U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__rsize)) 
              & (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_eq_5)));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__dFirst_size 
        = (((IData)((0U != (7U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT___GEN) 
                                  >> 3U)))) << 2U) 
           | (((IData)((0U != (3U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT___GEN_0) 
                                     >> 1U)))) << 1U) 
              | (IData)((0U != (5U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT___GEN_0))))));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outArb__DOT___io_out_valid_output 
        = (1U & (((0x10U & ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)) 
                            << 4U)) | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_valid) 
                                       << 1U)) >> (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outArb__DOT__chosen)));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___outArb_io_in_4_ready 
        = ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__sending)) 
           & (4U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outArb__DOT__chosen)));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___outArb_io_in_1_ready 
        = ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__sending)) 
           & (1U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outArb__DOT__chosen)));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__readys_readys 
        = (3U & (~ (((2U & (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__readys_mask)) 
                     | (1U & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT___readys_filter_T_1) 
                               >> 1U) | (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__readys_mask)))) 
                    & (((IData)((0U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT___readys_filter_T_1))) 
                        << 1U) | (1U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_deq_valid_output) 
                                        | (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT___readys_filter_T_1)))))));
    vlSelf->TestHarness__DOT__ram__DOT___adapter_auto_out_a_bits_mask 
        = ((7U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__state))
            ? ((0xf0U & ((- (IData)((1U & ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__bodyValid) 
                                           >> 1U)))) 
                         << 4U)) | (0xfU & (- (IData)(
                                                      (1U 
                                                       & (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__bodyValid))))))
            : ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_acc_5) 
                 | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_eq_5) 
                    & (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__byteAddr))) 
                << 7U) | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_acc_5) 
                            | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_eq_5) 
                               & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__byteAddr)))) 
                           << 6U) | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_acc_4) 
                                       | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_eq_4) 
                                          & (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__byteAddr))) 
                                      << 5U) | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_acc_4) 
                                                  | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_eq_4) 
                                                     & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__byteAddr)))) 
                                                 << 4U) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_acc_3) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_eq_3) 
                                                        & (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__byteAddr))) 
                                                    << 3U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_acc_3) 
                                                        | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_eq_3) 
                                                           & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__byteAddr)))) 
                                                       << 2U) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_acc_2) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_eq_2) 
                                                              & (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__byteAddr))) 
                                                          << 1U) 
                                                         | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_acc_2) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__get_acquire_a_mask_eq_2) 
                                                               & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__adapter__DOT__byteAddr))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__401(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__401\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__bundleIn_0_d_bits_size 
        = ((0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__acknum))
            ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__dFirst_size)
            : (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__dOrig));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outArb__DOT___T 
        = ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__sending)) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outArb__DOT___io_out_valid_output));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT___T_1 
        = ((~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__sending)) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outArb__DOT___io_out_valid_output));
    vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__do_deq 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___outArb_io_in_4_ready) 
           & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1274 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___outArb_io_in_4_ready) 
           & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT__empty)));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__latch 
        = ((0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__beatsLeft)) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___outArb_io_in_1_ready));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT___T_799 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___outArb_io_in_1_ready) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_valid));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT___readys_mask_T 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__readys_readys) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__readys_valid));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__winnerQual_0 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__readys_readys) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__bundleIn_0_d_valid));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__winnerQual_1 
        = (((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__readys_readys) 
            >> 1U) & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_deq_valid_output));
    vlSelf->TestHarness__DOT__ram__DOT___xbar_auto_out_0_d_ready 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___outArb_io_in_1_ready) 
           & ((0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__beatsLeft))
               ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__readys_readys)
               : (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__state_0)));
    if ((0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__beatsLeft))) {
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__muxStateEarly_1 
            = (((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__readys_readys) 
                >> 1U) & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_deq_valid_output));
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__muxStateEarly_0 
            = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__readys_readys) 
               & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__bundleIn_0_d_valid));
    } else {
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__muxStateEarly_1 
            = vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__state_1;
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__muxStateEarly_0 
            = vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__state_0;
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__402(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__402\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT___xbar_auto_out_1_d_ready 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT___outArb_io_in_1_ready) 
           & ((0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__beatsLeft))
               ? ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__readys_readys) 
                  >> 1U) : (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__state_1)));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1198 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT___T_1274) 
           & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__monitor__DOT__a_first_counter_1)));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_747 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT___xbar_auto_out_0_d_ready) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__bundleIn_0_d_valid));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__x1_d_ready 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT___xbar_auto_out_0_d_ready) 
           | (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__drop));
    if (vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__muxStateEarly_0) {
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_denied 
            = (1U & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                     >> 0x10U));
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_sink 
            = (1U & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                     >> 0xfU));
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_param 
            = (3U & (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                     >> 3U));
    } else {
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_denied = 0U;
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_sink = 0U;
        vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_param = 0U;
    }
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_source 
        = (0xfU & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__muxStateEarly_0)
                     ? ((vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                         << 0x15U) | (vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                      >> 0xbU)) : 0U) 
                   | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__muxStateEarly_1)
                       ? ((IData)(vlSelf->TestHarness__DOT__ram__DOT___fragmenter_1_auto_out_a_bits_source) 
                          >> 4U) : 0U)));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_size 
        = (((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__muxStateEarly_0)
             ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__bundleIn_0_d_bits_size)
             : 0U) | ((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__muxStateEarly_1)
                       ? (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__bundleIn_0_d_bits_size)
                       : 0U));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_opcode 
        = (7U & (((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__muxStateEarly_0)
                   ? vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]
                   : 0U) | (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__muxStateEarly_1)));
    vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__a_first_done 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT___xbar_auto_out_1_d_ready) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_deq_valid_output));
    vlSelf->TestHarness__DOT__ram__DOT__rom__DOT__monitor__DOT__d_first_done 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT___xbar_auto_out_1_d_ready) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_deq_valid_output));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__403(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__403\n"); );
    // Body
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT___T_7 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT___xbar_auto_out_1_d_ready) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_deq_valid_output));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__monitor__DOT___T_729 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT___xbar_auto_out_1_d_ready) 
           & (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_deq_valid_output));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT___io_enq_ready_output 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT___xbar_auto_out_1_d_ready) 
           & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter_1__DOT__repeater__DOT__full)));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_613 
        = (((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT___T_747) 
            & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1))) 
           & (6U != (7U & vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_deq 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__x1_d_ready) 
           & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)));
    vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__monitor__DOT__d_first_done 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__x1_d_ready) 
           & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)));
    vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT___T_7 
        = ((IData)(vlSelf->TestHarness__DOT__ram__DOT__fragmenter__DOT__x1_d_ready) 
           & (~ (IData)(vlSelf->TestHarness__DOT__ram__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__same_cycle_resp 
        = (((IData)(vlSelf->TestHarness__DOT__ram__DOT___serdesser_auto_client_out_a_valid) 
            & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__a_first_counter_1))) 
           & ((0xfU & (vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__inDes__DOT__data_3 
                       >> 0xaU)) == (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_source)));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT___T_677 
        = (((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT___T_799) 
            & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__d_first_counter_1))) 
           & (6U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_opcode)));
    vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT___T_681 
        = (((IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_valid) 
            & (0U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__monitor__DOT__d_first_counter_1))) 
           & (6U != (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_opcode)));
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outArb__DOT___io_out_bits_last_output 
        = (1U & ((0xedU | ((((1U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__merged_bits_last_counter_4)) 
                             | (0U == ((4U & vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])
                                        ? 0U : (7U 
                                                & (~ 
                                                   (0x3ffffU 
                                                    & (((IData)(0x3fU) 
                                                        << 
                                                        (0xfU 
                                                         & (vlSelf->TestHarness__DOT__ram__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                            >> 6U))) 
                                                       >> 3U))))))) 
                            << 4U) | (((1U == (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__merged_bits_last_counter_1)) 
                                       | (0U == ((1U 
                                                  & (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_opcode))
                                                  ? 
                                                 (7U 
                                                  & (~ 
                                                     (0x3ffU 
                                                      & (((IData)(0x3fU) 
                                                          << (IData)(vlSelf->TestHarness__DOT__ram__DOT__xbar__DOT__out_9_bits_size)) 
                                                         >> 3U))))
                                                  : 0U))) 
                                      << 1U))) >> (IData)(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outArb__DOT__chosen)));
}
