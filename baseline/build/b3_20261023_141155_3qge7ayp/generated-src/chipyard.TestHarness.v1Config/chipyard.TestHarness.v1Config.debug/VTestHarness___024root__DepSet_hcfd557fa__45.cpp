// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTestHarness.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTestHarness___024root.h"

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3936(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3936\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_7 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [7U][2U] << 0x1fU) | 
                             ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [7U][1U] 
                                                            >> 0x14U))
                                                 ? 0U
                                                 : 
                                                ((IData)(0x3ffU) 
                                                 + 
                                                 ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [7U][1U] 
                                                   << 0xcU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [7U][1U] 
                                                     >> 0x14U)))) 
                                               | (- (IData)(
                                                            (((3U 
                                                               == 
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [7U][1U] 
                                                                >> 0x1eU)) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [7U][1U] 
                                                                 >> 0x1dU)) 
                                                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_7_unrecoded_rawIn_isInf))))) 
                                              << 0x14U)) 
                              | (0xfffffU & (IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_7_unrecoded_fractOut 
                                                     >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [7U][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [7U][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_7_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [7U][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [7U][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_7_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [7U][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_7_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_7_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [7U][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [7U][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [7U][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [7U][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [7U][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_7_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [7U][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_7_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3937(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3937\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_8 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [8U][2U] << 0x1fU) | 
                             ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [8U][1U] 
                                                            >> 0x14U))
                                                 ? 0U
                                                 : 
                                                ((IData)(0x3ffU) 
                                                 + 
                                                 ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [8U][1U] 
                                                   << 0xcU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [8U][1U] 
                                                     >> 0x14U)))) 
                                               | (- (IData)(
                                                            (((3U 
                                                               == 
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [8U][1U] 
                                                                >> 0x1eU)) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [8U][1U] 
                                                                 >> 0x1dU)) 
                                                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_8_unrecoded_rawIn_isInf))))) 
                                              << 0x14U)) 
                              | (0xfffffU & (IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_8_unrecoded_fractOut 
                                                     >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [8U][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [8U][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_8_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [8U][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [8U][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_8_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [8U][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_8_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_8_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [8U][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [8U][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [8U][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [8U][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [8U][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_8_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [8U][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_8_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3938(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3938\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_9 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [9U][2U] << 0x1fU) | 
                             ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [9U][1U] 
                                                            >> 0x14U))
                                                 ? 0U
                                                 : 
                                                ((IData)(0x3ffU) 
                                                 + 
                                                 ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [9U][1U] 
                                                   << 0xcU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [9U][1U] 
                                                     >> 0x14U)))) 
                                               | (- (IData)(
                                                            (((3U 
                                                               == 
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [9U][1U] 
                                                                >> 0x1eU)) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [9U][1U] 
                                                                 >> 0x1dU)) 
                                                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_9_unrecoded_rawIn_isInf))))) 
                                              << 0x14U)) 
                              | (0xfffffU & (IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_9_unrecoded_fractOut 
                                                     >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [9U][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [9U][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_9_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [9U][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [9U][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_9_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [9U][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_9_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_9_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [9U][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [9U][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [9U][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [9U][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [9U][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_9_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [9U][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_9_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3939(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3939\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_10 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0xaU][2U] << 0x1fU) 
                             | ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                              [0xaU][1U] 
                                                              >> 0x14U))
                                                   ? 0U
                                                   : 
                                                  ((IData)(0x3ffU) 
                                                   + 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0xaU][1U] 
                                                     << 0xcU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0xaU][1U] 
                                                       >> 0x14U)))) 
                                                 | (- (IData)(
                                                              (((3U 
                                                                 == 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xaU][1U] 
                                                                  >> 0x1eU)) 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                   [0xaU][1U] 
                                                                   >> 0x1dU)) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_10_unrecoded_rawIn_isInf))))) 
                                                << 0x14U)) 
                                | (0xfffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_10_unrecoded_fractOut 
                                                       >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0xaU][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0xaU][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_10_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0xaU][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0xaU][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_10_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0xaU][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_10_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_10_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0xaU][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0xaU][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0xaU][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0xaU][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xaU][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_10_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0xaU][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_10_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3940(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3940\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_11 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0xbU][2U] << 0x1fU) 
                             | ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                              [0xbU][1U] 
                                                              >> 0x14U))
                                                   ? 0U
                                                   : 
                                                  ((IData)(0x3ffU) 
                                                   + 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0xbU][1U] 
                                                     << 0xcU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0xbU][1U] 
                                                       >> 0x14U)))) 
                                                 | (- (IData)(
                                                              (((3U 
                                                                 == 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xbU][1U] 
                                                                  >> 0x1eU)) 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                   [0xbU][1U] 
                                                                   >> 0x1dU)) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_11_unrecoded_rawIn_isInf))))) 
                                                << 0x14U)) 
                                | (0xfffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_11_unrecoded_fractOut 
                                                       >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0xbU][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0xbU][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_11_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0xbU][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0xbU][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_11_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0xbU][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_11_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_11_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0xbU][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0xbU][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0xbU][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0xbU][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xbU][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_11_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0xbU][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_11_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3941(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3941\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_12 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0xcU][2U] << 0x1fU) 
                             | ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                              [0xcU][1U] 
                                                              >> 0x14U))
                                                   ? 0U
                                                   : 
                                                  ((IData)(0x3ffU) 
                                                   + 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0xcU][1U] 
                                                     << 0xcU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0xcU][1U] 
                                                       >> 0x14U)))) 
                                                 | (- (IData)(
                                                              (((3U 
                                                                 == 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xcU][1U] 
                                                                  >> 0x1eU)) 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                   [0xcU][1U] 
                                                                   >> 0x1dU)) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_12_unrecoded_rawIn_isInf))))) 
                                                << 0x14U)) 
                                | (0xfffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_12_unrecoded_fractOut 
                                                       >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0xcU][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0xcU][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_12_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0xcU][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0xcU][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_12_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0xcU][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_12_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_12_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0xcU][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0xcU][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0xcU][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0xcU][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xcU][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_12_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0xcU][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_12_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3942(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3942\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_13 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0xdU][2U] << 0x1fU) 
                             | ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                              [0xdU][1U] 
                                                              >> 0x14U))
                                                   ? 0U
                                                   : 
                                                  ((IData)(0x3ffU) 
                                                   + 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0xdU][1U] 
                                                     << 0xcU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0xdU][1U] 
                                                       >> 0x14U)))) 
                                                 | (- (IData)(
                                                              (((3U 
                                                                 == 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xdU][1U] 
                                                                  >> 0x1eU)) 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                   [0xdU][1U] 
                                                                   >> 0x1dU)) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_13_unrecoded_rawIn_isInf))))) 
                                                << 0x14U)) 
                                | (0xfffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_13_unrecoded_fractOut 
                                                       >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0xdU][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0xdU][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_13_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0xdU][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0xdU][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_13_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0xdU][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_13_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_13_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0xdU][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0xdU][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0xdU][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0xdU][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xdU][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_13_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0xdU][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_13_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3943(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3943\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_14 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0xeU][2U] << 0x1fU) 
                             | ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                              [0xeU][1U] 
                                                              >> 0x14U))
                                                   ? 0U
                                                   : 
                                                  ((IData)(0x3ffU) 
                                                   + 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0xeU][1U] 
                                                     << 0xcU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0xeU][1U] 
                                                       >> 0x14U)))) 
                                                 | (- (IData)(
                                                              (((3U 
                                                                 == 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xeU][1U] 
                                                                  >> 0x1eU)) 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                   [0xeU][1U] 
                                                                   >> 0x1dU)) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_14_unrecoded_rawIn_isInf))))) 
                                                << 0x14U)) 
                                | (0xfffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_14_unrecoded_fractOut 
                                                       >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0xeU][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0xeU][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_14_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0xeU][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0xeU][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_14_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0xeU][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_14_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_14_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0xeU][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0xeU][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0xeU][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0xeU][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xeU][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_14_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0xeU][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_14_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3944(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3944\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_15 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0xfU][2U] << 0x1fU) 
                             | ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                              [0xfU][1U] 
                                                              >> 0x14U))
                                                   ? 0U
                                                   : 
                                                  ((IData)(0x3ffU) 
                                                   + 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0xfU][1U] 
                                                     << 0xcU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0xfU][1U] 
                                                       >> 0x14U)))) 
                                                 | (- (IData)(
                                                              (((3U 
                                                                 == 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xfU][1U] 
                                                                  >> 0x1eU)) 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                   [0xfU][1U] 
                                                                   >> 0x1dU)) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_15_unrecoded_rawIn_isInf))))) 
                                                << 0x14U)) 
                                | (0xfffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_15_unrecoded_fractOut 
                                                       >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0xfU][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0xfU][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_15_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0xfU][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0xfU][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_15_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0xfU][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_15_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_15_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0xfU][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0xfU][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0xfU][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0xfU][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xfU][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_15_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0xfU][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_15_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3945(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3945\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_16 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0x10U][2U] << 0x1fU) 
                             | ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                              [0x10U][1U] 
                                                              >> 0x14U))
                                                   ? 0U
                                                   : 
                                                  ((IData)(0x3ffU) 
                                                   + 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0x10U][1U] 
                                                     << 0xcU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x10U][1U] 
                                                       >> 0x14U)))) 
                                                 | (- (IData)(
                                                              (((3U 
                                                                 == 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x10U][1U] 
                                                                  >> 0x1eU)) 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                   [0x10U][1U] 
                                                                   >> 0x1dU)) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_16_unrecoded_rawIn_isInf))))) 
                                                << 0x14U)) 
                                | (0xfffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_16_unrecoded_fractOut 
                                                       >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x10U][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0x10U][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_16_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0x10U][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0x10U][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_16_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x10U][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_16_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_16_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x10U][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x10U][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x10U][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x10U][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x10U][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_16_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x10U][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_16_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3946(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3946\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_17 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0x11U][2U] << 0x1fU) 
                             | ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                              [0x11U][1U] 
                                                              >> 0x14U))
                                                   ? 0U
                                                   : 
                                                  ((IData)(0x3ffU) 
                                                   + 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0x11U][1U] 
                                                     << 0xcU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x11U][1U] 
                                                       >> 0x14U)))) 
                                                 | (- (IData)(
                                                              (((3U 
                                                                 == 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x11U][1U] 
                                                                  >> 0x1eU)) 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                   [0x11U][1U] 
                                                                   >> 0x1dU)) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_17_unrecoded_rawIn_isInf))))) 
                                                << 0x14U)) 
                                | (0xfffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_17_unrecoded_fractOut 
                                                       >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x11U][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0x11U][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_17_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0x11U][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0x11U][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_17_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x11U][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_17_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_17_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x11U][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x11U][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x11U][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x11U][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x11U][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_17_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x11U][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_17_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3947(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3947\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_18 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0x12U][2U] << 0x1fU) 
                             | ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                              [0x12U][1U] 
                                                              >> 0x14U))
                                                   ? 0U
                                                   : 
                                                  ((IData)(0x3ffU) 
                                                   + 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0x12U][1U] 
                                                     << 0xcU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x12U][1U] 
                                                       >> 0x14U)))) 
                                                 | (- (IData)(
                                                              (((3U 
                                                                 == 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x12U][1U] 
                                                                  >> 0x1eU)) 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                   [0x12U][1U] 
                                                                   >> 0x1dU)) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_18_unrecoded_rawIn_isInf))))) 
                                                << 0x14U)) 
                                | (0xfffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_18_unrecoded_fractOut 
                                                       >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x12U][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0x12U][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_18_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0x12U][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0x12U][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_18_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x12U][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_18_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_18_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x12U][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x12U][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x12U][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x12U][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x12U][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_18_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x12U][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_18_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3948(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3948\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_19 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0x13U][2U] << 0x1fU) 
                             | ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                              [0x13U][1U] 
                                                              >> 0x14U))
                                                   ? 0U
                                                   : 
                                                  ((IData)(0x3ffU) 
                                                   + 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0x13U][1U] 
                                                     << 0xcU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x13U][1U] 
                                                       >> 0x14U)))) 
                                                 | (- (IData)(
                                                              (((3U 
                                                                 == 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x13U][1U] 
                                                                  >> 0x1eU)) 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                   [0x13U][1U] 
                                                                   >> 0x1dU)) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_19_unrecoded_rawIn_isInf))))) 
                                                << 0x14U)) 
                                | (0xfffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_19_unrecoded_fractOut 
                                                       >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x13U][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0x13U][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_19_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0x13U][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0x13U][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_19_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x13U][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_19_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_19_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x13U][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x13U][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x13U][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x13U][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x13U][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_19_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x13U][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_19_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3949(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3949\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_20 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0x14U][2U] << 0x1fU) 
                             | ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                              [0x14U][1U] 
                                                              >> 0x14U))
                                                   ? 0U
                                                   : 
                                                  ((IData)(0x3ffU) 
                                                   + 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0x14U][1U] 
                                                     << 0xcU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x14U][1U] 
                                                       >> 0x14U)))) 
                                                 | (- (IData)(
                                                              (((3U 
                                                                 == 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x14U][1U] 
                                                                  >> 0x1eU)) 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                   [0x14U][1U] 
                                                                   >> 0x1dU)) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_20_unrecoded_rawIn_isInf))))) 
                                                << 0x14U)) 
                                | (0xfffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_20_unrecoded_fractOut 
                                                       >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x14U][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0x14U][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_20_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0x14U][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0x14U][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_20_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x14U][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_20_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_20_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x14U][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x14U][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x14U][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x14U][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x14U][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_20_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x14U][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_20_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3950(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3950\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_21 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0x15U][2U] << 0x1fU) 
                             | ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                              [0x15U][1U] 
                                                              >> 0x14U))
                                                   ? 0U
                                                   : 
                                                  ((IData)(0x3ffU) 
                                                   + 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0x15U][1U] 
                                                     << 0xcU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x15U][1U] 
                                                       >> 0x14U)))) 
                                                 | (- (IData)(
                                                              (((3U 
                                                                 == 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x15U][1U] 
                                                                  >> 0x1eU)) 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                   [0x15U][1U] 
                                                                   >> 0x1dU)) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_21_unrecoded_rawIn_isInf))))) 
                                                << 0x14U)) 
                                | (0xfffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_21_unrecoded_fractOut 
                                                       >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x15U][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0x15U][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_21_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0x15U][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0x15U][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_21_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x15U][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_21_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_21_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x15U][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x15U][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x15U][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x15U][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x15U][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_21_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x15U][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_21_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3951(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3951\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_22 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0x16U][2U] << 0x1fU) 
                             | ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                              [0x16U][1U] 
                                                              >> 0x14U))
                                                   ? 0U
                                                   : 
                                                  ((IData)(0x3ffU) 
                                                   + 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0x16U][1U] 
                                                     << 0xcU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x16U][1U] 
                                                       >> 0x14U)))) 
                                                 | (- (IData)(
                                                              (((3U 
                                                                 == 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x16U][1U] 
                                                                  >> 0x1eU)) 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                   [0x16U][1U] 
                                                                   >> 0x1dU)) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_22_unrecoded_rawIn_isInf))))) 
                                                << 0x14U)) 
                                | (0xfffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_22_unrecoded_fractOut 
                                                       >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x16U][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0x16U][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_22_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0x16U][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0x16U][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_22_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x16U][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_22_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_22_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x16U][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x16U][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x16U][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x16U][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x16U][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_22_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x16U][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_22_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3952(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3952\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_23 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0x17U][2U] << 0x1fU) 
                             | ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                              [0x17U][1U] 
                                                              >> 0x14U))
                                                   ? 0U
                                                   : 
                                                  ((IData)(0x3ffU) 
                                                   + 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0x17U][1U] 
                                                     << 0xcU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x17U][1U] 
                                                       >> 0x14U)))) 
                                                 | (- (IData)(
                                                              (((3U 
                                                                 == 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x17U][1U] 
                                                                  >> 0x1eU)) 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                   [0x17U][1U] 
                                                                   >> 0x1dU)) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_23_unrecoded_rawIn_isInf))))) 
                                                << 0x14U)) 
                                | (0xfffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_23_unrecoded_fractOut 
                                                       >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x17U][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0x17U][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_23_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0x17U][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0x17U][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_23_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x17U][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_23_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_23_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x17U][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x17U][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x17U][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x17U][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x17U][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_23_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x17U][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_23_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3953(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3953\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_24 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0x18U][2U] << 0x1fU) 
                             | ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                              [0x18U][1U] 
                                                              >> 0x14U))
                                                   ? 0U
                                                   : 
                                                  ((IData)(0x3ffU) 
                                                   + 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0x18U][1U] 
                                                     << 0xcU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x18U][1U] 
                                                       >> 0x14U)))) 
                                                 | (- (IData)(
                                                              (((3U 
                                                                 == 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x18U][1U] 
                                                                  >> 0x1eU)) 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                   [0x18U][1U] 
                                                                   >> 0x1dU)) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_24_unrecoded_rawIn_isInf))))) 
                                                << 0x14U)) 
                                | (0xfffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_24_unrecoded_fractOut 
                                                       >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x18U][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0x18U][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_24_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0x18U][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0x18U][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_24_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x18U][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_24_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_24_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x18U][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x18U][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x18U][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x18U][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x18U][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_24_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x18U][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_24_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3954(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3954\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_25 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0x19U][2U] << 0x1fU) 
                             | ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                              [0x19U][1U] 
                                                              >> 0x14U))
                                                   ? 0U
                                                   : 
                                                  ((IData)(0x3ffU) 
                                                   + 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0x19U][1U] 
                                                     << 0xcU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x19U][1U] 
                                                       >> 0x14U)))) 
                                                 | (- (IData)(
                                                              (((3U 
                                                                 == 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x19U][1U] 
                                                                  >> 0x1eU)) 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                   [0x19U][1U] 
                                                                   >> 0x1dU)) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_25_unrecoded_rawIn_isInf))))) 
                                                << 0x14U)) 
                                | (0xfffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_25_unrecoded_fractOut 
                                                       >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x19U][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0x19U][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_25_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0x19U][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0x19U][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_25_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x19U][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_25_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_25_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x19U][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x19U][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x19U][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x19U][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x19U][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_25_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x19U][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_25_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3955(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3955\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_26 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0x1aU][2U] << 0x1fU) 
                             | ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                              [0x1aU][1U] 
                                                              >> 0x14U))
                                                   ? 0U
                                                   : 
                                                  ((IData)(0x3ffU) 
                                                   + 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0x1aU][1U] 
                                                     << 0xcU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x1aU][1U] 
                                                       >> 0x14U)))) 
                                                 | (- (IData)(
                                                              (((3U 
                                                                 == 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1aU][1U] 
                                                                  >> 0x1eU)) 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                   [0x1aU][1U] 
                                                                   >> 0x1dU)) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_26_unrecoded_rawIn_isInf))))) 
                                                << 0x14U)) 
                                | (0xfffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_26_unrecoded_fractOut 
                                                       >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x1aU][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0x1aU][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_26_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0x1aU][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0x1aU][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_26_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x1aU][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_26_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_26_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x1aU][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x1aU][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x1aU][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x1aU][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1aU][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_26_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x1aU][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_26_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3956(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3956\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_27 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0x1bU][2U] << 0x1fU) 
                             | ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                              [0x1bU][1U] 
                                                              >> 0x14U))
                                                   ? 0U
                                                   : 
                                                  ((IData)(0x3ffU) 
                                                   + 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0x1bU][1U] 
                                                     << 0xcU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x1bU][1U] 
                                                       >> 0x14U)))) 
                                                 | (- (IData)(
                                                              (((3U 
                                                                 == 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1bU][1U] 
                                                                  >> 0x1eU)) 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                   [0x1bU][1U] 
                                                                   >> 0x1dU)) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_27_unrecoded_rawIn_isInf))))) 
                                                << 0x14U)) 
                                | (0xfffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_27_unrecoded_fractOut 
                                                       >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x1bU][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0x1bU][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_27_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0x1bU][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0x1bU][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_27_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x1bU][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_27_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_27_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x1bU][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x1bU][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x1bU][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x1bU][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1bU][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_27_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x1bU][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_27_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3957(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3957\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_28 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0x1cU][2U] << 0x1fU) 
                             | ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                              [0x1cU][1U] 
                                                              >> 0x14U))
                                                   ? 0U
                                                   : 
                                                  ((IData)(0x3ffU) 
                                                   + 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0x1cU][1U] 
                                                     << 0xcU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x1cU][1U] 
                                                       >> 0x14U)))) 
                                                 | (- (IData)(
                                                              (((3U 
                                                                 == 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1cU][1U] 
                                                                  >> 0x1eU)) 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                   [0x1cU][1U] 
                                                                   >> 0x1dU)) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_28_unrecoded_rawIn_isInf))))) 
                                                << 0x14U)) 
                                | (0xfffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_28_unrecoded_fractOut 
                                                       >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x1cU][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0x1cU][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_28_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0x1cU][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0x1cU][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_28_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x1cU][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_28_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_28_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x1cU][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x1cU][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x1cU][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x1cU][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1cU][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_28_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x1cU][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_28_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3958(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3958\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_29 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0x1dU][2U] << 0x1fU) 
                             | ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                              [0x1dU][1U] 
                                                              >> 0x14U))
                                                   ? 0U
                                                   : 
                                                  ((IData)(0x3ffU) 
                                                   + 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0x1dU][1U] 
                                                     << 0xcU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x1dU][1U] 
                                                       >> 0x14U)))) 
                                                 | (- (IData)(
                                                              (((3U 
                                                                 == 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1dU][1U] 
                                                                  >> 0x1eU)) 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                   [0x1dU][1U] 
                                                                   >> 0x1dU)) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_29_unrecoded_rawIn_isInf))))) 
                                                << 0x14U)) 
                                | (0xfffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_29_unrecoded_fractOut 
                                                       >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x1dU][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0x1dU][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_29_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0x1dU][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0x1dU][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_29_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x1dU][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_29_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_29_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x1dU][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x1dU][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x1dU][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x1dU][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1dU][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_29_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x1dU][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_29_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3959(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3959\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_30 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0x1eU][2U] << 0x1fU) 
                             | ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                              [0x1eU][1U] 
                                                              >> 0x14U))
                                                   ? 0U
                                                   : 
                                                  ((IData)(0x3ffU) 
                                                   + 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0x1eU][1U] 
                                                     << 0xcU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x1eU][1U] 
                                                       >> 0x14U)))) 
                                                 | (- (IData)(
                                                              (((3U 
                                                                 == 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1eU][1U] 
                                                                  >> 0x1eU)) 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                   [0x1eU][1U] 
                                                                   >> 0x1dU)) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_30_unrecoded_rawIn_isInf))))) 
                                                << 0x14U)) 
                                | (0xfffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_30_unrecoded_fractOut 
                                                       >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x1eU][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0x1eU][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_30_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0x1eU][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0x1eU][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_30_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x1eU][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_30_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_30_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x1eU][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x1eU][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x1eU][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x1eU][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1eU][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_30_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x1eU][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_30_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3960(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3960\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_31 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0x1fU][2U] << 0x1fU) 
                             | ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                              [0x1fU][1U] 
                                                              >> 0x14U))
                                                   ? 0U
                                                   : 
                                                  ((IData)(0x3ffU) 
                                                   + 
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0x1fU][1U] 
                                                     << 0xcU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x1fU][1U] 
                                                       >> 0x14U)))) 
                                                 | (- (IData)(
                                                              (((3U 
                                                                 == 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1fU][1U] 
                                                                  >> 0x1eU)) 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                   [0x1fU][1U] 
                                                                   >> 0x1dU)) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_31_unrecoded_rawIn_isInf))))) 
                                                << 0x14U)) 
                                | (0xfffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_31_unrecoded_fractOut 
                                                       >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x1fU][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0x1fU][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_31_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0x1fU][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0x1fU][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_31_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x1fU][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_31_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_31_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x1fU][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0x1fU][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x1fU][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x1fU][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1fU][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_31_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0x1fU][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_31_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3961(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3961\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___memLatencyMask_T_8 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_fastpipe) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_fromint));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_fpu_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ex_reg_ctrl_typeTagOut 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___fp_decoder_io_sigs_typeTagOut;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ex_reg_ctrl_sqrt 
            = (0x3ffffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_46);
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ex_reg_ctrl_fromint 
            = ((0xffffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_60)) 
               | (0x1fffffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_72));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___divSqrt_io_inValid_T 
        = (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_typeTagOut));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___divSqrt_io_inValid_T_2 
        = (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_typeTagOut));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___memLatencyMask_T_3 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_fma) 
           & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_typeTagOut)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___memLatencyMask_T_6 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_fma) 
           & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_typeTagOut)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_wen 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_reg_valid) 
           & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_fma) 
               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_fastpipe)) 
              | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_fromint)));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT____Vcellinp__fpiu__io_in_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_wflags 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ex_reg_ctrl_wflags;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_ren2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ex_reg_ctrl_ren2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma_io_in_bits_req_rm;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in2[0U] 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu_io_in_bits_req_in2[0U];
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in2[1U] 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu_io_in_bits_req_in2[1U];
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in2[2U] 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu_io_in_bits_req_in2[2U];
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wb_toint_valid 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wb_reg_valid) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wb_ctrl_toint));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ex_reg_valid 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_3_reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_fpu_valid));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT___fractB_Z_T_10 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__inReady) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_sqrt));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT___fractB_Z_T_10 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__inReady) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_sqrt));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___T_40 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_div) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_sqrt));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3962(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3962\n"); );
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_fpu_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ex_reg_ctrl_toint 
            = ((0x1ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_12)) 
               | ((0x7fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_50)) 
                  | ((0x7fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_52)) 
                     | ((0xffffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_56)) 
                        | (0xfffffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_64)))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ex_reg_ctrl_fastpipe 
            = ((0x3fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_26)) 
               | ((0x7fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_28)) 
                  | ((0x7ffffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_40) 
                     | (0x7ffffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_44))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ex_reg_ctrl_div 
            = (IData)((0x18000053U == (0xfc00007fU 
                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits)));
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT____Vcellinp__fpiu__io_in_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[0U] 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu_io_in_bits_req_in1[0U];
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[1U] 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu_io_in_bits_req_in1[1U];
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[2U] 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu_io_in_bits_req_in1[2U];
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3963(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3963\n"); );
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT____Vcellinp__fpiu__io_in_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_typ 
            = (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ex_reg_inst 
                     >> 0x14U));
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_fpu_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ex_reg_ctrl_fma 
            = (1U & ((0x1fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T)) 
                     | ((IData)((0x53U == (0xec00007fU 
                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                        | (0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_6)))));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05Fcmd_amo_logical_T_6 
        = ((((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd)) 
             | (9U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
            | (0xaU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
           | (0xbU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3964(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3964\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05Fcmd_amo_arithmetic_T_8 
        = (((((8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd)) 
              | (0xcU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
             | (0xdU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
            | (0xeU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
           | (0xfU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_cmd_read 
        = (((((((((((((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd)) 
                      | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
                     | (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
                    | (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
                   | (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
                  | (9U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
                 | (0xaU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
                | (0xbU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
               | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
              | (0xcU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
             | (0xdU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
            | (0xeU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
           | (0xfU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_cmd_write 
        = ((((((((((((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd)) 
                     | (0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
                    | (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
                   | (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
                  | (9U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
                 | (0xaU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
                | (0xbU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
               | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
              | (0xcU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
             | (0xdU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
            | (0xeU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))) 
           | (0xfU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3965(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3965\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05Fcmd_lrsc_T_2 
        = ((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd)) 
           | (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_valid_likely 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_perf_canAcceptLoadThenLoad_T_55) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_held));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___T_25 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_valid_ECP) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__has_ECP))) 
           & (0x20U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_index_ECP)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__if_check_completed 
        = (0x1fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rsu_status 
        = (3U & ((0x44U | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__check_done) 
                            << 7U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__rsu_status) 
                                      << 4U))) >> (7U 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__rsu_status) 
                                                      << 1U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__resHi 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___T_23)) 
           & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___T_17) 
                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___T_18)) 
               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_8))
               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__isHi)
               : ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___T_13)) 
                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__resHi))));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_3_reset) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__state = 0U;
    } else if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___T_23) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__state 
            = ((4U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn))
                ? (1U | (2U & ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__lhs_sign) 
                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__rhs_sign))) 
                               << 1U))) : 2U);
    } else if ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN) 
                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___io_resp_valid_output)) 
                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__killm_common) 
                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div_io_kill_REG)) 
                   | ((((~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode)) 
                            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)))) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killm))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_div)) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___icsl_io_if_overtaking_next_cycle))))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__state = 0U;
    } else if (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___T_17) 
                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___T_18))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__state 
            = (5U | (2U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__neg_out)) 
                           << 1U)));
    } else if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_8) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__state = 6U;
    } else if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___T_13) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__state = 7U;
    } else if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___T_10) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__state = 3U;
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3966(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3966\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_h8b72345a__0;
    VlWide<4>/*127:0*/ __Vtemp_h7a2f7a56__0;
    VlWide<4>/*127:0*/ __Vtemp_hc1bfb270__0;
    VlWide<4>/*127:0*/ __Vtemp_h71dd03bc__0;
    VlWide<5>/*159:0*/ __Vtemp_hd434d685__0;
    VlWide<4>/*127:0*/ __Vtemp_he71ef6ba__0;
    VlWide<5>/*159:0*/ __Vtemp_he391af4f__0;
    VlWide<5>/*159:0*/ __Vtemp_h83b8e72b__0;
    VlWide<5>/*159:0*/ __Vtemp_hc65a788f__0;
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___T_23) {
        vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__count 
            = (4U & (((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn) 
                          >> 2U)) & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_dw))) 
                     << 2U));
        vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__neg_out 
            = ((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___decoded_orMatrixOutputs_T_4))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__lhs_sign)
                : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__lhs_sign) 
                   != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__rhs_sign)));
        VL_EXTEND_WI(98,32, __Vtemp_h8b72345a__0, ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_dw)
                                                    ? (IData)(
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_rs_0 
                                                               >> 0x20U))
                                                    : 
                                                   (- (IData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__lhs_sign)))));
        vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[0U] 
            = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_rs_0);
        vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U] 
            = __Vtemp_h8b72345a__0[0U];
        vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[2U] 
            = __Vtemp_h8b72345a__0[1U];
        vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[3U] 
            = __Vtemp_h8b72345a__0[2U];
        vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[4U] 
            = __Vtemp_h8b72345a__0[3U];
    } else {
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___T_17) {
            if ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___eOut_T_9) 
                  & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__divby0))) 
                 & (0U != (7U & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___eOutPos_T_1) 
                                    >> 3U)))))) {
                VL_EXTEND_WQ(127,64, __Vtemp_h7a2f7a56__0, 
                             (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U])) 
                               << 0x20U) | (QData)((IData)(
                                                           vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[0U]))));
                VL_SHIFTL_WWI(127,127,6, __Vtemp_hc1bfb270__0, __Vtemp_h7a2f7a56__0, 
                              (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___eOutPos_T_1))));
                __Vtemp_h71dd03bc__0[0U] = __Vtemp_hc1bfb270__0[0U];
                __Vtemp_h71dd03bc__0[1U] = __Vtemp_hc1bfb270__0[1U];
                __Vtemp_h71dd03bc__0[2U] = __Vtemp_hc1bfb270__0[2U];
                __Vtemp_h71dd03bc__0[3U] = (0x7fffffffU 
                                            & __Vtemp_hc1bfb270__0[3U]);
                VL_EXTEND_WW(130,127, __Vtemp_hd434d685__0, __Vtemp_h71dd03bc__0);
                vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[0U] 
                    = __Vtemp_hd434d685__0[0U];
                vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U] 
                    = __Vtemp_hd434d685__0[1U];
                vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[2U] 
                    = __Vtemp_hd434d685__0[2U];
                vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[3U] 
                    = __Vtemp_hd434d685__0[3U];
                vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[4U] 
                    = __Vtemp_hd434d685__0[4U];
                vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__count 
                    = (7U & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___eOutPos_T_1) 
                                >> 3U)));
            } else {
                vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__count 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__count)));
                __Vtemp_he71ef6ba__0[0U] = (IData)(
                                                   ((0xffffffffffffff80ULL 
                                                     & (((QData)((IData)(
                                                                         vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U])) 
                                                         << 0x27U) 
                                                        | ((QData)((IData)(
                                                                           vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[0U])) 
                                                           << 7U))) 
                                                    | (QData)((IData)(
                                                                      ((0x40U 
                                                                        & ((~ 
                                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__subtractor[2U]) 
                                                                           << 6U)) 
                                                                       | ((0x20U 
                                                                           & ((~ 
                                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_1[2U]) 
                                                                              << 5U)) 
                                                                          | ((0x10U 
                                                                              & ((~ 
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_2[2U]) 
                                                                                << 4U)) 
                                                                             | ((8U 
                                                                                & ((~ 
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_3[2U]) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((~ 
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_4[2U]) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((~ 
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_5[2U]) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_6[2U]))))))))))));
                __Vtemp_he71ef6ba__0[1U] = (IData)(
                                                   (((0xffffffffffffff80ULL 
                                                      & (((QData)((IData)(
                                                                          vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U])) 
                                                          << 0x27U) 
                                                         | ((QData)((IData)(
                                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[0U])) 
                                                            << 7U))) 
                                                     | (QData)((IData)(
                                                                       ((0x40U 
                                                                         & ((~ 
                                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__subtractor[2U]) 
                                                                            << 6U)) 
                                                                        | ((0x20U 
                                                                            & ((~ 
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_1[2U]) 
                                                                               << 5U)) 
                                                                           | ((0x10U 
                                                                               & ((~ 
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_2[2U]) 
                                                                                << 4U)) 
                                                                              | ((8U 
                                                                                & ((~ 
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_3[2U]) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((~ 
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_4[2U]) 
                                                                                << 2U)) 
                                                                                | ((2U 
                                                                                & ((~ 
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_5[2U]) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & (~ 
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_6[2U]))))))))))) 
                                                    >> 0x20U));
                if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___T_18) {
                    __Vtemp_he391af4f__0[0U] = (((IData)(
                                                         (((QData)((IData)(
                                                                           vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U])) 
                                                           << 0x20U) 
                                                          | (QData)((IData)(
                                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[0U])))) 
                                                 << 1U) 
                                                | (1U 
                                                   & (~ 
                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__subtractor[2U])));
                    __Vtemp_he391af4f__0[1U] = (((IData)(
                                                         (((QData)((IData)(
                                                                           vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U])) 
                                                           << 0x20U) 
                                                          | (QData)((IData)(
                                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[0U])))) 
                                                 >> 0x1fU) 
                                                | ((IData)(
                                                           ((((QData)((IData)(
                                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U])) 
                                                              << 0x20U) 
                                                             | (QData)((IData)(
                                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[0U]))) 
                                                            >> 0x20U)) 
                                                   << 1U));
                    __Vtemp_he391af4f__0[2U] = (((IData)(
                                                         ((((QData)((IData)(
                                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[0U]))) 
                                                          >> 0x20U)) 
                                                 >> 0x1fU) 
                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_2) 
                                                   << 1U));
                    __Vtemp_he391af4f__0[3U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_2) 
                                                 >> 0x1fU) 
                                                | ((IData)(
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_2 
                                                            >> 0x20U)) 
                                                   << 1U));
                    __Vtemp_he391af4f__0[4U] = ((IData)(
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_2 
                                                         >> 0x20U)) 
                                                >> 0x1fU);
                } else {
                    __Vtemp_he391af4f__0[0U] = ((__Vtemp_he71ef6ba__0[0U] 
                                                 << 1U) 
                                                | (1U 
                                                   & (~ 
                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_7[2U])));
                    __Vtemp_he391af4f__0[1U] = ((__Vtemp_he71ef6ba__0[0U] 
                                                 >> 0x1fU) 
                                                | (__Vtemp_he71ef6ba__0[1U] 
                                                   << 1U));
                    __Vtemp_he391af4f__0[2U] = ((__Vtemp_he71ef6ba__0[1U] 
                                                 >> 0x1fU) 
                                                | ((IData)(
                                                           ((1U 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_7[2U])
                                                             ? 
                                                            ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_32 
                                                              << 1U) 
                                                             | (QData)((IData)(
                                                                               (1U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U] 
                                                                                >> 0x19U)))))
                                                             : 
                                                            (((QData)((IData)(
                                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_7[1U])) 
                                                              << 0x20U) 
                                                             | (QData)((IData)(
                                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_7[0U]))))) 
                                                   << 1U));
                    __Vtemp_he391af4f__0[3U] = (((IData)(
                                                         ((1U 
                                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_7[2U])
                                                           ? 
                                                          ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_32 
                                                            << 1U) 
                                                           | (QData)((IData)(
                                                                             (1U 
                                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U] 
                                                                                >> 0x19U)))))
                                                           : 
                                                          (((QData)((IData)(
                                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_7[1U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_7[0U]))))) 
                                                 >> 0x1fU) 
                                                | ((IData)(
                                                           (((1U 
                                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_7[2U])
                                                              ? 
                                                             ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_32 
                                                               << 1U) 
                                                              | (QData)((IData)(
                                                                                (1U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U] 
                                                                                >> 0x19U)))))
                                                              : 
                                                             (((QData)((IData)(
                                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_7[1U])) 
                                                               << 0x20U) 
                                                              | (QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_7[0U])))) 
                                                            >> 0x20U)) 
                                                   << 1U));
                    __Vtemp_he391af4f__0[4U] = ((IData)(
                                                        (((1U 
                                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_7[2U])
                                                           ? 
                                                          ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_32 
                                                            << 1U) 
                                                           | (QData)((IData)(
                                                                             (1U 
                                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U] 
                                                                                >> 0x19U)))))
                                                           : 
                                                          (((QData)((IData)(
                                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_7[1U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_7[0U])))) 
                                                         >> 0x20U)) 
                                                >> 0x1fU);
                }
                VL_EXTEND_WW(130,129, __Vtemp_h83b8e72b__0, __Vtemp_he391af4f__0);
                vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[0U] 
                    = __Vtemp_h83b8e72b__0[0U];
                vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U] 
                    = __Vtemp_h83b8e72b__0[1U];
                vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[2U] 
                    = __Vtemp_h83b8e72b__0[2U];
                vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[3U] 
                    = __Vtemp_h83b8e72b__0[3U];
                vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[4U] 
                    = __Vtemp_h83b8e72b__0[4U];
            }
        } else if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___T_14) {
            vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__count 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__count)));
            vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[0U] 
                = (IData)(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__eOut)
                            ? (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__eOutRes[1U])) 
                                << 0x20U) | (QData)((IData)(
                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__eOutRes[0U])))
                            : (((QData)((IData)((0xffU 
                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_0[0U]))) 
                                << 0x38U) | (0xffffffffffffffULL 
                                             & (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U])) 
                                                 << 0x18U) 
                                                | ((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[0U])) 
                                                   >> 8U))))));
            vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U] 
                = (IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__eOut)
                             ? (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__eOutRes[1U])) 
                                 << 0x20U) | (QData)((IData)(
                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__eOutRes[0U])))
                             : (((QData)((IData)((0xffU 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_0[0U]))) 
                                 << 0x38U) | (0xffffffffffffffULL 
                                              & (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U])) 
                                                  << 0x18U) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[0U])) 
                                                    >> 8U))))) 
                           >> 0x20U));
            vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[2U] 
                = (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_0[1U] 
                     << 0x19U) | (0x1fffffeU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_0[0U] 
                                                >> 7U))) 
                   | ((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__count)) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__neg_out)));
            vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[3U] 
                = ((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_0[1U] 
                          >> 7U)) | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_0[2U] 
                                      << 0x19U) | (0x1fffffeU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_0[1U] 
                                                      >> 7U))));
            vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[4U] 
                = ((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_0[2U] 
                          >> 7U)) | (2U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_0[2U] 
                                           >> 7U)));
        } else if (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___T_13) 
                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___T_10) 
                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U] 
                          >> 0x1fU)))) {
            VL_EXTEND_WQ(130,64, __Vtemp_hc65a788f__0, 
                         (- vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__result));
            vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[0U] 
                = __Vtemp_hc65a788f__0[0U];
            vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U] 
                = __Vtemp_hc65a788f__0[1U];
            vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[2U] 
                = __Vtemp_hc65a788f__0[2U];
            vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[3U] 
                = __Vtemp_hc65a788f__0[3U];
            vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[4U] 
                = __Vtemp_hc65a788f__0[4U];
        }
        vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__neg_out 
            = ((~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___T_17) 
                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__divby0)) 
                   & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__isHi)))) 
               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__neg_out));
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3967(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3967\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_h4e7d1761__0;
    VlWide<4>/*127:0*/ __Vtemp_h12f3b458__0;
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_xcpt_pf_inst 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__fq__DOT__valid_0)
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__fq__DOT__elts_0_xcpt_pf_inst)
            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_tlb_resp_pf_inst));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_xcpt 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_tlb_resp_ae_inst) 
            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_tlb_resp_pf_inst)) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_tlb_resp_gf_inst));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wdata_rawIn_adjustedExp_1 
        = (0x1ffU & (((0U == (0xffU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                               >> 0x17U))))
                       ? (0x1e0U | (0x1fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wdata_rawIn_normDist_1))))
                       : (0xffU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                           >> 0x17U)))) 
                     + (0x80U | ((0U == (0xffU & (IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                          >> 0x17U))))
                                  ? 2U : 1U))));
    VL_EXTEND_WQ(115,52, __Vtemp_h4e7d1761__0, (0xfffffffffffffULL 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2));
    VL_SHIFTL_WWI(115,115,6, __Vtemp_h12f3b458__0, __Vtemp_h4e7d1761__0, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wdata_rawIn_normDist));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_rawIn_out_sig_T_1 
        = (0xfffffffffffffULL & ((0U == (0x7ffU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                           >> 0x34U))))
                                  ? (0xffffffffffffeULL 
                                     & (((QData)((IData)(
                                                         __Vtemp_h12f3b458__0[1U])) 
                                         << 0x21U) 
                                        | ((QData)((IData)(
                                                           __Vtemp_h12f3b458__0[0U])) 
                                           << 1U)))
                                  : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wdata_rawIn_adjustedExp 
        = (0xfffU & (((0U == (0x7ffU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                >> 0x34U))))
                       ? (0xfc0U | (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wdata_rawIn_normDist))))
                       : (0x7ffU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                            >> 0x34U)))) 
                     + (0x400U | ((0U == (0x7ffU & (IData)(
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                            >> 0x34U))))
                                   ? 2U : 1U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_io_resp_addr 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__resp_valid_reg)
            ? (0xffffffffffULL & (((QData)((IData)(
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__out_packet[1U])) 
                                   << 0x20U) | (QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__out_packet[0U]))))
            : 0ULL);
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3968(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3968\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_io_resp_data 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__resp_valid_reg)
            ? (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__out_packet[3U])) 
                << 0x20U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__out_packet[2U])))
            : 0ULL);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_io_resp_replay 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__req_valid_reg) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__resp_valid_reg))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__resp_kill_reg)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__beats1_1 
        = ((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode))
            ? (0x1ffU & (~ (((0x1aU >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_size))
                              ? (0x7ffffffU & ((IData)(0xfffU) 
                                               << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_size)))
                              : 0U) >> 3U))) : 0U);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__block_probe_for_core_progress 
        = (IData)(((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__blockProbeAfterGrantCount)) 
                   | (0U != (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__lrscCount)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___T_125 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_param) 
            << 2U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_probe_state_state));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_probe 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_3_reset)) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_29) 
              | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___probe_bits_T)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_20 
        = (7U & (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_2_valid_0) 
                     << 2U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_1_valid_0) 
                                << 1U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_0_valid_0)))));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_45) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_2_tag_v 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_refill_v;
    }
    if ((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_50)))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_tag_v 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_refill_v;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_39) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_special_entry_tag_v 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_refill_v;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_41) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_0_tag_v 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_refill_v;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_0_level 
            = (1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__max_count));
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_43) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_1_tag_v 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_refill_v;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_47) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_3_tag_v 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_refill_v;
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3969(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3969\n"); );
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s0_clk_en) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_size 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_req_bits_size;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_43) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_1_data_0 
            = (((QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn) 
                                  << 0xcU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_u) 
                                               << 0xbU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_g) 
                                                  << 0xaU) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_ae_ptw) 
                                                     << 9U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_ae_final) 
                                                        << 8U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_pf) 
                                                           << 7U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_gf) 
                                                              << 6U) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_sw) 
                                                                 << 5U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_sx) 
                                                                    << 4U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_sr) 
                                                                       << 3U) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hw) 
                                                                          << 2U) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hx) 
                                                                             << 1U) 
                                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hr))))))))))))))) 
                << 9U) | (QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_pw) 
                                           << 8U) | 
                                          (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_px) 
                                            << 7U) 
                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_pr) 
                                               << 6U) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_ppp) 
                                                  << 5U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_pal) 
                                                     << 4U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_paa) 
                                                        << 3U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_eff) 
                                                           << 2U) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_c) 
                                                             << 1U)))))))))));
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_45) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_2_data_0 
            = (((QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn) 
                                  << 0xcU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_u) 
                                               << 0xbU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_g) 
                                                  << 0xaU) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_ae_ptw) 
                                                     << 9U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_ae_final) 
                                                        << 8U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_pf) 
                                                           << 7U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_gf) 
                                                              << 6U) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_sw) 
                                                                 << 5U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_sx) 
                                                                    << 4U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_sr) 
                                                                       << 3U) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hw) 
                                                                          << 2U) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hx) 
                                                                             << 1U) 
                                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hr))))))))))))))) 
                << 9U) | (QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_pw) 
                                           << 8U) | 
                                          (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_px) 
                                            << 7U) 
                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_pr) 
                                               << 6U) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_ppp) 
                                                  << 5U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_pal) 
                                                     << 4U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_paa) 
                                                        << 3U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_eff) 
                                                           << 2U) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_c) 
                                                             << 1U)))))))))));
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3970(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3970\n"); );
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_47) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_3_data_0 
            = (((QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn) 
                                  << 0xcU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_u) 
                                               << 0xbU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_g) 
                                                  << 0xaU) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_ae_ptw) 
                                                     << 9U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_ae_final) 
                                                        << 8U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_pf) 
                                                           << 7U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_gf) 
                                                              << 6U) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_sw) 
                                                                 << 5U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_sx) 
                                                                    << 4U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_sr) 
                                                                       << 3U) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hw) 
                                                                          << 2U) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hx) 
                                                                             << 1U) 
                                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hr))))))))))))))) 
                << 9U) | (QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_pw) 
                                           << 8U) | 
                                          (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_px) 
                                            << 7U) 
                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_pr) 
                                               << 6U) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_ppp) 
                                                  << 5U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_pal) 
                                                     << 4U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_paa) 
                                                        << 3U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_eff) 
                                                           << 2U) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_c) 
                                                             << 1U)))))))))));
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_41) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_0_data_0 
            = (((QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn) 
                                  << 0xcU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_u) 
                                               << 0xbU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_g) 
                                                  << 0xaU) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_ae_ptw) 
                                                     << 9U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_ae_final) 
                                                        << 8U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_pf) 
                                                           << 7U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_gf) 
                                                              << 6U) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_sw) 
                                                                 << 5U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_sx) 
                                                                    << 4U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_sr) 
                                                                       << 3U) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hw) 
                                                                          << 2U) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hx) 
                                                                             << 1U) 
                                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hr))))))))))))))) 
                << 9U) | (QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_pw) 
                                           << 8U) | 
                                          (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_px) 
                                            << 7U) 
                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_pr) 
                                               << 6U) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_ppp) 
                                                  << 5U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_pal) 
                                                     << 4U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_paa) 
                                                        << 3U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_eff) 
                                                           << 2U) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_c) 
                                                             << 1U)))))))))));
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_39) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_special_entry_data_0 
            = (((QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn) 
                                  << 0xcU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_u) 
                                               << 0xbU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_g) 
                                                  << 0xaU) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_ae_ptw) 
                                                     << 9U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_ae_final) 
                                                        << 8U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_pf) 
                                                           << 7U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_gf) 
                                                              << 6U) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_sw) 
                                                                 << 5U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_sx) 
                                                                    << 4U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_sr) 
                                                                       << 3U) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hw) 
                                                                          << 2U) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hx) 
                                                                             << 1U) 
                                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hr))))))))))))))) 
                << 9U) | (QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_pw) 
                                           << 8U) | 
                                          (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_px) 
                                            << 7U) 
                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_pr) 
                                               << 6U) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_ppp) 
                                                  << 5U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_pal) 
                                                     << 4U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_paa) 
                                                        << 3U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_eff) 
                                                           << 2U) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_newEntry_c) 
                                                             << 1U)))))))))));
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3971(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3971\n"); );
    // Body
    if ((1U & (~ (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_valid_0)) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_49)) 
                  | (0U != (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag)))))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_data_0 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05Fsectored_entries_0_0_data_T;
    }
    if ((1U & (~ (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_valid_0)) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_49)) 
                  | (1U != (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag)))))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_data_1 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05Fsectored_entries_0_0_data_T;
    }
    if ((1U & (~ (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_valid_0)) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_49)) 
                  | (2U != (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag)))))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_data_2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05Fsectored_entries_0_0_data_T;
    }
    if ((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_50)))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_tag_vpn 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag;
    }
    if ((1U & (~ (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_valid_0)) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_49)) 
                  | (~ (IData)((3U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag)))))))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_data_3 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05Fsectored_entries_0_0_data_T;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_41) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_0_tag_vpn 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_43) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_1_tag_vpn 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_45) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_2_tag_vpn 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_47) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_3_tag_vpn 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_39) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_special_entry_tag_vpn 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_tag)
            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_tag));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3972(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3972\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__check_privret_REG 
        = ((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_if_correct_process) 
               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__io_if_check_privret_REG)) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__ic_counter_done)) 
             & ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__fsm_state)) 
                | (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__fsm_state)))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_returned_to_special_address_valid))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__excpt_mode)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_142 
        = (0x7fU & (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___r_sectored_repl_addr_valids_T_20) 
                        << 6U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___r_sectored_repl_addr_valids_T_17) 
                                   << 5U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___r_sectored_repl_addr_valids_T_14) 
                                              << 4U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___r_sectored_repl_addr_valids_T_11) 
                                                 << 3U) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___r_sectored_repl_addr_valids_T_8) 
                                                    << 2U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___r_sectored_repl_addr_valids_T_5) 
                                                       << 1U) 
                                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___r_sectored_repl_addr_valids_T_2)))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_wxd 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_wxd)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__empty));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_csr 
        = ((((0x73U == (0x7fU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst)) 
             & ((((((2U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                  >> 0xcU))) | (1U 
                                                == 
                                                (7U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                                    >> 0xcU)))) 
                   | (3U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                   >> 0xcU)))) | (5U 
                                                  == 
                                                  (7U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                                      >> 0xcU)))) 
                 | (6U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                 >> 0xcU)))) | (7U 
                                                == 
                                                (7U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                                    >> 0xcU))))) 
            & (~ ((((((((((((((((0x300U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                            >> 0x14U)) 
                                | (0x304U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                              >> 0x14U))) 
                               | (0x305U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                             >> 0x14U))) 
                              | (0x340U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                            >> 0x14U))) 
                             | (0x341U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                           >> 0x14U))) 
                            | (0x344U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                          >> 0x14U))) 
                           | (0x100U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                         >> 0x14U))) 
                          | (0x104U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                        >> 0x14U))) 
                         | (0x140U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                       >> 0x14U))) 
                        | (0x141U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                      >> 0x14U))) | 
                       (0x142U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                   >> 0x14U))) | (0x143U 
                                                  == 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                                   >> 0x14U))) 
                     | (0x144U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                   >> 0x14U))) | (3U 
                                                  == 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                                   >> 0x14U))) 
                   | (1U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                             >> 0x14U))) | (2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                                   >> 0x14U))))) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_valid));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3973(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3973\n"); );
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__if_sysret 
            = (0x10200073U == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst);
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__elu__io_wb_pc 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_pc;
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__if_sysret = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__elu__io_wb_pc = 0ULL;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___returned_to_special_address_valid_T_1 
        = (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_pc 
           == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__pc_special);
    if ((1U & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___T_71) 
                  | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_pc_valid)))))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_pc 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_pc;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__state_reg_touch_way_sized 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__r_btb_updatePipe_valid)
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__waddr)
            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__r_respPipe_bits_entry));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__updatePageHit 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__pageValid) 
           & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__pages_5 
                == (0x1ffffffU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__r_btb_updatePipe_bits_pc 
                                          >> 0xeU)))) 
               << 5U) | (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__pages_4 
                           == (0x1ffffffU & (IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__r_btb_updatePipe_bits_pc 
                                                     >> 0xeU)))) 
                          << 4U) | (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__pages_3 
                                      == (0x1ffffffU 
                                          & (IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__r_btb_updatePipe_bits_pc 
                                                     >> 0xeU)))) 
                                     << 3U) | (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__pages_2 
                                                 == 
                                                 (0x1ffffffU 
                                                  & (IData)(
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__r_btb_updatePipe_bits_pc 
                                                             >> 0xeU)))) 
                                                << 2U) 
                                               | (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__pages_1 
                                                    == 
                                                    (0x1ffffffU 
                                                     & (IData)(
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__r_btb_updatePipe_bits_pc 
                                                                >> 0xeU)))) 
                                                   << 1U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__pages_0 
                                                     == 
                                                     (0x1ffffffU 
                                                      & (IData)(
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__r_btb_updatePipe_bits_pc 
                                                                 >> 0xeU))))))))));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_3_reset) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_pc = 0x10040ULL;
    } else if ((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_replay)))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_pc 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_pc;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT____Vcellinp__u_channel__io_deq_ready 
        = (IData)(((0x1cU == (0x1eU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ghe_debug_perf_ctrl))) 
                   & (0xfU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_sel_delay))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3 
        = (QData)((IData)((((0xeU == (0xfU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ghe_debug_perf_ctrl) 
                                              >> 1U))) 
                            | (0xfU == (0xfU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ghe_debug_perf_ctrl) 
                                                >> 1U))))
                            ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__u_channel__DOT__mem_ext__DOT___GEN)
                                ? ((0x31U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__u_channel__DOT__mem_ext__DOT___GEN_0))
                                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__u_channel__DOT__mem_ext__DOT__Memory
                                   [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__u_channel__DOT__mem_ext__DOT___GEN_0]
                                    : 0U) : 0U) : 0U)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3974(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3974\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_zbk 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killd) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_zbk));
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_zkn 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killd) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_zkn));
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_zks 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killd) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_zks));
    if ((1U & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___T_71) 
                  | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_pc_valid)))))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_jalr 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_jalr;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_zbk 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_zbk;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_zkn 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_zkn;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_zks 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_zks;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_wdata 
            = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_jalr) 
                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                   >> 0xcU)) ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_pc
                : (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_scie_unpipelined) 
                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_zbk)) 
                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_zkn)) 
                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_zks))
                    ? 0ULL : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_dw)
                               ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__out
                               : (((QData)((IData)(
                                                   (- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__out 
                                                                          >> 0x1fU))))))) 
                                   << 0x20U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__out))))));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_scie_unpipelined 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killd) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_scie_unpipelined));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___r_sectored_repl_addr_valids_T_21 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_7_valid_0) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_7_valid_1));
    if ((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_101)))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_7_tag_v 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__refill_v;
    }
    if ((1U & (~ (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_valid_1)) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_44)) 
                  | (~ ((7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__waddr_1)) 
                        & (0U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag)))))))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_7_data_0 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___sectored_entries_0_7_data_T;
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3975(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3975\n"); );
    // Body
    if ((1U & (~ (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_valid_1)) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_44)) 
                  | (~ ((7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__waddr_1)) 
                        & (1U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag)))))))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_7_data_1 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___sectored_entries_0_7_data_T;
    }
    if ((1U & (~ (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_valid_1)) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_44)) 
                  | (~ ((7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__waddr_1)) 
                        & (2U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag)))))))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_7_data_2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___sectored_entries_0_7_data_T;
    }
    if ((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_45)))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_0_tag_vpn 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag;
    }
    if ((1U & (~ (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_valid_1)) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_44)) 
                  | (~ ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__waddr_1)) 
                        & (3U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag)))))))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_0_data_3 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___sectored_entries_0_0_data_T;
    }
    if ((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_53)))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_1_tag_vpn 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag;
    }
    if ((1U & (~ (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_valid_1)) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_44)) 
                  | (~ ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__waddr_1)) 
                        & (3U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag)))))))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_1_data_3 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___sectored_entries_0_1_data_T;
    }
    if ((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_61)))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_2_tag_vpn 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag;
    }
    if ((1U & (~ (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_valid_1)) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_44)) 
                  | (~ ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__waddr_1)) 
                        & (3U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag)))))))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_2_data_3 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___sectored_entries_0_2_data_T;
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3976(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3976\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_69)))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_3_tag_vpn 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag;
    }
    if ((1U & (~ (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_valid_1)) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_44)) 
                  | (~ ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__waddr_1)) 
                        & (3U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag)))))))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_3_data_3 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___sectored_entries_0_3_data_T;
    }
    if ((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_77)))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_4_tag_vpn 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag;
    }
    if ((1U & (~ (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_valid_1)) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_44)) 
                  | (~ ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__waddr_1)) 
                        & (3U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag)))))))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_4_data_3 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___sectored_entries_0_4_data_T;
    }
    if ((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_85)))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_5_tag_vpn 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag;
    }
    if ((1U & (~ (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_valid_1)) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_44)) 
                  | (~ ((5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__waddr_1)) 
                        & (3U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag)))))))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_5_data_3 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___sectored_entries_0_5_data_T;
    }
    if ((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_93)))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_6_tag_vpn 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag;
    }
    if ((1U & (~ (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_valid_1)) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_44)) 
                  | (~ ((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__waddr_1)) 
                        & (3U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag)))))))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_6_data_3 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___sectored_entries_0_6_data_T;
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3977(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3977\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_101)))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_7_tag_vpn 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag;
    }
    if ((1U & (~ (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_valid_1)) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_44)) 
                  | (~ ((7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__waddr_1)) 
                        & (3U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag)))))))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_7_data_3 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___sectored_entries_0_7_data_T;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_36) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_0_tag_vpn 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_38) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_1_tag_vpn 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_40) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_tag_vpn 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_tag_v 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__refill_v;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_data_0 
            = (((QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn) 
                                  << 0xcU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_u) 
                                               << 0xbU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_g) 
                                                  << 0xaU) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_ae_ptw) 
                                                     << 9U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_ae_final) 
                                                        << 8U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_pf) 
                                                           << 7U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_gf) 
                                                              << 6U) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_sw) 
                                                                 << 5U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_sx) 
                                                                    << 4U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_sr) 
                                                                       << 3U) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hw) 
                                                                          << 2U) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hx) 
                                                                             << 1U) 
                                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hr))))))))))))))) 
                << 9U) | (QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_pw) 
                                           << 8U) | 
                                          (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_px) 
                                            << 7U) 
                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_pr) 
                                               << 6U) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_ppp) 
                                                  << 5U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_pal) 
                                                     << 4U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_paa) 
                                                        << 3U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_eff) 
                                                           << 2U) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_c) 
                                                             << 1U)))))))))));
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_42) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_tag_vpn 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_34) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__special_entry_tag_vpn 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_refill_tag;
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3978(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3978\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_26 
        = (7U & (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_valid_0) 
                     << 2U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_1_valid_0) 
                                << 1U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_0_valid_0)))));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_38) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_1_tag_v 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__refill_v;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_1_data_0 
            = (((QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn) 
                                  << 0xcU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_u) 
                                               << 0xbU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_g) 
                                                  << 0xaU) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_ae_ptw) 
                                                     << 9U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_ae_final) 
                                                        << 8U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_pf) 
                                                           << 7U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_gf) 
                                                              << 6U) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_sw) 
                                                                 << 5U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_sx) 
                                                                    << 4U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_sr) 
                                                                       << 3U) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hw) 
                                                                          << 2U) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hx) 
                                                                             << 1U) 
                                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hr))))))))))))))) 
                << 9U) | (QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_pw) 
                                           << 8U) | 
                                          (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_px) 
                                            << 7U) 
                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_pr) 
                                               << 6U) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_ppp) 
                                                  << 5U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_pal) 
                                                     << 4U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_paa) 
                                                        << 3U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_eff) 
                                                           << 2U) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_c) 
                                                             << 1U)))))))))));
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_42) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_tag_v 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__refill_v;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_data_0 
            = (((QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn) 
                                  << 0xcU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_u) 
                                               << 0xbU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_g) 
                                                  << 0xaU) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_ae_ptw) 
                                                     << 9U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_ae_final) 
                                                        << 8U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_pf) 
                                                           << 7U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_gf) 
                                                              << 6U) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_sw) 
                                                                 << 5U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_sx) 
                                                                    << 4U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_sr) 
                                                                       << 3U) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hw) 
                                                                          << 2U) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hx) 
                                                                             << 1U) 
                                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hr))))))))))))))) 
                << 9U) | (QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_pw) 
                                           << 8U) | 
                                          (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_px) 
                                            << 7U) 
                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_pr) 
                                               << 6U) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_ppp) 
                                                  << 5U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_pal) 
                                                     << 4U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_paa) 
                                                        << 3U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_eff) 
                                                           << 2U) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__newEntry_c) 
                                                             << 1U)))))))))));
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3979(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3979\n"); );
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_pc_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_mem_size 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_mem_size;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__fq__io_enq_bits_xcpt_ae_inst 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_tl_error)) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_tlb_resp_ae_inst));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___npc_T_4 
        = (0x1ffffffffULL & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__prevRVI)
                              ? (((QData)((IData)((
                                                   ((- (IData)(
                                                               (1U 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                                                                   >> 0xfU)))) 
                                                    << 0x13U) 
                                                   | ((8U 
                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_partial_insn))
                                                       ? 
                                                      ((0x78000U 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                                                           << 0xfU)) 
                                                       | ((0x7800U 
                                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_partial_insn) 
                                                              >> 1U)) 
                                                          | ((0x400U 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                                                                 << 6U)) 
                                                             | (0x3ffU 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                                                                   >> 5U)))))
                                                       : 
                                                      ((0x7f800U 
                                                        & ((- (IData)(
                                                                      (1U 
                                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                                                                          >> 0xfU)))) 
                                                           << 0xbU)) 
                                                       | ((0x400U 
                                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_partial_insn) 
                                                              << 3U)) 
                                                          | ((0x3f0U 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                                                                 >> 5U)) 
                                                             | (0xfU 
                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_partial_insn) 
                                                                   >> 8U))))))))) 
                                  << 1U) - 2ULL) : 
                             ((QData)((IData)((((- (IData)(
                                                           (1U 
                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                                                               >> 0xcU)))) 
                                                << 0xaU) 
                                               | ((0x4000U 
                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data)
                                                   ? 
                                                  ((0x380U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                                                                      >> 0xcU)))) 
                                                       << 7U)) 
                                                   | ((0x60U 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data) 
                                                      | ((0x10U 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                                                             << 2U)) 
                                                         | ((0xcU 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                                                                >> 8U)) 
                                                            | (3U 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                                                                  >> 3U))))))
                                                   : 
                                                  ((0x200U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                                                       << 1U)) 
                                                   | ((0x180U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                                                          >> 2U)) 
                                                      | ((0x40U 
                                                          & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data) 
                                                         | ((0x20U 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                                                                >> 2U)) 
                                                            | ((0x10U 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                                                                   << 2U)) 
                                                               | ((8U 
                                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                                                                      >> 8U)) 
                                                                  | (7U 
                                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                                                                        >> 3U)))))))))))) 
                              << 1U)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3980(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3980\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__rviReturn_1 
        = ((IData)((0x67U == (0xffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data))) 
           & (1U == ((0xcU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                              >> 0x10U)) | (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                                                  >> 0xfU)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__rviReturn 
        = ((IData)((0x67U == (0xffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_partial_insn)))) 
           & (1U == ((0xcU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data) 
                     | ((2U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                               << 1U)) | (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_partial_insn) 
                                                >> 0xfU))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___hasCF_this_idx_T_8 
        = ((0x67U == (0x7fU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data)) 
           | (0x6fU == (0x7fU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_data 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__fq__DOT__valid_0)
            ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__fq__DOT__elts_0_data
            : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___GEN_2 
        = ((0x1cU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                     >> 0x1bU)) | (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                                         >> 0x10U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___GEN_0 
        = ((0x1cU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                     >> 0xbU)) | (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___GEN_3 
        = ((0x3cU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                     >> 0x1aU)) | (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                                         >> 0x10U)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3981(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3981\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___GEN_1 
        = ((0x3cU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
                     >> 0xaU)) | (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___ex_rs_T_6 
        = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_msb_0 
            << 2U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_lsb_0)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___ex_rs_T_13 
        = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_msb_1 
            << 2U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_lsb_1)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3982(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3982\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT__mux_data_rawIn_normDist_1 
        = ((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                          >> 0x16U))) ? 0U : ((1U & (IData)(
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                             >> 0x15U)))
                                               ? 1U
                                               : ((1U 
                                                   & (IData)(
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                              >> 0x14U)))
                                                   ? 2U
                                                   : 
                                                  ((1U 
                                                    & (IData)(
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                               >> 0x13U)))
                                                    ? 3U
                                                    : 
                                                   ((1U 
                                                     & (IData)(
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                >> 0x12U)))
                                                     ? 4U
                                                     : 
                                                    ((1U 
                                                      & (IData)(
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                 >> 0x11U)))
                                                      ? 5U
                                                      : 
                                                     ((1U 
                                                       & (IData)(
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                  >> 0x10U)))
                                                       ? 6U
                                                       : 
                                                      ((1U 
                                                        & (IData)(
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                   >> 0xfU)))
                                                        ? 7U
                                                        : 
                                                       ((1U 
                                                         & (IData)(
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                    >> 0xeU)))
                                                         ? 8U
                                                         : 
                                                        ((1U 
                                                          & (IData)(
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                     >> 0xdU)))
                                                          ? 9U
                                                          : 
                                                         ((1U 
                                                           & (IData)(
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                      >> 0xcU)))
                                                           ? 0xaU
                                                           : 
                                                          ((1U 
                                                            & (IData)(
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                       >> 0xbU)))
                                                            ? 0xbU
                                                            : 
                                                           ((1U 
                                                             & (IData)(
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                        >> 0xaU)))
                                                             ? 0xcU
                                                             : 
                                                            ((1U 
                                                              & (IData)(
                                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                         >> 9U)))
                                                              ? 0xdU
                                                              : 
                                                             ((1U 
                                                               & (IData)(
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                          >> 8U)))
                                                               ? 0xeU
                                                               : 
                                                              ((1U 
                                                                & (IData)(
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                           >> 7U)))
                                                                ? 0xfU
                                                                : 
                                                               ((1U 
                                                                 & (IData)(
                                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                            >> 6U)))
                                                                 ? 0x10U
                                                                 : 
                                                                ((1U 
                                                                  & (IData)(
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                             >> 5U)))
                                                                  ? 0x11U
                                                                  : 
                                                                 ((1U 
                                                                   & (IData)(
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                              >> 4U)))
                                                                   ? 0x12U
                                                                   : 
                                                                  ((1U 
                                                                    & (IData)(
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                               >> 3U)))
                                                                    ? 0x13U
                                                                    : 
                                                                   ((1U 
                                                                     & (IData)(
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 2U)))
                                                                     ? 0x14U
                                                                     : 
                                                                    ((1U 
                                                                      & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 1U)))
                                                                      ? 0x15U
                                                                      : 0x16U))))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__3983(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__3983\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT__mux_data_rawIn_normDist 
        = ((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                          >> 0x33U))) ? 0U : ((1U & (IData)(
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                             >> 0x32U)))
                                               ? 1U
                                               : ((1U 
                                                   & (IData)(
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                              >> 0x31U)))
                                                   ? 2U
                                                   : 
                                                  ((1U 
                                                    & (IData)(
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                               >> 0x30U)))
                                                    ? 3U
                                                    : 
                                                   ((1U 
                                                     & (IData)(
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                >> 0x2fU)))
                                                     ? 4U
                                                     : 
                                                    ((1U 
                                                      & (IData)(
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                 >> 0x2eU)))
                                                      ? 5U
                                                      : 
                                                     ((1U 
                                                       & (IData)(
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                  >> 0x2dU)))
                                                       ? 6U
                                                       : 
                                                      ((1U 
                                                        & (IData)(
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                   >> 0x2cU)))
                                                        ? 7U
                                                        : 
                                                       ((1U 
                                                         & (IData)(
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                    >> 0x2bU)))
                                                         ? 8U
                                                         : 
                                                        ((1U 
                                                          & (IData)(
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                     >> 0x2aU)))
                                                          ? 9U
                                                          : 
                                                         ((1U 
                                                           & (IData)(
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                      >> 0x29U)))
                                                           ? 0xaU
                                                           : 
                                                          ((1U 
                                                            & (IData)(
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                       >> 0x28U)))
                                                            ? 0xbU
                                                            : 
                                                           ((1U 
                                                             & (IData)(
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                        >> 0x27U)))
                                                             ? 0xcU
                                                             : 
                                                            ((1U 
                                                              & (IData)(
                                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                         >> 0x26U)))
                                                              ? 0xdU
                                                              : 
                                                             ((1U 
                                                               & (IData)(
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                          >> 0x25U)))
                                                               ? 0xeU
                                                               : 
                                                              ((1U 
                                                                & (IData)(
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                           >> 0x24U)))
                                                                ? 0xfU
                                                                : 
                                                               ((1U 
                                                                 & (IData)(
                                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                            >> 0x23U)))
                                                                 ? 0x10U
                                                                 : 
                                                                ((1U 
                                                                  & (IData)(
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                             >> 0x22U)))
                                                                  ? 0x11U
                                                                  : 
                                                                 ((1U 
                                                                   & (IData)(
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                              >> 0x21U)))
                                                                   ? 0x12U
                                                                   : 
                                                                  ((1U 
                                                                    & (IData)(
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                               >> 0x20U)))
                                                                    ? 0x13U
                                                                    : 
                                                                   ((1U 
                                                                     & (IData)(
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 0x1fU)))
                                                                     ? 0x14U
                                                                     : 
                                                                    ((1U 
                                                                      & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 0x1eU)))
                                                                      ? 0x15U
                                                                      : 
                                                                     ((1U 
                                                                       & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 0x1dU)))
                                                                       ? 0x16U
                                                                       : 
                                                                      ((1U 
                                                                        & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 0x1cU)))
                                                                        ? 0x17U
                                                                        : 
                                                                       ((1U 
                                                                         & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 0x1bU)))
                                                                         ? 0x18U
                                                                         : 
                                                                        ((1U 
                                                                          & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 0x1aU)))
                                                                          ? 0x19U
                                                                          : 
                                                                         ((1U 
                                                                           & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 0x19U)))
                                                                           ? 0x1aU
                                                                           : 
                                                                          ((1U 
                                                                            & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 0x18U)))
                                                                            ? 0x1bU
                                                                            : 
                                                                           ((1U 
                                                                             & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 0x17U)))
                                                                             ? 0x1cU
                                                                             : 
                                                                            ((1U 
                                                                              & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 0x16U)))
                                                                              ? 0x1dU
                                                                              : 
                                                                             ((1U 
                                                                               & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 0x15U)))
                                                                               ? 0x1eU
                                                                               : 
                                                                              ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 0x14U)))
                                                                                ? 0x1fU
                                                                                : 
                                                                               ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 0x13U)))
                                                                                 ? 0x20U
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 0x12U)))
                                                                                 ? 0x21U
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 0x11U)))
                                                                                 ? 0x22U
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 0x10U)))
                                                                                 ? 0x23U
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 0xfU)))
                                                                                 ? 0x24U
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 0xeU)))
                                                                                 ? 0x25U
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 0xdU)))
                                                                                 ? 0x26U
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 0xcU)))
                                                                                 ? 0x27U
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 0xbU)))
                                                                                 ? 0x28U
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 0xaU)))
                                                                                 ? 0x29U
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 9U)))
                                                                                 ? 0x2aU
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 8U)))
                                                                                 ? 0x2bU
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 7U)))
                                                                                 ? 0x2cU
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 6U)))
                                                                                 ? 0x2dU
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 5U)))
                                                                                 ? 0x2eU
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 4U)))
                                                                                 ? 0x2fU
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 3U)))
                                                                                 ? 0x30U
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 2U)))
                                                                                 ? 0x31U
                                                                                 : 
                                                                                (0x32U 
                                                                                | (1U 
                                                                                & (~ (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
                                                                                >> 1U)))))))))))))))))))))))))))))))))))))))))))))))))))))));
}
