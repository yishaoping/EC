// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTestHarness.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTestHarness___024root.h"

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__23010(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__23010\n"); );
    // Body
    if ((0x2000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__beats1 
            = (0x1ffU & (~ (0xffffffU & (((IData)(0xfffU) 
                                          << (0xfU 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                 >> 7U))) 
                                         >> 3U))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__beats1 
            = (0x1ffU & (~ (0xffffffU & (((IData)(0xfffU) 
                                          << (0xfU 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                 >> 7U))) 
                                         >> 3U))));
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__beats1 = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__beats1 = 0U;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___T_302 
        = (IData)(((0x2000U == (0xe000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__blockUncachedGrant) 
                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__grantIsCached 
        = ((4U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                         >> 0xdU))) | (5U == (7U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                               >> 0xdU))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__same_cycle_resp 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT___same_cycle_resp_T_1) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_source) 
              == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                        >> 5U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_in_0_valid)
            ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_valid)
                ? (((QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_7) 
                                      << 0x18U) | (
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_6) 
                                                    << 0x10U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_5) 
                                                       << 8U) 
                                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_4)))))) 
                    << 0x20U) | (QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_3) 
                                                  << 0x18U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_2) 
                                                     << 0x10U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_1) 
                                                        << 8U) 
                                                       | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r)))))))
                : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_data)
            : (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                << 0x3fU) | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U])) 
                              << 0x1fU) | ((QData)((IData)(
                                                           vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                           >> 1U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___T_300 
        = (IData)(((0xa000U == (0xe000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_in_0_valid)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__23011(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__23011\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_ha9df12c5__0;
    VlWide<6>/*191:0*/ __Vtemp_h99addd7e__0;
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_cnt 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__beats1) 
           & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__counter) 
                 - (IData)(1U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_15 
        = (0xffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__beats1) 
                    & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__counter) 
                          - (IData)(1U)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__d_last 
        = ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__counter)) 
           | (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__beats1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError 
        = (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                 | ((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_cnt)) 
                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__accruedRefillError))));
    __Vtemp_ha9df12c5__0[1U] = (((IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                           << 0x3fU) 
                                          | (((QData)((IData)(
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                               >> 0xcU))) 
                                              << 0x2bU) 
                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                                 << 0x2aU) 
                                                | (((QData)((IData)(
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                     >> 0xcU))) 
                                                    << 0x16U) 
                                                   | (QData)((IData)(
                                                                     (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError) 
                                                                       << 0x15U) 
                                                                      | ((0x1ffffeU 
                                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                             >> 0xbU)) 
                                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)))))))))) 
                                 >> 0xcU) | ((IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                                        << 0x3fU) 
                                                       | (((QData)((IData)(
                                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                            >> 0xcU))) 
                                                           << 0x2bU) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                                              << 0x2aU) 
                                                             | (((QData)((IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                                >> 0xcU))) 
                                                                 << 0x16U) 
                                                                | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError) 
                                                                                << 0x15U) 
                                                                                | ((0x1ffffeU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                                >> 0xbU)) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError))))))))) 
                                                      >> 0x20U)) 
                                             << 0x14U));
    __Vtemp_h99addd7e__0[4U] = (((IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                           << 0x3fU) 
                                          | (((QData)((IData)(
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                               >> 0xcU))) 
                                              << 0x2bU) 
                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                                 << 0x2aU) 
                                                | (((QData)((IData)(
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                     >> 0xcU))) 
                                                    << 0x16U) 
                                                   | (QData)((IData)(
                                                                     (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError) 
                                                                       << 0x15U) 
                                                                      | ((0x1ffffeU 
                                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                             >> 0xbU)) 
                                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)))))))))) 
                                 >> 0x18U) | ((IData)(
                                                      ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                                         << 0x3fU) 
                                                        | (((QData)((IData)(
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                             >> 0xcU))) 
                                                            << 0x2bU) 
                                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                                               << 0x2aU) 
                                                              | (((QData)((IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                                >> 0xcU))) 
                                                                  << 0x16U) 
                                                                 | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError) 
                                                                                << 0x15U) 
                                                                                | ((0x1ffffeU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                                >> 0xbU)) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError))))))))) 
                                                       >> 0x20U)) 
                                              << 8U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[0U] 
        = (((IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                      << 0x3fU) | (((QData)((IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                     >> 0xcU))) 
                                    << 0x2bU) | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                                  << 0x2aU) 
                                                 | (((QData)((IData)(
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                      >> 0xcU))) 
                                                     << 0x16U) 
                                                    | (QData)((IData)(
                                                                      (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError) 
                                                                        << 0x15U) 
                                                                       | ((0x1ffffeU 
                                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                              >> 0xbU)) 
                                                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)))))))))) 
            << 0x14U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                         >> 0xcU));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[1U] 
        = __Vtemp_ha9df12c5__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[2U] 
        = ((0xfff00000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                           << 8U)) | ((IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                                 << 0x3fU) 
                                                | (((QData)((IData)(
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                     >> 0xcU))) 
                                                    << 0x2bU) 
                                                   | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                                       << 0x2aU) 
                                                      | (((QData)((IData)(
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                           >> 0xcU))) 
                                                          << 0x16U) 
                                                         | (QData)((IData)(
                                                                           (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError) 
                                                                             << 0x15U) 
                                                                            | ((0x1ffffeU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                                >> 0xbU)) 
                                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError))))))))) 
                                               >> 0x20U)) 
                                      >> 0xcU));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[3U] 
        = (((IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                      << 0x3fU) | (((QData)((IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                     >> 0xcU))) 
                                    << 0x2bU) | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                                  << 0x2aU) 
                                                 | (((QData)((IData)(
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                      >> 0xcU))) 
                                                     << 0x16U) 
                                                    | (QData)((IData)(
                                                                      (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError) 
                                                                        << 0x15U) 
                                                                       | ((0x1ffffeU 
                                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                              >> 0xbU)) 
                                                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)))))))))) 
            << 8U) | (0xfffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                  >> 0x18U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[4U] 
        = __Vtemp_h99addd7e__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[5U] 
        = ((IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                      << 0x3fU) | (((QData)((IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                     >> 0xcU))) 
                                    << 0x2bU) | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                                  << 0x2aU) 
                                                 | (((QData)((IData)(
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                      >> 0xcU))) 
                                                     << 0x16U) 
                                                    | (QData)((IData)(
                                                                      (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError) 
                                                                        << 0x15U) 
                                                                       | ((0x1ffffeU 
                                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                              >> 0xbU)) 
                                                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError))))))))) 
                    >> 0x20U)) >> 0x18U);
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__23012(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__23012\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT___GEN[0U] 
        = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_6)) 
                    << 0x36U) | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_5)) 
                                  << 0x2dU) | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_4)) 
                                                << 0x24U) 
                                               | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_3)) 
                                                   << 0x1bU) 
                                                  | (QData)((IData)(
                                                                    (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_2) 
                                                                      << 0x12U) 
                                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_1) 
                                                                         << 9U) 
                                                                        | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_0))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT___GEN[1U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_7) 
            << 0x1fU) | (IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_6)) 
                                   << 0x36U) | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_5)) 
                                                 << 0x2dU) 
                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_4)) 
                                                    << 0x24U) 
                                                   | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_3)) 
                                                       << 0x1bU) 
                                                      | (QData)((IData)(
                                                                        (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_2) 
                                                                          << 0x12U) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_1) 
                                                                             << 9U) 
                                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_0))))))))) 
                                 >> 0x20U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT___GEN[2U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_10) 
            << 0x1aU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_9) 
                          << 0x11U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_8) 
                                        << 8U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_7) 
                                                  >> 1U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT___GEN[3U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_14) 
            << 0x1eU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_13) 
                          << 0x15U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_12) 
                                        << 0xcU) | 
                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_11) 
                                         << 3U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_10) 
                                                   >> 6U)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT___GEN[4U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_17) 
            << 0x19U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_16) 
                          << 0x10U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_15) 
                                        << 7U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_14) 
                                                  >> 2U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT___GEN[5U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_21) 
            << 0x1dU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_20) 
                          << 0x14U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_19) 
                                        << 0xbU) | 
                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_18) 
                                         << 2U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_17) 
                                                   >> 7U)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT___GEN[6U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_24) 
            << 0x18U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_23) 
                          << 0xfU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_22) 
                                       << 6U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_21) 
                                                 >> 3U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT___GEN[7U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_28) 
            << 0x1cU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_27) 
                          << 0x13U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_26) 
                                        << 0xaU) | 
                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_25) 
                                         << 1U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_24) 
                                                   >> 8U)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT___GEN[8U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_31) 
            << 0x17U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_30) 
                          << 0xeU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_29) 
                                       << 5U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_28) 
                                                 >> 4U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT___GEN[9U] 
        = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_38)) 
                    << 0x36U) | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_37)) 
                                  << 0x2dU) | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_36)) 
                                                << 0x24U) 
                                               | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_35)) 
                                                   << 0x1bU) 
                                                  | (QData)((IData)(
                                                                    (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_34) 
                                                                      << 0x12U) 
                                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_33) 
                                                                         << 9U) 
                                                                        | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_32))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT___GEN[0xaU] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_39) 
            << 0x1fU) | (IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_38)) 
                                   << 0x36U) | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_37)) 
                                                 << 0x2dU) 
                                                | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_36)) 
                                                    << 0x24U) 
                                                   | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_35)) 
                                                       << 0x1bU) 
                                                      | (QData)((IData)(
                                                                        (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_34) 
                                                                          << 0x12U) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_33) 
                                                                             << 9U) 
                                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_32))))))))) 
                                 >> 0x20U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT___GEN[0xbU] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_42) 
            << 0x1aU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_41) 
                          << 0x11U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_40) 
                                        << 8U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_39) 
                                                  >> 1U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT___GEN[0xcU] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_46) 
            << 0x1eU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_45) 
                          << 0x15U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_44) 
                                        << 0xcU) | 
                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_43) 
                                         << 3U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_42) 
                                                   >> 6U)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT___GEN[0xdU] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_49) 
            << 0x19U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_48) 
                          << 0x10U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_47) 
                                        << 7U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_46) 
                                                  >> 2U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT___GEN[0xeU] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_53) 
            << 0x1dU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_52) 
                          << 0x14U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_51) 
                                        << 0xbU) | 
                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_50) 
                                         << 2U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_49) 
                                                   >> 7U)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT___GEN[0xfU] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_56) 
            << 0x18U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_55) 
                          << 0xfU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_54) 
                                       << 6U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_53) 
                                                 >> 3U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT___GEN[0x10U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_60) 
            << 0x1cU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_59) 
                          << 0x13U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_58) 
                                        << 0xaU) | 
                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_57) 
                                         << 1U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_56) 
                                                   >> 8U)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT___GEN[0x11U] 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_63) 
            << 0x17U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_62) 
                          << 0xeU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_61) 
                                       << 5U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__mem_60) 
                                                 >> 4U))));
}

extern const VlUnpacked<CData/*7:0*/, 128> VTestHarness__ConstPool__TABLE_hedf4ac3e_0;
extern const VlUnpacked<CData/*2:0*/, 128> VTestHarness__ConstPool__TABLE_h486ae98f_0;
extern const VlUnpacked<CData/*2:0*/, 128> VTestHarness__ConstPool__TABLE_h6c4e642c_0;
extern const VlUnpacked<CData/*2:0*/, 128> VTestHarness__ConstPool__TABLE_h95ad2e13_0;
extern const VlUnpacked<CData/*2:0*/, 128> VTestHarness__ConstPool__TABLE_h51102efa_0;
extern const VlUnpacked<CData/*2:0*/, 128> VTestHarness__ConstPool__TABLE_h9fff39c9_0;
extern const VlUnpacked<CData/*2:0*/, 128> VTestHarness__ConstPool__TABLE_h27053e20_0;

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__23013(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__23013\n"); );
    // Body
    vlSelf->__Vtableidx3 = ((0x70U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                      << 2U)) | ((0xeU 
                                                  & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__widx_gray) 
                                                      << 1U) 
                                                     ^ 
                                                     (8U 
                                                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__widx_gray)))) 
                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT___T)));
    if ((1U & VTestHarness__ConstPool__TABLE_hedf4ac3e_0
         [vlSelf->__Vtableidx3])) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_0_sink 
            = VTestHarness__ConstPool__TABLE_h486ae98f_0
            [vlSelf->__Vtableidx3];
    }
    if ((2U & VTestHarness__ConstPool__TABLE_hedf4ac3e_0
         [vlSelf->__Vtableidx3])) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_1_sink 
            = VTestHarness__ConstPool__TABLE_h6c4e642c_0
            [vlSelf->__Vtableidx3];
    }
    if ((4U & VTestHarness__ConstPool__TABLE_hedf4ac3e_0
         [vlSelf->__Vtableidx3])) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_2_sink 
            = VTestHarness__ConstPool__TABLE_h95ad2e13_0
            [vlSelf->__Vtableidx3];
    }
    if ((8U & VTestHarness__ConstPool__TABLE_hedf4ac3e_0
         [vlSelf->__Vtableidx3])) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_3_sink 
            = VTestHarness__ConstPool__TABLE_h51102efa_0
            [vlSelf->__Vtableidx3];
    }
    if ((0x10U & VTestHarness__ConstPool__TABLE_hedf4ac3e_0
         [vlSelf->__Vtableidx3])) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_4_sink 
            = VTestHarness__ConstPool__TABLE_h9fff39c9_0
            [vlSelf->__Vtableidx3];
    }
    if ((0x20U & VTestHarness__ConstPool__TABLE_hedf4ac3e_0
         [vlSelf->__Vtableidx3])) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_5_sink 
            = VTestHarness__ConstPool__TABLE_h27053e20_0
            [vlSelf->__Vtableidx3];
    }
}

