// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTestHarness.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTestHarness___024root.h"

extern const VlWide<33>/*1055:0*/ VTestHarness__ConstPool__CONST_h3892cc72_0;
extern const VlWide<9>/*287:0*/ VTestHarness__ConstPool__CONST_h52851b57_0;
extern const VlWide<9>/*287:0*/ VTestHarness__ConstPool__CONST_h478702bb_0;
extern const VlWide<33>/*1055:0*/ VTestHarness__ConstPool__CONST_hf1d99c76_0;
extern const VlWide<33>/*1055:0*/ VTestHarness__ConstPool__CONST_hf1d81c7e_0;
extern const VlWide<33>/*1055:0*/ VTestHarness__ConstPool__CONST_h81905067_0;
extern const VlWide<17>/*543:0*/ VTestHarness__ConstPool__CONST_h00a540f1_0;
extern const VlWide<17>/*543:0*/ VTestHarness__ConstPool__CONST_h881bc0c4_0;
extern const VlWide<33>/*1055:0*/ VTestHarness__ConstPool__CONST_hf1d99c4e_0;

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__15227(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__15227\n"); );
    // Init
    VlWide<9>/*287:0*/ __Vtemp_h59385317__0;
    VlWide<33>/*1055:0*/ __Vtemp_hfd83c24f__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9dd30ecc__0;
    VlWide<33>/*1055:0*/ __Vtemp_h65421e99__0;
    VlWide<33>/*1055:0*/ __Vtemp_hd4c63f41__0;
    VlWide<33>/*1055:0*/ __Vtemp_ha5e95abe__0;
    VlWide<33>/*1055:0*/ __Vtemp_h092d9994__0;
    VlWide<33>/*1055:0*/ __Vtemp_h2e4b71c1__0;
    VlWide<3>/*95:0*/ __Vtemp_h97c8015d__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__0;
    VlWide<4>/*127:0*/ __Vtemp_h1777d4f3__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__1;
    VlWide<4>/*127:0*/ __Vtemp_h5c5e292d__0;
    VlWide<17>/*543:0*/ __Vtemp_h59771d95__0;
    VlWide<33>/*1055:0*/ __Vtemp_h12ac5163__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9dd30ecc__1;
    VlWide<33>/*1055:0*/ __Vtemp_hdcccbf99__0;
    VlWide<33>/*1055:0*/ __Vtemp_hfe5b1fc7__0;
    VlWide<33>/*1055:0*/ __Vtemp_ha5e95abe__1;
    VlWide<33>/*1055:0*/ __Vtemp_haa8e0d7f__0;
    VlWide<33>/*1055:0*/ __Vtemp_hec083356__0;
    // Body
    VL_EXTEND_WI(1027,4, __Vtemp_hfd83c24f__0, ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1584)
                                                 ? 
                                                (1U 
                                                 | (0xeU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       << 1U)))
                                                 : 0U));
    VL_EXTEND_WI(1025,7, __Vtemp_h9dd30ecc__0, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)));
    __Vtemp_h65421e99__0[0U] = (__Vtemp_h9dd30ecc__0[0U] 
                                << 2U);
    __Vtemp_h65421e99__0[1U] = ((__Vtemp_h9dd30ecc__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[1U] 
                                              << 2U));
    __Vtemp_h65421e99__0[2U] = ((__Vtemp_h9dd30ecc__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[2U] 
                                              << 2U));
    __Vtemp_h65421e99__0[3U] = ((__Vtemp_h9dd30ecc__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[3U] 
                                              << 2U));
    __Vtemp_h65421e99__0[4U] = ((__Vtemp_h9dd30ecc__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[4U] 
                                              << 2U));
    __Vtemp_h65421e99__0[5U] = ((__Vtemp_h9dd30ecc__0[4U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[5U] 
                                              << 2U));
    __Vtemp_h65421e99__0[6U] = ((__Vtemp_h9dd30ecc__0[5U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[6U] 
                                              << 2U));
    __Vtemp_h65421e99__0[7U] = ((__Vtemp_h9dd30ecc__0[6U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[7U] 
                                              << 2U));
    __Vtemp_h65421e99__0[8U] = ((__Vtemp_h9dd30ecc__0[7U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[8U] 
                                              << 2U));
    __Vtemp_h65421e99__0[9U] = ((__Vtemp_h9dd30ecc__0[8U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[9U] 
                                              << 2U));
    __Vtemp_h65421e99__0[0xaU] = ((__Vtemp_h9dd30ecc__0[9U] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xaU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xbU] = ((__Vtemp_h9dd30ecc__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xbU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xcU] = ((__Vtemp_h9dd30ecc__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xcU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xdU] = ((__Vtemp_h9dd30ecc__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xdU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xeU] = ((__Vtemp_h9dd30ecc__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xeU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xfU] = ((__Vtemp_h9dd30ecc__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xfU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0x10U] = ((__Vtemp_h9dd30ecc__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x10U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x11U] = ((__Vtemp_h9dd30ecc__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x11U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x12U] = ((__Vtemp_h9dd30ecc__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x12U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x13U] = ((__Vtemp_h9dd30ecc__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x13U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x14U] = ((__Vtemp_h9dd30ecc__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x14U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x15U] = ((__Vtemp_h9dd30ecc__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x15U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x16U] = ((__Vtemp_h9dd30ecc__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x16U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x17U] = ((__Vtemp_h9dd30ecc__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x17U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x18U] = ((__Vtemp_h9dd30ecc__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x18U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x19U] = ((__Vtemp_h9dd30ecc__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x19U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1aU] = ((__Vtemp_h9dd30ecc__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1aU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1bU] = ((__Vtemp_h9dd30ecc__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1bU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1cU] = ((__Vtemp_h9dd30ecc__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1cU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1dU] = ((__Vtemp_h9dd30ecc__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1dU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1eU] = ((__Vtemp_h9dd30ecc__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1eU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1fU] = ((__Vtemp_h9dd30ecc__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1fU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x20U] = ((__Vtemp_h9dd30ecc__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1027,1027,1027, __Vtemp_hd4c63f41__0, __Vtemp_hfd83c24f__0, __Vtemp_h65421e99__0);
    VL_EXTEND_WI(1037,7, __Vtemp_ha5e95abe__0, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source));
    __Vtemp_h092d9994__0[0U] = (__Vtemp_ha5e95abe__0[0U] 
                                << 2U);
    __Vtemp_h092d9994__0[1U] = ((__Vtemp_ha5e95abe__0[0U] 
                                 >> 0x1eU) | (__Vtemp_ha5e95abe__0[1U] 
                                              << 2U));
    __Vtemp_h092d9994__0[2U] = ((__Vtemp_ha5e95abe__0[1U] 
                                 >> 0x1eU) | (__Vtemp_ha5e95abe__0[2U] 
                                              << 2U));
    __Vtemp_h092d9994__0[3U] = ((__Vtemp_ha5e95abe__0[2U] 
                                 >> 0x1eU) | (__Vtemp_ha5e95abe__0[3U] 
                                              << 2U));
    __Vtemp_h092d9994__0[4U] = ((__Vtemp_ha5e95abe__0[3U] 
                                 >> 0x1eU) | (__Vtemp_ha5e95abe__0[4U] 
                                              << 2U));
    __Vtemp_h092d9994__0[5U] = ((__Vtemp_ha5e95abe__0[4U] 
                                 >> 0x1eU) | (__Vtemp_ha5e95abe__0[5U] 
                                              << 2U));
    __Vtemp_h092d9994__0[6U] = ((__Vtemp_ha5e95abe__0[5U] 
                                 >> 0x1eU) | (__Vtemp_ha5e95abe__0[6U] 
                                              << 2U));
    __Vtemp_h092d9994__0[7U] = ((__Vtemp_ha5e95abe__0[6U] 
                                 >> 0x1eU) | (__Vtemp_ha5e95abe__0[7U] 
                                              << 2U));
    __Vtemp_h092d9994__0[8U] = ((__Vtemp_ha5e95abe__0[7U] 
                                 >> 0x1eU) | (__Vtemp_ha5e95abe__0[8U] 
                                              << 2U));
    __Vtemp_h092d9994__0[9U] = ((__Vtemp_ha5e95abe__0[8U] 
                                 >> 0x1eU) | (__Vtemp_ha5e95abe__0[9U] 
                                              << 2U));
    __Vtemp_h092d9994__0[0xaU] = ((__Vtemp_ha5e95abe__0[9U] 
                                   >> 0x1eU) | (__Vtemp_ha5e95abe__0[0xaU] 
                                                << 2U));
    __Vtemp_h092d9994__0[0xbU] = ((__Vtemp_ha5e95abe__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_ha5e95abe__0[0xbU] 
                                                << 2U));
    __Vtemp_h092d9994__0[0xcU] = ((__Vtemp_ha5e95abe__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_ha5e95abe__0[0xcU] 
                                                << 2U));
    __Vtemp_h092d9994__0[0xdU] = ((__Vtemp_ha5e95abe__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_ha5e95abe__0[0xdU] 
                                                << 2U));
    __Vtemp_h092d9994__0[0xeU] = ((__Vtemp_ha5e95abe__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_ha5e95abe__0[0xeU] 
                                                << 2U));
    __Vtemp_h092d9994__0[0xfU] = ((__Vtemp_ha5e95abe__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_ha5e95abe__0[0xfU] 
                                                << 2U));
    __Vtemp_h092d9994__0[0x10U] = ((__Vtemp_ha5e95abe__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x10U] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x11U] = ((__Vtemp_ha5e95abe__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x11U] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x12U] = ((__Vtemp_ha5e95abe__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x12U] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x13U] = ((__Vtemp_ha5e95abe__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x13U] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x14U] = ((__Vtemp_ha5e95abe__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x14U] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x15U] = ((__Vtemp_ha5e95abe__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x15U] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x16U] = ((__Vtemp_ha5e95abe__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x16U] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x17U] = ((__Vtemp_ha5e95abe__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x17U] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x18U] = ((__Vtemp_ha5e95abe__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x18U] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x19U] = ((__Vtemp_ha5e95abe__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x19U] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x1aU] = ((__Vtemp_ha5e95abe__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x1aU] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x1bU] = ((__Vtemp_ha5e95abe__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x1bU] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x1cU] = ((__Vtemp_ha5e95abe__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x1cU] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x1dU] = ((__Vtemp_ha5e95abe__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x1dU] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x1eU] = ((__Vtemp_ha5e95abe__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x1eU] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x1fU] = ((__Vtemp_ha5e95abe__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x1fU] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x20U] = ((__Vtemp_ha5e95abe__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_h2e4b71c1__0, VTestHarness__ConstPool__CONST_h3892cc72_0, __Vtemp_h092d9994__0);
    __Vtemp_h59385317__0[1U] = (VTestHarness__ConstPool__CONST_h52851b57_0[1U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[1U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight_opcodes[1U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[1U] 
                                               & __Vtemp_hd4c63f41__0[1U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[1U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[1U] 
                                                 & __Vtemp_h2e4b71c1__0[1U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[1U])))));
    __Vtemp_h59385317__0[2U] = (VTestHarness__ConstPool__CONST_h52851b57_0[2U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[2U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight_opcodes[2U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[2U] 
                                               & __Vtemp_hd4c63f41__0[2U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[2U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[2U] 
                                                 & __Vtemp_h2e4b71c1__0[2U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[2U])))));
    __Vtemp_h59385317__0[3U] = (VTestHarness__ConstPool__CONST_h52851b57_0[3U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[3U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight_opcodes[3U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[3U] 
                                               & __Vtemp_hd4c63f41__0[3U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[3U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[3U] 
                                                 & __Vtemp_h2e4b71c1__0[3U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[3U])))));
    __Vtemp_h59385317__0[4U] = (VTestHarness__ConstPool__CONST_h52851b57_0[4U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[4U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight_opcodes[4U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[4U] 
                                               & __Vtemp_hd4c63f41__0[4U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[4U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[4U] 
                                                 & __Vtemp_h2e4b71c1__0[4U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[4U])))));
    __Vtemp_h59385317__0[5U] = (VTestHarness__ConstPool__CONST_h52851b57_0[5U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[5U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight_opcodes[5U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[5U] 
                                               & __Vtemp_hd4c63f41__0[5U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[5U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[5U] 
                                                 & __Vtemp_h2e4b71c1__0[5U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[5U])))));
    __Vtemp_h59385317__0[6U] = (VTestHarness__ConstPool__CONST_h52851b57_0[6U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[6U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight_opcodes[6U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[6U] 
                                               & __Vtemp_hd4c63f41__0[6U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[6U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[6U] 
                                                 & __Vtemp_h2e4b71c1__0[6U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[6U])))));
    __Vtemp_h59385317__0[7U] = (VTestHarness__ConstPool__CONST_h52851b57_0[7U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[7U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight_opcodes[7U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[7U] 
                                               & __Vtemp_hd4c63f41__0[7U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[7U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[7U] 
                                                 & __Vtemp_h2e4b71c1__0[7U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[7U])))));
    __Vtemp_h59385317__0[8U] = (VTestHarness__ConstPool__CONST_h52851b57_0[8U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[8U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight_opcodes[8U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[8U] 
                                               & __Vtemp_hd4c63f41__0[8U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[8U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[8U] 
                                                 & __Vtemp_h2e4b71c1__0[8U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[8U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight_opcodes[0U] 
        = (VTestHarness__ConstPool__CONST_h52851b57_0[0U] 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
               ? VTestHarness__ConstPool__CONST_h478702bb_0[0U]
               : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight_opcodes[0U] 
                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1584)
                       ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[0U] 
                          & __Vtemp_hd4c63f41__0[0U])
                       : VTestHarness__ConstPool__CONST_h478702bb_0[0U])) 
                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1599)
                         ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0U] 
                            & __Vtemp_h2e4b71c1__0[0U])
                         : VTestHarness__ConstPool__CONST_h478702bb_0[0U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight_opcodes[1U] 
        = __Vtemp_h59385317__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight_opcodes[2U] 
        = __Vtemp_h59385317__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight_opcodes[3U] 
        = __Vtemp_h59385317__0[3U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight_opcodes[4U] 
        = __Vtemp_h59385317__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight_opcodes[5U] 
        = __Vtemp_h59385317__0[5U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight_opcodes[6U] 
        = __Vtemp_h59385317__0[6U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight_opcodes[7U] 
        = __Vtemp_h59385317__0[7U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight_opcodes[8U] 
        = __Vtemp_h59385317__0[8U];
    __Vtemp_hc961d23f__0[0U] = 1U;
    __Vtemp_hc961d23f__0[1U] = 0U;
    __Vtemp_hc961d23f__0[2U] = 0U;
    __Vtemp_hc961d23f__0[3U] = 0U;
    VL_SHIFTL_WWI(128,128,7, __Vtemp_h1777d4f3__0, __Vtemp_hc961d23f__0, 
                  (0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                            >> 0xaU)));
    __Vtemp_hc961d23f__1[0U] = 1U;
    __Vtemp_hc961d23f__1[1U] = 0U;
    __Vtemp_hc961d23f__1[2U] = 0U;
    __Vtemp_hc961d23f__1[3U] = 0U;
    VL_SHIFTL_WWI(128,128,7, __Vtemp_h5c5e292d__0, __Vtemp_hc961d23f__1, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset) {
        __Vtemp_h97c8015d__0[1U] = 0U;
        __Vtemp_h97c8015d__0[2U] = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight[0U] = 0U;
    } else {
        __Vtemp_h97c8015d__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight[1U] 
                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1584)
                                         ? __Vtemp_h1777d4f3__0[1U]
                                         : 0U)) & (~ 
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1599)
                                                     ? 
                                                    __Vtemp_h5c5e292d__0[1U]
                                                     : 0U)));
        __Vtemp_h97c8015d__0[2U] = (1U & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight[2U] 
                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1584)
                                               ? __Vtemp_h1777d4f3__0[2U]
                                               : 0U)) 
                                          & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1599)
                                                 ? 
                                                __Vtemp_h5c5e292d__0[2U]
                                                 : 0U))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight[0U] 
            = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight[0U] 
                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1584)
                    ? __Vtemp_h1777d4f3__0[0U] : 0U)) 
               & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT___T_1599)
                      ? __Vtemp_h5c5e292d__0[0U] : 0U)));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight[1U] 
        = __Vtemp_h97c8015d__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight[2U] 
        = __Vtemp_h97c8015d__0[2U];
    VL_EXTEND_WI(1028,5, __Vtemp_h12ac5163__0, ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                                 ? 
                                                (1U 
                                                 | (0x1eU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 5U)))
                                                 : 0U));
    VL_EXTEND_WI(1025,7, __Vtemp_h9dd30ecc__1, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)));
    __Vtemp_hdcccbf99__0[0U] = (__Vtemp_h9dd30ecc__1[0U] 
                                << 3U);
    __Vtemp_hdcccbf99__0[1U] = ((__Vtemp_h9dd30ecc__1[0U] 
                                 >> 0x1dU) | (__Vtemp_h9dd30ecc__1[1U] 
                                              << 3U));
    __Vtemp_hdcccbf99__0[2U] = ((__Vtemp_h9dd30ecc__1[1U] 
                                 >> 0x1dU) | (__Vtemp_h9dd30ecc__1[2U] 
                                              << 3U));
    __Vtemp_hdcccbf99__0[3U] = ((__Vtemp_h9dd30ecc__1[2U] 
                                 >> 0x1dU) | (__Vtemp_h9dd30ecc__1[3U] 
                                              << 3U));
    __Vtemp_hdcccbf99__0[4U] = ((__Vtemp_h9dd30ecc__1[3U] 
                                 >> 0x1dU) | (__Vtemp_h9dd30ecc__1[4U] 
                                              << 3U));
    __Vtemp_hdcccbf99__0[5U] = ((__Vtemp_h9dd30ecc__1[4U] 
                                 >> 0x1dU) | (__Vtemp_h9dd30ecc__1[5U] 
                                              << 3U));
    __Vtemp_hdcccbf99__0[6U] = ((__Vtemp_h9dd30ecc__1[5U] 
                                 >> 0x1dU) | (__Vtemp_h9dd30ecc__1[6U] 
                                              << 3U));
    __Vtemp_hdcccbf99__0[7U] = ((__Vtemp_h9dd30ecc__1[6U] 
                                 >> 0x1dU) | (__Vtemp_h9dd30ecc__1[7U] 
                                              << 3U));
    __Vtemp_hdcccbf99__0[8U] = ((__Vtemp_h9dd30ecc__1[7U] 
                                 >> 0x1dU) | (__Vtemp_h9dd30ecc__1[8U] 
                                              << 3U));
    __Vtemp_hdcccbf99__0[9U] = ((__Vtemp_h9dd30ecc__1[8U] 
                                 >> 0x1dU) | (__Vtemp_h9dd30ecc__1[9U] 
                                              << 3U));
    __Vtemp_hdcccbf99__0[0xaU] = ((__Vtemp_h9dd30ecc__1[9U] 
                                   >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0xaU] 
                                                << 3U));
    __Vtemp_hdcccbf99__0[0xbU] = ((__Vtemp_h9dd30ecc__1[0xaU] 
                                   >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0xbU] 
                                                << 3U));
    __Vtemp_hdcccbf99__0[0xcU] = ((__Vtemp_h9dd30ecc__1[0xbU] 
                                   >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0xcU] 
                                                << 3U));
    __Vtemp_hdcccbf99__0[0xdU] = ((__Vtemp_h9dd30ecc__1[0xcU] 
                                   >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0xdU] 
                                                << 3U));
    __Vtemp_hdcccbf99__0[0xeU] = ((__Vtemp_h9dd30ecc__1[0xdU] 
                                   >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0xeU] 
                                                << 3U));
    __Vtemp_hdcccbf99__0[0xfU] = ((__Vtemp_h9dd30ecc__1[0xeU] 
                                   >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0xfU] 
                                                << 3U));
    __Vtemp_hdcccbf99__0[0x10U] = ((__Vtemp_h9dd30ecc__1[0xfU] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0x10U] 
                                                 << 3U));
    __Vtemp_hdcccbf99__0[0x11U] = ((__Vtemp_h9dd30ecc__1[0x10U] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0x11U] 
                                                 << 3U));
    __Vtemp_hdcccbf99__0[0x12U] = ((__Vtemp_h9dd30ecc__1[0x11U] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0x12U] 
                                                 << 3U));
    __Vtemp_hdcccbf99__0[0x13U] = ((__Vtemp_h9dd30ecc__1[0x12U] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0x13U] 
                                                 << 3U));
    __Vtemp_hdcccbf99__0[0x14U] = ((__Vtemp_h9dd30ecc__1[0x13U] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0x14U] 
                                                 << 3U));
    __Vtemp_hdcccbf99__0[0x15U] = ((__Vtemp_h9dd30ecc__1[0x14U] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0x15U] 
                                                 << 3U));
    __Vtemp_hdcccbf99__0[0x16U] = ((__Vtemp_h9dd30ecc__1[0x15U] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0x16U] 
                                                 << 3U));
    __Vtemp_hdcccbf99__0[0x17U] = ((__Vtemp_h9dd30ecc__1[0x16U] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0x17U] 
                                                 << 3U));
    __Vtemp_hdcccbf99__0[0x18U] = ((__Vtemp_h9dd30ecc__1[0x17U] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0x18U] 
                                                 << 3U));
    __Vtemp_hdcccbf99__0[0x19U] = ((__Vtemp_h9dd30ecc__1[0x18U] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0x19U] 
                                                 << 3U));
    __Vtemp_hdcccbf99__0[0x1aU] = ((__Vtemp_h9dd30ecc__1[0x19U] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0x1aU] 
                                                 << 3U));
    __Vtemp_hdcccbf99__0[0x1bU] = ((__Vtemp_h9dd30ecc__1[0x1aU] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0x1bU] 
                                                 << 3U));
    __Vtemp_hdcccbf99__0[0x1cU] = ((__Vtemp_h9dd30ecc__1[0x1bU] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0x1cU] 
                                                 << 3U));
    __Vtemp_hdcccbf99__0[0x1dU] = ((__Vtemp_h9dd30ecc__1[0x1cU] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0x1dU] 
                                                 << 3U));
    __Vtemp_hdcccbf99__0[0x1eU] = ((__Vtemp_h9dd30ecc__1[0x1dU] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0x1eU] 
                                                 << 3U));
    __Vtemp_hdcccbf99__0[0x1fU] = ((__Vtemp_h9dd30ecc__1[0x1eU] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0x1fU] 
                                                 << 3U));
    __Vtemp_hdcccbf99__0[0x20U] = ((__Vtemp_h9dd30ecc__1[0x1fU] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__1[0x20U] 
                                                 << 3U));
    VL_SHIFTL_WWW(1028,1028,1028, __Vtemp_hfe5b1fc7__0, __Vtemp_h12ac5163__0, __Vtemp_hdcccbf99__0);
    VL_EXTEND_WI(1036,7, __Vtemp_ha5e95abe__1, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source));
    __Vtemp_haa8e0d7f__0[0U] = (__Vtemp_ha5e95abe__1[0U] 
                                << 3U);
    __Vtemp_haa8e0d7f__0[1U] = ((__Vtemp_ha5e95abe__1[0U] 
                                 >> 0x1dU) | (__Vtemp_ha5e95abe__1[1U] 
                                              << 3U));
    __Vtemp_haa8e0d7f__0[2U] = ((__Vtemp_ha5e95abe__1[1U] 
                                 >> 0x1dU) | (__Vtemp_ha5e95abe__1[2U] 
                                              << 3U));
    __Vtemp_haa8e0d7f__0[3U] = ((__Vtemp_ha5e95abe__1[2U] 
                                 >> 0x1dU) | (__Vtemp_ha5e95abe__1[3U] 
                                              << 3U));
    __Vtemp_haa8e0d7f__0[4U] = ((__Vtemp_ha5e95abe__1[3U] 
                                 >> 0x1dU) | (__Vtemp_ha5e95abe__1[4U] 
                                              << 3U));
    __Vtemp_haa8e0d7f__0[5U] = ((__Vtemp_ha5e95abe__1[4U] 
                                 >> 0x1dU) | (__Vtemp_ha5e95abe__1[5U] 
                                              << 3U));
    __Vtemp_haa8e0d7f__0[6U] = ((__Vtemp_ha5e95abe__1[5U] 
                                 >> 0x1dU) | (__Vtemp_ha5e95abe__1[6U] 
                                              << 3U));
    __Vtemp_haa8e0d7f__0[7U] = ((__Vtemp_ha5e95abe__1[6U] 
                                 >> 0x1dU) | (__Vtemp_ha5e95abe__1[7U] 
                                              << 3U));
    __Vtemp_haa8e0d7f__0[8U] = ((__Vtemp_ha5e95abe__1[7U] 
                                 >> 0x1dU) | (__Vtemp_ha5e95abe__1[8U] 
                                              << 3U));
    __Vtemp_haa8e0d7f__0[9U] = ((__Vtemp_ha5e95abe__1[8U] 
                                 >> 0x1dU) | (__Vtemp_ha5e95abe__1[9U] 
                                              << 3U));
    __Vtemp_haa8e0d7f__0[0xaU] = ((__Vtemp_ha5e95abe__1[9U] 
                                   >> 0x1dU) | (__Vtemp_ha5e95abe__1[0xaU] 
                                                << 3U));
    __Vtemp_haa8e0d7f__0[0xbU] = ((__Vtemp_ha5e95abe__1[0xaU] 
                                   >> 0x1dU) | (__Vtemp_ha5e95abe__1[0xbU] 
                                                << 3U));
    __Vtemp_haa8e0d7f__0[0xcU] = ((__Vtemp_ha5e95abe__1[0xbU] 
                                   >> 0x1dU) | (__Vtemp_ha5e95abe__1[0xcU] 
                                                << 3U));
    __Vtemp_haa8e0d7f__0[0xdU] = ((__Vtemp_ha5e95abe__1[0xcU] 
                                   >> 0x1dU) | (__Vtemp_ha5e95abe__1[0xdU] 
                                                << 3U));
    __Vtemp_haa8e0d7f__0[0xeU] = ((__Vtemp_ha5e95abe__1[0xdU] 
                                   >> 0x1dU) | (__Vtemp_ha5e95abe__1[0xeU] 
                                                << 3U));
    __Vtemp_haa8e0d7f__0[0xfU] = ((__Vtemp_ha5e95abe__1[0xeU] 
                                   >> 0x1dU) | (__Vtemp_ha5e95abe__1[0xfU] 
                                                << 3U));
    __Vtemp_haa8e0d7f__0[0x10U] = ((__Vtemp_ha5e95abe__1[0xfU] 
                                    >> 0x1dU) | (__Vtemp_ha5e95abe__1[0x10U] 
                                                 << 3U));
    __Vtemp_haa8e0d7f__0[0x11U] = ((__Vtemp_ha5e95abe__1[0x10U] 
                                    >> 0x1dU) | (__Vtemp_ha5e95abe__1[0x11U] 
                                                 << 3U));
    __Vtemp_haa8e0d7f__0[0x12U] = ((__Vtemp_ha5e95abe__1[0x11U] 
                                    >> 0x1dU) | (__Vtemp_ha5e95abe__1[0x12U] 
                                                 << 3U));
    __Vtemp_haa8e0d7f__0[0x13U] = ((__Vtemp_ha5e95abe__1[0x12U] 
                                    >> 0x1dU) | (__Vtemp_ha5e95abe__1[0x13U] 
                                                 << 3U));
    __Vtemp_haa8e0d7f__0[0x14U] = ((__Vtemp_ha5e95abe__1[0x13U] 
                                    >> 0x1dU) | (__Vtemp_ha5e95abe__1[0x14U] 
                                                 << 3U));
    __Vtemp_haa8e0d7f__0[0x15U] = ((__Vtemp_ha5e95abe__1[0x14U] 
                                    >> 0x1dU) | (__Vtemp_ha5e95abe__1[0x15U] 
                                                 << 3U));
    __Vtemp_haa8e0d7f__0[0x16U] = ((__Vtemp_ha5e95abe__1[0x15U] 
                                    >> 0x1dU) | (__Vtemp_ha5e95abe__1[0x16U] 
                                                 << 3U));
    __Vtemp_haa8e0d7f__0[0x17U] = ((__Vtemp_ha5e95abe__1[0x16U] 
                                    >> 0x1dU) | (__Vtemp_ha5e95abe__1[0x17U] 
                                                 << 3U));
    __Vtemp_haa8e0d7f__0[0x18U] = ((__Vtemp_ha5e95abe__1[0x17U] 
                                    >> 0x1dU) | (__Vtemp_ha5e95abe__1[0x18U] 
                                                 << 3U));
    __Vtemp_haa8e0d7f__0[0x19U] = ((__Vtemp_ha5e95abe__1[0x18U] 
                                    >> 0x1dU) | (__Vtemp_ha5e95abe__1[0x19U] 
                                                 << 3U));
    __Vtemp_haa8e0d7f__0[0x1aU] = ((__Vtemp_ha5e95abe__1[0x19U] 
                                    >> 0x1dU) | (__Vtemp_ha5e95abe__1[0x1aU] 
                                                 << 3U));
    __Vtemp_haa8e0d7f__0[0x1bU] = ((__Vtemp_ha5e95abe__1[0x1aU] 
                                    >> 0x1dU) | (__Vtemp_ha5e95abe__1[0x1bU] 
                                                 << 3U));
    __Vtemp_haa8e0d7f__0[0x1cU] = ((__Vtemp_ha5e95abe__1[0x1bU] 
                                    >> 0x1dU) | (__Vtemp_ha5e95abe__1[0x1cU] 
                                                 << 3U));
    __Vtemp_haa8e0d7f__0[0x1dU] = ((__Vtemp_ha5e95abe__1[0x1cU] 
                                    >> 0x1dU) | (__Vtemp_ha5e95abe__1[0x1dU] 
                                                 << 3U));
    __Vtemp_haa8e0d7f__0[0x1eU] = ((__Vtemp_ha5e95abe__1[0x1dU] 
                                    >> 0x1dU) | (__Vtemp_ha5e95abe__1[0x1eU] 
                                                 << 3U));
    __Vtemp_haa8e0d7f__0[0x1fU] = ((__Vtemp_ha5e95abe__1[0x1eU] 
                                    >> 0x1dU) | (__Vtemp_ha5e95abe__1[0x1fU] 
                                                 << 3U));
    __Vtemp_haa8e0d7f__0[0x20U] = ((__Vtemp_ha5e95abe__1[0x1fU] 
                                    >> 0x1dU) | (__Vtemp_ha5e95abe__1[0x20U] 
                                                 << 3U));
    VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_hec083356__0, VTestHarness__ConstPool__CONST_h81905067_0, __Vtemp_haa8e0d7f__0);
    __Vtemp_h59771d95__0[1U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[1U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[1U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[1U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[1U] 
                                               & __Vtemp_hfe5b1fc7__0[1U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[1U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[1U] 
                                                 & __Vtemp_hec083356__0[1U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[1U])))));
    __Vtemp_h59771d95__0[2U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[2U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[2U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[2U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[2U] 
                                               & __Vtemp_hfe5b1fc7__0[2U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[2U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[2U] 
                                                 & __Vtemp_hec083356__0[2U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[2U])))));
    __Vtemp_h59771d95__0[3U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[3U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[3U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[3U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[3U] 
                                               & __Vtemp_hfe5b1fc7__0[3U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[3U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[3U] 
                                                 & __Vtemp_hec083356__0[3U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[3U])))));
    __Vtemp_h59771d95__0[4U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[4U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[4U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[4U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[4U] 
                                               & __Vtemp_hfe5b1fc7__0[4U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[4U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[4U] 
                                                 & __Vtemp_hec083356__0[4U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[4U])))));
    __Vtemp_h59771d95__0[5U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[5U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[5U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[5U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[5U] 
                                               & __Vtemp_hfe5b1fc7__0[5U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[5U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[5U] 
                                                 & __Vtemp_hec083356__0[5U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[5U])))));
    __Vtemp_h59771d95__0[6U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[6U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[6U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[6U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[6U] 
                                               & __Vtemp_hfe5b1fc7__0[6U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[6U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[6U] 
                                                 & __Vtemp_hec083356__0[6U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[6U])))));
    __Vtemp_h59771d95__0[7U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[7U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[7U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[7U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[7U] 
                                               & __Vtemp_hfe5b1fc7__0[7U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[7U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[7U] 
                                                 & __Vtemp_hec083356__0[7U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[7U])))));
    __Vtemp_h59771d95__0[8U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[8U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[8U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[8U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[8U] 
                                               & __Vtemp_hfe5b1fc7__0[8U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[8U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[8U] 
                                                 & __Vtemp_hec083356__0[8U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[8U])))));
    __Vtemp_h59771d95__0[9U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[9U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[9U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[9U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[9U] 
                                               & __Vtemp_hfe5b1fc7__0[9U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[9U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[9U] 
                                                 & __Vtemp_hec083356__0[9U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[9U])))));
    __Vtemp_h59771d95__0[0xaU] = (VTestHarness__ConstPool__CONST_h00a540f1_0[0xaU] 
                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                      ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0xaU]
                                      : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[0xaU] 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                              ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0xaU] 
                                                 & __Vtemp_hfe5b1fc7__0[0xaU])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xaU])) 
                                         & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                                ? (
                                                   VTestHarness__ConstPool__CONST_hf1d81c7e_0[0xaU] 
                                                   & __Vtemp_hec083356__0[0xaU])
                                                : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xaU])))));
    __Vtemp_h59771d95__0[0xbU] = (VTestHarness__ConstPool__CONST_h00a540f1_0[0xbU] 
                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                      ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0xbU]
                                      : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[0xbU] 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                              ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0xbU] 
                                                 & __Vtemp_hfe5b1fc7__0[0xbU])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xbU])) 
                                         & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                                ? (
                                                   VTestHarness__ConstPool__CONST_hf1d81c7e_0[0xbU] 
                                                   & __Vtemp_hec083356__0[0xbU])
                                                : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xbU])))));
    __Vtemp_h59771d95__0[0xcU] = (VTestHarness__ConstPool__CONST_h00a540f1_0[0xcU] 
                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                      ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0xcU]
                                      : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[0xcU] 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                              ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0xcU] 
                                                 & __Vtemp_hfe5b1fc7__0[0xcU])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xcU])) 
                                         & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                                ? (
                                                   VTestHarness__ConstPool__CONST_hf1d81c7e_0[0xcU] 
                                                   & __Vtemp_hec083356__0[0xcU])
                                                : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xcU])))));
    __Vtemp_h59771d95__0[0xdU] = (VTestHarness__ConstPool__CONST_h00a540f1_0[0xdU] 
                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                      ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0xdU]
                                      : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[0xdU] 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                              ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0xdU] 
                                                 & __Vtemp_hfe5b1fc7__0[0xdU])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xdU])) 
                                         & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                                ? (
                                                   VTestHarness__ConstPool__CONST_hf1d81c7e_0[0xdU] 
                                                   & __Vtemp_hec083356__0[0xdU])
                                                : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xdU])))));
    __Vtemp_h59771d95__0[0xeU] = (VTestHarness__ConstPool__CONST_h00a540f1_0[0xeU] 
                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                      ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0xeU]
                                      : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[0xeU] 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                              ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0xeU] 
                                                 & __Vtemp_hfe5b1fc7__0[0xeU])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xeU])) 
                                         & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                                ? (
                                                   VTestHarness__ConstPool__CONST_hf1d81c7e_0[0xeU] 
                                                   & __Vtemp_hec083356__0[0xeU])
                                                : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xeU])))));
    __Vtemp_h59771d95__0[0xfU] = (VTestHarness__ConstPool__CONST_h00a540f1_0[0xfU] 
                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                      ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0xfU]
                                      : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[0xfU] 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                              ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0xfU] 
                                                 & __Vtemp_hfe5b1fc7__0[0xfU])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xfU])) 
                                         & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                                ? (
                                                   VTestHarness__ConstPool__CONST_hf1d81c7e_0[0xfU] 
                                                   & __Vtemp_hec083356__0[0xfU])
                                                : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xfU])))));
    __Vtemp_h59771d95__0[0x10U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[0x10U] 
                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                       ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0x10U]
                                       : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[0x10U] 
                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                               ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0x10U] 
                                                  & __Vtemp_hfe5b1fc7__0[0x10U])
                                               : VTestHarness__ConstPool__CONST_h881bc0c4_0[0x10U])) 
                                          & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                                 ? 
                                                (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0x10U] 
                                                 & __Vtemp_hec083356__0[0x10U])
                                                 : 
                                                VTestHarness__ConstPool__CONST_h881bc0c4_0[0x10U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[0U] 
        = (VTestHarness__ConstPool__CONST_h00a540f1_0[0U] 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
               ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0U]
               : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[0U] 
                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                       ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0U] 
                          & __Vtemp_hfe5b1fc7__0[0U])
                       : VTestHarness__ConstPool__CONST_h881bc0c4_0[0U])) 
                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                         ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0U] 
                            & __Vtemp_hec083356__0[0U])
                         : VTestHarness__ConstPool__CONST_h881bc0c4_0[0U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[1U] 
        = __Vtemp_h59771d95__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[2U] 
        = __Vtemp_h59771d95__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[3U] 
        = __Vtemp_h59771d95__0[3U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[4U] 
        = __Vtemp_h59771d95__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[5U] 
        = __Vtemp_h59771d95__0[5U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[6U] 
        = __Vtemp_h59771d95__0[6U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[7U] 
        = __Vtemp_h59771d95__0[7U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[8U] 
        = __Vtemp_h59771d95__0[8U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[9U] 
        = __Vtemp_h59771d95__0[9U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[0xaU] 
        = __Vtemp_h59771d95__0[0xaU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[0xbU] 
        = __Vtemp_h59771d95__0[0xbU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[0xcU] 
        = __Vtemp_h59771d95__0[0xcU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[0xdU] 
        = __Vtemp_h59771d95__0[0xdU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[0xeU] 
        = __Vtemp_h59771d95__0[0xeU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[0xfU] 
        = __Vtemp_h59771d95__0[0xfU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes[0x10U] 
        = __Vtemp_h59771d95__0[0x10U];
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__15228(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__15228\n"); );
    // Init
    VlWide<9>/*287:0*/ __Vtemp_h13f1ee64__0;
    VlWide<33>/*1055:0*/ __Vtemp_h5281fcd7__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9dd30ecc__0;
    VlWide<33>/*1055:0*/ __Vtemp_h65421e99__0;
    VlWide<33>/*1055:0*/ __Vtemp_h01cad281__0;
    VlWide<33>/*1055:0*/ __Vtemp_ha5e95abe__0;
    VlWide<33>/*1055:0*/ __Vtemp_h092d9994__0;
    VlWide<33>/*1055:0*/ __Vtemp_h2e4b71c1__0;
    VlWide<3>/*95:0*/ __Vtemp_hc9c98513__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__0;
    VlWide<4>/*127:0*/ __Vtemp_h1777d4f3__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__1;
    VlWide<4>/*127:0*/ __Vtemp_h5c5e292d__0;
    // Body
    VL_EXTEND_WI(1027,4, __Vtemp_h5281fcd7__0, ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                                 ? 
                                                (1U 
                                                 | (0xeU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       << 1U)))
                                                 : 0U));
    VL_EXTEND_WI(1025,7, __Vtemp_h9dd30ecc__0, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)));
    __Vtemp_h65421e99__0[0U] = (__Vtemp_h9dd30ecc__0[0U] 
                                << 2U);
    __Vtemp_h65421e99__0[1U] = ((__Vtemp_h9dd30ecc__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[1U] 
                                              << 2U));
    __Vtemp_h65421e99__0[2U] = ((__Vtemp_h9dd30ecc__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[2U] 
                                              << 2U));
    __Vtemp_h65421e99__0[3U] = ((__Vtemp_h9dd30ecc__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[3U] 
                                              << 2U));
    __Vtemp_h65421e99__0[4U] = ((__Vtemp_h9dd30ecc__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[4U] 
                                              << 2U));
    __Vtemp_h65421e99__0[5U] = ((__Vtemp_h9dd30ecc__0[4U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[5U] 
                                              << 2U));
    __Vtemp_h65421e99__0[6U] = ((__Vtemp_h9dd30ecc__0[5U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[6U] 
                                              << 2U));
    __Vtemp_h65421e99__0[7U] = ((__Vtemp_h9dd30ecc__0[6U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[7U] 
                                              << 2U));
    __Vtemp_h65421e99__0[8U] = ((__Vtemp_h9dd30ecc__0[7U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[8U] 
                                              << 2U));
    __Vtemp_h65421e99__0[9U] = ((__Vtemp_h9dd30ecc__0[8U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[9U] 
                                              << 2U));
    __Vtemp_h65421e99__0[0xaU] = ((__Vtemp_h9dd30ecc__0[9U] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xaU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xbU] = ((__Vtemp_h9dd30ecc__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xbU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xcU] = ((__Vtemp_h9dd30ecc__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xcU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xdU] = ((__Vtemp_h9dd30ecc__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xdU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xeU] = ((__Vtemp_h9dd30ecc__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xeU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xfU] = ((__Vtemp_h9dd30ecc__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xfU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0x10U] = ((__Vtemp_h9dd30ecc__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x10U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x11U] = ((__Vtemp_h9dd30ecc__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x11U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x12U] = ((__Vtemp_h9dd30ecc__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x12U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x13U] = ((__Vtemp_h9dd30ecc__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x13U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x14U] = ((__Vtemp_h9dd30ecc__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x14U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x15U] = ((__Vtemp_h9dd30ecc__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x15U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x16U] = ((__Vtemp_h9dd30ecc__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x16U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x17U] = ((__Vtemp_h9dd30ecc__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x17U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x18U] = ((__Vtemp_h9dd30ecc__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x18U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x19U] = ((__Vtemp_h9dd30ecc__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x19U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1aU] = ((__Vtemp_h9dd30ecc__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1aU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1bU] = ((__Vtemp_h9dd30ecc__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1bU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1cU] = ((__Vtemp_h9dd30ecc__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1cU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1dU] = ((__Vtemp_h9dd30ecc__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1dU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1eU] = ((__Vtemp_h9dd30ecc__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1eU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1fU] = ((__Vtemp_h9dd30ecc__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1fU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x20U] = ((__Vtemp_h9dd30ecc__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1027,1027,1027, __Vtemp_h01cad281__0, __Vtemp_h5281fcd7__0, __Vtemp_h65421e99__0);
    VL_EXTEND_WI(1037,7, __Vtemp_ha5e95abe__0, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source));
    __Vtemp_h092d9994__0[0U] = (__Vtemp_ha5e95abe__0[0U] 
                                << 2U);
    __Vtemp_h092d9994__0[1U] = ((__Vtemp_ha5e95abe__0[0U] 
                                 >> 0x1eU) | (__Vtemp_ha5e95abe__0[1U] 
                                              << 2U));
    __Vtemp_h092d9994__0[2U] = ((__Vtemp_ha5e95abe__0[1U] 
                                 >> 0x1eU) | (__Vtemp_ha5e95abe__0[2U] 
                                              << 2U));
    __Vtemp_h092d9994__0[3U] = ((__Vtemp_ha5e95abe__0[2U] 
                                 >> 0x1eU) | (__Vtemp_ha5e95abe__0[3U] 
                                              << 2U));
    __Vtemp_h092d9994__0[4U] = ((__Vtemp_ha5e95abe__0[3U] 
                                 >> 0x1eU) | (__Vtemp_ha5e95abe__0[4U] 
                                              << 2U));
    __Vtemp_h092d9994__0[5U] = ((__Vtemp_ha5e95abe__0[4U] 
                                 >> 0x1eU) | (__Vtemp_ha5e95abe__0[5U] 
                                              << 2U));
    __Vtemp_h092d9994__0[6U] = ((__Vtemp_ha5e95abe__0[5U] 
                                 >> 0x1eU) | (__Vtemp_ha5e95abe__0[6U] 
                                              << 2U));
    __Vtemp_h092d9994__0[7U] = ((__Vtemp_ha5e95abe__0[6U] 
                                 >> 0x1eU) | (__Vtemp_ha5e95abe__0[7U] 
                                              << 2U));
    __Vtemp_h092d9994__0[8U] = ((__Vtemp_ha5e95abe__0[7U] 
                                 >> 0x1eU) | (__Vtemp_ha5e95abe__0[8U] 
                                              << 2U));
    __Vtemp_h092d9994__0[9U] = ((__Vtemp_ha5e95abe__0[8U] 
                                 >> 0x1eU) | (__Vtemp_ha5e95abe__0[9U] 
                                              << 2U));
    __Vtemp_h092d9994__0[0xaU] = ((__Vtemp_ha5e95abe__0[9U] 
                                   >> 0x1eU) | (__Vtemp_ha5e95abe__0[0xaU] 
                                                << 2U));
    __Vtemp_h092d9994__0[0xbU] = ((__Vtemp_ha5e95abe__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_ha5e95abe__0[0xbU] 
                                                << 2U));
    __Vtemp_h092d9994__0[0xcU] = ((__Vtemp_ha5e95abe__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_ha5e95abe__0[0xcU] 
                                                << 2U));
    __Vtemp_h092d9994__0[0xdU] = ((__Vtemp_ha5e95abe__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_ha5e95abe__0[0xdU] 
                                                << 2U));
    __Vtemp_h092d9994__0[0xeU] = ((__Vtemp_ha5e95abe__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_ha5e95abe__0[0xeU] 
                                                << 2U));
    __Vtemp_h092d9994__0[0xfU] = ((__Vtemp_ha5e95abe__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_ha5e95abe__0[0xfU] 
                                                << 2U));
    __Vtemp_h092d9994__0[0x10U] = ((__Vtemp_ha5e95abe__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x10U] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x11U] = ((__Vtemp_ha5e95abe__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x11U] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x12U] = ((__Vtemp_ha5e95abe__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x12U] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x13U] = ((__Vtemp_ha5e95abe__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x13U] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x14U] = ((__Vtemp_ha5e95abe__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x14U] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x15U] = ((__Vtemp_ha5e95abe__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x15U] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x16U] = ((__Vtemp_ha5e95abe__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x16U] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x17U] = ((__Vtemp_ha5e95abe__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x17U] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x18U] = ((__Vtemp_ha5e95abe__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x18U] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x19U] = ((__Vtemp_ha5e95abe__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x19U] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x1aU] = ((__Vtemp_ha5e95abe__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x1aU] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x1bU] = ((__Vtemp_ha5e95abe__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x1bU] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x1cU] = ((__Vtemp_ha5e95abe__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x1cU] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x1dU] = ((__Vtemp_ha5e95abe__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x1dU] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x1eU] = ((__Vtemp_ha5e95abe__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x1eU] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x1fU] = ((__Vtemp_ha5e95abe__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x1fU] 
                                                 << 2U));
    __Vtemp_h092d9994__0[0x20U] = ((__Vtemp_ha5e95abe__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_ha5e95abe__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_h2e4b71c1__0, VTestHarness__ConstPool__CONST_h3892cc72_0, __Vtemp_h092d9994__0);
    __Vtemp_h13f1ee64__0[1U] = (VTestHarness__ConstPool__CONST_h52851b57_0[1U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[1U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes[1U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[1U] 
                                               & __Vtemp_h01cad281__0[1U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[1U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[1U] 
                                                 & __Vtemp_h2e4b71c1__0[1U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[1U])))));
    __Vtemp_h13f1ee64__0[2U] = (VTestHarness__ConstPool__CONST_h52851b57_0[2U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[2U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes[2U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[2U] 
                                               & __Vtemp_h01cad281__0[2U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[2U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[2U] 
                                                 & __Vtemp_h2e4b71c1__0[2U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[2U])))));
    __Vtemp_h13f1ee64__0[3U] = (VTestHarness__ConstPool__CONST_h52851b57_0[3U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[3U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes[3U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[3U] 
                                               & __Vtemp_h01cad281__0[3U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[3U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[3U] 
                                                 & __Vtemp_h2e4b71c1__0[3U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[3U])))));
    __Vtemp_h13f1ee64__0[4U] = (VTestHarness__ConstPool__CONST_h52851b57_0[4U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[4U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes[4U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[4U] 
                                               & __Vtemp_h01cad281__0[4U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[4U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[4U] 
                                                 & __Vtemp_h2e4b71c1__0[4U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[4U])))));
    __Vtemp_h13f1ee64__0[5U] = (VTestHarness__ConstPool__CONST_h52851b57_0[5U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[5U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes[5U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[5U] 
                                               & __Vtemp_h01cad281__0[5U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[5U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[5U] 
                                                 & __Vtemp_h2e4b71c1__0[5U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[5U])))));
    __Vtemp_h13f1ee64__0[6U] = (VTestHarness__ConstPool__CONST_h52851b57_0[6U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[6U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes[6U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[6U] 
                                               & __Vtemp_h01cad281__0[6U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[6U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[6U] 
                                                 & __Vtemp_h2e4b71c1__0[6U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[6U])))));
    __Vtemp_h13f1ee64__0[7U] = (VTestHarness__ConstPool__CONST_h52851b57_0[7U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[7U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes[7U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[7U] 
                                               & __Vtemp_h01cad281__0[7U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[7U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[7U] 
                                                 & __Vtemp_h2e4b71c1__0[7U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[7U])))));
    __Vtemp_h13f1ee64__0[8U] = (VTestHarness__ConstPool__CONST_h52851b57_0[8U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[8U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes[8U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[8U] 
                                               & __Vtemp_h01cad281__0[8U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[8U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[8U] 
                                                 & __Vtemp_h2e4b71c1__0[8U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[8U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes[0U] 
        = (VTestHarness__ConstPool__CONST_h52851b57_0[0U] 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
               ? VTestHarness__ConstPool__CONST_h478702bb_0[0U]
               : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes[0U] 
                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                       ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[0U] 
                          & __Vtemp_h01cad281__0[0U])
                       : VTestHarness__ConstPool__CONST_h478702bb_0[0U])) 
                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                         ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0U] 
                            & __Vtemp_h2e4b71c1__0[0U])
                         : VTestHarness__ConstPool__CONST_h478702bb_0[0U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes[1U] 
        = __Vtemp_h13f1ee64__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes[2U] 
        = __Vtemp_h13f1ee64__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes[3U] 
        = __Vtemp_h13f1ee64__0[3U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes[4U] 
        = __Vtemp_h13f1ee64__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes[5U] 
        = __Vtemp_h13f1ee64__0[5U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes[6U] 
        = __Vtemp_h13f1ee64__0[6U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes[7U] 
        = __Vtemp_h13f1ee64__0[7U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes[8U] 
        = __Vtemp_h13f1ee64__0[8U];
    __Vtemp_hc961d23f__0[0U] = 1U;
    __Vtemp_hc961d23f__0[1U] = 0U;
    __Vtemp_hc961d23f__0[2U] = 0U;
    __Vtemp_hc961d23f__0[3U] = 0U;
    VL_SHIFTL_WWI(128,128,7, __Vtemp_h1777d4f3__0, __Vtemp_hc961d23f__0, 
                  (0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                            >> 0xaU)));
    __Vtemp_hc961d23f__1[0U] = 1U;
    __Vtemp_hc961d23f__1[1U] = 0U;
    __Vtemp_hc961d23f__1[2U] = 0U;
    __Vtemp_hc961d23f__1[3U] = 0U;
    VL_SHIFTL_WWI(128,128,7, __Vtemp_h5c5e292d__0, __Vtemp_hc961d23f__1, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset) {
        __Vtemp_hc9c98513__0[1U] = 0U;
        __Vtemp_hc9c98513__0[2U] = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight[0U] = 0U;
        vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 = 0ULL;
    } else {
        __Vtemp_hc9c98513__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight[1U] 
                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                         ? __Vtemp_h1777d4f3__0[1U]
                                         : 0U)) & (~ 
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                                     ? 
                                                    __Vtemp_h5c5e292d__0[1U]
                                                     : 0U)));
        __Vtemp_hc9c98513__0[2U] = (1U & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight[2U] 
                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                                               ? __Vtemp_h1777d4f3__0[2U]
                                               : 0U)) 
                                          & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                                                 ? 
                                                __Vtemp_h5c5e292d__0[2U]
                                                 : 0U))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight[0U] 
            = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight[0U] 
                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1584)
                    ? __Vtemp_h1777d4f3__0[0U] : 0U)) 
               & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT___T_1599)
                      ? __Vtemp_h5c5e292d__0[0U] : 0U)));
        if (((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_0) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_1)) 
                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_2)) 
                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_3)) 
                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_4)) 
               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_5)) 
              | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_6)) 
             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_7))) {
            vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 
                = (((QData)((IData)(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_7)
                                        ? ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                            << 0x10U) 
                                           | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                              >> 0x10U))
                                        : (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 
                                                   >> 0x38U))) 
                                      << 0x18U) | (
                                                   (0xff0000U 
                                                    & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_6)
                                                         ? 
                                                        ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                                          << 0x18U) 
                                                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                                            >> 8U))
                                                         : (IData)(
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 
                                                                    >> 0x30U))) 
                                                       << 0x10U)) 
                                                   | ((0xff00U 
                                                       & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_5)
                                                            ? 
                                                           vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U]
                                                            : (IData)(
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 
                                                                       >> 0x28U))) 
                                                          << 8U)) 
                                                      | (0xffU 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_4)
                                                             ? 
                                                            ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U] 
                                                              << 8U) 
                                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U] 
                                                                >> 0x18U))
                                                             : (IData)(
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 
                                                                        >> 0x20U))))))))) 
                    << 0x20U) | (QData)((IData)(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_3)
                                                    ? 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U] 
                                                     << 0x10U) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U] 
                                                       >> 0x10U))
                                                    : (IData)(
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 
                                                               >> 0x18U))) 
                                                  << 0x18U) 
                                                 | ((0xff0000U 
                                                     & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_2)
                                                          ? 
                                                         ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U] 
                                                           << 0x18U) 
                                                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U] 
                                                             >> 8U))
                                                          : (IData)(
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 
                                                                     >> 0x10U))) 
                                                        << 0x10U)) 
                                                    | ((0xff00U 
                                                        & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_1)
                                                             ? 
                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U]
                                                             : (IData)(
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 
                                                                        >> 8U))) 
                                                           << 8U)) 
                                                       | (0xffU 
                                                          & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_0)
                                                              ? 
                                                             ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                               << 8U) 
                                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                                 >> 0x18U))
                                                              : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0)))))))));
        } else if ((0xc7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__int_rtc_tick_c_value))) {
            vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 
                = (1ULL + vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0);
        }
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight[1U] 
        = __Vtemp_hc9c98513__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight[2U] 
        = __Vtemp_hc9c98513__0[2U];
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__15229(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__15229\n"); );
    // Init
    VlWide<9>/*287:0*/ __Vtemp_hae8e16a3__0;
    VlWide<33>/*1055:0*/ __Vtemp_h2bef47a0__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9dd30ecc__0;
    VlWide<33>/*1055:0*/ __Vtemp_h65421e99__0;
    VlWide<33>/*1055:0*/ __Vtemp_h00155da8__0;
    VlWide<33>/*1055:0*/ __Vtemp_h45cda2df__0;
    VlWide<33>/*1055:0*/ __Vtemp_hc4c695b1__0;
    VlWide<33>/*1055:0*/ __Vtemp_h1d360246__0;
    VlWide<9>/*287:0*/ __Vtemp_h151081f0__0;
    VlWide<33>/*1055:0*/ __Vtemp_hbfed2efa__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9dd30ecc__1;
    VlWide<33>/*1055:0*/ __Vtemp_hdccc2f4a__0;
    VlWide<33>/*1055:0*/ __Vtemp_h0164b999__0;
    VlWide<33>/*1055:0*/ __Vtemp_h45cda2df__1;
    VlWide<33>/*1055:0*/ __Vtemp_h9051941e__0;
    VlWide<33>/*1055:0*/ __Vtemp_hdbe524af__0;
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___T_1) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT__saved_address 
            = (0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                             << 0xfU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                         >> 0x11U)));
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___T_1) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__saved_address 
            = (0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                             << 0xfU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                         >> 0x11U)));
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___T_1) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT__saved_address 
            = (0xfffffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                              << 0xfU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                          >> 0x11U)));
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___T_1) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__saved_address 
            = (0x3ffffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                              << 0xfU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                          >> 0x11U)));
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__repeater__DOT___T_1) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__repeater__DOT__saved_address 
            = (0x1ffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                            << 0xfU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                        >> 0x11U)));
    }
    VL_EXTEND_WI(1027,4, __Vtemp_h2bef47a0__0, ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                                                 ? 
                                                (1U 
                                                 | (0xeU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 5U)))
                                                 : 0U));
    VL_EXTEND_WI(1025,7, __Vtemp_h9dd30ecc__0, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)));
    __Vtemp_h65421e99__0[0U] = (__Vtemp_h9dd30ecc__0[0U] 
                                << 2U);
    __Vtemp_h65421e99__0[1U] = ((__Vtemp_h9dd30ecc__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[1U] 
                                              << 2U));
    __Vtemp_h65421e99__0[2U] = ((__Vtemp_h9dd30ecc__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[2U] 
                                              << 2U));
    __Vtemp_h65421e99__0[3U] = ((__Vtemp_h9dd30ecc__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[3U] 
                                              << 2U));
    __Vtemp_h65421e99__0[4U] = ((__Vtemp_h9dd30ecc__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[4U] 
                                              << 2U));
    __Vtemp_h65421e99__0[5U] = ((__Vtemp_h9dd30ecc__0[4U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[5U] 
                                              << 2U));
    __Vtemp_h65421e99__0[6U] = ((__Vtemp_h9dd30ecc__0[5U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[6U] 
                                              << 2U));
    __Vtemp_h65421e99__0[7U] = ((__Vtemp_h9dd30ecc__0[6U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[7U] 
                                              << 2U));
    __Vtemp_h65421e99__0[8U] = ((__Vtemp_h9dd30ecc__0[7U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[8U] 
                                              << 2U));
    __Vtemp_h65421e99__0[9U] = ((__Vtemp_h9dd30ecc__0[8U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[9U] 
                                              << 2U));
    __Vtemp_h65421e99__0[0xaU] = ((__Vtemp_h9dd30ecc__0[9U] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xaU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xbU] = ((__Vtemp_h9dd30ecc__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xbU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xcU] = ((__Vtemp_h9dd30ecc__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xcU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xdU] = ((__Vtemp_h9dd30ecc__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xdU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xeU] = ((__Vtemp_h9dd30ecc__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xeU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xfU] = ((__Vtemp_h9dd30ecc__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xfU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0x10U] = ((__Vtemp_h9dd30ecc__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x10U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x11U] = ((__Vtemp_h9dd30ecc__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x11U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x12U] = ((__Vtemp_h9dd30ecc__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x12U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x13U] = ((__Vtemp_h9dd30ecc__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x13U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x14U] = ((__Vtemp_h9dd30ecc__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x14U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x15U] = ((__Vtemp_h9dd30ecc__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x15U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x16U] = ((__Vtemp_h9dd30ecc__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x16U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x17U] = ((__Vtemp_h9dd30ecc__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x17U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x18U] = ((__Vtemp_h9dd30ecc__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x18U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x19U] = ((__Vtemp_h9dd30ecc__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x19U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1aU] = ((__Vtemp_h9dd30ecc__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1aU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1bU] = ((__Vtemp_h9dd30ecc__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1bU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1cU] = ((__Vtemp_h9dd30ecc__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1cU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1dU] = ((__Vtemp_h9dd30ecc__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1dU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1eU] = ((__Vtemp_h9dd30ecc__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1eU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1fU] = ((__Vtemp_h9dd30ecc__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1fU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x20U] = ((__Vtemp_h9dd30ecc__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1027,1027,1027, __Vtemp_h00155da8__0, __Vtemp_h2bef47a0__0, __Vtemp_h65421e99__0);
    VL_EXTEND_WI(1037,7, __Vtemp_h45cda2df__0, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 8U)));
    __Vtemp_hc4c695b1__0[0U] = (__Vtemp_h45cda2df__0[0U] 
                                << 2U);
    __Vtemp_hc4c695b1__0[1U] = ((__Vtemp_h45cda2df__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h45cda2df__0[1U] 
                                              << 2U));
    __Vtemp_hc4c695b1__0[2U] = ((__Vtemp_h45cda2df__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h45cda2df__0[2U] 
                                              << 2U));
    __Vtemp_hc4c695b1__0[3U] = ((__Vtemp_h45cda2df__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h45cda2df__0[3U] 
                                              << 2U));
    __Vtemp_hc4c695b1__0[4U] = ((__Vtemp_h45cda2df__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h45cda2df__0[4U] 
                                              << 2U));
    __Vtemp_hc4c695b1__0[5U] = ((__Vtemp_h45cda2df__0[4U] 
                                 >> 0x1eU) | (__Vtemp_h45cda2df__0[5U] 
                                              << 2U));
    __Vtemp_hc4c695b1__0[6U] = ((__Vtemp_h45cda2df__0[5U] 
                                 >> 0x1eU) | (__Vtemp_h45cda2df__0[6U] 
                                              << 2U));
    __Vtemp_hc4c695b1__0[7U] = ((__Vtemp_h45cda2df__0[6U] 
                                 >> 0x1eU) | (__Vtemp_h45cda2df__0[7U] 
                                              << 2U));
    __Vtemp_hc4c695b1__0[8U] = ((__Vtemp_h45cda2df__0[7U] 
                                 >> 0x1eU) | (__Vtemp_h45cda2df__0[8U] 
                                              << 2U));
    __Vtemp_hc4c695b1__0[9U] = ((__Vtemp_h45cda2df__0[8U] 
                                 >> 0x1eU) | (__Vtemp_h45cda2df__0[9U] 
                                              << 2U));
    __Vtemp_hc4c695b1__0[0xaU] = ((__Vtemp_h45cda2df__0[9U] 
                                   >> 0x1eU) | (__Vtemp_h45cda2df__0[0xaU] 
                                                << 2U));
    __Vtemp_hc4c695b1__0[0xbU] = ((__Vtemp_h45cda2df__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h45cda2df__0[0xbU] 
                                                << 2U));
    __Vtemp_hc4c695b1__0[0xcU] = ((__Vtemp_h45cda2df__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h45cda2df__0[0xcU] 
                                                << 2U));
    __Vtemp_hc4c695b1__0[0xdU] = ((__Vtemp_h45cda2df__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h45cda2df__0[0xdU] 
                                                << 2U));
    __Vtemp_hc4c695b1__0[0xeU] = ((__Vtemp_h45cda2df__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h45cda2df__0[0xeU] 
                                                << 2U));
    __Vtemp_hc4c695b1__0[0xfU] = ((__Vtemp_h45cda2df__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h45cda2df__0[0xfU] 
                                                << 2U));
    __Vtemp_hc4c695b1__0[0x10U] = ((__Vtemp_h45cda2df__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__0[0x10U] 
                                                 << 2U));
    __Vtemp_hc4c695b1__0[0x11U] = ((__Vtemp_h45cda2df__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__0[0x11U] 
                                                 << 2U));
    __Vtemp_hc4c695b1__0[0x12U] = ((__Vtemp_h45cda2df__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__0[0x12U] 
                                                 << 2U));
    __Vtemp_hc4c695b1__0[0x13U] = ((__Vtemp_h45cda2df__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__0[0x13U] 
                                                 << 2U));
    __Vtemp_hc4c695b1__0[0x14U] = ((__Vtemp_h45cda2df__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__0[0x14U] 
                                                 << 2U));
    __Vtemp_hc4c695b1__0[0x15U] = ((__Vtemp_h45cda2df__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__0[0x15U] 
                                                 << 2U));
    __Vtemp_hc4c695b1__0[0x16U] = ((__Vtemp_h45cda2df__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__0[0x16U] 
                                                 << 2U));
    __Vtemp_hc4c695b1__0[0x17U] = ((__Vtemp_h45cda2df__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__0[0x17U] 
                                                 << 2U));
    __Vtemp_hc4c695b1__0[0x18U] = ((__Vtemp_h45cda2df__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__0[0x18U] 
                                                 << 2U));
    __Vtemp_hc4c695b1__0[0x19U] = ((__Vtemp_h45cda2df__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__0[0x19U] 
                                                 << 2U));
    __Vtemp_hc4c695b1__0[0x1aU] = ((__Vtemp_h45cda2df__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__0[0x1aU] 
                                                 << 2U));
    __Vtemp_hc4c695b1__0[0x1bU] = ((__Vtemp_h45cda2df__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__0[0x1bU] 
                                                 << 2U));
    __Vtemp_hc4c695b1__0[0x1cU] = ((__Vtemp_h45cda2df__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__0[0x1cU] 
                                                 << 2U));
    __Vtemp_hc4c695b1__0[0x1dU] = ((__Vtemp_h45cda2df__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__0[0x1dU] 
                                                 << 2U));
    __Vtemp_hc4c695b1__0[0x1eU] = ((__Vtemp_h45cda2df__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__0[0x1eU] 
                                                 << 2U));
    __Vtemp_hc4c695b1__0[0x1fU] = ((__Vtemp_h45cda2df__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__0[0x1fU] 
                                                 << 2U));
    __Vtemp_hc4c695b1__0[0x20U] = ((__Vtemp_h45cda2df__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_h1d360246__0, VTestHarness__ConstPool__CONST_h3892cc72_0, __Vtemp_hc4c695b1__0);
    __Vtemp_hae8e16a3__0[1U] = (VTestHarness__ConstPool__CONST_h52851b57_0[1U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[1U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_sizes[1U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[1U] 
                                               & __Vtemp_h00155da8__0[1U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[1U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1199)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[1U] 
                                                 & __Vtemp_h1d360246__0[1U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[1U])))));
    __Vtemp_hae8e16a3__0[2U] = (VTestHarness__ConstPool__CONST_h52851b57_0[2U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[2U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_sizes[2U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[2U] 
                                               & __Vtemp_h00155da8__0[2U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[2U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1199)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[2U] 
                                                 & __Vtemp_h1d360246__0[2U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[2U])))));
    __Vtemp_hae8e16a3__0[3U] = (VTestHarness__ConstPool__CONST_h52851b57_0[3U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[3U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_sizes[3U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[3U] 
                                               & __Vtemp_h00155da8__0[3U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[3U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1199)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[3U] 
                                                 & __Vtemp_h1d360246__0[3U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[3U])))));
    __Vtemp_hae8e16a3__0[4U] = (VTestHarness__ConstPool__CONST_h52851b57_0[4U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[4U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_sizes[4U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[4U] 
                                               & __Vtemp_h00155da8__0[4U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[4U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1199)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[4U] 
                                                 & __Vtemp_h1d360246__0[4U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[4U])))));
    __Vtemp_hae8e16a3__0[5U] = (VTestHarness__ConstPool__CONST_h52851b57_0[5U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[5U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_sizes[5U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[5U] 
                                               & __Vtemp_h00155da8__0[5U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[5U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1199)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[5U] 
                                                 & __Vtemp_h1d360246__0[5U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[5U])))));
    __Vtemp_hae8e16a3__0[6U] = (VTestHarness__ConstPool__CONST_h52851b57_0[6U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[6U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_sizes[6U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[6U] 
                                               & __Vtemp_h00155da8__0[6U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[6U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1199)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[6U] 
                                                 & __Vtemp_h1d360246__0[6U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[6U])))));
    __Vtemp_hae8e16a3__0[7U] = (VTestHarness__ConstPool__CONST_h52851b57_0[7U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[7U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_sizes[7U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[7U] 
                                               & __Vtemp_h00155da8__0[7U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[7U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1199)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[7U] 
                                                 & __Vtemp_h1d360246__0[7U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[7U])))));
    __Vtemp_hae8e16a3__0[8U] = (VTestHarness__ConstPool__CONST_h52851b57_0[8U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[8U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_sizes[8U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[8U] 
                                               & __Vtemp_h00155da8__0[8U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[8U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1199)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[8U] 
                                                 & __Vtemp_h1d360246__0[8U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[8U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_sizes[0U] 
        = (VTestHarness__ConstPool__CONST_h52851b57_0[0U] 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
               ? VTestHarness__ConstPool__CONST_h478702bb_0[0U]
               : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_sizes[0U] 
                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                       ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[0U] 
                          & __Vtemp_h00155da8__0[0U])
                       : VTestHarness__ConstPool__CONST_h478702bb_0[0U])) 
                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1199)
                         ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0U] 
                            & __Vtemp_h1d360246__0[0U])
                         : VTestHarness__ConstPool__CONST_h478702bb_0[0U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_sizes[1U] 
        = __Vtemp_hae8e16a3__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_sizes[2U] 
        = __Vtemp_hae8e16a3__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_sizes[3U] 
        = __Vtemp_hae8e16a3__0[3U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_sizes[4U] 
        = __Vtemp_hae8e16a3__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_sizes[5U] 
        = __Vtemp_hae8e16a3__0[5U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_sizes[6U] 
        = __Vtemp_hae8e16a3__0[6U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_sizes[7U] 
        = __Vtemp_hae8e16a3__0[7U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_sizes[8U] 
        = __Vtemp_hae8e16a3__0[8U];
    VL_EXTEND_WI(1027,4, __Vtemp_hbfed2efa__0, ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                                                 ? 
                                                (1U 
                                                 | (0xeU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       << 1U)))
                                                 : 0U));
    VL_EXTEND_WI(1025,7, __Vtemp_h9dd30ecc__1, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)));
    __Vtemp_hdccc2f4a__0[0U] = (__Vtemp_h9dd30ecc__1[0U] 
                                << 2U);
    __Vtemp_hdccc2f4a__0[1U] = ((__Vtemp_h9dd30ecc__1[0U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[1U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[2U] = ((__Vtemp_h9dd30ecc__1[1U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[2U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[3U] = ((__Vtemp_h9dd30ecc__1[2U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[3U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[4U] = ((__Vtemp_h9dd30ecc__1[3U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[4U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[5U] = ((__Vtemp_h9dd30ecc__1[4U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[5U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[6U] = ((__Vtemp_h9dd30ecc__1[5U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[6U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[7U] = ((__Vtemp_h9dd30ecc__1[6U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[7U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[8U] = ((__Vtemp_h9dd30ecc__1[7U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[8U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[9U] = ((__Vtemp_h9dd30ecc__1[8U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[9U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[0xaU] = ((__Vtemp_h9dd30ecc__1[9U] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xaU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xbU] = ((__Vtemp_h9dd30ecc__1[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xbU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xcU] = ((__Vtemp_h9dd30ecc__1[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xcU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xdU] = ((__Vtemp_h9dd30ecc__1[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xdU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xeU] = ((__Vtemp_h9dd30ecc__1[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xeU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xfU] = ((__Vtemp_h9dd30ecc__1[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xfU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0x10U] = ((__Vtemp_h9dd30ecc__1[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x10U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x11U] = ((__Vtemp_h9dd30ecc__1[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x11U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x12U] = ((__Vtemp_h9dd30ecc__1[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x12U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x13U] = ((__Vtemp_h9dd30ecc__1[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x13U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x14U] = ((__Vtemp_h9dd30ecc__1[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x14U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x15U] = ((__Vtemp_h9dd30ecc__1[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x15U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x16U] = ((__Vtemp_h9dd30ecc__1[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x16U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x17U] = ((__Vtemp_h9dd30ecc__1[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x17U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x18U] = ((__Vtemp_h9dd30ecc__1[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x18U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x19U] = ((__Vtemp_h9dd30ecc__1[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x19U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1aU] = ((__Vtemp_h9dd30ecc__1[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1aU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1bU] = ((__Vtemp_h9dd30ecc__1[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1bU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1cU] = ((__Vtemp_h9dd30ecc__1[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1cU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1dU] = ((__Vtemp_h9dd30ecc__1[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1dU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1eU] = ((__Vtemp_h9dd30ecc__1[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1eU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1fU] = ((__Vtemp_h9dd30ecc__1[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1fU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x20U] = ((__Vtemp_h9dd30ecc__1[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1027,1027,1027, __Vtemp_h0164b999__0, __Vtemp_hbfed2efa__0, __Vtemp_hdccc2f4a__0);
    VL_EXTEND_WI(1037,7, __Vtemp_h45cda2df__1, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 8U)));
    __Vtemp_h9051941e__0[0U] = (__Vtemp_h45cda2df__1[0U] 
                                << 2U);
    __Vtemp_h9051941e__0[1U] = ((__Vtemp_h45cda2df__1[0U] 
                                 >> 0x1eU) | (__Vtemp_h45cda2df__1[1U] 
                                              << 2U));
    __Vtemp_h9051941e__0[2U] = ((__Vtemp_h45cda2df__1[1U] 
                                 >> 0x1eU) | (__Vtemp_h45cda2df__1[2U] 
                                              << 2U));
    __Vtemp_h9051941e__0[3U] = ((__Vtemp_h45cda2df__1[2U] 
                                 >> 0x1eU) | (__Vtemp_h45cda2df__1[3U] 
                                              << 2U));
    __Vtemp_h9051941e__0[4U] = ((__Vtemp_h45cda2df__1[3U] 
                                 >> 0x1eU) | (__Vtemp_h45cda2df__1[4U] 
                                              << 2U));
    __Vtemp_h9051941e__0[5U] = ((__Vtemp_h45cda2df__1[4U] 
                                 >> 0x1eU) | (__Vtemp_h45cda2df__1[5U] 
                                              << 2U));
    __Vtemp_h9051941e__0[6U] = ((__Vtemp_h45cda2df__1[5U] 
                                 >> 0x1eU) | (__Vtemp_h45cda2df__1[6U] 
                                              << 2U));
    __Vtemp_h9051941e__0[7U] = ((__Vtemp_h45cda2df__1[6U] 
                                 >> 0x1eU) | (__Vtemp_h45cda2df__1[7U] 
                                              << 2U));
    __Vtemp_h9051941e__0[8U] = ((__Vtemp_h45cda2df__1[7U] 
                                 >> 0x1eU) | (__Vtemp_h45cda2df__1[8U] 
                                              << 2U));
    __Vtemp_h9051941e__0[9U] = ((__Vtemp_h45cda2df__1[8U] 
                                 >> 0x1eU) | (__Vtemp_h45cda2df__1[9U] 
                                              << 2U));
    __Vtemp_h9051941e__0[0xaU] = ((__Vtemp_h45cda2df__1[9U] 
                                   >> 0x1eU) | (__Vtemp_h45cda2df__1[0xaU] 
                                                << 2U));
    __Vtemp_h9051941e__0[0xbU] = ((__Vtemp_h45cda2df__1[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h45cda2df__1[0xbU] 
                                                << 2U));
    __Vtemp_h9051941e__0[0xcU] = ((__Vtemp_h45cda2df__1[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h45cda2df__1[0xcU] 
                                                << 2U));
    __Vtemp_h9051941e__0[0xdU] = ((__Vtemp_h45cda2df__1[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h45cda2df__1[0xdU] 
                                                << 2U));
    __Vtemp_h9051941e__0[0xeU] = ((__Vtemp_h45cda2df__1[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h45cda2df__1[0xeU] 
                                                << 2U));
    __Vtemp_h9051941e__0[0xfU] = ((__Vtemp_h45cda2df__1[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h45cda2df__1[0xfU] 
                                                << 2U));
    __Vtemp_h9051941e__0[0x10U] = ((__Vtemp_h45cda2df__1[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__1[0x10U] 
                                                 << 2U));
    __Vtemp_h9051941e__0[0x11U] = ((__Vtemp_h45cda2df__1[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__1[0x11U] 
                                                 << 2U));
    __Vtemp_h9051941e__0[0x12U] = ((__Vtemp_h45cda2df__1[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__1[0x12U] 
                                                 << 2U));
    __Vtemp_h9051941e__0[0x13U] = ((__Vtemp_h45cda2df__1[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__1[0x13U] 
                                                 << 2U));
    __Vtemp_h9051941e__0[0x14U] = ((__Vtemp_h45cda2df__1[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__1[0x14U] 
                                                 << 2U));
    __Vtemp_h9051941e__0[0x15U] = ((__Vtemp_h45cda2df__1[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__1[0x15U] 
                                                 << 2U));
    __Vtemp_h9051941e__0[0x16U] = ((__Vtemp_h45cda2df__1[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__1[0x16U] 
                                                 << 2U));
    __Vtemp_h9051941e__0[0x17U] = ((__Vtemp_h45cda2df__1[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__1[0x17U] 
                                                 << 2U));
    __Vtemp_h9051941e__0[0x18U] = ((__Vtemp_h45cda2df__1[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__1[0x18U] 
                                                 << 2U));
    __Vtemp_h9051941e__0[0x19U] = ((__Vtemp_h45cda2df__1[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__1[0x19U] 
                                                 << 2U));
    __Vtemp_h9051941e__0[0x1aU] = ((__Vtemp_h45cda2df__1[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__1[0x1aU] 
                                                 << 2U));
    __Vtemp_h9051941e__0[0x1bU] = ((__Vtemp_h45cda2df__1[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__1[0x1bU] 
                                                 << 2U));
    __Vtemp_h9051941e__0[0x1cU] = ((__Vtemp_h45cda2df__1[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__1[0x1cU] 
                                                 << 2U));
    __Vtemp_h9051941e__0[0x1dU] = ((__Vtemp_h45cda2df__1[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__1[0x1dU] 
                                                 << 2U));
    __Vtemp_h9051941e__0[0x1eU] = ((__Vtemp_h45cda2df__1[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__1[0x1eU] 
                                                 << 2U));
    __Vtemp_h9051941e__0[0x1fU] = ((__Vtemp_h45cda2df__1[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__1[0x1fU] 
                                                 << 2U));
    __Vtemp_h9051941e__0[0x20U] = ((__Vtemp_h45cda2df__1[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h45cda2df__1[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_hdbe524af__0, VTestHarness__ConstPool__CONST_h3892cc72_0, __Vtemp_h9051941e__0);
    __Vtemp_h151081f0__0[1U] = (VTestHarness__ConstPool__CONST_h52851b57_0[1U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[1U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_opcodes[1U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[1U] 
                                               & __Vtemp_h0164b999__0[1U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[1U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1199)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[1U] 
                                                 & __Vtemp_hdbe524af__0[1U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[1U])))));
    __Vtemp_h151081f0__0[2U] = (VTestHarness__ConstPool__CONST_h52851b57_0[2U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[2U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_opcodes[2U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[2U] 
                                               & __Vtemp_h0164b999__0[2U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[2U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1199)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[2U] 
                                                 & __Vtemp_hdbe524af__0[2U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[2U])))));
    __Vtemp_h151081f0__0[3U] = (VTestHarness__ConstPool__CONST_h52851b57_0[3U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[3U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_opcodes[3U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[3U] 
                                               & __Vtemp_h0164b999__0[3U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[3U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1199)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[3U] 
                                                 & __Vtemp_hdbe524af__0[3U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[3U])))));
    __Vtemp_h151081f0__0[4U] = (VTestHarness__ConstPool__CONST_h52851b57_0[4U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[4U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_opcodes[4U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[4U] 
                                               & __Vtemp_h0164b999__0[4U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[4U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1199)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[4U] 
                                                 & __Vtemp_hdbe524af__0[4U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[4U])))));
    __Vtemp_h151081f0__0[5U] = (VTestHarness__ConstPool__CONST_h52851b57_0[5U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[5U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_opcodes[5U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[5U] 
                                               & __Vtemp_h0164b999__0[5U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[5U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1199)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[5U] 
                                                 & __Vtemp_hdbe524af__0[5U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[5U])))));
    __Vtemp_h151081f0__0[6U] = (VTestHarness__ConstPool__CONST_h52851b57_0[6U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[6U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_opcodes[6U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[6U] 
                                               & __Vtemp_h0164b999__0[6U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[6U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1199)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[6U] 
                                                 & __Vtemp_hdbe524af__0[6U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[6U])))));
    __Vtemp_h151081f0__0[7U] = (VTestHarness__ConstPool__CONST_h52851b57_0[7U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[7U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_opcodes[7U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[7U] 
                                               & __Vtemp_h0164b999__0[7U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[7U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1199)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[7U] 
                                                 & __Vtemp_hdbe524af__0[7U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[7U])))));
    __Vtemp_h151081f0__0[8U] = (VTestHarness__ConstPool__CONST_h52851b57_0[8U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[8U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_opcodes[8U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[8U] 
                                               & __Vtemp_h0164b999__0[8U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[8U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1199)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[8U] 
                                                 & __Vtemp_hdbe524af__0[8U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[8U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_opcodes[0U] 
        = (VTestHarness__ConstPool__CONST_h52851b57_0[0U] 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
               ? VTestHarness__ConstPool__CONST_h478702bb_0[0U]
               : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_opcodes[0U] 
                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                       ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[0U] 
                          & __Vtemp_h0164b999__0[0U])
                       : VTestHarness__ConstPool__CONST_h478702bb_0[0U])) 
                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1199)
                         ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0U] 
                            & __Vtemp_hdbe524af__0[0U])
                         : VTestHarness__ConstPool__CONST_h478702bb_0[0U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_opcodes[1U] 
        = __Vtemp_h151081f0__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_opcodes[2U] 
        = __Vtemp_h151081f0__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_opcodes[3U] 
        = __Vtemp_h151081f0__0[3U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_opcodes[4U] 
        = __Vtemp_h151081f0__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_opcodes[5U] 
        = __Vtemp_h151081f0__0[5U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_opcodes[6U] 
        = __Vtemp_h151081f0__0[6U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_opcodes[7U] 
        = __Vtemp_h151081f0__0[7U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight_opcodes[8U] 
        = __Vtemp_h151081f0__0[8U];
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__15230(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__15230\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_he70fd588__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__0;
    VlWide<4>/*127:0*/ __Vtemp_h9a9a6856__0;
    VlWide<4>/*127:0*/ __Vtemp_hca162495__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__1;
    VlWide<4>/*127:0*/ __Vtemp_h42b5cca9__0;
    VlWide<4>/*127:0*/ __Vtemp_h20a81ffc__0;
    VlWide<17>/*543:0*/ __Vtemp_h0947b9cb__0;
    VlWide<33>/*1055:0*/ __Vtemp_hc06f2ff0__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9dd30ecc__0;
    VlWide<33>/*1055:0*/ __Vtemp_h65420e98__0;
    VlWide<33>/*1055:0*/ __Vtemp_hcf0d6b7b__0;
    VlWide<33>/*1055:0*/ __Vtemp_he95f0a0a__0;
    VlWide<33>/*1055:0*/ __Vtemp_h1bc3ccb5__0;
    VlWide<33>/*1055:0*/ __Vtemp_hfb66acfe__0;
    VlWide<9>/*287:0*/ __Vtemp_h82623b09__0;
    VlWide<33>/*1055:0*/ __Vtemp_he7180a8b__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9dd30ecc__1;
    VlWide<33>/*1055:0*/ __Vtemp_hdccc2f4a__0;
    VlWide<33>/*1055:0*/ __Vtemp_hc02ad7c1__0;
    VlWide<33>/*1055:0*/ __Vtemp_he95f0a0a__1;
    VlWide<33>/*1055:0*/ __Vtemp_he4c1bc1e__0;
    VlWide<33>/*1055:0*/ __Vtemp_h0da585df__0;
    // Body
    __Vtemp_hc961d23f__0[0U] = 1U;
    __Vtemp_hc961d23f__0[1U] = 0U;
    __Vtemp_hc961d23f__0[2U] = 0U;
    __Vtemp_hc961d23f__0[3U] = 0U;
    VL_EXTEND_WI(128,7, __Vtemp_h9a9a6856__0, (0x7fU 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 0xaU)));
    VL_SHIFTL_WWW(128,128,128, __Vtemp_hca162495__0, __Vtemp_hc961d23f__0, __Vtemp_h9a9a6856__0);
    __Vtemp_hc961d23f__1[0U] = 1U;
    __Vtemp_hc961d23f__1[1U] = 0U;
    __Vtemp_hc961d23f__1[2U] = 0U;
    __Vtemp_hc961d23f__1[3U] = 0U;
    VL_EXTEND_WI(128,7, __Vtemp_h42b5cca9__0, (0x7fU 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 8U)));
    VL_SHIFTL_WWW(128,128,128, __Vtemp_h20a81ffc__0, __Vtemp_hc961d23f__1, __Vtemp_h42b5cca9__0);
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset) {
        __Vtemp_he70fd588__0[1U] = 0U;
        __Vtemp_he70fd588__0[2U] = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight[0U] = 0U;
    } else {
        __Vtemp_he70fd588__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight[1U] 
                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                                         ? __Vtemp_hca162495__0[1U]
                                         : 0U)) & (~ 
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1199)
                                                     ? 
                                                    __Vtemp_h20a81ffc__0[1U]
                                                     : 0U)));
        __Vtemp_he70fd588__0[2U] = (1U & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight[2U] 
                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                                               ? __Vtemp_hca162495__0[2U]
                                               : 0U)) 
                                          & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1199)
                                                 ? 
                                                __Vtemp_h20a81ffc__0[2U]
                                                 : 0U))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight[0U] 
            = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight[0U] 
                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1184)
                    ? __Vtemp_hca162495__0[0U] : 0U)) 
               & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1199)
                      ? __Vtemp_h20a81ffc__0[0U] : 0U)));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight[1U] 
        = __Vtemp_he70fd588__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__inflight[2U] 
        = __Vtemp_he70fd588__0[2U];
    VL_EXTEND_WI(1028,5, __Vtemp_hc06f2ff0__0, ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                                 ? 
                                                (1U 
                                                 | (0x1eU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 5U)))
                                                 : 0U));
    VL_EXTEND_WI(1025,7, __Vtemp_h9dd30ecc__0, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)));
    __Vtemp_h65420e98__0[0U] = (__Vtemp_h9dd30ecc__0[0U] 
                                << 3U);
    __Vtemp_h65420e98__0[1U] = ((__Vtemp_h9dd30ecc__0[0U] 
                                 >> 0x1dU) | (__Vtemp_h9dd30ecc__0[1U] 
                                              << 3U));
    __Vtemp_h65420e98__0[2U] = ((__Vtemp_h9dd30ecc__0[1U] 
                                 >> 0x1dU) | (__Vtemp_h9dd30ecc__0[2U] 
                                              << 3U));
    __Vtemp_h65420e98__0[3U] = ((__Vtemp_h9dd30ecc__0[2U] 
                                 >> 0x1dU) | (__Vtemp_h9dd30ecc__0[3U] 
                                              << 3U));
    __Vtemp_h65420e98__0[4U] = ((__Vtemp_h9dd30ecc__0[3U] 
                                 >> 0x1dU) | (__Vtemp_h9dd30ecc__0[4U] 
                                              << 3U));
    __Vtemp_h65420e98__0[5U] = ((__Vtemp_h9dd30ecc__0[4U] 
                                 >> 0x1dU) | (__Vtemp_h9dd30ecc__0[5U] 
                                              << 3U));
    __Vtemp_h65420e98__0[6U] = ((__Vtemp_h9dd30ecc__0[5U] 
                                 >> 0x1dU) | (__Vtemp_h9dd30ecc__0[6U] 
                                              << 3U));
    __Vtemp_h65420e98__0[7U] = ((__Vtemp_h9dd30ecc__0[6U] 
                                 >> 0x1dU) | (__Vtemp_h9dd30ecc__0[7U] 
                                              << 3U));
    __Vtemp_h65420e98__0[8U] = ((__Vtemp_h9dd30ecc__0[7U] 
                                 >> 0x1dU) | (__Vtemp_h9dd30ecc__0[8U] 
                                              << 3U));
    __Vtemp_h65420e98__0[9U] = ((__Vtemp_h9dd30ecc__0[8U] 
                                 >> 0x1dU) | (__Vtemp_h9dd30ecc__0[9U] 
                                              << 3U));
    __Vtemp_h65420e98__0[0xaU] = ((__Vtemp_h9dd30ecc__0[9U] 
                                   >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0xaU] 
                                                << 3U));
    __Vtemp_h65420e98__0[0xbU] = ((__Vtemp_h9dd30ecc__0[0xaU] 
                                   >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0xbU] 
                                                << 3U));
    __Vtemp_h65420e98__0[0xcU] = ((__Vtemp_h9dd30ecc__0[0xbU] 
                                   >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0xcU] 
                                                << 3U));
    __Vtemp_h65420e98__0[0xdU] = ((__Vtemp_h9dd30ecc__0[0xcU] 
                                   >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0xdU] 
                                                << 3U));
    __Vtemp_h65420e98__0[0xeU] = ((__Vtemp_h9dd30ecc__0[0xdU] 
                                   >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0xeU] 
                                                << 3U));
    __Vtemp_h65420e98__0[0xfU] = ((__Vtemp_h9dd30ecc__0[0xeU] 
                                   >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0xfU] 
                                                << 3U));
    __Vtemp_h65420e98__0[0x10U] = ((__Vtemp_h9dd30ecc__0[0xfU] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0x10U] 
                                                 << 3U));
    __Vtemp_h65420e98__0[0x11U] = ((__Vtemp_h9dd30ecc__0[0x10U] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0x11U] 
                                                 << 3U));
    __Vtemp_h65420e98__0[0x12U] = ((__Vtemp_h9dd30ecc__0[0x11U] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0x12U] 
                                                 << 3U));
    __Vtemp_h65420e98__0[0x13U] = ((__Vtemp_h9dd30ecc__0[0x12U] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0x13U] 
                                                 << 3U));
    __Vtemp_h65420e98__0[0x14U] = ((__Vtemp_h9dd30ecc__0[0x13U] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0x14U] 
                                                 << 3U));
    __Vtemp_h65420e98__0[0x15U] = ((__Vtemp_h9dd30ecc__0[0x14U] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0x15U] 
                                                 << 3U));
    __Vtemp_h65420e98__0[0x16U] = ((__Vtemp_h9dd30ecc__0[0x15U] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0x16U] 
                                                 << 3U));
    __Vtemp_h65420e98__0[0x17U] = ((__Vtemp_h9dd30ecc__0[0x16U] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0x17U] 
                                                 << 3U));
    __Vtemp_h65420e98__0[0x18U] = ((__Vtemp_h9dd30ecc__0[0x17U] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0x18U] 
                                                 << 3U));
    __Vtemp_h65420e98__0[0x19U] = ((__Vtemp_h9dd30ecc__0[0x18U] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0x19U] 
                                                 << 3U));
    __Vtemp_h65420e98__0[0x1aU] = ((__Vtemp_h9dd30ecc__0[0x19U] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0x1aU] 
                                                 << 3U));
    __Vtemp_h65420e98__0[0x1bU] = ((__Vtemp_h9dd30ecc__0[0x1aU] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0x1bU] 
                                                 << 3U));
    __Vtemp_h65420e98__0[0x1cU] = ((__Vtemp_h9dd30ecc__0[0x1bU] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0x1cU] 
                                                 << 3U));
    __Vtemp_h65420e98__0[0x1dU] = ((__Vtemp_h9dd30ecc__0[0x1cU] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0x1dU] 
                                                 << 3U));
    __Vtemp_h65420e98__0[0x1eU] = ((__Vtemp_h9dd30ecc__0[0x1dU] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0x1eU] 
                                                 << 3U));
    __Vtemp_h65420e98__0[0x1fU] = ((__Vtemp_h9dd30ecc__0[0x1eU] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0x1fU] 
                                                 << 3U));
    __Vtemp_h65420e98__0[0x20U] = ((__Vtemp_h9dd30ecc__0[0x1fU] 
                                    >> 0x1dU) | (__Vtemp_h9dd30ecc__0[0x20U] 
                                                 << 3U));
    VL_SHIFTL_WWW(1028,1028,1028, __Vtemp_hcf0d6b7b__0, __Vtemp_hc06f2ff0__0, __Vtemp_h65420e98__0);
    VL_EXTEND_WI(1036,7, __Vtemp_he95f0a0a__0, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 9U)));
    __Vtemp_h1bc3ccb5__0[0U] = (__Vtemp_he95f0a0a__0[0U] 
                                << 3U);
    __Vtemp_h1bc3ccb5__0[1U] = ((__Vtemp_he95f0a0a__0[0U] 
                                 >> 0x1dU) | (__Vtemp_he95f0a0a__0[1U] 
                                              << 3U));
    __Vtemp_h1bc3ccb5__0[2U] = ((__Vtemp_he95f0a0a__0[1U] 
                                 >> 0x1dU) | (__Vtemp_he95f0a0a__0[2U] 
                                              << 3U));
    __Vtemp_h1bc3ccb5__0[3U] = ((__Vtemp_he95f0a0a__0[2U] 
                                 >> 0x1dU) | (__Vtemp_he95f0a0a__0[3U] 
                                              << 3U));
    __Vtemp_h1bc3ccb5__0[4U] = ((__Vtemp_he95f0a0a__0[3U] 
                                 >> 0x1dU) | (__Vtemp_he95f0a0a__0[4U] 
                                              << 3U));
    __Vtemp_h1bc3ccb5__0[5U] = ((__Vtemp_he95f0a0a__0[4U] 
                                 >> 0x1dU) | (__Vtemp_he95f0a0a__0[5U] 
                                              << 3U));
    __Vtemp_h1bc3ccb5__0[6U] = ((__Vtemp_he95f0a0a__0[5U] 
                                 >> 0x1dU) | (__Vtemp_he95f0a0a__0[6U] 
                                              << 3U));
    __Vtemp_h1bc3ccb5__0[7U] = ((__Vtemp_he95f0a0a__0[6U] 
                                 >> 0x1dU) | (__Vtemp_he95f0a0a__0[7U] 
                                              << 3U));
    __Vtemp_h1bc3ccb5__0[8U] = ((__Vtemp_he95f0a0a__0[7U] 
                                 >> 0x1dU) | (__Vtemp_he95f0a0a__0[8U] 
                                              << 3U));
    __Vtemp_h1bc3ccb5__0[9U] = ((__Vtemp_he95f0a0a__0[8U] 
                                 >> 0x1dU) | (__Vtemp_he95f0a0a__0[9U] 
                                              << 3U));
    __Vtemp_h1bc3ccb5__0[0xaU] = ((__Vtemp_he95f0a0a__0[9U] 
                                   >> 0x1dU) | (__Vtemp_he95f0a0a__0[0xaU] 
                                                << 3U));
    __Vtemp_h1bc3ccb5__0[0xbU] = ((__Vtemp_he95f0a0a__0[0xaU] 
                                   >> 0x1dU) | (__Vtemp_he95f0a0a__0[0xbU] 
                                                << 3U));
    __Vtemp_h1bc3ccb5__0[0xcU] = ((__Vtemp_he95f0a0a__0[0xbU] 
                                   >> 0x1dU) | (__Vtemp_he95f0a0a__0[0xcU] 
                                                << 3U));
    __Vtemp_h1bc3ccb5__0[0xdU] = ((__Vtemp_he95f0a0a__0[0xcU] 
                                   >> 0x1dU) | (__Vtemp_he95f0a0a__0[0xdU] 
                                                << 3U));
    __Vtemp_h1bc3ccb5__0[0xeU] = ((__Vtemp_he95f0a0a__0[0xdU] 
                                   >> 0x1dU) | (__Vtemp_he95f0a0a__0[0xeU] 
                                                << 3U));
    __Vtemp_h1bc3ccb5__0[0xfU] = ((__Vtemp_he95f0a0a__0[0xeU] 
                                   >> 0x1dU) | (__Vtemp_he95f0a0a__0[0xfU] 
                                                << 3U));
    __Vtemp_h1bc3ccb5__0[0x10U] = ((__Vtemp_he95f0a0a__0[0xfU] 
                                    >> 0x1dU) | (__Vtemp_he95f0a0a__0[0x10U] 
                                                 << 3U));
    __Vtemp_h1bc3ccb5__0[0x11U] = ((__Vtemp_he95f0a0a__0[0x10U] 
                                    >> 0x1dU) | (__Vtemp_he95f0a0a__0[0x11U] 
                                                 << 3U));
    __Vtemp_h1bc3ccb5__0[0x12U] = ((__Vtemp_he95f0a0a__0[0x11U] 
                                    >> 0x1dU) | (__Vtemp_he95f0a0a__0[0x12U] 
                                                 << 3U));
    __Vtemp_h1bc3ccb5__0[0x13U] = ((__Vtemp_he95f0a0a__0[0x12U] 
                                    >> 0x1dU) | (__Vtemp_he95f0a0a__0[0x13U] 
                                                 << 3U));
    __Vtemp_h1bc3ccb5__0[0x14U] = ((__Vtemp_he95f0a0a__0[0x13U] 
                                    >> 0x1dU) | (__Vtemp_he95f0a0a__0[0x14U] 
                                                 << 3U));
    __Vtemp_h1bc3ccb5__0[0x15U] = ((__Vtemp_he95f0a0a__0[0x14U] 
                                    >> 0x1dU) | (__Vtemp_he95f0a0a__0[0x15U] 
                                                 << 3U));
    __Vtemp_h1bc3ccb5__0[0x16U] = ((__Vtemp_he95f0a0a__0[0x15U] 
                                    >> 0x1dU) | (__Vtemp_he95f0a0a__0[0x16U] 
                                                 << 3U));
    __Vtemp_h1bc3ccb5__0[0x17U] = ((__Vtemp_he95f0a0a__0[0x16U] 
                                    >> 0x1dU) | (__Vtemp_he95f0a0a__0[0x17U] 
                                                 << 3U));
    __Vtemp_h1bc3ccb5__0[0x18U] = ((__Vtemp_he95f0a0a__0[0x17U] 
                                    >> 0x1dU) | (__Vtemp_he95f0a0a__0[0x18U] 
                                                 << 3U));
    __Vtemp_h1bc3ccb5__0[0x19U] = ((__Vtemp_he95f0a0a__0[0x18U] 
                                    >> 0x1dU) | (__Vtemp_he95f0a0a__0[0x19U] 
                                                 << 3U));
    __Vtemp_h1bc3ccb5__0[0x1aU] = ((__Vtemp_he95f0a0a__0[0x19U] 
                                    >> 0x1dU) | (__Vtemp_he95f0a0a__0[0x1aU] 
                                                 << 3U));
    __Vtemp_h1bc3ccb5__0[0x1bU] = ((__Vtemp_he95f0a0a__0[0x1aU] 
                                    >> 0x1dU) | (__Vtemp_he95f0a0a__0[0x1bU] 
                                                 << 3U));
    __Vtemp_h1bc3ccb5__0[0x1cU] = ((__Vtemp_he95f0a0a__0[0x1bU] 
                                    >> 0x1dU) | (__Vtemp_he95f0a0a__0[0x1cU] 
                                                 << 3U));
    __Vtemp_h1bc3ccb5__0[0x1dU] = ((__Vtemp_he95f0a0a__0[0x1cU] 
                                    >> 0x1dU) | (__Vtemp_he95f0a0a__0[0x1dU] 
                                                 << 3U));
    __Vtemp_h1bc3ccb5__0[0x1eU] = ((__Vtemp_he95f0a0a__0[0x1dU] 
                                    >> 0x1dU) | (__Vtemp_he95f0a0a__0[0x1eU] 
                                                 << 3U));
    __Vtemp_h1bc3ccb5__0[0x1fU] = ((__Vtemp_he95f0a0a__0[0x1eU] 
                                    >> 0x1dU) | (__Vtemp_he95f0a0a__0[0x1fU] 
                                                 << 3U));
    __Vtemp_h1bc3ccb5__0[0x20U] = ((__Vtemp_he95f0a0a__0[0x1fU] 
                                    >> 0x1dU) | (__Vtemp_he95f0a0a__0[0x20U] 
                                                 << 3U));
    VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_hfb66acfe__0, VTestHarness__ConstPool__CONST_h81905067_0, __Vtemp_h1bc3ccb5__0);
    __Vtemp_h0947b9cb__0[1U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[1U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[1U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[1U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[1U] 
                                               & __Vtemp_hcf0d6b7b__0[1U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[1U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[1U] 
                                                 & __Vtemp_hfb66acfe__0[1U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[1U])))));
    __Vtemp_h0947b9cb__0[2U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[2U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[2U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[2U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[2U] 
                                               & __Vtemp_hcf0d6b7b__0[2U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[2U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[2U] 
                                                 & __Vtemp_hfb66acfe__0[2U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[2U])))));
    __Vtemp_h0947b9cb__0[3U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[3U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[3U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[3U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[3U] 
                                               & __Vtemp_hcf0d6b7b__0[3U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[3U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[3U] 
                                                 & __Vtemp_hfb66acfe__0[3U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[3U])))));
    __Vtemp_h0947b9cb__0[4U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[4U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[4U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[4U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[4U] 
                                               & __Vtemp_hcf0d6b7b__0[4U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[4U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[4U] 
                                                 & __Vtemp_hfb66acfe__0[4U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[4U])))));
    __Vtemp_h0947b9cb__0[5U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[5U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[5U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[5U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[5U] 
                                               & __Vtemp_hcf0d6b7b__0[5U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[5U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[5U] 
                                                 & __Vtemp_hfb66acfe__0[5U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[5U])))));
    __Vtemp_h0947b9cb__0[6U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[6U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[6U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[6U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[6U] 
                                               & __Vtemp_hcf0d6b7b__0[6U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[6U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[6U] 
                                                 & __Vtemp_hfb66acfe__0[6U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[6U])))));
    __Vtemp_h0947b9cb__0[7U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[7U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[7U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[7U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[7U] 
                                               & __Vtemp_hcf0d6b7b__0[7U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[7U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[7U] 
                                                 & __Vtemp_hfb66acfe__0[7U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[7U])))));
    __Vtemp_h0947b9cb__0[8U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[8U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[8U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[8U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[8U] 
                                               & __Vtemp_hcf0d6b7b__0[8U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[8U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[8U] 
                                                 & __Vtemp_hfb66acfe__0[8U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[8U])))));
    __Vtemp_h0947b9cb__0[9U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[9U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[9U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[9U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[9U] 
                                               & __Vtemp_hcf0d6b7b__0[9U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[9U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[9U] 
                                                 & __Vtemp_hfb66acfe__0[9U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[9U])))));
    __Vtemp_h0947b9cb__0[0xaU] = (VTestHarness__ConstPool__CONST_h00a540f1_0[0xaU] 
                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                      ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0xaU]
                                      : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xaU] 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                              ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0xaU] 
                                                 & __Vtemp_hcf0d6b7b__0[0xaU])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xaU])) 
                                         & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                                ? (
                                                   VTestHarness__ConstPool__CONST_hf1d81c7e_0[0xaU] 
                                                   & __Vtemp_hfb66acfe__0[0xaU])
                                                : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xaU])))));
    __Vtemp_h0947b9cb__0[0xbU] = (VTestHarness__ConstPool__CONST_h00a540f1_0[0xbU] 
                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                      ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0xbU]
                                      : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xbU] 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                              ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0xbU] 
                                                 & __Vtemp_hcf0d6b7b__0[0xbU])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xbU])) 
                                         & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                                ? (
                                                   VTestHarness__ConstPool__CONST_hf1d81c7e_0[0xbU] 
                                                   & __Vtemp_hfb66acfe__0[0xbU])
                                                : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xbU])))));
    __Vtemp_h0947b9cb__0[0xcU] = (VTestHarness__ConstPool__CONST_h00a540f1_0[0xcU] 
                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                      ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0xcU]
                                      : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xcU] 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                              ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0xcU] 
                                                 & __Vtemp_hcf0d6b7b__0[0xcU])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xcU])) 
                                         & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                                ? (
                                                   VTestHarness__ConstPool__CONST_hf1d81c7e_0[0xcU] 
                                                   & __Vtemp_hfb66acfe__0[0xcU])
                                                : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xcU])))));
    __Vtemp_h0947b9cb__0[0xdU] = (VTestHarness__ConstPool__CONST_h00a540f1_0[0xdU] 
                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                      ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0xdU]
                                      : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xdU] 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                              ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0xdU] 
                                                 & __Vtemp_hcf0d6b7b__0[0xdU])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xdU])) 
                                         & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                                ? (
                                                   VTestHarness__ConstPool__CONST_hf1d81c7e_0[0xdU] 
                                                   & __Vtemp_hfb66acfe__0[0xdU])
                                                : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xdU])))));
    __Vtemp_h0947b9cb__0[0xeU] = (VTestHarness__ConstPool__CONST_h00a540f1_0[0xeU] 
                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                      ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0xeU]
                                      : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xeU] 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                              ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0xeU] 
                                                 & __Vtemp_hcf0d6b7b__0[0xeU])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xeU])) 
                                         & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                                ? (
                                                   VTestHarness__ConstPool__CONST_hf1d81c7e_0[0xeU] 
                                                   & __Vtemp_hfb66acfe__0[0xeU])
                                                : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xeU])))));
    __Vtemp_h0947b9cb__0[0xfU] = (VTestHarness__ConstPool__CONST_h00a540f1_0[0xfU] 
                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                      ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0xfU]
                                      : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xfU] 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                              ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0xfU] 
                                                 & __Vtemp_hcf0d6b7b__0[0xfU])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xfU])) 
                                         & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                                ? (
                                                   VTestHarness__ConstPool__CONST_hf1d81c7e_0[0xfU] 
                                                   & __Vtemp_hfb66acfe__0[0xfU])
                                                : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xfU])))));
    __Vtemp_h0947b9cb__0[0x10U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[0x10U] 
                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                       ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0x10U]
                                       : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0x10U] 
                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                               ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0x10U] 
                                                  & __Vtemp_hcf0d6b7b__0[0x10U])
                                               : VTestHarness__ConstPool__CONST_h881bc0c4_0[0x10U])) 
                                          & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                                 ? 
                                                (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0x10U] 
                                                 & __Vtemp_hfb66acfe__0[0x10U])
                                                 : 
                                                VTestHarness__ConstPool__CONST_h881bc0c4_0[0x10U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0U] 
        = (VTestHarness__ConstPool__CONST_h00a540f1_0[0U] 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
               ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0U]
               : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0U] 
                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                       ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0U] 
                          & __Vtemp_hcf0d6b7b__0[0U])
                       : VTestHarness__ConstPool__CONST_h881bc0c4_0[0U])) 
                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                         ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0U] 
                            & __Vtemp_hfb66acfe__0[0U])
                         : VTestHarness__ConstPool__CONST_h881bc0c4_0[0U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[1U] 
        = __Vtemp_h0947b9cb__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[2U] 
        = __Vtemp_h0947b9cb__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[3U] 
        = __Vtemp_h0947b9cb__0[3U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[4U] 
        = __Vtemp_h0947b9cb__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[5U] 
        = __Vtemp_h0947b9cb__0[5U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[6U] 
        = __Vtemp_h0947b9cb__0[6U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[7U] 
        = __Vtemp_h0947b9cb__0[7U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[8U] 
        = __Vtemp_h0947b9cb__0[8U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[9U] 
        = __Vtemp_h0947b9cb__0[9U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xaU] 
        = __Vtemp_h0947b9cb__0[0xaU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xbU] 
        = __Vtemp_h0947b9cb__0[0xbU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xcU] 
        = __Vtemp_h0947b9cb__0[0xcU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xdU] 
        = __Vtemp_h0947b9cb__0[0xdU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xeU] 
        = __Vtemp_h0947b9cb__0[0xeU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xfU] 
        = __Vtemp_h0947b9cb__0[0xfU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0x10U] 
        = __Vtemp_h0947b9cb__0[0x10U];
    VL_EXTEND_WI(1027,4, __Vtemp_he7180a8b__0, ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                                 ? 
                                                (1U 
                                                 | (0xeU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       << 1U)))
                                                 : 0U));
    VL_EXTEND_WI(1025,7, __Vtemp_h9dd30ecc__1, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)));
    __Vtemp_hdccc2f4a__0[0U] = (__Vtemp_h9dd30ecc__1[0U] 
                                << 2U);
    __Vtemp_hdccc2f4a__0[1U] = ((__Vtemp_h9dd30ecc__1[0U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[1U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[2U] = ((__Vtemp_h9dd30ecc__1[1U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[2U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[3U] = ((__Vtemp_h9dd30ecc__1[2U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[3U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[4U] = ((__Vtemp_h9dd30ecc__1[3U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[4U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[5U] = ((__Vtemp_h9dd30ecc__1[4U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[5U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[6U] = ((__Vtemp_h9dd30ecc__1[5U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[6U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[7U] = ((__Vtemp_h9dd30ecc__1[6U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[7U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[8U] = ((__Vtemp_h9dd30ecc__1[7U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[8U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[9U] = ((__Vtemp_h9dd30ecc__1[8U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[9U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[0xaU] = ((__Vtemp_h9dd30ecc__1[9U] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xaU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xbU] = ((__Vtemp_h9dd30ecc__1[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xbU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xcU] = ((__Vtemp_h9dd30ecc__1[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xcU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xdU] = ((__Vtemp_h9dd30ecc__1[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xdU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xeU] = ((__Vtemp_h9dd30ecc__1[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xeU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xfU] = ((__Vtemp_h9dd30ecc__1[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xfU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0x10U] = ((__Vtemp_h9dd30ecc__1[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x10U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x11U] = ((__Vtemp_h9dd30ecc__1[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x11U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x12U] = ((__Vtemp_h9dd30ecc__1[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x12U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x13U] = ((__Vtemp_h9dd30ecc__1[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x13U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x14U] = ((__Vtemp_h9dd30ecc__1[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x14U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x15U] = ((__Vtemp_h9dd30ecc__1[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x15U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x16U] = ((__Vtemp_h9dd30ecc__1[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x16U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x17U] = ((__Vtemp_h9dd30ecc__1[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x17U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x18U] = ((__Vtemp_h9dd30ecc__1[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x18U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x19U] = ((__Vtemp_h9dd30ecc__1[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x19U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1aU] = ((__Vtemp_h9dd30ecc__1[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1aU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1bU] = ((__Vtemp_h9dd30ecc__1[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1bU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1cU] = ((__Vtemp_h9dd30ecc__1[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1cU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1dU] = ((__Vtemp_h9dd30ecc__1[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1dU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1eU] = ((__Vtemp_h9dd30ecc__1[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1eU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1fU] = ((__Vtemp_h9dd30ecc__1[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1fU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x20U] = ((__Vtemp_h9dd30ecc__1[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1027,1027,1027, __Vtemp_hc02ad7c1__0, __Vtemp_he7180a8b__0, __Vtemp_hdccc2f4a__0);
    VL_EXTEND_WI(1037,7, __Vtemp_he95f0a0a__1, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 9U)));
    __Vtemp_he4c1bc1e__0[0U] = (__Vtemp_he95f0a0a__1[0U] 
                                << 2U);
    __Vtemp_he4c1bc1e__0[1U] = ((__Vtemp_he95f0a0a__1[0U] 
                                 >> 0x1eU) | (__Vtemp_he95f0a0a__1[1U] 
                                              << 2U));
    __Vtemp_he4c1bc1e__0[2U] = ((__Vtemp_he95f0a0a__1[1U] 
                                 >> 0x1eU) | (__Vtemp_he95f0a0a__1[2U] 
                                              << 2U));
    __Vtemp_he4c1bc1e__0[3U] = ((__Vtemp_he95f0a0a__1[2U] 
                                 >> 0x1eU) | (__Vtemp_he95f0a0a__1[3U] 
                                              << 2U));
    __Vtemp_he4c1bc1e__0[4U] = ((__Vtemp_he95f0a0a__1[3U] 
                                 >> 0x1eU) | (__Vtemp_he95f0a0a__1[4U] 
                                              << 2U));
    __Vtemp_he4c1bc1e__0[5U] = ((__Vtemp_he95f0a0a__1[4U] 
                                 >> 0x1eU) | (__Vtemp_he95f0a0a__1[5U] 
                                              << 2U));
    __Vtemp_he4c1bc1e__0[6U] = ((__Vtemp_he95f0a0a__1[5U] 
                                 >> 0x1eU) | (__Vtemp_he95f0a0a__1[6U] 
                                              << 2U));
    __Vtemp_he4c1bc1e__0[7U] = ((__Vtemp_he95f0a0a__1[6U] 
                                 >> 0x1eU) | (__Vtemp_he95f0a0a__1[7U] 
                                              << 2U));
    __Vtemp_he4c1bc1e__0[8U] = ((__Vtemp_he95f0a0a__1[7U] 
                                 >> 0x1eU) | (__Vtemp_he95f0a0a__1[8U] 
                                              << 2U));
    __Vtemp_he4c1bc1e__0[9U] = ((__Vtemp_he95f0a0a__1[8U] 
                                 >> 0x1eU) | (__Vtemp_he95f0a0a__1[9U] 
                                              << 2U));
    __Vtemp_he4c1bc1e__0[0xaU] = ((__Vtemp_he95f0a0a__1[9U] 
                                   >> 0x1eU) | (__Vtemp_he95f0a0a__1[0xaU] 
                                                << 2U));
    __Vtemp_he4c1bc1e__0[0xbU] = ((__Vtemp_he95f0a0a__1[0xaU] 
                                   >> 0x1eU) | (__Vtemp_he95f0a0a__1[0xbU] 
                                                << 2U));
    __Vtemp_he4c1bc1e__0[0xcU] = ((__Vtemp_he95f0a0a__1[0xbU] 
                                   >> 0x1eU) | (__Vtemp_he95f0a0a__1[0xcU] 
                                                << 2U));
    __Vtemp_he4c1bc1e__0[0xdU] = ((__Vtemp_he95f0a0a__1[0xcU] 
                                   >> 0x1eU) | (__Vtemp_he95f0a0a__1[0xdU] 
                                                << 2U));
    __Vtemp_he4c1bc1e__0[0xeU] = ((__Vtemp_he95f0a0a__1[0xdU] 
                                   >> 0x1eU) | (__Vtemp_he95f0a0a__1[0xeU] 
                                                << 2U));
    __Vtemp_he4c1bc1e__0[0xfU] = ((__Vtemp_he95f0a0a__1[0xeU] 
                                   >> 0x1eU) | (__Vtemp_he95f0a0a__1[0xfU] 
                                                << 2U));
    __Vtemp_he4c1bc1e__0[0x10U] = ((__Vtemp_he95f0a0a__1[0xfU] 
                                    >> 0x1eU) | (__Vtemp_he95f0a0a__1[0x10U] 
                                                 << 2U));
    __Vtemp_he4c1bc1e__0[0x11U] = ((__Vtemp_he95f0a0a__1[0x10U] 
                                    >> 0x1eU) | (__Vtemp_he95f0a0a__1[0x11U] 
                                                 << 2U));
    __Vtemp_he4c1bc1e__0[0x12U] = ((__Vtemp_he95f0a0a__1[0x11U] 
                                    >> 0x1eU) | (__Vtemp_he95f0a0a__1[0x12U] 
                                                 << 2U));
    __Vtemp_he4c1bc1e__0[0x13U] = ((__Vtemp_he95f0a0a__1[0x12U] 
                                    >> 0x1eU) | (__Vtemp_he95f0a0a__1[0x13U] 
                                                 << 2U));
    __Vtemp_he4c1bc1e__0[0x14U] = ((__Vtemp_he95f0a0a__1[0x13U] 
                                    >> 0x1eU) | (__Vtemp_he95f0a0a__1[0x14U] 
                                                 << 2U));
    __Vtemp_he4c1bc1e__0[0x15U] = ((__Vtemp_he95f0a0a__1[0x14U] 
                                    >> 0x1eU) | (__Vtemp_he95f0a0a__1[0x15U] 
                                                 << 2U));
    __Vtemp_he4c1bc1e__0[0x16U] = ((__Vtemp_he95f0a0a__1[0x15U] 
                                    >> 0x1eU) | (__Vtemp_he95f0a0a__1[0x16U] 
                                                 << 2U));
    __Vtemp_he4c1bc1e__0[0x17U] = ((__Vtemp_he95f0a0a__1[0x16U] 
                                    >> 0x1eU) | (__Vtemp_he95f0a0a__1[0x17U] 
                                                 << 2U));
    __Vtemp_he4c1bc1e__0[0x18U] = ((__Vtemp_he95f0a0a__1[0x17U] 
                                    >> 0x1eU) | (__Vtemp_he95f0a0a__1[0x18U] 
                                                 << 2U));
    __Vtemp_he4c1bc1e__0[0x19U] = ((__Vtemp_he95f0a0a__1[0x18U] 
                                    >> 0x1eU) | (__Vtemp_he95f0a0a__1[0x19U] 
                                                 << 2U));
    __Vtemp_he4c1bc1e__0[0x1aU] = ((__Vtemp_he95f0a0a__1[0x19U] 
                                    >> 0x1eU) | (__Vtemp_he95f0a0a__1[0x1aU] 
                                                 << 2U));
    __Vtemp_he4c1bc1e__0[0x1bU] = ((__Vtemp_he95f0a0a__1[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_he95f0a0a__1[0x1bU] 
                                                 << 2U));
    __Vtemp_he4c1bc1e__0[0x1cU] = ((__Vtemp_he95f0a0a__1[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_he95f0a0a__1[0x1cU] 
                                                 << 2U));
    __Vtemp_he4c1bc1e__0[0x1dU] = ((__Vtemp_he95f0a0a__1[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_he95f0a0a__1[0x1dU] 
                                                 << 2U));
    __Vtemp_he4c1bc1e__0[0x1eU] = ((__Vtemp_he95f0a0a__1[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_he95f0a0a__1[0x1eU] 
                                                 << 2U));
    __Vtemp_he4c1bc1e__0[0x1fU] = ((__Vtemp_he95f0a0a__1[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_he95f0a0a__1[0x1fU] 
                                                 << 2U));
    __Vtemp_he4c1bc1e__0[0x20U] = ((__Vtemp_he95f0a0a__1[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_he95f0a0a__1[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_h0da585df__0, VTestHarness__ConstPool__CONST_h3892cc72_0, __Vtemp_he4c1bc1e__0);
    __Vtemp_h82623b09__0[1U] = (VTestHarness__ConstPool__CONST_h52851b57_0[1U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[1U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[1U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[1U] 
                                               & __Vtemp_hc02ad7c1__0[1U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[1U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[1U] 
                                                 & __Vtemp_h0da585df__0[1U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[1U])))));
    __Vtemp_h82623b09__0[2U] = (VTestHarness__ConstPool__CONST_h52851b57_0[2U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[2U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[2U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[2U] 
                                               & __Vtemp_hc02ad7c1__0[2U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[2U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[2U] 
                                                 & __Vtemp_h0da585df__0[2U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[2U])))));
    __Vtemp_h82623b09__0[3U] = (VTestHarness__ConstPool__CONST_h52851b57_0[3U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[3U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[3U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[3U] 
                                               & __Vtemp_hc02ad7c1__0[3U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[3U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[3U] 
                                                 & __Vtemp_h0da585df__0[3U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[3U])))));
    __Vtemp_h82623b09__0[4U] = (VTestHarness__ConstPool__CONST_h52851b57_0[4U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[4U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[4U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[4U] 
                                               & __Vtemp_hc02ad7c1__0[4U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[4U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[4U] 
                                                 & __Vtemp_h0da585df__0[4U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[4U])))));
    __Vtemp_h82623b09__0[5U] = (VTestHarness__ConstPool__CONST_h52851b57_0[5U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[5U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[5U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[5U] 
                                               & __Vtemp_hc02ad7c1__0[5U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[5U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[5U] 
                                                 & __Vtemp_h0da585df__0[5U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[5U])))));
    __Vtemp_h82623b09__0[6U] = (VTestHarness__ConstPool__CONST_h52851b57_0[6U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[6U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[6U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[6U] 
                                               & __Vtemp_hc02ad7c1__0[6U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[6U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[6U] 
                                                 & __Vtemp_h0da585df__0[6U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[6U])))));
    __Vtemp_h82623b09__0[7U] = (VTestHarness__ConstPool__CONST_h52851b57_0[7U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[7U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[7U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[7U] 
                                               & __Vtemp_hc02ad7c1__0[7U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[7U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[7U] 
                                                 & __Vtemp_h0da585df__0[7U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[7U])))));
    __Vtemp_h82623b09__0[8U] = (VTestHarness__ConstPool__CONST_h52851b57_0[8U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[8U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[8U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[8U] 
                                               & __Vtemp_hc02ad7c1__0[8U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[8U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[8U] 
                                                 & __Vtemp_h0da585df__0[8U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[8U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[0U] 
        = (VTestHarness__ConstPool__CONST_h52851b57_0[0U] 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
               ? VTestHarness__ConstPool__CONST_h478702bb_0[0U]
               : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[0U] 
                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1127)
                       ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[0U] 
                          & __Vtemp_hc02ad7c1__0[0U])
                       : VTestHarness__ConstPool__CONST_h478702bb_0[0U])) 
                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1142)
                         ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0U] 
                            & __Vtemp_h0da585df__0[0U])
                         : VTestHarness__ConstPool__CONST_h478702bb_0[0U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[1U] 
        = __Vtemp_h82623b09__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[2U] 
        = __Vtemp_h82623b09__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[3U] 
        = __Vtemp_h82623b09__0[3U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[4U] 
        = __Vtemp_h82623b09__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[5U] 
        = __Vtemp_h82623b09__0[5U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[6U] 
        = __Vtemp_h82623b09__0[6U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[7U] 
        = __Vtemp_h82623b09__0[7U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[8U] 
        = __Vtemp_h82623b09__0[8U];
}
