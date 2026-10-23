// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTestHarness.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTestHarness___024root.h"

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1709(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1709\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_12 
        = ((0x400U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                      << 9U)) | ((0x200U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                            << 7U)) 
                                 | ((0x100U & ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                   >> 3U)) 
                                               << 8U)) 
                                    | ((0x80U & ((~ 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                   >> 4U)) 
                                                 << 7U)) 
                                       | ((0x40U & 
                                           ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                >> 5U)) 
                                            << 6U)) 
                                          | ((0x20U 
                                              & ((~ 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                   >> 6U)) 
                                                 << 5U)) 
                                             | ((0x10U 
                                                 & ((~ 
                                                     ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                      >> 7U)) 
                                                    << 4U)) 
                                                | ((8U 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                       >> 5U)) 
                                                   | ((4U 
                                                       & ((~ 
                                                           ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                            >> 9U)) 
                                                          << 2U)) 
                                                      | ((2U 
                                                          & ((~ 
                                                              ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                               >> 0xaU)) 
                                                             << 1U)) 
                                                         | (1U 
                                                            & (~ 
                                                               ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                >> 0xbU)))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_38 
        = ((0x400U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                      << 9U)) | ((0x200U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                            << 7U)) 
                                 | ((0x100U & ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                   >> 3U)) 
                                               << 8U)) 
                                    | ((0x80U & ((~ 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                   >> 4U)) 
                                                 << 7U)) 
                                       | ((0x40U & 
                                           ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                >> 5U)) 
                                            << 6U)) 
                                          | ((0x20U 
                                              & ((~ 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                   >> 6U)) 
                                                 << 5U)) 
                                             | ((0x10U 
                                                 & ((~ 
                                                     ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                      >> 7U)) 
                                                    << 4U)) 
                                                | ((8U 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                       >> 5U)) 
                                                   | ((4U 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                          >> 7U)) 
                                                      | ((2U 
                                                          & ((~ 
                                                              ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                               >> 0xaU)) 
                                                             << 1U)) 
                                                         | (1U 
                                                            & (~ 
                                                               ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                >> 0xbU)))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1710(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1710\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_40 
        = ((0x400U & ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                          >> 1U)) << 0xaU)) | ((0x200U 
                                                & ((~ 
                                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                     >> 2U)) 
                                                   << 9U)) 
                                               | ((0x100U 
                                                   & ((~ 
                                                       ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                        >> 3U)) 
                                                      << 8U)) 
                                                  | ((0x80U 
                                                      & ((~ 
                                                          ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                           >> 4U)) 
                                                         << 7U)) 
                                                     | ((0x40U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                            << 1U)) 
                                                        | ((0x20U 
                                                            & ((~ 
                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                 >> 6U)) 
                                                               << 5U)) 
                                                           | ((0x10U 
                                                               & ((~ 
                                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                    >> 7U)) 
                                                                  << 4U)) 
                                                              | ((8U 
                                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                     >> 5U)) 
                                                                 | ((4U 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                        >> 7U)) 
                                                                    | ((2U 
                                                                        & ((~ 
                                                                            ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                             >> 0xaU)) 
                                                                           << 1U)) 
                                                                       | (1U 
                                                                          & (~ 
                                                                             ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                              >> 0xbU)))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_2 
        = ((0x800U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr)) 
                      << 0xbU)) | ((0x400U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                              << 9U)) 
                                   | ((0x200U & ((~ 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                   >> 2U)) 
                                                 << 9U)) 
                                      | ((0x100U & 
                                          ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                               >> 3U)) 
                                           << 8U)) 
                                         | ((0x80U 
                                             & ((~ 
                                                 ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                  >> 4U)) 
                                                << 7U)) 
                                            | ((0x40U 
                                                & ((~ 
                                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                     >> 5U)) 
                                                   << 6U)) 
                                               | ((0x20U 
                                                   & ((~ 
                                                       ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                        >> 6U)) 
                                                      << 5U)) 
                                                  | ((0x10U 
                                                      & ((~ 
                                                          ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                           >> 7U)) 
                                                         << 4U)) 
                                                     | ((8U 
                                                         & ((~ 
                                                             ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                              >> 8U)) 
                                                            << 3U)) 
                                                        | ((4U 
                                                            & ((~ 
                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                 >> 9U)) 
                                                               << 2U)) 
                                                           | ((2U 
                                                               & ((~ 
                                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                    >> 0xaU)) 
                                                                  << 1U)) 
                                                              | (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                     >> 0xbU))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1711(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1711\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_114 
        = ((0x800U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr)) 
                      << 0xbU)) | ((0x400U & ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                  >> 1U)) 
                                              << 0xaU)) 
                                   | ((0x200U & ((~ 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                   >> 2U)) 
                                                 << 9U)) 
                                      | ((0x100U & 
                                          ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                               >> 3U)) 
                                           << 8U)) 
                                         | ((0x80U 
                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                << 3U)) 
                                            | ((0x40U 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                   << 1U)) 
                                               | ((0x20U 
                                                   & ((~ 
                                                       ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                        >> 6U)) 
                                                      << 5U)) 
                                                  | ((0x10U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                         >> 3U)) 
                                                     | ((8U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                            >> 5U)) 
                                                        | ((4U 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                               >> 7U)) 
                                                           | ((2U 
                                                               & ((~ 
                                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                    >> 0xaU)) 
                                                                  << 1U)) 
                                                              | (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                     >> 0xbU))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_116 
        = ((0x800U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                      << 0xbU)) | ((0x400U & ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                  >> 1U)) 
                                              << 0xaU)) 
                                   | ((0x200U & ((~ 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                   >> 2U)) 
                                                 << 9U)) 
                                      | ((0x100U & 
                                          ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                               >> 3U)) 
                                           << 8U)) 
                                         | ((0x80U 
                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                << 3U)) 
                                            | ((0x40U 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                   << 1U)) 
                                               | ((0x20U 
                                                   & ((~ 
                                                       ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                        >> 6U)) 
                                                      << 5U)) 
                                                  | ((0x10U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                         >> 3U)) 
                                                     | ((8U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                            >> 5U)) 
                                                        | ((4U 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                               >> 7U)) 
                                                           | ((2U 
                                                               & ((~ 
                                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                    >> 0xaU)) 
                                                                  << 1U)) 
                                                              | (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                     >> 0xbU))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1712(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1712\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_118 
        = ((0x800U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr)) 
                      << 0xbU)) | ((0x400U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                              << 9U)) 
                                   | ((0x200U & ((~ 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                   >> 2U)) 
                                                 << 9U)) 
                                      | ((0x100U & 
                                          ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                               >> 3U)) 
                                           << 8U)) 
                                         | ((0x80U 
                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                << 3U)) 
                                            | ((0x40U 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                   << 1U)) 
                                               | ((0x20U 
                                                   & ((~ 
                                                       ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                        >> 6U)) 
                                                      << 5U)) 
                                                  | ((0x10U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                         >> 3U)) 
                                                     | ((8U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                            >> 5U)) 
                                                        | ((4U 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                               >> 7U)) 
                                                           | ((2U 
                                                               & ((~ 
                                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                    >> 0xaU)) 
                                                                  << 1U)) 
                                                              | (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                     >> 0xbU))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_120 
        = ((0x800U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                      << 0xbU)) | ((0x400U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                              << 9U)) 
                                   | ((0x200U & ((~ 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                   >> 2U)) 
                                                 << 9U)) 
                                      | ((0x100U & 
                                          ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                               >> 3U)) 
                                           << 8U)) 
                                         | ((0x80U 
                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                << 3U)) 
                                            | ((0x40U 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                   << 1U)) 
                                               | ((0x20U 
                                                   & ((~ 
                                                       ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                        >> 6U)) 
                                                      << 5U)) 
                                                  | ((0x10U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                         >> 3U)) 
                                                     | ((8U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                            >> 5U)) 
                                                        | ((4U 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                               >> 7U)) 
                                                           | ((2U 
                                                               & ((~ 
                                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                    >> 0xaU)) 
                                                                  << 1U)) 
                                                              | (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                     >> 0xbU))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1713(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1713\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_122 
        = ((0x800U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr)) 
                      << 0xbU)) | ((0x400U & ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                  >> 1U)) 
                                              << 0xaU)) 
                                   | ((0x200U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                 << 7U)) 
                                      | ((0x100U & 
                                          ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                               >> 3U)) 
                                           << 8U)) 
                                         | ((0x80U 
                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                << 3U)) 
                                            | ((0x40U 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                   << 1U)) 
                                               | ((0x20U 
                                                   & ((~ 
                                                       ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                        >> 6U)) 
                                                      << 5U)) 
                                                  | ((0x10U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                         >> 3U)) 
                                                     | ((8U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                            >> 5U)) 
                                                        | ((4U 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                               >> 7U)) 
                                                           | ((2U 
                                                               & ((~ 
                                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                    >> 0xaU)) 
                                                                  << 1U)) 
                                                              | (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                     >> 0xbU))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_124 
        = ((0x800U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                      << 0xbU)) | ((0x400U & ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                  >> 1U)) 
                                              << 0xaU)) 
                                   | ((0x200U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                 << 7U)) 
                                      | ((0x100U & 
                                          ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                               >> 3U)) 
                                           << 8U)) 
                                         | ((0x80U 
                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                << 3U)) 
                                            | ((0x40U 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                   << 1U)) 
                                               | ((0x20U 
                                                   & ((~ 
                                                       ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                        >> 6U)) 
                                                      << 5U)) 
                                                  | ((0x10U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                         >> 3U)) 
                                                     | ((8U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                            >> 5U)) 
                                                        | ((4U 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                               >> 7U)) 
                                                           | ((2U 
                                                               & ((~ 
                                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                    >> 0xaU)) 
                                                                  << 1U)) 
                                                              | (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                     >> 0xbU))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1714(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1714\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_126 
        = ((0x800U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr)) 
                      << 0xbU)) | ((0x400U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                              << 9U)) 
                                   | ((0x200U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                 << 7U)) 
                                      | ((0x100U & 
                                          ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                               >> 3U)) 
                                           << 8U)) 
                                         | ((0x80U 
                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                << 3U)) 
                                            | ((0x40U 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                   << 1U)) 
                                               | ((0x20U 
                                                   & ((~ 
                                                       ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                        >> 6U)) 
                                                      << 5U)) 
                                                  | ((0x10U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                         >> 3U)) 
                                                     | ((8U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                            >> 5U)) 
                                                        | ((4U 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                               >> 7U)) 
                                                           | ((2U 
                                                               & ((~ 
                                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                    >> 0xaU)) 
                                                                  << 1U)) 
                                                              | (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                     >> 0xbU))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_128 
        = ((0x800U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                      << 0xbU)) | ((0x400U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                              << 9U)) 
                                   | ((0x200U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                 << 7U)) 
                                      | ((0x100U & 
                                          ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                               >> 3U)) 
                                           << 8U)) 
                                         | ((0x80U 
                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                << 3U)) 
                                            | ((0x40U 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                   << 1U)) 
                                               | ((0x20U 
                                                   & ((~ 
                                                       ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                        >> 6U)) 
                                                      << 5U)) 
                                                  | ((0x10U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                         >> 3U)) 
                                                     | ((8U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                            >> 5U)) 
                                                        | ((4U 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                               >> 7U)) 
                                                           | ((2U 
                                                               & ((~ 
                                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                    >> 0xaU)) 
                                                                  << 1U)) 
                                                              | (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                     >> 0xbU))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1715(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1715\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_4 
        = ((0x800U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                      << 0xbU)) | ((0x400U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                              << 9U)) 
                                   | ((0x200U & ((~ 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                   >> 2U)) 
                                                 << 9U)) 
                                      | ((0x100U & 
                                          ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                               >> 3U)) 
                                           << 8U)) 
                                         | ((0x80U 
                                             & ((~ 
                                                 ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                  >> 4U)) 
                                                << 7U)) 
                                            | ((0x40U 
                                                & ((~ 
                                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                     >> 5U)) 
                                                   << 6U)) 
                                               | ((0x20U 
                                                   & ((~ 
                                                       ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                        >> 6U)) 
                                                      << 5U)) 
                                                  | ((0x10U 
                                                      & ((~ 
                                                          ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                           >> 7U)) 
                                                         << 4U)) 
                                                     | ((8U 
                                                         & ((~ 
                                                             ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                              >> 8U)) 
                                                            << 3U)) 
                                                        | ((4U 
                                                            & ((~ 
                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                 >> 9U)) 
                                                               << 2U)) 
                                                           | ((2U 
                                                               & ((~ 
                                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                    >> 0xaU)) 
                                                                  << 1U)) 
                                                              | (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                     >> 0xbU))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T 
        = ((0x400U & ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                          >> 1U)) << 0xaU)) | ((0x200U 
                                                & ((~ 
                                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                     >> 2U)) 
                                                   << 9U)) 
                                               | ((0x100U 
                                                   & ((~ 
                                                       ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                        >> 3U)) 
                                                      << 8U)) 
                                                  | ((0x80U 
                                                      & ((~ 
                                                          ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                           >> 4U)) 
                                                         << 7U)) 
                                                     | ((0x40U 
                                                         & ((~ 
                                                             ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                              >> 5U)) 
                                                            << 6U)) 
                                                        | ((0x20U 
                                                            & ((~ 
                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                 >> 6U)) 
                                                               << 5U)) 
                                                           | ((0x10U 
                                                               & ((~ 
                                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                    >> 7U)) 
                                                                  << 4U)) 
                                                              | ((8U 
                                                                  & ((~ 
                                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                       >> 8U)) 
                                                                     << 3U)) 
                                                                 | ((4U 
                                                                     & ((~ 
                                                                         ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                          >> 9U)) 
                                                                        << 2U)) 
                                                                    | ((2U 
                                                                        & ((~ 
                                                                            ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                             >> 0xaU)) 
                                                                           << 1U)) 
                                                                       | (1U 
                                                                          & (~ 
                                                                             ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                                                                              >> 0xbU)))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1716(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1716\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__insn_ret 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_cmd)) 
           & (IData)((0x100U == (0xdfcU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__insn_call 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_cmd)) 
           & (IData)((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1717(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1717\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__insn_break 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_cmd)) 
           & (IData)((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_6 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_258)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_335));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_7 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_258) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_335));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_set_sboard 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_div) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_dcache_miss));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_wen 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_typeTag)
                  ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_killed))
                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__rawOutValid) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_killed)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1718(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1718\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_inFlight 
        = (1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_killed)) 
                 & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__inReady)) 
                    | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__inReady)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_fpu_fcsr_rm 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1875)
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_frm_shadow)
            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_frm));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ex_rs_T_5 
        = (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_1[
                            (((IData)(0x3fU) + (0xffU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_lsb_0) 
                                                   << 6U))) 
                             >> 5U)])) << ((0U == (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_lsb_0) 
                                                      << 6U)))
                                            ? 0x20U
                                            : ((IData)(0x40U) 
                                               - (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_lsb_0) 
                                                     << 6U))))) 
           | (((0U == (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_lsb_0) 
                                << 6U))) ? 0ULL : ((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_1[
                                                                   (((IData)(0x1fU) 
                                                                     + 
                                                                     (0xffU 
                                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_lsb_0) 
                                                                         << 6U))) 
                                                                    >> 5U)])) 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_lsb_0) 
                                                        << 6U))))) 
              | ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_1[
                                 (6U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_lsb_0) 
                                        << 1U))])) 
                 >> (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_lsb_0) 
                              << 6U)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ex_rs_T_12 
        = (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_1[
                            (((IData)(0x3fU) + (0xffU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_lsb_1) 
                                                   << 6U))) 
                             >> 5U)])) << ((0U == (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_lsb_1) 
                                                      << 6U)))
                                            ? 0x20U
                                            : ((IData)(0x40U) 
                                               - (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_lsb_1) 
                                                     << 6U))))) 
           | (((0U == (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_lsb_1) 
                                << 6U))) ? 0ULL : ((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_1[
                                                                   (((IData)(0x1fU) 
                                                                     + 
                                                                     (0xffU 
                                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_lsb_1) 
                                                                         << 6U))) 
                                                                    >> 5U)])) 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_lsb_1) 
                                                        << 6U))))) 
              | ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_1[
                                 (6U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_lsb_1) 
                                        << 1U))])) 
                 >> (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_lsb_1) 
                              << 6U)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__replay_wb_lsl 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)) 
           & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_io_resp_replay) 
               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_resp_replay_csr)) 
              | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_resp_replay_rocc)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_fpu_dmem_resp_val 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__dmem_resp_valid) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__dmem_resp_fpu));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_req_valid_csr_test_T 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__dmem_resp_valid) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__dmem_resp_xpu));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__dmem_resp_replay 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode))
            ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__dmem_resp_valid) 
               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_io_resp_replay))
            : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__dmem_resp_valid) 
               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__doUncachedResp)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_cause 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_xcpt)
            ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_cause
            : (QData)((IData)(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_103)
                                ? 0xfU : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_109)
                                           ? 0xdU : 
                                          ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_115)
                                            ? 0x17U
                                            : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_121)
                                                ? 0x15U
                                                : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_127)
                                                    ? 7U
                                                    : 
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_133)
                                                     ? 5U
                                                     : 
                                                    (4U 
                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_139) 
                                                        << 1U)))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1719(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1719\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_xcpt 
        = (((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_xcpt) 
                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_103)) 
                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_109)) 
                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_115)) 
               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_121)) 
              | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_127)) 
             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_133)) 
            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_139)) 
           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_140) 
               & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)))) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_xcpt_ma_ld_output)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__id_mem_busy 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_req_valid)
            : ((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_valid) 
                   & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_no_xcpt))) 
                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_no_xcpt)))) 
                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__cached_grant_wait)) 
                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__uncachedInFlight_0)) 
               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___io_dmem_req_valid_output)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_req_valid 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___ptw_io_mem_req_valid) 
            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___io_dmem_req_valid_output));
    if ((3U != (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__inst 
            = (0xffffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst);
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___io_inst_0_bits_xcpt1_WIRE_1 = 0U;
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__inst 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___io_inst_0_bits_xcpt1_WIRE_1 
            = ((((2U & (((IData)(1U) << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__nBufValid)) 
                        - (IData)(1U))) ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__buf_xcpt_pf_inst)
                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_xcpt_pf_inst)) 
                << 2U) | ((((2U & (((IData)(1U) << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__nBufValid)) 
                                   - (IData)(1U))) ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__buf_xcpt_gf_inst)
                             : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_xcpt_gf_inst)) 
                           << 1U) | ((2U & (((IData)(1U) 
                                             << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__nBufValid)) 
                                            - (IData)(1U)))
                                      ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__buf_xcpt_ae_inst)
                                      : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_xcpt_ae_inst))));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___T_23 
        = (1U & ((((3U & ((IData)(1U) << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__nBufValid))) 
                   - (IData)(1U)) & (3U != (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst))) 
                 | (1U & ((((IData)(1U) << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__nBufValid)) 
                           - (IData)(1U)) >> 1U))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1720(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1720\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h7c937d55__0;
    VlWide<3>/*95:0*/ __Vtemp_h06c8d1f4__0;
    // Body
    __Vtemp_h7c937d55__0[0U] = (IData)((((QData)((IData)(
                                                         (0x1fU 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                             >> 7U)))) 
                                         << 0x37U) 
                                        | (((QData)((IData)(
                                                            (0x1fU 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                >> 7U)))) 
                                            << 0x32U) 
                                           | (((QData)((IData)(
                                                               (0x1fU 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                   >> 7U)))) 
                                               << 0x2dU) 
                                              | (((QData)((IData)(
                                                                  (0x1fU 
                                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                      >> 7U)))) 
                                                  << 0x28U) 
                                                 | (((QData)((IData)(
                                                                     (0x1fU 
                                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                         >> 7U)))) 
                                                     << 0x23U) 
                                                    | (((QData)((IData)(
                                                                        (0x1fU 
                                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                            >> 7U)))) 
                                                        << 0x1eU) 
                                                       | (QData)((IData)(
                                                                         ((0x3e000000U 
                                                                           & (((0x1000U 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst)
                                                                                ? 
                                                                               ((0U 
                                                                                != 
                                                                                (0x1fU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U)))
                                                                                 ? 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 7U)
                                                                                 : 1U)
                                                                                : 
                                                                               ((0U 
                                                                                != 
                                                                                (0x1fU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U)))
                                                                                 ? 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 7U)
                                                                                 : 0U)) 
                                                                              << 0x19U)) 
                                                                          | ((0x1f00000U 
                                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                << 0xdU)) 
                                                                             | ((0xf8000U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                << 8U)) 
                                                                                | ((0x7c00U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                << 3U)) 
                                                                                | (0x3e0U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U)))))))))))))));
    __Vtemp_h7c937d55__0[1U] = ((0xf0000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                << 0x15U)) 
                                | (IData)(((((QData)((IData)(
                                                             (0x1fU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                 >> 7U)))) 
                                             << 0x37U) 
                                            | (((QData)((IData)(
                                                                (0x1fU 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                    >> 7U)))) 
                                                << 0x32U) 
                                               | (((QData)((IData)(
                                                                   (0x1fU 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                       >> 7U)))) 
                                                   << 0x2dU) 
                                                  | (((QData)((IData)(
                                                                      (0x1fU 
                                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                          >> 7U)))) 
                                                      << 0x28U) 
                                                     | (((QData)((IData)(
                                                                         (0x1fU 
                                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                             >> 7U)))) 
                                                         << 0x23U) 
                                                        | (((QData)((IData)(
                                                                            (0x1fU 
                                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 7U)))) 
                                                            << 0x1eU) 
                                                           | (QData)((IData)(
                                                                             ((0x3e000000U 
                                                                               & (((0x1000U 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst)
                                                                                 ? 
                                                                                ((0U 
                                                                                != 
                                                                                (0x1fU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U)))
                                                                                 ? 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 7U)
                                                                                 : 1U)
                                                                                 : 
                                                                                ((0U 
                                                                                != 
                                                                                (0x1fU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U)))
                                                                                 ? 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 7U)
                                                                                 : 0U)) 
                                                                                << 0x19U)) 
                                                                              | ((0x1f00000U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                << 0xdU)) 
                                                                                | ((0xf8000U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                << 8U)) 
                                                                                | ((0x7c00U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                << 3U)) 
                                                                                | (0x3e0U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U)))))))))))))) 
                                           >> 0x20U)));
    __Vtemp_h06c8d1f4__0[0U] = (IData)((((QData)((IData)(
                                                         (7U 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                             >> 7U)))) 
                                         << 0x3cU) 
                                        | (((QData)((IData)(
                                                            (0x1fU 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                >> 7U)))) 
                                            << 0x37U) 
                                           | (((QData)((IData)(
                                                               (0x1fU 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                   >> 7U)))) 
                                               << 0x32U) 
                                              | (((QData)((IData)(
                                                                  (0x1fU 
                                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                      >> 7U)))) 
                                                  << 0x2dU) 
                                                 | (((QData)((IData)(
                                                                     (0x1fU 
                                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                         >> 7U)))) 
                                                     << 0x28U) 
                                                    | (0xffffffffffULL 
                                                       & (((QData)((IData)(
                                                                           (8U 
                                                                            | (7U 
                                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U))))) 
                                                           << 0x23U) 
                                                          | (((QData)((IData)(
                                                                              (8U 
                                                                               | (7U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U))))) 
                                                              << 0x1eU) 
                                                             | (((QData)((IData)(
                                                                                (8U 
                                                                                | (7U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U))))) 
                                                                 << 0x19U) 
                                                                | (((QData)((IData)(
                                                                                (8U 
                                                                                | (7U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U))))) 
                                                                    << 0x14U) 
                                                                   | (((QData)((IData)(
                                                                                (8U 
                                                                                | (7U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U))))) 
                                                                       << 0xfU) 
                                                                      | (((QData)((IData)(
                                                                                (8U 
                                                                                | (7U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U))))) 
                                                                          << 0xaU) 
                                                                         | (((QData)((IData)(
                                                                                (8U 
                                                                                | (7U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U))))) 
                                                                             << 5U) 
                                                                            | (QData)((IData)(
                                                                                (8U 
                                                                                | (7U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U)))))))))))))))))));
    __Vtemp_h06c8d1f4__0[1U] = (0x80000000U | (IData)(
                                                      ((((QData)((IData)(
                                                                         (7U 
                                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                             >> 7U)))) 
                                                         << 0x3cU) 
                                                        | (((QData)((IData)(
                                                                            (0x1fU 
                                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 7U)))) 
                                                            << 0x37U) 
                                                           | (((QData)((IData)(
                                                                               (0x1fU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 7U)))) 
                                                               << 0x32U) 
                                                              | (((QData)((IData)(
                                                                                (0x1fU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 7U)))) 
                                                                  << 0x2dU) 
                                                                 | (((QData)((IData)(
                                                                                (0x1fU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 7U)))) 
                                                                     << 0x28U) 
                                                                    | (0xffffffffffULL 
                                                                       & (((QData)((IData)(
                                                                                (8U 
                                                                                | (7U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U))))) 
                                                                           << 0x23U) 
                                                                          | (((QData)((IData)(
                                                                                (8U 
                                                                                | (7U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U))))) 
                                                                              << 0x1eU) 
                                                                             | (((QData)((IData)(
                                                                                (8U 
                                                                                | (7U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U))))) 
                                                                                << 0x19U) 
                                                                                | (((QData)((IData)(
                                                                                (8U 
                                                                                | (7U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U))))) 
                                                                                << 0x14U) 
                                                                                | (((QData)((IData)(
                                                                                (8U 
                                                                                | (7U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U))))) 
                                                                                << 0xfU) 
                                                                                | (((QData)((IData)(
                                                                                (8U 
                                                                                | (7U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U))))) 
                                                                                << 0xaU) 
                                                                                | (((QData)((IData)(
                                                                                (8U 
                                                                                | (7U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U))))) 
                                                                                << 5U) 
                                                                                | (QData)((IData)(
                                                                                (8U 
                                                                                | (7U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U)))))))))))))))))) 
                                                       >> 0x20U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___GEN_2[0U] 
        = __Vtemp_h06c8d1f4__0[0U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___GEN_2[1U] 
        = __Vtemp_h06c8d1f4__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___GEN_2[2U] 
        = (0x200U | ((__Vtemp_h7c937d55__0[0U] << 0xbU) 
                     | (0x1c0U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                  >> 1U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___GEN_2[3U] 
        = ((1U & (__Vtemp_h7c937d55__0[0U] >> 0x15U)) 
           | ((0x7feU & (__Vtemp_h7c937d55__0[0U] >> 0x15U)) 
              | (__Vtemp_h7c937d55__0[1U] << 0xbU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___GEN_2[4U] 
        = ((1U & (__Vtemp_h7c937d55__0[1U] >> 0x15U)) 
           | ((0x7feU & (__Vtemp_h7c937d55__0[1U] >> 0x15U)) 
              | ((0xf8000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                 << 0x14U)) | ((0x7c00000U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                   << 0xfU)) 
                                               | ((0x3e0000U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                      << 0xaU)) 
                                                  | ((0x1f000U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                         << 5U)) 
                                                     | (0x800U 
                                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst)))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1721(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1721\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h0185eab8__0;
    VlWide<3>/*95:0*/ __Vtemp_h0e442cad__0;
    VlWide<4>/*127:0*/ __Vtemp_h617862da__0;
    VlWide<4>/*127:0*/ __Vtemp_hd553d87b__0;
    VlWide<5>/*159:0*/ __Vtemp_h562f39f1__0;
    VlWide<5>/*159:0*/ __Vtemp_hff853c60__0;
    VlWide<5>/*159:0*/ __Vtemp_hd22088fc__0;
    // Body
    __Vtemp_h0185eab8__0[0U] = (IData)((0x1080000000ULL 
                                        | (((QData)((IData)(
                                                            (0x1fU 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                >> 0xfU)))) 
                                            << 0x37U) 
                                           | (((QData)((IData)(
                                                               (0x1fU 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                   >> 0xfU)))) 
                                               << 0x32U) 
                                              | (((QData)((IData)(
                                                                  (0x1fU 
                                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                      >> 0xfU)))) 
                                                  << 0x2dU) 
                                                 | (((QData)((IData)(
                                                                     (0x1fU 
                                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                         >> 0xfU)))) 
                                                     << 0x28U) 
                                                    | (QData)((IData)(
                                                                      (0x4010840U 
                                                                       | ((((1U 
                                                                             & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 0xcU) 
                                                                                | (~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1fU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U)))))))
                                                                             ? 
                                                                            (0x1fU 
                                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 7U))
                                                                             : 0U) 
                                                                           << 0x14U) 
                                                                          | (0x1fU 
                                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 7U))))))))))));
    __Vtemp_h0185eab8__0[1U] = ((0xf0000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                << 0xdU)) 
                                | (IData)(((0x1080000000ULL 
                                            | (((QData)((IData)(
                                                                (0x1fU 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                    >> 0xfU)))) 
                                                << 0x37U) 
                                               | (((QData)((IData)(
                                                                   (0x1fU 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                       >> 0xfU)))) 
                                                   << 0x32U) 
                                                  | (((QData)((IData)(
                                                                      (0x1fU 
                                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                          >> 0xfU)))) 
                                                      << 0x2dU) 
                                                     | (((QData)((IData)(
                                                                         (0x1fU 
                                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                             >> 0xfU)))) 
                                                         << 0x28U) 
                                                        | (QData)((IData)(
                                                                          (0x4010840U 
                                                                           | ((((1U 
                                                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 0xcU) 
                                                                                | (~ (IData)(
                                                                                (0U 
                                                                                != 
                                                                                (0x1fU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 2U)))))))
                                                                                 ? 
                                                                                (0x1fU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 7U))
                                                                                 : 0U) 
                                                                               << 0x14U) 
                                                                              | (0x1fU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 7U))))))))))) 
                                           >> 0x20U)));
    __Vtemp_h0e442cad__0[2U] = ((0x1fU & (__Vtemp_h0185eab8__0[1U] 
                                          >> 0x11U)) 
                                | ((0x3e0U & (__Vtemp_h0185eab8__0[1U] 
                                              >> 0x11U)) 
                                   | ((0x7c00U & (__Vtemp_h0185eab8__0[1U] 
                                                  >> 0x11U)) 
                                      | ((0x7c000000U 
                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                             << 0xbU)) 
                                         | ((0x3e00000U 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                << 6U)) 
                                            | ((0x1f0000U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                   << 1U)) 
                                               | (0x8000U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                     >> 4U))))))));
    __Vtemp_h617862da__0[1U] = (0x42U | ((((0x1ffff00U 
                                            & (__Vtemp_h0185eab8__0[0U] 
                                               << 8U)) 
                                           | (0x38U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                 >> 4U))) 
                                          | (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                   >> 9U))) 
                                         | ((0x3e000000U 
                                             & (__Vtemp_h0185eab8__0[0U] 
                                                << 8U)) 
                                            | (0xc0000000U 
                                               & (__Vtemp_h0185eab8__0[0U] 
                                                  << 8U)))));
    __Vtemp_hd553d87b__0[0U] = (0x10000008U | (((0xc0000000U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                    << 0x17U)) 
                                                | ((0xe000000U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                       << 0x12U)) 
                                                   | ((0x1f00000U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                          << 0xdU)) 
                                                      | ((0x7c00U 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                             << 3U)) 
                                                         | (0x3e0U 
                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                               >> 2U)))))) 
                                               | (7U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                     >> 7U))));
    __Vtemp_hd553d87b__0[1U] = (2U | (((0x18U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                 >> 4U)) 
                                       | (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                >> 9U))) 
                                      | (__Vtemp_h617862da__0[1U] 
                                         << 5U)));
    __Vtemp_hd553d87b__0[3U] = ((0x1fU & (__Vtemp_h0e442cad__0[2U] 
                                          >> 2U)) | 
                                (0x3fffffe0U & (__Vtemp_h0e442cad__0[2U] 
                                                >> 2U)));
    __Vtemp_h562f39f1__0[2U] = ((__Vtemp_hd553d87b__0[1U] 
                                 >> 0x1bU) | ((0x3e0U 
                                               & (__Vtemp_h617862da__0[1U] 
                                                  >> 0x16U)) 
                                              | ((0x1c00U 
                                                  & (__Vtemp_h0185eab8__0[0U] 
                                                     >> 0xeU)) 
                                                 | ((0x3e000U 
                                                     & (__Vtemp_h0185eab8__0[0U] 
                                                        >> 0xeU)) 
                                                    | (__Vtemp_h0185eab8__0[1U] 
                                                       << 0x12U)))));
    __Vtemp_h562f39f1__0[3U] = (((7U & (__Vtemp_h0185eab8__0[1U] 
                                        >> 0xeU)) | 
                                 (0x18U & (__Vtemp_h0e442cad__0[2U] 
                                           << 3U))) 
                                | (__Vtemp_hd553d87b__0[3U] 
                                   << 5U));
    __Vtemp_hff853c60__0[1U] = ((0x1fU & (__Vtemp_hd553d87b__0[0U] 
                                          >> 0xcU)) 
                                | ((0x3e0U & (__Vtemp_hd553d87b__0[0U] 
                                              >> 0xcU)) 
                                   | ((0x7c00U & (__Vtemp_hd553d87b__0[0U] 
                                                  >> 0xcU)) 
                                      | ((0xf8000U 
                                          & (__Vtemp_hd553d87b__0[0U] 
                                             >> 0xcU)) 
                                         | (__Vtemp_hd553d87b__0[1U] 
                                            << 0x14U)))));
    __Vtemp_hff853c60__0[2U] = ((0x1fU & (__Vtemp_hd553d87b__0[1U] 
                                          >> 0xcU)) 
                                | ((0x3e0U & (__Vtemp_hd553d87b__0[1U] 
                                              >> 0xcU)) 
                                   | ((0x7c00U & (__Vtemp_hd553d87b__0[1U] 
                                                  >> 0xcU)) 
                                      | (__Vtemp_h562f39f1__0[2U] 
                                         << 0xfU))));
    __Vtemp_hff853c60__0[3U] = ((0x1fU & (__Vtemp_h562f39f1__0[2U] 
                                          >> 0x11U)) 
                                | ((0x3e0U & (__Vtemp_h562f39f1__0[2U] 
                                              >> 0x11U)) 
                                   | ((0x7c00U & (__Vtemp_h562f39f1__0[2U] 
                                                  >> 0x11U)) 
                                      | (__Vtemp_h562f39f1__0[3U] 
                                         << 0xfU))));
    __Vtemp_hd22088fc__0[1U] = (2U | (((0x3f8U & (__Vtemp_hd553d87b__0[0U] 
                                                  << 3U)) 
                                       | (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                >> 9U))) 
                                      | ((0x7c00U & 
                                          (__Vtemp_hd553d87b__0[0U] 
                                           << 3U)) 
                                         | (__Vtemp_hff853c60__0[1U] 
                                            << 0xfU))));
    __Vtemp_hd22088fc__0[4U] = ((0x3ffU & (__Vtemp_hff853c60__0[3U] 
                                           >> 0x11U)) 
                                | ((0x7c00U & (__Vtemp_hff853c60__0[3U] 
                                               >> 0x11U)) 
                                   | ((0xf8000U & (
                                                   __Vtemp_h562f39f1__0[3U] 
                                                   >> 2U)) 
                                      | ((0x1f00000U 
                                          & (__Vtemp_h562f39f1__0[3U] 
                                             >> 2U)) 
                                         | ((0x3e000000U 
                                             & (__Vtemp_h562f39f1__0[3U] 
                                                >> 2U)) 
                                            | (0xc0000000U 
                                               & (__Vtemp_hd553d87b__0[3U] 
                                                  << 3U)))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___GEN_3[0U] 
        = (0x10842102U | ((((((0xc0000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                              << 0x17U)) 
                              | (0xe000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                               << 0x12U))) 
                             | (0x700000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                             << 0xdU))) 
                            | (0x38000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                           << 8U))) 
                           | (0x1c00U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                         << 3U))) | 
                          (0xe0U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                    >> 2U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___GEN_3[1U] 
        = __Vtemp_hd22088fc__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___GEN_3[2U] 
        = ((0x3ffU & (__Vtemp_hff853c60__0[1U] >> 0x11U)) 
           | ((0x7c00U & (__Vtemp_hff853c60__0[1U] 
                          >> 0x11U)) | (__Vtemp_hff853c60__0[2U] 
                                        << 0xfU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___GEN_3[3U] 
        = ((0x3ffU & (__Vtemp_hff853c60__0[2U] >> 0x11U)) 
           | ((0x7c00U & (__Vtemp_hff853c60__0[2U] 
                          >> 0x11U)) | (__Vtemp_hff853c60__0[3U] 
                                        << 0xfU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___GEN_3[4U] 
        = __Vtemp_hd22088fc__0[4U];
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1722(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1722\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_s_funct_T_2 
        = ((4U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                  >> 0xaU)) | (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                     >> 5U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2 
        = ((0x18U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                     << 3U)) | (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                      >> 0xdU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_76 
        = (1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_btb_taken)) 
                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_imem_checker_mode))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__predicted_taken 
        = (1U & (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_imem_checker_mode)) 
                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT___io_resp_valid_T_84)) 
                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT___T_135))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_43 
        = (1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_btb_taken)) 
                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_imem_checker_mode))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_72 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_65) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_btb_resp_bits_bridx)) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__valid_1)) 
            & (0x30000U == (0x30000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_imem_checker_mode)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_39 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_65) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_btb_resp_bits_bridx))) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__valid)) 
            & (3U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_imem_checker_mode)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_106 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_imem_checker_mode)
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_bjl_taken)
            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_btb_taken));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__predict_taken_1 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_imem_checker_mode)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_btb_resp_bits_bht_value));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__predict_taken 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_imem_checker_mode)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_btb_resp_bits_bht_value));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1723(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1723\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_27 
        = ((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_5[2U])
            ? ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_22 
                << 1U) | (QData)((IData)((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U] 
                                                >> 0x1bU)))))
            : (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_5[1U])) 
                << 0x20U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_5[0U]))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT____Vcellinp__r_pte_barrier__io_x_v 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_5)) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_10)
               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_v)
               : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_8)
                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_v)
                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_pte_v))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT____Vcellinp__r_pte_barrier__io_x_r 
        = (1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_5)) 
                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_10)
                     ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_r)
                     : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_8)
                         ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_r)
                         : (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_data 
                                    >> 1U))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT____Vcellinp__r_pte_barrier__io_x_w 
        = (1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_5)) 
                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_10)
                     ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_w)
                     : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_8)
                         ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_w)
                         : (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_data 
                                    >> 2U))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT____Vcellinp__r_pte_barrier__io_x_x 
        = (1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_5)) 
                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_10)
                     ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_x)
                     : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_8)
                         ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_x)
                         : (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_data 
                                    >> 3U))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT____Vcellinp__r_pte_barrier__io_x_u 
        = (1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_5)) 
                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_10)
                     ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_u)
                     : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_8)
                         ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_u)
                         : (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_data 
                                    >> 4U))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1724(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1724\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT____Vcellinp__r_pte_barrier__io_x_g 
        = (1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_5)) 
                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_10)
                     ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_g)
                     : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_8)
                         ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_g)
                         : (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_data 
                                    >> 5U))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT____Vcellinp__r_pte_barrier__io_x_a 
        = (1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_5)) 
                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_10)
                     ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_a)
                     : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_8)
                         ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_a)
                         : (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_data 
                                    >> 6U))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT____Vcellinp__r_pte_barrier__io_x_d 
        = (1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_5)) 
                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_10)
                     ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_d)
                     : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_8)
                         ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_d)
                         : (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_data 
                                    >> 7U))))));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_5) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT____Vcellinp__r_pte_barrier__io_x_reserved_for_software = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT____Vcellinp__r_pte_barrier__io_x_reserved_for_future = 0U;
    } else if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_10) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT____Vcellinp__r_pte_barrier__io_x_reserved_for_software 
            = (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_reserved_for_software));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT____Vcellinp__r_pte_barrier__io_x_reserved_for_future 
            = (0x3ffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_reserved_for_future));
    } else if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_8) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT____Vcellinp__r_pte_barrier__io_x_reserved_for_software 
            = (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_reserved_for_software));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT____Vcellinp__r_pte_barrier__io_x_reserved_for_future 
            = (0x3ffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_reserved_for_future));
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT____Vcellinp__r_pte_barrier__io_x_reserved_for_software 
            = (3U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_data 
                             >> 8U)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT____Vcellinp__r_pte_barrier__io_x_reserved_for_future 
            = (0x3ffU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_data 
                                 >> 0x36U)));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_param 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__muxStateEarly_0)
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_param)
            : 0U);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_opcode 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__muxStateEarly_0)
             ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode)
             : 0U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__muxStateEarly_1) 
                      << 2U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_mask 
        = (0xffU & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__muxStateEarly_0)
                      ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_mask)
                      : 0U) | (- (IData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__muxStateEarly_1)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1725(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1725\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_data 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__muxStateEarly_0)
            ? ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_uncached) 
                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_write)) 
                & (((((((((((0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd)) 
                            | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_read))) 
                           | (0xfU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                          | (0xeU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                         | (0xdU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                        | (0xcU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                       | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                      | (0xbU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                     | (0xaU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                    | (9U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                   | (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))))
                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_data
                : 0ULL) : 0ULL);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_source 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__muxStateEarly_0)
             ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_source)
             : 0U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__muxStateEarly_1) 
                      << 1U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_size 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__muxStateEarly_0)
             ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)
             : 0U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__muxStateEarly_1)
                       ? 6U : 0U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_address 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__muxStateEarly_0)
             ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address
             : 0U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__muxStateEarly_1)
                       ? (0xffffffc0U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr)
                       : 0U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___r_farf_wb_T_13 
        = (7U & (((IData)(((0ULL == (0x7f800000ULL 
                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___r_farf_wb_T_2)) 
                           & (~ (IData)((0U != (0x7fffffU 
                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___r_farf_wb_T_2)))))))
                   ? 0U : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__r_farf_wb_rawIn_adjustedExp_1) 
                           >> 6U)) | ((3U == (3U & 
                                              ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__r_farf_wb_rawIn_adjustedExp_1) 
                                               >> 7U))) 
                                      & (0U != (0x7fffffU 
                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___r_farf_wb_T_2))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1726(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1726\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___r_farf_wb_T_6 
        = (7U & (((IData)(((0ULL == (0x7ff0000000000000ULL 
                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___r_farf_wb_T_2)) 
                           & (~ (IData)((0U != (0xfffffffffffffULL 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___r_farf_wb_T_2))))))
                   ? 0U : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__r_farf_wb_rawIn_adjustedExp) 
                           >> 9U)) | ((3U == (3U & 
                                              ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__r_farf_wb_rawIn_adjustedExp) 
                                               >> 0xaU))) 
                                      & (0U != (0xfffffffffffffULL 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___r_farf_wb_T_2)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1878 
        = ((0x3ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_6)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1887 
        = ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_8)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1890 
        = ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_14)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1893 
        = ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_16)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1896 
        = ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_18)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1899 
        = ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_20)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1881 
        = ((0x3ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_22)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1837 
        = ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_26)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1849 
        = ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_34)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1858 
        = ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_36)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1727(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1727\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1855 
        = ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_100)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1852 
        = ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_102)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1846 
        = ((0x3ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_108)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_40 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__csr_wen) 
           & (0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_148)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_41 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__csr_wen) 
            & (0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_110))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_cfg_l)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_42 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__csr_wen) 
            & (0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_110))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_l)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_43 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__csr_wen) 
            & (0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_110))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_l)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_44 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__csr_wen) 
            & (0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_110))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_l)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_45 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__csr_wen) 
            & (0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_110))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_l)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_46 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__csr_wen) 
            & (0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_110))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_l)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_47 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__csr_wen) 
            & (0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_110))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_l)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_48 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__csr_wen) 
            & (0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_110))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_l)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1869 
        = ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_2)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1875)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1728(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1728\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1871 
        = ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_2)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1875));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_124 
        = ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_114))
            ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr
            : 0U);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_125 
        = ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_116))
            ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr
            : 0U);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_126 
        = ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_118))
            ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr
            : 0U);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_127 
        = ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_120))
            ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr
            : 0U);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_128 
        = ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_122))
            ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr
            : 0U);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_129 
        = ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_124))
            ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr
            : 0U);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_130 
        = ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_126))
            ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr
            : 0U);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_131 
        = ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_128))
            ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr
            : 0U);
    if ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_4))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1874 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1875)));
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1875) {
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1876 = 1U;
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_16 
                = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_frm) 
                    << 5U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_fflags));
        } else {
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1876 = 0U;
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_16 
                = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_frm_shadow) 
                    << 5U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_fflags_shadow));
        }
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1874 = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1876 = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_16 = 0U;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1864 
        = ((0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1875)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1866 
        = ((0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1875));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1729(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1729\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_14 
        = ((0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T))
            ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1875)
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_fflags_shadow)
                : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_fflags))
            : 0U);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_33 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__insn_ret) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__check_privret_REG) 
                        & (~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__check_ret_priv))))) 
                       & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__shadow_status))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_24 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__insn_ret) 
           & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr) 
                 >> 9U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___exception_T 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__insn_call) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__insn_break));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__waddr 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_wen)
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_waddr)
            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wbInfo_0_rd));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_sboard_clr 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_wen) 
           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wen) 
              & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wbInfo_0_pipeid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_fcsr_flags_bits 
        = (0x1fU & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wb_toint_valid)
                       ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wb_toint_exc)
                       : 0U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_wen)
                                 ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_typeTag)
                                     ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___divSqrt_1_io_exceptionFlags)
                                     : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___divSqrt_io_exceptionFlags))
                                 : 0U)) | ((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wen))
                                            ? ((0x13U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wbInfo_0_pipeid))))
                                                ? (
                                                   (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__io_out_b_exc) 
                                                     << 0xfU) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___sfma_io_out_bits_exc) 
                                                        << 0xaU) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT__io_out_b_exc) 
                                                           << 5U) 
                                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__io_out_b_exc)))) 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(5U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wbInfo_0_pipeid))))
                                                : 0U)
                                            : 0U)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1730(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1730\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h92c0a17d__0;
    VlWide<3>/*95:0*/ __Vtemp_h4163c58a__0;
    VlWide<9>/*287:0*/ __Vtemp_hc225461b__0;
    VlWide<3>/*95:0*/ __Vtemp_hc9d08a06__0;
    VlWide<3>/*95:0*/ __Vtemp_h3c2ba5e2__0;
    // Body
    VL_EXTEND_WQ(65,33, __Vtemp_h92c0a17d__0, (((QData)((IData)(
                                                                ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__isNaNOut)) 
                                                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__sign_Z)))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 (((((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__sRoundedExp) 
                                                                           & (~ 
                                                                              (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__isZero_Z) 
                                                                                | VL_GTS_III(11, 0x6bU, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__sRoundedExp)))
                                                                                ? 0x1c0U
                                                                                : 0U))) 
                                                                          & (~ 
                                                                             ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__pegMinNonzeroMagOut)
                                                                               ? 0x194U
                                                                               : 0U))) 
                                                                         << 0x17U) 
                                                                        & (0xbf800000U 
                                                                           | (0x40000000U 
                                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__pegMaxFiniteMagOut)) 
                                                                                << 0x1eU)))) 
                                                                       & (0xdf800000U 
                                                                          | (0x20000000U 
                                                                             & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__notNaN_isInfOut)) 
                                                                                << 0x1dU)))) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__pegMinNonzeroMagOut)
                                                                           ? 0x6bU
                                                                           : 0U) 
                                                                         << 0x17U)) 
                                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__pegMaxFiniteMagOut)
                                                                          ? 0x17fU
                                                                          : 0U) 
                                                                        << 0x17U)) 
                                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__notNaN_isInfOut)
                                                                         ? 0x180U
                                                                         : 0U) 
                                                                       << 0x17U)) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__isNaNOut)
                                                                        ? 0x1c0U
                                                                        : 0U) 
                                                                      << 0x17U)) 
                                                                  | (0x7fffffU 
                                                                     & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__isNaNOut) 
                                                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__isZero_Z)) 
                                                                          | VL_GTS_III(11, 0x6bU, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__sRoundedExp)))
                                                                          ? 
                                                                         ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__isNaNOut) 
                                                                          << 0x16U)
                                                                          : 
                                                                         ((0x4000000U 
                                                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT___divSqrtRecFNToRaw_io_rawOut_sig)
                                                                           ? 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__roundedSig 
                                                                           >> 1U)
                                                                           : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__roundedSig)) 
                                                                        | (- (IData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__pegMaxFiniteMagOut))))))))));
    VL_EXTEND_WQ(65,33, __Vtemp_h4163c58a__0, (((QData)((IData)(
                                                                ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__isNaNOut)) 
                                                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sign)))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 (((((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__sRoundedExp) 
                                                                           & (~ 
                                                                              (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_isZero) 
                                                                                | VL_GTS_III(11, 0x6bU, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__sRoundedExp)))
                                                                                ? 0x1c0U
                                                                                : 0U))) 
                                                                          & (~ 
                                                                             ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__pegMinNonzeroMagOut)
                                                                               ? 0x194U
                                                                               : 0U))) 
                                                                         << 0x17U) 
                                                                        & (0xbf800000U 
                                                                           | (0x40000000U 
                                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__pegMaxFiniteMagOut)) 
                                                                                << 0x1eU)))) 
                                                                       & (0xdf800000U 
                                                                          | (0x20000000U 
                                                                             & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__notNaN_isInfOut)) 
                                                                                << 0x1dU)))) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__pegMinNonzeroMagOut)
                                                                           ? 0x6bU
                                                                           : 0U) 
                                                                         << 0x17U)) 
                                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__pegMaxFiniteMagOut)
                                                                          ? 0x17fU
                                                                          : 0U) 
                                                                        << 0x17U)) 
                                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__notNaN_isInfOut)
                                                                         ? 0x180U
                                                                         : 0U) 
                                                                       << 0x17U)) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__isNaNOut)
                                                                        ? 0x1c0U
                                                                        : 0U) 
                                                                      << 0x17U)) 
                                                                  | (0x7fffffU 
                                                                     & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__isNaNOut) 
                                                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_isZero)) 
                                                                          | VL_GTS_III(11, 0x6bU, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__sRoundedExp)))
                                                                          ? 
                                                                         ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__isNaNOut) 
                                                                          << 0x16U)
                                                                          : 
                                                                         ((0x4000000U 
                                                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sig)
                                                                           ? 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__roundedSig 
                                                                           >> 1U)
                                                                           : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__roundedSig)) 
                                                                        | (- (IData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__pegMaxFiniteMagOut))))))))));
    __Vtemp_hc225461b__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__io_out_b_data[0U];
    __Vtemp_hc225461b__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__io_out_b_data[1U];
    __Vtemp_hc225461b__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT__io_out_b_data[0U] 
                                 << 1U) | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__io_out_b_data[2U]);
    __Vtemp_hc225461b__0[3U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT__io_out_b_data[0U] 
                                 >> 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT__io_out_b_data[1U] 
                                              << 1U));
    __Vtemp_hc225461b__0[4U] = ((__Vtemp_h4163c58a__0[0U] 
                                 << 2U) | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT__io_out_b_data[1U] 
                                            >> 0x1fU) 
                                           | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT__io_out_b_data[2U] 
                                              << 1U)));
    __Vtemp_hc225461b__0[5U] = ((__Vtemp_h4163c58a__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h4163c58a__0[1U] 
                                              << 2U));
    __Vtemp_hc225461b__0[6U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__io_out_b_data[0U] 
                                 << 3U) | ((__Vtemp_h4163c58a__0[1U] 
                                            >> 0x1eU) 
                                           | (__Vtemp_h4163c58a__0[2U] 
                                              << 2U)));
    __Vtemp_hc225461b__0[7U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__io_out_b_data[0U] 
                                 >> 0x1dU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__io_out_b_data[1U] 
                                              << 3U));
    __Vtemp_hc225461b__0[8U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__io_out_b_data[1U] 
                                 >> 0x1dU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__io_out_b_data[2U] 
                                              << 3U));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_wen) {
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_typeTag) {
            __Vtemp_hc9d08a06__0[1U] = ((0xefefffffU 
                                         | (- (IData)(
                                                      (7U 
                                                       != 
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___divSqrt_1_io_out[1U] 
                                                        >> 0x1dU))))) 
                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___divSqrt_1_io_out[1U]);
            __Vtemp_hc9d08a06__0[2U] = ((1U | (- (IData)(
                                                         (7U 
                                                          != 
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___divSqrt_1_io_out[1U] 
                                                           >> 0x1dU))))) 
                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___divSqrt_1_io_out[2U]);
            __Vtemp_h3c2ba5e2__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___divSqrt_1_io_out[0U];
        } else {
            __Vtemp_hc9d08a06__0[1U] = __Vtemp_h92c0a17d__0[1U];
            __Vtemp_hc9d08a06__0[2U] = __Vtemp_h92c0a17d__0[2U];
            __Vtemp_h3c2ba5e2__0[0U] = __Vtemp_h92c0a17d__0[0U];
        }
    } else if ((0x103U >= (0x1ffU & ((IData)(0x41U) 
                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wbInfo_0_pipeid))))) {
        __Vtemp_hc9d08a06__0[1U] = (((0U == (0x1fU 
                                             & ((IData)(0x41U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wbInfo_0_pipeid))))
                                      ? 0U : (__Vtemp_hc225461b__0[
                                              ((IData)(2U) 
                                               + (0xfU 
                                                  & (((IData)(0x41U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wbInfo_0_pipeid)) 
                                                     >> 5U)))] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(0x41U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wbInfo_0_pipeid)))))) 
                                    | (__Vtemp_hc225461b__0[
                                       ((IData)(1U) 
                                        + (0xfU & (
                                                   ((IData)(0x41U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wbInfo_0_pipeid)) 
                                                   >> 5U)))] 
                                       >> (0x1fU & 
                                           ((IData)(0x41U) 
                                            * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wbInfo_0_pipeid)))));
        __Vtemp_hc9d08a06__0[2U] = (((0U == (0x1fU 
                                             & ((IData)(0x41U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wbInfo_0_pipeid))))
                                      ? 0U : (__Vtemp_hc225461b__0[
                                              ((IData)(3U) 
                                               + (0xfU 
                                                  & (((IData)(0x41U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wbInfo_0_pipeid)) 
                                                     >> 5U)))] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(0x41U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wbInfo_0_pipeid)))))) 
                                    | (__Vtemp_hc225461b__0[
                                       ((IData)(2U) 
                                        + (0xfU & (
                                                   ((IData)(0x41U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wbInfo_0_pipeid)) 
                                                   >> 5U)))] 
                                       >> (0x1fU & 
                                           ((IData)(0x41U) 
                                            * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wbInfo_0_pipeid)))));
        __Vtemp_h3c2ba5e2__0[0U] = (((0U == (0x1fU 
                                             & ((IData)(0x41U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wbInfo_0_pipeid))))
                                      ? 0U : (__Vtemp_hc225461b__0[
                                              ((IData)(1U) 
                                               + (0xfU 
                                                  & (((IData)(0x41U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wbInfo_0_pipeid)) 
                                                     >> 5U)))] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(0x41U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wbInfo_0_pipeid)))))) 
                                    | (__Vtemp_hc225461b__0[
                                       (0xfU & (((IData)(0x41U) 
                                                 * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wbInfo_0_pipeid)) 
                                                >> 5U))] 
                                       >> (0x1fU & 
                                           ((IData)(0x41U) 
                                            * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wbInfo_0_pipeid)))));
    } else {
        __Vtemp_hc9d08a06__0[1U] = 0U;
        __Vtemp_hc9d08a06__0[2U] = 0U;
        __Vtemp_h3c2ba5e2__0[0U] = 0U;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_25[0U] 
        = __Vtemp_h3c2ba5e2__0[0U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_25[1U] 
        = __Vtemp_hc9d08a06__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_25[2U] 
        = (1U & __Vtemp_hc9d08a06__0[2U]);
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1731(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1731\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_fcsr_flags_valid 
        = (1U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wb_toint_valid) 
                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_wen)) 
                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wen)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_inValid 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_reg_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___T_40)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_inFlight)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_nack_mem_output 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__write_port_busy) 
            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___T_40) 
               & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wen)))) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_inFlight));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma_io_in_bits_req_rm 
        = (7U & ((7U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ex_reg_inst 
                               >> 0xcU))) ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_fpu_fcsr_rm)
                  : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ex_reg_inst 
                     >> 0xcU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_rs_0 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_bypass_0)
            ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ex_rs_T_5
            : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ex_rs_T_6);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_rs_1 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_bypass_1)
            ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ex_rs_T_12
            : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ex_rs_T_13);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___id_stall_fpu_T_7 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__dmem_resp_replay) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__dmem_resp_fpu));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_173 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__dmem_resp_replay) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__dmem_resp_xpu));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__cause 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__insn_call)
            ? (QData)((IData)((0xfU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_prv) 
                                       - (IData)(8U)))))
            : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__insn_break)
                ? 3ULL : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_cause));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_gva 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_xcpt) 
           & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_xcpt)) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_hls_or_dv)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_tval 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_xcpt) 
            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__tval_any_addr) 
               | (2ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_cause)))
            ? (((QData)((IData)((1U & (((0U == (0x1ffffffU 
                                                & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_wdata 
                                                           >> 0x27U)))) 
                                        | (0x1ffffffU 
                                           == (0x1ffffffU 
                                               & (IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_wdata 
                                                          >> 0x27U)))))
                                        ? (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_wdata 
                                                   >> 0x27U))
                                        : (~ (IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_wdata 
                                                      >> 0x26U))))))) 
                << 0x27U) | (0x7fffffffffULL & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_wdata))
            : 0ULL);
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1732(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1732\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___dataArb_io_in_0_valid_T_9 
        = (1U & (((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_req_valid) 
                      & (~ ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_req_bits_cmd)) 
                            | (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_req_bits_cmd)))))) 
                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__releaseInFlight)) 
                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore_drain_on_miss_REG)));
    if ((0x9fU >= (0xffU & ((IData)(5U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rd 
            = (0x1fU & (((0U == (0x1fU & ((IData)(5U) 
                                          * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))))
                          ? 0U : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___GEN_2[
                                  (((IData)(4U) + (0xffU 
                                                   & ((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2)))) 
                                   >> 5U)] << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2)))))) 
                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___GEN_2[
                           (7U & (((IData)(5U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2)) 
                                  >> 5U))] >> (0x1fU 
                                               & ((IData)(5U) 
                                                  * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1 
            = (0x1fU & (((0U == (0x1fU & ((IData)(5U) 
                                          * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))))
                          ? 0U : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___GEN_3[
                                  (((IData)(4U) + (0xffU 
                                                   & ((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2)))) 
                                   >> 5U)] << ((IData)(0x20U) 
                                               - (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2)))))) 
                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___GEN_3[
                           (7U & (((IData)(5U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2)) 
                                  >> 5U))] >> (0x1fU 
                                               & ((IData)(5U) 
                                                  * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))))));
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rd = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1 = 0U;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_42_bits 
        = ((0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
            ? ((0x1000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst)
                ? ((0U != (0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                    >> 2U))) ? (0x33U 
                                                | ((0x1f00000U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                       << 0x12U)) 
                                                   | ((0xf8000U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                          << 8U)) 
                                                      | (0xf80U 
                                                         & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst))))
                    : ((0U != (0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                        >> 7U))) ? 
                       (0xe7U | ((0x1f00000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                << 0x12U)) 
                                 | (0xf8000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                << 8U))))
                        : (0x73U | ((0x1f00000U & (0x100000U 
                                                   | (0xfff00000U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                         << 0x12U)))) 
                                    | (0xf8000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                   << 8U))))))
                : ((0x1f00000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                  << 0x12U)) | ((0U 
                                                 != 
                                                 (0x1fU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                     >> 2U)))
                                                 ? 
                                                (0x33U 
                                                 | (0xf80U 
                                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst))
                                                 : 
                                                ((0xf8000U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                     << 8U)) 
                                                 | ((0U 
                                                     != 
                                                     (0x1fU 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                         >> 7U)))
                                                     ? 0x67U
                                                     : 0x1fU)))))
            : ((0x13U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
                ? (0x13000U | ((0x1c000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                               << 0x18U)) 
                               | ((0x2000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                 << 0xdU)) 
                                  | ((0x1800000U & 
                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                       << 0x12U)) | 
                                     ((0xf80U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst) 
                                      | ((0U != (0x1fU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                    >> 7U)))
                                          ? 3U : 0x1fU))))))
                : ((0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
                    ? (0x12000U | ((0xc000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                  << 0x18U)) 
                                   | ((0x2000000U & 
                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                        << 0xdU)) | 
                                      ((0x1c00000U 
                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                           << 0x12U)) 
                                       | ((0xf80U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst) 
                                          | ((0U != 
                                              (0x1fU 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                  >> 7U)))
                                              ? 3U : 0x1fU))))))
                    : ((0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
                        ? (0x13007U | ((0x1c000000U 
                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                           << 0x18U)) 
                                       | ((0x2000000U 
                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                              << 0xdU)) 
                                          | ((0x1800000U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                 << 0x12U)) 
                                             | (0xf80U 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst)))))
                        : ((0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
                            ? (0x1013U | ((0x2000000U 
                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                              << 0xdU)) 
                                          | ((0x1f00000U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                 << 0x12U)) 
                                             | ((0xf8000U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                    << 8U)) 
                                                | (0xf80U 
                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst)))))
                            : ((0xfU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
                                ? (0x41063U | (((- (IData)(
                                                           (1U 
                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                               >> 0xcU)))) 
                                                << 0x1cU) 
                                               | ((0xc000000U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                      << 0x15U)) 
                                                  | ((0x2000000U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                         << 0x17U)) 
                                                     | ((0x38000U 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                            << 8U)) 
                                                        | ((0xc00U 
                                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst) 
                                                           | ((0x300U 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                  << 5U)) 
                                                              | (0x80U 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                    >> 5U)))))))))
                                : ((0xeU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
                                    ? (0x40063U | (
                                                   ((- (IData)(
                                                               (1U 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                   >> 0xcU)))) 
                                                    << 0x1cU) 
                                                   | ((0xc000000U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                          << 0x15U)) 
                                                      | ((0x2000000U 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                             << 0x17U)) 
                                                         | ((0x38000U 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                << 8U)) 
                                                            | ((0xc00U 
                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst) 
                                                               | ((0x300U 
                                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                      << 5U)) 
                                                                  | (0x80U 
                                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                        >> 5U)))))))))
                                    : ((0xdU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
                                        ? (0x6fU | 
                                           ((0x80000000U 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                << 0x13U)) 
                                            | ((0x40000000U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                   << 0x16U)) 
                                               | ((0x30000000U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                      << 0x13U)) 
                                                  | ((0x8000000U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                         << 0x15U)) 
                                                     | ((0x4000000U 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                            << 0x13U)) 
                                                        | ((0x2000000U 
                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                               << 0x17U)) 
                                                           | ((0x1000000U 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                  << 0xdU)) 
                                                              | ((0xe00000U 
                                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                     << 0x12U)) 
                                                                 | (0x1ff000U 
                                                                    & ((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 0xcU)))) 
                                                                       << 0xcU)))))))))))
                                        : ((0xcU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
                                            ? ((3U 
                                                == 
                                                (3U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                    >> 0xaU)))
                                                ? (0x840433U 
                                                   | (((0U 
                                                        == 
                                                        (3U 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                            >> 5U))) 
                                                       << 0x1eU) 
                                                      | ((0x700000U 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                             << 0x12U)) 
                                                         | ((0x38000U 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                << 8U)) 
                                                            | ((((0x17U 
                                                                  >= 
                                                                  (0x1fU 
                                                                   & ((IData)(3U) 
                                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_s_funct_T_2))))
                                                                  ? 
                                                                 (7U 
                                                                  & ((0x680f80U 
                                                                      | (0x3fU 
                                                                         & (((1U 
                                                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_s_funct_T_2)) 
                                                                             << 5U) 
                                                                            | ((1U 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_s_funct_T_2)) 
                                                                               << 2U)))) 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & ((IData)(3U) 
                                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_s_funct_T_2)))))
                                                                  : 0U) 
                                                                << 0xcU) 
                                                               | ((0x380U 
                                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst) 
                                                                  | (8U 
                                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                        >> 9U))))))))
                                                : (0x13U 
                                                   | ((((2U 
                                                         == 
                                                         (3U 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                             >> 0xaU)))
                                                         ? 
                                                        (0x11dU 
                                                         | ((0x3f8000U 
                                                             & ((- (IData)(
                                                                           (1U 
                                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                               >> 0xcU)))) 
                                                                << 0xfU)) 
                                                            | ((0x7c00U 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                   << 8U)) 
                                                               | (0xe0U 
                                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                     >> 2U)))))
                                                         : 
                                                        (0x115U 
                                                         | (((1U 
                                                              == 
                                                              (3U 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                  >> 0xaU))) 
                                                             << 0x14U) 
                                                            | ((0x8000U 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                   << 3U)) 
                                                               | ((0x7c00U 
                                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                      << 8U)) 
                                                                  | (0xe0U 
                                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                        >> 2U))))))) 
                                                       << 0xaU) 
                                                      | (0x380U 
                                                         & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst))))
                                            : ((0xbU 
                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
                                                ? (
                                                   ((- (IData)(
                                                               (1U 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                   >> 0xcU)))) 
                                                    << 0x1dU) 
                                                   | (((0U 
                                                        == 
                                                        (0x1fU 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                            >> 7U))) 
                                                       | (2U 
                                                          == 
                                                          (0x1fU 
                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                              >> 7U))))
                                                       ? 
                                                      ((0x18000000U 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                           << 0x18U)) 
                                                       | ((0x4000000U 
                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                              << 0x15U)) 
                                                          | ((0x2000000U 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                 << 0x17U)) 
                                                             | ((0x1000000U 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                    << 0x12U)) 
                                                                | ((0xf8000U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                       << 8U)) 
                                                                   | ((0xf80U 
                                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst) 
                                                                      | ((IData)(
                                                                                ((0U 
                                                                                != 
                                                                                (0x7cU 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst)) 
                                                                                | (0U 
                                                                                != 
                                                                                (0x7fU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 0xcU))))))))
                                                                          ? 0x13U
                                                                          : 0x1fU)))))))
                                                       : 
                                                      (0x37U 
                                                       | ((0x1ffe0000U 
                                                           & ((- (IData)(
                                                                         (1U 
                                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                             >> 0xcU)))) 
                                                              << 0x11U)) 
                                                          | ((0x1f000U 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                 << 0xaU)) 
                                                             | ((0xf80U 
                                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst) 
                                                                | ((0U 
                                                                    == 
                                                                    ((0xfe0U 
                                                                      & ((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 0xcU)))) 
                                                                         << 5U)) 
                                                                     | (0x1fU 
                                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                           >> 2U)))) 
                                                                   << 3U)))))))
                                                : (
                                                   (0xaU 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
                                                    ? 
                                                   (0x13U 
                                                    | (((- (IData)(
                                                                   (1U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                       >> 0xcU)))) 
                                                        << 0x19U) 
                                                       | ((0x1f00000U 
                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                              << 0x12U)) 
                                                          | (0xf80U 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst))))
                                                    : 
                                                   ((9U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
                                                     ? 
                                                    (0x1bU 
                                                     | (((- (IData)(
                                                                    (1U 
                                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                        >> 0xcU)))) 
                                                         << 0x19U) 
                                                        | ((0x1f00000U 
                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                               << 0x12U)) 
                                                           | ((0xf8000U 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                  << 8U)) 
                                                              | ((0xf80U 
                                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst) 
                                                                 | ((0U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                         >> 7U))) 
                                                                    << 2U))))))
                                                     : 
                                                    ((8U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
                                                      ? 
                                                     (0x13U 
                                                      | (((- (IData)(
                                                                     (1U 
                                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                         >> 0xcU)))) 
                                                          << 0x19U) 
                                                         | ((0x1f00000U 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                << 0x12U)) 
                                                            | ((0xf8000U 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                   << 8U)) 
                                                               | (0xf80U 
                                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst)))))
                                                      : 
                                                     ((7U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
                                                       ? 
                                                      (0x843023U 
                                                       | ((0xc000000U 
                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                              << 0x15U)) 
                                                          | ((0x2000000U 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                 << 0xdU)) 
                                                             | ((0x700000U 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                    << 0x12U)) 
                                                                | ((0x38000U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                       << 8U)) 
                                                                   | (0xc00U 
                                                                      & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst))))))
                                                       : 
                                                      ((6U 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
                                                        ? 
                                                       (0x842023U 
                                                        | ((0x4000000U 
                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                               << 0x15U)) 
                                                           | ((0x2000000U 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                  << 0xdU)) 
                                                              | ((0x700000U 
                                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                     << 0x12U)) 
                                                                 | ((0x38000U 
                                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                        << 8U)) 
                                                                    | ((0xc00U 
                                                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst) 
                                                                       | (0x200U 
                                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                             << 3U))))))))
                                                        : 
                                                       ((5U 
                                                         == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
                                                         ? 
                                                        (0x843027U 
                                                         | ((0xc000000U 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                << 0x15U)) 
                                                            | ((0x2000000U 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                   << 0xdU)) 
                                                               | ((0x700000U 
                                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                      << 0x12U)) 
                                                                  | ((0x38000U 
                                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                         << 8U)) 
                                                                     | (0xc00U 
                                                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst))))))
                                                         : 
                                                        ((4U 
                                                          == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
                                                          ? 
                                                         (0x84203fU 
                                                          | ((0x4000000U 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                 << 0x15U)) 
                                                             | ((0x2000000U 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                    << 0xdU)) 
                                                                | ((0x700000U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                       << 0x12U)) 
                                                                   | ((0x38000U 
                                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                          << 8U)) 
                                                                      | ((0xc00U 
                                                                          & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst) 
                                                                         | (0x200U 
                                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                               << 3U))))))))
                                                          : 
                                                         ((3U 
                                                           == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
                                                           ? 
                                                          (0x43403U 
                                                           | ((0xc000000U 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                  << 0x15U)) 
                                                              | ((0x3800000U 
                                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                     << 0xdU)) 
                                                                 | ((0x38000U 
                                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                        << 8U)) 
                                                                    | (0x380U 
                                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                          << 5U))))))
                                                           : 
                                                          ((2U 
                                                            == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
                                                            ? 
                                                           (0x42403U 
                                                            | ((0x4000000U 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                   << 0x15U)) 
                                                               | ((0x3800000U 
                                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                      << 0xdU)) 
                                                                  | ((0x400000U 
                                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                         << 0x10U)) 
                                                                     | ((0x38000U 
                                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                            << 8U)) 
                                                                        | (0x380U 
                                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                              << 5U)))))))
                                                            : 
                                                           ((1U 
                                                             == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
                                                             ? 
                                                            (0x43407U 
                                                             | ((0xc000000U 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                    << 0x15U)) 
                                                                | ((0x3800000U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                       << 0xdU)) 
                                                                   | ((0x38000U 
                                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                          << 8U)) 
                                                                      | (0x380U 
                                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                            << 5U))))))
                                                             : 
                                                            (0x10400U 
                                                             | ((0x3c000000U 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                    << 0x13U)) 
                                                                | ((0x3000000U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                       << 0xdU)) 
                                                                   | ((0x800000U 
                                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                          << 0x12U)) 
                                                                      | ((0x400000U 
                                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                             << 0x10U)) 
                                                                         | ((0x380U 
                                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                << 5U)) 
                                                                            | ((0U 
                                                                                != 
                                                                                (0xffU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                                                >> 5U)))
                                                                                ? 0x13U
                                                                                : 0x1fU)))))))))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1733(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1733\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___GEN_1 
        = ((((((((0x1fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2)) 
                 | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))) 
                | (0x1dU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))) 
               | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))) 
              | (0x1bU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))) 
             | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))) 
            | (0x19U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))) 
           | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s0_speculative 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_speculative) 
            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_valid) 
               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_speculative)))) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__predicted_taken));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__fq__io_enq_bits_replay 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_72) 
              | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_39)) 
             | (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___s2_tag_disparity_T))) 
            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_s2_kill_T_2) 
                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_valid))) 
               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_xcpt)))) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___fq_io_enq_bits_replay_T_5));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__predictBranch_1 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__predict_taken_1) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_88) 
              | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_89)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__taken_1 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__prevRVI_1) 
            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___hasCF_this_idx_T_8) 
               | ((0x63U == (0x7fU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data)) 
                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__predict_taken_1)))) 
           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__valid_1) 
              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___hasCF_this_idx_T_11) 
                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__rvcJR_1)) 
                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__rvcBranch_1) 
                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__predict_taken_1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__predictBranch 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__predict_taken) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_55) 
              | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_56)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__taken 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__prevRVI) 
            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___hasCF_this_idx_T) 
               | ((0x63U == (0x7fU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_partial_insn))) 
                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__predict_taken)))) 
           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__valid) 
              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___hasCF_this_idx_T_3) 
                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__rvcJR)) 
                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__rvcBranch) 
                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__predict_taken)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1734(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1734\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_hf69d571c__0;
    VlWide<3>/*95:0*/ __Vtemp_he036b953__0;
    VlWide<3>/*95:0*/ __Vtemp_ha1df588f__0;
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_1_reset) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__lfsr_prng__DOT__state_2 = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0_prng__DOT__state_2 = 0U;
    } else {
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__lfsr_prng__io_increment) {
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__lfsr_prng__DOT__state_2 
                = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__lfsr_prng__DOT__state_1;
        }
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___refill_fire_T) {
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0_prng__DOT__state_2 
                = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0_prng__DOT__state_1;
        }
    }
    __Vtemp_hf69d571c__0[0U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_27) 
                                 << 1U) | (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U] 
                                                 >> 0x1aU)));
    __Vtemp_hf69d571c__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_27) 
                                 >> 0x1fU) | ((IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_27 
                                                       >> 0x20U)) 
                                              << 1U));
    __Vtemp_hf69d571c__0[2U] = ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_27 
                                         >> 0x20U)) 
                                >> 0x1fU);
    VL_EXTEND_WQ(65,64, __Vtemp_he036b953__0, (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__divisor[1U])) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__divisor[0U]))));
    VL_SUB_W(3, __Vtemp_ha1df588f__0, __Vtemp_hf69d571c__0, __Vtemp_he036b953__0);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_6[0U] 
        = __Vtemp_ha1df588f__0[0U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_6[1U] 
        = __Vtemp_ha1df588f__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_6[2U] 
        = (1U & __Vtemp_ha1df588f__0[2U]);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT__mask_eq_2 
        = (IData)((0U == (6U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_address)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT__mask_eq_3 
        = (IData)((2U == (6U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_address)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT__mask_eq_4 
        = (IData)((4U == (6U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_address)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT__mask_eq_5 
        = (IData)((6U == (6U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_address)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT__mask_acc 
        = ((2U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_size)) 
           | ((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_size))) 
              & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_address 
                    >> 2U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT__mask_acc_1 
        = ((2U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_size)) 
           | ((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_size))) 
              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_address 
                 >> 2U)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1735(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1735\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_25 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1864) 
                 | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1866))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_22 
        = (7U & ((((((((((((((((IData)((0xf14U == (0xffcU 
                                                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr))))
                                ? 1U : 0U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_14)) 
                             | ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_2))
                                 ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1875)
                                     ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_frm_shadow)
                                     : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_frm))
                                 : 0U)) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_16)) 
                           | ((0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_40))
                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mcountinhibit)
                               : 0U)) | ((0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_38))
                                          ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mcounteren
                                          : 0U)) | 
                         ((0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_12))
                           ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_scounteren
                           : 0U)) | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_124) 
                       | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_125) 
                      | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_126) 
                     | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_127) 
                    | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_128) 
                   | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_129) 
                  | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_130) 
                 | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_131));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1736(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1736\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_trace_0_exception_output 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___exception_T) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_xcpt));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___csr_io_eret 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___exception_T) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__insn_ret));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___reg_fflags_shadow_T_1 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_fflags_shadow) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_fcsr_flags_bits));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1833 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_fcsr_flags_valid) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1875)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1835 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_fcsr_flags_valid) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1875));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__entering 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__inReady) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_inValid) 
              & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_typeTagOut))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__entering 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__inReady) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_inValid) 
              & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_typeTagOut))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_fpu_inflight 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_inFlight) 
             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_inValid)) 
            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_wen)) 
           | (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wen)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__fpu_kill_mem 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_fp)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_nack_mem_output));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__lhs_sign 
        = (1U & (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn)) 
                  | (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___decoded_T_2))) 
                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_dw)
                     ? (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_rs_0 
                                >> 0x3fU)) : (IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_rs_0 
                                                      >> 0x1fU)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__alu__io_in1 
        = ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_alu1))
            ? (((QData)((IData)((0xffffffU & (- (IData)(
                                                        (1U 
                                                         & (IData)(
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_pc 
                                                                    >> 0x27U)))))))) 
                << 0x28U) | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_pc)
            : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_alu1))
                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_rs_0
                : 0ULL));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1737(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1737\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_h603e5b60__0;
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__rhs_sign 
        = (1U & (((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___decoded_T_2)) 
                  | (IData)((4U == (5U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn))))) 
                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_dw)
                     ? (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_rs_1 
                                >> 0x3fU)) : (IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_rs_1 
                                                      >> 0x1fU)))));
    __Vtemp_h603e5b60__0[2U] = (IData)((((- (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_imm_sign))) 
                                         << 0x1fU) 
                                        | (QData)((IData)(
                                                          ((0x7ff00000U 
                                                            & (((2U 
                                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm))
                                                                 ? 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                                 >> 0x14U)
                                                                 : 
                                                                (- (IData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_imm_sign)))) 
                                                               << 0x14U)) 
                                                           | ((0xff000U 
                                                               & ((((2U 
                                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm)) 
                                                                    & (3U 
                                                                       != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm)))
                                                                    ? 
                                                                   (- (IData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_imm_sign)))
                                                                    : 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                                    >> 0xcU)) 
                                                                  << 0xcU)) 
                                                              | ((0x800U 
                                                                  & (((~ 
                                                                       ((2U 
                                                                         == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm)) 
                                                                        | (5U 
                                                                           == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm)))) 
                                                                      & ((3U 
                                                                          == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm))
                                                                          ? 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                                          >> 0x14U)
                                                                          : 
                                                                         ((1U 
                                                                           == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm))
                                                                           ? 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                                           >> 7U)
                                                                           : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_imm_sign)))) 
                                                                     << 0xbU)) 
                                                                 | (((((2U 
                                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm)) 
                                                                       | (5U 
                                                                          == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm)))
                                                                       ? 0U
                                                                       : 
                                                                      (0x3fU 
                                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                                          >> 0x19U))) 
                                                                     << 5U) 
                                                                    | ((((2U 
                                                                          == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm))
                                                                          ? 0U
                                                                          : 
                                                                         (0xfU 
                                                                          & (((0U 
                                                                               == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm)) 
                                                                              | (1U 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm)))
                                                                              ? 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                                              >> 8U)
                                                                              : 
                                                                             ((5U 
                                                                               == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm))
                                                                               ? 
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                                               >> 0x10U)
                                                                               : 
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                                               >> 0x15U))))) 
                                                                        << 1U) 
                                                                       | (1U 
                                                                          & ((0U 
                                                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm))
                                                                              ? 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                                              >> 7U)
                                                                              : 
                                                                             ((4U 
                                                                               == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm))
                                                                               ? 
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                                               >> 0x14U)
                                                                               : 
                                                                              ((5U 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm)) 
                                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                                                >> 0xfU))))))))))))));
    __Vtemp_h603e5b60__0[3U] = (IData)(((((- (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_imm_sign))) 
                                          << 0x1fU) 
                                         | (QData)((IData)(
                                                           ((0x7ff00000U 
                                                             & (((2U 
                                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm))
                                                                  ? 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                                  >> 0x14U)
                                                                  : 
                                                                 (- (IData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_imm_sign)))) 
                                                                << 0x14U)) 
                                                            | ((0xff000U 
                                                                & ((((2U 
                                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm)) 
                                                                     & (3U 
                                                                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm)))
                                                                     ? 
                                                                    (- (IData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_imm_sign)))
                                                                     : 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                                     >> 0xcU)) 
                                                                   << 0xcU)) 
                                                               | ((0x800U 
                                                                   & (((~ 
                                                                        ((2U 
                                                                          == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm)) 
                                                                         | (5U 
                                                                            == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm)))) 
                                                                       & ((3U 
                                                                           == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm))
                                                                           ? 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                                           >> 0x14U)
                                                                           : 
                                                                          ((1U 
                                                                            == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm))
                                                                            ? 
                                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                                            >> 7U)
                                                                            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_imm_sign)))) 
                                                                      << 0xbU)) 
                                                                  | (((((2U 
                                                                         == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm)) 
                                                                        | (5U 
                                                                           == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm)))
                                                                        ? 0U
                                                                        : 
                                                                       (0x3fU 
                                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                                           >> 0x19U))) 
                                                                      << 5U) 
                                                                     | ((((2U 
                                                                           == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm))
                                                                           ? 0U
                                                                           : 
                                                                          (0xfU 
                                                                           & (((0U 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm)) 
                                                                               | (1U 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm)))
                                                                               ? 
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                                               >> 8U)
                                                                               : 
                                                                              ((5U 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm))
                                                                                ? 
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                                                >> 0x10U)
                                                                                : 
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                                                >> 0x15U))))) 
                                                                         << 1U) 
                                                                        | (1U 
                                                                           & ((0U 
                                                                               == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm))
                                                                               ? 
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                                               >> 7U)
                                                                               : 
                                                                              ((4U 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm))
                                                                                ? 
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                                                >> 0x14U)
                                                                                : 
                                                                               ((5U 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm)) 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                                                >> 0xfU))))))))))))) 
                                        >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_2[0U] = 0U;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_2[1U] = 0U;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_2[2U] 
        = (IData)((QData)((IData)(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rvc)
                                    ? 2U : 4U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_2[3U] 
        = (IData)(((QData)((IData)(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rvc)
                                     ? 2U : 4U))) >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_2[4U] 
        = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_rs_1);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_2[5U] 
        = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_rs_1 
                   >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_2[6U] 
        = __Vtemp_h603e5b60__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_2[7U] 
        = __Vtemp_h603e5b60__0[3U];
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1738(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1738\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__do_deq 
        = (1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_173)) 
                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__empty))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_req_valid_rocc_T 
        = (1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_173)) 
                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__empty))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__delegate 
        = (1U & ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_prv) 
                     >> 1U)) & ((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__cause 
                                               >> 0x3fU)))
                                 ? (IData)(VL_SHIFTR_QQQ(64,64,64, 
                                                         (0x2222ULL 
                                                          & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mideleg), (QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__cause))))))
                                 : (IData)(VL_SHIFTR_QQQ(64,64,64, 
                                                         (0xf0b55dULL 
                                                          & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_medeleg), (QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__cause)))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_in_0_bits_write 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore_drain_structural) 
           | (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___dataArb_io_in_0_valid_T_4) 
                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_held)) 
                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_rmw_r))) 
               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_valid)) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___dataArb_io_in_0_valid_T_9)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_in_0_valid 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore_drain_structural) 
           | (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___dataArb_io_in_0_valid_T_4) 
                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_held)) 
                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_rmw_r))) 
               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_valid)) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___dataArb_io_in_0_valid_T_9)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_wb_T_7 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rd) 
           == (0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                        >> 7U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_ex_T_7 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rd) 
           == (0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                        >> 7U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_mem_T_7 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rd) 
           == (0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                        >> 7U)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1739(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1739\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___rf_ext_R0_data 
        = ((0x1eU >= (0x1fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1))))
            ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
           [(0x1fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1)))]
            : 0ULL);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_wb_T_1 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1) 
           == (0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                        >> 7U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_ex_T_1 
        = ((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                     >> 7U)) == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_mem_T_1 
        = ((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                     >> 7U)) == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___GEN_1) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2 
            = (0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                        >> 0x14U));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst;
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2 
            = (0x1fU & (((((((((0x17U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2)) 
                               | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))) 
                              | (0x15U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))) 
                             | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))) 
                            | (0x13U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))) 
                           | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))) 
                          | (0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))) 
                         | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2)))
                         ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                            >> 2U) : (((0xfU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2)) 
                                       | (0xeU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2)))
                                       ? 0U : (8U | 
                                               (7U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                   >> 2U))))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
            = ((0x17U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
                ? (0x13023U | ((0x1c000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                               << 0x13U)) 
                               | ((0x2000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                 << 0xdU)) 
                                  | ((0x1f00000U & 
                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                       << 0x12U)) | 
                                     (0xc00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst)))))
                : ((0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
                    ? (0x12023U | ((0xc000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                  << 0x13U)) 
                                   | ((0x2000000U & 
                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                        << 0xdU)) | 
                                      ((0x1f00000U 
                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                           << 0x12U)) 
                                       | (0xe00U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst)))))
                    : ((0x15U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_2))
                        ? (0x13027U | ((0x1c000000U 
                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                           << 0x13U)) 
                                       | ((0x2000000U 
                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                              << 0xdU)) 
                                          | ((0x1f00000U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                                 << 0x12U)) 
                                             | (0xc00U 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst)))))
                        : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__exp__DOT___io_out_T_42_bits)));
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1740(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1740\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_replay 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__fq__DOT__valid_0)
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__fq__DOT__elts_0_replay)
            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__fq__io_enq_bits_replay));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__btb__io_ras_update_bits_returnAddr 
        = (0x7fffffffffULL & ((~ (3ULL | (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_pc))) 
                              + ((QData)((IData)(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__taken)
                                                   ? 1U
                                                   : 2U))) 
                                 << 1U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_101 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__valid_1) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__taken))) 
           & (0x30000U == (0x30000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__taken)
            ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__prevRVI)
                 ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__rviReturn)
                 : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__rvcReturn))
                ? 3U : (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__prevRVI)
                          ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__rviCall)
                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__rvcJALR))
                         ? 2U : (1U & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__prevRVI)
                                           ? (0x63U 
                                              == (0x7fU 
                                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_partial_insn)))
                                           : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__rvcBranch))))))
            : (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__prevRVI_1)
                 ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__rviReturn_1)
                 : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__rvcReturn_1))
                ? 3U : (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__prevRVI_1)
                          ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__rviCall_1)
                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__rvcJALR_1))
                         ? 2U : (1U & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__prevRVI_1)
                                           ? (0x63U 
                                              == (0x7fU 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data))
                                           : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__rvcBranch_1)))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__taken_2 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__taken) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__taken_1));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1741(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1741\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_32 
        = ((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_6[2U])
            ? ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_27 
                << 1U) | (QData)((IData)((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U] 
                                                >> 0x1aU)))))
            : (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_6[1U])) 
                << 0x20U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_6[0U]))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT__mask_acc_2 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT__mask_acc) 
           | ((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_size))) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT__mask_eq_2)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT__mask_acc_3 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT__mask_acc) 
           | ((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_size))) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT__mask_eq_3)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT__mask_acc_4 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT__mask_acc_1) 
           | ((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_size))) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT__mask_eq_4)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT__mask_acc_5 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT__mask_acc_1) 
           | ((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_size))) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT__mask_eq_5)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_WIRE 
        = (((((((((((((((((((((((((((((((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_148))
                                         ? (0x2080000000000000ULL 
                                            | (QData)((IData)(
                                                              (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_chain) 
                                                                << 0xbU) 
                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_tmatch) 
                                                                   << 7U) 
                                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_m) 
                                                                      << 6U) 
                                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_s) 
                                                                         << 4U) 
                                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_u) 
                                                                            << 3U) 
                                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_x) 
                                                                               << 2U) 
                                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_w) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_r)))))))))))
                                         : 0ULL) | 
                                       ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_150))
                                         ? (((QData)((IData)(
                                                             (0x1ffffffU 
                                                              & (- (IData)(
                                                                           (1U 
                                                                            & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_address 
                                                                                >> 0x26U)))))))) 
                                             << 0x27U) 
                                            | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_address)
                                         : 0ULL)) | 
                                      ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_28))
                                        ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_misa
                                        : 0ULL)) | 
                                     ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_26))
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)
                                           ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_0
                                           : (0x8000000000000000ULL 
                                              | (((QData)((IData)(
                                                                  (0x14000300U 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_gva) 
                                                                       << 0x1fU) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_tsr) 
                                                                          << 0xfU) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_tw) 
                                                                             << 0xeU) 
                                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_tvm) 
                                                                                << 0xdU) 
                                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mxr) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_sum) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mprv) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_fs) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mpp) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_spp) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mpie)))))))))))))) 
                                                  << 7U) 
                                                 | (QData)((IData)(
                                                                   (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_spie) 
                                                                     << 5U) 
                                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mie) 
                                                                        << 3U) 
                                                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_sie) 
                                                                          << 1U))))))))
                                       : 0ULL)) | (
                                                   (0xfffU 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_36))
                                                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__read_mtvec
                                                    : 0ULL)) 
                                   | ((0x3ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_108))
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)
                                           ? (0x2aaaULL 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_5)
                                           : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_3)
                                       : 0ULL)) | (
                                                   (0xfffU 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_34))
                                                    ? 
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)
                                                     ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_1
                                                     : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mie)
                                                    : 0ULL)) 
                                 | ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_100))
                                     ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)
                                         ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_3
                                         : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mscratch)
                                     : 0ULL)) | ((0xfffU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_102))
                                                  ? 
                                                 ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)
                                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_4
                                                   : 
                                                  (((QData)((IData)(
                                                                    (0xffffffU 
                                                                     & (- (IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___read_mepc_T_4 
                                                                                >> 0x27U)))))))) 
                                                    << 0x28U) 
                                                   | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___read_mepc_T_4))
                                                  : 0ULL)) 
                               | ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_106))
                                   ? (((QData)((IData)(
                                                       (0xffffffU 
                                                        & (- (IData)(
                                                                     (1U 
                                                                      & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mtval 
                                                                                >> 0x27U)))))))) 
                                       << 0x28U) | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mtval)
                                   : 0ULL)) | ((0xfffU 
                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_104))
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mcause
                                                : 0ULL)) 
                             | ((0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_156))
                                 ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__value_1
                                 : 0ULL)) | ((0xfffU 
                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_158))
                                              ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__value
                                              : 0ULL)) 
                           | ((IData)((0xc00U == (0xffeU 
                                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr))))
                               ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__value_1
                               : 0ULL)) | ((IData)(
                                                   (0xc02U 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr)))
                                            ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__value
                                            : 0ULL)) 
                         | ((0x3ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_6))
                             ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)
                                 ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_6
                                 : (0x8000000200000000ULL 
                                    | (QData)((IData)(
                                                      (0x18000U 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mxr) 
                                                           << 0x13U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_sum) 
                                                              << 0x12U) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_fs) 
                                                                 << 0xdU) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_spp) 
                                                                    << 8U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_spie) 
                                                                       << 5U) 
                                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_sie) 
                                                                         << 1U)))))))))))
                             : 0ULL)) | ((0x3ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_22))
                                          ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)
                                              ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_12
                                              : (0x2222ULL 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_3 
                                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mideleg)))
                                          : 0ULL)) 
                       | ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_8))
                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)
                               ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_7
                               : (0x2222ULL & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mie 
                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mideleg)))
                           : 0ULL)) | ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_14))
                                        ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)
                                            ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_8
                                            : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_sscratch)
                                        : 0ULL)) | 
                     ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_18))
                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)
                           ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_10
                           : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_scause)
                       : 0ULL)) | ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_20))
                                    ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)
                                        ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_11
                                        : (((QData)((IData)(
                                                            (0xffffffU 
                                                             & (- (IData)(
                                                                          (1U 
                                                                           & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_stval 
                                                                                >> 0x27U)))))))) 
                                            << 0x28U) 
                                           | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_stval))
                                    : 0ULL)) | ((0x1fU 
                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_24))
                                                 ? 
                                                (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_satp_mode)) 
                                                  << 0x3cU) 
                                                 | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_satp_ppn)
                                                 : 0ULL)) 
                  | ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_16))
                      ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)
                          ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_9
                          : (((QData)((IData)((0xffffffU 
                                               & (- (IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___read_sepc_T_4 
                                                                        >> 0x27U)))))))) 
                              << 0x28U) | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___read_sepc_T_4))
                      : 0ULL)) | ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_10))
                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__read_stvec
                                   : 0ULL)) | ((0xfffU 
                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_32))
                                                ? (0x2222ULL 
                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mideleg)
                                                : 0ULL)) 
               | ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_30))
                   ? (0xf0b55dULL & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_medeleg)
                   : 0ULL)) | ((0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_110))
                                ? (((QData)((IData)(
                                                    (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_l) 
                                                      << 0x1fU) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_a) 
                                                         << 0x1bU) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_x) 
                                                            << 0x1aU) 
                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_w) 
                                                               << 0x19U) 
                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_r) 
                                                                  << 0x18U) 
                                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_l) 
                                                                     << 0x17U) 
                                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_a) 
                                                                        << 0x13U) 
                                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_x) 
                                                                           << 0x12U) 
                                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_w) 
                                                                              << 0x11U) 
                                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_r) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_l) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_a) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_x) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_w) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_r) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_l) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_a) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_x) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_w) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_r)))))))))))))))))))))) 
                                    << 0x20U) | (QData)((IData)(
                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_l) 
                                                                  << 0x1fU) 
                                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_a) 
                                                                     << 0x1bU) 
                                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_x) 
                                                                        << 0x1aU) 
                                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_w) 
                                                                           << 0x19U) 
                                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_r) 
                                                                              << 0x18U) 
                                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_l) 
                                                                                << 0x17U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_a) 
                                                                                << 0x13U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_x) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_w) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_r) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_l) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_a) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_x) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_w) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_r) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_cfg_l) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_cfg_a) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_cfg_x) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_cfg_w) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_cfg_r)))))))))))))))))))))))
                                : 0ULL)) | ((0x3fU 
                                             == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_154))
                                             ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_custom_0
                                             : 0ULL)) 
            | (((QData)((IData)((0x3fffffU & ((((((
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_124 
                                                     | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_125) 
                                                    | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_126) 
                                                   | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_127) 
                                                  | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_128) 
                                                 | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_129) 
                                                | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_130) 
                                               | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_131) 
                                              >> 8U)))) 
                << 8U) | (QData)((IData)(((0xe0U & 
                                           (((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_16) 
                                                   | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_124) 
                                                  | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_125) 
                                                 | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_126) 
                                                | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_127) 
                                               | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_128) 
                                              | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_129) 
                                             | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_130) 
                                            | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_131)) 
                                          | ((0x18U 
                                              & ((((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_14) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_16)) 
                                                        | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_124) 
                                                       | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_125) 
                                                      | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_126) 
                                                     | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_127) 
                                                    | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_128) 
                                                   | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_129) 
                                                  | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_130) 
                                                 | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_T_131)) 
                                             | ((6U 
                                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_22)) 
                                                | (1U 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_22) 
                                                      | (IData)(
                                                                (0xf12U 
                                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr)))))))))))) 
           | ((IData)((0xf13U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr)))
               ? 0x20181004ULL : 0ULL));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1742(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1742\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_36 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1833) 
                 | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1835))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__set_fs_dirty_shadow 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__csr_wen) 
            & ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1874)) 
                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1876)) 
                | ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1869)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1871))) 
               | ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1864)) 
                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1866)))) 
           | ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1833)) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1835)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT___T_6 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__entering) 
                 | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__inReady))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT___T_6 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__entering) 
                 | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__inReady))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_something_inflight 
        = ((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__state)) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_fpu_inflight));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___T_7 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_dw)
            ? (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__alu__io_in1 
                       >> 0x20U)) : (- (IData)((IData)(
                                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn) 
                                                         >> 3U) 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__alu__io_in1 
                                                           >> 0x1fU))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__alu__io_in2 
        = (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_2[
                            (((IData)(0x3fU) + (0xffU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_alu2) 
                                                   << 6U))) 
                             >> 5U)])) << ((0U == (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_alu2) 
                                                      << 6U)))
                                            ? 0x20U
                                            : ((IData)(0x40U) 
                                               - (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_alu2) 
                                                     << 6U))))) 
           | (((0U == (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_alu2) 
                                << 6U))) ? 0ULL : ((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_2[
                                                                   (((IData)(0x1fU) 
                                                                     + 
                                                                     (0xffU 
                                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_alu2) 
                                                                         << 6U))) 
                                                                    >> 5U)])) 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_alu2) 
                                                        << 6U))))) 
              | ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_2[
                                 (6U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_alu2) 
                                        << 1U))])) 
                 >> (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_alu2) 
                              << 6U)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ll_waddr 
        = (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_173)
                     ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__dmem_resp_waddr)
                     : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_req_valid_rocc_T)
                         ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT___ram_ext_R0_data[0U]
                         : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__req_tag))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__lsl__io_req_valid_rocc 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_req_valid_rocc_T) 
             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode))) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_rocc)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_wxd));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1743(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1743\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN 
        = (1U & ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_173) 
                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_req_valid_rocc_T))) 
                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_wxd))));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_trace_0_exception_output) {
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__delegate) {
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_23 
                = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mpie;
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_31 = 1U;
        } else {
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_23 
                = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mie;
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_31 = 0U;
        }
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_23 
            = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_298)
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mie)
                : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mpie));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_31 = 0U;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__notDebugTVec_base 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__delegate)
            ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__read_stvec
            : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__read_mtvec);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__advance_pstore1 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___pstore1_held_T) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_sc_fail))) 
            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_held)) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_valid) 
              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_in_0_bits_write)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_eccMask 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_in_0_valid)
            ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_valid)
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_mask)
                : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_mask))
            : 0xffU);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__id_bypass_src_0_1 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_29) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_ex_T_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__id_bypass_src_0_2 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___T_34) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_mem_T_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___rf_ext_R1_data 
        = ((0x1eU >= (0x1fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2))))
            ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
           [(0x1fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2)))]
            : 0ULL);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_wb_T_3 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2) 
           == (0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                        >> 7U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_ex_T_3 
        = ((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                     >> 7U)) == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_mem_T_3 
        = ((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                     >> 7U)) == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_6 
        = ((0x800U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                      << 0xbU)) | ((0x400U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                              << 9U)) 
                                   | ((0x200U & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                   >> 2U)) 
                                                 << 9U)) 
                                      | ((0x100U & 
                                          ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                               >> 3U)) 
                                           << 8U)) 
                                         | ((0x80U 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                << 3U)) 
                                            | ((0x40U 
                                                & ((~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                     >> 5U)) 
                                                   << 6U)) 
                                               | ((0x20U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                      >> 1U)) 
                                                  | ((0x10U 
                                                      & ((~ 
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                           >> 0x1aU)) 
                                                         << 4U)) 
                                                     | ((8U 
                                                         & ((~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                              >> 0x1cU)) 
                                                            << 3U)) 
                                                        | ((4U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                 >> 0x1dU)) 
                                                               << 2U)) 
                                                           | ((2U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                    >> 0x1eU)) 
                                                                  << 1U)) 
                                                              | (1U 
                                                                 & (~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                     >> 0x1fU))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1744(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1744\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_44 
        = ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                     << 7U)) | ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                          << 5U)) | 
                                ((0x20U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                               >> 2U)) 
                                           << 5U)) 
                                 | ((0x10U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                  >> 3U)) 
                                              << 4U)) 
                                    | ((8U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                  >> 4U)) 
                                              << 3U)) 
                                       | ((4U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                 >> 3U)) 
                                          | ((2U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                               >> 5U)) 
                                             | (1U 
                                                & (~ 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                    >> 0xdU))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_62 
        = ((0x4000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                       << 0xeU)) | ((0x2000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                << 0xcU)) 
                                    | ((0x1000U & (
                                                   (~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                     >> 2U)) 
                                                   << 0xcU)) 
                                       | ((0x800U & 
                                           ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                >> 3U)) 
                                            << 0xbU)) 
                                          | ((0x400U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                 << 6U)) 
                                             | ((0x200U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                      >> 5U)) 
                                                    << 9U)) 
                                                | ((0x100U 
                                                    & ((~ 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                         >> 6U)) 
                                                       << 8U)) 
                                                   | ((0x80U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                          >> 5U)) 
                                                      | ((0x40U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                               >> 0xdU)) 
                                                             << 6U)) 
                                                         | ((0x20U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                  >> 0x1aU)) 
                                                                << 5U)) 
                                                            | ((0x10U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                     >> 0x1bU)) 
                                                                   << 4U)) 
                                                               | ((8U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                        >> 0x1cU)) 
                                                                      << 3U)) 
                                                                  | ((4U 
                                                                      & ((~ 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                           >> 0x1dU)) 
                                                                         << 2U)) 
                                                                     | ((2U 
                                                                         & ((~ 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                              >> 0x1eU)) 
                                                                            << 1U)) 
                                                                        | (1U 
                                                                           & (~ 
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                               >> 0x1fU)))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1745(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1745\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_66 
        = ((0x8000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                       << 0xfU)) | ((0x4000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                << 0xdU)) 
                                    | ((0x2000U & (
                                                   (~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                     >> 2U)) 
                                                   << 0xdU)) 
                                       | ((0x1000U 
                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                              << 9U)) 
                                          | ((0x800U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                 << 7U)) 
                                             | ((0x400U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                      >> 5U)) 
                                                    << 0xaU)) 
                                                | ((0x200U 
                                                    & ((~ 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                         >> 6U)) 
                                                       << 9U)) 
                                                   | ((0x100U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                          >> 4U)) 
                                                      | ((0x80U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                               >> 0xdU)) 
                                                             << 7U)) 
                                                         | ((0x40U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                  >> 0x19U)) 
                                                                << 6U)) 
                                                            | ((0x20U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                     >> 0x1aU)) 
                                                                   << 5U)) 
                                                               | ((0x10U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                        >> 0x1bU)) 
                                                                      << 4U)) 
                                                                  | ((8U 
                                                                      & ((~ 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                           >> 0x1cU)) 
                                                                         << 3U)) 
                                                                     | ((4U 
                                                                         & ((~ 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                              >> 0x1dU)) 
                                                                            << 2U)) 
                                                                        | ((2U 
                                                                            & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                                >> 0x1eU)) 
                                                                               << 1U)) 
                                                                           | (1U 
                                                                              & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                                >> 0x1fU))))))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_134 
        = ((0x8000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                       << 0xfU)) | ((0x4000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                << 0xdU)) 
                                    | ((0x2000U & (
                                                   (~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                     >> 2U)) 
                                                   << 0xdU)) 
                                       | ((0x1000U 
                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                              << 9U)) 
                                          | ((0x800U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                 << 7U)) 
                                             | ((0x400U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                      >> 5U)) 
                                                    << 0xaU)) 
                                                | ((0x200U 
                                                    & ((~ 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                         >> 6U)) 
                                                       << 9U)) 
                                                   | ((0x100U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                          >> 4U)) 
                                                      | ((0x80U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                               >> 0xdU)) 
                                                             << 7U)) 
                                                         | ((0x40U 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                >> 8U)) 
                                                            | ((0x20U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                     >> 0x19U)) 
                                                                   << 5U)) 
                                                               | ((0x10U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                        >> 0x1aU)) 
                                                                      << 4U)) 
                                                                  | ((8U 
                                                                      & ((~ 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                           >> 0x1bU)) 
                                                                         << 3U)) 
                                                                     | ((4U 
                                                                         & ((~ 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                              >> 0x1cU)) 
                                                                            << 2U)) 
                                                                        | ((2U 
                                                                            & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                                >> 0x1dU)) 
                                                                               << 1U)) 
                                                                           | (1U 
                                                                              & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                                                >> 0x1fU))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__1746(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__1746\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_144 
        = ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                     << 7U)) | ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                          << 5U)) | 
                                ((0x20U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                               >> 2U)) 
                                           << 5U)) 
                                 | ((0x10U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                  >> 3U)) 
                                              << 4U)) 
                                    | ((8U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                              >> 2U)) 
                                       | ((4U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                 >> 4U)) 
                                          | ((2U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                               >> 0xbU)) 
                                             | (1U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                   >> 0xeU)))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_148 
        = ((0x100U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                      << 8U)) | ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                           << 6U)) 
                                 | ((0x40U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                  >> 2U)) 
                                              << 6U)) 
                                    | ((0x20U & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                   >> 3U)) 
                                                 << 5U)) 
                                       | ((0x10U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits) 
                                          | ((8U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                               >> 2U)) 
                                             | ((4U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                    >> 4U)) 
                                                | ((2U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                       >> 0xbU)) 
                                                   | (1U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                         >> 0xeU))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_158 
        = ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                     << 7U)) | ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                          << 5U)) | 
                                ((0x20U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                               >> 2U)) 
                                           << 5U)) 
                                 | ((0x10U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                  >> 3U)) 
                                              << 4U)) 
                                    | ((8U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                              >> 2U)) 
                                       | ((4U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                 >> 4U)) 
                                          | ((2U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                               >> 0xcU)) 
                                             | (1U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                   >> 0xeU)))))))));
}