extern const VlUnpacked<CData/*2:0*/, 128> VTestHarness__ConstPool__TABLE_h13f806b4_0;
extern const VlUnpacked<CData/*2:0*/, 128> VTestHarness__ConstPool__TABLE_h301b9bb2_0;

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__23014(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__23014\n"); );
    // Body
    if ((0x40U & VTestHarness__ConstPool__TABLE_hedf4ac3e_0
         [vlSelf->__Vtableidx3])) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_6_sink 
            = VTestHarness__ConstPool__TABLE_h13f806b4_0
            [vlSelf->__Vtableidx3];
    }
    if ((0x80U & VTestHarness__ConstPool__TABLE_hedf4ac3e_0
         [vlSelf->__Vtableidx3])) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_7_sink 
            = VTestHarness__ConstPool__TABLE_h301b9bb2_0
            [vlSelf->__Vtableidx3];
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[0U];
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[1U];
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[2U];
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__same_cycle_resp 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT___same_cycle_resp_T_1) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_source) 
              == (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                        >> 5U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__grantIsUncached 
        = (((1U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                          >> 0xdU))) | (0U == (7U & 
                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                >> 0xdU)))) 
           | (2U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                           >> 0xdU))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___metaArb_io_in_3_bits_data_T_1 
        = ((((((((((((((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd)) 
                       | (0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                      | (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                     | (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                    | (9U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                   | (0xaU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                  | (0xbU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                 | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                | (0xcU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
               | (0xdU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
              | (0xeU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
             | (0xfU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
            << 3U) | ((((((((((((((((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd)) 
                                    | (0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                                   | (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                                  | (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                                 | (9U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                                | (0xaU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                               | (0xbU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                              | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                             | (0xcU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                            | (0xdU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                           | (0xeU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                          | (0xfU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                         | (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                        | (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                       << 2U) | (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                       >> 0xbU))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__23015(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__23015\n"); );
    // Body
    if ((0x2000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__beats1 
            = (0x1ffU & (~ (0xffffffU & (((IData)(0xfffU) 
                                          << (0xfU 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                 >> 7U))) 
                                         >> 3U))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__beats1 
            = (0x1ffU & (~ (0xffffffU & (((IData)(0xfffU) 
                                          << (0xfU 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                 >> 7U))) 
                                         >> 3U))));
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__beats1 = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__beats1 = 0U;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___T_302 
        = (IData)(((0x2000U == (0xe000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__blockUncachedGrant) 
                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__grantIsCached 
        = ((4U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                         >> 0xdU))) | (5U == (7U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                               >> 0xdU))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT__same_cycle_resp 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT___same_cycle_resp_T_1) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_source) 
              == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                        >> 5U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_in_0_valid)
            ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_valid)
                ? (((QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_7) 
                                      << 0x18U) | (
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_6) 
                                                    << 0x10U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_5) 
                                                       << 8U) 
                                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_4)))))) 
                    << 0x20U) | (QData)((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_3) 
                                                  << 0x18U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_2) 
                                                     << 0x10U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_1) 
                                                        << 8U) 
                                                       | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r)))))))
                : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_data)
            : (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                << 0x3fU) | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U])) 
                              << 0x1fU) | ((QData)((IData)(
                                                           vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                           >> 1U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___T_300 
        = (IData)(((0xa000U == (0xe000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_in_0_valid)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__23016(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__23016\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_hed416d20__0;
    VlWide<6>/*191:0*/ __Vtemp_h0b9a8b25__0;
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_cnt 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__beats1) 
           & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__counter) 
                 - (IData)(1U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_15 
        = (0xffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__beats1) 
                    & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__counter) 
                          - (IData)(1U)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__d_last 
        = ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__counter)) 
           | (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__beats1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError 
        = (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                 | ((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_cnt)) 
                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__accruedRefillError))));
    __Vtemp_hed416d20__0[1U] = (((IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                           << 0x3fU) 
                                          | (((QData)((IData)(
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                               >> 0xcU))) 
                                              << 0x2bU) 
                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                                 << 0x2aU) 
                                                | (((QData)((IData)(
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                     >> 0xcU))) 
                                                    << 0x16U) 
                                                   | (QData)((IData)(
                                                                     (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError) 
                                                                       << 0x15U) 
                                                                      | ((0x1ffffeU 
                                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                             >> 0xbU)) 
                                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)))))))))) 
                                 >> 0xcU) | ((IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                                        << 0x3fU) 
                                                       | (((QData)((IData)(
                                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                            >> 0xcU))) 
                                                           << 0x2bU) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                                              << 0x2aU) 
                                                             | (((QData)((IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                                >> 0xcU))) 
                                                                 << 0x16U) 
                                                                | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError) 
                                                                                << 0x15U) 
                                                                                | ((0x1ffffeU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                                >> 0xbU)) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError))))))))) 
                                                      >> 0x20U)) 
                                             << 0x14U));
    __Vtemp_h0b9a8b25__0[4U] = (((IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                           << 0x3fU) 
                                          | (((QData)((IData)(
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                               >> 0xcU))) 
                                              << 0x2bU) 
                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                                 << 0x2aU) 
                                                | (((QData)((IData)(
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                     >> 0xcU))) 
                                                    << 0x16U) 
                                                   | (QData)((IData)(
                                                                     (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError) 
                                                                       << 0x15U) 
                                                                      | ((0x1ffffeU 
                                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                             >> 0xbU)) 
                                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)))))))))) 
                                 >> 0x18U) | ((IData)(
                                                      ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                                         << 0x3fU) 
                                                        | (((QData)((IData)(
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                             >> 0xcU))) 
                                                            << 0x2bU) 
                                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                                               << 0x2aU) 
                                                              | (((QData)((IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                                >> 0xcU))) 
                                                                  << 0x16U) 
                                                                 | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError) 
                                                                                << 0x15U) 
                                                                                | ((0x1ffffeU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                                >> 0xbU)) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError))))))))) 
                                                       >> 0x20U)) 
                                              << 8U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[0U] 
        = (((IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                      << 0x3fU) | (((QData)((IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                     >> 0xcU))) 
                                    << 0x2bU) | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                                  << 0x2aU) 
                                                 | (((QData)((IData)(
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                      >> 0xcU))) 
                                                     << 0x16U) 
                                                    | (QData)((IData)(
                                                                      (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError) 
                                                                        << 0x15U) 
                                                                       | ((0x1ffffeU 
                                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                              >> 0xbU)) 
                                                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)))))))))) 
            << 0x14U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                         >> 0xcU));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[1U] 
        = __Vtemp_hed416d20__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[2U] 
        = ((0xfff00000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                           << 8U)) | ((IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                                 << 0x3fU) 
                                                | (((QData)((IData)(
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                     >> 0xcU))) 
                                                    << 0x2bU) 
                                                   | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                                       << 0x2aU) 
                                                      | (((QData)((IData)(
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                           >> 0xcU))) 
                                                          << 0x16U) 
                                                         | (QData)((IData)(
                                                                           (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError) 
                                                                             << 0x15U) 
                                                                            | ((0x1ffffeU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                                >> 0xbU)) 
                                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError))))))))) 
                                               >> 0x20U)) 
                                      >> 0xcU));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[3U] 
        = (((IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                      << 0x3fU) | (((QData)((IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                     >> 0xcU))) 
                                    << 0x2bU) | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                                  << 0x2aU) 
                                                 | (((QData)((IData)(
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                      >> 0xcU))) 
                                                     << 0x16U) 
                                                    | (QData)((IData)(
                                                                      (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError) 
                                                                        << 0x15U) 
                                                                       | ((0x1ffffeU 
                                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                              >> 0xbU)) 
                                                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)))))))))) 
            << 8U) | (0xfffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                  >> 0x18U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[4U] 
        = __Vtemp_h0b9a8b25__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[5U] 
        = ((IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                      << 0x3fU) | (((QData)((IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                     >> 0xcU))) 
                                    << 0x2bU) | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError)) 
                                                  << 0x2aU) 
                                                 | (((QData)((IData)(
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                      >> 0xcU))) 
                                                     << 0x16U) 
                                                    | (QData)((IData)(
                                                                      (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError) 
                                                                        << 0x15U) 
                                                                       | ((0x1ffffeU 
                                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                                              >> 0xbU)) 
                                                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError))))))))) 
                    >> 0x20U)) >> 0x18U);
}

VL_INLINE_OPT void VTestHarness___024root___multiclk__TOP__0(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___multiclk__TOP__0\n"); );
    // Body
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__restore 
        = ((((~ (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__state)) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txm__DOT__out))) 
            & (3U == (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__debounce))) 
           | (0U == (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__prescaler)));
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT___GEN_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txm__DOT__out)) 
           & (3U == (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__debounce)));
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT___GEN_1 
        = ((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT___GEN_0) 
           | (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__txm__DOT__state));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__23017(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__23017\n"); );
    // Body
    if (vlSelf->reset) {
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxm__DOT__out = 1U;
    } else if (vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxm__DOT___T_5) {
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxm__DOT__out 
            = (1U & (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxm__DOT__shifter));
    }
    if (vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxm__DOT___T_5) {
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxm__DOT__shifter 
            = (0x100U | (0xffU & ((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxm__DOT__shifter) 
                                  >> 1U)));
    } else if (vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxm__DOT___T_4) {
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxm__DOT__shifter 
            = (vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__ram_ext__DOT__Memory
               [vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__deq_ptr_value] 
               << 1U);
    }
    if (((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT___T) 
         & (7U == (IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__index)))) {
        vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_7 
            = vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__data[0U];
    }
    if (((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT___T) 
         & (6U == (IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__index)))) {
        vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_6 
            = vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__data[0U];
    }
    if (((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT___T) 
         & (5U == (IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__index)))) {
        vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_5 
            = vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__data[0U];
    }
    if (((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT___T) 
         & (4U == (IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__index)))) {
        vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_4 
            = vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__data[0U];
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__23018(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__23018\n"); );
    // Body
    if (((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT___T) 
         & (3U == (IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__index)))) {
        vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_3 
            = vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__data[0U];
    }
    if (((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT___T) 
         & (2U == (IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__index)))) {
        vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_2 
            = vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__data[0U];
    }
    if (((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT___T) 
         & (1U == (IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__index)))) {
        vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_1 
            = vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__data[0U];
    }
    if (((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT___T) 
         & (0U == (IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__index)))) {
        vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_0 
            = vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__data[0U];
    }
    if (vlSelf->__Vdlyvset__TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__ram_ext__DOT__Memory__v0) {
        vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__ram_ext__DOT__Memory[vlSelf->__Vdlyvdim0__TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__ram_ext__DOT__Memory__v0] 
            = vlSelf->__Vdlyvval__TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__ram_ext__DOT__Memory__v0;
    }
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxm__DOT___T_5 
        = ((0U == (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxm__DOT__prescaler)) 
           & (0U != (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxm__DOT__counter)));
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__deq_ptr_value 
        = vlSelf->__Vdly__TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__deq_ptr_value;
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__data[0U] 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__data[0U];
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__data[1U] 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__data[1U];
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__data[2U] 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__data[2U];
    vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__data[3U] 
        = vlSelf->__Vdly__TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__data[3U];
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__ptr_match 
        = ((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__enq_ptr_value) 
           == (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__deq_ptr_value));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__23019(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__23019\n"); );
    // Body
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__full 
        = ((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__ptr_match) 
           & (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__maybe_full));
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__empty 
        = ((IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__ptr_match) 
           & (~ (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__maybe_full)));
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__do_enq 
        = ((~ (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__full)) 
           & (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__sim__DOT_____05Fin_valid_reg));
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__do_deq 
        = (1U & ((~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxm__DOT__counter)))) 
                 & (~ (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__empty))));
    vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxm__DOT___T_4 
        = (((~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxm__DOT__counter)))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__empty))) 
           & (0U != vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxm__DOT__plusarg_reader__DOT__myplus));
}

