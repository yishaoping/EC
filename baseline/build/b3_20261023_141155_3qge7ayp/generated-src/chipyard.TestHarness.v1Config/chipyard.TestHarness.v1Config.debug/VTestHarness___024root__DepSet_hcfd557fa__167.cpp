// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTestHarness.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTestHarness___024root.h"

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__18956(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__18956\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_ha18635c8__0;
    VlWide<3>/*95:0*/ __Vtemp_h23449f50__0;
    VlWide<20>/*639:0*/ __Vtemp_h68606771__0;
    // Body
    __Vtemp_ha18635c8__0[0U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_20_ctrl_imm_sel)) 
                                         << 0x3cU) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_19_ctrl_imm_sel)) 
                                            << 0x39U) 
                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_18_ctrl_imm_sel)) 
                                               << 0x36U) 
                                              | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_17_ctrl_imm_sel)) 
                                                  << 0x33U) 
                                                 | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_16_ctrl_imm_sel)) 
                                                     << 0x30U) 
                                                    | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_15_ctrl_imm_sel)) 
                                                        << 0x2dU) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_14_ctrl_imm_sel)) 
                                                           << 0x2aU) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_13_ctrl_imm_sel)) 
                                                              << 0x27U) 
                                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_12_ctrl_imm_sel)) 
                                                                 << 0x24U) 
                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_11_ctrl_imm_sel)) 
                                                                    << 0x21U) 
                                                                   | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_10_ctrl_imm_sel)) 
                                                                       << 0x1eU) 
                                                                      | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_9_ctrl_imm_sel) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_8_ctrl_imm_sel) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_7_ctrl_imm_sel) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_6_ctrl_imm_sel) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_5_ctrl_imm_sel) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_4_ctrl_imm_sel) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_3_ctrl_imm_sel) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_ctrl_imm_sel) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_ctrl_imm_sel) 
                                                                                << 3U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_0_ctrl_imm_sel))))))))))))))))))))))));
    __Vtemp_ha18635c8__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_21_ctrl_imm_sel) 
                                 << 0x1fU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_20_ctrl_imm_sel)) 
                                                        << 0x3cU) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_19_ctrl_imm_sel)) 
                                                           << 0x39U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_18_ctrl_imm_sel)) 
                                                              << 0x36U) 
                                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_17_ctrl_imm_sel)) 
                                                                 << 0x33U) 
                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_16_ctrl_imm_sel)) 
                                                                    << 0x30U) 
                                                                   | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_15_ctrl_imm_sel)) 
                                                                       << 0x2dU) 
                                                                      | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_14_ctrl_imm_sel)) 
                                                                          << 0x2aU) 
                                                                         | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_13_ctrl_imm_sel)) 
                                                                             << 0x27U) 
                                                                            | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_12_ctrl_imm_sel)) 
                                                                                << 0x24U) 
                                                                               | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_11_ctrl_imm_sel)) 
                                                                                << 0x21U) 
                                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_10_ctrl_imm_sel)) 
                                                                                << 0x1eU) 
                                                                                | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_9_ctrl_imm_sel) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_8_ctrl_imm_sel) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_7_ctrl_imm_sel) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_6_ctrl_imm_sel) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_5_ctrl_imm_sel) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_4_ctrl_imm_sel) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_3_ctrl_imm_sel) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_ctrl_imm_sel) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_ctrl_imm_sel) 
                                                                                << 3U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_0_ctrl_imm_sel))))))))))))))))))))))) 
                                                      >> 0x20U)));
    __Vtemp_h23449f50__0[0U] = __Vtemp_ha18635c8__0[0U];
    __Vtemp_h23449f50__0[1U] = __Vtemp_ha18635c8__0[1U];
    __Vtemp_h23449f50__0[2U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_31_ctrl_imm_sel) 
                                 << 0x1dU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_30_ctrl_imm_sel) 
                                               << 0x1aU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_29_ctrl_imm_sel) 
                                                  << 0x17U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_28_ctrl_imm_sel) 
                                                     << 0x14U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_27_ctrl_imm_sel) 
                                                        << 0x11U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_26_ctrl_imm_sel) 
                                                           << 0xeU) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_25_ctrl_imm_sel) 
                                                              << 0xbU) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_24_ctrl_imm_sel) 
                                                                 << 8U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_23_ctrl_imm_sel) 
                                                                    << 5U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_22_ctrl_imm_sel) 
                                                                       << 2U) 
                                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_21_ctrl_imm_sel) 
                                                                         >> 1U)))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_0_ctrl_imm_sel_output 
        = ((0x5fU >= (0x7fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
            ? (7U & (((0U == (0x1fU & ((IData)(3U) 
                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
                       ? 0U : (__Vtemp_h23449f50__0[
                               (((IData)(2U) + (0x7fU 
                                                & ((IData)(3U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))) 
                                >> 5U)] << ((IData)(0x20U) 
                                            - (0x1fU 
                                               & ((IData)(3U) 
                                                  * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))))) 
                     | (__Vtemp_h23449f50__0[(3U & 
                                              (((IData)(3U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)) 
                                               >> 5U))] 
                        >> (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))))
            : 0U);
    __Vtemp_h68606771__0[0U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_imm_packed)) 
                                         << 0x28U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_imm_packed)) 
                                            << 0x14U) 
                                           | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_0_imm_packed)))));
    __Vtemp_h68606771__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_3_imm_packed 
                                 << 0x1cU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_imm_packed)) 
                                                        << 0x28U) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_imm_packed)) 
                                                           << 0x14U) 
                                                          | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_0_imm_packed)))) 
                                                      >> 0x20U)));
    __Vtemp_h68606771__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_4_imm_packed 
                                 << 0x10U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_3_imm_packed 
                                              >> 4U));
    __Vtemp_h68606771__0[3U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_6_imm_packed 
                                 << 0x18U) | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_5_imm_packed 
                                               << 4U) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_4_imm_packed 
                                                 >> 0x10U)));
    __Vtemp_h68606771__0[4U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_7_imm_packed 
                                 << 0xcU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_6_imm_packed 
                                             >> 8U));
    __Vtemp_h68606771__0[5U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_10_imm_packed)) 
                                         << 0x28U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_9_imm_packed)) 
                                            << 0x14U) 
                                           | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_8_imm_packed)))));
    __Vtemp_h68606771__0[6U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_11_imm_packed 
                                 << 0x1cU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_10_imm_packed)) 
                                                        << 0x28U) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_9_imm_packed)) 
                                                           << 0x14U) 
                                                          | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_8_imm_packed)))) 
                                                      >> 0x20U)));
    __Vtemp_h68606771__0[7U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_12_imm_packed 
                                 << 0x10U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_11_imm_packed 
                                              >> 4U));
    __Vtemp_h68606771__0[8U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_14_imm_packed 
                                 << 0x18U) | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_13_imm_packed 
                                               << 4U) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_12_imm_packed 
                                                 >> 0x10U)));
    __Vtemp_h68606771__0[9U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_15_imm_packed 
                                 << 0xcU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_14_imm_packed 
                                             >> 8U));
    __Vtemp_h68606771__0[0xaU] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_18_imm_packed)) 
                                           << 0x28U) 
                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_17_imm_packed)) 
                                              << 0x14U) 
                                             | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_16_imm_packed)))));
    __Vtemp_h68606771__0[0xbU] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_19_imm_packed 
                                   << 0x1cU) | (IData)(
                                                       ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_18_imm_packed)) 
                                                          << 0x28U) 
                                                         | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_17_imm_packed)) 
                                                             << 0x14U) 
                                                            | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_16_imm_packed)))) 
                                                        >> 0x20U)));
    __Vtemp_h68606771__0[0xcU] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_20_imm_packed 
                                   << 0x10U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_19_imm_packed 
                                                >> 4U));
    __Vtemp_h68606771__0[0xdU] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_22_imm_packed 
                                   << 0x18U) | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_21_imm_packed 
                                                 << 4U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_20_imm_packed 
                                                   >> 0x10U)));
    __Vtemp_h68606771__0[0xeU] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_23_imm_packed 
                                   << 0xcU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_22_imm_packed 
                                               >> 8U));
    __Vtemp_h68606771__0[0xfU] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_26_imm_packed)) 
                                           << 0x28U) 
                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_25_imm_packed)) 
                                              << 0x14U) 
                                             | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_24_imm_packed)))));
    __Vtemp_h68606771__0[0x10U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_27_imm_packed 
                                    << 0x1cU) | (IData)(
                                                        ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_26_imm_packed)) 
                                                           << 0x28U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_25_imm_packed)) 
                                                              << 0x14U) 
                                                             | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_24_imm_packed)))) 
                                                         >> 0x20U)));
    __Vtemp_h68606771__0[0x11U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_28_imm_packed 
                                    << 0x10U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_27_imm_packed 
                                                 >> 4U));
    __Vtemp_h68606771__0[0x12U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_30_imm_packed 
                                    << 0x18U) | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_29_imm_packed 
                                                  << 4U) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_28_imm_packed 
                                                    >> 0x10U)));
    __Vtemp_h68606771__0[0x13U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_31_imm_packed 
                                    << 0xcU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_30_imm_packed 
                                                >> 8U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_0_imm_packed_output 
        = ((0x27fU >= (0x3ffU & ((IData)(0x14U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
            ? (0xfffffU & (((0U == (0x1fU & ((IData)(0x14U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
                             ? 0U : (__Vtemp_h68606771__0[
                                     (((IData)(0x13U) 
                                       + (0x3ffU & 
                                          ((IData)(0x14U) 
                                           * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))) 
                                      >> 5U)] << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(0x14U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))))) 
                           | (__Vtemp_h68606771__0[
                              (0x1fU & (((IData)(0x14U) 
                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)) 
                                        >> 5U))] >> 
                              (0x1fU & ((IData)(0x14U) 
                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))))
            : 0U);
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__18957(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__18957\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h9be6196a__0;
    VlWide<3>/*95:0*/ __Vtemp_hf359d73f__0;
    VlWide<20>/*639:0*/ __Vtemp_h2331a88b__0;
    // Body
    __Vtemp_h9be6196a__0[0U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_20_ctrl_imm_sel)) 
                                         << 0x3cU) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_19_ctrl_imm_sel)) 
                                            << 0x39U) 
                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_18_ctrl_imm_sel)) 
                                               << 0x36U) 
                                              | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_17_ctrl_imm_sel)) 
                                                  << 0x33U) 
                                                 | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_16_ctrl_imm_sel)) 
                                                     << 0x30U) 
                                                    | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_15_ctrl_imm_sel)) 
                                                        << 0x2dU) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_14_ctrl_imm_sel)) 
                                                           << 0x2aU) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_13_ctrl_imm_sel)) 
                                                              << 0x27U) 
                                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_12_ctrl_imm_sel)) 
                                                                 << 0x24U) 
                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_11_ctrl_imm_sel)) 
                                                                    << 0x21U) 
                                                                   | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_10_ctrl_imm_sel)) 
                                                                       << 0x1eU) 
                                                                      | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_9_ctrl_imm_sel) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_8_ctrl_imm_sel) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_7_ctrl_imm_sel) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_6_ctrl_imm_sel) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_5_ctrl_imm_sel) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_4_ctrl_imm_sel) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_3_ctrl_imm_sel) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_2_ctrl_imm_sel) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_1_ctrl_imm_sel) 
                                                                                << 3U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_0_ctrl_imm_sel))))))))))))))))))))))));
    __Vtemp_h9be6196a__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_21_ctrl_imm_sel) 
                                 << 0x1fU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_20_ctrl_imm_sel)) 
                                                        << 0x3cU) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_19_ctrl_imm_sel)) 
                                                           << 0x39U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_18_ctrl_imm_sel)) 
                                                              << 0x36U) 
                                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_17_ctrl_imm_sel)) 
                                                                 << 0x33U) 
                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_16_ctrl_imm_sel)) 
                                                                    << 0x30U) 
                                                                   | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_15_ctrl_imm_sel)) 
                                                                       << 0x2dU) 
                                                                      | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_14_ctrl_imm_sel)) 
                                                                          << 0x2aU) 
                                                                         | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_13_ctrl_imm_sel)) 
                                                                             << 0x27U) 
                                                                            | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_12_ctrl_imm_sel)) 
                                                                                << 0x24U) 
                                                                               | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_11_ctrl_imm_sel)) 
                                                                                << 0x21U) 
                                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_10_ctrl_imm_sel)) 
                                                                                << 0x1eU) 
                                                                                | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_9_ctrl_imm_sel) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_8_ctrl_imm_sel) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_7_ctrl_imm_sel) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_6_ctrl_imm_sel) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_5_ctrl_imm_sel) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_4_ctrl_imm_sel) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_3_ctrl_imm_sel) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_2_ctrl_imm_sel) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_1_ctrl_imm_sel) 
                                                                                << 3U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_0_ctrl_imm_sel))))))))))))))))))))))) 
                                                      >> 0x20U)));
    __Vtemp_hf359d73f__0[0U] = __Vtemp_h9be6196a__0[0U];
    __Vtemp_hf359d73f__0[1U] = __Vtemp_h9be6196a__0[1U];
    __Vtemp_hf359d73f__0[2U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_31_ctrl_imm_sel) 
                                 << 0x1dU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_30_ctrl_imm_sel) 
                                               << 0x1aU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_29_ctrl_imm_sel) 
                                                  << 0x17U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_28_ctrl_imm_sel) 
                                                     << 0x14U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_27_ctrl_imm_sel) 
                                                        << 0x11U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_26_ctrl_imm_sel) 
                                                           << 0xeU) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_25_ctrl_imm_sel) 
                                                              << 0xbU) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_24_ctrl_imm_sel) 
                                                                 << 8U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_23_ctrl_imm_sel) 
                                                                    << 5U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_22_ctrl_imm_sel) 
                                                                       << 2U) 
                                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_21_ctrl_imm_sel) 
                                                                         >> 1U)))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_1_ctrl_imm_sel_output 
        = ((0x5fU >= (0x7fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
            ? (7U & (((0U == (0x1fU & ((IData)(3U) 
                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
                       ? 0U : (__Vtemp_hf359d73f__0[
                               (((IData)(2U) + (0x7fU 
                                                & ((IData)(3U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))) 
                                >> 5U)] << ((IData)(0x20U) 
                                            - (0x1fU 
                                               & ((IData)(3U) 
                                                  * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))))) 
                     | (__Vtemp_hf359d73f__0[(3U & 
                                              (((IData)(3U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)) 
                                               >> 5U))] 
                        >> (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))))
            : 0U);
    __Vtemp_h2331a88b__0[0U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_2_imm_packed)) 
                                         << 0x28U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_1_imm_packed)) 
                                            << 0x14U) 
                                           | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_0_imm_packed)))));
    __Vtemp_h2331a88b__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_3_imm_packed 
                                 << 0x1cU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_2_imm_packed)) 
                                                        << 0x28U) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_1_imm_packed)) 
                                                           << 0x14U) 
                                                          | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_0_imm_packed)))) 
                                                      >> 0x20U)));
    __Vtemp_h2331a88b__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_4_imm_packed 
                                 << 0x10U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_3_imm_packed 
                                              >> 4U));
    __Vtemp_h2331a88b__0[3U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_6_imm_packed 
                                 << 0x18U) | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_5_imm_packed 
                                               << 4U) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_4_imm_packed 
                                                 >> 0x10U)));
    __Vtemp_h2331a88b__0[4U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_7_imm_packed 
                                 << 0xcU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_6_imm_packed 
                                             >> 8U));
    __Vtemp_h2331a88b__0[5U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_10_imm_packed)) 
                                         << 0x28U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_9_imm_packed)) 
                                            << 0x14U) 
                                           | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_8_imm_packed)))));
    __Vtemp_h2331a88b__0[6U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_11_imm_packed 
                                 << 0x1cU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_10_imm_packed)) 
                                                        << 0x28U) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_9_imm_packed)) 
                                                           << 0x14U) 
                                                          | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_8_imm_packed)))) 
                                                      >> 0x20U)));
    __Vtemp_h2331a88b__0[7U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_12_imm_packed 
                                 << 0x10U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_11_imm_packed 
                                              >> 4U));
    __Vtemp_h2331a88b__0[8U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_14_imm_packed 
                                 << 0x18U) | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_13_imm_packed 
                                               << 4U) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_12_imm_packed 
                                                 >> 0x10U)));
    __Vtemp_h2331a88b__0[9U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_15_imm_packed 
                                 << 0xcU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_14_imm_packed 
                                             >> 8U));
    __Vtemp_h2331a88b__0[0xaU] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_18_imm_packed)) 
                                           << 0x28U) 
                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_17_imm_packed)) 
                                              << 0x14U) 
                                             | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_16_imm_packed)))));
    __Vtemp_h2331a88b__0[0xbU] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_19_imm_packed 
                                   << 0x1cU) | (IData)(
                                                       ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_18_imm_packed)) 
                                                          << 0x28U) 
                                                         | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_17_imm_packed)) 
                                                             << 0x14U) 
                                                            | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_16_imm_packed)))) 
                                                        >> 0x20U)));
    __Vtemp_h2331a88b__0[0xcU] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_20_imm_packed 
                                   << 0x10U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_19_imm_packed 
                                                >> 4U));
    __Vtemp_h2331a88b__0[0xdU] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_22_imm_packed 
                                   << 0x18U) | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_21_imm_packed 
                                                 << 4U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_20_imm_packed 
                                                   >> 0x10U)));
    __Vtemp_h2331a88b__0[0xeU] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_23_imm_packed 
                                   << 0xcU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_22_imm_packed 
                                               >> 8U));
    __Vtemp_h2331a88b__0[0xfU] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_26_imm_packed)) 
                                           << 0x28U) 
                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_25_imm_packed)) 
                                              << 0x14U) 
                                             | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_24_imm_packed)))));
    __Vtemp_h2331a88b__0[0x10U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_27_imm_packed 
                                    << 0x1cU) | (IData)(
                                                        ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_26_imm_packed)) 
                                                           << 0x28U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_25_imm_packed)) 
                                                              << 0x14U) 
                                                             | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_24_imm_packed)))) 
                                                         >> 0x20U)));
    __Vtemp_h2331a88b__0[0x11U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_28_imm_packed 
                                    << 0x10U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_27_imm_packed 
                                                 >> 4U));
    __Vtemp_h2331a88b__0[0x12U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_30_imm_packed 
                                    << 0x18U) | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_29_imm_packed 
                                                  << 4U) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_28_imm_packed 
                                                    >> 0x10U)));
    __Vtemp_h2331a88b__0[0x13U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_31_imm_packed 
                                    << 0xcU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_30_imm_packed 
                                                >> 8U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_1_imm_packed_output 
        = ((0x27fU >= (0x3ffU & ((IData)(0x14U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
            ? (0xfffffU & (((0U == (0x1fU & ((IData)(0x14U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
                             ? 0U : (__Vtemp_h2331a88b__0[
                                     (((IData)(0x13U) 
                                       + (0x3ffU & 
                                          ((IData)(0x14U) 
                                           * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))) 
                                      >> 5U)] << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(0x14U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))))) 
                           | (__Vtemp_h2331a88b__0[
                              (0x1fU & (((IData)(0x14U) 
                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)) 
                                        >> 5U))] >> 
                              (0x1fU & ((IData)(0x14U) 
                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))))
            : 0U);
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__18958(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__18958\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_hf1a5b766__0;
    VlWide<3>/*95:0*/ __Vtemp_h112884b2__0;
    VlWide<20>/*639:0*/ __Vtemp_h10127d45__0;
    // Body
    __Vtemp_hf1a5b766__0[0U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_20_ctrl_imm_sel)) 
                                         << 0x3cU) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_19_ctrl_imm_sel)) 
                                            << 0x39U) 
                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_18_ctrl_imm_sel)) 
                                               << 0x36U) 
                                              | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_17_ctrl_imm_sel)) 
                                                  << 0x33U) 
                                                 | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_16_ctrl_imm_sel)) 
                                                     << 0x30U) 
                                                    | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_15_ctrl_imm_sel)) 
                                                        << 0x2dU) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_14_ctrl_imm_sel)) 
                                                           << 0x2aU) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_13_ctrl_imm_sel)) 
                                                              << 0x27U) 
                                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_12_ctrl_imm_sel)) 
                                                                 << 0x24U) 
                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_11_ctrl_imm_sel)) 
                                                                    << 0x21U) 
                                                                   | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_10_ctrl_imm_sel)) 
                                                                       << 0x1eU) 
                                                                      | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_9_ctrl_imm_sel) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_8_ctrl_imm_sel) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_7_ctrl_imm_sel) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_6_ctrl_imm_sel) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_5_ctrl_imm_sel) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_4_ctrl_imm_sel) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_3_ctrl_imm_sel) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_2_ctrl_imm_sel) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_1_ctrl_imm_sel) 
                                                                                << 3U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_0_ctrl_imm_sel))))))))))))))))))))))));
    __Vtemp_hf1a5b766__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_21_ctrl_imm_sel) 
                                 << 0x1fU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_20_ctrl_imm_sel)) 
                                                        << 0x3cU) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_19_ctrl_imm_sel)) 
                                                           << 0x39U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_18_ctrl_imm_sel)) 
                                                              << 0x36U) 
                                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_17_ctrl_imm_sel)) 
                                                                 << 0x33U) 
                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_16_ctrl_imm_sel)) 
                                                                    << 0x30U) 
                                                                   | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_15_ctrl_imm_sel)) 
                                                                       << 0x2dU) 
                                                                      | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_14_ctrl_imm_sel)) 
                                                                          << 0x2aU) 
                                                                         | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_13_ctrl_imm_sel)) 
                                                                             << 0x27U) 
                                                                            | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_12_ctrl_imm_sel)) 
                                                                                << 0x24U) 
                                                                               | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_11_ctrl_imm_sel)) 
                                                                                << 0x21U) 
                                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_10_ctrl_imm_sel)) 
                                                                                << 0x1eU) 
                                                                                | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_9_ctrl_imm_sel) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_8_ctrl_imm_sel) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_7_ctrl_imm_sel) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_6_ctrl_imm_sel) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_5_ctrl_imm_sel) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_4_ctrl_imm_sel) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_3_ctrl_imm_sel) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_2_ctrl_imm_sel) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_1_ctrl_imm_sel) 
                                                                                << 3U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_0_ctrl_imm_sel))))))))))))))))))))))) 
                                                      >> 0x20U)));
    __Vtemp_h112884b2__0[0U] = __Vtemp_hf1a5b766__0[0U];
    __Vtemp_h112884b2__0[1U] = __Vtemp_hf1a5b766__0[1U];
    __Vtemp_h112884b2__0[2U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_31_ctrl_imm_sel) 
                                 << 0x1dU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_30_ctrl_imm_sel) 
                                               << 0x1aU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_29_ctrl_imm_sel) 
                                                  << 0x17U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_28_ctrl_imm_sel) 
                                                     << 0x14U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_27_ctrl_imm_sel) 
                                                        << 0x11U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_26_ctrl_imm_sel) 
                                                           << 0xeU) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_25_ctrl_imm_sel) 
                                                              << 0xbU) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_24_ctrl_imm_sel) 
                                                                 << 8U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_23_ctrl_imm_sel) 
                                                                    << 5U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_22_ctrl_imm_sel) 
                                                                       << 2U) 
                                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_21_ctrl_imm_sel) 
                                                                         >> 1U)))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_2_ctrl_imm_sel_output 
        = ((0x5fU >= (0x7fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
            ? (7U & (((0U == (0x1fU & ((IData)(3U) 
                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
                       ? 0U : (__Vtemp_h112884b2__0[
                               (((IData)(2U) + (0x7fU 
                                                & ((IData)(3U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))) 
                                >> 5U)] << ((IData)(0x20U) 
                                            - (0x1fU 
                                               & ((IData)(3U) 
                                                  * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))))) 
                     | (__Vtemp_h112884b2__0[(3U & 
                                              (((IData)(3U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)) 
                                               >> 5U))] 
                        >> (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))))
            : 0U);
    __Vtemp_h10127d45__0[0U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_2_imm_packed)) 
                                         << 0x28U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_1_imm_packed)) 
                                            << 0x14U) 
                                           | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_0_imm_packed)))));
    __Vtemp_h10127d45__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_3_imm_packed 
                                 << 0x1cU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_2_imm_packed)) 
                                                        << 0x28U) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_1_imm_packed)) 
                                                           << 0x14U) 
                                                          | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_0_imm_packed)))) 
                                                      >> 0x20U)));
    __Vtemp_h10127d45__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_4_imm_packed 
                                 << 0x10U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_3_imm_packed 
                                              >> 4U));
    __Vtemp_h10127d45__0[3U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_6_imm_packed 
                                 << 0x18U) | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_5_imm_packed 
                                               << 4U) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_4_imm_packed 
                                                 >> 0x10U)));
    __Vtemp_h10127d45__0[4U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_7_imm_packed 
                                 << 0xcU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_6_imm_packed 
                                             >> 8U));
    __Vtemp_h10127d45__0[5U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_10_imm_packed)) 
                                         << 0x28U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_9_imm_packed)) 
                                            << 0x14U) 
                                           | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_8_imm_packed)))));
    __Vtemp_h10127d45__0[6U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_11_imm_packed 
                                 << 0x1cU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_10_imm_packed)) 
                                                        << 0x28U) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_9_imm_packed)) 
                                                           << 0x14U) 
                                                          | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_8_imm_packed)))) 
                                                      >> 0x20U)));
    __Vtemp_h10127d45__0[7U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_12_imm_packed 
                                 << 0x10U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_11_imm_packed 
                                              >> 4U));
    __Vtemp_h10127d45__0[8U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_14_imm_packed 
                                 << 0x18U) | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_13_imm_packed 
                                               << 4U) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_12_imm_packed 
                                                 >> 0x10U)));
    __Vtemp_h10127d45__0[9U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_15_imm_packed 
                                 << 0xcU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_14_imm_packed 
                                             >> 8U));
    __Vtemp_h10127d45__0[0xaU] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_18_imm_packed)) 
                                           << 0x28U) 
                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_17_imm_packed)) 
                                              << 0x14U) 
                                             | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_16_imm_packed)))));
    __Vtemp_h10127d45__0[0xbU] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_19_imm_packed 
                                   << 0x1cU) | (IData)(
                                                       ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_18_imm_packed)) 
                                                          << 0x28U) 
                                                         | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_17_imm_packed)) 
                                                             << 0x14U) 
                                                            | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_16_imm_packed)))) 
                                                        >> 0x20U)));
    __Vtemp_h10127d45__0[0xcU] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_20_imm_packed 
                                   << 0x10U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_19_imm_packed 
                                                >> 4U));
    __Vtemp_h10127d45__0[0xdU] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_22_imm_packed 
                                   << 0x18U) | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_21_imm_packed 
                                                 << 4U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_20_imm_packed 
                                                   >> 0x10U)));
    __Vtemp_h10127d45__0[0xeU] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_23_imm_packed 
                                   << 0xcU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_22_imm_packed 
                                               >> 8U));
    __Vtemp_h10127d45__0[0xfU] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_26_imm_packed)) 
                                           << 0x28U) 
                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_25_imm_packed)) 
                                              << 0x14U) 
                                             | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_24_imm_packed)))));
    __Vtemp_h10127d45__0[0x10U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_27_imm_packed 
                                    << 0x1cU) | (IData)(
                                                        ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_26_imm_packed)) 
                                                           << 0x28U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_25_imm_packed)) 
                                                              << 0x14U) 
                                                             | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_24_imm_packed)))) 
                                                         >> 0x20U)));
    __Vtemp_h10127d45__0[0x11U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_28_imm_packed 
                                    << 0x10U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_27_imm_packed 
                                                 >> 4U));
    __Vtemp_h10127d45__0[0x12U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_30_imm_packed 
                                    << 0x18U) | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_29_imm_packed 
                                                  << 4U) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_28_imm_packed 
                                                    >> 0x10U)));
    __Vtemp_h10127d45__0[0x13U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_31_imm_packed 
                                    << 0xcU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_30_imm_packed 
                                                >> 8U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_2_imm_packed_output 
        = ((0x27fU >= (0x3ffU & ((IData)(0x14U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
            ? (0xfffffU & (((0U == (0x1fU & ((IData)(0x14U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
                             ? 0U : (__Vtemp_h10127d45__0[
                                     (((IData)(0x13U) 
                                       + (0x3ffU & 
                                          ((IData)(0x14U) 
                                           * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))) 
                                      >> 5U)] << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(0x14U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))))) 
                           | (__Vtemp_h10127d45__0[
                              (0x1fU & (((IData)(0x14U) 
                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)) 
                                        >> 5U))] >> 
                              (0x1fU & ((IData)(0x14U) 
                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))))
            : 0U);
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__18959(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__18959\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_ldst_val 
        = (1U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_31_ldst_val) 
                   << 0x1fU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_30_ldst_val) 
                                 << 0x1eU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_29_ldst_val) 
                                               << 0x1dU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_28_ldst_val) 
                                                  << 0x1cU) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_27_ldst_val) 
                                                     << 0x1bU) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_26_ldst_val) 
                                                        << 0x1aU) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_25_ldst_val) 
                                                           << 0x19U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_24_ldst_val) 
                                                              << 0x18U) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_23_ldst_val) 
                                                                 << 0x17U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_22_ldst_val) 
                                                                    << 0x16U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_21_ldst_val) 
                                                                       << 0x15U) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_20_ldst_val) 
                                                                          << 0x14U) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_19_ldst_val) 
                                                                             << 0x13U) 
                                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_18_ldst_val) 
                                                                                << 0x12U) 
                                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_17_ldst_val) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_16_ldst_val) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_15_ldst_val) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_14_ldst_val) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_13_ldst_val) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_12_ldst_val) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_11_ldst_val) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_10_ldst_val) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_9_ldst_val) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_8_ldst_val) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_7_ldst_val) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_6_ldst_val) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_5_ldst_val) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_4_ldst_val) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_3_ldst_val) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_ldst_val) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_ldst_val) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_0_ldst_val)))))))))))))))))))))))))))))))) 
                 >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_ldst_val 
        = (1U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_31_ldst_val) 
                   << 0x1fU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_30_ldst_val) 
                                 << 0x1eU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_29_ldst_val) 
                                               << 0x1dU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_28_ldst_val) 
                                                  << 0x1cU) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_27_ldst_val) 
                                                     << 0x1bU) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_26_ldst_val) 
                                                        << 0x1aU) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_25_ldst_val) 
                                                           << 0x19U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_24_ldst_val) 
                                                              << 0x18U) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_23_ldst_val) 
                                                                 << 0x17U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_22_ldst_val) 
                                                                    << 0x16U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_21_ldst_val) 
                                                                       << 0x15U) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_20_ldst_val) 
                                                                          << 0x14U) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_19_ldst_val) 
                                                                             << 0x13U) 
                                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_18_ldst_val) 
                                                                                << 0x12U) 
                                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_17_ldst_val) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_16_ldst_val) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_15_ldst_val) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_14_ldst_val) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_13_ldst_val) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_12_ldst_val) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_11_ldst_val) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_10_ldst_val) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_9_ldst_val) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_8_ldst_val) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_7_ldst_val) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_6_ldst_val) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_5_ldst_val) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_4_ldst_val) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_3_ldst_val) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_2_ldst_val) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_1_ldst_val) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_0_ldst_val)))))))))))))))))))))))))))))))) 
                 >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__18960(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__18960\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_ldst_val 
        = (1U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_31_ldst_val) 
                   << 0x1fU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_30_ldst_val) 
                                 << 0x1eU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_29_ldst_val) 
                                               << 0x1dU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_28_ldst_val) 
                                                  << 0x1cU) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_27_ldst_val) 
                                                     << 0x1bU) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_26_ldst_val) 
                                                        << 0x1aU) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_25_ldst_val) 
                                                           << 0x19U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_24_ldst_val) 
                                                              << 0x18U) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_23_ldst_val) 
                                                                 << 0x17U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_22_ldst_val) 
                                                                    << 0x16U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_21_ldst_val) 
                                                                       << 0x15U) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_20_ldst_val) 
                                                                          << 0x14U) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_19_ldst_val) 
                                                                             << 0x13U) 
                                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_18_ldst_val) 
                                                                                << 0x12U) 
                                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_17_ldst_val) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_16_ldst_val) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_15_ldst_val) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_14_ldst_val) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_13_ldst_val) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_12_ldst_val) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_11_ldst_val) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_10_ldst_val) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_9_ldst_val) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_8_ldst_val) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_7_ldst_val) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_6_ldst_val) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_5_ldst_val) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_4_ldst_val) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_3_ldst_val) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_2_ldst_val) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_1_ldst_val) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_0_ldst_val)))))))))))))))))))))))))))))))) 
                 >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_dst_rtype 
        = (3U & (IData)(((((QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_31_dst_rtype) 
                                             << 0x1eU) 
                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_30_dst_rtype) 
                                                << 0x1cU) 
                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_29_dst_rtype) 
                                                   << 0x1aU) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_28_dst_rtype) 
                                                      << 0x18U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_27_dst_rtype) 
                                                         << 0x16U) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_26_dst_rtype) 
                                                            << 0x14U) 
                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_25_dst_rtype) 
                                                               << 0x12U) 
                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_24_dst_rtype) 
                                                                  << 0x10U) 
                                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_23_dst_rtype) 
                                                                     << 0xeU) 
                                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_22_dst_rtype) 
                                                                        << 0xcU) 
                                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_21_dst_rtype) 
                                                                           << 0xaU) 
                                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_20_dst_rtype) 
                                                                              << 8U) 
                                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_19_dst_rtype) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_18_dst_rtype) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_17_dst_rtype) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_16_dst_rtype)))))))))))))))))) 
                           << 0x20U) | (QData)((IData)(
                                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_15_dst_rtype) 
                                                         << 0x1eU) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_14_dst_rtype) 
                                                            << 0x1cU) 
                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_13_dst_rtype) 
                                                               << 0x1aU) 
                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_12_dst_rtype) 
                                                                  << 0x18U) 
                                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_11_dst_rtype) 
                                                                     << 0x16U) 
                                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_10_dst_rtype) 
                                                                        << 0x14U) 
                                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_9_dst_rtype) 
                                                                           << 0x12U) 
                                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_8_dst_rtype) 
                                                                              << 0x10U) 
                                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_7_dst_rtype) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_6_dst_rtype) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_5_dst_rtype) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_4_dst_rtype) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_3_dst_rtype) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_dst_rtype) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_dst_rtype) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_0_dst_rtype))))))))))))))))))) 
                         >> (0x3fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx) 
                                      << 1U)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__18961(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__18961\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_dst_rtype 
        = (3U & (IData)(((((QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_31_dst_rtype) 
                                             << 0x1eU) 
                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_30_dst_rtype) 
                                                << 0x1cU) 
                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_29_dst_rtype) 
                                                   << 0x1aU) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_28_dst_rtype) 
                                                      << 0x18U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_27_dst_rtype) 
                                                         << 0x16U) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_26_dst_rtype) 
                                                            << 0x14U) 
                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_25_dst_rtype) 
                                                               << 0x12U) 
                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_24_dst_rtype) 
                                                                  << 0x10U) 
                                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_23_dst_rtype) 
                                                                     << 0xeU) 
                                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_22_dst_rtype) 
                                                                        << 0xcU) 
                                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_21_dst_rtype) 
                                                                           << 0xaU) 
                                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_20_dst_rtype) 
                                                                              << 8U) 
                                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_19_dst_rtype) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_18_dst_rtype) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_17_dst_rtype) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_16_dst_rtype)))))))))))))))))) 
                           << 0x20U) | (QData)((IData)(
                                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_15_dst_rtype) 
                                                         << 0x1eU) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_14_dst_rtype) 
                                                            << 0x1cU) 
                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_13_dst_rtype) 
                                                               << 0x1aU) 
                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_12_dst_rtype) 
                                                                  << 0x18U) 
                                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_11_dst_rtype) 
                                                                     << 0x16U) 
                                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_10_dst_rtype) 
                                                                        << 0x14U) 
                                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_9_dst_rtype) 
                                                                           << 0x12U) 
                                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_8_dst_rtype) 
                                                                              << 0x10U) 
                                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_7_dst_rtype) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_6_dst_rtype) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_5_dst_rtype) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_4_dst_rtype) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_3_dst_rtype) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_2_dst_rtype) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_1_dst_rtype) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_0_dst_rtype))))))))))))))))))) 
                         >> (0x3fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx) 
                                      << 1U)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_dst_rtype 
        = (3U & (IData)(((((QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_31_dst_rtype) 
                                             << 0x1eU) 
                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_30_dst_rtype) 
                                                << 0x1cU) 
                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_29_dst_rtype) 
                                                   << 0x1aU) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_28_dst_rtype) 
                                                      << 0x18U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_27_dst_rtype) 
                                                         << 0x16U) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_26_dst_rtype) 
                                                            << 0x14U) 
                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_25_dst_rtype) 
                                                               << 0x12U) 
                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_24_dst_rtype) 
                                                                  << 0x10U) 
                                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_23_dst_rtype) 
                                                                     << 0xeU) 
                                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_22_dst_rtype) 
                                                                        << 0xcU) 
                                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_21_dst_rtype) 
                                                                           << 0xaU) 
                                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_20_dst_rtype) 
                                                                              << 8U) 
                                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_19_dst_rtype) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_18_dst_rtype) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_17_dst_rtype) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_16_dst_rtype)))))))))))))))))) 
                           << 0x20U) | (QData)((IData)(
                                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_15_dst_rtype) 
                                                         << 0x1eU) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_14_dst_rtype) 
                                                            << 0x1cU) 
                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_13_dst_rtype) 
                                                               << 0x1aU) 
                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_12_dst_rtype) 
                                                                  << 0x18U) 
                                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_11_dst_rtype) 
                                                                     << 0x16U) 
                                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_10_dst_rtype) 
                                                                        << 0x14U) 
                                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_9_dst_rtype) 
                                                                           << 0x12U) 
                                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_8_dst_rtype) 
                                                                              << 0x10U) 
                                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_7_dst_rtype) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_6_dst_rtype) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_5_dst_rtype) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_4_dst_rtype) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_3_dst_rtype) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_2_dst_rtype) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_1_dst_rtype) 
                                                                                << 2U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_0_dst_rtype))))))))))))))))))) 
                         >> (0x3fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx) 
                                      << 1U)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__18962(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__18962\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h6acd698f__0;
    VlWide<5>/*159:0*/ __Vtemp_hc047b040__0;
    VlWide<3>/*95:0*/ __Vtemp_h32a0785e__0;
    VlWide<5>/*159:0*/ __Vtemp_h11732b4a__0;
    // Body
    __Vtemp_h6acd698f__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_12_ftq_idx) 
                                 << 0x1cU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_11_ftq_idx)) 
                                                        << 0x37U) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_10_ftq_idx)) 
                                                           << 0x32U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_9_ftq_idx)) 
                                                              << 0x2dU) 
                                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_8_ftq_idx)) 
                                                                 << 0x28U) 
                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_7_ftq_idx)) 
                                                                    << 0x23U) 
                                                                   | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_6_ftq_idx)) 
                                                                       << 0x1eU) 
                                                                      | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_5_ftq_idx) 
                                                                                << 0x19U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_4_ftq_idx) 
                                                                                << 0x14U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_3_ftq_idx) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_ftq_idx) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_ftq_idx) 
                                                                                << 5U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_0_ftq_idx)))))))))))))) 
                                                      >> 0x20U)));
    __Vtemp_hc047b040__0[0U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_11_ftq_idx)) 
                                         << 0x37U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_10_ftq_idx)) 
                                            << 0x32U) 
                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_9_ftq_idx)) 
                                               << 0x2dU) 
                                              | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_8_ftq_idx)) 
                                                  << 0x28U) 
                                                 | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_7_ftq_idx)) 
                                                     << 0x23U) 
                                                    | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_6_ftq_idx)) 
                                                        << 0x1eU) 
                                                       | (QData)((IData)(
                                                                         (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_5_ftq_idx) 
                                                                           << 0x19U) 
                                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_4_ftq_idx) 
                                                                              << 0x14U) 
                                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_3_ftq_idx) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_ftq_idx) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_ftq_idx) 
                                                                                << 5U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_0_ftq_idx)))))))))))))));
    __Vtemp_hc047b040__0[1U] = __Vtemp_h6acd698f__0[1U];
    __Vtemp_hc047b040__0[2U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_19_ftq_idx) 
                                 << 0x1fU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_18_ftq_idx) 
                                               << 0x1aU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_17_ftq_idx) 
                                                  << 0x15U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_16_ftq_idx) 
                                                     << 0x10U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_15_ftq_idx) 
                                                        << 0xbU) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_14_ftq_idx) 
                                                           << 6U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_13_ftq_idx) 
                                                              << 1U) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_12_ftq_idx) 
                                                                >> 4U))))))));
    __Vtemp_hc047b040__0[3U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_25_ftq_idx) 
                                 << 0x1dU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_24_ftq_idx) 
                                               << 0x18U) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_23_ftq_idx) 
                                                  << 0x13U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_22_ftq_idx) 
                                                     << 0xeU) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_21_ftq_idx) 
                                                        << 9U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_20_ftq_idx) 
                                                           << 4U) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_19_ftq_idx) 
                                                             >> 1U)))))));
    __Vtemp_hc047b040__0[4U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_31_ftq_idx) 
                                 << 0x1bU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_30_ftq_idx) 
                                               << 0x16U) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_29_ftq_idx) 
                                                  << 0x11U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_28_ftq_idx) 
                                                     << 0xcU) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_27_ftq_idx) 
                                                        << 7U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_26_ftq_idx) 
                                                           << 2U) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_25_ftq_idx) 
                                                             >> 3U)))))));
    __Vtemp_h32a0785e__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_12_ftq_idx) 
                                 << 0x1cU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_11_ftq_idx)) 
                                                        << 0x37U) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_10_ftq_idx)) 
                                                           << 0x32U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_9_ftq_idx)) 
                                                              << 0x2dU) 
                                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_8_ftq_idx)) 
                                                                 << 0x28U) 
                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_7_ftq_idx)) 
                                                                    << 0x23U) 
                                                                   | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_6_ftq_idx)) 
                                                                       << 0x1eU) 
                                                                      | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_5_ftq_idx) 
                                                                                << 0x19U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_4_ftq_idx) 
                                                                                << 0x14U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_3_ftq_idx) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_2_ftq_idx) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_1_ftq_idx) 
                                                                                << 5U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_0_ftq_idx)))))))))))))) 
                                                      >> 0x20U)));
    __Vtemp_h11732b4a__0[0U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_11_ftq_idx)) 
                                         << 0x37U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_10_ftq_idx)) 
                                            << 0x32U) 
                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_9_ftq_idx)) 
                                               << 0x2dU) 
                                              | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_8_ftq_idx)) 
                                                  << 0x28U) 
                                                 | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_7_ftq_idx)) 
                                                     << 0x23U) 
                                                    | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_6_ftq_idx)) 
                                                        << 0x1eU) 
                                                       | (QData)((IData)(
                                                                         (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_5_ftq_idx) 
                                                                           << 0x19U) 
                                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_4_ftq_idx) 
                                                                              << 0x14U) 
                                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_3_ftq_idx) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_2_ftq_idx) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_1_ftq_idx) 
                                                                                << 5U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_0_ftq_idx)))))))))))))));
    __Vtemp_h11732b4a__0[1U] = __Vtemp_h32a0785e__0[1U];
    __Vtemp_h11732b4a__0[2U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_19_ftq_idx) 
                                 << 0x1fU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_18_ftq_idx) 
                                               << 0x1aU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_17_ftq_idx) 
                                                  << 0x15U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_16_ftq_idx) 
                                                     << 0x10U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_15_ftq_idx) 
                                                        << 0xbU) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_14_ftq_idx) 
                                                           << 6U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_13_ftq_idx) 
                                                              << 1U) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_12_ftq_idx) 
                                                                >> 4U))))))));
    __Vtemp_h11732b4a__0[3U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_25_ftq_idx) 
                                 << 0x1dU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_24_ftq_idx) 
                                               << 0x18U) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_23_ftq_idx) 
                                                  << 0x13U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_22_ftq_idx) 
                                                     << 0xeU) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_21_ftq_idx) 
                                                        << 9U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_20_ftq_idx) 
                                                           << 4U) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_19_ftq_idx) 
                                                             >> 1U)))))));
    __Vtemp_h11732b4a__0[4U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_31_ftq_idx) 
                                 << 0x1bU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_30_ftq_idx) 
                                               << 0x16U) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_29_ftq_idx) 
                                                  << 0x11U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_28_ftq_idx) 
                                                     << 0xcU) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_27_ftq_idx) 
                                                        << 7U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_26_ftq_idx) 
                                                           << 2U) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_25_ftq_idx) 
                                                             >> 3U)))))));
    if ((0x9fU >= (0xffU & ((IData)(5U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_0_ftq_idx_output 
            = (0x1fU & (((0U == (0x1fU & ((IData)(5U) 
                                          * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
                          ? 0U : (__Vtemp_hc047b040__0[
                                  (((IData)(4U) + (0xffU 
                                                   & ((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))) 
                                   >> 5U)] << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))))) 
                        | (__Vtemp_hc047b040__0[(7U 
                                                 & (((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)) 
                                                    >> 5U))] 
                           >> (0x1fU & ((IData)(5U) 
                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_1_ftq_idx_output 
            = (0x1fU & (((0U == (0x1fU & ((IData)(5U) 
                                          * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
                          ? 0U : (__Vtemp_h11732b4a__0[
                                  (((IData)(4U) + (0xffU 
                                                   & ((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))) 
                                   >> 5U)] << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))))) 
                        | (__Vtemp_h11732b4a__0[(7U 
                                                 & (((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)) 
                                                    >> 5U))] 
                           >> (0x1fU & ((IData)(5U) 
                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))));
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_0_ftq_idx_output = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_1_ftq_idx_output = 0U;
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__18963(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__18963\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h91fdef9f__0;
    VlWide<5>/*159:0*/ __Vtemp_h9f406569__0;
    VlWide<32>/*1023:0*/ __Vtemp_h6decaf5d__0;
    // Body
    __Vtemp_h91fdef9f__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_12_ftq_idx) 
                                 << 0x1cU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_11_ftq_idx)) 
                                                        << 0x37U) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_10_ftq_idx)) 
                                                           << 0x32U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_9_ftq_idx)) 
                                                              << 0x2dU) 
                                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_8_ftq_idx)) 
                                                                 << 0x28U) 
                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_7_ftq_idx)) 
                                                                    << 0x23U) 
                                                                   | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_6_ftq_idx)) 
                                                                       << 0x1eU) 
                                                                      | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_5_ftq_idx) 
                                                                                << 0x19U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_4_ftq_idx) 
                                                                                << 0x14U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_3_ftq_idx) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_2_ftq_idx) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_1_ftq_idx) 
                                                                                << 5U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_0_ftq_idx)))))))))))))) 
                                                      >> 0x20U)));
    __Vtemp_h9f406569__0[0U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_11_ftq_idx)) 
                                         << 0x37U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_10_ftq_idx)) 
                                            << 0x32U) 
                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_9_ftq_idx)) 
                                               << 0x2dU) 
                                              | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_8_ftq_idx)) 
                                                  << 0x28U) 
                                                 | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_7_ftq_idx)) 
                                                     << 0x23U) 
                                                    | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_6_ftq_idx)) 
                                                        << 0x1eU) 
                                                       | (QData)((IData)(
                                                                         (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_5_ftq_idx) 
                                                                           << 0x19U) 
                                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_4_ftq_idx) 
                                                                              << 0x14U) 
                                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_3_ftq_idx) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_2_ftq_idx) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_1_ftq_idx) 
                                                                                << 5U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_0_ftq_idx)))))))))))))));
    __Vtemp_h9f406569__0[1U] = __Vtemp_h91fdef9f__0[1U];
    __Vtemp_h9f406569__0[2U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_19_ftq_idx) 
                                 << 0x1fU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_18_ftq_idx) 
                                               << 0x1aU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_17_ftq_idx) 
                                                  << 0x15U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_16_ftq_idx) 
                                                     << 0x10U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_15_ftq_idx) 
                                                        << 0xbU) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_14_ftq_idx) 
                                                           << 6U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_13_ftq_idx) 
                                                              << 1U) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_12_ftq_idx) 
                                                                >> 4U))))))));
    __Vtemp_h9f406569__0[3U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_25_ftq_idx) 
                                 << 0x1dU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_24_ftq_idx) 
                                               << 0x18U) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_23_ftq_idx) 
                                                  << 0x13U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_22_ftq_idx) 
                                                     << 0xeU) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_21_ftq_idx) 
                                                        << 9U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_20_ftq_idx) 
                                                           << 4U) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_19_ftq_idx) 
                                                             >> 1U)))))));
    __Vtemp_h9f406569__0[4U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_31_ftq_idx) 
                                 << 0x1bU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_30_ftq_idx) 
                                               << 0x16U) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_29_ftq_idx) 
                                                  << 0x11U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_28_ftq_idx) 
                                                     << 0xcU) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_27_ftq_idx) 
                                                        << 7U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_26_ftq_idx) 
                                                           << 2U) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_25_ftq_idx) 
                                                             >> 3U)))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_2_ftq_idx_output 
        = ((0x9fU >= (0xffU & ((IData)(5U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
            ? (0x1fU & (((0U == (0x1fU & ((IData)(5U) 
                                          * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
                          ? 0U : (__Vtemp_h9f406569__0[
                                  (((IData)(4U) + (0xffU 
                                                   & ((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))) 
                                   >> 5U)] << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))))) 
                        | (__Vtemp_h9f406569__0[(7U 
                                                 & (((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)) 
                                                    >> 5U))] 
                           >> (0x1fU & ((IData)(5U) 
                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))))
            : 0U);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_2_uses_ldq_output 
        = (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_243 
                 >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)));
    __Vtemp_h6decaf5d__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_0_debug_inst;
    __Vtemp_h6decaf5d__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_debug_inst;
    __Vtemp_h6decaf5d__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_debug_inst;
    __Vtemp_h6decaf5d__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_3_debug_inst;
    __Vtemp_h6decaf5d__0[4U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_4_debug_inst;
    __Vtemp_h6decaf5d__0[5U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_5_debug_inst;
    __Vtemp_h6decaf5d__0[6U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_6_debug_inst;
    __Vtemp_h6decaf5d__0[7U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_7_debug_inst;
    __Vtemp_h6decaf5d__0[8U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_8_debug_inst;
    __Vtemp_h6decaf5d__0[9U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_9_debug_inst;
    __Vtemp_h6decaf5d__0[0xaU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_10_debug_inst;
    __Vtemp_h6decaf5d__0[0xbU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_11_debug_inst;
    __Vtemp_h6decaf5d__0[0xcU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_12_debug_inst;
    __Vtemp_h6decaf5d__0[0xdU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_13_debug_inst;
    __Vtemp_h6decaf5d__0[0xeU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_14_debug_inst;
    __Vtemp_h6decaf5d__0[0xfU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_15_debug_inst;
    __Vtemp_h6decaf5d__0[0x10U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_16_debug_inst;
    __Vtemp_h6decaf5d__0[0x11U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_17_debug_inst;
    __Vtemp_h6decaf5d__0[0x12U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_18_debug_inst;
    __Vtemp_h6decaf5d__0[0x13U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_19_debug_inst;
    __Vtemp_h6decaf5d__0[0x14U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_20_debug_inst;
    __Vtemp_h6decaf5d__0[0x15U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_21_debug_inst;
    __Vtemp_h6decaf5d__0[0x16U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_22_debug_inst;
    __Vtemp_h6decaf5d__0[0x17U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_23_debug_inst;
    __Vtemp_h6decaf5d__0[0x18U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_24_debug_inst;
    __Vtemp_h6decaf5d__0[0x19U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_25_debug_inst;
    __Vtemp_h6decaf5d__0[0x1aU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_26_debug_inst;
    __Vtemp_h6decaf5d__0[0x1bU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_27_debug_inst;
    __Vtemp_h6decaf5d__0[0x1cU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_28_debug_inst;
    __Vtemp_h6decaf5d__0[0x1dU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_29_debug_inst;
    __Vtemp_h6decaf5d__0[0x1eU] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_31_debug_inst)) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_30_debug_inst))));
    __Vtemp_h6decaf5d__0[0x1fU] = (IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_31_debug_inst)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_30_debug_inst))) 
                                           >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_debug_inst 
        = (((0U == (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx) 
                             << 5U))) ? 0U : (__Vtemp_h6decaf5d__0[
                                              (((IData)(0x1fU) 
                                                + (0x3ffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx) 
                                                      << 5U))) 
                                               >> 5U)] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx) 
                                                      << 5U))))) 
           | (__Vtemp_h6decaf5d__0[(0x1fU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))] 
              >> (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx) 
                           << 5U))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__18964(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__18964\n"); );
    // Init
    VlWide<32>/*1023:0*/ __Vtemp_h084280f9__0;
    VlWide<32>/*1023:0*/ __Vtemp_h9f50262d__0;
    // Body
    __Vtemp_h084280f9__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_0_debug_inst;
    __Vtemp_h084280f9__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_1_debug_inst;
    __Vtemp_h084280f9__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_2_debug_inst;
    __Vtemp_h084280f9__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_3_debug_inst;
    __Vtemp_h084280f9__0[4U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_4_debug_inst;
    __Vtemp_h084280f9__0[5U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_5_debug_inst;
    __Vtemp_h084280f9__0[6U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_6_debug_inst;
    __Vtemp_h084280f9__0[7U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_7_debug_inst;
    __Vtemp_h084280f9__0[8U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_8_debug_inst;
    __Vtemp_h084280f9__0[9U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_9_debug_inst;
    __Vtemp_h084280f9__0[0xaU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_10_debug_inst;
    __Vtemp_h084280f9__0[0xbU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_11_debug_inst;
    __Vtemp_h084280f9__0[0xcU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_12_debug_inst;
    __Vtemp_h084280f9__0[0xdU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_13_debug_inst;
    __Vtemp_h084280f9__0[0xeU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_14_debug_inst;
    __Vtemp_h084280f9__0[0xfU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_15_debug_inst;
    __Vtemp_h084280f9__0[0x10U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_16_debug_inst;
    __Vtemp_h084280f9__0[0x11U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_17_debug_inst;
    __Vtemp_h084280f9__0[0x12U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_18_debug_inst;
    __Vtemp_h084280f9__0[0x13U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_19_debug_inst;
    __Vtemp_h084280f9__0[0x14U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_20_debug_inst;
    __Vtemp_h084280f9__0[0x15U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_21_debug_inst;
    __Vtemp_h084280f9__0[0x16U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_22_debug_inst;
    __Vtemp_h084280f9__0[0x17U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_23_debug_inst;
    __Vtemp_h084280f9__0[0x18U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_24_debug_inst;
    __Vtemp_h084280f9__0[0x19U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_25_debug_inst;
    __Vtemp_h084280f9__0[0x1aU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_26_debug_inst;
    __Vtemp_h084280f9__0[0x1bU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_27_debug_inst;
    __Vtemp_h084280f9__0[0x1cU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_28_debug_inst;
    __Vtemp_h084280f9__0[0x1dU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_29_debug_inst;
    __Vtemp_h084280f9__0[0x1eU] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_31_debug_inst)) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_30_debug_inst))));
    __Vtemp_h084280f9__0[0x1fU] = (IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_31_debug_inst)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_30_debug_inst))) 
                                           >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_debug_inst 
        = (((0U == (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx) 
                             << 5U))) ? 0U : (__Vtemp_h084280f9__0[
                                              (((IData)(0x1fU) 
                                                + (0x3ffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx) 
                                                      << 5U))) 
                                               >> 5U)] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx) 
                                                      << 5U))))) 
           | (__Vtemp_h084280f9__0[(0x1fU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))] 
              >> (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx) 
                           << 5U))));
    __Vtemp_h9f50262d__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_0_debug_inst;
    __Vtemp_h9f50262d__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_1_debug_inst;
    __Vtemp_h9f50262d__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_2_debug_inst;
    __Vtemp_h9f50262d__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_3_debug_inst;
    __Vtemp_h9f50262d__0[4U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_4_debug_inst;
    __Vtemp_h9f50262d__0[5U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_5_debug_inst;
    __Vtemp_h9f50262d__0[6U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_6_debug_inst;
    __Vtemp_h9f50262d__0[7U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_7_debug_inst;
    __Vtemp_h9f50262d__0[8U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_8_debug_inst;
    __Vtemp_h9f50262d__0[9U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_9_debug_inst;
    __Vtemp_h9f50262d__0[0xaU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_10_debug_inst;
    __Vtemp_h9f50262d__0[0xbU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_11_debug_inst;
    __Vtemp_h9f50262d__0[0xcU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_12_debug_inst;
    __Vtemp_h9f50262d__0[0xdU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_13_debug_inst;
    __Vtemp_h9f50262d__0[0xeU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_14_debug_inst;
    __Vtemp_h9f50262d__0[0xfU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_15_debug_inst;
    __Vtemp_h9f50262d__0[0x10U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_16_debug_inst;
    __Vtemp_h9f50262d__0[0x11U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_17_debug_inst;
    __Vtemp_h9f50262d__0[0x12U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_18_debug_inst;
    __Vtemp_h9f50262d__0[0x13U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_19_debug_inst;
    __Vtemp_h9f50262d__0[0x14U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_20_debug_inst;
    __Vtemp_h9f50262d__0[0x15U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_21_debug_inst;
    __Vtemp_h9f50262d__0[0x16U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_22_debug_inst;
    __Vtemp_h9f50262d__0[0x17U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_23_debug_inst;
    __Vtemp_h9f50262d__0[0x18U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_24_debug_inst;
    __Vtemp_h9f50262d__0[0x19U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_25_debug_inst;
    __Vtemp_h9f50262d__0[0x1aU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_26_debug_inst;
    __Vtemp_h9f50262d__0[0x1bU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_27_debug_inst;
    __Vtemp_h9f50262d__0[0x1cU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_28_debug_inst;
    __Vtemp_h9f50262d__0[0x1dU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_29_debug_inst;
    __Vtemp_h9f50262d__0[0x1eU] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_31_debug_inst)) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_30_debug_inst))));
    __Vtemp_h9f50262d__0[0x1fU] = (IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_31_debug_inst)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_30_debug_inst))) 
                                           >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_debug_inst 
        = (((0U == (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx) 
                             << 5U))) ? 0U : (__Vtemp_h9f50262d__0[
                                              (((IData)(0x1fU) 
                                                + (0x3ffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx) 
                                                      << 5U))) 
                                               >> 5U)] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx) 
                                                      << 5U))))) 
           | (__Vtemp_h9f50262d__0[(0x1fU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))] 
              >> (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx) 
                           << 5U))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__18965(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__18965\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_2_uses_stq_output 
        = (1U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_31_uses_stq) 
                   << 0x1fU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_30_uses_stq) 
                                 << 0x1eU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_29_uses_stq) 
                                               << 0x1dU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_28_uses_stq) 
                                                  << 0x1cU) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_27_uses_stq) 
                                                     << 0x1bU) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_26_uses_stq) 
                                                        << 0x1aU) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_25_uses_stq) 
                                                           << 0x19U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_24_uses_stq) 
                                                              << 0x18U) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_23_uses_stq) 
                                                                 << 0x17U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_22_uses_stq) 
                                                                    << 0x16U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_21_uses_stq) 
                                                                       << 0x15U) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_20_uses_stq) 
                                                                          << 0x14U) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_19_uses_stq) 
                                                                             << 0x13U) 
                                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_18_uses_stq) 
                                                                                << 0x12U) 
                                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_17_uses_stq) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_16_uses_stq) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_15_uses_stq) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_14_uses_stq) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_13_uses_stq) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_12_uses_stq) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_11_uses_stq) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_10_uses_stq) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_9_uses_stq) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_8_uses_stq) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_7_uses_stq) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_6_uses_stq) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_5_uses_stq) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_4_uses_stq) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_3_uses_stq) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_2_uses_stq) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_1_uses_stq) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_0_uses_stq)))))))))))))))))))))))))))))))) 
                 >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_1_uses_ldq_output 
        = (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_154 
                 >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_1_uses_stq_output 
        = (1U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_31_uses_stq) 
                   << 0x1fU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_30_uses_stq) 
                                 << 0x1eU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_29_uses_stq) 
                                               << 0x1dU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_28_uses_stq) 
                                                  << 0x1cU) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_27_uses_stq) 
                                                     << 0x1bU) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_26_uses_stq) 
                                                        << 0x1aU) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_25_uses_stq) 
                                                           << 0x19U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_24_uses_stq) 
                                                              << 0x18U) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_23_uses_stq) 
                                                                 << 0x17U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_22_uses_stq) 
                                                                    << 0x16U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_21_uses_stq) 
                                                                       << 0x15U) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_20_uses_stq) 
                                                                          << 0x14U) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_19_uses_stq) 
                                                                             << 0x13U) 
                                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_18_uses_stq) 
                                                                                << 0x12U) 
                                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_17_uses_stq) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_16_uses_stq) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_15_uses_stq) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_14_uses_stq) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_13_uses_stq) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_12_uses_stq) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_11_uses_stq) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_10_uses_stq) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_9_uses_stq) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_8_uses_stq) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_7_uses_stq) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_6_uses_stq) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_5_uses_stq) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_4_uses_stq) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_3_uses_stq) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_2_uses_stq) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_1_uses_stq) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_0_uses_stq)))))))))))))))))))))))))))))))) 
                 >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__18966(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__18966\n"); );
    // Init
    VlWide<12>/*383:0*/ __Vtemp_h666ab677__0;
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_0_uses_ldq_output 
        = (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_65 
                 >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_0_uses_stq_output 
        = (1U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_31_uses_stq) 
                   << 0x1fU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_30_uses_stq) 
                                 << 0x1eU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_29_uses_stq) 
                                               << 0x1dU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_28_uses_stq) 
                                                  << 0x1cU) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_27_uses_stq) 
                                                     << 0x1bU) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_26_uses_stq) 
                                                        << 0x1aU) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_25_uses_stq) 
                                                           << 0x19U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_24_uses_stq) 
                                                              << 0x18U) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_23_uses_stq) 
                                                                 << 0x17U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_22_uses_stq) 
                                                                    << 0x16U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_21_uses_stq) 
                                                                       << 0x15U) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_20_uses_stq) 
                                                                          << 0x14U) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_19_uses_stq) 
                                                                             << 0x13U) 
                                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_18_uses_stq) 
                                                                                << 0x12U) 
                                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_17_uses_stq) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_16_uses_stq) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_15_uses_stq) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_14_uses_stq) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_13_uses_stq) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_12_uses_stq) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_11_uses_stq) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_10_uses_stq) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_9_uses_stq) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_8_uses_stq) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_7_uses_stq) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_6_uses_stq) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_5_uses_stq) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_4_uses_stq) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_3_uses_stq) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_uses_stq) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_uses_stq) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_0_uses_stq)))))))))))))))))))))))))))))))) 
                 >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)));
    __Vtemp_h666ab677__0[0U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_4_csr_addr)) 
                                         << 0x30U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_3_csr_addr)) 
                                            << 0x24U) 
                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_2_csr_addr)) 
                                               << 0x18U) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_1_csr_addr) 
                                                                  << 0xcU) 
                                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_0_csr_addr))))))));
    __Vtemp_h666ab677__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_5_csr_addr) 
                                 << 0x1cU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_4_csr_addr)) 
                                                        << 0x30U) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_3_csr_addr)) 
                                                           << 0x24U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_2_csr_addr)) 
                                                              << 0x18U) 
                                                             | (QData)((IData)(
                                                                               (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_1_csr_addr) 
                                                                                << 0xcU) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_0_csr_addr))))))) 
                                                      >> 0x20U)));
    __Vtemp_h666ab677__0[2U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_7_csr_addr) 
                                 << 0x14U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_6_csr_addr) 
                                               << 8U) 
                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_5_csr_addr) 
                                                 >> 4U)));
    __Vtemp_h666ab677__0[3U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_12_csr_addr)) 
                                         << 0x30U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_11_csr_addr)) 
                                            << 0x24U) 
                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_10_csr_addr)) 
                                               << 0x18U) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_9_csr_addr) 
                                                                  << 0xcU) 
                                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_8_csr_addr))))))));
    __Vtemp_h666ab677__0[4U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_13_csr_addr) 
                                 << 0x1cU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_12_csr_addr)) 
                                                        << 0x30U) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_11_csr_addr)) 
                                                           << 0x24U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_10_csr_addr)) 
                                                              << 0x18U) 
                                                             | (QData)((IData)(
                                                                               (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_9_csr_addr) 
                                                                                << 0xcU) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_8_csr_addr))))))) 
                                                      >> 0x20U)));
    __Vtemp_h666ab677__0[5U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_15_csr_addr) 
                                 << 0x14U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_14_csr_addr) 
                                               << 8U) 
                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_13_csr_addr) 
                                                 >> 4U)));
    __Vtemp_h666ab677__0[6U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_20_csr_addr)) 
                                         << 0x30U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_19_csr_addr)) 
                                            << 0x24U) 
                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_18_csr_addr)) 
                                               << 0x18U) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_17_csr_addr) 
                                                                  << 0xcU) 
                                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_16_csr_addr))))))));
    __Vtemp_h666ab677__0[7U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_21_csr_addr) 
                                 << 0x1cU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_20_csr_addr)) 
                                                        << 0x30U) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_19_csr_addr)) 
                                                           << 0x24U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_18_csr_addr)) 
                                                              << 0x18U) 
                                                             | (QData)((IData)(
                                                                               (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_17_csr_addr) 
                                                                                << 0xcU) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_16_csr_addr))))))) 
                                                      >> 0x20U)));
    __Vtemp_h666ab677__0[8U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_23_csr_addr) 
                                 << 0x14U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_22_csr_addr) 
                                               << 8U) 
                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_21_csr_addr) 
                                                 >> 4U)));
    __Vtemp_h666ab677__0[9U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_28_csr_addr)) 
                                         << 0x30U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_27_csr_addr)) 
                                            << 0x24U) 
                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_26_csr_addr)) 
                                               << 0x18U) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_25_csr_addr) 
                                                                  << 0xcU) 
                                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_24_csr_addr))))))));
    __Vtemp_h666ab677__0[0xaU] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_29_csr_addr) 
                                   << 0x1cU) | (IData)(
                                                       ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_28_csr_addr)) 
                                                          << 0x30U) 
                                                         | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_27_csr_addr)) 
                                                             << 0x24U) 
                                                            | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_26_csr_addr)) 
                                                                << 0x18U) 
                                                               | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_25_csr_addr) 
                                                                                << 0xcU) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_24_csr_addr))))))) 
                                                        >> 0x20U)));
    __Vtemp_h666ab677__0[0xbU] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_31_csr_addr) 
                                   << 0x14U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_30_csr_addr) 
                                                 << 8U) 
                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_29_csr_addr) 
                                                   >> 4U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_csr_addr 
        = ((0x17fU >= (0x1ffU & ((IData)(0xcU) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
            ? (0xfffU & (((0U == (0x1fU & ((IData)(0xcU) 
                                           * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
                           ? 0U : (__Vtemp_h666ab677__0[
                                   (((IData)(0xbU) 
                                     + (0x1ffU & ((IData)(0xcU) 
                                                  * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))) 
                                    >> 5U)] << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & ((IData)(0xcU) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))))) 
                         | (__Vtemp_h666ab677__0[(0xfU 
                                                  & (((IData)(0xcU) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)) 
                                                     >> 5U))] 
                            >> (0x1fU & ((IData)(0xcU) 
                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))))
            : 0U);
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__18967(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__18967\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_hf95fc64c__0;
    VlWide<3>/*95:0*/ __Vtemp_hf88603ef__0;
    VlWide<12>/*383:0*/ __Vtemp_h96314633__0;
    // Body
    __Vtemp_hf95fc64c__0[0U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_20_ctrl_csr_cmd)) 
                                         << 0x3cU) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_19_ctrl_csr_cmd)) 
                                            << 0x39U) 
                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_18_ctrl_csr_cmd)) 
                                               << 0x36U) 
                                              | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_17_ctrl_csr_cmd)) 
                                                  << 0x33U) 
                                                 | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_16_ctrl_csr_cmd)) 
                                                     << 0x30U) 
                                                    | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_15_ctrl_csr_cmd)) 
                                                        << 0x2dU) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_14_ctrl_csr_cmd)) 
                                                           << 0x2aU) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_13_ctrl_csr_cmd)) 
                                                              << 0x27U) 
                                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_12_ctrl_csr_cmd)) 
                                                                 << 0x24U) 
                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_11_ctrl_csr_cmd)) 
                                                                    << 0x21U) 
                                                                   | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_10_ctrl_csr_cmd)) 
                                                                       << 0x1eU) 
                                                                      | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_9_ctrl_csr_cmd) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_8_ctrl_csr_cmd) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_7_ctrl_csr_cmd) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_6_ctrl_csr_cmd) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_5_ctrl_csr_cmd) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_4_ctrl_csr_cmd) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_3_ctrl_csr_cmd) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_2_ctrl_csr_cmd) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_1_ctrl_csr_cmd) 
                                                                                << 3U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_0_ctrl_csr_cmd))))))))))))))))))))))));
    __Vtemp_hf95fc64c__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_21_ctrl_csr_cmd) 
                                 << 0x1fU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_20_ctrl_csr_cmd)) 
                                                        << 0x3cU) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_19_ctrl_csr_cmd)) 
                                                           << 0x39U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_18_ctrl_csr_cmd)) 
                                                              << 0x36U) 
                                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_17_ctrl_csr_cmd)) 
                                                                 << 0x33U) 
                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_16_ctrl_csr_cmd)) 
                                                                    << 0x30U) 
                                                                   | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_15_ctrl_csr_cmd)) 
                                                                       << 0x2dU) 
                                                                      | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_14_ctrl_csr_cmd)) 
                                                                          << 0x2aU) 
                                                                         | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_13_ctrl_csr_cmd)) 
                                                                             << 0x27U) 
                                                                            | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_12_ctrl_csr_cmd)) 
                                                                                << 0x24U) 
                                                                               | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_11_ctrl_csr_cmd)) 
                                                                                << 0x21U) 
                                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_10_ctrl_csr_cmd)) 
                                                                                << 0x1eU) 
                                                                                | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_9_ctrl_csr_cmd) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_8_ctrl_csr_cmd) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_7_ctrl_csr_cmd) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_6_ctrl_csr_cmd) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_5_ctrl_csr_cmd) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_4_ctrl_csr_cmd) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_3_ctrl_csr_cmd) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_2_ctrl_csr_cmd) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_1_ctrl_csr_cmd) 
                                                                                << 3U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_0_ctrl_csr_cmd))))))))))))))))))))))) 
                                                      >> 0x20U)));
    __Vtemp_hf88603ef__0[0U] = __Vtemp_hf95fc64c__0[0U];
    __Vtemp_hf88603ef__0[1U] = __Vtemp_hf95fc64c__0[1U];
    __Vtemp_hf88603ef__0[2U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_31_ctrl_csr_cmd) 
                                 << 0x1dU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_30_ctrl_csr_cmd) 
                                               << 0x1aU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_29_ctrl_csr_cmd) 
                                                  << 0x17U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_28_ctrl_csr_cmd) 
                                                     << 0x14U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_27_ctrl_csr_cmd) 
                                                        << 0x11U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_26_ctrl_csr_cmd) 
                                                           << 0xeU) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_25_ctrl_csr_cmd) 
                                                              << 0xbU) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_24_ctrl_csr_cmd) 
                                                                 << 8U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_23_ctrl_csr_cmd) 
                                                                    << 5U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_22_ctrl_csr_cmd) 
                                                                       << 2U) 
                                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_21_ctrl_csr_cmd) 
                                                                         >> 1U)))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_ctrl_csr_cmd 
        = ((0x5fU >= (0x7fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
            ? (7U & (((0U == (0x1fU & ((IData)(3U) 
                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
                       ? 0U : (__Vtemp_hf88603ef__0[
                               (((IData)(2U) + (0x7fU 
                                                & ((IData)(3U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))) 
                                >> 5U)] << ((IData)(0x20U) 
                                            - (0x1fU 
                                               & ((IData)(3U) 
                                                  * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))))) 
                     | (__Vtemp_hf88603ef__0[(3U & 
                                              (((IData)(3U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)) 
                                               >> 5U))] 
                        >> (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))))
            : 0U);
    __Vtemp_h96314633__0[0U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_4_csr_addr)) 
                                         << 0x30U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_3_csr_addr)) 
                                            << 0x24U) 
                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_csr_addr)) 
                                               << 0x18U) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_csr_addr) 
                                                                  << 0xcU) 
                                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_0_csr_addr))))))));
    __Vtemp_h96314633__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_5_csr_addr) 
                                 << 0x1cU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_4_csr_addr)) 
                                                        << 0x30U) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_3_csr_addr)) 
                                                           << 0x24U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_csr_addr)) 
                                                              << 0x18U) 
                                                             | (QData)((IData)(
                                                                               (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_csr_addr) 
                                                                                << 0xcU) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_0_csr_addr))))))) 
                                                      >> 0x20U)));
    __Vtemp_h96314633__0[2U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_7_csr_addr) 
                                 << 0x14U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_6_csr_addr) 
                                               << 8U) 
                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_5_csr_addr) 
                                                 >> 4U)));
    __Vtemp_h96314633__0[3U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_12_csr_addr)) 
                                         << 0x30U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_11_csr_addr)) 
                                            << 0x24U) 
                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_10_csr_addr)) 
                                               << 0x18U) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_9_csr_addr) 
                                                                  << 0xcU) 
                                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_8_csr_addr))))))));
    __Vtemp_h96314633__0[4U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_13_csr_addr) 
                                 << 0x1cU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_12_csr_addr)) 
                                                        << 0x30U) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_11_csr_addr)) 
                                                           << 0x24U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_10_csr_addr)) 
                                                              << 0x18U) 
                                                             | (QData)((IData)(
                                                                               (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_9_csr_addr) 
                                                                                << 0xcU) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_8_csr_addr))))))) 
                                                      >> 0x20U)));
    __Vtemp_h96314633__0[5U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_15_csr_addr) 
                                 << 0x14U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_14_csr_addr) 
                                               << 8U) 
                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_13_csr_addr) 
                                                 >> 4U)));
    __Vtemp_h96314633__0[6U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_20_csr_addr)) 
                                         << 0x30U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_19_csr_addr)) 
                                            << 0x24U) 
                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_18_csr_addr)) 
                                               << 0x18U) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_17_csr_addr) 
                                                                  << 0xcU) 
                                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_16_csr_addr))))))));
    __Vtemp_h96314633__0[7U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_21_csr_addr) 
                                 << 0x1cU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_20_csr_addr)) 
                                                        << 0x30U) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_19_csr_addr)) 
                                                           << 0x24U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_18_csr_addr)) 
                                                              << 0x18U) 
                                                             | (QData)((IData)(
                                                                               (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_17_csr_addr) 
                                                                                << 0xcU) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_16_csr_addr))))))) 
                                                      >> 0x20U)));
    __Vtemp_h96314633__0[8U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_23_csr_addr) 
                                 << 0x14U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_22_csr_addr) 
                                               << 8U) 
                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_21_csr_addr) 
                                                 >> 4U)));
    __Vtemp_h96314633__0[9U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_28_csr_addr)) 
                                         << 0x30U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_27_csr_addr)) 
                                            << 0x24U) 
                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_26_csr_addr)) 
                                               << 0x18U) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_25_csr_addr) 
                                                                  << 0xcU) 
                                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_24_csr_addr))))))));
    __Vtemp_h96314633__0[0xaU] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_29_csr_addr) 
                                   << 0x1cU) | (IData)(
                                                       ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_28_csr_addr)) 
                                                          << 0x30U) 
                                                         | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_27_csr_addr)) 
                                                             << 0x24U) 
                                                            | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_26_csr_addr)) 
                                                                << 0x18U) 
                                                               | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_25_csr_addr) 
                                                                                << 0xcU) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_24_csr_addr))))))) 
                                                        >> 0x20U)));
    __Vtemp_h96314633__0[0xbU] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_31_csr_addr) 
                                   << 0x14U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_30_csr_addr) 
                                                 << 8U) 
                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_29_csr_addr) 
                                                   >> 4U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_csr_addr 
        = ((0x17fU >= (0x1ffU & ((IData)(0xcU) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
            ? (0xfffU & (((0U == (0x1fU & ((IData)(0xcU) 
                                           * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
                           ? 0U : (__Vtemp_h96314633__0[
                                   (((IData)(0xbU) 
                                     + (0x1ffU & ((IData)(0xcU) 
                                                  * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))) 
                                    >> 5U)] << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & ((IData)(0xcU) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))))) 
                         | (__Vtemp_h96314633__0[(0xfU 
                                                  & (((IData)(0xcU) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)) 
                                                     >> 5U))] 
                            >> (0x1fU & ((IData)(0xcU) 
                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))))
            : 0U);
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__18968(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__18968\n"); );
    // Init
    VlWide<12>/*383:0*/ __Vtemp_hecd57545__0;
    VlWide<3>/*95:0*/ __Vtemp_h37e7b36d__0;
    VlWide<3>/*95:0*/ __Vtemp_h04318fb0__0;
    // Body
    __Vtemp_hecd57545__0[0U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_4_csr_addr)) 
                                         << 0x30U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_3_csr_addr)) 
                                            << 0x24U) 
                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_2_csr_addr)) 
                                               << 0x18U) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_1_csr_addr) 
                                                                  << 0xcU) 
                                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_0_csr_addr))))))));
    __Vtemp_hecd57545__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_5_csr_addr) 
                                 << 0x1cU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_4_csr_addr)) 
                                                        << 0x30U) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_3_csr_addr)) 
                                                           << 0x24U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_2_csr_addr)) 
                                                              << 0x18U) 
                                                             | (QData)((IData)(
                                                                               (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_1_csr_addr) 
                                                                                << 0xcU) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_0_csr_addr))))))) 
                                                      >> 0x20U)));
    __Vtemp_hecd57545__0[2U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_7_csr_addr) 
                                 << 0x14U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_6_csr_addr) 
                                               << 8U) 
                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_5_csr_addr) 
                                                 >> 4U)));
    __Vtemp_hecd57545__0[3U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_12_csr_addr)) 
                                         << 0x30U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_11_csr_addr)) 
                                            << 0x24U) 
                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_10_csr_addr)) 
                                               << 0x18U) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_9_csr_addr) 
                                                                  << 0xcU) 
                                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_8_csr_addr))))))));
    __Vtemp_hecd57545__0[4U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_13_csr_addr) 
                                 << 0x1cU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_12_csr_addr)) 
                                                        << 0x30U) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_11_csr_addr)) 
                                                           << 0x24U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_10_csr_addr)) 
                                                              << 0x18U) 
                                                             | (QData)((IData)(
                                                                               (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_9_csr_addr) 
                                                                                << 0xcU) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_8_csr_addr))))))) 
                                                      >> 0x20U)));
    __Vtemp_hecd57545__0[5U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_15_csr_addr) 
                                 << 0x14U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_14_csr_addr) 
                                               << 8U) 
                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_13_csr_addr) 
                                                 >> 4U)));
    __Vtemp_hecd57545__0[6U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_20_csr_addr)) 
                                         << 0x30U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_19_csr_addr)) 
                                            << 0x24U) 
                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_18_csr_addr)) 
                                               << 0x18U) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_17_csr_addr) 
                                                                  << 0xcU) 
                                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_16_csr_addr))))))));
    __Vtemp_hecd57545__0[7U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_21_csr_addr) 
                                 << 0x1cU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_20_csr_addr)) 
                                                        << 0x30U) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_19_csr_addr)) 
                                                           << 0x24U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_18_csr_addr)) 
                                                              << 0x18U) 
                                                             | (QData)((IData)(
                                                                               (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_17_csr_addr) 
                                                                                << 0xcU) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_16_csr_addr))))))) 
                                                      >> 0x20U)));
    __Vtemp_hecd57545__0[8U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_23_csr_addr) 
                                 << 0x14U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_22_csr_addr) 
                                               << 8U) 
                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_21_csr_addr) 
                                                 >> 4U)));
    __Vtemp_hecd57545__0[9U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_28_csr_addr)) 
                                         << 0x30U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_27_csr_addr)) 
                                            << 0x24U) 
                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_26_csr_addr)) 
                                               << 0x18U) 
                                              | (QData)((IData)(
                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_25_csr_addr) 
                                                                  << 0xcU) 
                                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_24_csr_addr))))))));
    __Vtemp_hecd57545__0[0xaU] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_29_csr_addr) 
                                   << 0x1cU) | (IData)(
                                                       ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_28_csr_addr)) 
                                                          << 0x30U) 
                                                         | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_27_csr_addr)) 
                                                             << 0x24U) 
                                                            | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_26_csr_addr)) 
                                                                << 0x18U) 
                                                               | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_25_csr_addr) 
                                                                                << 0xcU) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_24_csr_addr))))))) 
                                                        >> 0x20U)));
    __Vtemp_hecd57545__0[0xbU] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_31_csr_addr) 
                                   << 0x14U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_30_csr_addr) 
                                                 << 8U) 
                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_29_csr_addr) 
                                                   >> 4U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_csr_addr 
        = ((0x17fU >= (0x1ffU & ((IData)(0xcU) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
            ? (0xfffU & (((0U == (0x1fU & ((IData)(0xcU) 
                                           * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
                           ? 0U : (__Vtemp_hecd57545__0[
                                   (((IData)(0xbU) 
                                     + (0x1ffU & ((IData)(0xcU) 
                                                  * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))) 
                                    >> 5U)] << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & ((IData)(0xcU) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))))) 
                         | (__Vtemp_hecd57545__0[(0xfU 
                                                  & (((IData)(0xcU) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)) 
                                                     >> 5U))] 
                            >> (0x1fU & ((IData)(0xcU) 
                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))))
            : 0U);
    __Vtemp_h37e7b36d__0[0U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_20_ctrl_csr_cmd)) 
                                         << 0x3cU) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_19_ctrl_csr_cmd)) 
                                            << 0x39U) 
                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_18_ctrl_csr_cmd)) 
                                               << 0x36U) 
                                              | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_17_ctrl_csr_cmd)) 
                                                  << 0x33U) 
                                                 | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_16_ctrl_csr_cmd)) 
                                                     << 0x30U) 
                                                    | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_15_ctrl_csr_cmd)) 
                                                        << 0x2dU) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_14_ctrl_csr_cmd)) 
                                                           << 0x2aU) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_13_ctrl_csr_cmd)) 
                                                              << 0x27U) 
                                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_12_ctrl_csr_cmd)) 
                                                                 << 0x24U) 
                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_11_ctrl_csr_cmd)) 
                                                                    << 0x21U) 
                                                                   | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_10_ctrl_csr_cmd)) 
                                                                       << 0x1eU) 
                                                                      | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_9_ctrl_csr_cmd) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_8_ctrl_csr_cmd) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_7_ctrl_csr_cmd) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_6_ctrl_csr_cmd) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_5_ctrl_csr_cmd) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_4_ctrl_csr_cmd) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_3_ctrl_csr_cmd) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_ctrl_csr_cmd) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_ctrl_csr_cmd) 
                                                                                << 3U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_0_ctrl_csr_cmd))))))))))))))))))))))));
    __Vtemp_h37e7b36d__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_21_ctrl_csr_cmd) 
                                 << 0x1fU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_20_ctrl_csr_cmd)) 
                                                        << 0x3cU) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_19_ctrl_csr_cmd)) 
                                                           << 0x39U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_18_ctrl_csr_cmd)) 
                                                              << 0x36U) 
                                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_17_ctrl_csr_cmd)) 
                                                                 << 0x33U) 
                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_16_ctrl_csr_cmd)) 
                                                                    << 0x30U) 
                                                                   | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_15_ctrl_csr_cmd)) 
                                                                       << 0x2dU) 
                                                                      | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_14_ctrl_csr_cmd)) 
                                                                          << 0x2aU) 
                                                                         | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_13_ctrl_csr_cmd)) 
                                                                             << 0x27U) 
                                                                            | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_12_ctrl_csr_cmd)) 
                                                                                << 0x24U) 
                                                                               | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_11_ctrl_csr_cmd)) 
                                                                                << 0x21U) 
                                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_10_ctrl_csr_cmd)) 
                                                                                << 0x1eU) 
                                                                                | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_9_ctrl_csr_cmd) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_8_ctrl_csr_cmd) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_7_ctrl_csr_cmd) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_6_ctrl_csr_cmd) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_5_ctrl_csr_cmd) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_4_ctrl_csr_cmd) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_3_ctrl_csr_cmd) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_ctrl_csr_cmd) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_ctrl_csr_cmd) 
                                                                                << 3U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_0_ctrl_csr_cmd))))))))))))))))))))))) 
                                                      >> 0x20U)));
    __Vtemp_h04318fb0__0[0U] = __Vtemp_h37e7b36d__0[0U];
    __Vtemp_h04318fb0__0[1U] = __Vtemp_h37e7b36d__0[1U];
    __Vtemp_h04318fb0__0[2U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_31_ctrl_csr_cmd) 
                                 << 0x1dU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_30_ctrl_csr_cmd) 
                                               << 0x1aU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_29_ctrl_csr_cmd) 
                                                  << 0x17U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_28_ctrl_csr_cmd) 
                                                     << 0x14U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_27_ctrl_csr_cmd) 
                                                        << 0x11U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_26_ctrl_csr_cmd) 
                                                           << 0xeU) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_25_ctrl_csr_cmd) 
                                                              << 0xbU) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_24_ctrl_csr_cmd) 
                                                                 << 8U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_23_ctrl_csr_cmd) 
                                                                    << 5U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_22_ctrl_csr_cmd) 
                                                                       << 2U) 
                                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_21_ctrl_csr_cmd) 
                                                                         >> 1U)))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_ctrl_csr_cmd 
        = ((0x5fU >= (0x7fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
            ? (7U & (((0U == (0x1fU & ((IData)(3U) 
                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
                       ? 0U : (__Vtemp_h04318fb0__0[
                               (((IData)(2U) + (0x7fU 
                                                & ((IData)(3U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))) 
                                >> 5U)] << ((IData)(0x20U) 
                                            - (0x1fU 
                                               & ((IData)(3U) 
                                                  * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))))) 
                     | (__Vtemp_h04318fb0__0[(3U & 
                                              (((IData)(3U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)) 
                                               >> 5U))] 
                        >> (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))))
            : 0U);
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__18969(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__18969\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h13e7a4d6__0;
    VlWide<3>/*95:0*/ __Vtemp_h412a6369__0;
    // Body
    __Vtemp_h13e7a4d6__0[0U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_20_ctrl_csr_cmd)) 
                                         << 0x3cU) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_19_ctrl_csr_cmd)) 
                                            << 0x39U) 
                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_18_ctrl_csr_cmd)) 
                                               << 0x36U) 
                                              | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_17_ctrl_csr_cmd)) 
                                                  << 0x33U) 
                                                 | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_16_ctrl_csr_cmd)) 
                                                     << 0x30U) 
                                                    | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_15_ctrl_csr_cmd)) 
                                                        << 0x2dU) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_14_ctrl_csr_cmd)) 
                                                           << 0x2aU) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_13_ctrl_csr_cmd)) 
                                                              << 0x27U) 
                                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_12_ctrl_csr_cmd)) 
                                                                 << 0x24U) 
                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_11_ctrl_csr_cmd)) 
                                                                    << 0x21U) 
                                                                   | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_10_ctrl_csr_cmd)) 
                                                                       << 0x1eU) 
                                                                      | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_9_ctrl_csr_cmd) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_8_ctrl_csr_cmd) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_7_ctrl_csr_cmd) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_6_ctrl_csr_cmd) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_5_ctrl_csr_cmd) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_4_ctrl_csr_cmd) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_3_ctrl_csr_cmd) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_2_ctrl_csr_cmd) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_1_ctrl_csr_cmd) 
                                                                                << 3U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_0_ctrl_csr_cmd))))))))))))))))))))))));
    __Vtemp_h13e7a4d6__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_21_ctrl_csr_cmd) 
                                 << 0x1fU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_20_ctrl_csr_cmd)) 
                                                        << 0x3cU) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_19_ctrl_csr_cmd)) 
                                                           << 0x39U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_18_ctrl_csr_cmd)) 
                                                              << 0x36U) 
                                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_17_ctrl_csr_cmd)) 
                                                                 << 0x33U) 
                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_16_ctrl_csr_cmd)) 
                                                                    << 0x30U) 
                                                                   | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_15_ctrl_csr_cmd)) 
                                                                       << 0x2dU) 
                                                                      | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_14_ctrl_csr_cmd)) 
                                                                          << 0x2aU) 
                                                                         | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_13_ctrl_csr_cmd)) 
                                                                             << 0x27U) 
                                                                            | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_12_ctrl_csr_cmd)) 
                                                                                << 0x24U) 
                                                                               | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_11_ctrl_csr_cmd)) 
                                                                                << 0x21U) 
                                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_10_ctrl_csr_cmd)) 
                                                                                << 0x1eU) 
                                                                                | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_9_ctrl_csr_cmd) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_8_ctrl_csr_cmd) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_7_ctrl_csr_cmd) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_6_ctrl_csr_cmd) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_5_ctrl_csr_cmd) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_4_ctrl_csr_cmd) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_3_ctrl_csr_cmd) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_2_ctrl_csr_cmd) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_1_ctrl_csr_cmd) 
                                                                                << 3U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_0_ctrl_csr_cmd))))))))))))))))))))))) 
                                                      >> 0x20U)));
    __Vtemp_h412a6369__0[0U] = __Vtemp_h13e7a4d6__0[0U];
    __Vtemp_h412a6369__0[1U] = __Vtemp_h13e7a4d6__0[1U];
    __Vtemp_h412a6369__0[2U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_31_ctrl_csr_cmd) 
                                 << 0x1dU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_30_ctrl_csr_cmd) 
                                               << 0x1aU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_29_ctrl_csr_cmd) 
                                                  << 0x17U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_28_ctrl_csr_cmd) 
                                                     << 0x14U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_27_ctrl_csr_cmd) 
                                                        << 0x11U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_26_ctrl_csr_cmd) 
                                                           << 0xeU) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_25_ctrl_csr_cmd) 
                                                              << 0xbU) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_24_ctrl_csr_cmd) 
                                                                 << 8U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_23_ctrl_csr_cmd) 
                                                                    << 5U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_22_ctrl_csr_cmd) 
                                                                       << 2U) 
                                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_21_ctrl_csr_cmd) 
                                                                         >> 1U)))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_ctrl_csr_cmd 
        = ((0x5fU >= (0x7fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
            ? (7U & (((0U == (0x1fU & ((IData)(3U) 
                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))
                       ? 0U : (__Vtemp_h412a6369__0[
                               (((IData)(2U) + (0x7fU 
                                                & ((IData)(3U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))) 
                                >> 5U)] << ((IData)(0x20U) 
                                            - (0x1fU 
                                               & ((IData)(3U) 
                                                  * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)))))) 
                     | (__Vtemp_h412a6369__0[(3U & 
                                              (((IData)(3U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)) 
                                               >> 5U))] 
                        >> (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))))
            : 0U);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1476 
        = (((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_state)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___empty_T)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__maybe_full)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__full 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___empty_T) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__maybe_full));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__18970(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__18970\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h949a6b44__0;
    // Body
    __Vtemp_h949a6b44__0[0U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_20_cfi_type)) 
                                         << 0x3cU) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_19_cfi_type)) 
                                            << 0x39U) 
                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_18_cfi_type)) 
                                               << 0x36U) 
                                              | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_17_cfi_type)) 
                                                  << 0x33U) 
                                                 | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_16_cfi_type)) 
                                                     << 0x30U) 
                                                    | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_15_cfi_type)) 
                                                        << 0x2dU) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_14_cfi_type)) 
                                                           << 0x2aU) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_13_cfi_type)) 
                                                              << 0x27U) 
                                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_12_cfi_type)) 
                                                                 << 0x24U) 
                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_11_cfi_type)) 
                                                                    << 0x21U) 
                                                                   | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_10_cfi_type)) 
                                                                       << 0x1eU) 
                                                                      | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_9_cfi_type) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_8_cfi_type) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_7_cfi_type) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_6_cfi_type) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_5_cfi_type) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_4_cfi_type) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_3_cfi_type) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_2_cfi_type) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_1_cfi_type) 
                                                                                << 3U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_0_cfi_type))))))))))))))))))))))));
    __Vtemp_h949a6b44__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_21_cfi_type) 
                                 << 0x1fU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_20_cfi_type)) 
                                                        << 0x3cU) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_19_cfi_type)) 
                                                           << 0x39U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_18_cfi_type)) 
                                                              << 0x36U) 
                                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_17_cfi_type)) 
                                                                 << 0x33U) 
                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_16_cfi_type)) 
                                                                    << 0x30U) 
                                                                   | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_15_cfi_type)) 
                                                                       << 0x2dU) 
                                                                      | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_14_cfi_type)) 
                                                                          << 0x2aU) 
                                                                         | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_13_cfi_type)) 
                                                                             << 0x27U) 
                                                                            | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_12_cfi_type)) 
                                                                                << 0x24U) 
                                                                               | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_11_cfi_type)) 
                                                                                << 0x21U) 
                                                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_10_cfi_type)) 
                                                                                << 0x1eU) 
                                                                                | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_9_cfi_type) 
                                                                                << 0x1bU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_8_cfi_type) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_7_cfi_type) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_6_cfi_type) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_5_cfi_type) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_4_cfi_type) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_3_cfi_type) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_2_cfi_type) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_1_cfi_type) 
                                                                                << 3U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_0_cfi_type))))))))))))))))))))))) 
                                                      >> 0x20U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_51[0U] 
        = __Vtemp_h949a6b44__0[0U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_51[1U] 
        = __Vtemp_h949a6b44__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_51[2U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_31_cfi_type) 
            << 0x1dU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_30_cfi_type) 
                          << 0x1aU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_29_cfi_type) 
                                        << 0x17U) | 
                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_28_cfi_type) 
                                         << 0x14U) 
                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_27_cfi_type) 
                                            << 0x11U) 
                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_26_cfi_type) 
                                               << 0xeU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_25_cfi_type) 
                                                  << 0xbU) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_24_cfi_type) 
                                                     << 8U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_23_cfi_type) 
                                                        << 5U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_22_cfi_type) 
                                                           << 2U) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_21_cfi_type) 
                                                             >> 1U)))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__18971(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__18971\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_50 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_31_cfi_mispredicted) 
            << 0x1fU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_30_cfi_mispredicted) 
                          << 0x1eU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_29_cfi_mispredicted) 
                                        << 0x1dU) | 
                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_28_cfi_mispredicted) 
                                         << 0x1cU) 
                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_27_cfi_mispredicted) 
                                            << 0x1bU) 
                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_26_cfi_mispredicted) 
                                               << 0x1aU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_25_cfi_mispredicted) 
                                                  << 0x19U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_24_cfi_mispredicted) 
                                                     << 0x18U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_23_cfi_mispredicted) 
                                                        << 0x17U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_22_cfi_mispredicted) 
                                                           << 0x16U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_21_cfi_mispredicted) 
                                                              << 0x15U) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_20_cfi_mispredicted) 
                                                                 << 0x14U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_19_cfi_mispredicted) 
                                                                    << 0x13U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_18_cfi_mispredicted) 
                                                                       << 0x12U) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_17_cfi_mispredicted) 
                                                                          << 0x11U) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_16_cfi_mispredicted) 
                                                                             << 0x10U) 
                                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_15_cfi_mispredicted) 
                                                                                << 0xfU) 
                                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_14_cfi_mispredicted) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_13_cfi_mispredicted) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_12_cfi_mispredicted) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_11_cfi_mispredicted) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_10_cfi_mispredicted) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_9_cfi_mispredicted) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_8_cfi_mispredicted) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_7_cfi_mispredicted) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_6_cfi_mispredicted) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_5_cfi_mispredicted) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_4_cfi_mispredicted) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_3_cfi_mispredicted) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_2_cfi_mispredicted) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_1_cfi_mispredicted) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_0_cfi_mispredicted))))))))))))))))))))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__new_ghist_cfi_in_bank_0 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___new_ghist_new_history_new_saw_branch_taken_T_1) 
           & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_entry_cfi_idx_bits) 
                 >> 2U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_0);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[1U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_1) 
            << 8U) | (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_0 
                              >> 0x20U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[2U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_2) 
            << 0x10U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_1) 
                          >> 0x18U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_1 
                                                >> 0x20U)) 
                                       << 8U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[3U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_3) 
            << 0x18U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_2) 
                          >> 0x10U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_2 
                                                >> 0x20U)) 
                                       << 0x10U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[4U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_3) 
            >> 8U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_3 
                               >> 0x20U)) << 0x18U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[5U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_4);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[6U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_5) 
            << 8U) | (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_4 
                              >> 0x20U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[7U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_6) 
            << 0x10U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_5) 
                          >> 0x18U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_5 
                                                >> 0x20U)) 
                                       << 8U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[8U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_7) 
            << 0x18U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_6) 
                          >> 0x10U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_6 
                                                >> 0x20U)) 
                                       << 0x10U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[9U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_7) 
            >> 8U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_7 
                               >> 0x20U)) << 0x18U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0xaU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_8);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0xbU] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_9) 
            << 8U) | (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_8 
                              >> 0x20U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0xcU] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_10) 
            << 0x10U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_9) 
                          >> 0x18U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_9 
                                                >> 0x20U)) 
                                       << 8U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0xdU] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_11) 
            << 0x18U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_10) 
                          >> 0x10U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_10 
                                                >> 0x20U)) 
                                       << 0x10U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0xeU] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_11) 
            >> 8U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_11 
                               >> 0x20U)) << 0x18U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0xfU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_12);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x10U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_13) 
            << 8U) | (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_12 
                              >> 0x20U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x11U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_14) 
            << 0x10U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_13) 
                          >> 0x18U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_13 
                                                >> 0x20U)) 
                                       << 8U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x12U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_15) 
            << 0x18U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_14) 
                          >> 0x10U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_14 
                                                >> 0x20U)) 
                                       << 0x10U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x13U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_15) 
            >> 8U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_15 
                               >> 0x20U)) << 0x18U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x14U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_16);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x15U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_17) 
            << 8U) | (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_16 
                              >> 0x20U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x16U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_18) 
            << 0x10U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_17) 
                          >> 0x18U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_17 
                                                >> 0x20U)) 
                                       << 8U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x17U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_19) 
            << 0x18U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_18) 
                          >> 0x10U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_18 
                                                >> 0x20U)) 
                                       << 0x10U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x18U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_19) 
            >> 8U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_19 
                               >> 0x20U)) << 0x18U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x19U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_20);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x1aU] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_21) 
            << 8U) | (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_20 
                              >> 0x20U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x1bU] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_22) 
            << 0x10U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_21) 
                          >> 0x18U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_21 
                                                >> 0x20U)) 
                                       << 8U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x1cU] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_23) 
            << 0x18U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_22) 
                          >> 0x10U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_22 
                                                >> 0x20U)) 
                                       << 0x10U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x1dU] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_23) 
            >> 8U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_23 
                               >> 0x20U)) << 0x18U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x1eU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_24);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x1fU] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_25) 
            << 8U) | (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_24 
                              >> 0x20U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x20U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_26) 
            << 0x10U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_25) 
                          >> 0x18U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_25 
                                                >> 0x20U)) 
                                       << 8U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x21U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_27) 
            << 0x18U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_26) 
                          >> 0x10U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_26 
                                                >> 0x20U)) 
                                       << 0x10U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x22U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_27) 
            >> 8U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_27 
                               >> 0x20U)) << 0x18U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x23U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_28);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x24U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_29) 
            << 8U) | (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_28 
                              >> 0x20U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x25U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_30) 
            << 0x10U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_29) 
                          >> 0x18U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_29 
                                                >> 0x20U)) 
                                       << 8U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x26U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_31) 
            << 0x18U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_30) 
                          >> 0x10U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_30 
                                                >> 0x20U)) 
                                       << 0x10U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_53[0x27U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_31) 
            >> 8U) | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_31 
                               >> 0x20U)) << 0x18U));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__18972(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__18972\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_2 
        = (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_1) 
                    | (((7U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_entry_cfi_idx_bits))
                         ? (0xffU & ((IData)(1U) << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_entry_cfi_idx_bits)))
                         : 0U) >> 3U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT___T_74 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_2__DOT__io_f3_resp_2_valid_REG)
                  ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_2__DOT__io_f3_resp_2_bits_ctr_REG) 
                     >> 2U) : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT___T_70)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT___T_74 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_2__DOT__io_f3_resp_2_valid_REG)
                  ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_2__DOT__io_f3_resp_2_bits_ctr_REG) 
                     >> 2U) : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT___T_70)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[1U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[2U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_1_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[3U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_1_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[4U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_2_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[5U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_2_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[6U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_3_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[7U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_3_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[8U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_4_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[9U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_4_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0xaU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_5_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0xbU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_5_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0xcU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_6_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0xdU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_6_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0xeU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_7_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0xfU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_7_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x10U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_8_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x11U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_8_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x12U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_9_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x13U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_9_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x14U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_10_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x15U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_10_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x16U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_11_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x17U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_11_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x18U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_12_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x19U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_12_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x1aU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_13_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x1bU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_13_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x1cU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_14_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x1dU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_14_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x1eU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_15_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x1fU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_15_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x20U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_16_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x21U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_16_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x22U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_17_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x23U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_17_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x24U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_18_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x25U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_18_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x26U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_19_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x27U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_19_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x28U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_20_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x29U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_20_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x2aU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_21_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x2bU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_21_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x2cU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_22_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x2dU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_22_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x2eU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_23_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x2fU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_23_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x30U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x31U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x32U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x33U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x34U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x35U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x36U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x37U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x38U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x39U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x3aU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x3bU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x3cU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x3dU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x3eU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_193[0x3fU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_uop_exc_cause 
                   >> 0x20U));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__18973(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__18973\n"); );
    // Init
    VlWide<32>/*1023:0*/ __Vtemp_hfc15453f__0;
    VlWide<32>/*1023:0*/ __Vtemp_ha27f88e6__0;
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_0_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[1U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_0_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[2U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_1_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[3U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_1_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[4U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_2_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[5U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_2_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[6U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_3_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[7U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_3_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[8U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_4_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[9U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_4_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0xaU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_5_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0xbU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_5_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0xcU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_6_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0xdU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_6_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0xeU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_7_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0xfU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_7_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x10U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_8_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x11U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_8_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x12U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_9_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x13U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_9_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x14U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_10_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x15U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_10_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x16U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_11_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x17U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_11_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x18U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_12_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x19U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_12_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x1aU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_13_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x1bU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_13_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x1cU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_14_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x1dU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_14_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x1eU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_15_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x1fU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_15_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x20U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_16_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x21U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_16_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x22U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_17_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x23U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_17_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x24U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x25U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x26U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x27U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x28U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x29U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x2aU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x2bU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x2cU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x2dU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x2eU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x2fU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x30U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_0_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x31U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_0_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x32U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_0_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x33U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_0_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x34U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_0_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x35U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_0_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x36U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_0_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x37U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_0_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x38U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_0_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x39U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_0_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x3aU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_0_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x3bU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_0_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x3cU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_0_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x3dU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_0_bits_uop_exc_cause 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x3eU] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_0_bits_uop_exc_cause);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_51[0x3fU] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_0_bits_uop_exc_cause 
                   >> 0x20U));
    __Vtemp_hfc15453f__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_0_exc_cause);
    __Vtemp_hfc15453f__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_0_exc_cause 
                                        >> 0x20U));
    __Vtemp_hfc15453f__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_1_exc_cause);
    __Vtemp_hfc15453f__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_1_exc_cause 
                                        >> 0x20U));
    __Vtemp_hfc15453f__0[4U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_2_exc_cause);
    __Vtemp_hfc15453f__0[5U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_2_exc_cause 
                                        >> 0x20U));
    __Vtemp_hfc15453f__0[6U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_3_exc_cause);
    __Vtemp_hfc15453f__0[7U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_3_exc_cause 
                                        >> 0x20U));
    __Vtemp_hfc15453f__0[8U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_4_exc_cause);
    __Vtemp_hfc15453f__0[9U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_4_exc_cause 
                                        >> 0x20U));
    __Vtemp_hfc15453f__0[0xaU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_5_exc_cause);
    __Vtemp_hfc15453f__0[0xbU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_5_exc_cause 
                                          >> 0x20U));
    __Vtemp_hfc15453f__0[0xcU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_6_exc_cause);
    __Vtemp_hfc15453f__0[0xdU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_6_exc_cause 
                                          >> 0x20U));
    __Vtemp_hfc15453f__0[0xeU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_7_exc_cause);
    __Vtemp_hfc15453f__0[0xfU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_7_exc_cause 
                                          >> 0x20U));
    __Vtemp_hfc15453f__0[0x10U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_8_exc_cause);
    __Vtemp_hfc15453f__0[0x11U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_8_exc_cause 
                                           >> 0x20U));
    __Vtemp_hfc15453f__0[0x12U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_9_exc_cause);
    __Vtemp_hfc15453f__0[0x13U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_9_exc_cause 
                                           >> 0x20U));
    __Vtemp_hfc15453f__0[0x14U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_10_exc_cause);
    __Vtemp_hfc15453f__0[0x15U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_10_exc_cause 
                                           >> 0x20U));
    __Vtemp_hfc15453f__0[0x16U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_11_exc_cause);
    __Vtemp_hfc15453f__0[0x17U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_11_exc_cause 
                                           >> 0x20U));
    __Vtemp_hfc15453f__0[0x18U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_12_exc_cause);
    __Vtemp_hfc15453f__0[0x19U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_12_exc_cause 
                                           >> 0x20U));
    __Vtemp_hfc15453f__0[0x1aU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_13_exc_cause);
    __Vtemp_hfc15453f__0[0x1bU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_13_exc_cause 
                                           >> 0x20U));
    __Vtemp_hfc15453f__0[0x1cU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_14_exc_cause);
    __Vtemp_hfc15453f__0[0x1dU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_14_exc_cause 
                                           >> 0x20U));
    __Vtemp_hfc15453f__0[0x1eU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_15_exc_cause);
    __Vtemp_hfc15453f__0[0x1fU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__uops_15_exc_cause 
                                           >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT___rpq_io_deq_bits_uop_exc_cause 
        = (((QData)((IData)(__Vtemp_hfc15453f__0[(((IData)(0x3fU) 
                                                   + 
                                                   (0x3ffU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__deq_ptr_value) 
                                                       << 6U))) 
                                                  >> 5U)])) 
            << ((0U == (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__deq_ptr_value) 
                                 << 6U))) ? 0x20U : 
                ((IData)(0x40U) - (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__deq_ptr_value) 
                                            << 6U))))) 
           | (((0U == (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__deq_ptr_value) 
                                << 6U))) ? 0ULL : ((QData)((IData)(
                                                                   __Vtemp_hfc15453f__0[
                                                                   (((IData)(0x1fU) 
                                                                     + 
                                                                     (0x3ffU 
                                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__deq_ptr_value) 
                                                                         << 6U))) 
                                                                    >> 5U)])) 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__deq_ptr_value) 
                                                        << 6U))))) 
              | ((QData)((IData)(__Vtemp_hfc15453f__0[
                                 (0x1eU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__deq_ptr_value) 
                                           << 1U))])) 
                 >> (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__rpq__DOT__deq_ptr_value) 
                              << 6U)))));
    __Vtemp_ha27f88e6__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_0_exc_cause);
    __Vtemp_ha27f88e6__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_0_exc_cause 
                                        >> 0x20U));
    __Vtemp_ha27f88e6__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_1_exc_cause);
    __Vtemp_ha27f88e6__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_1_exc_cause 
                                        >> 0x20U));
    __Vtemp_ha27f88e6__0[4U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_2_exc_cause);
    __Vtemp_ha27f88e6__0[5U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_2_exc_cause 
                                        >> 0x20U));
    __Vtemp_ha27f88e6__0[6U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_3_exc_cause);
    __Vtemp_ha27f88e6__0[7U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_3_exc_cause 
                                        >> 0x20U));
    __Vtemp_ha27f88e6__0[8U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_4_exc_cause);
    __Vtemp_ha27f88e6__0[9U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_4_exc_cause 
                                        >> 0x20U));
    __Vtemp_ha27f88e6__0[0xaU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_5_exc_cause);
    __Vtemp_ha27f88e6__0[0xbU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_5_exc_cause 
                                          >> 0x20U));
    __Vtemp_ha27f88e6__0[0xcU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_6_exc_cause);
    __Vtemp_ha27f88e6__0[0xdU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_6_exc_cause 
                                          >> 0x20U));
    __Vtemp_ha27f88e6__0[0xeU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_7_exc_cause);
    __Vtemp_ha27f88e6__0[0xfU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_7_exc_cause 
                                          >> 0x20U));
    __Vtemp_ha27f88e6__0[0x10U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_8_exc_cause);
    __Vtemp_ha27f88e6__0[0x11U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_8_exc_cause 
                                           >> 0x20U));
    __Vtemp_ha27f88e6__0[0x12U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_9_exc_cause);
    __Vtemp_ha27f88e6__0[0x13U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_9_exc_cause 
                                           >> 0x20U));
    __Vtemp_ha27f88e6__0[0x14U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_10_exc_cause);
    __Vtemp_ha27f88e6__0[0x15U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_10_exc_cause 
                                           >> 0x20U));
    __Vtemp_ha27f88e6__0[0x16U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_11_exc_cause);
    __Vtemp_ha27f88e6__0[0x17U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_11_exc_cause 
                                           >> 0x20U));
    __Vtemp_ha27f88e6__0[0x18U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_12_exc_cause);
    __Vtemp_ha27f88e6__0[0x19U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_12_exc_cause 
                                           >> 0x20U));
    __Vtemp_ha27f88e6__0[0x1aU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_13_exc_cause);
    __Vtemp_ha27f88e6__0[0x1bU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_13_exc_cause 
                                           >> 0x20U));
    __Vtemp_ha27f88e6__0[0x1cU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_14_exc_cause);
    __Vtemp_ha27f88e6__0[0x1dU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_14_exc_cause 
                                           >> 0x20U));
    __Vtemp_ha27f88e6__0[0x1eU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_15_exc_cause);
    __Vtemp_ha27f88e6__0[0x1fU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__uops_15_exc_cause 
                                           >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT___rpq_io_deq_bits_uop_exc_cause 
        = (((QData)((IData)(__Vtemp_ha27f88e6__0[(((IData)(0x3fU) 
                                                   + 
                                                   (0x3ffU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__deq_ptr_value) 
                                                       << 6U))) 
                                                  >> 5U)])) 
            << ((0U == (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__deq_ptr_value) 
                                 << 6U))) ? 0x20U : 
                ((IData)(0x40U) - (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__deq_ptr_value) 
                                            << 6U))))) 
           | (((0U == (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__deq_ptr_value) 
                                << 6U))) ? 0ULL : ((QData)((IData)(
                                                                   __Vtemp_ha27f88e6__0[
                                                                   (((IData)(0x1fU) 
                                                                     + 
                                                                     (0x3ffU 
                                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__deq_ptr_value) 
                                                                         << 6U))) 
                                                                    >> 5U)])) 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__deq_ptr_value) 
                                                        << 6U))))) 
              | ((QData)((IData)(__Vtemp_ha27f88e6__0[
                                 (0x1eU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__deq_ptr_value) 
                                           << 1U))])) 
                 >> (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__rpq__DOT__deq_ptr_value) 
                              << 6U)))));
}
