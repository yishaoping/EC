// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTestHarness.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTestHarness___024root.h"

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21528(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21528\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_254 
        = ((0x4000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                       << 0xeU)) | ((0x2000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0xcU)) 
                                    | ((0x1000U & (
                                                   (~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                     >> 2U)) 
                                                   << 0xcU)) 
                                       | ((0x800U & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                            << 7U)) 
                                          | ((0x400U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 << 5U)) 
                                             | ((0x200U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 6U)) 
                                                    << 9U)) 
                                                | ((0x100U 
                                                    & ((~ 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         >> 0xdU)) 
                                                       << 8U)) 
                                                   | ((0x80U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                          >> 7U)) 
                                                      | ((0x40U 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                             >> 0x13U)) 
                                                         | ((0x20U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                  >> 0x1aU)) 
                                                                << 5U)) 
                                                            | ((0x10U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                     >> 0x1bU)) 
                                                                   << 4U)) 
                                                               | ((8U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                        >> 0x1cU)) 
                                                                      << 3U)) 
                                                                  | ((4U 
                                                                      & ((~ 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                           >> 0x1dU)) 
                                                                         << 2U)) 
                                                                     | ((2U 
                                                                         & ((~ 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                              >> 0x1eU)) 
                                                                            << 1U)) 
                                                                        | (1U 
                                                                           & (~ 
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                               >> 0x1fU)))))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_296 
        = ((0x40000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                        << 0x12U)) | ((0x20000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   << 0x10U)) 
                                      | ((0x10000U 
                                          & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 >> 2U)) 
                                             << 0x10U)) 
                                         | ((0x8000U 
                                             & ((~ 
                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 3U)) 
                                                << 0xfU)) 
                                            | ((0x4000U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   << 0xaU)) 
                                               | ((0x2000U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      << 8U)) 
                                                  | ((0x1000U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         << 6U)) 
                                                     | ((0x800U 
                                                         & ((~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                              >> 7U)) 
                                                            << 0xbU)) 
                                                        | ((0x400U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                 >> 8U)) 
                                                               << 0xaU)) 
                                                           | ((0x200U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                    >> 9U)) 
                                                                  << 9U)) 
                                                              | ((0x100U 
                                                                  & ((~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                       >> 0xdU)) 
                                                                     << 8U)) 
                                                                 | ((0x80U 
                                                                     & ((~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                          >> 0xeU)) 
                                                                        << 7U)) 
                                                                    | ((0x40U 
                                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                           >> 0x13U)) 
                                                                       | ((0x20U 
                                                                           & ((~ 
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1aU)) 
                                                                              << 5U)) 
                                                                          | ((0x10U 
                                                                              & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                << 4U)) 
                                                                             | ((8U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1fU)))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21529(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21529\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_330 
        = ((0x4000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                       << 0xeU)) | ((0x2000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0xcU)) 
                                    | ((0x1000U & (
                                                   (~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                     >> 2U)) 
                                                   << 0xcU)) 
                                       | ((0x800U & 
                                           ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                >> 3U)) 
                                            << 0xbU)) 
                                          | ((0x400U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 << 6U)) 
                                             | ((0x200U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 5U)) 
                                                    << 9U)) 
                                                | ((0x100U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                       << 2U)) 
                                                   | ((0x80U 
                                                       & ((~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                            >> 0xdU)) 
                                                          << 7U)) 
                                                      | ((0x40U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                               >> 0xeU)) 
                                                             << 6U)) 
                                                         | ((0x20U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                  >> 0x1aU)) 
                                                                << 5U)) 
                                                            | ((0x10U 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                   >> 0x17U)) 
                                                               | ((8U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                        >> 0x1cU)) 
                                                                      << 3U)) 
                                                                  | ((4U 
                                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                         >> 0x1bU)) 
                                                                     | ((2U 
                                                                         & ((~ 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                              >> 0x1eU)) 
                                                                            << 1U)) 
                                                                        | (1U 
                                                                           & (~ 
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                               >> 0x1fU)))))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_36 
        = ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                     << 7U)) | ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                          << 5U)) | 
                                ((0x20U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 2U)) 
                                           << 5U)) 
                                 | ((0x10U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 3U)) 
                                              << 4U)) 
                                    | ((8U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 4U)) 
                                              << 3U)) 
                                       | ((4U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 >> 3U)) 
                                          | ((2U & 
                                              ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 6U)) 
                                               << 1U)) 
                                             | (1U 
                                                & (~ 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                    >> 0xeU))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21530(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21530\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_154 
        = ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                     << 7U)) | ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                          << 5U)) | 
                                ((0x20U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 3U)) 
                                           << 5U)) 
                                 | ((0x10U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 4U)) 
                                              << 4U)) 
                                    | ((8U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                              >> 2U)) 
                                       | ((4U & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 6U)) 
                                                 << 2U)) 
                                          | ((2U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 0xcU)) 
                                             | (1U 
                                                & (~ 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                    >> 0xeU))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_226 
        = ((0x100U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                      << 8U)) | ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                           << 6U)) 
                                 | ((0x40U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 2U)) 
                                              << 6U)) 
                                    | ((0x20U & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 3U)) 
                                                 << 5U)) 
                                       | ((0x10U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst) 
                                          | ((8U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 2U)) 
                                             | ((4U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                    >> 4U)) 
                                                | ((2U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                       >> 0xcU)) 
                                                   | (1U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         >> 0xeU))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_364 
        = ((0x8000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                       << 0xfU)) | ((0x4000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0xdU)) 
                                    | ((0x2000U & (
                                                   (~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                     >> 2U)) 
                                                   << 0xdU)) 
                                       | ((0x1000U 
                                           & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 3U)) 
                                              << 0xcU)) 
                                          | ((0x800U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 << 7U)) 
                                             | ((0x400U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 5U)) 
                                                    << 0xaU)) 
                                                | ((0x200U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                       << 3U)) 
                                                   | ((0x100U 
                                                       & ((~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                            >> 0x14U)) 
                                                          << 8U)) 
                                                      | ((0x80U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                               >> 0x15U)) 
                                                             << 7U)) 
                                                         | ((0x40U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                  >> 0x16U)) 
                                                                << 6U)) 
                                                            | ((0x20U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                     >> 0x17U)) 
                                                                   << 5U)) 
                                                               | ((0x10U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                        >> 0x18U)) 
                                                                      << 4U)) 
                                                                  | ((8U 
                                                                      & ((~ 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                           >> 0x1aU)) 
                                                                         << 3U)) 
                                                                     | ((4U 
                                                                         & ((~ 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                              >> 0x1bU)) 
                                                                            << 2U)) 
                                                                        | ((2U 
                                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                               >> 0x1dU)) 
                                                                           | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                              >> 0x1fU))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21531(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21531\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_22 
        = ((0x200U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                      << 9U)) | ((0x100U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                            << 7U)) 
                                 | ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                              << 5U)) 
                                    | ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 << 3U)) 
                                       | ((0x20U & 
                                           ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                >> 4U)) 
                                            << 5U)) 
                                          | ((0x10U 
                                              & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 5U)) 
                                                 << 4U)) 
                                             | ((8U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 6U)) 
                                                    << 3U)) 
                                                | ((4U 
                                                    & ((~ 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         >> 0xcU)) 
                                                       << 2U)) 
                                                   | ((2U 
                                                       & ((~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                            >> 0xdU)) 
                                                          << 1U)) 
                                                      | (1U 
                                                         & (~ 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                             >> 0xeU))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_80 
        = ((0x800U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                      << 0xbU)) | ((0x400U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                              << 9U)) 
                                   | ((0x200U & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 2U)) 
                                                 << 9U)) 
                                      | ((0x100U & 
                                          ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 3U)) 
                                           << 8U)) 
                                         | ((0x80U 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 3U)) 
                                            | ((0x40U 
                                                & ((~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                     >> 5U)) 
                                                   << 6U)) 
                                               | ((0x20U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 1U)) 
                                                  | ((0x10U 
                                                      & ((~ 
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                           >> 0x1aU)) 
                                                         << 4U)) 
                                                     | ((8U 
                                                         & ((~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                              >> 0x1bU)) 
                                                            << 3U)) 
                                                        | ((4U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                 >> 0x1dU)) 
                                                               << 2U)) 
                                                           | ((2U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                    >> 0x1eU)) 
                                                                  << 1U)) 
                                                              | (1U 
                                                                 & (~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                     >> 0x1fU))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21532(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21532\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_84 
        = ((0x800U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                      << 0xbU)) | ((0x400U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                              << 9U)) 
                                   | ((0x200U & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 2U)) 
                                                 << 9U)) 
                                      | ((0x100U & 
                                          ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 3U)) 
                                           << 8U)) 
                                         | ((0x80U 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 3U)) 
                                            | ((0x40U 
                                                & ((~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                     >> 5U)) 
                                                   << 6U)) 
                                               | ((0x20U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 1U)) 
                                                  | ((0x10U 
                                                      & ((~ 
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                           >> 0x1aU)) 
                                                         << 4U)) 
                                                     | ((8U 
                                                         & ((~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                              >> 0x1cU)) 
                                                            << 3U)) 
                                                        | ((4U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                 >> 0x1dU)) 
                                                               << 2U)) 
                                                           | ((2U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                    >> 0x1eU)) 
                                                                  << 1U)) 
                                                              | (1U 
                                                                 & (~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                     >> 0x1fU))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_232 
        = ((0x4000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                       << 0xeU)) | ((0x2000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0xcU)) 
                                    | ((0x1000U & (
                                                   (~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                     >> 2U)) 
                                                   << 0xcU)) 
                                       | ((0x800U & 
                                           ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                >> 3U)) 
                                            << 0xbU)) 
                                          | ((0x400U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 << 6U)) 
                                             | ((0x200U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                    << 4U)) 
                                                | ((0x100U 
                                                    & ((~ 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         >> 6U)) 
                                                       << 8U)) 
                                                   | ((0x80U 
                                                       & ((~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                            >> 0xeU)) 
                                                          << 7U)) 
                                                      | ((0x40U 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                             >> 0x13U)) 
                                                         | ((0x20U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                  >> 0x1aU)) 
                                                                << 5U)) 
                                                            | ((0x10U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                     >> 0x1bU)) 
                                                                   << 4U)) 
                                                               | ((8U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                        >> 0x1cU)) 
                                                                      << 3U)) 
                                                                  | ((4U 
                                                                      & ((~ 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                           >> 0x1dU)) 
                                                                         << 2U)) 
                                                                     | ((2U 
                                                                         & ((~ 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                              >> 0x1eU)) 
                                                                            << 1U)) 
                                                                        | (1U 
                                                                           & (~ 
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                               >> 0x1fU)))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21533(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21533\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_302 
        = ((0x1000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                       << 0xcU)) | ((0x800U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               << 0xaU)) 
                                    | ((0x400U & ((~ 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                    >> 2U)) 
                                                  << 0xaU)) 
                                       | ((0x200U & 
                                           ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                >> 3U)) 
                                            << 9U)) 
                                          | ((0x100U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 << 4U)) 
                                             | ((0x80U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 5U)) 
                                                    << 7U)) 
                                                | ((0x40U 
                                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst) 
                                                   | ((0x20U 
                                                       & ((~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                            >> 0x1aU)) 
                                                          << 5U)) 
                                                      | ((0x10U 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                             >> 0x17U)) 
                                                         | ((8U 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                >> 0x19U)) 
                                                            | ((4U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                     >> 0x1dU)) 
                                                                   << 2U)) 
                                                               | ((2U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                        >> 0x1eU)) 
                                                                      << 1U)) 
                                                                  | (1U 
                                                                     & (~ 
                                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                         >> 0x1fU)))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_360 
        = ((0x4000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                       << 0xeU)) | ((0x2000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0xcU)) 
                                    | ((0x1000U & (
                                                   (~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                     >> 2U)) 
                                                   << 0xcU)) 
                                       | ((0x800U & 
                                           ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                >> 3U)) 
                                            << 0xbU)) 
                                          | ((0x400U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 << 6U)) 
                                             | ((0x200U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 5U)) 
                                                    << 9U)) 
                                                | ((0x100U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                       << 2U)) 
                                                   | ((0x80U 
                                                       & ((~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                            >> 0xcU)) 
                                                          << 7U)) 
                                                      | ((0x40U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                               >> 0xeU)) 
                                                             << 6U)) 
                                                         | ((0x20U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                  >> 0x1aU)) 
                                                                << 5U)) 
                                                            | ((0x10U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                     >> 0x1bU)) 
                                                                   << 4U)) 
                                                               | ((8U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                        >> 0x1cU)) 
                                                                      << 3U)) 
                                                                  | ((4U 
                                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                         >> 0x1bU)) 
                                                                     | ((2U 
                                                                         & ((~ 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                              >> 0x1eU)) 
                                                                            << 1U)) 
                                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                           >> 0x1fU)))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21534(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21534\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_362 
        = ((0x4000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                       << 0xeU)) | ((0x2000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0xcU)) 
                                    | ((0x1000U & (
                                                   (~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                     >> 2U)) 
                                                   << 0xcU)) 
                                       | ((0x800U & 
                                           ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                >> 3U)) 
                                            << 0xbU)) 
                                          | ((0x400U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 << 6U)) 
                                             | ((0x200U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 5U)) 
                                                    << 9U)) 
                                                | ((0x100U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                       << 2U)) 
                                                   | ((0x80U 
                                                       & ((~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                            >> 0xdU)) 
                                                          << 7U)) 
                                                      | ((0x40U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                               >> 0xeU)) 
                                                             << 6U)) 
                                                         | ((0x20U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                  >> 0x1aU)) 
                                                                << 5U)) 
                                                            | ((0x10U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                     >> 0x1bU)) 
                                                                   << 4U)) 
                                                               | ((8U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                        >> 0x1cU)) 
                                                                      << 3U)) 
                                                                  | ((4U 
                                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                         >> 0x1bU)) 
                                                                     | ((2U 
                                                                         & ((~ 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                              >> 0x1eU)) 
                                                                            << 1U)) 
                                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                           >> 0x1fU)))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_370 
        = ((0x8000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                       << 0xfU)) | ((0x4000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0xdU)) 
                                    | ((0x2000U & (
                                                   (~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                     >> 2U)) 
                                                   << 0xdU)) 
                                       | ((0x1000U 
                                           & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 3U)) 
                                              << 0xcU)) 
                                          | ((0x800U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 << 7U)) 
                                             | ((0x400U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 5U)) 
                                                    << 0xaU)) 
                                                | ((0x200U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                       << 3U)) 
                                                   | ((0x100U 
                                                       & ((~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                            >> 0x16U)) 
                                                          << 8U)) 
                                                      | ((0x80U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                               >> 0x17U)) 
                                                             << 7U)) 
                                                         | ((0x40U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                  >> 0x18U)) 
                                                                << 6U)) 
                                                            | ((0x20U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                     >> 0x1aU)) 
                                                                   << 5U)) 
                                                               | ((0x10U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                        >> 0x1bU)) 
                                                                      << 4U)) 
                                                                  | ((8U 
                                                                      & ((~ 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                           >> 0x1cU)) 
                                                                         << 3U)) 
                                                                     | ((4U 
                                                                         & ((~ 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                              >> 0x1dU)) 
                                                                            << 2U)) 
                                                                        | ((2U 
                                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                               >> 0x1dU)) 
                                                                           | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                              >> 0x1fU))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21535(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21535\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_318 
        = ((0x4000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                       << 0xeU)) | ((0x2000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0xcU)) 
                                    | ((0x1000U & (
                                                   (~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                     >> 2U)) 
                                                   << 0xcU)) 
                                       | ((0x800U & 
                                           ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                >> 3U)) 
                                            << 0xbU)) 
                                          | ((0x400U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 << 6U)) 
                                             | ((0x200U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 5U)) 
                                                    << 9U)) 
                                                | ((0x100U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                       << 2U)) 
                                                   | ((0x80U 
                                                       & ((~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                            >> 0xcU)) 
                                                          << 7U)) 
                                                      | ((0x40U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                               >> 0xeU)) 
                                                             << 6U)) 
                                                         | ((0x20U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                  >> 0x1aU)) 
                                                                << 5U)) 
                                                            | ((0x10U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                     >> 0x1bU)) 
                                                                   << 4U)) 
                                                               | ((8U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                        >> 0x1cU)) 
                                                                      << 3U)) 
                                                                  | ((4U 
                                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                         >> 0x1bU)) 
                                                                     | ((2U 
                                                                         & ((~ 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                              >> 0x1eU)) 
                                                                            << 1U)) 
                                                                        | (1U 
                                                                           & (~ 
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                               >> 0x1fU)))))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_58 
        = ((0x10U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                     << 4U)) | ((8U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                       << 2U)) | ((4U 
                                                   & ((~ 
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                        >> 4U)) 
                                                      << 2U)) 
                                                  | ((2U 
                                                      & ((~ 
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                           >> 5U)) 
                                                         << 1U)) 
                                                     | (1U 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                           >> 6U))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21536(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21536\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_102 
        = ((0x8000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                          << 0x1bU)) | ((0x4000000U 
                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                            << 0x16U)) 
                                        | ((0x2000000U 
                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               << 0x14U)) 
                                           | ((0x1000000U 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  << 0x12U)) 
                                              | ((0x800000U 
                                                  & ((~ 
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                       >> 7U)) 
                                                     << 0x17U)) 
                                                 | ((0x400000U 
                                                     & ((~ 
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                          >> 8U)) 
                                                        << 0x16U)) 
                                                    | ((0x200000U 
                                                        & ((~ 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                             >> 9U)) 
                                                           << 0x15U)) 
                                                       | ((0x100000U 
                                                           & ((~ 
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                >> 0xaU)) 
                                                              << 0x14U)) 
                                                          | ((0x80000U 
                                                              & ((~ 
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                   >> 0xbU)) 
                                                                 << 0x13U)) 
                                                             | ((0x40000U 
                                                                 & ((~ 
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                      >> 0xcU)) 
                                                                    << 0x12U)) 
                                                                | ((0x20000U 
                                                                    & ((~ 
                                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                         >> 0xdU)) 
                                                                       << 0x11U)) 
                                                                   | ((0x10000U 
                                                                       & ((~ 
                                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                            >> 0xeU)) 
                                                                          << 0x10U)) 
                                                                      | ((0x8000U 
                                                                          & ((~ 
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                               >> 0xfU)) 
                                                                             << 0xfU)) 
                                                                         | ((0x4000U 
                                                                             & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x10U)) 
                                                                                << 0xeU)) 
                                                                            | ((0x2000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x11U)) 
                                                                                << 0xdU)) 
                                                                               | ((0x1000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x12U)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x13U)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x15U)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x16U)) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x17U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x18U)) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x19U)) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1aU)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1cU)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1fU))))))))))))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21537(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21537\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_280 
        = ((0x8000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                          << 0x1bU)) | ((0x4000000U 
                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                            << 0x16U)) 
                                        | ((0x2000000U 
                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               << 0x14U)) 
                                           | ((0x1000000U 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  << 0x12U)) 
                                              | ((0x800000U 
                                                  & ((~ 
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                       >> 7U)) 
                                                     << 0x17U)) 
                                                 | ((0x400000U 
                                                     & ((~ 
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                          >> 8U)) 
                                                        << 0x16U)) 
                                                    | ((0x200000U 
                                                        & ((~ 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                             >> 9U)) 
                                                           << 0x15U)) 
                                                       | ((0x100000U 
                                                           & ((~ 
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                >> 0xaU)) 
                                                              << 0x14U)) 
                                                          | ((0x80000U 
                                                              & ((~ 
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                   >> 0xbU)) 
                                                                 << 0x13U)) 
                                                             | ((0x40000U 
                                                                 & ((~ 
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                      >> 0xcU)) 
                                                                    << 0x12U)) 
                                                                | ((0x20000U 
                                                                    & ((~ 
                                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                         >> 0xdU)) 
                                                                       << 0x11U)) 
                                                                   | ((0x10000U 
                                                                       & ((~ 
                                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                            >> 0xeU)) 
                                                                          << 0x10U)) 
                                                                      | ((0x8000U 
                                                                          & ((~ 
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                               >> 0xfU)) 
                                                                             << 0xfU)) 
                                                                         | ((0x4000U 
                                                                             & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x10U)) 
                                                                                << 0xeU)) 
                                                                            | ((0x2000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x11U)) 
                                                                                << 0xdU)) 
                                                                               | ((0x1000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x12U)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x13U)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x14U)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0xcU)) 
                                                                                | ((0x100U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x16U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x17U)) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x18U)) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x19U)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1aU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1aU)) 
                                                                                | ((2U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1fU))))))))))))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21538(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21538\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_286 
        = ((0x8000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                          << 0x17U)) | ((0x4000000U 
                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                            << 0x15U)) 
                                        | ((0x2000000U 
                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               << 0x13U)) 
                                           | ((0x1000000U 
                                               & ((~ 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                    >> 7U)) 
                                                  << 0x18U)) 
                                              | ((0x800000U 
                                                  & ((~ 
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                       >> 8U)) 
                                                     << 0x17U)) 
                                                 | ((0x400000U 
                                                     & ((~ 
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                          >> 9U)) 
                                                        << 0x16U)) 
                                                    | ((0x200000U 
                                                        & ((~ 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                             >> 0xaU)) 
                                                           << 0x15U)) 
                                                       | ((0x100000U 
                                                           & ((~ 
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                >> 0xbU)) 
                                                              << 0x14U)) 
                                                          | ((0x80000U 
                                                              & ((~ 
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                   >> 0xcU)) 
                                                                 << 0x13U)) 
                                                             | ((0x40000U 
                                                                 & ((~ 
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                      >> 0xdU)) 
                                                                    << 0x12U)) 
                                                                | ((0x20000U 
                                                                    & ((~ 
                                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                         >> 0xeU)) 
                                                                       << 0x11U)) 
                                                                   | ((0x10000U 
                                                                       & ((~ 
                                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                            >> 0xfU)) 
                                                                          << 0x10U)) 
                                                                      | ((0x8000U 
                                                                          & ((~ 
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                               >> 0x10U)) 
                                                                             << 0xfU)) 
                                                                         | ((0x4000U 
                                                                             & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x11U)) 
                                                                                << 0xeU)) 
                                                                            | ((0x2000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x12U)) 
                                                                                << 0xdU)) 
                                                                               | ((0x1000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x13U)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 9U)) 
                                                                                | ((0x400U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x15U)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0xdU)) 
                                                                                | ((0x100U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x17U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x18U)) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x19U)) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1aU)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1fU))))))))))))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21539(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21539\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_352 
        = ((0x8000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                          << 0x17U)) | ((0x4000000U 
                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                            << 0x15U)) 
                                        | ((0x2000000U 
                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               << 0x13U)) 
                                           | ((0x1000000U 
                                               & ((~ 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                    >> 7U)) 
                                                  << 0x18U)) 
                                              | ((0x800000U 
                                                  & ((~ 
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                       >> 8U)) 
                                                     << 0x17U)) 
                                                 | ((0x400000U 
                                                     & ((~ 
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                          >> 9U)) 
                                                        << 0x16U)) 
                                                    | ((0x200000U 
                                                        & ((~ 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                             >> 0xaU)) 
                                                           << 0x15U)) 
                                                       | ((0x100000U 
                                                           & ((~ 
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                >> 0xbU)) 
                                                              << 0x14U)) 
                                                          | ((0x80000U 
                                                              & ((~ 
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                   >> 0xcU)) 
                                                                 << 0x13U)) 
                                                             | ((0x40000U 
                                                                 & ((~ 
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                      >> 0xdU)) 
                                                                    << 0x12U)) 
                                                                | ((0x20000U 
                                                                    & ((~ 
                                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                         >> 0xeU)) 
                                                                       << 0x11U)) 
                                                                   | ((0x10000U 
                                                                       & ((~ 
                                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                            >> 0xfU)) 
                                                                          << 0x10U)) 
                                                                      | ((0x8000U 
                                                                          & ((~ 
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                               >> 0x10U)) 
                                                                             << 0xfU)) 
                                                                         | ((0x4000U 
                                                                             & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x11U)) 
                                                                                << 0xeU)) 
                                                                            | ((0x2000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x12U)) 
                                                                                << 0xdU)) 
                                                                               | ((0x1000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x13U)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x14U)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0xbU)) 
                                                                                | ((0x200U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x16U)) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x17U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x11U)) 
                                                                                | ((0x40U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x13U)) 
                                                                                | ((0x20U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1aU)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x17U)) 
                                                                                | ((8U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                | ((2U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1fU))))))))))))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21540(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21540\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_98 
        = ((0x100U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                      << 8U)) | ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                           << 6U)) 
                                 | ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                              << 4U)) 
                                    | ((0x20U & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 3U)) 
                                                 << 5U)) 
                                       | ((0x10U & 
                                           ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                >> 4U)) 
                                            << 4U)) 
                                          | ((8U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 2U)) 
                                             | ((4U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                    >> 4U)) 
                                                | ((2U 
                                                    & ((~ 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         >> 0xdU)) 
                                                       << 1U)) 
                                                   | (1U 
                                                      & (~ 
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                          >> 0xeU)))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_94 
        = ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                     << 7U)) | ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                          << 5U)) | 
                                ((0x20U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 2U)) 
                                           << 5U)) 
                                 | ((0x10U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 3U)) 
                                              << 4U)) 
                                    | ((8U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 4U)) 
                                              << 3U)) 
                                       | ((4U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 >> 3U)) 
                                          | ((2U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 5U)) 
                                             | (1U 
                                                & (~ 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                    >> 0xdU))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_60 
        = ((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                     << 5U)) | ((0x10U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                          << 3U)) | 
                                ((8U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                            >> 4U)) 
                                        << 3U)) | (
                                                   (4U 
                                                    & ((~ 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         >> 5U)) 
                                                       << 2U)) 
                                                   | ((2U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                          >> 5U)) 
                                                      | (1U 
                                                         & (~ 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                             >> 0x1aU))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21541(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21541\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_148 
        = ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                     << 6U)) | ((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                          << 4U)) | 
                                ((0x10U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 2U)) 
                                           << 4U)) 
                                 | ((8U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst) 
                                    | ((4U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 4U)) 
                                              << 2U)) 
                                       | ((2U & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 6U)) 
                                                 << 1U)) 
                                          | (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 0xdU))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_164 
        = ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                     << 6U)) | ((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                          << 4U)) | 
                                ((0x10U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 2U)) 
                                           << 4U)) 
                                 | ((8U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst) 
                                    | ((4U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                              >> 2U)) 
                                       | ((2U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 >> 5U)) 
                                          | (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 0xdU))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_12 
        = ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                     << 6U)) | ((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                          << 4U)) | 
                                ((0x10U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 2U)) 
                                           << 4U)) 
                                 | ((8U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst) 
                                    | ((4U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 4U)) 
                                              << 2U)) 
                                       | ((2U & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 6U)) 
                                                 << 1U)) 
                                          | (1U & (~ 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                    >> 0xcU)))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21542(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21542\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_90 
        = ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                     << 6U)) | ((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                          << 4U)) | 
                                ((0x10U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 2U)) 
                                           << 4U)) 
                                 | ((8U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst) 
                                    | ((4U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                              >> 2U)) 
                                       | ((2U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 >> 5U)) 
                                          | (1U & (~ 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                    >> 0xcU)))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_116 
        = ((0x4000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                       << 0xeU)) | ((0x2000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0xcU)) 
                                    | ((0x1000U & (
                                                   (~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                     >> 2U)) 
                                                   << 0xcU)) 
                                       | ((0x800U & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                            << 8U)) 
                                          | ((0x400U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 << 6U)) 
                                             | ((0x200U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 6U)) 
                                                    << 9U)) 
                                                | ((0x100U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                       >> 4U)) 
                                                   | ((0x80U 
                                                       & ((~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                            >> 0xdU)) 
                                                          << 7U)) 
                                                      | ((0x40U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                               >> 0x19U)) 
                                                             << 6U)) 
                                                         | ((0x20U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                  >> 0x1aU)) 
                                                                << 5U)) 
                                                            | ((0x10U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                     >> 0x1bU)) 
                                                                   << 4U)) 
                                                               | ((8U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                        >> 0x1cU)) 
                                                                      << 3U)) 
                                                                  | ((4U 
                                                                      & ((~ 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                           >> 0x1dU)) 
                                                                         << 2U)) 
                                                                     | ((2U 
                                                                         & ((~ 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                              >> 0x1eU)) 
                                                                            << 1U)) 
                                                                        | (1U 
                                                                           & (~ 
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                               >> 0x1fU)))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21543(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21543\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_198 
        = ((0x4000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                       << 0xeU)) | ((0x2000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0xcU)) 
                                    | ((0x1000U & (
                                                   (~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                     >> 2U)) 
                                                   << 0xcU)) 
                                       | ((0x800U & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                            << 8U)) 
                                          | ((0x400U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 << 6U)) 
                                             | ((0x200U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 6U)) 
                                                    << 9U)) 
                                                | ((0x100U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                       >> 4U)) 
                                                   | ((0x80U 
                                                       & ((~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                            >> 0xdU)) 
                                                          << 7U)) 
                                                      | ((0x40U 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                             >> 8U)) 
                                                         | ((0x20U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                  >> 0x19U)) 
                                                                << 5U)) 
                                                            | ((0x10U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                     >> 0x1aU)) 
                                                                   << 4U)) 
                                                               | ((8U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                        >> 0x1bU)) 
                                                                      << 3U)) 
                                                                  | ((4U 
                                                                      & ((~ 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                           >> 0x1cU)) 
                                                                         << 2U)) 
                                                                     | ((2U 
                                                                         & ((~ 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                              >> 0x1dU)) 
                                                                            << 1U)) 
                                                                        | (1U 
                                                                           & (~ 
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                               >> 0x1fU)))))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_202 
        = ((0x4000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                       << 0xeU)) | ((0x2000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0xcU)) 
                                    | ((0x1000U & (
                                                   (~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                     >> 2U)) 
                                                   << 0xcU)) 
                                       | ((0x800U & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                            << 7U)) 
                                          | ((0x400U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 << 5U)) 
                                             | ((0x200U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 6U)) 
                                                    << 9U)) 
                                                | ((0x100U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                       >> 4U)) 
                                                   | ((0x80U 
                                                       & ((~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                            >> 0xdU)) 
                                                          << 7U)) 
                                                      | ((0x40U 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                             >> 8U)) 
                                                         | ((0x20U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                  >> 0x19U)) 
                                                                << 5U)) 
                                                            | ((0x10U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                     >> 0x1aU)) 
                                                                   << 4U)) 
                                                               | ((8U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                        >> 0x1bU)) 
                                                                      << 3U)) 
                                                                  | ((4U 
                                                                      & ((~ 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                           >> 0x1cU)) 
                                                                         << 2U)) 
                                                                     | ((2U 
                                                                         & ((~ 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                              >> 0x1dU)) 
                                                                            << 1U)) 
                                                                        | (1U 
                                                                           & (~ 
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                               >> 0x1fU)))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21544(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21544\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_30 
        = ((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                     << 5U)) | ((0x10U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                          << 3U)) | 
                                ((8U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                        << 1U)) | (
                                                   (4U 
                                                    & ((~ 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         >> 3U)) 
                                                       << 2U)) 
                                                   | ((2U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                          >> 3U)) 
                                                      | (1U 
                                                         & (~ 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                             >> 6U))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_196 
        = ((0x4000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                       << 0xeU)) | ((0x2000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0xcU)) 
                                    | ((0x1000U & (
                                                   (~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                     >> 2U)) 
                                                   << 0xcU)) 
                                       | ((0x800U & 
                                           ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                >> 3U)) 
                                            << 0xbU)) 
                                          | ((0x400U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 << 6U)) 
                                             | ((0x200U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 5U)) 
                                                    << 9U)) 
                                                | ((0x100U 
                                                    & ((~ 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         >> 6U)) 
                                                       << 8U)) 
                                                   | ((0x80U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                          >> 5U)) 
                                                      | ((0x40U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                               >> 0xdU)) 
                                                             << 6U)) 
                                                         | ((0x20U 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                >> 9U)) 
                                                            | ((0x10U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                     >> 0x1aU)) 
                                                                   << 4U)) 
                                                               | ((8U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                        >> 0x1bU)) 
                                                                      << 3U)) 
                                                                  | ((4U 
                                                                      & ((~ 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                           >> 0x1cU)) 
                                                                         << 2U)) 
                                                                     | ((2U 
                                                                         & ((~ 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                              >> 0x1dU)) 
                                                                            << 1U)) 
                                                                        | (1U 
                                                                           & (~ 
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                               >> 0x1fU)))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21545(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21545\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_192 
        = ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                     << 7U)) | ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                          << 5U)) | 
                                ((0x20U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 2U)) 
                                           << 5U)) 
                                 | ((0x10U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 3U)) 
                                              << 4U)) 
                                    | ((8U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 4U)) 
                                              << 3U)) 
                                       | ((4U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 >> 3U)) 
                                          | ((2U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 5U)) 
                                             | (1U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 0xeU)))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT___io_decode_1_system_illegal_T 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_mstatus_prv) 
           < (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                    >> 0x1cU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_140 
        = ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                     << 7U)) | ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                          << 5U)) | 
                                ((0x20U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 3U)) 
                                           << 5U)) 
                                 | ((0x10U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 4U)) 
                                              << 4U)) 
                                    | ((8U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 5U)) 
                                              << 3U)) 
                                       | ((4U & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 6U)) 
                                                 << 2U)) 
                                          | ((2U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 0xcU)) 
                                             | (1U 
                                                & (~ 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                    >> 0xeU))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_272 
        = ((0x10000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                        << 0x10U)) | ((0x8000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  << 0xeU)) 
                                      | ((0x4000U & 
                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                           << 0xcU)) 
                                         | ((0x2000U 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0xaU)) 
                                            | ((0x1000U 
                                                & ((~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                     >> 4U)) 
                                                   << 0xcU)) 
                                               | ((0x800U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      << 6U)) 
                                                  | ((0x400U 
                                                      & ((~ 
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                           >> 6U)) 
                                                         << 0xaU)) 
                                                     | ((0x200U 
                                                         & ((~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                              >> 0x14U)) 
                                                            << 9U)) 
                                                        | ((0x100U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                 >> 0x15U)) 
                                                               << 8U)) 
                                                           | ((0x80U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                    >> 0x16U)) 
                                                                  << 7U)) 
                                                              | ((0x40U 
                                                                  & ((~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                       >> 0x17U)) 
                                                                     << 6U)) 
                                                                 | ((0x20U 
                                                                     & ((~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                          >> 0x18U)) 
                                                                        << 5U)) 
                                                                    | ((0x10U 
                                                                        & ((~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                             >> 0x1bU)) 
                                                                           << 4U)) 
                                                                       | ((8U 
                                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                              >> 0x19U)) 
                                                                          | ((4U 
                                                                              & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                << 2U)) 
                                                                             | ((2U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1fU)))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21546(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21546\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_26 
        = ((0x100U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                      << 8U)) | ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                           << 6U)) 
                                 | ((0x40U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 2U)) 
                                              << 6U)) 
                                    | ((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 << 1U)) 
                                       | ((0x10U & 
                                           ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                >> 5U)) 
                                            << 4U)) 
                                          | ((8U & 
                                              ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 6U)) 
                                               << 3U)) 
                                             | ((4U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 0xcU)) 
                                                    << 2U)) 
                                                | ((2U 
                                                    & ((~ 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         >> 0xdU)) 
                                                       << 1U)) 
                                                   | (1U 
                                                      & (~ 
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                          >> 0xeU)))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_376 
        = ((0x80000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                        << 0x13U)) | ((0x40000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   << 0x11U)) 
                                      | ((0x20000U 
                                          & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 >> 2U)) 
                                             << 0x11U)) 
                                         | ((0x10000U 
                                             & ((~ 
                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 3U)) 
                                                << 0x10U)) 
                                            | ((0x8000U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   << 0xbU)) 
                                               | ((0x4000U 
                                                   & ((~ 
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                        >> 5U)) 
                                                      << 0xeU)) 
                                                  | ((0x2000U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         << 7U)) 
                                                     | ((0x1000U 
                                                         & ((~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                              >> 0xcU)) 
                                                            << 0xcU)) 
                                                        | ((0x800U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                 >> 0xdU)) 
                                                               << 0xbU)) 
                                                           | ((0x400U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                    >> 0xeU)) 
                                                                  << 0xaU)) 
                                                              | ((0x200U 
                                                                  & ((~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                       >> 0x14U)) 
                                                                     << 9U)) 
                                                                 | ((0x100U 
                                                                     & ((~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                          >> 0x15U)) 
                                                                        << 8U)) 
                                                                    | ((0x80U 
                                                                        & ((~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                             >> 0x16U)) 
                                                                           << 7U)) 
                                                                       | ((0x40U 
                                                                           & ((~ 
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x17U)) 
                                                                              << 6U)) 
                                                                          | ((0x20U 
                                                                              & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x18U)) 
                                                                                << 5U)) 
                                                                             | ((0x10U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1aU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                | ((2U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1fU))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21547(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21547\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_366 
        = ((0x4000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                       << 0xeU)) | ((0x2000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0xcU)) 
                                    | ((0x1000U & (
                                                   (~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                     >> 2U)) 
                                                   << 0xcU)) 
                                       | ((0x800U & 
                                           ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                >> 3U)) 
                                            << 0xbU)) 
                                          | ((0x400U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 << 6U)) 
                                             | ((0x200U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 5U)) 
                                                    << 9U)) 
                                                | ((0x100U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                       << 2U)) 
                                                   | ((0x80U 
                                                       & ((~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                            >> 0x16U)) 
                                                          << 7U)) 
                                                      | ((0x40U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                               >> 0x17U)) 
                                                             << 6U)) 
                                                         | ((0x20U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                  >> 0x18U)) 
                                                                << 5U)) 
                                                            | ((0x10U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                     >> 0x1aU)) 
                                                                   << 4U)) 
                                                               | ((8U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                        >> 0x1bU)) 
                                                                      << 3U)) 
                                                                  | ((4U 
                                                                      & ((~ 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                           >> 0x1dU)) 
                                                                         << 2U)) 
                                                                     | ((2U 
                                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                            >> 0x1dU)) 
                                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                           >> 0x1fU)))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_76 
        = ((0x400U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                      << 0xaU)) | ((0x200U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                              << 8U)) 
                                   | ((0x100U & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 2U)) 
                                                 << 8U)) 
                                      | ((0x80U & (
                                                   (~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                     >> 3U)) 
                                                   << 7U)) 
                                         | ((0x40U 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 2U)) 
                                            | ((0x20U 
                                                & ((~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                     >> 5U)) 
                                                   << 5U)) 
                                               | ((0x10U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 2U)) 
                                                  | ((8U 
                                                      & ((~ 
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                           >> 0x1aU)) 
                                                         << 3U)) 
                                                     | ((4U 
                                                         & ((~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                              >> 0x1dU)) 
                                                            << 2U)) 
                                                        | ((2U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                 >> 0x1eU)) 
                                                               << 1U)) 
                                                           | (1U 
                                                              & (~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                  >> 0x1fU)))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21548(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21548\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_306 
        = ((0x2000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                       << 0xdU)) | ((0x1000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0xbU)) 
                                    | ((0x800U & ((~ 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                    >> 2U)) 
                                                  << 0xbU)) 
                                       | ((0x400U & 
                                           ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                >> 3U)) 
                                            << 0xaU)) 
                                          | ((0x200U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 << 5U)) 
                                             | ((0x100U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 5U)) 
                                                    << 8U)) 
                                                | ((0x80U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                       << 1U)) 
                                                   | ((0x40U 
                                                       & ((~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                            >> 0xcU)) 
                                                          << 6U)) 
                                                      | ((0x20U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                               >> 0xeU)) 
                                                             << 5U)) 
                                                         | ((0x10U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                  >> 0x1aU)) 
                                                                << 4U)) 
                                                            | ((8U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                     >> 0x1bU)) 
                                                                   << 3U)) 
                                                               | ((4U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                        >> 0x1cU)) 
                                                                      << 2U)) 
                                                                  | ((2U 
                                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                         >> 0x1cU)) 
                                                                     | (1U 
                                                                        & (~ 
                                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                            >> 0x1eU))))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_308 
        = ((0x2000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                       << 0xdU)) | ((0x1000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0xbU)) 
                                    | ((0x800U & ((~ 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                    >> 2U)) 
                                                  << 0xbU)) 
                                       | ((0x400U & 
                                           ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                >> 3U)) 
                                            << 0xaU)) 
                                          | ((0x200U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 << 5U)) 
                                             | ((0x100U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 5U)) 
                                                    << 8U)) 
                                                | ((0x80U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                       << 1U)) 
                                                   | ((0x40U 
                                                       & ((~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                            >> 0xdU)) 
                                                          << 6U)) 
                                                      | ((0x20U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                               >> 0xeU)) 
                                                             << 5U)) 
                                                         | ((0x10U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                  >> 0x1aU)) 
                                                                << 4U)) 
                                                            | ((8U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                     >> 0x1bU)) 
                                                                   << 3U)) 
                                                               | ((4U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                        >> 0x1cU)) 
                                                                      << 2U)) 
                                                                  | ((2U 
                                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                         >> 0x1cU)) 
                                                                     | (1U 
                                                                        & (~ 
                                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                            >> 0x1eU))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21549(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21549\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_338 
        = ((0x20000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                        << 0x11U)) | ((0x10000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   << 0xfU)) 
                                      | ((0x8000U & 
                                          ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 2U)) 
                                           << 0xfU)) 
                                         | ((0x4000U 
                                             & ((~ 
                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 3U)) 
                                                << 0xeU)) 
                                            | ((0x2000U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   << 9U)) 
                                               | ((0x1000U 
                                                   & ((~ 
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                        >> 5U)) 
                                                      << 0xcU)) 
                                                  | ((0x800U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         << 5U)) 
                                                     | ((0x400U 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                            >> 0xaU)) 
                                                        | ((0x200U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                 >> 0x15U)) 
                                                               << 9U)) 
                                                           | ((0x100U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                    >> 0x16U)) 
                                                                  << 8U)) 
                                                              | ((0x80U 
                                                                  & ((~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                       >> 0x17U)) 
                                                                     << 7U)) 
                                                                 | ((0x40U 
                                                                     & ((~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                          >> 0x18U)) 
                                                                        << 6U)) 
                                                                    | ((0x20U 
                                                                        & ((~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                             >> 0x19U)) 
                                                                           << 5U)) 
                                                                       | ((0x10U 
                                                                           & ((~ 
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1aU)) 
                                                                              << 4U)) 
                                                                          | ((8U 
                                                                              & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                << 3U)) 
                                                                             | ((4U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1cU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1eU)))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21550(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21550\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_380 
        = ((0x80000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                        << 0x13U)) | ((0x40000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   << 0x11U)) 
                                      | ((0x20000U 
                                          & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 >> 2U)) 
                                             << 0x11U)) 
                                         | ((0x10000U 
                                             & ((~ 
                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 3U)) 
                                                << 0x10U)) 
                                            | ((0x8000U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   << 0xbU)) 
                                               | ((0x4000U 
                                                   & ((~ 
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                        >> 5U)) 
                                                      << 0xeU)) 
                                                  | ((0x2000U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         << 7U)) 
                                                     | ((0x1000U 
                                                         & ((~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                              >> 0xdU)) 
                                                            << 0xcU)) 
                                                        | ((0x800U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                 >> 0xeU)) 
                                                               << 0xbU)) 
                                                           | ((0x400U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                    >> 0x14U)) 
                                                                  << 0xaU)) 
                                                              | ((0x200U 
                                                                  & ((~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                       >> 0x15U)) 
                                                                     << 9U)) 
                                                                 | ((0x100U 
                                                                     & ((~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                          >> 0x16U)) 
                                                                        << 8U)) 
                                                                    | ((0x80U 
                                                                        & ((~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                             >> 0x17U)) 
                                                                           << 7U)) 
                                                                       | ((0x40U 
                                                                           & ((~ 
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x18U)) 
                                                                              << 6U)) 
                                                                          | ((0x20U 
                                                                              & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1aU)) 
                                                                                << 5U)) 
                                                                             | ((0x10U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1cU)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                | ((2U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1fU))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21551(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21551\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_314 
        = ((0x2000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                       << 0xdU)) | ((0x1000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0xbU)) 
                                    | ((0x800U & ((~ 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                    >> 2U)) 
                                                  << 0xbU)) 
                                       | ((0x400U & 
                                           ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                >> 3U)) 
                                            << 0xaU)) 
                                          | ((0x200U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 << 5U)) 
                                             | ((0x100U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 5U)) 
                                                    << 8U)) 
                                                | ((0x80U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                       << 1U)) 
                                                   | ((0x40U 
                                                       & ((~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                            >> 0xdU)) 
                                                          << 6U)) 
                                                      | ((0x20U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                               >> 0xeU)) 
                                                             << 5U)) 
                                                         | ((0x10U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                  >> 0x1aU)) 
                                                                << 4U)) 
                                                            | ((8U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                     >> 0x1cU)) 
                                                                   << 3U)) 
                                                               | ((4U 
                                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                      >> 0x1bU)) 
                                                                  | ((2U 
                                                                      & ((~ 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                           >> 0x1eU)) 
                                                                         << 1U)) 
                                                                     | (1U 
                                                                        & (~ 
                                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                            >> 0x1fU))))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_346 
        = ((0x20000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                        << 0x11U)) | ((0x10000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   << 0xfU)) 
                                      | ((0x8000U & 
                                          ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 2U)) 
                                           << 0xfU)) 
                                         | ((0x4000U 
                                             & ((~ 
                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 3U)) 
                                                << 0xeU)) 
                                            | ((0x2000U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   << 9U)) 
                                               | ((0x1000U 
                                                   & ((~ 
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                        >> 5U)) 
                                                      << 0xcU)) 
                                                  | ((0x800U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         << 5U)) 
                                                     | ((0x400U 
                                                         & ((~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                              >> 0x14U)) 
                                                            << 0xaU)) 
                                                        | ((0x200U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                 >> 0x15U)) 
                                                               << 9U)) 
                                                           | ((0x100U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                    >> 0x16U)) 
                                                                  << 8U)) 
                                                              | ((0x80U 
                                                                  & ((~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                       >> 0x17U)) 
                                                                     << 7U)) 
                                                                 | ((0x40U 
                                                                     & ((~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                          >> 0x18U)) 
                                                                        << 6U)) 
                                                                    | ((0x20U 
                                                                        & ((~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                             >> 0x1aU)) 
                                                                           << 5U)) 
                                                                       | ((0x10U 
                                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                              >> 0x17U)) 
                                                                          | ((8U 
                                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x19U)) 
                                                                             | ((4U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1fU))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21552(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21552\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_4 
        = ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                     << 7U)) | ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                          << 5U)) | 
                                ((0x20U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 2U)) 
                                           << 5U)) 
                                 | ((0x10U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 3U)) 
                                              << 4U)) 
                                    | ((8U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 4U)) 
                                              << 3U)) 
                                       | ((4U & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 5U)) 
                                                 << 2U)) 
                                          | ((2U & 
                                              ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 6U)) 
                                               << 1U)) 
                                             | (1U 
                                                & (~ 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                    >> 0xdU))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_176 
        = ((0x200U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                      << 9U)) | ((0x100U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                            << 7U)) 
                                 | ((0x80U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 2U)) 
                                              << 7U)) 
                                    | ((0x40U & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 3U)) 
                                                 << 6U)) 
                                       | ((0x20U & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                            << 1U)) 
                                          | ((0x10U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 >> 1U)) 
                                             | ((8U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                    >> 3U)) 
                                                | ((4U 
                                                    & ((~ 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         >> 0xcU)) 
                                                       << 2U)) 
                                                   | ((2U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                          >> 0xcU)) 
                                                      | (1U 
                                                         & (~ 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                             >> 0xeU))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21553(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21553\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_252 
        = ((0x4000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                       << 0xeU)) | ((0x2000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0xcU)) 
                                    | ((0x1000U & (
                                                   (~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                     >> 2U)) 
                                                   << 0xcU)) 
                                       | ((0x800U & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                            << 7U)) 
                                          | ((0x400U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 << 5U)) 
                                             | ((0x200U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 6U)) 
                                                    << 9U)) 
                                                | ((0x100U 
                                                    & ((~ 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         >> 0xcU)) 
                                                       << 8U)) 
                                                   | ((0x80U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                          >> 7U)) 
                                                      | ((0x40U 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                             >> 0x13U)) 
                                                         | ((0x20U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                  >> 0x1aU)) 
                                                                << 5U)) 
                                                            | ((0x10U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                     >> 0x1bU)) 
                                                                   << 4U)) 
                                                               | ((8U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                        >> 0x1cU)) 
                                                                      << 3U)) 
                                                                  | ((4U 
                                                                      & ((~ 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                           >> 0x1dU)) 
                                                                         << 2U)) 
                                                                     | ((2U 
                                                                         & ((~ 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                              >> 0x1eU)) 
                                                                            << 1U)) 
                                                                        | (1U 
                                                                           & (~ 
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                               >> 0x1fU)))))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_348 
        = ((0x40000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                        << 0x12U)) | ((0x20000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   << 0x10U)) 
                                      | ((0x10000U 
                                          & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 >> 2U)) 
                                             << 0x10U)) 
                                         | ((0x8000U 
                                             & ((~ 
                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 3U)) 
                                                << 0xfU)) 
                                            | ((0x4000U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   << 0xaU)) 
                                               | ((0x2000U 
                                                   & ((~ 
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                        >> 5U)) 
                                                      << 0xdU)) 
                                                  | ((0x1000U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         << 6U)) 
                                                     | ((0x800U 
                                                         & ((~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                              >> 0x14U)) 
                                                            << 0xbU)) 
                                                        | ((0x400U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                 >> 0x15U)) 
                                                               << 0xaU)) 
                                                           | ((0x200U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                    >> 0x16U)) 
                                                                  << 9U)) 
                                                              | ((0x100U 
                                                                  & ((~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                       >> 0x17U)) 
                                                                     << 8U)) 
                                                                 | ((0x80U 
                                                                     & ((~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                          >> 0x18U)) 
                                                                        << 7U)) 
                                                                    | ((0x40U 
                                                                        & ((~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                             >> 0x19U)) 
                                                                           << 6U)) 
                                                                       | ((0x20U 
                                                                           & ((~ 
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1aU)) 
                                                                              << 5U)) 
                                                                          | ((0x10U 
                                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x17U)) 
                                                                             | ((8U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1fU)))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21554(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21554\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_214 
        = ((0x100U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                      << 8U)) | ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                           << 6U)) 
                                 | ((0x40U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 2U)) 
                                              << 6U)) 
                                    | ((0x20U & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 3U)) 
                                                 << 5U)) 
                                       | ((0x10U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst) 
                                          | ((8U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 2U)) 
                                             | ((4U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                    >> 4U)) 
                                                | ((2U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                       >> 0xbU)) 
                                                   | (1U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         >> 0xeU))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_32 
        = ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                     << 6U)) | ((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                          << 4U)) | 
                                ((0x10U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                           << 2U)) 
                                 | ((8U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 3U)) 
                                           << 3U)) 
                                    | ((4U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                              >> 2U)) 
                                       | ((2U & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 5U)) 
                                                 << 1U)) 
                                          | (1U & (~ 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                    >> 6U)))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_298 
        = ((0x80000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                        << 0x13U)) | ((0x40000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   << 0x11U)) 
                                      | ((0x20000U 
                                          & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 >> 2U)) 
                                             << 0x11U)) 
                                         | ((0x10000U 
                                             & ((~ 
                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 3U)) 
                                                << 0x10U)) 
                                            | ((0x8000U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   << 0xbU)) 
                                               | ((0x4000U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      << 9U)) 
                                                  | ((0x2000U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         << 7U)) 
                                                     | ((0x1000U 
                                                         & ((~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                              >> 7U)) 
                                                            << 0xcU)) 
                                                        | ((0x800U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                 >> 8U)) 
                                                               << 0xbU)) 
                                                           | ((0x400U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                    >> 9U)) 
                                                                  << 0xaU)) 
                                                              | ((0x200U 
                                                                  & ((~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                       >> 0xcU)) 
                                                                     << 9U)) 
                                                                 | ((0x100U 
                                                                     & ((~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                          >> 0xdU)) 
                                                                        << 8U)) 
                                                                    | ((0x80U 
                                                                        & ((~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                             >> 0xeU)) 
                                                                           << 7U)) 
                                                                       | ((0x40U 
                                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                              >> 0x13U)) 
                                                                          | ((0x20U 
                                                                              & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1aU)) 
                                                                                << 5U)) 
                                                                             | ((0x10U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1fU))))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21555(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21555\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_112 
        = ((0x4000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                       << 0xeU)) | ((0x2000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0xcU)) 
                                    | ((0x1000U & (
                                                   (~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                     >> 2U)) 
                                                   << 0xcU)) 
                                       | ((0x800U & 
                                           ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                >> 3U)) 
                                            << 0xbU)) 
                                          | ((0x400U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 << 6U)) 
                                             | ((0x200U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      >> 5U)) 
                                                    << 9U)) 
                                                | ((0x100U 
                                                    & ((~ 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         >> 6U)) 
                                                       << 8U)) 
                                                   | ((0x80U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                          >> 5U)) 
                                                      | ((0x40U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                               >> 0xdU)) 
                                                             << 6U)) 
                                                         | ((0x20U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                  >> 0x1aU)) 
                                                                << 5U)) 
                                                            | ((0x10U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                     >> 0x1bU)) 
                                                                   << 4U)) 
                                                               | ((8U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                        >> 0x1cU)) 
                                                                      << 3U)) 
                                                                  | ((4U 
                                                                      & ((~ 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                           >> 0x1dU)) 
                                                                         << 2U)) 
                                                                     | ((2U 
                                                                         & ((~ 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                              >> 0x1eU)) 
                                                                            << 1U)) 
                                                                        | (1U 
                                                                           & (~ 
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                               >> 0x1fU)))))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_158 
        = ((0x400U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                      << 0xaU)) | ((0x200U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                              << 8U)) 
                                   | ((0x100U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 << 6U)) 
                                      | ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   << 4U)) 
                                         | ((0x40U 
                                             & ((~ 
                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 4U)) 
                                                << 6U)) 
                                            | ((0x20U 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst) 
                                               | ((0x10U 
                                                   & ((~ 
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                        >> 6U)) 
                                                      << 4U)) 
                                                  | ((8U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         >> 0xaU)) 
                                                     | ((4U 
                                                         & ((~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                              >> 0xeU)) 
                                                            << 2U)) 
                                                        | ((2U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                 >> 0x1bU)) 
                                                               << 1U)) 
                                                           | (1U 
                                                              & (~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                  >> 0x1cU)))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21556(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21556\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_266 
        = ((0x1000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                       << 0xcU)) | ((0x800U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               << 0xaU)) 
                                    | ((0x400U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  << 8U)) 
                                       | ((0x200U & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                            << 6U)) 
                                          | ((0x100U 
                                              & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 4U)) 
                                                 << 8U)) 
                                             | ((0x80U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                    << 2U)) 
                                                | ((0x40U 
                                                    & ((~ 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         >> 6U)) 
                                                       << 6U)) 
                                                   | ((0x20U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                          >> 8U)) 
                                                      | ((0x10U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                               >> 0xeU)) 
                                                             << 4U)) 
                                                         | ((8U 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                >> 0x18U)) 
                                                            | ((4U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                     >> 0x1dU)) 
                                                                   << 2U)) 
                                                               | ((2U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                        >> 0x1eU)) 
                                                                      << 1U)) 
                                                                  | (1U 
                                                                     & (~ 
                                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                         >> 0x1fU)))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_100 
        = ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                     << 6U)) | ((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                          << 4U)) | 
                                ((0x10U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                           << 2U)) 
                                 | ((8U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst) 
                                    | ((4U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 4U)) 
                                              << 2U)) 
                                       | ((2U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 >> 4U)) 
                                          | (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 6U))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21557(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21557\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_342 
        = ((0x20000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                        << 0x11U)) | ((0x10000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   << 0xfU)) 
                                      | ((0x8000U & 
                                          ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 2U)) 
                                           << 0xfU)) 
                                         | ((0x4000U 
                                             & ((~ 
                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 3U)) 
                                                << 0xeU)) 
                                            | ((0x2000U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   << 9U)) 
                                               | ((0x1000U 
                                                   & ((~ 
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                        >> 5U)) 
                                                      << 0xcU)) 
                                                  | ((0x800U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                         << 5U)) 
                                                     | ((0x400U 
                                                         & ((~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                              >> 0x14U)) 
                                                            << 0xaU)) 
                                                        | ((0x200U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                 >> 0x15U)) 
                                                               << 9U)) 
                                                           | ((0x100U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                    >> 0x16U)) 
                                                                  << 8U)) 
                                                              | ((0x80U 
                                                                  & ((~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                       >> 0x17U)) 
                                                                     << 7U)) 
                                                                 | ((0x40U 
                                                                     & ((~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                          >> 0x18U)) 
                                                                        << 6U)) 
                                                                    | ((0x20U 
                                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                           >> 0x14U)) 
                                                                       | ((0x10U 
                                                                           & ((~ 
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1aU)) 
                                                                              << 4U)) 
                                                                          | ((8U 
                                                                              & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                << 3U)) 
                                                                             | ((4U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1cU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1eU)))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21558(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21558\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_168 
        = ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                     << 7U)) | ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                          << 5U)) | 
                                ((0x20U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 2U)) 
                                           << 5U)) 
                                 | ((0x10U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 3U)) 
                                              << 4U)) 
                                    | ((8U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                              >> 1U)) 
                                       | ((4U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 >> 3U)) 
                                          | ((2U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 5U)) 
                                             | (1U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 0xdU)))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_132 
        = ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                     << 7U)) | ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                          << 5U)) | 
                                ((0x20U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 2U)) 
                                           << 5U)) 
                                 | ((0x10U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                  >> 3U)) 
                                              << 4U)) 
                                    | ((8U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                              >> 1U)) 
                                       | ((4U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 >> 3U)) 
                                          | ((2U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                               >> 5U)) 
                                             | (1U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   >> 0xcU)))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_104 
        = ((0x10000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                           << 0x1cU)) | ((0x8000000U 
                                          & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 >> 3U)) 
                                             << 0x1bU)) 
                                         | ((0x4000000U 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0x16U)) 
                                            | ((0x2000000U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   << 0x14U)) 
                                               | ((0x1000000U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      << 0x12U)) 
                                                  | ((0x800000U 
                                                      & ((~ 
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                           >> 7U)) 
                                                         << 0x17U)) 
                                                     | ((0x400000U 
                                                         & ((~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                              >> 8U)) 
                                                            << 0x16U)) 
                                                        | ((0x200000U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                 >> 9U)) 
                                                               << 0x15U)) 
                                                           | ((0x100000U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                    >> 0xaU)) 
                                                                  << 0x14U)) 
                                                              | ((0x80000U 
                                                                  & ((~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                       >> 0xbU)) 
                                                                     << 0x13U)) 
                                                                 | ((0x40000U 
                                                                     & ((~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                          >> 0xcU)) 
                                                                        << 0x12U)) 
                                                                    | ((0x20000U 
                                                                        & ((~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                             >> 0xdU)) 
                                                                           << 0x11U)) 
                                                                       | ((0x10000U 
                                                                           & ((~ 
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0xeU)) 
                                                                              << 0x10U)) 
                                                                          | ((0x8000U 
                                                                              & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0xfU)) 
                                                                                << 0xfU)) 
                                                                             | ((0x4000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x10U)) 
                                                                                << 0xeU)) 
                                                                                | ((0x2000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x11U)) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x12U)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x13U)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x15U)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x16U)) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x17U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x18U)) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x19U)) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1aU)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1cU)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1fU)))))))))))))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21559(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21559\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_282 
        = ((0x10000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                           << 0x1cU)) | ((0x8000000U 
                                          & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                 >> 3U)) 
                                             << 0x1bU)) 
                                         | ((0x4000000U 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0x16U)) 
                                            | ((0x2000000U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                   << 0x14U)) 
                                               | ((0x1000000U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                      << 0x12U)) 
                                                  | ((0x800000U 
                                                      & ((~ 
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                           >> 7U)) 
                                                         << 0x17U)) 
                                                     | ((0x400000U 
                                                         & ((~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                              >> 8U)) 
                                                            << 0x16U)) 
                                                        | ((0x200000U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                 >> 9U)) 
                                                               << 0x15U)) 
                                                           | ((0x100000U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                    >> 0xaU)) 
                                                                  << 0x14U)) 
                                                              | ((0x80000U 
                                                                  & ((~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                       >> 0xbU)) 
                                                                     << 0x13U)) 
                                                                 | ((0x40000U 
                                                                     & ((~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                          >> 0xcU)) 
                                                                        << 0x12U)) 
                                                                    | ((0x20000U 
                                                                        & ((~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                             >> 0xdU)) 
                                                                           << 0x11U)) 
                                                                       | ((0x10000U 
                                                                           & ((~ 
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0xeU)) 
                                                                              << 0x10U)) 
                                                                          | ((0x8000U 
                                                                              & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0xfU)) 
                                                                                << 0xfU)) 
                                                                             | ((0x4000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x10U)) 
                                                                                << 0xeU)) 
                                                                                | ((0x2000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x11U)) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x12U)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x13U)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x14U)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0xcU)) 
                                                                                | ((0x100U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x16U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x17U)) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x18U)) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x19U)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1aU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1aU)) 
                                                                                | ((2U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1fU)))))))))))))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21560(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21560\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_354 
        = ((0x10000000U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                               >> 3U)) << 0x1cU)) | 
           ((0x8000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                           << 0x17U)) | ((0x4000000U 
                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                             << 0x15U)) 
                                         | ((0x2000000U 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0x13U)) 
                                            | ((0x1000000U 
                                                & ((~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                     >> 7U)) 
                                                   << 0x18U)) 
                                               | ((0x800000U 
                                                   & ((~ 
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                        >> 8U)) 
                                                      << 0x17U)) 
                                                  | ((0x400000U 
                                                      & ((~ 
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                           >> 9U)) 
                                                         << 0x16U)) 
                                                     | ((0x200000U 
                                                         & ((~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                              >> 0xaU)) 
                                                            << 0x15U)) 
                                                        | ((0x100000U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                 >> 0xbU)) 
                                                               << 0x14U)) 
                                                           | ((0x80000U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                    >> 0xcU)) 
                                                                  << 0x13U)) 
                                                              | ((0x40000U 
                                                                  & ((~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                       >> 0xdU)) 
                                                                     << 0x12U)) 
                                                                 | ((0x20000U 
                                                                     & ((~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                          >> 0xeU)) 
                                                                        << 0x11U)) 
                                                                    | ((0x10000U 
                                                                        & ((~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                             >> 0xfU)) 
                                                                           << 0x10U)) 
                                                                       | ((0x8000U 
                                                                           & ((~ 
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x10U)) 
                                                                              << 0xfU)) 
                                                                          | ((0x4000U 
                                                                              & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x11U)) 
                                                                                << 0xeU)) 
                                                                             | ((0x2000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x12U)) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x13U)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x14U)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0xbU)) 
                                                                                | ((0x200U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x16U)) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x17U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x11U)) 
                                                                                | ((0x40U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x13U)) 
                                                                                | ((0x20U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1aU)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x17U)) 
                                                                                | ((8U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                | ((2U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1fU)))))))))))))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21561(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21561\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_1__DOT___cs_decoder_decoded_T_288 
        = ((0x10000000U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                               >> 3U)) << 0x1cU)) | 
           ((0x8000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                           << 0x17U)) | ((0x4000000U 
                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                             << 0x15U)) 
                                         | ((0x2000000U 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                << 0x13U)) 
                                            | ((0x1000000U 
                                                & ((~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                     >> 7U)) 
                                                   << 0x18U)) 
                                               | ((0x800000U 
                                                   & ((~ 
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                        >> 8U)) 
                                                      << 0x17U)) 
                                                  | ((0x400000U 
                                                      & ((~ 
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                           >> 9U)) 
                                                         << 0x16U)) 
                                                     | ((0x200000U 
                                                         & ((~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                              >> 0xaU)) 
                                                            << 0x15U)) 
                                                        | ((0x100000U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                 >> 0xbU)) 
                                                               << 0x14U)) 
                                                           | ((0x80000U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                    >> 0xcU)) 
                                                                  << 0x13U)) 
                                                              | ((0x40000U 
                                                                  & ((~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                       >> 0xdU)) 
                                                                     << 0x12U)) 
                                                                 | ((0x20000U 
                                                                     & ((~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                          >> 0xeU)) 
                                                                        << 0x11U)) 
                                                                    | ((0x10000U 
                                                                        & ((~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                             >> 0xfU)) 
                                                                           << 0x10U)) 
                                                                       | ((0x8000U 
                                                                           & ((~ 
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x10U)) 
                                                                              << 0xfU)) 
                                                                          | ((0x4000U 
                                                                              & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x11U)) 
                                                                                << 0xeU)) 
                                                                             | ((0x2000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x12U)) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x13U)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 9U)) 
                                                                                | ((0x400U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x15U)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0xdU)) 
                                                                                | ((0x100U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x17U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x18U)) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x19U)) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1aU)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_1_bits_inst 
                                                                                >> 0x1fU)))))))))))))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21562(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21562\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_294 
        = ((0x10000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                        << 0x10U)) | ((0x8000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                  << 0xeU)) 
                                      | ((0x4000U & 
                                          ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                               >> 2U)) 
                                           << 0xeU)) 
                                         | ((0x2000U 
                                             & ((~ 
                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                  >> 3U)) 
                                                << 0xdU)) 
                                            | ((0x1000U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                   << 8U)) 
                                               | ((0x800U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                      << 6U)) 
                                                  | ((0x400U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                         << 4U)) 
                                                     | ((0x200U 
                                                         & ((~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                              >> 7U)) 
                                                            << 9U)) 
                                                        | ((0x100U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                 >> 8U)) 
                                                               << 8U)) 
                                                           | ((0x80U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                    >> 9U)) 
                                                                  << 7U)) 
                                                              | ((0x40U 
                                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                     >> 0x13U)) 
                                                                 | ((0x20U 
                                                                     & ((~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                          >> 0x1aU)) 
                                                                        << 5U)) 
                                                                    | ((0x10U 
                                                                        & ((~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                             >> 0x1bU)) 
                                                                           << 4U)) 
                                                                       | ((8U 
                                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                              >> 0x19U)) 
                                                                          | ((4U 
                                                                              & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                << 2U)) 
                                                                             | ((2U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1fU)))))))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_304 
        = ((0x2000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                       << 0xdU)) | ((0x1000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                << 0xbU)) 
                                    | ((0x800U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                  << 9U)) 
                                       | ((0x400U & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                            << 7U)) 
                                          | ((0x200U 
                                              & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                   >> 4U)) 
                                                 << 9U)) 
                                             | ((0x100U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                    << 3U)) 
                                                | ((0x80U 
                                                    & ((~ 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                         >> 6U)) 
                                                       << 7U)) 
                                                   | ((0x40U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                          >> 7U)) 
                                                      | ((0x20U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                               >> 0xeU)) 
                                                             << 5U)) 
                                                         | ((0x10U 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                >> 0x17U)) 
                                                            | ((8U 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                   >> 0x19U)) 
                                                               | ((4U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                        >> 0x1dU)) 
                                                                      << 2U)) 
                                                                  | ((2U 
                                                                      & ((~ 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                           >> 0x1eU)) 
                                                                         << 1U)) 
                                                                     | (1U 
                                                                        & (~ 
                                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                            >> 0x1fU))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21563(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21563\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_24 
        = ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                     << 7U)) | ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                          << 5U)) | 
                                ((0x20U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                               >> 2U)) 
                                           << 5U)) 
                                 | ((0x10U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                  >> 3U)) 
                                              << 4U)) 
                                    | ((8U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                              >> 1U)) 
                                       | ((4U & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                   >> 5U)) 
                                                 << 2U)) 
                                          | ((2U & 
                                              ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                   >> 6U)) 
                                               << 1U)) 
                                             | (1U 
                                                & (~ 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                    >> 0xcU))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_44 
        = ((0x2000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                       << 0xdU)) | ((0x1000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                << 0xbU)) 
                                    | ((0x800U & ((~ 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                    >> 2U)) 
                                                  << 0xbU)) 
                                       | ((0x400U & 
                                           ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                >> 3U)) 
                                            << 0xaU)) 
                                          | ((0x200U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                 << 5U)) 
                                             | ((0x100U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                    << 3U)) 
                                                | ((0x80U 
                                                    & ((~ 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                         >> 6U)) 
                                                       << 7U)) 
                                                   | ((0x40U 
                                                       & ((~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                            >> 0x19U)) 
                                                          << 6U)) 
                                                      | ((0x20U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                               >> 0x1aU)) 
                                                             << 5U)) 
                                                         | ((0x10U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                  >> 0x1bU)) 
                                                                << 4U)) 
                                                            | ((8U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                     >> 0x1cU)) 
                                                                   << 3U)) 
                                                               | ((4U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                        >> 0x1dU)) 
                                                                      << 2U)) 
                                                                  | ((2U 
                                                                      & ((~ 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                           >> 0x1eU)) 
                                                                         << 1U)) 
                                                                     | (1U 
                                                                        & (~ 
                                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                            >> 0x1fU))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21564(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21564\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_52 
        = ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                     << 6U)) | ((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                          << 4U)) | 
                                ((0x10U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                           << 2U)) 
                                 | ((8U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                               >> 3U)) 
                                           << 3U)) 
                                    | ((4U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                              >> 2U)) 
                                       | ((2U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                 >> 4U)) 
                                          | (1U & (~ 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                    >> 6U)))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_2 
        = ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                     << 7U)) | ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                          << 5U)) | 
                                ((0x20U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                               >> 2U)) 
                                           << 5U)) 
                                 | ((0x10U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                  >> 3U)) 
                                              << 4U)) 
                                    | ((8U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                  >> 4U)) 
                                              << 3U)) 
                                       | ((4U & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                   >> 5U)) 
                                                 << 2U)) 
                                          | ((2U & 
                                              ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                   >> 6U)) 
                                               << 1U)) 
                                             | (1U 
                                                & (~ 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                    >> 0xcU))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_340 
        = ((0x40000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                        << 0x12U)) | ((0x20000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                   << 0x10U)) 
                                      | ((0x10000U 
                                          & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                 >> 2U)) 
                                             << 0x10U)) 
                                         | ((0x8000U 
                                             & ((~ 
                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                  >> 3U)) 
                                                << 0xfU)) 
                                            | ((0x4000U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                   << 0xaU)) 
                                               | ((0x2000U 
                                                   & ((~ 
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                        >> 5U)) 
                                                      << 0xdU)) 
                                                  | ((0x1000U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                         << 6U)) 
                                                     | ((0x800U 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                            >> 9U)) 
                                                        | ((0x400U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                 >> 0x15U)) 
                                                               << 0xaU)) 
                                                           | ((0x200U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                    >> 0x16U)) 
                                                                  << 9U)) 
                                                              | ((0x100U 
                                                                  & ((~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                       >> 0x17U)) 
                                                                     << 8U)) 
                                                                 | ((0x80U 
                                                                     & ((~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                          >> 0x18U)) 
                                                                        << 7U)) 
                                                                    | ((0x40U 
                                                                        & ((~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                             >> 0x19U)) 
                                                                           << 6U)) 
                                                                       | ((0x20U 
                                                                           & ((~ 
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1aU)) 
                                                                              << 5U)) 
                                                                          | ((0x10U 
                                                                              & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                << 4U)) 
                                                                             | ((8U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1cU)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1fU)))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21565(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21565\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_344 
        = ((0x40000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                        << 0x12U)) | ((0x20000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                   << 0x10U)) 
                                      | ((0x10000U 
                                          & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                 >> 2U)) 
                                             << 0x10U)) 
                                         | ((0x8000U 
                                             & ((~ 
                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                  >> 3U)) 
                                                << 0xfU)) 
                                            | ((0x4000U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                   << 0xaU)) 
                                               | ((0x2000U 
                                                   & ((~ 
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                        >> 5U)) 
                                                      << 0xdU)) 
                                                  | ((0x1000U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                         << 6U)) 
                                                     | ((0x800U 
                                                         & ((~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                              >> 0x14U)) 
                                                            << 0xbU)) 
                                                        | ((0x400U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                 >> 0x15U)) 
                                                               << 0xaU)) 
                                                           | ((0x200U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                    >> 0x16U)) 
                                                                  << 9U)) 
                                                              | ((0x100U 
                                                                  & ((~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                       >> 0x17U)) 
                                                                     << 8U)) 
                                                                 | ((0x80U 
                                                                     & ((~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                          >> 0x18U)) 
                                                                        << 7U)) 
                                                                    | ((0x40U 
                                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                           >> 0x13U)) 
                                                                       | ((0x20U 
                                                                           & ((~ 
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1aU)) 
                                                                              << 5U)) 
                                                                          | ((0x10U 
                                                                              & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                << 4U)) 
                                                                             | ((8U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1cU)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1fU)))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21566(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21566\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_374 
        = ((0x8000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                       << 0xfU)) | ((0x4000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                << 0xdU)) 
                                    | ((0x2000U & (
                                                   (~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                     >> 2U)) 
                                                   << 0xdU)) 
                                       | ((0x1000U 
                                           & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                  >> 3U)) 
                                              << 0xcU)) 
                                          | ((0x800U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                 << 7U)) 
                                             | ((0x400U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                      >> 5U)) 
                                                    << 0xaU)) 
                                                | ((0x200U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                       << 3U)) 
                                                   | ((0x100U 
                                                       & ((~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                            >> 0x16U)) 
                                                          << 8U)) 
                                                      | ((0x80U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                               >> 0x17U)) 
                                                             << 7U)) 
                                                         | ((0x40U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                  >> 0x18U)) 
                                                                << 6U)) 
                                                            | ((0x20U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                     >> 0x1aU)) 
                                                                   << 5U)) 
                                                               | ((0x10U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                        >> 0x1bU)) 
                                                                      << 4U)) 
                                                                  | ((8U 
                                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                         >> 0x19U)) 
                                                                     | ((4U 
                                                                         & ((~ 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                              >> 0x1dU)) 
                                                                            << 2U)) 
                                                                        | ((2U 
                                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                               >> 0x1dU)) 
                                                                           | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                              >> 0x1fU))))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_390 
        = ((0x100000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                         << 0x14U)) | ((0x80000U & 
                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                         << 0x12U)) 
                                       | ((0x40000U 
                                           & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                  >> 2U)) 
                                              << 0x12U)) 
                                          | ((0x20000U 
                                              & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                   >> 3U)) 
                                                 << 0x11U)) 
                                             | ((0x10000U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                    << 0xcU)) 
                                                | ((0x8000U 
                                                    & ((~ 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                         >> 5U)) 
                                                       << 0xfU)) 
                                                   | ((0x4000U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                          << 8U)) 
                                                      | ((0x2000U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                               >> 0xcU)) 
                                                             << 0xdU)) 
                                                         | ((0x1000U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                  >> 0xdU)) 
                                                                << 0xcU)) 
                                                            | ((0x800U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                     >> 0xeU)) 
                                                                   << 0xbU)) 
                                                               | ((0x400U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                        >> 0x14U)) 
                                                                      << 0xaU)) 
                                                                  | ((0x200U 
                                                                      & ((~ 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                           >> 0x15U)) 
                                                                         << 9U)) 
                                                                     | ((0x100U 
                                                                         & ((~ 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                              >> 0x16U)) 
                                                                            << 8U)) 
                                                                        | ((0x80U 
                                                                            & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x17U)) 
                                                                               << 7U)) 
                                                                           | ((0x40U 
                                                                               & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x18U)) 
                                                                                << 6U)) 
                                                                              | ((0x20U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1aU)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                | ((2U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1fU)))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21567(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21567\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_156 
        = ((0x100U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                      << 8U)) | ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                           << 6U)) 
                                 | ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                              << 4U)) 
                                    | ((0x20U & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                   >> 3U)) 
                                                 << 5U)) 
                                       | ((0x10U & 
                                           ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                >> 4U)) 
                                            << 4U)) 
                                          | ((8U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                               >> 2U)) 
                                             | ((4U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                      >> 6U)) 
                                                    << 2U)) 
                                                | ((2U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                       >> 0xcU)) 
                                                   | (1U 
                                                      & (~ 
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                          >> 0xeU)))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_106 
        = ((0x40000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                           << 0x1eU)) | ((0x20000000U 
                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                             << 0x1cU)) 
                                         | ((0x10000000U 
                                             & ((~ 
                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                  >> 2U)) 
                                                << 0x1cU)) 
                                            | ((0x8000000U 
                                                & ((~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                     >> 3U)) 
                                                   << 0x1bU)) 
                                               | ((0x4000000U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                      << 0x16U)) 
                                                  | ((0x2000000U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                         << 0x14U)) 
                                                     | ((0x1000000U 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                            << 0x12U)) 
                                                        | ((0x800000U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                 >> 7U)) 
                                                               << 0x17U)) 
                                                           | ((0x400000U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                    >> 8U)) 
                                                                  << 0x16U)) 
                                                              | ((0x200000U 
                                                                  & ((~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                       >> 9U)) 
                                                                     << 0x15U)) 
                                                                 | ((0x100000U 
                                                                     & ((~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                          >> 0xaU)) 
                                                                        << 0x14U)) 
                                                                    | ((0x80000U 
                                                                        & ((~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                             >> 0xbU)) 
                                                                           << 0x13U)) 
                                                                       | ((0x40000U 
                                                                           & ((~ 
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0xcU)) 
                                                                              << 0x12U)) 
                                                                          | ((0x20000U 
                                                                              & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0xdU)) 
                                                                                << 0x11U)) 
                                                                             | ((0x10000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0xeU)) 
                                                                                << 0x10U)) 
                                                                                | ((0x8000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0xfU)) 
                                                                                << 0xfU)) 
                                                                                | ((0x4000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x10U)) 
                                                                                << 0xeU)) 
                                                                                | ((0x2000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x11U)) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x12U)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x13U)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x15U)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x16U)) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x17U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x18U)) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x19U)) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1aU)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1cU)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1fU)))))))))))))))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21568(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21568\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_284 
        = ((0x40000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                           << 0x1eU)) | ((0x20000000U 
                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                             << 0x1cU)) 
                                         | ((0x10000000U 
                                             & ((~ 
                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                  >> 2U)) 
                                                << 0x1cU)) 
                                            | ((0x8000000U 
                                                & ((~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                     >> 3U)) 
                                                   << 0x1bU)) 
                                               | ((0x4000000U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                      << 0x16U)) 
                                                  | ((0x2000000U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                         << 0x14U)) 
                                                     | ((0x1000000U 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                            << 0x12U)) 
                                                        | ((0x800000U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                 >> 7U)) 
                                                               << 0x17U)) 
                                                           | ((0x400000U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                    >> 8U)) 
                                                                  << 0x16U)) 
                                                              | ((0x200000U 
                                                                  & ((~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                       >> 9U)) 
                                                                     << 0x15U)) 
                                                                 | ((0x100000U 
                                                                     & ((~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                          >> 0xaU)) 
                                                                        << 0x14U)) 
                                                                    | ((0x80000U 
                                                                        & ((~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                             >> 0xbU)) 
                                                                           << 0x13U)) 
                                                                       | ((0x40000U 
                                                                           & ((~ 
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0xcU)) 
                                                                              << 0x12U)) 
                                                                          | ((0x20000U 
                                                                              & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0xdU)) 
                                                                                << 0x11U)) 
                                                                             | ((0x10000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0xeU)) 
                                                                                << 0x10U)) 
                                                                                | ((0x8000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0xfU)) 
                                                                                << 0xfU)) 
                                                                                | ((0x4000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x10U)) 
                                                                                << 0xeU)) 
                                                                                | ((0x2000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x11U)) 
                                                                                << 0xdU)) 
                                                                                | ((0x1000U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x12U)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x13U)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x14U)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0xcU)) 
                                                                                | ((0x100U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x16U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x17U)) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x18U)) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x19U)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1aU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1aU)) 
                                                                                | ((2U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1fU)))))))))))))))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21569(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21569\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_290 
        = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
            << 0x1fU) | ((0x40000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                         << 0x1dU)) 
                         | ((0x20000000U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                >> 2U)) 
                                            << 0x1dU)) 
                            | ((0x10000000U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                   >> 3U)) 
                                               << 0x1cU)) 
                               | ((0x8000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                 << 0x17U)) 
                                  | ((0x4000000U & 
                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                       << 0x15U)) | 
                                     ((0x2000000U & 
                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                        << 0x13U)) 
                                      | ((0x1000000U 
                                          & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                 >> 7U)) 
                                             << 0x18U)) 
                                         | ((0x800000U 
                                             & ((~ 
                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                  >> 8U)) 
                                                << 0x17U)) 
                                            | ((0x400000U 
                                                & ((~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                     >> 9U)) 
                                                   << 0x16U)) 
                                               | ((0x200000U 
                                                   & ((~ 
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                        >> 0xaU)) 
                                                      << 0x15U)) 
                                                  | ((0x100000U 
                                                      & ((~ 
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                           >> 0xbU)) 
                                                         << 0x14U)) 
                                                     | ((0x80000U 
                                                         & ((~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                              >> 0xcU)) 
                                                            << 0x13U)) 
                                                        | ((0x40000U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                 >> 0xdU)) 
                                                               << 0x12U)) 
                                                           | ((0x20000U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                    >> 0xeU)) 
                                                                  << 0x11U)) 
                                                              | ((0x10000U 
                                                                  & ((~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                       >> 0xfU)) 
                                                                     << 0x10U)) 
                                                                 | ((0x8000U 
                                                                     & ((~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                          >> 0x10U)) 
                                                                        << 0xfU)) 
                                                                    | ((0x4000U 
                                                                        & ((~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                             >> 0x11U)) 
                                                                           << 0xeU)) 
                                                                       | ((0x2000U 
                                                                           & ((~ 
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x12U)) 
                                                                              << 0xdU)) 
                                                                          | ((0x1000U 
                                                                              & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x13U)) 
                                                                                << 0xcU)) 
                                                                             | ((0x800U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 9U)) 
                                                                                | ((0x400U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x15U)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0xdU)) 
                                                                                | ((0x100U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x17U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x18U)) 
                                                                                << 7U)) 
                                                                                | ((0x40U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x19U)) 
                                                                                << 6U)) 
                                                                                | ((0x20U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1aU)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1fU))))))))))))))))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21570(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21570\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_356 
        = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
            << 0x1fU) | ((0x40000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                         << 0x1dU)) 
                         | ((0x20000000U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                >> 2U)) 
                                            << 0x1dU)) 
                            | ((0x10000000U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                   >> 3U)) 
                                               << 0x1cU)) 
                               | ((0x8000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                 << 0x17U)) 
                                  | ((0x4000000U & 
                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                       << 0x15U)) | 
                                     ((0x2000000U & 
                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                        << 0x13U)) 
                                      | ((0x1000000U 
                                          & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                 >> 7U)) 
                                             << 0x18U)) 
                                         | ((0x800000U 
                                             & ((~ 
                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                  >> 8U)) 
                                                << 0x17U)) 
                                            | ((0x400000U 
                                                & ((~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                     >> 9U)) 
                                                   << 0x16U)) 
                                               | ((0x200000U 
                                                   & ((~ 
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                        >> 0xaU)) 
                                                      << 0x15U)) 
                                                  | ((0x100000U 
                                                      & ((~ 
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                           >> 0xbU)) 
                                                         << 0x14U)) 
                                                     | ((0x80000U 
                                                         & ((~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                              >> 0xcU)) 
                                                            << 0x13U)) 
                                                        | ((0x40000U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                 >> 0xdU)) 
                                                               << 0x12U)) 
                                                           | ((0x20000U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                    >> 0xeU)) 
                                                                  << 0x11U)) 
                                                              | ((0x10000U 
                                                                  & ((~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                       >> 0xfU)) 
                                                                     << 0x10U)) 
                                                                 | ((0x8000U 
                                                                     & ((~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                          >> 0x10U)) 
                                                                        << 0xfU)) 
                                                                    | ((0x4000U 
                                                                        & ((~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                             >> 0x11U)) 
                                                                           << 0xeU)) 
                                                                       | ((0x2000U 
                                                                           & ((~ 
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x12U)) 
                                                                              << 0xdU)) 
                                                                          | ((0x1000U 
                                                                              & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x13U)) 
                                                                                << 0xcU)) 
                                                                             | ((0x800U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x14U)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0xbU)) 
                                                                                | ((0x200U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x16U)) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x17U)) 
                                                                                << 8U)) 
                                                                                | ((0x80U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x11U)) 
                                                                                | ((0x40U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x13U)) 
                                                                                | ((0x20U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1aU)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x17U)) 
                                                                                | ((8U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                | ((2U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1fU))))))))))))))))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21571(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21571\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_300 
        = ((0x200000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                         << 0x15U)) | ((0x100000U & 
                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                         << 0x13U)) 
                                       | ((0x80000U 
                                           & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                  >> 2U)) 
                                              << 0x13U)) 
                                          | ((0x40000U 
                                              & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                   >> 3U)) 
                                                 << 0x12U)) 
                                             | ((0x20000U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                    << 0xdU)) 
                                                | ((0x10000U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                       << 0xbU)) 
                                                   | ((0x8000U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                          << 9U)) 
                                                      | ((0x4000U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                               >> 7U)) 
                                                             << 0xeU)) 
                                                         | ((0x2000U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                  >> 8U)) 
                                                                << 0xdU)) 
                                                            | ((0x1000U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                     >> 9U)) 
                                                                   << 0xcU)) 
                                                               | ((0x800U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                        >> 0xaU)) 
                                                                      << 0xbU)) 
                                                                  | ((0x400U 
                                                                      & ((~ 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                           >> 0xbU)) 
                                                                         << 0xaU)) 
                                                                     | ((0x200U 
                                                                         & ((~ 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                              >> 0xcU)) 
                                                                            << 9U)) 
                                                                        | ((0x100U 
                                                                            & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0xdU)) 
                                                                               << 8U)) 
                                                                           | ((0x80U 
                                                                               & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0xeU)) 
                                                                                << 7U)) 
                                                                              | ((0x40U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x13U)) 
                                                                                | ((0x20U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1aU)) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1fU))))))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21572(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21572\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_10 
        = ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                     << 7U)) | ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                          << 5U)) | 
                                ((0x20U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                               >> 2U)) 
                                           << 5U)) 
                                 | ((0x10U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                  >> 5U)) 
                                              << 4U)) 
                                    | ((8U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                  >> 6U)) 
                                              << 3U)) 
                                       | ((4U & ((~ 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                   >> 0xcU)) 
                                                 << 2U)) 
                                          | ((2U & 
                                              ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                   >> 0xdU)) 
                                               << 1U)) 
                                             | (1U 
                                                & (~ 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                    >> 0xeU))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_40 
        = ((0x1000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                       << 0xcU)) | ((0x800U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                               << 0xaU)) 
                                    | ((0x400U & ((~ 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                    >> 2U)) 
                                                  << 0xaU)) 
                                       | ((0x200U & 
                                           ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                >> 3U)) 
                                            << 9U)) 
                                          | ((0x100U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                 << 4U)) 
                                             | ((0x80U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                    << 2U)) 
                                                | ((0x40U 
                                                    & ((~ 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                         >> 6U)) 
                                                       << 6U)) 
                                                   | ((0x20U 
                                                       & ((~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                            >> 0x1aU)) 
                                                          << 5U)) 
                                                      | ((0x10U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                               >> 0x1bU)) 
                                                             << 4U)) 
                                                         | ((8U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                  >> 0x1cU)) 
                                                                << 3U)) 
                                                            | ((4U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                     >> 0x1dU)) 
                                                                   << 2U)) 
                                                               | ((2U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                        >> 0x1eU)) 
                                                                      << 1U)) 
                                                                  | (1U 
                                                                     & (~ 
                                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                         >> 0x1fU)))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21573(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21573\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_42 
        = ((0x4000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                       << 0xeU)) | ((0x2000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                << 0xcU)) 
                                    | ((0x1000U & (
                                                   (~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                     >> 2U)) 
                                                   << 0xcU)) 
                                       | ((0x800U & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                            << 7U)) 
                                          | ((0x400U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                 << 5U)) 
                                             | ((0x200U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                      >> 6U)) 
                                                    << 9U)) 
                                                | ((0x100U 
                                                    & ((~ 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                         >> 0xcU)) 
                                                       << 8U)) 
                                                   | ((0x80U 
                                                       & ((~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                            >> 0xdU)) 
                                                          << 7U)) 
                                                      | ((0x40U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                               >> 0xeU)) 
                                                             << 6U)) 
                                                         | ((0x20U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                  >> 0x1aU)) 
                                                                << 5U)) 
                                                            | ((0x10U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                     >> 0x1bU)) 
                                                                   << 4U)) 
                                                               | ((8U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                        >> 0x1cU)) 
                                                                      << 3U)) 
                                                                  | ((4U 
                                                                      & ((~ 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                           >> 0x1dU)) 
                                                                         << 2U)) 
                                                                     | ((2U 
                                                                         & ((~ 
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                              >> 0x1eU)) 
                                                                            << 1U)) 
                                                                        | (1U 
                                                                           & (~ 
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                               >> 0x1fU)))))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_110 
        = ((0x2000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                       << 0xdU)) | ((0x1000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                << 0xbU)) 
                                    | ((0x800U & ((~ 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                    >> 2U)) 
                                                  << 0xbU)) 
                                       | ((0x400U & 
                                           ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                >> 3U)) 
                                            << 0xaU)) 
                                          | ((0x200U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                 << 5U)) 
                                             | ((0x100U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                      >> 6U)) 
                                                    << 8U)) 
                                                | ((0x80U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                       >> 5U)) 
                                                   | ((0x40U 
                                                       & ((~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                            >> 0xdU)) 
                                                          << 6U)) 
                                                      | ((0x20U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                               >> 0x1aU)) 
                                                             << 5U)) 
                                                         | ((0x10U 
                                                             & ((~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                  >> 0x1bU)) 
                                                                << 4U)) 
                                                            | ((8U 
                                                                & ((~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                     >> 0x1cU)) 
                                                                   << 3U)) 
                                                               | ((4U 
                                                                   & ((~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                        >> 0x1dU)) 
                                                                      << 2U)) 
                                                                  | ((2U 
                                                                      & ((~ 
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                           >> 0x1eU)) 
                                                                         << 1U)) 
                                                                     | (1U 
                                                                        & (~ 
                                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                            >> 0x1fU))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__21574(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__21574\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_20 
        = ((0x100U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                      << 8U)) | ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                           << 6U)) 
                                 | ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                              << 4U)) 
                                    | ((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                 << 2U)) 
                                       | ((0x10U & 
                                           ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                >> 4U)) 
                                            << 4U)) 
                                          | ((8U & 
                                              ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                   >> 5U)) 
                                               << 3U)) 
                                             | ((4U 
                                                 & ((~ 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                      >> 6U)) 
                                                    << 2U)) 
                                                | ((2U 
                                                    & ((~ 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                         >> 0xdU)) 
                                                       << 1U)) 
                                                   | (1U 
                                                      & (~ 
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                          >> 0xeU)))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_166 
        = ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                     << 6U)) | ((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                          << 4U)) | 
                                ((0x10U & ((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                               >> 2U)) 
                                           << 4U)) 
                                 | ((8U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                           >> 1U)) 
                                    | ((4U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                              >> 3U)) 
                                       | ((2U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                 >> 5U)) 
                                          | (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                   >> 0xdU))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__decode_units_0__DOT___cs_decoder_decoded_T_278 
        = ((0x40000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                        << 0x12U)) | ((0x20000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                   << 0x10U)) 
                                      | ((0x10000U 
                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                             << 0xeU)) 
                                         | ((0x8000U 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                << 0xcU)) 
                                            | ((0x4000U 
                                                & ((~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                     >> 4U)) 
                                                   << 0xeU)) 
                                               | ((0x2000U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                      << 8U)) 
                                                  | ((0x1000U 
                                                      & ((~ 
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                           >> 6U)) 
                                                         << 0xcU)) 
                                                     | ((0x800U 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                            >> 2U)) 
                                                        | ((0x400U 
                                                            & ((~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                 >> 0xeU)) 
                                                               << 0xaU)) 
                                                           | ((0x200U 
                                                               & ((~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                    >> 0x14U)) 
                                                                  << 9U)) 
                                                              | ((0x100U 
                                                                  & ((~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                       >> 0x15U)) 
                                                                     << 8U)) 
                                                                 | ((0x80U 
                                                                     & ((~ 
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                          >> 0x16U)) 
                                                                        << 7U)) 
                                                                    | ((0x40U 
                                                                        & ((~ 
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                             >> 0x17U)) 
                                                                           << 6U)) 
                                                                       | ((0x20U 
                                                                           & ((~ 
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x18U)) 
                                                                              << 5U)) 
                                                                          | ((0x10U 
                                                                              & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1bU)) 
                                                                                << 4U)) 
                                                                             | ((8U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1dU)) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1eU)) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___frontend_io_cpu_fetchpacket_bits_uops_0_bits_inst 
                                                                                >> 0x1fU)))))))))))))))))))));
}