VL_INLINE_OPT void VTestHarness___024root___multiclk__TOP__1(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___multiclk__TOP__1\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_hca0cc01c__0;
    VlWide<16>/*511:0*/ __Vtemp_h9ccfa325__0;
    VlWide<3>/*95:0*/ __Vtemp_h530a7cc9__0;
    VlWide<4>/*127:0*/ __Vtemp_h8f26d96c__0;
    VlWide<4>/*127:0*/ __Vtemp_hee6bb56e__0;
    // Body
    __Vtemp_hca0cc01c__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_0_address;
    __Vtemp_hca0cc01c__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_1_address;
    __Vtemp_hca0cc01c__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_2_address;
    __Vtemp_hca0cc01c__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_3_address;
    __Vtemp_hca0cc01c__0[4U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_4_address;
    __Vtemp_hca0cc01c__0[5U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_5_address;
    __Vtemp_hca0cc01c__0[6U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_7_address)) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_6_address))));
    __Vtemp_hca0cc01c__0[7U] = (IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_7_address)) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_6_address))) 
                                        >> 0x20U));
    __Vtemp_h9ccfa325__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_0_data);
    __Vtemp_h9ccfa325__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_0_data 
                                        >> 0x20U));
    __Vtemp_h9ccfa325__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_1_data);
    __Vtemp_h9ccfa325__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_1_data 
                                        >> 0x20U));
    __Vtemp_h9ccfa325__0[4U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_2_data);
    __Vtemp_h9ccfa325__0[5U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_2_data 
                                        >> 0x20U));
    __Vtemp_h9ccfa325__0[6U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_3_data);
    __Vtemp_h9ccfa325__0[7U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_3_data 
                                        >> 0x20U));
    __Vtemp_h9ccfa325__0[8U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_4_data);
    __Vtemp_h9ccfa325__0[9U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_4_data 
                                        >> 0x20U));
    __Vtemp_h9ccfa325__0[0xaU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_5_data);
    __Vtemp_h9ccfa325__0[0xbU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_5_data 
                                          >> 0x20U));
    __Vtemp_h9ccfa325__0[0xcU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_6_data);
    __Vtemp_h9ccfa325__0[0xdU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_6_data 
                                          >> 0x20U));
    __Vtemp_h9ccfa325__0[0xeU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_7_data);
    __Vtemp_h9ccfa325__0[0xfU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_7_data 
                                          >> 0x20U));
    __Vtemp_h530a7cc9__0[0U] = (IData)((((QData)((IData)(
                                                         __Vtemp_h9ccfa325__0[
                                                         (((IData)(0x3fU) 
                                                           + 
                                                           (0x1ffU 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                               << 6U))) 
                                                          >> 5U)])) 
                                         << ((0U == 
                                              (0x1fU 
                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                  << 6U)))
                                              ? 0x20U
                                              : ((IData)(0x40U) 
                                                 - 
                                                 (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                     << 6U))))) 
                                        | (((0U == 
                                             (0x1fU 
                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                 << 6U)))
                                             ? 0ULL
                                             : ((QData)((IData)(
                                                                __Vtemp_h9ccfa325__0[
                                                                (((IData)(0x1fU) 
                                                                  + 
                                                                  (0x1ffU 
                                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                                      << 6U))) 
                                                                 >> 5U)])) 
                                                << 
                                                ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                     << 6U))))) 
                                           | ((QData)((IData)(
                                                              __Vtemp_h9ccfa325__0[
                                                              (0xeU 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                                  << 1U))])) 
                                              >> (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                     << 6U))))));
    __Vtemp_h530a7cc9__0[1U] = (IData)(((((QData)((IData)(
                                                          __Vtemp_h9ccfa325__0[
                                                          (((IData)(0x3fU) 
                                                            + 
                                                            (0x1ffU 
                                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                                << 6U))) 
                                                           >> 5U)])) 
                                          << ((0U == 
                                               (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                   << 6U)))
                                               ? 0x20U
                                               : ((IData)(0x40U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                      << 6U))))) 
                                         | (((0U == 
                                              (0x1fU 
                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                  << 6U)))
                                              ? 0ULL
                                              : ((QData)((IData)(
                                                                 __Vtemp_h9ccfa325__0[
                                                                 (((IData)(0x1fU) 
                                                                   + 
                                                                   (0x1ffU 
                                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                                       << 6U))) 
                                                                  >> 5U)])) 
                                                 << 
                                                 ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                      << 6U))))) 
                                            | ((QData)((IData)(
                                                               __Vtemp_h9ccfa325__0[
                                                               (0xeU 
                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                                   << 1U))])) 
                                               >> (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                      << 6U))))) 
                                        >> 0x20U));
    __Vtemp_h8f26d96c__0[3U] = ((6U & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_7_source) 
                                          << 0xeU) 
                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_6_source) 
                                             << 0xcU) 
                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_5_source) 
                                                << 0xaU) 
                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_4_source) 
                                                   << 8U) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_3_source) 
                                                      << 6U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_2_source) 
                                                         << 4U) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_1_source) 
                                                            << 2U) 
                                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_0_source)))))))) 
                                        >> (0xfU & 
                                            ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                             << 1U))) 
                                       << 1U)) | ((
                                                   ((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                         << 5U)))
                                                     ? 0U
                                                     : 
                                                    (__Vtemp_hca0cc01c__0[
                                                     (((IData)(0x1fU) 
                                                       + 
                                                       (0xffU 
                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                           << 5U))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                          << 5U))))) 
                                                   | (__Vtemp_hca0cc01c__0[
                                                      (7U 
                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                          << 5U)))) 
                                                  >> 0x1fU));
    __Vtemp_hee6bb56e__0[3U] = ((((0x17U >= (0x1fU 
                                             & ((IData)(3U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index))))
                                   ? (7U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_7_param) 
                                              << 0x15U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_6_param) 
                                                 << 0x12U) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_5_param) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_4_param) 
                                                       << 0xcU) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_3_param) 
                                                          << 9U) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_2_param) 
                                                             << 6U) 
                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_1_param) 
                                                                << 3U) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_0_param)))))))) 
                                            >> (0x1fU 
                                                & ((IData)(3U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index)))))
                                   : 0U) << 7U) | (
                                                   (0x78U 
                                                    & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_7_size) 
                                                          << 0x1cU) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_6_size) 
                                                             << 0x18U) 
                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_5_size) 
                                                                << 0x14U) 
                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_4_size) 
                                                                   << 0x10U) 
                                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_3_size) 
                                                                      << 0xcU) 
                                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_2_size) 
                                                                         << 8U) 
                                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_1_size) 
                                                                            << 4U) 
                                                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_0_size)))))))) 
                                                        >> 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                            << 2U))) 
                                                       << 3U)) 
                                                   | __Vtemp_h8f26d96c__0[3U]));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[0U] 
        = ((__Vtemp_h530a7cc9__0[0U] << 1U) | (1U & 
                                               ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_7_corrupt) 
                                                  << 7U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_6_corrupt) 
                                                     << 6U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_5_corrupt) 
                                                        << 5U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_4_corrupt) 
                                                           << 4U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_3_corrupt) 
                                                              << 3U) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_2_corrupt) 
                                                                 << 2U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_1_corrupt) 
                                                                    << 1U) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_0_corrupt)))))))) 
                                                >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[1U] 
        = ((__Vtemp_h530a7cc9__0[0U] >> 0x1fU) | (__Vtemp_h530a7cc9__0[1U] 
                                                  << 1U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[2U] 
        = ((__Vtemp_h530a7cc9__0[1U] >> 0x1fU) | ((
                                                   ((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                         << 5U)))
                                                     ? 0U
                                                     : 
                                                    (__Vtemp_hca0cc01c__0[
                                                     (((IData)(0x1fU) 
                                                       + 
                                                       (0xffU 
                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                           << 5U))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                          << 5U))))) 
                                                   | (__Vtemp_hca0cc01c__0[
                                                      (7U 
                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                          << 5U)))) 
                                                  << 1U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[3U] 
        = ((((0x17U >= (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index))))
              ? (7U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_7_opcode) 
                         << 0x15U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_6_opcode) 
                                       << 0x12U) | 
                                      (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_5_opcode) 
                                        << 0xfU) | 
                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_4_opcode) 
                                         << 0xcU) | 
                                        (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_3_opcode) 
                                          << 9U) | 
                                         (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_2_opcode) 
                                           << 6U) | 
                                          (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_1_opcode) 
                                            << 3U) 
                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__mem_0_opcode)))))))) 
                       >> (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__index)))))
              : 0U) << 0xaU) | __Vtemp_hee6bb56e__0[3U]);
}

VL_INLINE_OPT void VTestHarness___024root___multiclk__TOP__2(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___multiclk__TOP__2\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_h3a0079cc__0;
    VlWide<16>/*511:0*/ __Vtemp_h4f5f090f__0;
    VlWide<3>/*95:0*/ __Vtemp_ha7e7e286__0;
    VlWide<4>/*127:0*/ __Vtemp_h0fba4d27__0;
    VlWide<4>/*127:0*/ __Vtemp_h53c014a5__0;
    VlWide<4>/*127:0*/ __Vtemp_h49dca115__0;
    // Body
    __Vtemp_h3a0079cc__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_0_address;
    __Vtemp_h3a0079cc__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_1_address;
    __Vtemp_h3a0079cc__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_2_address;
    __Vtemp_h3a0079cc__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_3_address;
    __Vtemp_h3a0079cc__0[4U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_4_address;
    __Vtemp_h3a0079cc__0[5U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_5_address;
    __Vtemp_h3a0079cc__0[6U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_7_address)) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_6_address))));
    __Vtemp_h3a0079cc__0[7U] = (IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_7_address)) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_6_address))) 
                                        >> 0x20U));
    __Vtemp_h4f5f090f__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_0_data);
    __Vtemp_h4f5f090f__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_0_data 
                                        >> 0x20U));
    __Vtemp_h4f5f090f__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_1_data);
    __Vtemp_h4f5f090f__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_1_data 
                                        >> 0x20U));
    __Vtemp_h4f5f090f__0[4U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_2_data);
    __Vtemp_h4f5f090f__0[5U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_2_data 
                                        >> 0x20U));
    __Vtemp_h4f5f090f__0[6U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_3_data);
    __Vtemp_h4f5f090f__0[7U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_3_data 
                                        >> 0x20U));
    __Vtemp_h4f5f090f__0[8U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_4_data);
    __Vtemp_h4f5f090f__0[9U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_4_data 
                                        >> 0x20U));
    __Vtemp_h4f5f090f__0[0xaU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_5_data);
    __Vtemp_h4f5f090f__0[0xbU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_5_data 
                                          >> 0x20U));
    __Vtemp_h4f5f090f__0[0xcU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_6_data);
    __Vtemp_h4f5f090f__0[0xdU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_6_data 
                                          >> 0x20U));
    __Vtemp_h4f5f090f__0[0xeU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_7_data);
    __Vtemp_h4f5f090f__0[0xfU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_7_data 
                                          >> 0x20U));
    __Vtemp_ha7e7e286__0[0U] = (((IData)((((QData)((IData)(
                                                           __Vtemp_h4f5f090f__0[
                                                           (((IData)(0x3fU) 
                                                             + 
                                                             (0x1ffU 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                 << 6U))) 
                                                            >> 5U)])) 
                                           << ((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U)))
                                                ? 0x20U
                                                : ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                          | (((0U == 
                                               (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                   << 6U)))
                                               ? 0ULL
                                               : ((QData)((IData)(
                                                                  __Vtemp_h4f5f090f__0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x1ffU 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                        << 6U))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                             | ((QData)((IData)(
                                                                __Vtemp_h4f5f090f__0[
                                                                (0xeU 
                                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                    << 1U))])) 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U)))))) 
                                 << 1U) | (1U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_7_corrupt) 
                                                   << 7U) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_6_corrupt) 
                                                      << 6U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_5_corrupt) 
                                                         << 5U) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_4_corrupt) 
                                                            << 4U) 
                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_3_corrupt) 
                                                               << 3U) 
                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_2_corrupt) 
                                                                  << 2U) 
                                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_1_corrupt) 
                                                                     << 1U) 
                                                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_0_corrupt)))))))) 
                                                 >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index))));
    __Vtemp_ha7e7e286__0[1U] = (((IData)((((QData)((IData)(
                                                           __Vtemp_h4f5f090f__0[
                                                           (((IData)(0x3fU) 
                                                             + 
                                                             (0x1ffU 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                 << 6U))) 
                                                            >> 5U)])) 
                                           << ((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U)))
                                                ? 0x20U
                                                : ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                          | (((0U == 
                                               (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                   << 6U)))
                                               ? 0ULL
                                               : ((QData)((IData)(
                                                                  __Vtemp_h4f5f090f__0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x1ffU 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                        << 6U))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                             | ((QData)((IData)(
                                                                __Vtemp_h4f5f090f__0[
                                                                (0xeU 
                                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                    << 1U))])) 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U)))))) 
                                 >> 0x1fU) | ((IData)(
                                                      ((((QData)((IData)(
                                                                         __Vtemp_h4f5f090f__0[
                                                                         (((IData)(0x3fU) 
                                                                           + 
                                                                           (0x1ffU 
                                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                               << 6U))) 
                                                                          >> 5U)])) 
                                                         << 
                                                         ((0U 
                                                           == 
                                                           (0x1fU 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                               << 6U)))
                                                           ? 0x20U
                                                           : 
                                                          ((IData)(0x40U) 
                                                           - 
                                                           (0x1fU 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                               << 6U))))) 
                                                        | (((0U 
                                                             == 
                                                             (0x1fU 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                 << 6U)))
                                                             ? 0ULL
                                                             : 
                                                            ((QData)((IData)(
                                                                             __Vtemp_h4f5f090f__0[
                                                                             (((IData)(0x1fU) 
                                                                               + 
                                                                               (0x1ffU 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                                << 6U))) 
                                                                              >> 5U)])) 
                                                             << 
                                                             ((IData)(0x20U) 
                                                              - 
                                                              (0x1fU 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                  << 6U))))) 
                                                           | ((QData)((IData)(
                                                                              __Vtemp_h4f5f090f__0[
                                                                              (0xeU 
                                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                                << 1U))])) 
                                                              >> 
                                                              (0x1fU 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                  << 6U))))) 
                                                       >> 0x20U)) 
                                              << 1U));
    __Vtemp_ha7e7e286__0[2U] = ((IData)(((((QData)((IData)(
                                                           __Vtemp_h4f5f090f__0[
                                                           (((IData)(0x3fU) 
                                                             + 
                                                             (0x1ffU 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                 << 6U))) 
                                                            >> 5U)])) 
                                           << ((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U)))
                                                ? 0x20U
                                                : ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                          | (((0U == 
                                               (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                   << 6U)))
                                               ? 0ULL
                                               : ((QData)((IData)(
                                                                  __Vtemp_h4f5f090f__0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x1ffU 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                        << 6U))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                             | ((QData)((IData)(
                                                                __Vtemp_h4f5f090f__0[
                                                                (0xeU 
                                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                    << 1U))])) 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U))))) 
                                         >> 0x20U)) 
                                >> 0x1fU);
    __Vtemp_h0fba4d27__0[2U] = (((((0U == (0x1fU & 
                                           ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                            << 5U)))
                                    ? 0U : (__Vtemp_h3a0079cc__0[
                                            (((IData)(0x1fU) 
                                              + (0xffU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 5U))) 
                                             >> 5U)] 
                                            << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                      << 5U))))) 
                                  | (__Vtemp_h3a0079cc__0[
                                     (7U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index))] 
                                     >> (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                  << 5U)))) 
                                 << 9U) | ((0x1feU 
                                            & ((IData)(
                                                       ((((QData)((IData)(
                                                                          (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_7_mask) 
                                                                            << 0x18U) 
                                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_6_mask) 
                                                                               << 0x10U) 
                                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_5_mask) 
                                                                                << 8U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_4_mask)))))) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_3_mask) 
                                                                             << 0x18U) 
                                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_2_mask) 
                                                                                << 0x10U) 
                                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_1_mask) 
                                                                                << 8U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_0_mask))))))) 
                                                        >> 
                                                        (0x3fU 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                            << 3U)))) 
                                               << 1U)) 
                                           | __Vtemp_ha7e7e286__0[2U]));
    __Vtemp_h53c014a5__0[3U] = ((0x600U & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_7_source) 
                                              << 0xeU) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_6_source) 
                                                 << 0xcU) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_5_source) 
                                                    << 0xaU) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_4_source) 
                                                       << 8U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_3_source) 
                                                          << 6U) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_2_source) 
                                                             << 4U) 
                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_1_source) 
                                                                << 2U) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_0_source)))))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                   << 1U))) 
                                           << 9U)) 
                                | ((((0U == (0x1fU 
                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                << 5U)))
                                      ? 0U : (__Vtemp_h3a0079cc__0[
                                              (((IData)(0x1fU) 
                                                + (0xffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                      << 5U))) 
                                               >> 5U)] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                      << 5U))))) 
                                    | (__Vtemp_h3a0079cc__0[
                                       (7U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index))] 
                                       >> (0x1fU & 
                                           ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                            << 5U)))) 
                                   >> 0x17U));
    __Vtemp_h49dca115__0[3U] = ((((0x17U >= (0x1fU 
                                             & ((IData)(3U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index))))
                                   ? (7U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_7_param) 
                                              << 0x15U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_6_param) 
                                                 << 0x12U) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_5_param) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_4_param) 
                                                       << 0xcU) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_3_param) 
                                                          << 9U) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_2_param) 
                                                             << 6U) 
                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_1_param) 
                                                                << 3U) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_0_param)))))))) 
                                            >> (0x1fU 
                                                & ((IData)(3U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index)))))
                                   : 0U) << 0xfU) | 
                                ((0x7800U & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_7_size) 
                                                << 0x1cU) 
                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_6_size) 
                                                   << 0x18U) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_5_size) 
                                                      << 0x14U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_4_size) 
                                                         << 0x10U) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_3_size) 
                                                            << 0xcU) 
                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_2_size) 
                                                               << 8U) 
                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_1_size) 
                                                                  << 4U) 
                                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_0_size)))))))) 
                                              >> (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                     << 2U))) 
                                             << 0xbU)) 
                                 | __Vtemp_h53c014a5__0[3U]));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[0U] 
        = __Vtemp_ha7e7e286__0[0U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[1U] 
        = __Vtemp_ha7e7e286__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[2U] 
        = __Vtemp_h0fba4d27__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[3U] 
        = ((((0x17U >= (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index))))
              ? (7U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_7_opcode) 
                         << 0x15U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_6_opcode) 
                                       << 0x12U) | 
                                      (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_5_opcode) 
                                        << 0xfU) | 
                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_4_opcode) 
                                         << 0xcU) | 
                                        (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_3_opcode) 
                                          << 9U) | 
                                         (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_2_opcode) 
                                           << 6U) | 
                                          (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_1_opcode) 
                                            << 3U) 
                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__mem_0_opcode)))))))) 
                       >> (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__index)))))
              : 0U) << 0x12U) | __Vtemp_h49dca115__0[3U]);
}

VL_INLINE_OPT void VTestHarness___024root___multiclk__TOP__3(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___multiclk__TOP__3\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_haf3cb62d__0;
    VlWide<16>/*511:0*/ __Vtemp_h37fdbc57__0;
    VlWide<3>/*95:0*/ __Vtemp_h1079783a__0;
    VlWide<4>/*127:0*/ __Vtemp_h59a45f15__0;
    VlWide<4>/*127:0*/ __Vtemp_ha15a6fc4__0;
    // Body
    __Vtemp_haf3cb62d__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_0_address;
    __Vtemp_haf3cb62d__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_1_address;
    __Vtemp_haf3cb62d__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_2_address;
    __Vtemp_haf3cb62d__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_3_address;
    __Vtemp_haf3cb62d__0[4U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_4_address;
    __Vtemp_haf3cb62d__0[5U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_5_address;
    __Vtemp_haf3cb62d__0[6U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_7_address)) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_6_address))));
    __Vtemp_haf3cb62d__0[7U] = (IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_7_address)) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_6_address))) 
                                        >> 0x20U));
    __Vtemp_h37fdbc57__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_0_data);
    __Vtemp_h37fdbc57__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_0_data 
                                        >> 0x20U));
    __Vtemp_h37fdbc57__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_1_data);
    __Vtemp_h37fdbc57__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_1_data 
                                        >> 0x20U));
    __Vtemp_h37fdbc57__0[4U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_2_data);
    __Vtemp_h37fdbc57__0[5U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_2_data 
                                        >> 0x20U));
    __Vtemp_h37fdbc57__0[6U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_3_data);
    __Vtemp_h37fdbc57__0[7U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_3_data 
                                        >> 0x20U));
    __Vtemp_h37fdbc57__0[8U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_4_data);
    __Vtemp_h37fdbc57__0[9U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_4_data 
                                        >> 0x20U));
    __Vtemp_h37fdbc57__0[0xaU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_5_data);
    __Vtemp_h37fdbc57__0[0xbU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_5_data 
                                          >> 0x20U));
    __Vtemp_h37fdbc57__0[0xcU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_6_data);
    __Vtemp_h37fdbc57__0[0xdU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_6_data 
                                          >> 0x20U));
    __Vtemp_h37fdbc57__0[0xeU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_7_data);
    __Vtemp_h37fdbc57__0[0xfU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_7_data 
                                          >> 0x20U));
    __Vtemp_h1079783a__0[0U] = (IData)((((QData)((IData)(
                                                         __Vtemp_h37fdbc57__0[
                                                         (((IData)(0x3fU) 
                                                           + 
                                                           (0x1ffU 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                               << 6U))) 
                                                          >> 5U)])) 
                                         << ((0U == 
                                              (0x1fU 
                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                  << 6U)))
                                              ? 0x20U
                                              : ((IData)(0x40U) 
                                                 - 
                                                 (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                     << 6U))))) 
                                        | (((0U == 
                                             (0x1fU 
                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                 << 6U)))
                                             ? 0ULL
                                             : ((QData)((IData)(
                                                                __Vtemp_h37fdbc57__0[
                                                                (((IData)(0x1fU) 
                                                                  + 
                                                                  (0x1ffU 
                                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                                      << 6U))) 
                                                                 >> 5U)])) 
                                                << 
                                                ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                     << 6U))))) 
                                           | ((QData)((IData)(
                                                              __Vtemp_h37fdbc57__0[
                                                              (0xeU 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                                  << 1U))])) 
                                              >> (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                     << 6U))))));
    __Vtemp_h1079783a__0[1U] = (IData)(((((QData)((IData)(
                                                          __Vtemp_h37fdbc57__0[
                                                          (((IData)(0x3fU) 
                                                            + 
                                                            (0x1ffU 
                                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                                << 6U))) 
                                                           >> 5U)])) 
                                          << ((0U == 
                                               (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                   << 6U)))
                                               ? 0x20U
                                               : ((IData)(0x40U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                      << 6U))))) 
                                         | (((0U == 
                                              (0x1fU 
                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                  << 6U)))
                                              ? 0ULL
                                              : ((QData)((IData)(
                                                                 __Vtemp_h37fdbc57__0[
                                                                 (((IData)(0x1fU) 
                                                                   + 
                                                                   (0x1ffU 
                                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                                       << 6U))) 
                                                                  >> 5U)])) 
                                                 << 
                                                 ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                      << 6U))))) 
                                            | ((QData)((IData)(
                                                               __Vtemp_h37fdbc57__0[
                                                               (0xeU 
                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                                   << 1U))])) 
                                               >> (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                      << 6U))))) 
                                        >> 0x20U));
    __Vtemp_h59a45f15__0[3U] = ((6U & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_7_source) 
                                          << 0xeU) 
                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_6_source) 
                                             << 0xcU) 
                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_5_source) 
                                                << 0xaU) 
                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_4_source) 
                                                   << 8U) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_3_source) 
                                                      << 6U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_2_source) 
                                                         << 4U) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_1_source) 
                                                            << 2U) 
                                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_0_source)))))))) 
                                        >> (0xfU & 
                                            ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                             << 1U))) 
                                       << 1U)) | ((
                                                   ((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                         << 5U)))
                                                     ? 0U
                                                     : 
                                                    (__Vtemp_haf3cb62d__0[
                                                     (((IData)(0x1fU) 
                                                       + 
                                                       (0xffU 
                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                           << 5U))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                          << 5U))))) 
                                                   | (__Vtemp_haf3cb62d__0[
                                                      (7U 
                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                          << 5U)))) 
                                                  >> 0x1fU));
    __Vtemp_ha15a6fc4__0[3U] = ((((0x17U >= (0x1fU 
                                             & ((IData)(3U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index))))
                                   ? (7U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_7_param) 
                                              << 0x15U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_6_param) 
                                                 << 0x12U) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_5_param) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_4_param) 
                                                       << 0xcU) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_3_param) 
                                                          << 9U) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_2_param) 
                                                             << 6U) 
                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_1_param) 
                                                                << 3U) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_0_param)))))))) 
                                            >> (0x1fU 
                                                & ((IData)(3U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index)))))
                                   : 0U) << 7U) | (
                                                   (0x78U 
                                                    & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_7_size) 
                                                          << 0x1cU) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_6_size) 
                                                             << 0x18U) 
                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_5_size) 
                                                                << 0x14U) 
                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_4_size) 
                                                                   << 0x10U) 
                                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_3_size) 
                                                                      << 0xcU) 
                                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_2_size) 
                                                                         << 8U) 
                                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_1_size) 
                                                                            << 4U) 
                                                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_0_size)))))))) 
                                                        >> 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                            << 2U))) 
                                                       << 3U)) 
                                                   | __Vtemp_h59a45f15__0[3U]));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[0U] 
        = ((__Vtemp_h1079783a__0[0U] << 1U) | (1U & 
                                               ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_7_corrupt) 
                                                  << 7U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_6_corrupt) 
                                                     << 6U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_5_corrupt) 
                                                        << 5U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_4_corrupt) 
                                                           << 4U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_3_corrupt) 
                                                              << 3U) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_2_corrupt) 
                                                                 << 2U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_1_corrupt) 
                                                                    << 1U) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_0_corrupt)))))))) 
                                                >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[1U] 
        = ((__Vtemp_h1079783a__0[0U] >> 0x1fU) | (__Vtemp_h1079783a__0[1U] 
                                                  << 1U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[2U] 
        = ((__Vtemp_h1079783a__0[1U] >> 0x1fU) | ((
                                                   ((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                         << 5U)))
                                                     ? 0U
                                                     : 
                                                    (__Vtemp_haf3cb62d__0[
                                                     (((IData)(0x1fU) 
                                                       + 
                                                       (0xffU 
                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                           << 5U))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                          << 5U))))) 
                                                   | (__Vtemp_haf3cb62d__0[
                                                      (7U 
                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                          << 5U)))) 
                                                  << 1U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[3U] 
        = ((((0x17U >= (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index))))
              ? (7U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_7_opcode) 
                         << 0x15U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_6_opcode) 
                                       << 0x12U) | 
                                      (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_5_opcode) 
                                        << 0xfU) | 
                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_4_opcode) 
                                         << 0xcU) | 
                                        (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_3_opcode) 
                                          << 9U) | 
                                         (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_2_opcode) 
                                           << 6U) | 
                                          (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_1_opcode) 
                                            << 3U) 
                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__mem_0_opcode)))))))) 
                       >> (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__index)))))
              : 0U) << 0xaU) | __Vtemp_ha15a6fc4__0[3U]);
}

VL_INLINE_OPT void VTestHarness___024root___multiclk__TOP__4(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___multiclk__TOP__4\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_h775da16e__0;
    VlWide<16>/*511:0*/ __Vtemp_h8d780f69__0;
    VlWide<3>/*95:0*/ __Vtemp_ha2e78d82__0;
    VlWide<4>/*127:0*/ __Vtemp_h029b9980__0;
    VlWide<4>/*127:0*/ __Vtemp_hafc775a1__0;
    VlWide<4>/*127:0*/ __Vtemp_h4f0c815b__0;
    // Body
    __Vtemp_h775da16e__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_0_address;
    __Vtemp_h775da16e__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_1_address;
    __Vtemp_h775da16e__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_2_address;
    __Vtemp_h775da16e__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_3_address;
    __Vtemp_h775da16e__0[4U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_4_address;
    __Vtemp_h775da16e__0[5U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_5_address;
    __Vtemp_h775da16e__0[6U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_7_address)) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_6_address))));
    __Vtemp_h775da16e__0[7U] = (IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_7_address)) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_6_address))) 
                                        >> 0x20U));
    __Vtemp_h8d780f69__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_0_data);
    __Vtemp_h8d780f69__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_0_data 
                                        >> 0x20U));
    __Vtemp_h8d780f69__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_1_data);
    __Vtemp_h8d780f69__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_1_data 
                                        >> 0x20U));
    __Vtemp_h8d780f69__0[4U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_2_data);
    __Vtemp_h8d780f69__0[5U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_2_data 
                                        >> 0x20U));
    __Vtemp_h8d780f69__0[6U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_3_data);
    __Vtemp_h8d780f69__0[7U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_3_data 
                                        >> 0x20U));
    __Vtemp_h8d780f69__0[8U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_4_data);
    __Vtemp_h8d780f69__0[9U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_4_data 
                                        >> 0x20U));
    __Vtemp_h8d780f69__0[0xaU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_5_data);
    __Vtemp_h8d780f69__0[0xbU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_5_data 
                                          >> 0x20U));
    __Vtemp_h8d780f69__0[0xcU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_6_data);
    __Vtemp_h8d780f69__0[0xdU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_6_data 
                                          >> 0x20U));
    __Vtemp_h8d780f69__0[0xeU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_7_data);
    __Vtemp_h8d780f69__0[0xfU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_7_data 
                                          >> 0x20U));
    __Vtemp_ha2e78d82__0[0U] = (((IData)((((QData)((IData)(
                                                           __Vtemp_h8d780f69__0[
                                                           (((IData)(0x3fU) 
                                                             + 
                                                             (0x1ffU 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                 << 6U))) 
                                                            >> 5U)])) 
                                           << ((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U)))
                                                ? 0x20U
                                                : ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                          | (((0U == 
                                               (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                   << 6U)))
                                               ? 0ULL
                                               : ((QData)((IData)(
                                                                  __Vtemp_h8d780f69__0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x1ffU 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                        << 6U))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                             | ((QData)((IData)(
                                                                __Vtemp_h8d780f69__0[
                                                                (0xeU 
                                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                    << 1U))])) 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U)))))) 
                                 << 1U) | (1U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_7_corrupt) 
                                                   << 7U) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_6_corrupt) 
                                                      << 6U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_5_corrupt) 
                                                         << 5U) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_4_corrupt) 
                                                            << 4U) 
                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_3_corrupt) 
                                                               << 3U) 
                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_2_corrupt) 
                                                                  << 2U) 
                                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_1_corrupt) 
                                                                     << 1U) 
                                                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_0_corrupt)))))))) 
                                                 >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index))));
    __Vtemp_ha2e78d82__0[1U] = (((IData)((((QData)((IData)(
                                                           __Vtemp_h8d780f69__0[
                                                           (((IData)(0x3fU) 
                                                             + 
                                                             (0x1ffU 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                 << 6U))) 
                                                            >> 5U)])) 
                                           << ((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U)))
                                                ? 0x20U
                                                : ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                          | (((0U == 
                                               (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                   << 6U)))
                                               ? 0ULL
                                               : ((QData)((IData)(
                                                                  __Vtemp_h8d780f69__0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x1ffU 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                        << 6U))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                             | ((QData)((IData)(
                                                                __Vtemp_h8d780f69__0[
                                                                (0xeU 
                                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                    << 1U))])) 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U)))))) 
                                 >> 0x1fU) | ((IData)(
                                                      ((((QData)((IData)(
                                                                         __Vtemp_h8d780f69__0[
                                                                         (((IData)(0x3fU) 
                                                                           + 
                                                                           (0x1ffU 
                                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                               << 6U))) 
                                                                          >> 5U)])) 
                                                         << 
                                                         ((0U 
                                                           == 
                                                           (0x1fU 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                               << 6U)))
                                                           ? 0x20U
                                                           : 
                                                          ((IData)(0x40U) 
                                                           - 
                                                           (0x1fU 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                               << 6U))))) 
                                                        | (((0U 
                                                             == 
                                                             (0x1fU 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                 << 6U)))
                                                             ? 0ULL
                                                             : 
                                                            ((QData)((IData)(
                                                                             __Vtemp_h8d780f69__0[
                                                                             (((IData)(0x1fU) 
                                                                               + 
                                                                               (0x1ffU 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                                << 6U))) 
                                                                              >> 5U)])) 
                                                             << 
                                                             ((IData)(0x20U) 
                                                              - 
                                                              (0x1fU 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                  << 6U))))) 
                                                           | ((QData)((IData)(
                                                                              __Vtemp_h8d780f69__0[
                                                                              (0xeU 
                                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                                << 1U))])) 
                                                              >> 
                                                              (0x1fU 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                  << 6U))))) 
                                                       >> 0x20U)) 
                                              << 1U));
    __Vtemp_ha2e78d82__0[2U] = ((IData)(((((QData)((IData)(
                                                           __Vtemp_h8d780f69__0[
                                                           (((IData)(0x3fU) 
                                                             + 
                                                             (0x1ffU 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                 << 6U))) 
                                                            >> 5U)])) 
                                           << ((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U)))
                                                ? 0x20U
                                                : ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                          | (((0U == 
                                               (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                   << 6U)))
                                               ? 0ULL
                                               : ((QData)((IData)(
                                                                  __Vtemp_h8d780f69__0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x1ffU 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                        << 6U))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                             | ((QData)((IData)(
                                                                __Vtemp_h8d780f69__0[
                                                                (0xeU 
                                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                    << 1U))])) 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U))))) 
                                         >> 0x20U)) 
                                >> 0x1fU);
    __Vtemp_h029b9980__0[2U] = (((((0U == (0x1fU & 
                                           ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                            << 5U)))
                                    ? 0U : (__Vtemp_h775da16e__0[
                                            (((IData)(0x1fU) 
                                              + (0xffU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 5U))) 
                                             >> 5U)] 
                                            << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                      << 5U))))) 
                                  | (__Vtemp_h775da16e__0[
                                     (7U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index))] 
                                     >> (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                  << 5U)))) 
                                 << 9U) | ((0x1feU 
                                            & ((IData)(
                                                       ((((QData)((IData)(
                                                                          (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_7_mask) 
                                                                            << 0x18U) 
                                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_6_mask) 
                                                                               << 0x10U) 
                                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_5_mask) 
                                                                                << 8U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_4_mask)))))) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_3_mask) 
                                                                             << 0x18U) 
                                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_2_mask) 
                                                                                << 0x10U) 
                                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_1_mask) 
                                                                                << 8U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_0_mask))))))) 
                                                        >> 
                                                        (0x3fU 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                            << 3U)))) 
                                               << 1U)) 
                                           | __Vtemp_ha2e78d82__0[2U]));
    __Vtemp_hafc775a1__0[3U] = ((0x600U & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_7_source) 
                                              << 0xeU) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_6_source) 
                                                 << 0xcU) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_5_source) 
                                                    << 0xaU) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_4_source) 
                                                       << 8U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_3_source) 
                                                          << 6U) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_2_source) 
                                                             << 4U) 
                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_1_source) 
                                                                << 2U) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_0_source)))))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                   << 1U))) 
                                           << 9U)) 
                                | ((((0U == (0x1fU 
                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                << 5U)))
                                      ? 0U : (__Vtemp_h775da16e__0[
                                              (((IData)(0x1fU) 
                                                + (0xffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                      << 5U))) 
                                               >> 5U)] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                      << 5U))))) 
                                    | (__Vtemp_h775da16e__0[
                                       (7U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index))] 
                                       >> (0x1fU & 
                                           ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                            << 5U)))) 
                                   >> 0x17U));
    __Vtemp_h4f0c815b__0[3U] = ((((0x17U >= (0x1fU 
                                             & ((IData)(3U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index))))
                                   ? (7U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_7_param) 
                                              << 0x15U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_6_param) 
                                                 << 0x12U) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_5_param) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_4_param) 
                                                       << 0xcU) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_3_param) 
                                                          << 9U) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_2_param) 
                                                             << 6U) 
                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_1_param) 
                                                                << 3U) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_0_param)))))))) 
                                            >> (0x1fU 
                                                & ((IData)(3U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index)))))
                                   : 0U) << 0xfU) | 
                                ((0x7800U & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_7_size) 
                                                << 0x1cU) 
                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_6_size) 
                                                   << 0x18U) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_5_size) 
                                                      << 0x14U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_4_size) 
                                                         << 0x10U) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_3_size) 
                                                            << 0xcU) 
                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_2_size) 
                                                               << 8U) 
                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_1_size) 
                                                                  << 4U) 
                                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_0_size)))))))) 
                                              >> (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                     << 2U))) 
                                             << 0xbU)) 
                                 | __Vtemp_hafc775a1__0[3U]));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[0U] 
        = __Vtemp_ha2e78d82__0[0U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[1U] 
        = __Vtemp_ha2e78d82__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[2U] 
        = __Vtemp_h029b9980__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[3U] 
        = ((((0x17U >= (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index))))
              ? (7U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_7_opcode) 
                         << 0x15U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_6_opcode) 
                                       << 0x12U) | 
                                      (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_5_opcode) 
                                        << 0xfU) | 
                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_4_opcode) 
                                         << 0xcU) | 
                                        (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_3_opcode) 
                                          << 9U) | 
                                         (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_2_opcode) 
                                           << 6U) | 
                                          (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_1_opcode) 
                                            << 3U) 
                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__mem_0_opcode)))))))) 
                       >> (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__index)))))
              : 0U) << 0x12U) | __Vtemp_h4f0c815b__0[3U]);
}

VL_INLINE_OPT void VTestHarness___024root___multiclk__TOP__5(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___multiclk__TOP__5\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_hddf6e07e__0;
    VlWide<16>/*511:0*/ __Vtemp_h944ba12b__0;
    VlWide<3>/*95:0*/ __Vtemp_h2cf35692__0;
    VlWide<4>/*127:0*/ __Vtemp_hbd34175b__0;
    VlWide<4>/*127:0*/ __Vtemp_h4d77335a__0;
    // Body
    __Vtemp_hddf6e07e__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_0_address;
    __Vtemp_hddf6e07e__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_1_address;
    __Vtemp_hddf6e07e__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_2_address;
    __Vtemp_hddf6e07e__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_3_address;
    __Vtemp_hddf6e07e__0[4U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_4_address;
    __Vtemp_hddf6e07e__0[5U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_5_address;
    __Vtemp_hddf6e07e__0[6U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_7_address)) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_6_address))));
    __Vtemp_hddf6e07e__0[7U] = (IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_7_address)) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_6_address))) 
                                        >> 0x20U));
    __Vtemp_h944ba12b__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_0_data);
    __Vtemp_h944ba12b__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_0_data 
                                        >> 0x20U));
    __Vtemp_h944ba12b__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_1_data);
    __Vtemp_h944ba12b__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_1_data 
                                        >> 0x20U));
    __Vtemp_h944ba12b__0[4U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_2_data);
    __Vtemp_h944ba12b__0[5U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_2_data 
                                        >> 0x20U));
    __Vtemp_h944ba12b__0[6U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_3_data);
    __Vtemp_h944ba12b__0[7U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_3_data 
                                        >> 0x20U));
    __Vtemp_h944ba12b__0[8U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_4_data);
    __Vtemp_h944ba12b__0[9U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_4_data 
                                        >> 0x20U));
    __Vtemp_h944ba12b__0[0xaU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_5_data);
    __Vtemp_h944ba12b__0[0xbU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_5_data 
                                          >> 0x20U));
    __Vtemp_h944ba12b__0[0xcU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_6_data);
    __Vtemp_h944ba12b__0[0xdU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_6_data 
                                          >> 0x20U));
    __Vtemp_h944ba12b__0[0xeU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_7_data);
    __Vtemp_h944ba12b__0[0xfU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_7_data 
                                          >> 0x20U));
    __Vtemp_h2cf35692__0[0U] = (IData)((((QData)((IData)(
                                                         __Vtemp_h944ba12b__0[
                                                         (((IData)(0x3fU) 
                                                           + 
                                                           (0x1ffU 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                               << 6U))) 
                                                          >> 5U)])) 
                                         << ((0U == 
                                              (0x1fU 
                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                  << 6U)))
                                              ? 0x20U
                                              : ((IData)(0x40U) 
                                                 - 
                                                 (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                     << 6U))))) 
                                        | (((0U == 
                                             (0x1fU 
                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                 << 6U)))
                                             ? 0ULL
                                             : ((QData)((IData)(
                                                                __Vtemp_h944ba12b__0[
                                                                (((IData)(0x1fU) 
                                                                  + 
                                                                  (0x1ffU 
                                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                                      << 6U))) 
                                                                 >> 5U)])) 
                                                << 
                                                ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                     << 6U))))) 
                                           | ((QData)((IData)(
                                                              __Vtemp_h944ba12b__0[
                                                              (0xeU 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                                  << 1U))])) 
                                              >> (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                     << 6U))))));
    __Vtemp_h2cf35692__0[1U] = (IData)(((((QData)((IData)(
                                                          __Vtemp_h944ba12b__0[
                                                          (((IData)(0x3fU) 
                                                            + 
                                                            (0x1ffU 
                                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                                << 6U))) 
                                                           >> 5U)])) 
                                          << ((0U == 
                                               (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                   << 6U)))
                                               ? 0x20U
                                               : ((IData)(0x40U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                      << 6U))))) 
                                         | (((0U == 
                                              (0x1fU 
                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                  << 6U)))
                                              ? 0ULL
                                              : ((QData)((IData)(
                                                                 __Vtemp_h944ba12b__0[
                                                                 (((IData)(0x1fU) 
                                                                   + 
                                                                   (0x1ffU 
                                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                                       << 6U))) 
                                                                  >> 5U)])) 
                                                 << 
                                                 ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                      << 6U))))) 
                                            | ((QData)((IData)(
                                                               __Vtemp_h944ba12b__0[
                                                               (0xeU 
                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                                   << 1U))])) 
                                               >> (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                      << 6U))))) 
                                        >> 0x20U));
    __Vtemp_hbd34175b__0[3U] = ((6U & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_7_source) 
                                          << 0xeU) 
                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_6_source) 
                                             << 0xcU) 
                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_5_source) 
                                                << 0xaU) 
                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_4_source) 
                                                   << 8U) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_3_source) 
                                                      << 6U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_2_source) 
                                                         << 4U) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_1_source) 
                                                            << 2U) 
                                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_0_source)))))))) 
                                        >> (0xfU & 
                                            ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                             << 1U))) 
                                       << 1U)) | ((
                                                   ((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                         << 5U)))
                                                     ? 0U
                                                     : 
                                                    (__Vtemp_hddf6e07e__0[
                                                     (((IData)(0x1fU) 
                                                       + 
                                                       (0xffU 
                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                           << 5U))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                          << 5U))))) 
                                                   | (__Vtemp_hddf6e07e__0[
                                                      (7U 
                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                          << 5U)))) 
                                                  >> 0x1fU));
    __Vtemp_h4d77335a__0[3U] = ((((0x17U >= (0x1fU 
                                             & ((IData)(3U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index))))
                                   ? (7U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_7_param) 
                                              << 0x15U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_6_param) 
                                                 << 0x12U) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_5_param) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_4_param) 
                                                       << 0xcU) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_3_param) 
                                                          << 9U) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_2_param) 
                                                             << 6U) 
                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_1_param) 
                                                                << 3U) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_0_param)))))))) 
                                            >> (0x1fU 
                                                & ((IData)(3U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index)))))
                                   : 0U) << 7U) | (
                                                   (0x78U 
                                                    & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_7_size) 
                                                          << 0x1cU) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_6_size) 
                                                             << 0x18U) 
                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_5_size) 
                                                                << 0x14U) 
                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_4_size) 
                                                                   << 0x10U) 
                                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_3_size) 
                                                                      << 0xcU) 
                                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_2_size) 
                                                                         << 8U) 
                                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_1_size) 
                                                                            << 4U) 
                                                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_0_size)))))))) 
                                                        >> 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                            << 2U))) 
                                                       << 3U)) 
                                                   | __Vtemp_hbd34175b__0[3U]));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[0U] 
        = ((__Vtemp_h2cf35692__0[0U] << 1U) | (1U & 
                                               ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_7_corrupt) 
                                                  << 7U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_6_corrupt) 
                                                     << 6U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_5_corrupt) 
                                                        << 5U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_4_corrupt) 
                                                           << 4U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_3_corrupt) 
                                                              << 3U) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_2_corrupt) 
                                                                 << 2U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_1_corrupt) 
                                                                    << 1U) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_0_corrupt)))))))) 
                                                >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[1U] 
        = ((__Vtemp_h2cf35692__0[0U] >> 0x1fU) | (__Vtemp_h2cf35692__0[1U] 
                                                  << 1U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[2U] 
        = ((__Vtemp_h2cf35692__0[1U] >> 0x1fU) | ((
                                                   ((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                         << 5U)))
                                                     ? 0U
                                                     : 
                                                    (__Vtemp_hddf6e07e__0[
                                                     (((IData)(0x1fU) 
                                                       + 
                                                       (0xffU 
                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                           << 5U))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                          << 5U))))) 
                                                   | (__Vtemp_hddf6e07e__0[
                                                      (7U 
                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                          << 5U)))) 
                                                  << 1U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[3U] 
        = ((((0x17U >= (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index))))
              ? (7U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_7_opcode) 
                         << 0x15U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_6_opcode) 
                                       << 0x12U) | 
                                      (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_5_opcode) 
                                        << 0xfU) | 
                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_4_opcode) 
                                         << 0xcU) | 
                                        (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_3_opcode) 
                                          << 9U) | 
                                         (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_2_opcode) 
                                           << 6U) | 
                                          (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_1_opcode) 
                                            << 3U) 
                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__mem_0_opcode)))))))) 
                       >> (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__index)))))
              : 0U) << 0xaU) | __Vtemp_h4d77335a__0[3U]);
}

VL_INLINE_OPT void VTestHarness___024root___multiclk__TOP__6(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___multiclk__TOP__6\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_h510d13ec__0;
    VlWide<16>/*511:0*/ __Vtemp_h5061070c__0;
    VlWide<3>/*95:0*/ __Vtemp_hd0d6c2ba__0;
    VlWide<4>/*127:0*/ __Vtemp_h16cab1a0__0;
    VlWide<4>/*127:0*/ __Vtemp_hf0843f9c__0;
    VlWide<4>/*127:0*/ __Vtemp_h9599c550__0;
    // Body
    __Vtemp_h510d13ec__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_0_address;
    __Vtemp_h510d13ec__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_1_address;
    __Vtemp_h510d13ec__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_2_address;
    __Vtemp_h510d13ec__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_3_address;
    __Vtemp_h510d13ec__0[4U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_4_address;
    __Vtemp_h510d13ec__0[5U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_5_address;
    __Vtemp_h510d13ec__0[6U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_7_address)) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_6_address))));
    __Vtemp_h510d13ec__0[7U] = (IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_7_address)) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_6_address))) 
                                        >> 0x20U));
    __Vtemp_h5061070c__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_0_data);
    __Vtemp_h5061070c__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_0_data 
                                        >> 0x20U));
    __Vtemp_h5061070c__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_1_data);
    __Vtemp_h5061070c__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_1_data 
                                        >> 0x20U));
    __Vtemp_h5061070c__0[4U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_2_data);
    __Vtemp_h5061070c__0[5U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_2_data 
                                        >> 0x20U));
    __Vtemp_h5061070c__0[6U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_3_data);
    __Vtemp_h5061070c__0[7U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_3_data 
                                        >> 0x20U));
    __Vtemp_h5061070c__0[8U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_4_data);
    __Vtemp_h5061070c__0[9U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_4_data 
                                        >> 0x20U));
    __Vtemp_h5061070c__0[0xaU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_5_data);
    __Vtemp_h5061070c__0[0xbU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_5_data 
                                          >> 0x20U));
    __Vtemp_h5061070c__0[0xcU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_6_data);
    __Vtemp_h5061070c__0[0xdU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_6_data 
                                          >> 0x20U));
    __Vtemp_h5061070c__0[0xeU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_7_data);
    __Vtemp_h5061070c__0[0xfU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_7_data 
                                          >> 0x20U));
    __Vtemp_hd0d6c2ba__0[0U] = (((IData)((((QData)((IData)(
                                                           __Vtemp_h5061070c__0[
                                                           (((IData)(0x3fU) 
                                                             + 
                                                             (0x1ffU 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                 << 6U))) 
                                                            >> 5U)])) 
                                           << ((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U)))
                                                ? 0x20U
                                                : ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                          | (((0U == 
                                               (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                   << 6U)))
                                               ? 0ULL
                                               : ((QData)((IData)(
                                                                  __Vtemp_h5061070c__0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x1ffU 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                        << 6U))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                             | ((QData)((IData)(
                                                                __Vtemp_h5061070c__0[
                                                                (0xeU 
                                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                    << 1U))])) 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U)))))) 
                                 << 1U) | (1U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_7_corrupt) 
                                                   << 7U) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_6_corrupt) 
                                                      << 6U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_5_corrupt) 
                                                         << 5U) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_4_corrupt) 
                                                            << 4U) 
                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_3_corrupt) 
                                                               << 3U) 
                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_2_corrupt) 
                                                                  << 2U) 
                                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_1_corrupt) 
                                                                     << 1U) 
                                                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_0_corrupt)))))))) 
                                                 >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index))));
    __Vtemp_hd0d6c2ba__0[1U] = (((IData)((((QData)((IData)(
                                                           __Vtemp_h5061070c__0[
                                                           (((IData)(0x3fU) 
                                                             + 
                                                             (0x1ffU 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                 << 6U))) 
                                                            >> 5U)])) 
                                           << ((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U)))
                                                ? 0x20U
                                                : ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                          | (((0U == 
                                               (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                   << 6U)))
                                               ? 0ULL
                                               : ((QData)((IData)(
                                                                  __Vtemp_h5061070c__0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x1ffU 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                        << 6U))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                             | ((QData)((IData)(
                                                                __Vtemp_h5061070c__0[
                                                                (0xeU 
                                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                    << 1U))])) 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U)))))) 
                                 >> 0x1fU) | ((IData)(
                                                      ((((QData)((IData)(
                                                                         __Vtemp_h5061070c__0[
                                                                         (((IData)(0x3fU) 
                                                                           + 
                                                                           (0x1ffU 
                                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                               << 6U))) 
                                                                          >> 5U)])) 
                                                         << 
                                                         ((0U 
                                                           == 
                                                           (0x1fU 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                               << 6U)))
                                                           ? 0x20U
                                                           : 
                                                          ((IData)(0x40U) 
                                                           - 
                                                           (0x1fU 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                               << 6U))))) 
                                                        | (((0U 
                                                             == 
                                                             (0x1fU 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                 << 6U)))
                                                             ? 0ULL
                                                             : 
                                                            ((QData)((IData)(
                                                                             __Vtemp_h5061070c__0[
                                                                             (((IData)(0x1fU) 
                                                                               + 
                                                                               (0x1ffU 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                                << 6U))) 
                                                                              >> 5U)])) 
                                                             << 
                                                             ((IData)(0x20U) 
                                                              - 
                                                              (0x1fU 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                  << 6U))))) 
                                                           | ((QData)((IData)(
                                                                              __Vtemp_h5061070c__0[
                                                                              (0xeU 
                                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                                << 1U))])) 
                                                              >> 
                                                              (0x1fU 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                  << 6U))))) 
                                                       >> 0x20U)) 
                                              << 1U));
    __Vtemp_hd0d6c2ba__0[2U] = ((IData)(((((QData)((IData)(
                                                           __Vtemp_h5061070c__0[
                                                           (((IData)(0x3fU) 
                                                             + 
                                                             (0x1ffU 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                 << 6U))) 
                                                            >> 5U)])) 
                                           << ((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U)))
                                                ? 0x20U
                                                : ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                          | (((0U == 
                                               (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                   << 6U)))
                                               ? 0ULL
                                               : ((QData)((IData)(
                                                                  __Vtemp_h5061070c__0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x1ffU 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                        << 6U))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                             | ((QData)((IData)(
                                                                __Vtemp_h5061070c__0[
                                                                (0xeU 
                                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                    << 1U))])) 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U))))) 
                                         >> 0x20U)) 
                                >> 0x1fU);
    __Vtemp_h16cab1a0__0[2U] = (((((0U == (0x1fU & 
                                           ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                            << 5U)))
                                    ? 0U : (__Vtemp_h510d13ec__0[
                                            (((IData)(0x1fU) 
                                              + (0xffU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 5U))) 
                                             >> 5U)] 
                                            << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                      << 5U))))) 
                                  | (__Vtemp_h510d13ec__0[
                                     (7U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index))] 
                                     >> (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                  << 5U)))) 
                                 << 9U) | ((0x1feU 
                                            & ((IData)(
                                                       ((((QData)((IData)(
                                                                          (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_7_mask) 
                                                                            << 0x18U) 
                                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_6_mask) 
                                                                               << 0x10U) 
                                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_5_mask) 
                                                                                << 8U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_4_mask)))))) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_3_mask) 
                                                                             << 0x18U) 
                                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_2_mask) 
                                                                                << 0x10U) 
                                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_1_mask) 
                                                                                << 8U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_0_mask))))))) 
                                                        >> 
                                                        (0x3fU 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                            << 3U)))) 
                                               << 1U)) 
                                           | __Vtemp_hd0d6c2ba__0[2U]));
    __Vtemp_hf0843f9c__0[3U] = ((0x600U & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_7_source) 
                                              << 0xeU) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_6_source) 
                                                 << 0xcU) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_5_source) 
                                                    << 0xaU) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_4_source) 
                                                       << 8U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_3_source) 
                                                          << 6U) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_2_source) 
                                                             << 4U) 
                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_1_source) 
                                                                << 2U) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_0_source)))))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                   << 1U))) 
                                           << 9U)) 
                                | ((((0U == (0x1fU 
                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                << 5U)))
                                      ? 0U : (__Vtemp_h510d13ec__0[
                                              (((IData)(0x1fU) 
                                                + (0xffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                      << 5U))) 
                                               >> 5U)] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                      << 5U))))) 
                                    | (__Vtemp_h510d13ec__0[
                                       (7U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index))] 
                                       >> (0x1fU & 
                                           ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                            << 5U)))) 
                                   >> 0x17U));
    __Vtemp_h9599c550__0[3U] = ((((0x17U >= (0x1fU 
                                             & ((IData)(3U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index))))
                                   ? (7U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_7_param) 
                                              << 0x15U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_6_param) 
                                                 << 0x12U) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_5_param) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_4_param) 
                                                       << 0xcU) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_3_param) 
                                                          << 9U) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_2_param) 
                                                             << 6U) 
                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_1_param) 
                                                                << 3U) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_0_param)))))))) 
                                            >> (0x1fU 
                                                & ((IData)(3U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index)))))
                                   : 0U) << 0xfU) | 
                                ((0x7800U & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_7_size) 
                                                << 0x1cU) 
                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_6_size) 
                                                   << 0x18U) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_5_size) 
                                                      << 0x14U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_4_size) 
                                                         << 0x10U) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_3_size) 
                                                            << 0xcU) 
                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_2_size) 
                                                               << 8U) 
                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_1_size) 
                                                                  << 4U) 
                                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_0_size)))))))) 
                                              >> (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                     << 2U))) 
                                             << 0xbU)) 
                                 | __Vtemp_hf0843f9c__0[3U]));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[0U] 
        = __Vtemp_hd0d6c2ba__0[0U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[1U] 
        = __Vtemp_hd0d6c2ba__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[2U] 
        = __Vtemp_h16cab1a0__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[3U] 
        = ((((0x17U >= (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index))))
              ? (7U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_7_opcode) 
                         << 0x15U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_6_opcode) 
                                       << 0x12U) | 
                                      (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_5_opcode) 
                                        << 0xfU) | 
                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_4_opcode) 
                                         << 0xcU) | 
                                        (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_3_opcode) 
                                          << 9U) | 
                                         (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_2_opcode) 
                                           << 6U) | 
                                          (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_1_opcode) 
                                            << 3U) 
                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__mem_0_opcode)))))))) 
                       >> (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__index)))))
              : 0U) << 0x12U) | __Vtemp_h9599c550__0[3U]);
}

VL_INLINE_OPT void VTestHarness___024root___multiclk__TOP__7(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___multiclk__TOP__7\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_h05a08aad__0;
    VlWide<16>/*511:0*/ __Vtemp_h0d08c83a__0;
    VlWide<3>/*95:0*/ __Vtemp_h281393ba__0;
    VlWide<4>/*127:0*/ __Vtemp_hac89eef0__0;
    VlWide<4>/*127:0*/ __Vtemp_h726a4428__0;
    // Body
    __Vtemp_h05a08aad__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_0_address;
    __Vtemp_h05a08aad__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_1_address;
    __Vtemp_h05a08aad__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_2_address;
    __Vtemp_h05a08aad__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_3_address;
    __Vtemp_h05a08aad__0[4U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_4_address;
    __Vtemp_h05a08aad__0[5U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_5_address;
    __Vtemp_h05a08aad__0[6U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_7_address)) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_6_address))));
    __Vtemp_h05a08aad__0[7U] = (IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_7_address)) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_6_address))) 
                                        >> 0x20U));
    __Vtemp_h0d08c83a__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_0_data);
    __Vtemp_h0d08c83a__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_0_data 
                                        >> 0x20U));
    __Vtemp_h0d08c83a__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_1_data);
    __Vtemp_h0d08c83a__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_1_data 
                                        >> 0x20U));
    __Vtemp_h0d08c83a__0[4U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_2_data);
    __Vtemp_h0d08c83a__0[5U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_2_data 
                                        >> 0x20U));
    __Vtemp_h0d08c83a__0[6U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_3_data);
    __Vtemp_h0d08c83a__0[7U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_3_data 
                                        >> 0x20U));
    __Vtemp_h0d08c83a__0[8U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_4_data);
    __Vtemp_h0d08c83a__0[9U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_4_data 
                                        >> 0x20U));
    __Vtemp_h0d08c83a__0[0xaU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_5_data);
    __Vtemp_h0d08c83a__0[0xbU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_5_data 
                                          >> 0x20U));
    __Vtemp_h0d08c83a__0[0xcU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_6_data);
    __Vtemp_h0d08c83a__0[0xdU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_6_data 
                                          >> 0x20U));
    __Vtemp_h0d08c83a__0[0xeU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_7_data);
    __Vtemp_h0d08c83a__0[0xfU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_7_data 
                                          >> 0x20U));
    __Vtemp_h281393ba__0[0U] = (IData)((((QData)((IData)(
                                                         __Vtemp_h0d08c83a__0[
                                                         (((IData)(0x3fU) 
                                                           + 
                                                           (0x1ffU 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                               << 6U))) 
                                                          >> 5U)])) 
                                         << ((0U == 
                                              (0x1fU 
                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                  << 6U)))
                                              ? 0x20U
                                              : ((IData)(0x40U) 
                                                 - 
                                                 (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                     << 6U))))) 
                                        | (((0U == 
                                             (0x1fU 
                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                 << 6U)))
                                             ? 0ULL
                                             : ((QData)((IData)(
                                                                __Vtemp_h0d08c83a__0[
                                                                (((IData)(0x1fU) 
                                                                  + 
                                                                  (0x1ffU 
                                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                                      << 6U))) 
                                                                 >> 5U)])) 
                                                << 
                                                ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                     << 6U))))) 
                                           | ((QData)((IData)(
                                                              __Vtemp_h0d08c83a__0[
                                                              (0xeU 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                                  << 1U))])) 
                                              >> (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                     << 6U))))));
    __Vtemp_h281393ba__0[1U] = (IData)(((((QData)((IData)(
                                                          __Vtemp_h0d08c83a__0[
                                                          (((IData)(0x3fU) 
                                                            + 
                                                            (0x1ffU 
                                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                                << 6U))) 
                                                           >> 5U)])) 
                                          << ((0U == 
                                               (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                   << 6U)))
                                               ? 0x20U
                                               : ((IData)(0x40U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                      << 6U))))) 
                                         | (((0U == 
                                              (0x1fU 
                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                  << 6U)))
                                              ? 0ULL
                                              : ((QData)((IData)(
                                                                 __Vtemp_h0d08c83a__0[
                                                                 (((IData)(0x1fU) 
                                                                   + 
                                                                   (0x1ffU 
                                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                                       << 6U))) 
                                                                  >> 5U)])) 
                                                 << 
                                                 ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                      << 6U))))) 
                                            | ((QData)((IData)(
                                                               __Vtemp_h0d08c83a__0[
                                                               (0xeU 
                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                                   << 1U))])) 
                                               >> (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                      << 6U))))) 
                                        >> 0x20U));
    __Vtemp_hac89eef0__0[3U] = ((6U & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_7_source) 
                                          << 0xeU) 
                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_6_source) 
                                             << 0xcU) 
                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_5_source) 
                                                << 0xaU) 
                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_4_source) 
                                                   << 8U) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_3_source) 
                                                      << 6U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_2_source) 
                                                         << 4U) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_1_source) 
                                                            << 2U) 
                                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_0_source)))))))) 
                                        >> (0xfU & 
                                            ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                             << 1U))) 
                                       << 1U)) | ((
                                                   ((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                         << 5U)))
                                                     ? 0U
                                                     : 
                                                    (__Vtemp_h05a08aad__0[
                                                     (((IData)(0x1fU) 
                                                       + 
                                                       (0xffU 
                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                           << 5U))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                          << 5U))))) 
                                                   | (__Vtemp_h05a08aad__0[
                                                      (7U 
                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                          << 5U)))) 
                                                  >> 0x1fU));
    __Vtemp_h726a4428__0[3U] = ((((0x17U >= (0x1fU 
                                             & ((IData)(3U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index))))
                                   ? (7U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_7_param) 
                                              << 0x15U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_6_param) 
                                                 << 0x12U) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_5_param) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_4_param) 
                                                       << 0xcU) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_3_param) 
                                                          << 9U) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_2_param) 
                                                             << 6U) 
                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_1_param) 
                                                                << 3U) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_0_param)))))))) 
                                            >> (0x1fU 
                                                & ((IData)(3U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index)))))
                                   : 0U) << 7U) | (
                                                   (0x78U 
                                                    & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_7_size) 
                                                          << 0x1cU) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_6_size) 
                                                             << 0x18U) 
                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_5_size) 
                                                                << 0x14U) 
                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_4_size) 
                                                                   << 0x10U) 
                                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_3_size) 
                                                                      << 0xcU) 
                                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_2_size) 
                                                                         << 8U) 
                                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_1_size) 
                                                                            << 4U) 
                                                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_0_size)))))))) 
                                                        >> 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                            << 2U))) 
                                                       << 3U)) 
                                                   | __Vtemp_hac89eef0__0[3U]));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[0U] 
        = ((__Vtemp_h281393ba__0[0U] << 1U) | (1U & 
                                               ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_7_corrupt) 
                                                  << 7U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_6_corrupt) 
                                                     << 6U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_5_corrupt) 
                                                        << 5U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_4_corrupt) 
                                                           << 4U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_3_corrupt) 
                                                              << 3U) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_2_corrupt) 
                                                                 << 2U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_1_corrupt) 
                                                                    << 1U) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_0_corrupt)))))))) 
                                                >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[1U] 
        = ((__Vtemp_h281393ba__0[0U] >> 0x1fU) | (__Vtemp_h281393ba__0[1U] 
                                                  << 1U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[2U] 
        = ((__Vtemp_h281393ba__0[1U] >> 0x1fU) | ((
                                                   ((0U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                         << 5U)))
                                                     ? 0U
                                                     : 
                                                    (__Vtemp_h05a08aad__0[
                                                     (((IData)(0x1fU) 
                                                       + 
                                                       (0xffU 
                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                           << 5U))) 
                                                      >> 5U)] 
                                                     << 
                                                     ((IData)(0x20U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                          << 5U))))) 
                                                   | (__Vtemp_h05a08aad__0[
                                                      (7U 
                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index))] 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index) 
                                                          << 5U)))) 
                                                  << 1U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[3U] 
        = ((((0x17U >= (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index))))
              ? (7U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_7_opcode) 
                         << 0x15U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_6_opcode) 
                                       << 0x12U) | 
                                      (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_5_opcode) 
                                        << 0xfU) | 
                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_4_opcode) 
                                         << 0xcU) | 
                                        (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_3_opcode) 
                                          << 9U) | 
                                         (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_2_opcode) 
                                           << 6U) | 
                                          (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_1_opcode) 
                                            << 3U) 
                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_0_opcode)))))))) 
                       >> (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__index)))))
              : 0U) << 0xaU) | __Vtemp_h726a4428__0[3U]);
}

VL_INLINE_OPT void VTestHarness___024root___multiclk__TOP__8(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___multiclk__TOP__8\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_h27b03127__0;
    VlWide<16>/*511:0*/ __Vtemp_h7434b57a__0;
    VlWide<3>/*95:0*/ __Vtemp_h214d5ae0__0;
    VlWide<4>/*127:0*/ __Vtemp_h19a2ac08__0;
    VlWide<4>/*127:0*/ __Vtemp_hc046a2bd__0;
    VlWide<4>/*127:0*/ __Vtemp_h5acaa38d__0;
    // Body
    __Vtemp_h27b03127__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_0_address;
    __Vtemp_h27b03127__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_1_address;
    __Vtemp_h27b03127__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_2_address;
    __Vtemp_h27b03127__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_3_address;
    __Vtemp_h27b03127__0[4U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_4_address;
    __Vtemp_h27b03127__0[5U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_5_address;
    __Vtemp_h27b03127__0[6U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_7_address)) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_6_address))));
    __Vtemp_h27b03127__0[7U] = (IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_7_address)) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_6_address))) 
                                        >> 0x20U));
    __Vtemp_h7434b57a__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_0_data);
    __Vtemp_h7434b57a__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_0_data 
                                        >> 0x20U));
    __Vtemp_h7434b57a__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_1_data);
    __Vtemp_h7434b57a__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_1_data 
                                        >> 0x20U));
    __Vtemp_h7434b57a__0[4U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_2_data);
    __Vtemp_h7434b57a__0[5U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_2_data 
                                        >> 0x20U));
    __Vtemp_h7434b57a__0[6U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_3_data);
    __Vtemp_h7434b57a__0[7U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_3_data 
                                        >> 0x20U));
    __Vtemp_h7434b57a__0[8U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_4_data);
    __Vtemp_h7434b57a__0[9U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_4_data 
                                        >> 0x20U));
    __Vtemp_h7434b57a__0[0xaU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_5_data);
    __Vtemp_h7434b57a__0[0xbU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_5_data 
                                          >> 0x20U));
    __Vtemp_h7434b57a__0[0xcU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_6_data);
    __Vtemp_h7434b57a__0[0xdU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_6_data 
                                          >> 0x20U));
    __Vtemp_h7434b57a__0[0xeU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_7_data);
    __Vtemp_h7434b57a__0[0xfU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_7_data 
                                          >> 0x20U));
    __Vtemp_h214d5ae0__0[0U] = (((IData)((((QData)((IData)(
                                                           __Vtemp_h7434b57a__0[
                                                           (((IData)(0x3fU) 
                                                             + 
                                                             (0x1ffU 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                 << 6U))) 
                                                            >> 5U)])) 
                                           << ((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U)))
                                                ? 0x20U
                                                : ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                          | (((0U == 
                                               (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                   << 6U)))
                                               ? 0ULL
                                               : ((QData)((IData)(
                                                                  __Vtemp_h7434b57a__0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x1ffU 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                        << 6U))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                             | ((QData)((IData)(
                                                                __Vtemp_h7434b57a__0[
                                                                (0xeU 
                                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                    << 1U))])) 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U)))))) 
                                 << 1U) | (1U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_7_corrupt) 
                                                   << 7U) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_6_corrupt) 
                                                      << 6U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_5_corrupt) 
                                                         << 5U) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_4_corrupt) 
                                                            << 4U) 
                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_3_corrupt) 
                                                               << 3U) 
                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_2_corrupt) 
                                                                  << 2U) 
                                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_1_corrupt) 
                                                                     << 1U) 
                                                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_0_corrupt)))))))) 
                                                 >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index))));
    __Vtemp_h214d5ae0__0[1U] = (((IData)((((QData)((IData)(
                                                           __Vtemp_h7434b57a__0[
                                                           (((IData)(0x3fU) 
                                                             + 
                                                             (0x1ffU 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                 << 6U))) 
                                                            >> 5U)])) 
                                           << ((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U)))
                                                ? 0x20U
                                                : ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                          | (((0U == 
                                               (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                   << 6U)))
                                               ? 0ULL
                                               : ((QData)((IData)(
                                                                  __Vtemp_h7434b57a__0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x1ffU 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                        << 6U))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                             | ((QData)((IData)(
                                                                __Vtemp_h7434b57a__0[
                                                                (0xeU 
                                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                    << 1U))])) 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U)))))) 
                                 >> 0x1fU) | ((IData)(
                                                      ((((QData)((IData)(
                                                                         __Vtemp_h7434b57a__0[
                                                                         (((IData)(0x3fU) 
                                                                           + 
                                                                           (0x1ffU 
                                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                               << 6U))) 
                                                                          >> 5U)])) 
                                                         << 
                                                         ((0U 
                                                           == 
                                                           (0x1fU 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                               << 6U)))
                                                           ? 0x20U
                                                           : 
                                                          ((IData)(0x40U) 
                                                           - 
                                                           (0x1fU 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                               << 6U))))) 
                                                        | (((0U 
                                                             == 
                                                             (0x1fU 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                 << 6U)))
                                                             ? 0ULL
                                                             : 
                                                            ((QData)((IData)(
                                                                             __Vtemp_h7434b57a__0[
                                                                             (((IData)(0x1fU) 
                                                                               + 
                                                                               (0x1ffU 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                                << 6U))) 
                                                                              >> 5U)])) 
                                                             << 
                                                             ((IData)(0x20U) 
                                                              - 
                                                              (0x1fU 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                  << 6U))))) 
                                                           | ((QData)((IData)(
                                                                              __Vtemp_h7434b57a__0[
                                                                              (0xeU 
                                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                                << 1U))])) 
                                                              >> 
                                                              (0x1fU 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                  << 6U))))) 
                                                       >> 0x20U)) 
                                              << 1U));
    __Vtemp_h214d5ae0__0[2U] = ((IData)(((((QData)((IData)(
                                                           __Vtemp_h7434b57a__0[
                                                           (((IData)(0x3fU) 
                                                             + 
                                                             (0x1ffU 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                 << 6U))) 
                                                            >> 5U)])) 
                                           << ((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U)))
                                                ? 0x20U
                                                : ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                          | (((0U == 
                                               (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                   << 6U)))
                                               ? 0ULL
                                               : ((QData)((IData)(
                                                                  __Vtemp_h7434b57a__0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x1ffU 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                        << 6U))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                       << 6U))))) 
                                             | ((QData)((IData)(
                                                                __Vtemp_h7434b57a__0[
                                                                (0xeU 
                                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                                    << 1U))])) 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 6U))))) 
                                         >> 0x20U)) 
                                >> 0x1fU);
    __Vtemp_h19a2ac08__0[2U] = (((((0U == (0x1fU & 
                                           ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                            << 5U)))
                                    ? 0U : (__Vtemp_h27b03127__0[
                                            (((IData)(0x1fU) 
                                              + (0xffU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                    << 5U))) 
                                             >> 5U)] 
                                            << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                      << 5U))))) 
                                  | (__Vtemp_h27b03127__0[
                                     (7U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index))] 
                                     >> (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                  << 5U)))) 
                                 << 9U) | ((0x1feU 
                                            & ((IData)(
                                                       ((((QData)((IData)(
                                                                          (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_7_mask) 
                                                                            << 0x18U) 
                                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_6_mask) 
                                                                               << 0x10U) 
                                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_5_mask) 
                                                                                << 8U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_4_mask)))))) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_3_mask) 
                                                                             << 0x18U) 
                                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_2_mask) 
                                                                                << 0x10U) 
                                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_1_mask) 
                                                                                << 8U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_0_mask))))))) 
                                                        >> 
                                                        (0x3fU 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                            << 3U)))) 
                                               << 1U)) 
                                           | __Vtemp_h214d5ae0__0[2U]));
    __Vtemp_hc046a2bd__0[3U] = ((0x600U & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_7_source) 
                                              << 0xeU) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_6_source) 
                                                 << 0xcU) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_5_source) 
                                                    << 0xaU) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_4_source) 
                                                       << 8U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_3_source) 
                                                          << 6U) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_2_source) 
                                                             << 4U) 
                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_1_source) 
                                                                << 2U) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_0_source)))))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                   << 1U))) 
                                           << 9U)) 
                                | ((((0U == (0x1fU 
                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                << 5U)))
                                      ? 0U : (__Vtemp_h27b03127__0[
                                              (((IData)(0x1fU) 
                                                + (0xffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                      << 5U))) 
                                               >> 5U)] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                      << 5U))))) 
                                    | (__Vtemp_h27b03127__0[
                                       (7U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index))] 
                                       >> (0x1fU & 
                                           ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                            << 5U)))) 
                                   >> 0x17U));
    __Vtemp_h5acaa38d__0[3U] = ((((0x17U >= (0x1fU 
                                             & ((IData)(3U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index))))
                                   ? (7U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_7_param) 
                                              << 0x15U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_6_param) 
                                                 << 0x12U) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_5_param) 
                                                    << 0xfU) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_4_param) 
                                                       << 0xcU) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_3_param) 
                                                          << 9U) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_2_param) 
                                                             << 6U) 
                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_1_param) 
                                                                << 3U) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_0_param)))))))) 
                                            >> (0x1fU 
                                                & ((IData)(3U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index)))))
                                   : 0U) << 0xfU) | 
                                ((0x7800U & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_7_size) 
                                                << 0x1cU) 
                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_6_size) 
                                                   << 0x18U) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_5_size) 
                                                      << 0x14U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_4_size) 
                                                         << 0x10U) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_3_size) 
                                                            << 0xcU) 
                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_2_size) 
                                                               << 8U) 
                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_1_size) 
                                                                  << 4U) 
                                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_0_size)))))))) 
                                              >> (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index) 
                                                     << 2U))) 
                                             << 0xbU)) 
                                 | __Vtemp_hc046a2bd__0[3U]));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[0U] 
        = __Vtemp_h214d5ae0__0[0U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[1U] 
        = __Vtemp_h214d5ae0__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[2U] 
        = __Vtemp_h19a2ac08__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[3U] 
        = ((((0x17U >= (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index))))
              ? (7U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_7_opcode) 
                         << 0x15U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_6_opcode) 
                                       << 0x12U) | 
                                      (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_5_opcode) 
                                        << 0xfU) | 
                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_4_opcode) 
                                         << 0xcU) | 
                                        (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_3_opcode) 
                                          << 9U) | 
                                         (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_2_opcode) 
                                           << 6U) | 
                                          (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_1_opcode) 
                                            << 3U) 
                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_0_opcode)))))))) 
                       >> (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__index)))))
              : 0U) << 0x12U) | __Vtemp_h5acaa38d__0[3U]);
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__23020(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__23020\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__23021(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__23021\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__23022(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__23022\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__23023(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__23023\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
}
