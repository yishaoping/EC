// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "VTestHarness__Syms.h"


extern const VlWide<8>/*255:0*/ VTestHarness__ConstPool__CONST_h4e4f723a_0;

void VTestHarness___024root__trace_chg_sub_8(VTestHarness___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root__trace_chg_sub_8\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 29350);
    VlWide<3>/*95:0*/ __Vtemp_h0abd8d3f__0;
    VlWide<3>/*95:0*/ __Vtemp_h1e2890c5__0;
    VlWide<5>/*159:0*/ __Vtemp_h10336803__0;
    VlWide<3>/*95:0*/ __Vtemp_h56c6a7bd__0;
    VlWide<3>/*95:0*/ __Vtemp_hc92888ee__0;
    VlWide<3>/*95:0*/ __Vtemp_hb2c720f9__9;
    VlWide<4>/*127:0*/ __Vtemp_h14e110c9__8;
    VlWide<3>/*95:0*/ __Vtemp_hcd24d8a3__0;
    VlWide<3>/*95:0*/ __Vtemp_h95b49b13__0;
    VlWide<4>/*127:0*/ __Vtemp_h353c8118__5;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__0;
    VlWide<4>/*127:0*/ __Vtemp_h5510ccc3__0;
    VlWide<4>/*127:0*/ __Vtemp_h0bf3af22__0;
    VlWide<3>/*95:0*/ __Vtemp_he55d0783__0;
    VlWide<3>/*95:0*/ __Vtemp_h50fe2c8b__0;
    VlWide<3>/*95:0*/ __Vtemp_hfbbb1fa2__0;
    VlWide<4>/*127:0*/ __Vtemp_hcffc7c87__0;
    VlWide<3>/*95:0*/ __Vtemp_h07fba5f3__0;
    VlWide<3>/*95:0*/ __Vtemp_haf83fa31__0;
    VlWide<4>/*127:0*/ __Vtemp_h6b530f7d__0;
    VlWide<3>/*95:0*/ __Vtemp_h6d4f267c__0;
    VlWide<3>/*95:0*/ __Vtemp_h5462a164__0;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x14U])) {
        bufp->chgBit(oldp+0,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__c_first_counter_1))));
        bufp->chgSData(oldp+1,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter_2),9);
        bufp->chgBit(oldp+2,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter_2))));
        bufp->chgIData(oldp+3,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__watchdog_1),32);
        bufp->chgCData(oldp+4,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__inflight_2),8);
        bufp->chgSData(oldp+5,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter_3),9);
        bufp->chgBit(oldp+6,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter_3))));
        bufp->chgBit(oldp+7,((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)))));
        bufp->chgBit(oldp+8,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+9,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+10,((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)))));
        bufp->chgBit(oldp+11,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+12,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+13,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+14,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+15,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+16,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+17,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+18,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+19,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_5) 
                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_5) 
                                      & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                  << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_5) 
                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_5) 
                                                 & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                             << 6U) 
                                            | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_4) 
                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_4) 
                                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                << 5U) 
                                               | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_4) 
                                                       & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                                   << 4U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_3) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_3) 
                                                          & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                      << 3U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_3) 
                                                             & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                                         << 2U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_2) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_2) 
                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                            << 1U) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_2) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_2) 
                                                                 & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))))))))))),8);
        bufp->chgBit(oldp+20,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_14));
        bufp->chgBit(oldp+21,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_15));
        bufp->chgBit(oldp+22,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_16));
        bufp->chgBit(oldp+23,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_16));
        bufp->chgBit(oldp+24,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_17));
        bufp->chgBit(oldp+25,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_17));
        bufp->chgBit(oldp+26,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_18));
        bufp->chgBit(oldp+27,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_18));
        bufp->chgBit(oldp+28,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_19));
        bufp->chgBit(oldp+29,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_19));
        bufp->chgCData(oldp+30,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_19) 
                                   << 7U) | (0x3fffff80U 
                                             & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_19) 
                                                 << 7U) 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 2U)))) 
                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_19) 
                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_19) 
                                         & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                               >> 9U)))) 
                                     << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_18) 
                                                 << 5U) 
                                                | (0xfffffe0U 
                                                   & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_18) 
                                                       << 5U) 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                         >> 4U)))) 
                                               | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_18) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_18) 
                                                       & (~ 
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                           >> 9U)))) 
                                                   << 4U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_17) 
                                                       << 3U) 
                                                      | (0x3fffff8U 
                                                         & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_17) 
                                                             << 3U) 
                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                               >> 6U)))) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_17) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_17) 
                                                             & (~ 
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                 >> 9U)))) 
                                                         << 2U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_16) 
                                                             << 1U) 
                                                            | (0xfffffeU 
                                                               & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_16) 
                                                                   << 1U) 
                                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                     >> 8U)))) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_16) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_16) 
                                                                 & (~ 
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                     >> 9U)))))))))))),8);
        bufp->chgCData(oldp+31,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT___same_cycle_resp_T_1)
                                  ? (3U & ((IData)(1U) 
                                           << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_source)))
                                  : 0U)),2);
        bufp->chgCData(oldp+32,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT___same_cycle_resp_T_3) 
                                  & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode))))
                                  ? (3U & ((IData)(1U) 
                                           << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_source)))
                                  : 0U)),2);
        bufp->chgSData(oldp+33,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter),9);
        bufp->chgCData(oldp+34,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__opcode_1),3);
        bufp->chgCData(oldp+35,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__param_1),2);
        bufp->chgCData(oldp+36,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__size_1),4);
        bufp->chgBit(oldp+37,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__source_1));
        bufp->chgCData(oldp+38,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__sink),3);
        bufp->chgBit(oldp+39,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__denied));
        bufp->chgBit(oldp+40,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__inflight));
        bufp->chgCData(oldp+41,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__inflight_opcodes),4);
        bufp->chgCData(oldp+42,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__inflight_sizes),8);
        bufp->chgSData(oldp+43,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter_1),9);
        bufp->chgBit(oldp+44,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter_1))));
        bufp->chgIData(oldp+45,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__watchdog),32);
        bufp->chgSData(oldp+46,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter_2),9);
        bufp->chgBit(oldp+47,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter_2))));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[0x14U] 
                     | vlSelf->__Vm_traceActivity[0x2aU]))) {
        bufp->chgBit(oldp+48,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__s_or_r) 
                                & (0x20U == (0x78U 
                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[4U]))) 
                               & (((7U != (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[4U])) 
                                   & (4U != (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[4U]))) 
                                  & (0U != (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[4U]))))));
        bufp->chgBit(oldp+49,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__s_or_r) 
                                & (0x2000U == (0x7800U 
                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[8U]))) 
                               & (((7U != (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[8U] 
                                                 >> 8U))) 
                                   & (4U != (7U & (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[8U] 
                                                   >> 8U)))) 
                                  & (0U != (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[8U] 
                                                  >> 8U)))))));
        bufp->chgBit(oldp+50,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__s_or_r) 
                               & (0x24U == (0x7fU & 
                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[4U])))));
        bufp->chgBit(oldp+51,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__s_or_r) 
                               & (0x2400U == (0x7f00U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[8U])))));
        bufp->chgBit(oldp+52,((((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_perf_acquire_counter)) 
                                | (0U == ((4U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))
                                           ? 0U : (0x1ffU 
                                                   & (~ 
                                                      (0xffffffU 
                                                       & (((IData)(0xfffU) 
                                                           << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)) 
                                                          >> 3U))))))) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_perf_acquire_T))));
        bufp->chgBit(oldp+53,((((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_perf_release_counter)) 
                                | (0U == ((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode))
                                           ? (0x1ffU 
                                              & (~ 
                                                 (((0x1aU 
                                                    >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_size))
                                                    ? 
                                                   (0x7ffffffU 
                                                    & ((IData)(0xfffU) 
                                                       << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_size)))
                                                    : 0U) 
                                                  >> 3U)))
                                           : 0U))) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___T_336))));
        bufp->chgBit(oldp+54,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_wb)) 
                                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode))))));
        bufp->chgBit(oldp+55,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_valid) 
                               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_wb)))));
        bufp->chgBit(oldp+56,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_valid) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_fence_i)) 
                                & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)))) 
                               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_requestor_2_s2_nack)))));
        bufp->chgBit(oldp+57,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_valid) 
                               & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_jal) 
                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_jalr)) 
                                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_branch)))));
        bufp->chgBit(oldp+58,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_valid) 
                                & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_29))) 
                               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_csr_stall_output)))));
        bufp->chgBit(oldp+59,((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_409) 
                                  & ((0x1fU >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1))
                                      ? ((0xfffffffeU 
                                          & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___r) 
                                         >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1))
                                      : 0U)) & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ll_wen) 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ll_waddr) 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1))))) 
                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_411) 
                                    & ((0x1fU >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2))
                                        ? ((0xfffffffeU 
                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___r) 
                                           >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2))
                                        : 0U)) & (~ 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ll_wen) 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ll_waddr) 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2)))))) 
                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_413) 
                                   & ((0x1fU >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rd))
                                       ? ((0xfffffffeU 
                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___r) 
                                          >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rd))
                                       : 0U)) & (~ 
                                                 ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ll_wen) 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ll_waddr) 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rd))))))));
        bufp->chgBit(oldp+60,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_wen) 
                               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_set_sboard)))));
        bufp->chgBit(oldp+61,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__if_RSU_packet) 
                               & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_index)))));
        bufp->chgBit(oldp+62,(((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_if_correct_process) 
                                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__io_if_check_privret_REG)) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__ic_counter_done)) 
                                 & ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__fsm_state)) 
                                    | (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__fsm_state)))) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_returned_to_special_address_valid))) 
                               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__excpt_mode)))));
        bufp->chgQData(oldp+63,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_valid_0)
                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_data_0
                                   : 0ULL) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_valid_1)
                                               ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_data_1
                                               : 0ULL))),64);
        bufp->chgBit(oldp+65,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen)) 
                               & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))));
        bufp->chgQData(oldp+66,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                  ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                      & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                      : 0ULL) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (0U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 0ULL))),64);
        bufp->chgQData(oldp+68,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                  ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                      & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                      : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                     [0x1eU]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (1U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0x1eU]))),64);
        bufp->chgQData(oldp+70,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_7)
                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rf_sp
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                      ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                          & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                          ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                          : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                         [0x1dU]) : 
                                     ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                        & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0x1dU])))),64);
        bufp->chgQData(oldp+72,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_7)
                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rf_gp
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                      ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                          & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                          ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                          : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                         [0x1cU]) : 
                                     ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                        & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                       & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0x1cU])))),64);
        bufp->chgQData(oldp+74,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                  ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                      & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                      : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                     [0x1bU]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (4U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0x1bU]))),64);
        bufp->chgQData(oldp+76,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                  ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                      & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                      : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                     [0x1aU]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (5U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0x1aU]))),64);
        bufp->chgQData(oldp+78,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                  ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                      & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                      : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                     [0x19U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (6U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0x19U]))),64);
        bufp->chgQData(oldp+80,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                  ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                      & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                      : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                     [0x18U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (7U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0x18U]))),64);
        bufp->chgQData(oldp+82,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                  ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                      & (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                      : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                     [0x17U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (8U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0x17U]))),64);
        bufp->chgQData(oldp+84,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                  ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                      & (9U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                      : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                     [0x16U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (9U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0x16U]))),64);
        bufp->chgQData(oldp+86,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                  ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                      & (0xaU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                      : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                     [0x15U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (0xaU 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0x15U]))),64);
        bufp->chgQData(oldp+88,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                  ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                      & (0xbU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                      : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                     [0x14U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (0xbU 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0x14U]))),64);
        bufp->chgQData(oldp+90,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                  ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                      & (0xcU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                      : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                     [0x13U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (0xcU 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0x13U]))),64);
        bufp->chgQData(oldp+92,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                  ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                      & (0xdU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                      : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                     [0x12U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (0xdU 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0x12U]))),64);
        bufp->chgQData(oldp+94,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                  ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                      & (0xeU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                      : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                     [0x11U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (0xeU 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0x11U]))),64);
        bufp->chgQData(oldp+96,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                  ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                      & (0xfU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                      : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                     [0x10U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (0xfU 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0x10U]))),64);
        bufp->chgQData(oldp+98,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                  ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                      & (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                      : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                     [0xfU]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                  & (0U 
                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                 & (0x10U 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                 ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                 : 
                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                [0xfU]))),64);
        bufp->chgQData(oldp+100,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0xeU]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (0x11U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0xeU]))),64);
        bufp->chgQData(oldp+102,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0xdU]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (0x12U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0xdU]))),64);
        bufp->chgQData(oldp+104,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x13U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0xcU]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (0x13U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0xcU]))),64);
        bufp->chgQData(oldp+106,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0xbU]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (0x14U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0xbU]))),64);
        bufp->chgQData(oldp+108,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x15U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0xaU]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (0x15U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0xaU]))),64);
        bufp->chgQData(oldp+110,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [9U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                 & (0U 
                                                    != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                & (0x16U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                               [9U]))),64);
        bufp->chgQData(oldp+112,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x17U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [8U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                 & (0U 
                                                    != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                & (0x17U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                               [8U]))),64);
        bufp->chgQData(oldp+114,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [7U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                 & (0U 
                                                    != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                & (0x18U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                               [7U]))),64);
        bufp->chgQData(oldp+116,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x19U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [6U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                 & (0U 
                                                    != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                & (0x19U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                               [6U]))),64);
        bufp->chgQData(oldp+118,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [5U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                 & (0U 
                                                    != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                & (0x1aU 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                               [5U]))),64);
        bufp->chgQData(oldp+120,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x1bU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [4U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                 & (0U 
                                                    != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                & (0x1bU 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                               [4U]))),64);
        bufp->chgQData(oldp+122,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [3U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                 & (0U 
                                                    != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                & (0x1cU 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                               [3U]))),64);
        bufp->chgQData(oldp+124,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x1dU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [2U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                 & (0U 
                                                    != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                & (0x1dU 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                               [2U]))),64);
        bufp->chgQData(oldp+126,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [1U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                 & (0U 
                                                    != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                & (0x1eU 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                               [1U]))),64);
        bufp->chgQData(oldp+128,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x1fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                 & (0U 
                                                    != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                & (0x1fU 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                               [0U]))),64);
        bufp->chgQData(oldp+130,((((QData)((IData)(
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN[
                                                   (((IData)(0x3fU) 
                                                     + 
                                                     (0x7c0U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__recording_counter) 
                                                         << 6U))) 
                                                    >> 5U)])) 
                                   << 0x20U) | (QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN[
                                                               (0x3eU 
                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__recording_counter) 
                                                                   << 1U))])))),64);
        bufp->chgBit(oldp+132,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_valid)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___T_17))));
        bufp->chgBit(oldp+133,((((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_valid) 
                                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___T_17))) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___T_18)) 
                                & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))));
        bufp->chgBit(oldp+134,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__do_check) 
                                  & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter))) 
                                 & (0x1fU != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay))) 
                                & (((((QData)((IData)(
                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN[
                                                      (((IData)(0x3fU) 
                                                        + 
                                                        (0x7c0U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay) 
                                                            << 6U))) 
                                                       >> 5U)])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN[
                                                                  (0x3eU 
                                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay) 
                                                                      << 1U))]))) 
                                    != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT___GEN)
                                         ? ((0x20U 
                                             >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT___GEN_0))
                                             ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT__Memory
                                            [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT___GEN_0]
                                             : 0ULL)
                                         : 0ULL)) | 
                                   ((((QData)((IData)(
                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN_0[
                                                      (((IData)(0x3fU) 
                                                        + 
                                                        (0x7c0U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay) 
                                                            << 6U))) 
                                                       >> 5U)])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN_0[
                                                                  (0x3eU 
                                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay) 
                                                                      << 1U))]))) 
                                    != ((0x20U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_ECP__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram_R_0_addr_pipe_0))
                                         ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_ECP__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram
                                        [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_ECP__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram_R_0_addr_pipe_0]
                                         : 0ULL))))));
        bufp->chgBit(oldp+135,((((3U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__inflight)) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__empty)) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT____Vcellinp__replayq__io_nack_valid)))));
        bufp->chgBit(oldp+136,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_nack_output) 
                                & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT__s2_id)))));
        bufp->chgBit(oldp+137,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_valid) 
                                & (((0xffffffffffULL 
                                     & (~ (1ULL | (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_pc)))) 
                                    == (0xffffffffffULL 
                                        & (~ (1ULL 
                                              | (~ 
                                                 (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                   << 0x38U) 
                                                  | (((QData)((IData)(
                                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                      << 0x18U) 
                                                     | ((QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                        >> 8U))))))))
                                    ? (((0xffffffffffULL 
                                         & (~ (1ULL 
                                               | (~ 
                                                  (((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                    << 0x38U) 
                                                   | (((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                       << 0x18U) 
                                                      | ((QData)((IData)(
                                                                         vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                         >> 8U))))))) 
                                        == (0xffffffffffULL 
                                            & (~ (3ULL 
                                                  | (~ 
                                                     (((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                       << 0x38U) 
                                                      | (((QData)((IData)(
                                                                          vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                          << 0x18U) 
                                                         | ((QData)((IData)(
                                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                            >> 8U)))))))) 
                                       | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U] 
                                          >> 0x11U))
                                    : ((3ULL > (0xffffffffffULL 
                                                & ((~ 
                                                    (1ULL 
                                                     | (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_pc))) 
                                                   - 
                                                   (~ 
                                                    (1ULL 
                                                     | (~ 
                                                        (((QData)((IData)(
                                                                          vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                          << 0x38U) 
                                                         | (((QData)((IData)(
                                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                             << 0x18U) 
                                                            | ((QData)((IData)(
                                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                               >> 8U))))))))) 
                                       | (((3ULL > 
                                            (0xffffffffffULL 
                                             & ((~ 
                                                 (1ULL 
                                                  | (~ 
                                                     (((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                       << 0x38U) 
                                                      | (((QData)((IData)(
                                                                          vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                          << 0x18U) 
                                                         | ((QData)((IData)(
                                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                            >> 8U)))))) 
                                                - (~ 
                                                   (1ULL 
                                                    | (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_pc)))))) 
                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U] 
                                              >> 0x11U)) 
                                          & ((0xffffffffffULL 
                                              & (~ 
                                                 (1ULL 
                                                  | (~ 
                                                     (((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                       << 0x38U) 
                                                      | (((QData)((IData)(
                                                                          vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                          << 0x18U) 
                                                         | ((QData)((IData)(
                                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                            >> 8U))))))) 
                                             != (0xffffffffffULL 
                                                 & (~ 
                                                    (3ULL 
                                                     | (~ 
                                                        (((QData)((IData)(
                                                                          vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                          << 0x38U) 
                                                         | (((QData)((IData)(
                                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                             << 0x18U) 
                                                            | ((QData)((IData)(
                                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                               >> 8U))))))))))))));
        bufp->chgQData(oldp+138,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__bjl_redirect_replay) 
                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__bjl_redirect_replay_continue))
                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_bjl_npc
                                   : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_replay)
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_pc
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__predicted_npc))),40);
        bufp->chgBit(oldp+140,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_valid) 
                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_pc 
                                     == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__replay_pc_cfi)) 
                                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__bjl_use_target))) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_imem_if_check_completed)))));
        bufp->chgBit(oldp+141,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_valid) 
                                 & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_jal) 
                                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_jalr)) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_branch))) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_imem_checker_mode))));
        bufp->chgBit(oldp+142,((1U & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__commit_bank_ptr)
                                          ? ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__empty_spec)) 
                                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__has_enq_1))
                                          : ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__empty_spec)) 
                                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__has_enq)))))));
        bufp->chgBit(oldp+143,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__empty_spec)) 
                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__has_enq)))));
        bufp->chgBit(oldp+144,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__empty_spec)) 
                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__has_enq_1)))));
        bufp->chgBit(oldp+145,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__reserve_fire) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__spec_bank_ptr)))));
        bufp->chgBit(oldp+146,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__commit_fire) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__commit_bank_ptr)))));
        bufp->chgBit(oldp+147,(((~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__spec_bank_ptr)) 
                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__spec_bank_ptr) 
                                       - (IData)(1U)))) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__BJL__io_bj_s2_replay))));
        if (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__empty_spec) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__do_enq))) {
            __Vtemp_h0abd8d3f__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_0__io_enq_bits[0U];
            __Vtemp_h0abd8d3f__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_0__io_enq_bits[1U];
            __Vtemp_h0abd8d3f__0[2U] = (0x3ffffU & 
                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_0__io_enq_bits[2U]);
        } else if ((0x51ffU >= (0x7fffU & ((IData)(0x52U) 
                                           * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr))))) {
            __Vtemp_h0abd8d3f__0[0U] = (((0U == (0x1fU 
                                                 & ((IData)(0x52U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr))))
                                          ? 0U : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT___GEN[
                                                  ((IData)(1U) 
                                                   + 
                                                   (0x3ffU 
                                                    & (((IData)(0x52U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)) 
                                                       >> 5U)))] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x52U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)))))) 
                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT___GEN[
                                           (0x3ffU 
                                            & (((IData)(0x52U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)) 
                                               >> 5U))] 
                                           >> (0x1fU 
                                               & ((IData)(0x52U) 
                                                  * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)))));
            __Vtemp_h0abd8d3f__0[1U] = (((0U == (0x1fU 
                                                 & ((IData)(0x52U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr))))
                                          ? 0U : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT___GEN[
                                                  ((IData)(2U) 
                                                   + 
                                                   (0x3ffU 
                                                    & (((IData)(0x52U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)) 
                                                       >> 5U)))] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x52U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)))))) 
                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT___GEN[
                                           ((IData)(1U) 
                                            + (0x3ffU 
                                               & (((IData)(0x52U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)) 
                                                  >> 5U)))] 
                                           >> (0x1fU 
                                               & ((IData)(0x52U) 
                                                  * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)))));
            __Vtemp_h0abd8d3f__0[2U] = (0x3ffffU & 
                                        (((0U == (0x1fU 
                                                  & ((IData)(0x52U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr))))
                                           ? 0U : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT___GEN[
                                                   ((IData)(3U) 
                                                    + 
                                                    (0x3ffU 
                                                     & (((IData)(0x52U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)) 
                                                        >> 5U)))] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(0x52U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)))))) 
                                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT___GEN[
                                            ((IData)(2U) 
                                             + (0x3ffU 
                                                & (((IData)(0x52U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)) 
                                                   >> 5U)))] 
                                            >> (0x1fU 
                                                & ((IData)(0x52U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr))))));
        } else {
            __Vtemp_h0abd8d3f__0[0U] = 0U;
            __Vtemp_h0abd8d3f__0[1U] = 0U;
            __Vtemp_h0abd8d3f__0[2U] = (0x3ffffU & 0U);
        }
        bufp->chgWData(oldp+148,(__Vtemp_h0abd8d3f__0),82);
        bufp->chgBit(oldp+151,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__reserve_fire) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__spec_bank_ptr))));
        bufp->chgBit(oldp+152,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__commit_fire) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__commit_bank_ptr))));
        bufp->chgBit(oldp+153,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__spec_bank_ptr)) 
                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__spec_bank_ptr) 
                                    - (IData)(1U))) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__BJL__io_bj_s2_replay))));
        if (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__empty_spec) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__do_enq))) {
            __Vtemp_h1e2890c5__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_1__io_enq_bits[0U];
            __Vtemp_h1e2890c5__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_1__io_enq_bits[1U];
            __Vtemp_h1e2890c5__0[2U] = (0x3ffffU & 
                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_1__io_enq_bits[2U]);
        } else if ((0x51ffU >= (0x7fffU & ((IData)(0x52U) 
                                           * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr))))) {
            __Vtemp_h1e2890c5__0[0U] = (((0U == (0x1fU 
                                                 & ((IData)(0x52U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr))))
                                          ? 0U : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT___GEN[
                                                  ((IData)(1U) 
                                                   + 
                                                   (0x3ffU 
                                                    & (((IData)(0x52U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)) 
                                                       >> 5U)))] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x52U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)))))) 
                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT___GEN[
                                           (0x3ffU 
                                            & (((IData)(0x52U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)) 
                                               >> 5U))] 
                                           >> (0x1fU 
                                               & ((IData)(0x52U) 
                                                  * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)))));
            __Vtemp_h1e2890c5__0[1U] = (((0U == (0x1fU 
                                                 & ((IData)(0x52U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr))))
                                          ? 0U : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT___GEN[
                                                  ((IData)(2U) 
                                                   + 
                                                   (0x3ffU 
                                                    & (((IData)(0x52U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)) 
                                                       >> 5U)))] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x52U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)))))) 
                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT___GEN[
                                           ((IData)(1U) 
                                            + (0x3ffU 
                                               & (((IData)(0x52U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)) 
                                                  >> 5U)))] 
                                           >> (0x1fU 
                                               & ((IData)(0x52U) 
                                                  * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)))));
            __Vtemp_h1e2890c5__0[2U] = (0x3ffffU & 
                                        (((0U == (0x1fU 
                                                  & ((IData)(0x52U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr))))
                                           ? 0U : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT___GEN[
                                                   ((IData)(3U) 
                                                    + 
                                                    (0x3ffU 
                                                     & (((IData)(0x52U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)) 
                                                        >> 5U)))] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(0x52U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)))))) 
                                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT___GEN[
                                            ((IData)(2U) 
                                             + (0x3ffU 
                                                & (((IData)(0x52U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)) 
                                                   >> 5U)))] 
                                            >> (0x1fU 
                                                & ((IData)(0x52U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr))))));
        } else {
            __Vtemp_h1e2890c5__0[0U] = 0U;
            __Vtemp_h1e2890c5__0[1U] = 0U;
            __Vtemp_h1e2890c5__0[2U] = (0x3ffffU & 0U);
        }
        bufp->chgWData(oldp+154,(__Vtemp_h1e2890c5__0),82);
        bufp->chgCData(oldp+157,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_imem_btb_update_valid)
                                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_btb_resp_entry)
                                   : 0x1cU)),5);
        bufp->chgQData(oldp+158,((0x7fffffffffULL & 
                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_imem_btb_update_valid)
                                    ? (~ (3ULL | (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_btb_update_bits_br_pc_output)))
                                    : (~ (3ULL | (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_pc)))))),39);
        bufp->chgBit(oldp+160,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_imem_btb_update_valid)) 
                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_cfi)))));
        bufp->chgQData(oldp+161,((0x7fffffffffULL & 
                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_imem_btb_update_valid)
                                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_btb_update_bits_br_pc_output
                                    : ((~ (3ULL | (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_pc))) 
                                       | ((QData)((IData)(
                                                          (1U 
                                                           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__taken))))) 
                                          << 1U))))),39);
        bufp->chgCData(oldp+163,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_imem_btb_update_valid)
                                   ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_btb_update_bits_cfiType_T_9) 
                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                          >> 7U)) ? 2U
                                       : (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_jalr) 
                                           & (1U == 
                                              ((0xcU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                   >> 0x10U)) 
                                               | (3U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                     >> 0xfU)))))
                                           ? 3U : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_btb_update_bits_cfiType_T_9)))
                                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___GEN))),2);
        bufp->chgBit(oldp+164,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__taken)) 
                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_88) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_89)))
                                 ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_116) 
                                    & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__wrong_path)))
                                 : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_55) 
                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_56)) 
                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_116)) 
                                    & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__wrong_path))))));
        bufp->chgSData(oldp+165,((0x1ffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT___GEN_5)
                                             ? (((~ (IData)(
                                                            (0x1fffffffffULL 
                                                             & ((~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_btb_update_bits_br_pc_output) 
                                                                >> 2U)))) 
                                                 ^ 
                                                 (3U 
                                                  & (~ (IData)(
                                                               (0xfffffffULL 
                                                                & ((~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_btb_update_bits_br_pc_output) 
                                                                   >> 0xbU)))))) 
                                                ^ (0x1c0U 
                                                   & (((IData)(0xddU) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_btb_resp_bht_history)) 
                                                      << 1U)))
                                             : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__reset_waddr)))),9);
        bufp->chgBit(oldp+166,((1U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__btb__io_bht_update_valid) 
                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_branch)) 
                                      | (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__reset_waddr) 
                                            >> 9U))))));
        bufp->chgBit(oldp+167,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT___GEN_5) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_br_taken))));
        bufp->chgBit(oldp+168,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_redirect) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___tlb_io_resp_miss)) 
                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_replay))));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[0x14U] 
                     | vlSelf->__Vm_traceActivity[0x3fU]))) {
        bufp->chgBit(oldp+169,(((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                    >> 0xaU)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_b_ready))));
        bufp->chgBit(oldp+170,(((~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__checker_mode_1cycle_delay)) 
                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode) 
                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__checker_priv_mode_1cycle_delay)))) 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_req_kill_T_3) 
                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__fpu_kill_mem)))));
        bufp->chgBit(oldp+171,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT___io_st_deq_T) 
                                & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_req_cmd)))));
        bufp->chgBit(oldp+172,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT___io_st_deq_T) 
                                & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_req_cmd)))));
        bufp->chgBit(oldp+173,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT___io_requestor_1_req_ready_output))));
        bufp->chgBit(oldp+174,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_valid) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_s1_kill)))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x15U])) {
        bufp->chgBit(oldp+175,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_tileClockGroup_tile_4_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+176,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_tileClockGroup_tile_4_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+177,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_tileClockGroup_tile_4_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_2));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x16U])) {
        bufp->chgBit(oldp+178,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+179,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+180,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+181,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+182,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+183,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+184,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+185,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+186,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+187,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+188,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+189,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+190,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+191,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+192,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+193,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+194,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+195,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+196,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+197,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+198,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+199,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+200,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x17U])) {
        bufp->chgBit(oldp+201,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__receiving));
        bufp->chgIData(oldp+202,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg),32);
        bufp->chgBit(oldp+203,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__sending));
        bufp->chgIData(oldp+204,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U]),32);
        bufp->chgIData(oldp+205,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_0),32);
        bufp->chgIData(oldp+206,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_1),32);
        bufp->chgIData(oldp+207,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_2),32);
        bufp->chgIData(oldp+208,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_3),32);
        bufp->chgIData(oldp+209,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_4),32);
        bufp->chgIData(oldp+210,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_5),32);
        bufp->chgIData(oldp+211,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_6),32);
        bufp->chgIData(oldp+212,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_7),32);
        bufp->chgBit(oldp+213,(vlSelf->TestHarness__DOT__simdram__DOT_____05Faw_ready_reg));
        bufp->chgBit(oldp+214,(vlSelf->TestHarness__DOT__simdram__DOT_____05Fw_ready_reg));
        bufp->chgBit(oldp+215,(vlSelf->TestHarness__DOT__simdram__DOT_____05Fb_valid_reg));
        bufp->chgCData(oldp+216,(vlSelf->TestHarness__DOT__simdram__DOT_____05Fb_id_reg),4);
        bufp->chgCData(oldp+217,(vlSelf->TestHarness__DOT__simdram__DOT_____05Fb_resp_reg),2);
        bufp->chgBit(oldp+218,(vlSelf->TestHarness__DOT__simdram__DOT_____05Far_ready_reg));
        bufp->chgBit(oldp+219,(vlSelf->TestHarness__DOT__simdram__DOT_____05Fr_valid_reg));
        bufp->chgCData(oldp+220,(vlSelf->TestHarness__DOT__simdram__DOT_____05Fr_id_reg),4);
        bufp->chgQData(oldp+221,(vlSelf->TestHarness__DOT__simdram__DOT_____05Fr_data_reg),64);
        bufp->chgCData(oldp+223,(vlSelf->TestHarness__DOT__simdram__DOT_____05Fr_resp_reg),2);
        bufp->chgBit(oldp+224,(vlSelf->TestHarness__DOT__simdram__DOT_____05Fr_last_reg));
        bufp->chgBit(oldp+225,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT___tl2axi4_auto_out_aw_valid) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT___GEN_4))));
        bufp->chgCData(oldp+226,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___queue_arw_deq_io_deq_bits_id),4);
        bufp->chgIData(oldp+227,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___queue_arw_deq_io_deq_bits_addr),32);
        bufp->chgCData(oldp+228,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___queue_arw_deq_io_deq_bits_len),8);
        bufp->chgCData(oldp+229,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___queue_arw_deq_io_deq_bits_size),3);
        bufp->chgCData(oldp+230,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__queue_arw_deq__DOT__maybe_full)
                                   ? (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__queue_arw_deq__DOT__ram_ext__DOT__Memory
                                            [0U][1U] 
                                            >> 0xfU))
                                   : 1U)),2);
        bufp->chgBit(oldp+231,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__queue_arw_deq__DOT__maybe_full) 
                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__queue_arw_deq__DOT__ram_ext__DOT__Memory
                                   [0U][1U] >> 0x11U))));
        bufp->chgCData(oldp+232,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__queue_arw_deq__DOT__maybe_full)
                                   ? (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__queue_arw_deq__DOT__ram_ext__DOT__Memory
                                              [0U][1U] 
                                              >> 0x12U))
                                   : 0U)),4);
        bufp->chgCData(oldp+233,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__queue_arw_deq__DOT__maybe_full)
                                   ? (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__queue_arw_deq__DOT__ram_ext__DOT__Memory
                                            [0U][1U] 
                                            >> 0x16U))
                                   : 1U)),3);
        bufp->chgCData(oldp+234,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__queue_arw_deq__DOT__maybe_full)
                                   ? (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__queue_arw_deq__DOT__ram_ext__DOT__Memory
                                              [0U][1U] 
                                              >> 0x19U))
                                   : 0U)),4);
        bufp->chgBit(oldp+235,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__deq__DOT___io_deq_valid_output));
        bufp->chgQData(oldp+236,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__deq__DOT__maybe_full)
                                   ? (((QData)((IData)(
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__deq__DOT__ram_ext__DOT__Memory
                                                       [0U][1U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__deq__DOT__ram_ext__DOT__Memory
                                                                   [0U][0U])))
                                   : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_data)),64);
        bufp->chgCData(oldp+238,((0xffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__deq__DOT__maybe_full)
                                            ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__deq__DOT__ram_ext__DOT__Memory
                                           [0U][2U]
                                            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_mask)))),8);
        bufp->chgBit(oldp+239,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__deq__DOT__maybe_full)
                                       ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__deq__DOT__ram_ext__DOT__Memory
                                          [0U][2U] 
                                          >> 8U) : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__out_w_bits_last)))));
        bufp->chgBit(oldp+240,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__x1_b_ready));
        bufp->chgBit(oldp+241,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT___tl2axi4_auto_out_ar_valid) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT___GEN_0))));
        bufp->chgBit(oldp+242,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__x1_r_ready));
        bufp->chgBit(oldp+243,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txm__DOT__out));
        bufp->chgBit(oldp+244,((1U & vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg)));
        bufp->chgBit(oldp+245,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 1U))));
        bufp->chgBit(oldp+246,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0xaU))));
        bufp->chgBit(oldp+247,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0xbU))));
        bufp->chgBit(oldp+248,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0xcU))));
        bufp->chgBit(oldp+249,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0xdU))));
        bufp->chgBit(oldp+250,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0xeU))));
        bufp->chgBit(oldp+251,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0xfU))));
        bufp->chgBit(oldp+252,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0x10U))));
        bufp->chgBit(oldp+253,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0x11U))));
        bufp->chgBit(oldp+254,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0x12U))));
        bufp->chgBit(oldp+255,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0x13U))));
        bufp->chgBit(oldp+256,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 2U))));
        bufp->chgBit(oldp+257,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0x14U))));
        bufp->chgBit(oldp+258,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0x15U))));
        bufp->chgBit(oldp+259,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0x16U))));
        bufp->chgBit(oldp+260,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0x17U))));
        bufp->chgBit(oldp+261,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0x18U))));
        bufp->chgBit(oldp+262,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0x19U))));
        bufp->chgBit(oldp+263,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0x1aU))));
        bufp->chgBit(oldp+264,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0x1bU))));
        bufp->chgBit(oldp+265,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0x1cU))));
        bufp->chgBit(oldp+266,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0x1dU))));
        bufp->chgBit(oldp+267,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 3U))));
        bufp->chgBit(oldp+268,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0x1eU))));
        bufp->chgBit(oldp+269,((vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                >> 0x1fU)));
        bufp->chgBit(oldp+270,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 4U))));
        bufp->chgBit(oldp+271,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 5U))));
        bufp->chgBit(oldp+272,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 6U))));
        bufp->chgBit(oldp+273,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 7U))));
        bufp->chgBit(oldp+274,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 8U))));
        bufp->chgBit(oldp+275,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 9U))));
        bufp->chgBit(oldp+276,((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U])));
        bufp->chgBit(oldp+277,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 1U))));
        bufp->chgBit(oldp+278,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 0xaU))));
        bufp->chgBit(oldp+279,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 0xbU))));
        bufp->chgBit(oldp+280,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 0xcU))));
        bufp->chgBit(oldp+281,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 0xdU))));
        bufp->chgBit(oldp+282,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 0xeU))));
        bufp->chgBit(oldp+283,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 0xfU))));
        bufp->chgBit(oldp+284,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 0x10U))));
        bufp->chgBit(oldp+285,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 0x11U))));
        bufp->chgBit(oldp+286,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 0x12U))));
        bufp->chgBit(oldp+287,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 0x13U))));
        bufp->chgBit(oldp+288,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 2U))));
        bufp->chgBit(oldp+289,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 0x14U))));
        bufp->chgBit(oldp+290,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 0x15U))));
        bufp->chgBit(oldp+291,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 0x16U))));
        bufp->chgBit(oldp+292,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 0x17U))));
        bufp->chgBit(oldp+293,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 0x18U))));
        bufp->chgBit(oldp+294,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 0x19U))));
        bufp->chgBit(oldp+295,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 0x1aU))));
        bufp->chgBit(oldp+296,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 0x1bU))));
        bufp->chgBit(oldp+297,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 0x1cU))));
        bufp->chgBit(oldp+298,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 0x1dU))));
        bufp->chgBit(oldp+299,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 3U))));
        bufp->chgBit(oldp+300,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 0x1eU))));
        bufp->chgBit(oldp+301,((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                >> 0x1fU)));
        bufp->chgBit(oldp+302,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 4U))));
        bufp->chgBit(oldp+303,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 5U))));
        bufp->chgBit(oldp+304,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 6U))));
        bufp->chgBit(oldp+305,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 7U))));
        bufp->chgBit(oldp+306,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 8U))));
        bufp->chgBit(oldp+307,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                      >> 9U))));
        bufp->chgIData(oldp+308,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U]),32);
        bufp->chgBit(oldp+309,((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_ght_status_out_sr_out 
                                >> 0x1fU)));
        bufp->chgCData(oldp+310,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[4U] 
                                        >> 0xcU))),3);
        bufp->chgCData(oldp+311,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[4U] 
                                        >> 0x14U))),3);
        bufp->chgIData(oldp+312,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_b_wctrl_0),22);
        bufp->chgIData(oldp+313,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_b_wctrl_1),22);
        bufp->chgIData(oldp+314,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_b_wctrl_2),22);
        bufp->chgIData(oldp+315,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_b_wctrl_3),22);
        bufp->chgCData(oldp+316,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_routed_status),5);
        bufp->chgCData(oldp+317,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_routed_status_1),5);
        bufp->chgCData(oldp+318,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_routed_status_2),5);
        bufp->chgCData(oldp+319,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_routed_status_3),5);
        bufp->chgQData(oldp+320,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_debug_gcounter),64);
        bufp->chgCData(oldp+322,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__int_rtc_tick_c_value),8);
        bufp->chgBit(oldp+323,((0xc7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__int_rtc_tick_c_value))));
        bufp->chgWData(oldp+324,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__inflight),1040);
        bufp->chgWData(oldp+357,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__inflight_opcodes),4160);
        bufp->chgWData(oldp+487,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__inflight_sizes),4160);
        bufp->chgIData(oldp+617,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__watchdog),32);
        bufp->chgWData(oldp+618,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__inflight),1040);
        bufp->chgWData(oldp+651,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__inflight_opcodes),4160);
        bufp->chgWData(oldp+781,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__inflight_sizes),4160);
        bufp->chgIData(oldp+911,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__watchdog),32);
        bufp->chgBit(oldp+912,(((1U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[4U] 
                                              >> 0xcU))) 
                                | (1U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[4U] 
                                                >> 0x14U))))));
        __Vtemp_h10336803__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[0U];
        __Vtemp_h10336803__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[1U];
        __Vtemp_h10336803__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[2U];
        __Vtemp_h10336803__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[3U];
        __Vtemp_h10336803__0[4U] = (0x1ffffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[4U]);
        bufp->chgWData(oldp+913,(__Vtemp_h10336803__0),145);
        bufp->chgWData(oldp+918,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__source__DOT__mem_0),145);
        bufp->chgWData(oldp+923,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__source__DOT__mem_1),145);
        bufp->chgWData(oldp+928,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__source__DOT__mem_2),145);
        bufp->chgWData(oldp+933,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__source__DOT__mem_3),145);
        bufp->chgWData(oldp+938,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__source__DOT__mem_4),145);
        bufp->chgWData(oldp+943,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__source__DOT__mem_5),145);
        bufp->chgWData(oldp+948,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__source__DOT__mem_6),145);
        bufp->chgWData(oldp+953,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__source__DOT__mem_7),145);
        bufp->chgBit(oldp+958,(((2U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[4U] 
                                              >> 0xcU))) 
                                | (2U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[4U] 
                                                >> 0x14U))))));
        bufp->chgWData(oldp+959,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__source__DOT__mem_0),145);
        bufp->chgWData(oldp+964,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__source__DOT__mem_1),145);
        bufp->chgWData(oldp+969,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__source__DOT__mem_2),145);
        bufp->chgWData(oldp+974,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__source__DOT__mem_3),145);
        bufp->chgWData(oldp+979,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__source__DOT__mem_4),145);
        bufp->chgWData(oldp+984,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__source__DOT__mem_5),145);
        bufp->chgWData(oldp+989,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__source__DOT__mem_6),145);
        bufp->chgWData(oldp+994,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__source__DOT__mem_7),145);
        bufp->chgBit(oldp+999,(((3U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[4U] 
                                              >> 0xcU))) 
                                | (3U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[4U] 
                                                >> 0x14U))))));
        bufp->chgWData(oldp+1000,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__source__DOT__mem_0),145);
        bufp->chgWData(oldp+1005,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__source__DOT__mem_1),145);
        bufp->chgWData(oldp+1010,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__source__DOT__mem_2),145);
        bufp->chgWData(oldp+1015,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__source__DOT__mem_3),145);
        bufp->chgWData(oldp+1020,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__source__DOT__mem_4),145);
        bufp->chgWData(oldp+1025,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__source__DOT__mem_5),145);
        bufp->chgWData(oldp+1030,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__source__DOT__mem_6),145);
        bufp->chgWData(oldp+1035,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__source__DOT__mem_7),145);
        bufp->chgBit(oldp+1040,(((4U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[4U] 
                                               >> 0xcU))) 
                                 | (4U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[4U] 
                                                 >> 0x14U))))));
        bufp->chgWData(oldp+1041,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__mem_0),145);
        bufp->chgWData(oldp+1046,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__mem_1),145);
        bufp->chgWData(oldp+1051,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__mem_2),145);
        bufp->chgWData(oldp+1056,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__mem_3),145);
        bufp->chgWData(oldp+1061,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__mem_4),145);
        bufp->chgWData(oldp+1066,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__mem_5),145);
        bufp->chgWData(oldp+1071,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__mem_6),145);
        bufp->chgWData(oldp+1076,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__mem_7),145);
        bufp->chgBit(oldp+1081,((((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_ght_status_out_sr_out 
                                   >> 0x1fU) | (0U 
                                                != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_routed_status))) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_ic_counter_sr_out[0U] 
                                    >> 0x1fU))));
        bufp->chgIData(oldp+1082,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_0),22);
        bufp->chgIData(oldp+1083,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_1),22);
        bufp->chgIData(oldp+1084,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_2),22);
        bufp->chgIData(oldp+1085,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_3),22);
        bufp->chgIData(oldp+1086,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_4),22);
        bufp->chgIData(oldp+1087,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_5),22);
        bufp->chgIData(oldp+1088,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_6),22);
        bufp->chgIData(oldp+1089,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_7),22);
        bufp->chgIData(oldp+1090,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_8),22);
        bufp->chgIData(oldp+1091,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_9),22);
        bufp->chgIData(oldp+1092,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_10),22);
        bufp->chgIData(oldp+1093,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_11),22);
        bufp->chgIData(oldp+1094,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_12),22);
        bufp->chgIData(oldp+1095,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_13),22);
        bufp->chgIData(oldp+1096,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_14),22);
        bufp->chgIData(oldp+1097,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_15),22);
        bufp->chgIData(oldp+1098,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_16),22);
        bufp->chgIData(oldp+1099,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_17),22);
        bufp->chgIData(oldp+1100,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_18),22);
        bufp->chgIData(oldp+1101,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_19),22);
        bufp->chgIData(oldp+1102,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_20),22);
        bufp->chgIData(oldp+1103,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_21),22);
        bufp->chgIData(oldp+1104,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_22),22);
        bufp->chgIData(oldp+1105,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_23),22);
        bufp->chgIData(oldp+1106,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_24),22);
        bufp->chgIData(oldp+1107,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_25),22);
        bufp->chgIData(oldp+1108,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_26),22);
        bufp->chgIData(oldp+1109,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_27),22);
        bufp->chgIData(oldp+1110,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_28),22);
        bufp->chgIData(oldp+1111,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_29),22);
        bufp->chgIData(oldp+1112,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_30),22);
        bufp->chgIData(oldp+1113,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_31),22);
        bufp->chgIData(oldp+1114,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_32),22);
        bufp->chgIData(oldp+1115,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_33),22);
        bufp->chgIData(oldp+1116,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_34),22);
        bufp->chgIData(oldp+1117,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_35),22);
        bufp->chgIData(oldp+1118,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_36),22);
        bufp->chgIData(oldp+1119,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_37),22);
        bufp->chgIData(oldp+1120,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_38),22);
        bufp->chgIData(oldp+1121,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_39),22);
        bufp->chgIData(oldp+1122,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_40),22);
        bufp->chgIData(oldp+1123,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_41),22);
        bufp->chgIData(oldp+1124,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_42),22);
        bufp->chgIData(oldp+1125,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_43),22);
        bufp->chgIData(oldp+1126,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_44),22);
        bufp->chgIData(oldp+1127,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_45),22);
        bufp->chgIData(oldp+1128,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_46),22);
        bufp->chgIData(oldp+1129,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_47),22);
        bufp->chgIData(oldp+1130,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_48),22);
        bufp->chgIData(oldp+1131,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_49),22);
        bufp->chgIData(oldp+1132,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_50),22);
        bufp->chgIData(oldp+1133,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_51),22);
        bufp->chgIData(oldp+1134,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_52),22);
        bufp->chgIData(oldp+1135,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_53),22);
        bufp->chgIData(oldp+1136,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_54),22);
        bufp->chgIData(oldp+1137,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_55),22);
        bufp->chgIData(oldp+1138,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_56),22);
        bufp->chgIData(oldp+1139,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_57),22);
        bufp->chgIData(oldp+1140,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_58),22);
        bufp->chgIData(oldp+1141,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_59),22);
        bufp->chgIData(oldp+1142,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_60),22);
        bufp->chgIData(oldp+1143,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_61),22);
        bufp->chgIData(oldp+1144,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_62),22);
        bufp->chgIData(oldp+1145,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_63),22);
        bufp->chgBit(oldp+1146,((1U & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_ght_status_out_sr_out 
                                         >> 0x1fU) 
                                        | (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_routed_status_1))) 
                                       | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_ic_counter_sr_out[1U] 
                                          >> 0xfU)))));
        bufp->chgIData(oldp+1147,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_0),22);
        bufp->chgIData(oldp+1148,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_1),22);
        bufp->chgIData(oldp+1149,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_2),22);
        bufp->chgIData(oldp+1150,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_3),22);
        bufp->chgIData(oldp+1151,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_4),22);
        bufp->chgIData(oldp+1152,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_5),22);
        bufp->chgIData(oldp+1153,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_6),22);
        bufp->chgIData(oldp+1154,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_7),22);
        bufp->chgIData(oldp+1155,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_8),22);
        bufp->chgIData(oldp+1156,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_9),22);
        bufp->chgIData(oldp+1157,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_10),22);
        bufp->chgIData(oldp+1158,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_11),22);
        bufp->chgIData(oldp+1159,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_12),22);
        bufp->chgIData(oldp+1160,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_13),22);
        bufp->chgIData(oldp+1161,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_14),22);
        bufp->chgIData(oldp+1162,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_15),22);
        bufp->chgIData(oldp+1163,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_16),22);
        bufp->chgIData(oldp+1164,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_17),22);
        bufp->chgIData(oldp+1165,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_18),22);
        bufp->chgIData(oldp+1166,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_19),22);
        bufp->chgIData(oldp+1167,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_20),22);
        bufp->chgIData(oldp+1168,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_21),22);
        bufp->chgIData(oldp+1169,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_22),22);
        bufp->chgIData(oldp+1170,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_23),22);
        bufp->chgIData(oldp+1171,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_24),22);
        bufp->chgIData(oldp+1172,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_25),22);
        bufp->chgIData(oldp+1173,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_26),22);
        bufp->chgIData(oldp+1174,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_27),22);
        bufp->chgIData(oldp+1175,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_28),22);
        bufp->chgIData(oldp+1176,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_29),22);
        bufp->chgIData(oldp+1177,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_30),22);
        bufp->chgIData(oldp+1178,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_31),22);
        bufp->chgIData(oldp+1179,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_32),22);
        bufp->chgIData(oldp+1180,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_33),22);
        bufp->chgIData(oldp+1181,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_34),22);
        bufp->chgIData(oldp+1182,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_35),22);
        bufp->chgIData(oldp+1183,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_36),22);
        bufp->chgIData(oldp+1184,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_37),22);
        bufp->chgIData(oldp+1185,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_38),22);
        bufp->chgIData(oldp+1186,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_39),22);
        bufp->chgIData(oldp+1187,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_40),22);
        bufp->chgIData(oldp+1188,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_41),22);
        bufp->chgIData(oldp+1189,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_42),22);
        bufp->chgIData(oldp+1190,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_43),22);
        bufp->chgIData(oldp+1191,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_44),22);
        bufp->chgIData(oldp+1192,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_45),22);
        bufp->chgIData(oldp+1193,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_46),22);
        bufp->chgIData(oldp+1194,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_47),22);
        bufp->chgIData(oldp+1195,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_48),22);
        bufp->chgIData(oldp+1196,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_49),22);
        bufp->chgIData(oldp+1197,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_50),22);
        bufp->chgIData(oldp+1198,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_51),22);
        bufp->chgIData(oldp+1199,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_52),22);
        bufp->chgIData(oldp+1200,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_53),22);
        bufp->chgIData(oldp+1201,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_54),22);
        bufp->chgIData(oldp+1202,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_55),22);
        bufp->chgIData(oldp+1203,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_56),22);
        bufp->chgIData(oldp+1204,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_57),22);
        bufp->chgIData(oldp+1205,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_58),22);
        bufp->chgIData(oldp+1206,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_59),22);
        bufp->chgIData(oldp+1207,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_60),22);
        bufp->chgIData(oldp+1208,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_61),22);
        bufp->chgIData(oldp+1209,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_62),22);
        bufp->chgIData(oldp+1210,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_63),22);
        bufp->chgBit(oldp+1211,((((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_ght_status_out_sr_out 
                                   >> 0x1fU) | (0U 
                                                != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_routed_status_2))) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_ic_counter_sr_out[1U] 
                                    >> 0x1fU))));
        bufp->chgIData(oldp+1212,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_0),22);
        bufp->chgIData(oldp+1213,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_1),22);
        bufp->chgIData(oldp+1214,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_2),22);
        bufp->chgIData(oldp+1215,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_3),22);
        bufp->chgIData(oldp+1216,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_4),22);
        bufp->chgIData(oldp+1217,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_5),22);
        bufp->chgIData(oldp+1218,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_6),22);
        bufp->chgIData(oldp+1219,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_7),22);
        bufp->chgIData(oldp+1220,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_8),22);
        bufp->chgIData(oldp+1221,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_9),22);
        bufp->chgIData(oldp+1222,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_10),22);
        bufp->chgIData(oldp+1223,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_11),22);
        bufp->chgIData(oldp+1224,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_12),22);
        bufp->chgIData(oldp+1225,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_13),22);
        bufp->chgIData(oldp+1226,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_14),22);
        bufp->chgIData(oldp+1227,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_15),22);
        bufp->chgIData(oldp+1228,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_16),22);
        bufp->chgIData(oldp+1229,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_17),22);
        bufp->chgIData(oldp+1230,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_18),22);
        bufp->chgIData(oldp+1231,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_19),22);
        bufp->chgIData(oldp+1232,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_20),22);
        bufp->chgIData(oldp+1233,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_21),22);
        bufp->chgIData(oldp+1234,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_22),22);
        bufp->chgIData(oldp+1235,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_23),22);
        bufp->chgIData(oldp+1236,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_24),22);
        bufp->chgIData(oldp+1237,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_25),22);
        bufp->chgIData(oldp+1238,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_26),22);
        bufp->chgIData(oldp+1239,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_27),22);
        bufp->chgIData(oldp+1240,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_28),22);
        bufp->chgIData(oldp+1241,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_29),22);
        bufp->chgIData(oldp+1242,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_30),22);
        bufp->chgIData(oldp+1243,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_31),22);
        bufp->chgIData(oldp+1244,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_32),22);
        bufp->chgIData(oldp+1245,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_33),22);
        bufp->chgIData(oldp+1246,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_34),22);
        bufp->chgIData(oldp+1247,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_35),22);
        bufp->chgIData(oldp+1248,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_36),22);
        bufp->chgIData(oldp+1249,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_37),22);
        bufp->chgIData(oldp+1250,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_38),22);
        bufp->chgIData(oldp+1251,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_39),22);
        bufp->chgIData(oldp+1252,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_40),22);
        bufp->chgIData(oldp+1253,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_41),22);
        bufp->chgIData(oldp+1254,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_42),22);
        bufp->chgIData(oldp+1255,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_43),22);
        bufp->chgIData(oldp+1256,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_44),22);
        bufp->chgIData(oldp+1257,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_45),22);
        bufp->chgIData(oldp+1258,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_46),22);
        bufp->chgIData(oldp+1259,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_47),22);
        bufp->chgIData(oldp+1260,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_48),22);
        bufp->chgIData(oldp+1261,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_49),22);
        bufp->chgIData(oldp+1262,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_50),22);
        bufp->chgIData(oldp+1263,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_51),22);
        bufp->chgIData(oldp+1264,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_52),22);
        bufp->chgIData(oldp+1265,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_53),22);
        bufp->chgIData(oldp+1266,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_54),22);
        bufp->chgIData(oldp+1267,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_55),22);
        bufp->chgIData(oldp+1268,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_56),22);
        bufp->chgIData(oldp+1269,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_57),22);
        bufp->chgIData(oldp+1270,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_58),22);
        bufp->chgIData(oldp+1271,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_59),22);
        bufp->chgIData(oldp+1272,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_60),22);
        bufp->chgIData(oldp+1273,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_61),22);
        bufp->chgIData(oldp+1274,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_62),22);
        bufp->chgIData(oldp+1275,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_63),22);
        bufp->chgBit(oldp+1276,((((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_ght_status_out_sr_out 
                                   >> 0x1fU) | (0U 
                                                != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_routed_status_3))) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_ic_counter_sr_out[2U] 
                                    >> 0xfU))));
        bufp->chgIData(oldp+1277,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_0),22);
        bufp->chgIData(oldp+1278,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_1),22);
        bufp->chgIData(oldp+1279,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_2),22);
        bufp->chgIData(oldp+1280,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_3),22);
        bufp->chgIData(oldp+1281,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_4),22);
        bufp->chgIData(oldp+1282,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_5),22);
        bufp->chgIData(oldp+1283,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_6),22);
        bufp->chgIData(oldp+1284,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_7),22);
        bufp->chgIData(oldp+1285,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_8),22);
        bufp->chgIData(oldp+1286,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_9),22);
        bufp->chgIData(oldp+1287,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_10),22);
        bufp->chgIData(oldp+1288,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_11),22);
        bufp->chgIData(oldp+1289,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_12),22);
        bufp->chgIData(oldp+1290,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_13),22);
        bufp->chgIData(oldp+1291,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_14),22);
        bufp->chgIData(oldp+1292,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_15),22);
        bufp->chgIData(oldp+1293,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_16),22);
        bufp->chgIData(oldp+1294,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_17),22);
        bufp->chgIData(oldp+1295,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_18),22);
        bufp->chgIData(oldp+1296,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_19),22);
        bufp->chgIData(oldp+1297,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_20),22);
        bufp->chgIData(oldp+1298,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_21),22);
        bufp->chgIData(oldp+1299,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_22),22);
        bufp->chgIData(oldp+1300,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_23),22);
        bufp->chgIData(oldp+1301,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_24),22);
        bufp->chgIData(oldp+1302,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_25),22);
        bufp->chgIData(oldp+1303,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_26),22);
        bufp->chgIData(oldp+1304,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_27),22);
        bufp->chgIData(oldp+1305,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_28),22);
        bufp->chgIData(oldp+1306,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_29),22);
        bufp->chgIData(oldp+1307,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_30),22);
        bufp->chgIData(oldp+1308,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_31),22);
        bufp->chgIData(oldp+1309,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_32),22);
        bufp->chgIData(oldp+1310,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_33),22);
        bufp->chgIData(oldp+1311,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_34),22);
        bufp->chgIData(oldp+1312,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_35),22);
        bufp->chgIData(oldp+1313,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_36),22);
        bufp->chgIData(oldp+1314,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_37),22);
        bufp->chgIData(oldp+1315,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_38),22);
        bufp->chgIData(oldp+1316,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_39),22);
        bufp->chgIData(oldp+1317,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_40),22);
        bufp->chgIData(oldp+1318,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_41),22);
        bufp->chgIData(oldp+1319,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_42),22);
        bufp->chgIData(oldp+1320,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_43),22);
        bufp->chgIData(oldp+1321,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_44),22);
        bufp->chgIData(oldp+1322,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_45),22);
        bufp->chgIData(oldp+1323,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_46),22);
        bufp->chgIData(oldp+1324,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_47),22);
        bufp->chgIData(oldp+1325,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_48),22);
        bufp->chgIData(oldp+1326,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_49),22);
        bufp->chgIData(oldp+1327,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_50),22);
        bufp->chgIData(oldp+1328,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_51),22);
        bufp->chgIData(oldp+1329,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_52),22);
        bufp->chgIData(oldp+1330,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_53),22);
        bufp->chgIData(oldp+1331,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_54),22);
        bufp->chgIData(oldp+1332,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_55),22);
        bufp->chgIData(oldp+1333,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_56),22);
        bufp->chgIData(oldp+1334,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_57),22);
        bufp->chgIData(oldp+1335,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_58),22);
        bufp->chgIData(oldp+1336,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_59),22);
        bufp->chgIData(oldp+1337,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_60),22);
        bufp->chgIData(oldp+1338,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_61),22);
        bufp->chgIData(oldp+1339,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_62),22);
        bufp->chgIData(oldp+1340,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_63),22);
        bufp->chgWData(oldp+1341,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_0),272);
        bufp->chgWData(oldp+1350,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_1),272);
        bufp->chgWData(oldp+1359,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_2),272);
        bufp->chgWData(oldp+1368,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_3),272);
        bufp->chgWData(oldp+1377,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_4),272);
        bufp->chgWData(oldp+1386,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_5),272);
        bufp->chgWData(oldp+1395,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_6),272);
        bufp->chgWData(oldp+1404,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_7),272);
        bufp->chgWData(oldp+1413,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_8),272);
        bufp->chgWData(oldp+1422,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_9),272);
        bufp->chgWData(oldp+1431,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_10),272);
        bufp->chgWData(oldp+1440,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_11),272);
        bufp->chgWData(oldp+1449,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_12),272);
        bufp->chgWData(oldp+1458,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_13),272);
        bufp->chgWData(oldp+1467,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_14),272);
        bufp->chgWData(oldp+1476,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_15),272);
        bufp->chgWData(oldp+1485,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_16),272);
        bufp->chgWData(oldp+1494,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_17),272);
        bufp->chgWData(oldp+1503,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_18),272);
        bufp->chgWData(oldp+1512,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_19),272);
        bufp->chgWData(oldp+1521,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_20),272);
        bufp->chgWData(oldp+1530,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_21),272);
        bufp->chgWData(oldp+1539,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_22),272);
        bufp->chgWData(oldp+1548,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_23),272);
        bufp->chgWData(oldp+1557,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_24),272);
        bufp->chgWData(oldp+1566,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_25),272);
        bufp->chgWData(oldp+1575,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_26),272);
        bufp->chgWData(oldp+1584,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_27),272);
        bufp->chgWData(oldp+1593,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_28),272);
        bufp->chgWData(oldp+1602,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_29),272);
        bufp->chgWData(oldp+1611,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_30),272);
        bufp->chgWData(oldp+1620,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_31),272);
        bufp->chgWData(oldp+1629,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_32),272);
        bufp->chgWData(oldp+1638,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_33),272);
        bufp->chgWData(oldp+1647,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_34),272);
        bufp->chgWData(oldp+1656,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_35),272);
        bufp->chgWData(oldp+1665,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_36),272);
        bufp->chgWData(oldp+1674,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_37),272);
        bufp->chgWData(oldp+1683,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_38),272);
        bufp->chgWData(oldp+1692,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_39),272);
        bufp->chgWData(oldp+1701,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_40),272);
        bufp->chgWData(oldp+1710,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_41),272);
        bufp->chgWData(oldp+1719,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_42),272);
        bufp->chgWData(oldp+1728,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_43),272);
        bufp->chgWData(oldp+1737,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_44),272);
        bufp->chgWData(oldp+1746,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_45),272);
        bufp->chgWData(oldp+1755,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_46),272);
        bufp->chgWData(oldp+1764,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_47),272);
        bufp->chgWData(oldp+1773,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_48),272);
        bufp->chgWData(oldp+1782,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_49),272);
        bufp->chgWData(oldp+1791,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_50),272);
        bufp->chgWData(oldp+1800,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_51),272);
        bufp->chgWData(oldp+1809,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_52),272);
        bufp->chgWData(oldp+1818,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_53),272);
        bufp->chgWData(oldp+1827,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_54),272);
        bufp->chgWData(oldp+1836,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_55),272);
        bufp->chgWData(oldp+1845,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_56),272);
        bufp->chgWData(oldp+1854,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_57),272);
        bufp->chgWData(oldp+1863,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_58),272);
        bufp->chgWData(oldp+1872,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_59),272);
        bufp->chgWData(oldp+1881,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_60),272);
        bufp->chgWData(oldp+1890,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_61),272);
        bufp->chgWData(oldp+1899,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_62),272);
        bufp->chgWData(oldp+1908,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_63),272);
        bufp->chgWData(oldp+1917,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_64),272);
        bufp->chgWData(oldp+1926,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_65),272);
        bufp->chgWData(oldp+1935,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_66),272);
        bufp->chgWData(oldp+1944,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_67),272);
        bufp->chgWData(oldp+1953,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_68),272);
        bufp->chgWData(oldp+1962,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_69),272);
        bufp->chgWData(oldp+1971,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_70),272);
        bufp->chgWData(oldp+1980,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_71),272);
        bufp->chgWData(oldp+1989,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_72),272);
        bufp->chgWData(oldp+1998,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_73),272);
        bufp->chgWData(oldp+2007,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_74),272);
        bufp->chgWData(oldp+2016,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_75),272);
        bufp->chgWData(oldp+2025,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_76),272);
        bufp->chgWData(oldp+2034,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_77),272);
        bufp->chgWData(oldp+2043,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_78),272);
        bufp->chgWData(oldp+2052,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_79),272);
        bufp->chgWData(oldp+2061,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_80),272);
        bufp->chgWData(oldp+2070,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_81),272);
        bufp->chgWData(oldp+2079,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_82),272);
        bufp->chgWData(oldp+2088,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_83),272);
        bufp->chgWData(oldp+2097,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_84),272);
        bufp->chgWData(oldp+2106,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_85),272);
        bufp->chgWData(oldp+2115,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_86),272);
        bufp->chgWData(oldp+2124,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_87),272);
        bufp->chgWData(oldp+2133,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_88),272);
        bufp->chgWData(oldp+2142,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_89),272);
        bufp->chgWData(oldp+2151,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_90),272);
        bufp->chgWData(oldp+2160,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_91),272);
        bufp->chgWData(oldp+2169,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_92),272);
        bufp->chgWData(oldp+2178,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_93),272);
        bufp->chgWData(oldp+2187,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_94),272);
        bufp->chgWData(oldp+2196,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_95),272);
        bufp->chgWData(oldp+2205,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_96),272);
        bufp->chgWData(oldp+2214,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_97),272);
        bufp->chgWData(oldp+2223,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_98),272);
        bufp->chgWData(oldp+2232,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_99),272);
        bufp->chgWData(oldp+2241,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_100),272);
        bufp->chgWData(oldp+2250,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_101),272);
        bufp->chgWData(oldp+2259,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_102),272);
        bufp->chgWData(oldp+2268,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_103),272);
        bufp->chgWData(oldp+2277,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_104),272);
        bufp->chgWData(oldp+2286,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_105),272);
        bufp->chgWData(oldp+2295,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_106),272);
        bufp->chgWData(oldp+2304,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_107),272);
        bufp->chgWData(oldp+2313,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_108),272);
        bufp->chgWData(oldp+2322,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_109),272);
        bufp->chgWData(oldp+2331,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_110),272);
        bufp->chgWData(oldp+2340,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_111),272);
        bufp->chgWData(oldp+2349,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_112),272);
        bufp->chgWData(oldp+2358,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_113),272);
        bufp->chgWData(oldp+2367,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_114),272);
        bufp->chgWData(oldp+2376,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_115),272);
        bufp->chgWData(oldp+2385,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_116),272);
        bufp->chgWData(oldp+2394,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_117),272);
        bufp->chgWData(oldp+2403,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_118),272);
        bufp->chgWData(oldp+2412,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_119),272);
        bufp->chgWData(oldp+2421,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_120),272);
        bufp->chgWData(oldp+2430,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_121),272);
        bufp->chgWData(oldp+2439,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_122),272);
        bufp->chgWData(oldp+2448,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_123),272);
        bufp->chgWData(oldp+2457,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_124),272);
        bufp->chgWData(oldp+2466,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_125),272);
        bufp->chgWData(oldp+2475,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_126),272);
        bufp->chgWData(oldp+2484,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_127),272);
        bufp->chgWData(oldp+2493,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_128),272);
        bufp->chgWData(oldp+2502,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_129),272);
        bufp->chgWData(oldp+2511,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_130),272);
        bufp->chgWData(oldp+2520,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_131),272);
        bufp->chgWData(oldp+2529,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_132),272);
        bufp->chgWData(oldp+2538,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_133),272);
        bufp->chgWData(oldp+2547,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_134),272);
        bufp->chgWData(oldp+2556,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_135),272);
        bufp->chgWData(oldp+2565,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_136),272);
        bufp->chgWData(oldp+2574,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_137),272);
        bufp->chgWData(oldp+2583,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_138),272);
        bufp->chgWData(oldp+2592,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_139),272);
        bufp->chgWData(oldp+2601,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_140),272);
        bufp->chgWData(oldp+2610,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_141),272);
        bufp->chgWData(oldp+2619,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_142),272);
        bufp->chgWData(oldp+2628,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_143),272);
        bufp->chgWData(oldp+2637,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_144),272);
        bufp->chgWData(oldp+2646,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_145),272);
        bufp->chgWData(oldp+2655,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_146),272);
        bufp->chgWData(oldp+2664,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_147),272);
        bufp->chgWData(oldp+2673,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_148),272);
        bufp->chgWData(oldp+2682,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_149),272);
        bufp->chgWData(oldp+2691,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_150),272);
        bufp->chgWData(oldp+2700,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_151),272);
        bufp->chgWData(oldp+2709,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_152),272);
        bufp->chgWData(oldp+2718,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_153),272);
        bufp->chgWData(oldp+2727,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_154),272);
        bufp->chgWData(oldp+2736,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_155),272);
        bufp->chgWData(oldp+2745,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_156),272);
        bufp->chgWData(oldp+2754,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_157),272);
        bufp->chgWData(oldp+2763,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_158),272);
        bufp->chgWData(oldp+2772,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_159),272);
        bufp->chgWData(oldp+2781,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_160),272);
        bufp->chgWData(oldp+2790,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_161),272);
        bufp->chgWData(oldp+2799,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_162),272);
        bufp->chgWData(oldp+2808,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_163),272);
        bufp->chgWData(oldp+2817,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_164),272);
        bufp->chgWData(oldp+2826,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_165),272);
        bufp->chgWData(oldp+2835,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_166),272);
        bufp->chgWData(oldp+2844,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_167),272);
        bufp->chgWData(oldp+2853,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_168),272);
        bufp->chgWData(oldp+2862,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_169),272);
        bufp->chgWData(oldp+2871,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_170),272);
        bufp->chgWData(oldp+2880,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_171),272);
        bufp->chgWData(oldp+2889,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_172),272);
        bufp->chgWData(oldp+2898,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_173),272);
        bufp->chgWData(oldp+2907,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_174),272);
        bufp->chgWData(oldp+2916,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_175),272);
        bufp->chgWData(oldp+2925,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_176),272);
        bufp->chgWData(oldp+2934,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_177),272);
        bufp->chgWData(oldp+2943,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_178),272);
        bufp->chgWData(oldp+2952,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_179),272);
        bufp->chgWData(oldp+2961,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_180),272);
        bufp->chgWData(oldp+2970,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_181),272);
        bufp->chgWData(oldp+2979,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_182),272);
        bufp->chgWData(oldp+2988,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_183),272);
        bufp->chgWData(oldp+2997,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_184),272);
        bufp->chgWData(oldp+3006,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_185),272);
        bufp->chgWData(oldp+3015,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_186),272);
        bufp->chgWData(oldp+3024,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_187),272);
        bufp->chgWData(oldp+3033,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_188),272);
        bufp->chgWData(oldp+3042,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_189),272);
        bufp->chgWData(oldp+3051,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_190),272);
        bufp->chgWData(oldp+3060,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_191),272);
        bufp->chgWData(oldp+3069,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_192),272);
        bufp->chgWData(oldp+3078,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_193),272);
        bufp->chgWData(oldp+3087,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_194),272);
        bufp->chgWData(oldp+3096,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_195),272);
        bufp->chgWData(oldp+3105,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_196),272);
        bufp->chgWData(oldp+3114,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_197),272);
        bufp->chgWData(oldp+3123,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_198),272);
        bufp->chgWData(oldp+3132,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_199),272);
        bufp->chgWData(oldp+3141,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_200),272);
        bufp->chgWData(oldp+3150,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_201),272);
        bufp->chgWData(oldp+3159,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_202),272);
        bufp->chgWData(oldp+3168,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_203),272);
        bufp->chgWData(oldp+3177,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_204),272);
        bufp->chgWData(oldp+3186,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_205),272);
        bufp->chgWData(oldp+3195,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_206),272);
        bufp->chgWData(oldp+3204,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_207),272);
        bufp->chgWData(oldp+3213,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_208),272);
        bufp->chgWData(oldp+3222,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_209),272);
        bufp->chgWData(oldp+3231,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_210),272);
        bufp->chgWData(oldp+3240,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_211),272);
        bufp->chgWData(oldp+3249,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_212),272);
        bufp->chgWData(oldp+3258,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_213),272);
        bufp->chgWData(oldp+3267,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_214),272);
        bufp->chgWData(oldp+3276,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_215),272);
        bufp->chgWData(oldp+3285,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_216),272);
        bufp->chgWData(oldp+3294,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_217),272);
        bufp->chgWData(oldp+3303,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_218),272);
        bufp->chgWData(oldp+3312,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_219),272);
        bufp->chgWData(oldp+3321,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_220),272);
        bufp->chgWData(oldp+3330,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_221),272);
        bufp->chgWData(oldp+3339,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_222),272);
        bufp->chgWData(oldp+3348,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_223),272);
        bufp->chgWData(oldp+3357,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_224),272);
        bufp->chgWData(oldp+3366,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_225),272);
        bufp->chgWData(oldp+3375,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_226),272);
        bufp->chgWData(oldp+3384,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_227),272);
        bufp->chgWData(oldp+3393,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_228),272);
        bufp->chgWData(oldp+3402,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_229),272);
        bufp->chgWData(oldp+3411,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_230),272);
        bufp->chgWData(oldp+3420,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_231),272);
        bufp->chgWData(oldp+3429,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_232),272);
        bufp->chgWData(oldp+3438,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_233),272);
        bufp->chgWData(oldp+3447,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_234),272);
        bufp->chgWData(oldp+3456,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_235),272);
        bufp->chgWData(oldp+3465,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_236),272);
        bufp->chgWData(oldp+3474,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_237),272);
        bufp->chgWData(oldp+3483,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_238),272);
        bufp->chgWData(oldp+3492,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_239),272);
        bufp->chgWData(oldp+3501,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_240),272);
        bufp->chgWData(oldp+3510,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_241),272);
        bufp->chgWData(oldp+3519,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_242),272);
        bufp->chgWData(oldp+3528,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_243),272);
        bufp->chgWData(oldp+3537,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_244),272);
        bufp->chgWData(oldp+3546,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_245),272);
        bufp->chgWData(oldp+3555,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_246),272);
        bufp->chgWData(oldp+3564,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_247),272);
        bufp->chgWData(oldp+3573,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_248),272);
        bufp->chgWData(oldp+3582,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_249),272);
        bufp->chgWData(oldp+3591,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_250),272);
        bufp->chgWData(oldp+3600,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_251),272);
        bufp->chgWData(oldp+3609,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_252),272);
        bufp->chgWData(oldp+3618,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_253),272);
        bufp->chgWData(oldp+3627,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_254),272);
        bufp->chgWData(oldp+3636,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_255),272);
        bufp->chgWData(oldp+3645,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_0),272);
        bufp->chgWData(oldp+3654,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_1),272);
        bufp->chgWData(oldp+3663,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_2),272);
        bufp->chgWData(oldp+3672,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_3),272);
        bufp->chgWData(oldp+3681,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_4),272);
        bufp->chgWData(oldp+3690,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_5),272);
        bufp->chgWData(oldp+3699,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_6),272);
        bufp->chgWData(oldp+3708,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_7),272);
        bufp->chgWData(oldp+3717,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_8),272);
        bufp->chgWData(oldp+3726,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_9),272);
        bufp->chgWData(oldp+3735,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_10),272);
        bufp->chgWData(oldp+3744,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_11),272);
        bufp->chgWData(oldp+3753,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_12),272);
        bufp->chgWData(oldp+3762,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_13),272);
        bufp->chgWData(oldp+3771,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_14),272);
        bufp->chgWData(oldp+3780,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_15),272);
        bufp->chgWData(oldp+3789,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_16),272);
        bufp->chgWData(oldp+3798,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_17),272);
        bufp->chgWData(oldp+3807,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_18),272);
        bufp->chgWData(oldp+3816,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_19),272);
        bufp->chgWData(oldp+3825,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_20),272);
        bufp->chgWData(oldp+3834,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_21),272);
        bufp->chgWData(oldp+3843,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_22),272);
        bufp->chgWData(oldp+3852,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_23),272);
        bufp->chgWData(oldp+3861,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_24),272);
        bufp->chgWData(oldp+3870,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_25),272);
        bufp->chgWData(oldp+3879,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_26),272);
        bufp->chgWData(oldp+3888,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_27),272);
        bufp->chgWData(oldp+3897,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_28),272);
        bufp->chgWData(oldp+3906,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_29),272);
        bufp->chgWData(oldp+3915,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_30),272);
        bufp->chgWData(oldp+3924,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_31),272);
        bufp->chgWData(oldp+3933,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_32),272);
        bufp->chgWData(oldp+3942,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_33),272);
        bufp->chgWData(oldp+3951,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_34),272);
        bufp->chgWData(oldp+3960,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_35),272);
        bufp->chgWData(oldp+3969,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_36),272);
        bufp->chgWData(oldp+3978,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_37),272);
        bufp->chgWData(oldp+3987,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_38),272);
        bufp->chgWData(oldp+3996,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_39),272);
        bufp->chgWData(oldp+4005,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_40),272);
        bufp->chgWData(oldp+4014,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_41),272);
        bufp->chgWData(oldp+4023,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_42),272);
        bufp->chgWData(oldp+4032,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_43),272);
        bufp->chgWData(oldp+4041,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_44),272);
        bufp->chgWData(oldp+4050,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_45),272);
        bufp->chgWData(oldp+4059,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_46),272);
        bufp->chgWData(oldp+4068,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_47),272);
        bufp->chgWData(oldp+4077,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_48),272);
        bufp->chgWData(oldp+4086,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_49),272);
        bufp->chgWData(oldp+4095,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_50),272);
        bufp->chgWData(oldp+4104,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_51),272);
        bufp->chgWData(oldp+4113,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_52),272);
        bufp->chgWData(oldp+4122,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_53),272);
        bufp->chgWData(oldp+4131,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_54),272);
        bufp->chgWData(oldp+4140,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_55),272);
        bufp->chgWData(oldp+4149,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_56),272);
        bufp->chgWData(oldp+4158,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_57),272);
        bufp->chgWData(oldp+4167,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_58),272);
        bufp->chgWData(oldp+4176,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_59),272);
        bufp->chgWData(oldp+4185,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_60),272);
        bufp->chgWData(oldp+4194,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_61),272);
        bufp->chgWData(oldp+4203,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_62),272);
        bufp->chgWData(oldp+4212,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_63),272);
        bufp->chgWData(oldp+4221,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_64),272);
        bufp->chgWData(oldp+4230,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_65),272);
        bufp->chgWData(oldp+4239,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_66),272);
        bufp->chgWData(oldp+4248,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_67),272);
        bufp->chgWData(oldp+4257,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_68),272);
        bufp->chgWData(oldp+4266,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_69),272);
        bufp->chgWData(oldp+4275,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_70),272);
        bufp->chgWData(oldp+4284,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_71),272);
        bufp->chgWData(oldp+4293,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_72),272);
        bufp->chgWData(oldp+4302,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_73),272);
        bufp->chgWData(oldp+4311,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_74),272);
        bufp->chgWData(oldp+4320,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_75),272);
        bufp->chgWData(oldp+4329,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_76),272);
        bufp->chgWData(oldp+4338,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_77),272);
        bufp->chgWData(oldp+4347,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_78),272);
        bufp->chgWData(oldp+4356,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_79),272);
        bufp->chgWData(oldp+4365,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_80),272);
        bufp->chgWData(oldp+4374,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_81),272);
        bufp->chgWData(oldp+4383,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_82),272);
        bufp->chgWData(oldp+4392,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_83),272);
        bufp->chgWData(oldp+4401,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_84),272);
        bufp->chgWData(oldp+4410,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_85),272);
        bufp->chgWData(oldp+4419,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_86),272);
        bufp->chgWData(oldp+4428,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_87),272);
        bufp->chgWData(oldp+4437,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_88),272);
        bufp->chgWData(oldp+4446,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_89),272);
        bufp->chgWData(oldp+4455,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_90),272);
        bufp->chgWData(oldp+4464,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_91),272);
        bufp->chgWData(oldp+4473,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_92),272);
        bufp->chgWData(oldp+4482,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_93),272);
        bufp->chgWData(oldp+4491,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_94),272);
        bufp->chgWData(oldp+4500,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_95),272);
        bufp->chgWData(oldp+4509,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_96),272);
        bufp->chgWData(oldp+4518,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_97),272);
        bufp->chgWData(oldp+4527,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_98),272);
        bufp->chgWData(oldp+4536,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_99),272);
        bufp->chgWData(oldp+4545,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_100),272);
        bufp->chgWData(oldp+4554,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_101),272);
        bufp->chgWData(oldp+4563,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_102),272);
        bufp->chgWData(oldp+4572,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_103),272);
        bufp->chgWData(oldp+4581,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_104),272);
        bufp->chgWData(oldp+4590,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_105),272);
        bufp->chgWData(oldp+4599,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_106),272);
        bufp->chgWData(oldp+4608,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_107),272);
        bufp->chgWData(oldp+4617,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_108),272);
        bufp->chgWData(oldp+4626,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_109),272);
        bufp->chgWData(oldp+4635,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_110),272);
        bufp->chgWData(oldp+4644,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_111),272);
        bufp->chgWData(oldp+4653,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_112),272);
        bufp->chgWData(oldp+4662,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_113),272);
        bufp->chgWData(oldp+4671,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_114),272);
        bufp->chgWData(oldp+4680,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_115),272);
        bufp->chgWData(oldp+4689,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_116),272);
        bufp->chgWData(oldp+4698,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_117),272);
        bufp->chgWData(oldp+4707,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_118),272);
        bufp->chgWData(oldp+4716,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_119),272);
        bufp->chgWData(oldp+4725,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_120),272);
        bufp->chgWData(oldp+4734,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_121),272);
        bufp->chgWData(oldp+4743,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_122),272);
        bufp->chgWData(oldp+4752,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_123),272);
        bufp->chgWData(oldp+4761,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_124),272);
        bufp->chgWData(oldp+4770,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_125),272);
        bufp->chgWData(oldp+4779,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_126),272);
        bufp->chgWData(oldp+4788,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_127),272);
        bufp->chgWData(oldp+4797,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_128),272);
        bufp->chgWData(oldp+4806,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_129),272);
        bufp->chgWData(oldp+4815,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_130),272);
        bufp->chgWData(oldp+4824,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_131),272);
        bufp->chgWData(oldp+4833,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_132),272);
        bufp->chgWData(oldp+4842,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_133),272);
        bufp->chgWData(oldp+4851,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_134),272);
        bufp->chgWData(oldp+4860,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_135),272);
        bufp->chgWData(oldp+4869,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_136),272);
        bufp->chgWData(oldp+4878,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_137),272);
        bufp->chgWData(oldp+4887,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_138),272);
        bufp->chgWData(oldp+4896,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_139),272);
        bufp->chgWData(oldp+4905,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_140),272);
        bufp->chgWData(oldp+4914,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_141),272);
        bufp->chgWData(oldp+4923,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_142),272);
        bufp->chgWData(oldp+4932,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_143),272);
        bufp->chgWData(oldp+4941,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_144),272);
        bufp->chgWData(oldp+4950,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_145),272);
        bufp->chgWData(oldp+4959,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_146),272);
        bufp->chgWData(oldp+4968,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_147),272);
        bufp->chgWData(oldp+4977,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_148),272);
        bufp->chgWData(oldp+4986,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_149),272);
        bufp->chgWData(oldp+4995,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_150),272);
        bufp->chgWData(oldp+5004,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_151),272);
        bufp->chgWData(oldp+5013,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_152),272);
        bufp->chgWData(oldp+5022,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_153),272);
        bufp->chgWData(oldp+5031,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_154),272);
        bufp->chgWData(oldp+5040,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_155),272);
        bufp->chgWData(oldp+5049,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_156),272);
        bufp->chgWData(oldp+5058,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_157),272);
        bufp->chgWData(oldp+5067,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_158),272);
        bufp->chgWData(oldp+5076,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_159),272);
        bufp->chgWData(oldp+5085,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_160),272);
        bufp->chgWData(oldp+5094,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_161),272);
        bufp->chgWData(oldp+5103,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_162),272);
        bufp->chgWData(oldp+5112,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_163),272);
        bufp->chgWData(oldp+5121,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_164),272);
        bufp->chgWData(oldp+5130,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_165),272);
        bufp->chgWData(oldp+5139,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_166),272);
        bufp->chgWData(oldp+5148,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_167),272);
        bufp->chgWData(oldp+5157,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_168),272);
        bufp->chgWData(oldp+5166,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_169),272);
        bufp->chgWData(oldp+5175,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_170),272);
        bufp->chgWData(oldp+5184,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_171),272);
        bufp->chgWData(oldp+5193,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_172),272);
        bufp->chgWData(oldp+5202,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_173),272);
        bufp->chgWData(oldp+5211,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_174),272);
        bufp->chgWData(oldp+5220,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_175),272);
        bufp->chgWData(oldp+5229,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_176),272);
        bufp->chgWData(oldp+5238,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_177),272);
        bufp->chgWData(oldp+5247,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_178),272);
        bufp->chgWData(oldp+5256,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_179),272);
        bufp->chgWData(oldp+5265,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_180),272);
        bufp->chgWData(oldp+5274,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_181),272);
        bufp->chgWData(oldp+5283,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_182),272);
        bufp->chgWData(oldp+5292,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_183),272);
        bufp->chgWData(oldp+5301,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_184),272);
        bufp->chgWData(oldp+5310,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_185),272);
        bufp->chgWData(oldp+5319,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_186),272);
        bufp->chgWData(oldp+5328,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_187),272);
        bufp->chgWData(oldp+5337,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_188),272);
        bufp->chgWData(oldp+5346,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_189),272);
        bufp->chgWData(oldp+5355,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_190),272);
        bufp->chgWData(oldp+5364,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_191),272);
        bufp->chgWData(oldp+5373,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_192),272);
        bufp->chgWData(oldp+5382,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_193),272);
        bufp->chgWData(oldp+5391,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_194),272);
        bufp->chgWData(oldp+5400,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_195),272);
        bufp->chgWData(oldp+5409,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_196),272);
        bufp->chgWData(oldp+5418,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_197),272);
        bufp->chgWData(oldp+5427,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_198),272);
        bufp->chgWData(oldp+5436,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_199),272);
        bufp->chgWData(oldp+5445,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_200),272);
        bufp->chgWData(oldp+5454,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_201),272);
        bufp->chgWData(oldp+5463,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_202),272);
        bufp->chgWData(oldp+5472,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_203),272);
        bufp->chgWData(oldp+5481,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_204),272);
        bufp->chgWData(oldp+5490,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_205),272);
        bufp->chgWData(oldp+5499,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_206),272);
        bufp->chgWData(oldp+5508,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_207),272);
        bufp->chgWData(oldp+5517,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_208),272);
        bufp->chgWData(oldp+5526,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_209),272);
        bufp->chgWData(oldp+5535,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_210),272);
        bufp->chgWData(oldp+5544,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_211),272);
        bufp->chgWData(oldp+5553,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_212),272);
        bufp->chgWData(oldp+5562,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_213),272);
        bufp->chgWData(oldp+5571,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_214),272);
        bufp->chgWData(oldp+5580,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_215),272);
        bufp->chgWData(oldp+5589,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_216),272);
        bufp->chgWData(oldp+5598,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_217),272);
        bufp->chgWData(oldp+5607,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_218),272);
        bufp->chgWData(oldp+5616,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_219),272);
        bufp->chgWData(oldp+5625,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_220),272);
        bufp->chgWData(oldp+5634,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_221),272);
        bufp->chgWData(oldp+5643,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_222),272);
        bufp->chgWData(oldp+5652,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_223),272);
        bufp->chgWData(oldp+5661,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_224),272);
        bufp->chgWData(oldp+5670,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_225),272);
        bufp->chgWData(oldp+5679,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_226),272);
        bufp->chgWData(oldp+5688,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_227),272);
        bufp->chgWData(oldp+5697,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_228),272);
        bufp->chgWData(oldp+5706,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_229),272);
        bufp->chgWData(oldp+5715,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_230),272);
        bufp->chgWData(oldp+5724,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_231),272);
        bufp->chgWData(oldp+5733,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_232),272);
        bufp->chgWData(oldp+5742,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_233),272);
        bufp->chgWData(oldp+5751,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_234),272);
        bufp->chgWData(oldp+5760,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_235),272);
        bufp->chgWData(oldp+5769,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_236),272);
        bufp->chgWData(oldp+5778,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_237),272);
        bufp->chgWData(oldp+5787,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_238),272);
        bufp->chgWData(oldp+5796,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_239),272);
        bufp->chgWData(oldp+5805,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_240),272);
        bufp->chgWData(oldp+5814,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_241),272);
        bufp->chgWData(oldp+5823,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_242),272);
        bufp->chgWData(oldp+5832,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_243),272);
        bufp->chgWData(oldp+5841,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_244),272);
        bufp->chgWData(oldp+5850,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_245),272);
        bufp->chgWData(oldp+5859,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_246),272);
        bufp->chgWData(oldp+5868,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_247),272);
        bufp->chgWData(oldp+5877,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_248),272);
        bufp->chgWData(oldp+5886,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_249),272);
        bufp->chgWData(oldp+5895,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_250),272);
        bufp->chgWData(oldp+5904,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_251),272);
        bufp->chgWData(oldp+5913,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_252),272);
        bufp->chgWData(oldp+5922,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_253),272);
        bufp->chgWData(oldp+5931,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_254),272);
        bufp->chgWData(oldp+5940,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_255),272);
        bufp->chgWData(oldp+5949,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_0),272);
        bufp->chgWData(oldp+5958,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_1),272);
        bufp->chgWData(oldp+5967,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_2),272);
        bufp->chgWData(oldp+5976,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_3),272);
        bufp->chgWData(oldp+5985,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_4),272);
        bufp->chgWData(oldp+5994,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_5),272);
        bufp->chgWData(oldp+6003,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_6),272);
        bufp->chgWData(oldp+6012,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_7),272);
        bufp->chgWData(oldp+6021,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_8),272);
        bufp->chgWData(oldp+6030,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_9),272);
        bufp->chgWData(oldp+6039,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_10),272);
        bufp->chgWData(oldp+6048,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_11),272);
        bufp->chgWData(oldp+6057,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_12),272);
        bufp->chgWData(oldp+6066,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_13),272);
        bufp->chgWData(oldp+6075,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_14),272);
        bufp->chgWData(oldp+6084,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_15),272);
        bufp->chgWData(oldp+6093,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_16),272);
        bufp->chgWData(oldp+6102,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_17),272);
        bufp->chgWData(oldp+6111,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_18),272);
        bufp->chgWData(oldp+6120,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_19),272);
        bufp->chgWData(oldp+6129,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_20),272);
        bufp->chgWData(oldp+6138,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_21),272);
        bufp->chgWData(oldp+6147,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_22),272);
        bufp->chgWData(oldp+6156,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_23),272);
        bufp->chgWData(oldp+6165,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_24),272);
        bufp->chgWData(oldp+6174,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_25),272);
        bufp->chgWData(oldp+6183,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_26),272);
        bufp->chgWData(oldp+6192,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_27),272);
        bufp->chgWData(oldp+6201,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_28),272);
        bufp->chgWData(oldp+6210,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_29),272);
        bufp->chgWData(oldp+6219,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_30),272);
        bufp->chgWData(oldp+6228,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_31),272);
        bufp->chgWData(oldp+6237,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_32),272);
        bufp->chgWData(oldp+6246,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_33),272);
        bufp->chgWData(oldp+6255,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_34),272);
        bufp->chgWData(oldp+6264,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_35),272);
        bufp->chgWData(oldp+6273,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_36),272);
        bufp->chgWData(oldp+6282,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_37),272);
        bufp->chgWData(oldp+6291,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_38),272);
        bufp->chgWData(oldp+6300,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_39),272);
        bufp->chgWData(oldp+6309,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_40),272);
        bufp->chgWData(oldp+6318,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_41),272);
        bufp->chgWData(oldp+6327,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_42),272);
        bufp->chgWData(oldp+6336,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_43),272);
        bufp->chgWData(oldp+6345,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_44),272);
        bufp->chgWData(oldp+6354,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_45),272);
        bufp->chgWData(oldp+6363,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_46),272);
        bufp->chgWData(oldp+6372,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_47),272);
        bufp->chgWData(oldp+6381,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_48),272);
        bufp->chgWData(oldp+6390,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_49),272);
        bufp->chgWData(oldp+6399,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_50),272);
        bufp->chgWData(oldp+6408,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_51),272);
        bufp->chgWData(oldp+6417,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_52),272);
        bufp->chgWData(oldp+6426,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_53),272);
        bufp->chgWData(oldp+6435,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_54),272);
        bufp->chgWData(oldp+6444,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_55),272);
        bufp->chgWData(oldp+6453,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_56),272);
        bufp->chgWData(oldp+6462,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_57),272);
        bufp->chgWData(oldp+6471,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_58),272);
        bufp->chgWData(oldp+6480,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_59),272);
        bufp->chgWData(oldp+6489,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_60),272);
        bufp->chgWData(oldp+6498,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_61),272);
        bufp->chgWData(oldp+6507,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_62),272);
        bufp->chgWData(oldp+6516,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_63),272);
        bufp->chgWData(oldp+6525,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_64),272);
        bufp->chgWData(oldp+6534,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_65),272);
        bufp->chgWData(oldp+6543,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_66),272);
        bufp->chgWData(oldp+6552,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_67),272);
        bufp->chgWData(oldp+6561,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_68),272);
        bufp->chgWData(oldp+6570,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_69),272);
        bufp->chgWData(oldp+6579,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_70),272);
        bufp->chgWData(oldp+6588,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_71),272);
        bufp->chgWData(oldp+6597,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_72),272);
        bufp->chgWData(oldp+6606,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_73),272);
        bufp->chgWData(oldp+6615,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_74),272);
        bufp->chgWData(oldp+6624,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_75),272);
        bufp->chgWData(oldp+6633,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_76),272);
        bufp->chgWData(oldp+6642,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_77),272);
        bufp->chgWData(oldp+6651,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_78),272);
        bufp->chgWData(oldp+6660,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_79),272);
        bufp->chgWData(oldp+6669,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_80),272);
        bufp->chgWData(oldp+6678,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_81),272);
        bufp->chgWData(oldp+6687,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_82),272);
        bufp->chgWData(oldp+6696,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_83),272);
        bufp->chgWData(oldp+6705,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_84),272);
        bufp->chgWData(oldp+6714,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_85),272);
        bufp->chgWData(oldp+6723,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_86),272);
        bufp->chgWData(oldp+6732,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_87),272);
        bufp->chgWData(oldp+6741,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_88),272);
        bufp->chgWData(oldp+6750,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_89),272);
        bufp->chgWData(oldp+6759,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_90),272);
        bufp->chgWData(oldp+6768,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_91),272);
        bufp->chgWData(oldp+6777,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_92),272);
        bufp->chgWData(oldp+6786,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_93),272);
        bufp->chgWData(oldp+6795,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_94),272);
        bufp->chgWData(oldp+6804,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_95),272);
        bufp->chgWData(oldp+6813,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_96),272);
        bufp->chgWData(oldp+6822,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_97),272);
        bufp->chgWData(oldp+6831,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_98),272);
        bufp->chgWData(oldp+6840,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_99),272);
        bufp->chgWData(oldp+6849,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_100),272);
        bufp->chgWData(oldp+6858,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_101),272);
        bufp->chgWData(oldp+6867,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_102),272);
        bufp->chgWData(oldp+6876,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_103),272);
        bufp->chgWData(oldp+6885,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_104),272);
        bufp->chgWData(oldp+6894,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_105),272);
        bufp->chgWData(oldp+6903,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_106),272);
        bufp->chgWData(oldp+6912,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_107),272);
        bufp->chgWData(oldp+6921,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_108),272);
        bufp->chgWData(oldp+6930,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_109),272);
        bufp->chgWData(oldp+6939,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_110),272);
        bufp->chgWData(oldp+6948,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_111),272);
        bufp->chgWData(oldp+6957,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_112),272);
        bufp->chgWData(oldp+6966,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_113),272);
        bufp->chgWData(oldp+6975,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_114),272);
        bufp->chgWData(oldp+6984,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_115),272);
        bufp->chgWData(oldp+6993,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_116),272);
        bufp->chgWData(oldp+7002,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_117),272);
        bufp->chgWData(oldp+7011,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_118),272);
        bufp->chgWData(oldp+7020,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_119),272);
        bufp->chgWData(oldp+7029,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_120),272);
        bufp->chgWData(oldp+7038,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_121),272);
        bufp->chgWData(oldp+7047,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_122),272);
        bufp->chgWData(oldp+7056,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_123),272);
        bufp->chgWData(oldp+7065,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_124),272);
        bufp->chgWData(oldp+7074,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_125),272);
        bufp->chgWData(oldp+7083,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_126),272);
        bufp->chgWData(oldp+7092,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_127),272);
        bufp->chgWData(oldp+7101,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_128),272);
        bufp->chgWData(oldp+7110,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_129),272);
        bufp->chgWData(oldp+7119,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_130),272);
        bufp->chgWData(oldp+7128,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_131),272);
        bufp->chgWData(oldp+7137,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_132),272);
        bufp->chgWData(oldp+7146,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_133),272);
        bufp->chgWData(oldp+7155,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_134),272);
        bufp->chgWData(oldp+7164,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_135),272);
        bufp->chgWData(oldp+7173,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_136),272);
        bufp->chgWData(oldp+7182,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_137),272);
        bufp->chgWData(oldp+7191,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_138),272);
        bufp->chgWData(oldp+7200,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_139),272);
        bufp->chgWData(oldp+7209,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_140),272);
        bufp->chgWData(oldp+7218,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_141),272);
        bufp->chgWData(oldp+7227,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_142),272);
        bufp->chgWData(oldp+7236,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_143),272);
        bufp->chgWData(oldp+7245,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_144),272);
        bufp->chgWData(oldp+7254,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_145),272);
        bufp->chgWData(oldp+7263,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_146),272);
        bufp->chgWData(oldp+7272,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_147),272);
        bufp->chgWData(oldp+7281,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_148),272);
        bufp->chgWData(oldp+7290,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_149),272);
        bufp->chgWData(oldp+7299,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_150),272);
        bufp->chgWData(oldp+7308,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_151),272);
        bufp->chgWData(oldp+7317,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_152),272);
        bufp->chgWData(oldp+7326,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_153),272);
        bufp->chgWData(oldp+7335,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_154),272);
        bufp->chgWData(oldp+7344,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_155),272);
        bufp->chgWData(oldp+7353,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_156),272);
        bufp->chgWData(oldp+7362,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_157),272);
        bufp->chgWData(oldp+7371,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_158),272);
        bufp->chgWData(oldp+7380,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_159),272);
        bufp->chgWData(oldp+7389,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_160),272);
        bufp->chgWData(oldp+7398,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_161),272);
        bufp->chgWData(oldp+7407,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_162),272);
        bufp->chgWData(oldp+7416,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_163),272);
        bufp->chgWData(oldp+7425,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_164),272);
        bufp->chgWData(oldp+7434,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_165),272);
        bufp->chgWData(oldp+7443,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_166),272);
        bufp->chgWData(oldp+7452,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_167),272);
        bufp->chgWData(oldp+7461,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_168),272);
        bufp->chgWData(oldp+7470,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_169),272);
        bufp->chgWData(oldp+7479,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_170),272);
        bufp->chgWData(oldp+7488,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_171),272);
        bufp->chgWData(oldp+7497,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_172),272);
        bufp->chgWData(oldp+7506,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_173),272);
        bufp->chgWData(oldp+7515,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_174),272);
        bufp->chgWData(oldp+7524,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_175),272);
        bufp->chgWData(oldp+7533,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_176),272);
        bufp->chgWData(oldp+7542,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_177),272);
        bufp->chgWData(oldp+7551,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_178),272);
        bufp->chgWData(oldp+7560,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_179),272);
        bufp->chgWData(oldp+7569,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_180),272);
        bufp->chgWData(oldp+7578,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_181),272);
        bufp->chgWData(oldp+7587,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_182),272);
        bufp->chgWData(oldp+7596,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_183),272);
        bufp->chgWData(oldp+7605,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_184),272);
        bufp->chgWData(oldp+7614,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_185),272);
        bufp->chgWData(oldp+7623,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_186),272);
        bufp->chgWData(oldp+7632,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_187),272);
        bufp->chgWData(oldp+7641,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_188),272);
        bufp->chgWData(oldp+7650,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_189),272);
        bufp->chgWData(oldp+7659,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_190),272);
        bufp->chgWData(oldp+7668,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_191),272);
        bufp->chgWData(oldp+7677,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_192),272);
        bufp->chgWData(oldp+7686,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_193),272);
        bufp->chgWData(oldp+7695,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_194),272);
        bufp->chgWData(oldp+7704,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_195),272);
        bufp->chgWData(oldp+7713,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_196),272);
        bufp->chgWData(oldp+7722,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_197),272);
        bufp->chgWData(oldp+7731,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_198),272);
        bufp->chgWData(oldp+7740,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_199),272);
        bufp->chgWData(oldp+7749,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_200),272);
        bufp->chgWData(oldp+7758,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_201),272);
        bufp->chgWData(oldp+7767,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_202),272);
        bufp->chgWData(oldp+7776,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_203),272);
        bufp->chgWData(oldp+7785,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_204),272);
        bufp->chgWData(oldp+7794,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_205),272);
        bufp->chgWData(oldp+7803,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_206),272);
        bufp->chgWData(oldp+7812,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_207),272);
        bufp->chgWData(oldp+7821,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_208),272);
        bufp->chgWData(oldp+7830,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_209),272);
        bufp->chgWData(oldp+7839,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_210),272);
        bufp->chgWData(oldp+7848,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_211),272);
        bufp->chgWData(oldp+7857,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_212),272);
        bufp->chgWData(oldp+7866,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_213),272);
        bufp->chgWData(oldp+7875,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_214),272);
        bufp->chgWData(oldp+7884,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_215),272);
        bufp->chgWData(oldp+7893,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_216),272);
        bufp->chgWData(oldp+7902,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_217),272);
        bufp->chgWData(oldp+7911,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_218),272);
        bufp->chgWData(oldp+7920,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_219),272);
        bufp->chgWData(oldp+7929,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_220),272);
        bufp->chgWData(oldp+7938,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_221),272);
        bufp->chgWData(oldp+7947,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_222),272);
        bufp->chgWData(oldp+7956,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_223),272);
        bufp->chgWData(oldp+7965,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_224),272);
        bufp->chgWData(oldp+7974,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_225),272);
        bufp->chgWData(oldp+7983,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_226),272);
        bufp->chgWData(oldp+7992,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_227),272);
        bufp->chgWData(oldp+8001,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_228),272);
        bufp->chgWData(oldp+8010,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_229),272);
        bufp->chgWData(oldp+8019,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_230),272);
        bufp->chgWData(oldp+8028,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_231),272);
        bufp->chgWData(oldp+8037,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_232),272);
        bufp->chgWData(oldp+8046,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_233),272);
        bufp->chgWData(oldp+8055,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_234),272);
        bufp->chgWData(oldp+8064,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_235),272);
        bufp->chgWData(oldp+8073,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_236),272);
        bufp->chgWData(oldp+8082,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_237),272);
        bufp->chgWData(oldp+8091,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_238),272);
        bufp->chgWData(oldp+8100,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_239),272);
        bufp->chgWData(oldp+8109,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_240),272);
        bufp->chgWData(oldp+8118,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_241),272);
        bufp->chgWData(oldp+8127,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_242),272);
        bufp->chgWData(oldp+8136,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_243),272);
        bufp->chgWData(oldp+8145,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_244),272);
        bufp->chgWData(oldp+8154,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_245),272);
        bufp->chgWData(oldp+8163,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_246),272);
        bufp->chgWData(oldp+8172,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_247),272);
        bufp->chgWData(oldp+8181,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_248),272);
        bufp->chgWData(oldp+8190,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_249),272);
        bufp->chgWData(oldp+8199,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_250),272);
        bufp->chgWData(oldp+8208,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_251),272);
        bufp->chgWData(oldp+8217,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_252),272);
        bufp->chgWData(oldp+8226,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_253),272);
        bufp->chgWData(oldp+8235,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_254),272);
        bufp->chgWData(oldp+8244,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_255),272);
        bufp->chgWData(oldp+8253,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_0),272);
        bufp->chgWData(oldp+8262,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_1),272);
        bufp->chgWData(oldp+8271,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_2),272);
        bufp->chgWData(oldp+8280,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_3),272);
        bufp->chgWData(oldp+8289,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_4),272);
        bufp->chgWData(oldp+8298,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_5),272);
        bufp->chgWData(oldp+8307,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_6),272);
        bufp->chgWData(oldp+8316,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_7),272);
        bufp->chgWData(oldp+8325,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_8),272);
        bufp->chgWData(oldp+8334,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_9),272);
        bufp->chgWData(oldp+8343,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_10),272);
        bufp->chgWData(oldp+8352,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_11),272);
        bufp->chgWData(oldp+8361,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_12),272);
        bufp->chgWData(oldp+8370,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_13),272);
        bufp->chgWData(oldp+8379,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_14),272);
        bufp->chgWData(oldp+8388,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_15),272);
        bufp->chgWData(oldp+8397,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_16),272);
        bufp->chgWData(oldp+8406,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_17),272);
        bufp->chgWData(oldp+8415,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_18),272);
        bufp->chgWData(oldp+8424,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_19),272);
        bufp->chgWData(oldp+8433,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_20),272);
        bufp->chgWData(oldp+8442,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_21),272);
        bufp->chgWData(oldp+8451,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_22),272);
        bufp->chgWData(oldp+8460,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_23),272);
        bufp->chgWData(oldp+8469,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_24),272);
        bufp->chgWData(oldp+8478,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_25),272);
        bufp->chgWData(oldp+8487,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_26),272);
        bufp->chgWData(oldp+8496,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_27),272);
        bufp->chgWData(oldp+8505,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_28),272);
        bufp->chgWData(oldp+8514,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_29),272);
        bufp->chgWData(oldp+8523,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_30),272);
        bufp->chgWData(oldp+8532,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_31),272);
        bufp->chgWData(oldp+8541,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_32),272);
        bufp->chgWData(oldp+8550,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_33),272);
        bufp->chgWData(oldp+8559,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_34),272);
        bufp->chgWData(oldp+8568,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_35),272);
        bufp->chgWData(oldp+8577,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_36),272);
        bufp->chgWData(oldp+8586,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_37),272);
        bufp->chgWData(oldp+8595,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_38),272);
        bufp->chgWData(oldp+8604,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_39),272);
        bufp->chgWData(oldp+8613,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_40),272);
        bufp->chgWData(oldp+8622,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_41),272);
        bufp->chgWData(oldp+8631,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_42),272);
        bufp->chgWData(oldp+8640,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_43),272);
        bufp->chgWData(oldp+8649,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_44),272);
        bufp->chgWData(oldp+8658,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_45),272);
        bufp->chgWData(oldp+8667,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_46),272);
        bufp->chgWData(oldp+8676,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_47),272);
        bufp->chgWData(oldp+8685,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_48),272);
        bufp->chgWData(oldp+8694,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_49),272);
        bufp->chgWData(oldp+8703,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_50),272);
        bufp->chgWData(oldp+8712,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_51),272);
        bufp->chgWData(oldp+8721,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_52),272);
        bufp->chgWData(oldp+8730,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_53),272);
        bufp->chgWData(oldp+8739,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_54),272);
        bufp->chgWData(oldp+8748,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_55),272);
        bufp->chgWData(oldp+8757,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_56),272);
        bufp->chgWData(oldp+8766,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_57),272);
        bufp->chgWData(oldp+8775,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_58),272);
        bufp->chgWData(oldp+8784,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_59),272);
        bufp->chgWData(oldp+8793,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_60),272);
        bufp->chgWData(oldp+8802,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_61),272);
        bufp->chgWData(oldp+8811,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_62),272);
        bufp->chgWData(oldp+8820,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_63),272);
        bufp->chgWData(oldp+8829,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_64),272);
        bufp->chgWData(oldp+8838,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_65),272);
        bufp->chgWData(oldp+8847,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_66),272);
        bufp->chgWData(oldp+8856,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_67),272);
        bufp->chgWData(oldp+8865,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_68),272);
        bufp->chgWData(oldp+8874,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_69),272);
        bufp->chgWData(oldp+8883,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_70),272);
        bufp->chgWData(oldp+8892,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_71),272);
        bufp->chgWData(oldp+8901,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_72),272);
        bufp->chgWData(oldp+8910,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_73),272);
        bufp->chgWData(oldp+8919,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_74),272);
        bufp->chgWData(oldp+8928,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_75),272);
        bufp->chgWData(oldp+8937,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_76),272);
        bufp->chgWData(oldp+8946,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_77),272);
        bufp->chgWData(oldp+8955,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_78),272);
        bufp->chgWData(oldp+8964,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_79),272);
        bufp->chgWData(oldp+8973,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_80),272);
        bufp->chgWData(oldp+8982,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_81),272);
        bufp->chgWData(oldp+8991,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_82),272);
        bufp->chgWData(oldp+9000,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_83),272);
        bufp->chgWData(oldp+9009,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_84),272);
        bufp->chgWData(oldp+9018,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_85),272);
        bufp->chgWData(oldp+9027,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_86),272);
        bufp->chgWData(oldp+9036,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_87),272);
        bufp->chgWData(oldp+9045,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_88),272);
        bufp->chgWData(oldp+9054,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_89),272);
        bufp->chgWData(oldp+9063,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_90),272);
        bufp->chgWData(oldp+9072,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_91),272);
        bufp->chgWData(oldp+9081,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_92),272);
        bufp->chgWData(oldp+9090,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_93),272);
        bufp->chgWData(oldp+9099,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_94),272);
        bufp->chgWData(oldp+9108,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_95),272);
        bufp->chgWData(oldp+9117,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_96),272);
        bufp->chgWData(oldp+9126,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_97),272);
        bufp->chgWData(oldp+9135,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_98),272);
        bufp->chgWData(oldp+9144,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_99),272);
        bufp->chgWData(oldp+9153,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_100),272);
        bufp->chgWData(oldp+9162,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_101),272);
        bufp->chgWData(oldp+9171,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_102),272);
        bufp->chgWData(oldp+9180,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_103),272);
        bufp->chgWData(oldp+9189,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_104),272);
        bufp->chgWData(oldp+9198,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_105),272);
        bufp->chgWData(oldp+9207,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_106),272);
        bufp->chgWData(oldp+9216,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_107),272);
        bufp->chgWData(oldp+9225,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_108),272);
        bufp->chgWData(oldp+9234,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_109),272);
        bufp->chgWData(oldp+9243,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_110),272);
        bufp->chgWData(oldp+9252,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_111),272);
        bufp->chgWData(oldp+9261,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_112),272);
        bufp->chgWData(oldp+9270,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_113),272);
        bufp->chgWData(oldp+9279,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_114),272);
        bufp->chgWData(oldp+9288,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_115),272);
        bufp->chgWData(oldp+9297,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_116),272);
        bufp->chgWData(oldp+9306,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_117),272);
        bufp->chgWData(oldp+9315,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_118),272);
        bufp->chgWData(oldp+9324,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_119),272);
        bufp->chgWData(oldp+9333,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_120),272);
        bufp->chgWData(oldp+9342,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_121),272);
        bufp->chgWData(oldp+9351,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_122),272);
        bufp->chgWData(oldp+9360,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_123),272);
        bufp->chgWData(oldp+9369,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_124),272);
        bufp->chgWData(oldp+9378,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_125),272);
        bufp->chgWData(oldp+9387,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_126),272);
        bufp->chgWData(oldp+9396,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_127),272);
        bufp->chgWData(oldp+9405,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_128),272);
        bufp->chgWData(oldp+9414,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_129),272);
        bufp->chgWData(oldp+9423,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_130),272);
        bufp->chgWData(oldp+9432,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_131),272);
        bufp->chgWData(oldp+9441,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_132),272);
        bufp->chgWData(oldp+9450,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_133),272);
        bufp->chgWData(oldp+9459,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_134),272);
        bufp->chgWData(oldp+9468,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_135),272);
        bufp->chgWData(oldp+9477,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_136),272);
        bufp->chgWData(oldp+9486,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_137),272);
        bufp->chgWData(oldp+9495,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_138),272);
        bufp->chgWData(oldp+9504,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_139),272);
        bufp->chgWData(oldp+9513,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_140),272);
        bufp->chgWData(oldp+9522,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_141),272);
        bufp->chgWData(oldp+9531,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_142),272);
        bufp->chgWData(oldp+9540,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_143),272);
        bufp->chgWData(oldp+9549,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_144),272);
        bufp->chgWData(oldp+9558,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_145),272);
        bufp->chgWData(oldp+9567,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_146),272);
        bufp->chgWData(oldp+9576,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_147),272);
        bufp->chgWData(oldp+9585,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_148),272);
        bufp->chgWData(oldp+9594,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_149),272);
        bufp->chgWData(oldp+9603,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_150),272);
        bufp->chgWData(oldp+9612,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_151),272);
        bufp->chgWData(oldp+9621,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_152),272);
        bufp->chgWData(oldp+9630,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_153),272);
        bufp->chgWData(oldp+9639,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_154),272);
        bufp->chgWData(oldp+9648,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_155),272);
        bufp->chgWData(oldp+9657,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_156),272);
        bufp->chgWData(oldp+9666,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_157),272);
        bufp->chgWData(oldp+9675,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_158),272);
        bufp->chgWData(oldp+9684,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_159),272);
        bufp->chgWData(oldp+9693,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_160),272);
        bufp->chgWData(oldp+9702,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_161),272);
        bufp->chgWData(oldp+9711,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_162),272);
        bufp->chgWData(oldp+9720,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_163),272);
        bufp->chgWData(oldp+9729,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_164),272);
        bufp->chgWData(oldp+9738,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_165),272);
        bufp->chgWData(oldp+9747,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_166),272);
        bufp->chgWData(oldp+9756,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_167),272);
        bufp->chgWData(oldp+9765,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_168),272);
        bufp->chgWData(oldp+9774,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_169),272);
        bufp->chgWData(oldp+9783,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_170),272);
        bufp->chgWData(oldp+9792,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_171),272);
        bufp->chgWData(oldp+9801,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_172),272);
        bufp->chgWData(oldp+9810,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_173),272);
        bufp->chgWData(oldp+9819,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_174),272);
        bufp->chgWData(oldp+9828,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_175),272);
        bufp->chgWData(oldp+9837,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_176),272);
        bufp->chgWData(oldp+9846,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_177),272);
        bufp->chgWData(oldp+9855,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_178),272);
        bufp->chgWData(oldp+9864,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_179),272);
        bufp->chgWData(oldp+9873,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_180),272);
        bufp->chgWData(oldp+9882,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_181),272);
        bufp->chgWData(oldp+9891,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_182),272);
        bufp->chgWData(oldp+9900,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_183),272);
        bufp->chgWData(oldp+9909,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_184),272);
        bufp->chgWData(oldp+9918,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_185),272);
        bufp->chgWData(oldp+9927,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_186),272);
        bufp->chgWData(oldp+9936,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_187),272);
        bufp->chgWData(oldp+9945,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_188),272);
        bufp->chgWData(oldp+9954,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_189),272);
        bufp->chgWData(oldp+9963,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_190),272);
        bufp->chgWData(oldp+9972,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_191),272);
        bufp->chgWData(oldp+9981,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_192),272);
        bufp->chgWData(oldp+9990,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_193),272);
        bufp->chgWData(oldp+9999,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_194),272);
        bufp->chgWData(oldp+10008,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_195),272);
        bufp->chgWData(oldp+10017,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_196),272);
        bufp->chgWData(oldp+10026,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_197),272);
        bufp->chgWData(oldp+10035,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_198),272);
        bufp->chgWData(oldp+10044,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_199),272);
        bufp->chgWData(oldp+10053,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_200),272);
        bufp->chgWData(oldp+10062,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_201),272);
        bufp->chgWData(oldp+10071,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_202),272);
        bufp->chgWData(oldp+10080,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_203),272);
        bufp->chgWData(oldp+10089,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_204),272);
        bufp->chgWData(oldp+10098,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_205),272);
        bufp->chgWData(oldp+10107,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_206),272);
        bufp->chgWData(oldp+10116,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_207),272);
        bufp->chgWData(oldp+10125,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_208),272);
        bufp->chgWData(oldp+10134,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_209),272);
        bufp->chgWData(oldp+10143,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_210),272);
        bufp->chgWData(oldp+10152,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_211),272);
        bufp->chgWData(oldp+10161,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_212),272);
        bufp->chgWData(oldp+10170,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_213),272);
        bufp->chgWData(oldp+10179,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_214),272);
        bufp->chgWData(oldp+10188,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_215),272);
        bufp->chgWData(oldp+10197,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_216),272);
        bufp->chgWData(oldp+10206,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_217),272);
        bufp->chgWData(oldp+10215,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_218),272);
        bufp->chgWData(oldp+10224,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_219),272);
        bufp->chgWData(oldp+10233,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_220),272);
        bufp->chgWData(oldp+10242,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_221),272);
        bufp->chgWData(oldp+10251,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_222),272);
        bufp->chgWData(oldp+10260,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_223),272);
        bufp->chgWData(oldp+10269,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_224),272);
        bufp->chgWData(oldp+10278,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_225),272);
        bufp->chgWData(oldp+10287,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_226),272);
        bufp->chgWData(oldp+10296,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_227),272);
        bufp->chgWData(oldp+10305,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_228),272);
        bufp->chgWData(oldp+10314,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_229),272);
        bufp->chgWData(oldp+10323,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_230),272);
        bufp->chgWData(oldp+10332,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_231),272);
        bufp->chgWData(oldp+10341,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_232),272);
        bufp->chgWData(oldp+10350,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_233),272);
        bufp->chgWData(oldp+10359,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_234),272);
        bufp->chgWData(oldp+10368,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_235),272);
        bufp->chgWData(oldp+10377,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_236),272);
        bufp->chgWData(oldp+10386,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_237),272);
        bufp->chgWData(oldp+10395,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_238),272);
        bufp->chgWData(oldp+10404,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_239),272);
        bufp->chgWData(oldp+10413,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_240),272);
        bufp->chgWData(oldp+10422,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_241),272);
        bufp->chgWData(oldp+10431,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_242),272);
        bufp->chgWData(oldp+10440,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_243),272);
        bufp->chgWData(oldp+10449,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_244),272);
        bufp->chgWData(oldp+10458,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_245),272);
        bufp->chgWData(oldp+10467,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_246),272);
        bufp->chgWData(oldp+10476,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_247),272);
        bufp->chgWData(oldp+10485,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_248),272);
        bufp->chgWData(oldp+10494,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_249),272);
        bufp->chgWData(oldp+10503,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_250),272);
        bufp->chgWData(oldp+10512,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_251),272);
        bufp->chgWData(oldp+10521,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_252),272);
        bufp->chgWData(oldp+10530,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_253),272);
        bufp->chgWData(oldp+10539,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_254),272);
        bufp->chgWData(oldp+10548,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_255),272);
        bufp->chgSData(oldp+10557,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg),9);
        bufp->chgSData(oldp+10558,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg),9);
        bufp->chgSData(oldp+10559,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg),9);
        bufp->chgSData(oldp+10560,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg),9);
        bufp->chgBit(oldp+10561,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__maybe_full)))));
        bufp->chgBit(oldp+10562,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__maybe_full));
        bufp->chgBit(oldp+10563,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0));
        bufp->chgBit(oldp+10564,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_0_0));
        bufp->chgBit(oldp+10565,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_1_0));
        bufp->chgBit(oldp+10566,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_2_0));
        bufp->chgBit(oldp+10567,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_3_0));
        bufp->chgBit(oldp+10568,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_4_0));
        bufp->chgBit(oldp+10569,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_5_0));
        bufp->chgBit(oldp+10570,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_6_0));
        bufp->chgBit(oldp+10571,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_7_0));
        bufp->chgBit(oldp+10572,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_8_0));
        bufp->chgBit(oldp+10573,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_9_0));
        bufp->chgBit(oldp+10574,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__maxDevs_0));
        bufp->chgBit(oldp+10575,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__maxDevs_1));
        bufp->chgBit(oldp+10576,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__maxDevs_2));
        bufp->chgBit(oldp+10577,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__maxDevs_3));
        bufp->chgBit(oldp+10578,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__maxDevs_4));
        bufp->chgBit(oldp+10579,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__maxDevs_5));
        bufp->chgBit(oldp+10580,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__maxDevs_6));
        bufp->chgBit(oldp+10581,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__maxDevs_7));
        bufp->chgBit(oldp+10582,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__maxDevs_8));
        bufp->chgBit(oldp+10583,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__maxDevs_9));
        bufp->chgBit(oldp+10584,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_0_0) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0))));
        bufp->chgBit(oldp+10585,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_1_0) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0))));
        bufp->chgBit(oldp+10586,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_2_0) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0))));
        bufp->chgBit(oldp+10587,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_3_0) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0))));
        bufp->chgBit(oldp+10588,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_4_0) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0))));
        bufp->chgBit(oldp+10589,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_5_0) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0))));
        bufp->chgBit(oldp+10590,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_6_0) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0))));
        bufp->chgBit(oldp+10591,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_7_0) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0))));
        bufp->chgBit(oldp+10592,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_8_0) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0))));
        bufp->chgBit(oldp+10593,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_9_0) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0))));
        bufp->chgBit(oldp+10594,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0)))));
        bufp->chgBit(oldp+10595,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__gateways_gateway__DOT__inFlight));
        bufp->chgWData(oldp+10596,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__inflight),1040);
        bufp->chgWData(oldp+10629,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__inflight_opcodes),4160);
        bufp->chgWData(oldp+10759,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__inflight_sizes),4160);
        bufp->chgIData(oldp+10889,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__watchdog),32);
        bufp->chgBit(oldp+10890,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__empty)))));
        bufp->chgBit(oldp+10891,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full)))));
        bufp->chgBit(oldp+10892,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__empty)))));
        bufp->chgBit(oldp+10893,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full)))));
        bufp->chgBit(oldp+10894,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__a_first_done));
        bufp->chgWData(oldp+10895,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__inflight),1040);
        bufp->chgWData(oldp+10928,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__inflight_opcodes),4160);
        bufp->chgWData(oldp+11058,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__inflight_sizes),4160);
        bufp->chgIData(oldp+11188,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__watchdog),32);
        bufp->chgBit(oldp+11189,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__d_first_done));
        bufp->chgBit(oldp+11190,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__a_first_done));
        bufp->chgWData(oldp+11191,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__inflight),1040);
        bufp->chgWData(oldp+11224,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__inflight_opcodes),4160);
        bufp->chgWData(oldp+11354,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__inflight_sizes),4160);
        bufp->chgIData(oldp+11484,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__watchdog),32);
        bufp->chgBit(oldp+11485,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__d_first_done));
        bufp->chgBit(oldp+11486,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_0__DOT__reg_0));
        bufp->chgBit(oldp+11487,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__x1_a_q__DOT__full)))));
        bufp->chgBit(oldp+11488,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__empty)))));
        bufp->chgCData(oldp+11489,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])),3);
        bufp->chgCData(oldp+11490,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 3U))),2);
        bufp->chgCData(oldp+11491,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 5U))),3);
        bufp->chgCData(oldp+11492,((0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                             >> 8U))),7);
        bufp->chgBit(oldp+11493,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                        >> 0xfU))));
        bufp->chgBit(oldp+11494,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                        >> 0x10U))));
        bufp->chgQData(oldp+11495,((((QData)((IData)(
                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                     << 0x2fU) | (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                   << 0xfU) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                     >> 0x11U)))),64);
        bufp->chgBit(oldp+11497,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                        >> 0x11U))));
        bufp->chgBit(oldp+11498,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__in_ready));
        bufp->chgBit(oldp+11499,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_valid));
        bufp->chgCData(oldp+11500,((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_back__DOT__ram_ext__DOT__Memory
                                    [0U][0U])),3);
        bufp->chgCData(oldp+11501,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_back__DOT__ram_ext__DOT__Memory
                                          [0U][2U] 
                                          >> 0x1dU))),2);
        bufp->chgSData(oldp+11502,((0x7ffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_back__DOT__ram_ext__DOT__Memory
                                              [0U][2U] 
                                              >> 0x12U))),11);
        bufp->chgQData(oldp+11503,(((1U & ((2U | ((8U 
                                                   & ((~ (IData)(
                                                                 (0U 
                                                                  != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___GEN_2)))) 
                                                      << 3U)) 
                                                  | ((4U 
                                                      & ((~ (IData)(
                                                                    (0U 
                                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___GEN_2)))) 
                                                         << 2U)) 
                                                     | (1U 
                                                        & (~ (IData)(
                                                                     (0U 
                                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___GEN_2)))))))) 
                                           >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex)))
                                     ? (((QData)((IData)(
                                                         VTestHarness__ConstPool__CONST_h4e4f723a_0[
                                                         (((IData)(0x3fU) 
                                                           + 
                                                           (0xffU 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex) 
                                                               << 6U))) 
                                                          >> 5U)])) 
                                         << ((0U == 
                                              (0x1fU 
                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex) 
                                                  << 6U)))
                                              ? 0x20U
                                              : ((IData)(0x40U) 
                                                 - 
                                                 (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex) 
                                                     << 6U))))) 
                                        | (((0U == 
                                             (0x1fU 
                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex) 
                                                 << 6U)))
                                             ? 0ULL
                                             : ((QData)((IData)(
                                                                VTestHarness__ConstPool__CONST_h4e4f723a_0[
                                                                (((IData)(0x1fU) 
                                                                  + 
                                                                  (0xffU 
                                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex) 
                                                                      << 6U))) 
                                                                 >> 5U)])) 
                                                << 
                                                ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex) 
                                                     << 6U))))) 
                                           | ((QData)((IData)(
                                                              VTestHarness__ConstPool__CONST_h4e4f723a_0[
                                                              (6U 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex) 
                                                                  << 1U))])) 
                                              >> (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex) 
                                                     << 6U)))))
                                     : 0ULL)),64);
        bufp->chgBit(oldp+11505,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__maybe_full));
        bufp->chgCData(oldp+11506,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                    [0U][0U])),3);
        bufp->chgCData(oldp+11507,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                          [0U][0U] 
                                          >> 3U))),3);
        bufp->chgCData(oldp+11508,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                          [0U][0U] 
                                          >> 6U))),2);
        bufp->chgSData(oldp+11509,((0x7ffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                              [0U][0U] 
                                              >> 8U))),11);
        bufp->chgIData(oldp+11510,((0x3ffffffU & ((
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                                   [0U][1U] 
                                                   << 0xdU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                                     [0U][0U] 
                                                     >> 0x13U)))),26);
        bufp->chgCData(oldp+11511,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                             [0U][1U] 
                                             >> 0xdU))),8);
        bufp->chgQData(oldp+11512,((((QData)((IData)(
                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                                     [0U][3U])) 
                                     << 0x2bU) | (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                                                   [0U][2U])) 
                                                   << 0xbU) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                                                     [0U][1U])) 
                                                     >> 0x15U)))),64);
        bufp->chgBit(oldp+11514,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                        [0U][3U] >> 0x15U))));
        bufp->chgBit(oldp+11515,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__maybe_full)))));
        bufp->chgBit(oldp+11516,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__out_7_valid));
        bufp->chgCData(oldp+11517,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__bundleIn_0_d_bits_opcode),3);
        bufp->chgCData(oldp+11518,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 3U))),2);
        bufp->chgCData(oldp+11519,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                            >> 5U))),4);
        bufp->chgCData(oldp+11520,((0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                             >> 9U))),6);
        bufp->chgBit(oldp+11521,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                        >> 0x10U))));
        bufp->chgBit(oldp+11522,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__bundleIn_0_d_bits_denied));
        bufp->chgQData(oldp+11523,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_in_d_bits_data),64);
        bufp->chgBit(oldp+11525,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__bundleIn_0_d_bits_corrupt));
        bufp->chgCData(oldp+11526,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__state),3);
        bufp->chgBit(oldp+11527,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__x1_2_a_valid));
        bufp->chgBit(oldp+11528,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__full)))));
        bufp->chgBit(oldp+11529,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)))));
        bufp->chgCData(oldp+11530,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])),3);
        bufp->chgCData(oldp+11531,((0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                             >> 9U))),7);
        bufp->chgBit(oldp+11532,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                        >> 0x11U))));
        bufp->chgQData(oldp+11533,((((QData)((IData)(
                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                     << 0x2eU) | (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                   << 0xeU) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                     >> 0x12U)))),64);
        bufp->chgBit(oldp+11535,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                        >> 0x12U))));
        bufp->chgBit(oldp+11536,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__bundleIn_0_d_valid));
        bufp->chgBit(oldp+11537,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__out_1_ready));
        bufp->chgCData(oldp+11538,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_s_0_state),2);
        bufp->chgCData(oldp+11539,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_bits_opcode),3);
        bufp->chgCData(oldp+11540,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_bits_param),3);
        bufp->chgCData(oldp+11541,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_bits_size),4);
        bufp->chgCData(oldp+11542,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_bits_source),7);
        bufp->chgIData(oldp+11543,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_bits_address),31);
        bufp->chgCData(oldp+11544,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_bits_mask),8);
        bufp->chgQData(oldp+11545,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_bits_data),64);
        bufp->chgBit(oldp+11547,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_bits_corrupt));
        bufp->chgBit(oldp+11548,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_fifoId));
        bufp->chgCData(oldp+11549,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_lut),4);
        bufp->chgQData(oldp+11550,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_d_0_data),64);
        bufp->chgBit(oldp+11552,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_d_0_denied));
        bufp->chgBit(oldp+11553,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_d_0_corrupt));
        bufp->chgBit(oldp+11554,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_s_0_state))));
        bufp->chgBit(oldp+11555,((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_s_0_state))));
        bufp->chgQData(oldp+11556,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__wide_mask),64);
        bufp->chgQData(oldp+11558,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__a_a_ext),64);
        bufp->chgQData(oldp+11560,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__a_d_ext),64);
        bufp->chgQData(oldp+11562,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__adder_out),64);
        bufp->chgBit(oldp+11564,((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_bits_size)))));
        bufp->chgBit(oldp+11565,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__source_c_bits_a_mask_acc));
        bufp->chgBit(oldp+11566,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__source_c_bits_a_mask_acc_1));
        bufp->chgBit(oldp+11567,((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_bits_size)))));
        bufp->chgBit(oldp+11568,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__source_c_bits_a_mask_eq_2));
        bufp->chgBit(oldp+11569,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__source_c_bits_a_mask_acc_2));
        bufp->chgBit(oldp+11570,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__source_c_bits_a_mask_eq_3));
        bufp->chgBit(oldp+11571,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__source_c_bits_a_mask_acc_3));
        bufp->chgBit(oldp+11572,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__source_c_bits_a_mask_eq_4));
        bufp->chgBit(oldp+11573,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__source_c_bits_a_mask_acc_4));
        bufp->chgBit(oldp+11574,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__source_c_bits_a_mask_eq_5));
        bufp->chgBit(oldp+11575,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__source_c_bits_a_mask_acc_5));
        bufp->chgSData(oldp+11576,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__beatsLeft),9);
        bufp->chgBit(oldp+11577,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__beatsLeft))));
        bufp->chgBit(oldp+11578,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__state_0));
        bufp->chgBit(oldp+11579,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__state_1));
        bufp->chgBit(oldp+11580,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__muxStateEarly_0));
        bufp->chgSData(oldp+11581,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__d_first_counter),9);
        bufp->chgBit(oldp+11582,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__d_first_counter))));
        bufp->chgBit(oldp+11583,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__d_cam_sel_match_0));
        bufp->chgBit(oldp+11584,((1U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))));
        bufp->chgBit(oldp+11585,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__d_drop));
        bufp->chgBit(oldp+11586,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__d_replace));
        bufp->chgSData(oldp+11587,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__a_first_counter),9);
        bufp->chgCData(oldp+11588,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__opcode),3);
        bufp->chgCData(oldp+11589,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__param),3);
        bufp->chgCData(oldp+11590,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__size),4);
        bufp->chgCData(oldp+11591,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__source),7);
        bufp->chgIData(oldp+11592,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__address),31);
        bufp->chgSData(oldp+11593,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__d_first_counter),9);
        bufp->chgCData(oldp+11594,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__opcode_1),3);
        bufp->chgCData(oldp+11595,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__param_1),2);
        bufp->chgCData(oldp+11596,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__size_1),4);
        bufp->chgCData(oldp+11597,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__source_1),7);
        bufp->chgBit(oldp+11598,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__sink));
        bufp->chgBit(oldp+11599,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__denied));
        bufp->chgWData(oldp+11600,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__inflight),65);
        bufp->chgWData(oldp+11603,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__inflight_opcodes),260);
        bufp->chgWData(oldp+11612,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__inflight_sizes),520);
        bufp->chgSData(oldp+11629,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__a_first_counter_1),9);
        bufp->chgBit(oldp+11630,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__a_first_counter_1))));
        bufp->chgSData(oldp+11631,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__d_first_counter_1),9);
        bufp->chgBit(oldp+11632,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__d_first_counter_1))));
        bufp->chgBit(oldp+11633,((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__bundleIn_0_d_bits_opcode))));
        bufp->chgIData(oldp+11634,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__watchdog),32);
        bufp->chgSData(oldp+11635,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__d_first_counter_2),9);
        bufp->chgBit(oldp+11636,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__d_first_counter_2))));
        bufp->chgBit(oldp+11637,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__source_ok_1));
        bufp->chgBit(oldp+11638,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)))));
        bufp->chgBit(oldp+11639,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full)))));
        bufp->chgBit(oldp+11640,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value));
        bufp->chgBit(oldp+11641,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value));
        bufp->chgBit(oldp+11642,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__maybe_full));
        bufp->chgBit(oldp+11643,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ptr_match));
        bufp->chgBit(oldp+11644,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty));
        bufp->chgBit(oldp+11645,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full));
        bufp->chgWData(oldp+11646,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data),83);
        bufp->chgWData(oldp+11649,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[0]),83);
        bufp->chgWData(oldp+11652,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[1]),83);
        bufp->chgSData(oldp+11655,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__a_first_counter),9);
        bufp->chgCData(oldp+11656,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__opcode),3);
        bufp->chgCData(oldp+11657,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__param),3);
        bufp->chgCData(oldp+11658,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__size),4);
        bufp->chgCData(oldp+11659,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__source),7);
        bufp->chgIData(oldp+11660,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__address),31);
        bufp->chgSData(oldp+11661,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_counter),9);
        bufp->chgCData(oldp+11662,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__opcode_1),3);
        bufp->chgCData(oldp+11663,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__param_1),2);
        bufp->chgCData(oldp+11664,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__size_1),4);
        bufp->chgCData(oldp+11665,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__source_1),7);
        bufp->chgBit(oldp+11666,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__sink));
        bufp->chgBit(oldp+11667,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__denied));
        bufp->chgWData(oldp+11668,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight),65);
        bufp->chgWData(oldp+11671,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_opcodes),260);
        bufp->chgWData(oldp+11680,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes),520);
        bufp->chgSData(oldp+11697,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__a_first_counter_1),9);
        bufp->chgBit(oldp+11698,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__a_first_counter_1))));
        bufp->chgSData(oldp+11699,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_counter_1),9);
        bufp->chgBit(oldp+11700,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_counter_1))));
        bufp->chgBit(oldp+11701,((6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))));
        bufp->chgIData(oldp+11702,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__watchdog),32);
        bufp->chgSData(oldp+11703,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_counter_2),9);
        bufp->chgBit(oldp+11704,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_counter_2))));
        bufp->chgBit(oldp+11705,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__source_ok_1));
        bufp->chgBit(oldp+11706,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value));
        bufp->chgBit(oldp+11707,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value));
        bufp->chgBit(oldp+11708,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__maybe_full));
        bufp->chgBit(oldp+11709,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__ptr_match));
        bufp->chgBit(oldp+11710,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty));
        bufp->chgBit(oldp+11711,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__full));
        bufp->chgWData(oldp+11712,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[0]),121);
        bufp->chgWData(oldp+11716,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[1]),121);
        bufp->chgCData(oldp+11720,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__acknum),3);
        bufp->chgCData(oldp+11721,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__dOrig),3);
        bufp->chgBit(oldp+11722,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__dToggle));
        bufp->chgBit(oldp+11723,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__acknum))));
        bufp->chgCData(oldp+11724,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__gennum),3);
        bufp->chgBit(oldp+11725,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__gennum))));
        bufp->chgBit(oldp+11726,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__aToggle_r));
        bufp->chgCData(oldp+11727,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__d_first_counter),3);
        bufp->chgCData(oldp+11728,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__opcode_1),3);
        bufp->chgCData(oldp+11729,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__param_1),2);
        bufp->chgCData(oldp+11730,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__size_1),3);
        bufp->chgCData(oldp+11731,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__source_1),7);
        bufp->chgBit(oldp+11732,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__sink));
        bufp->chgBit(oldp+11733,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__denied));
        bufp->chgWData(oldp+11734,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__inflight),65);
        bufp->chgWData(oldp+11737,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes),260);
        bufp->chgWData(oldp+11746,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes),260);
        bufp->chgCData(oldp+11755,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1),3);
        bufp->chgBit(oldp+11756,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1))));
        bufp->chgIData(oldp+11757,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__watchdog),32);
        bufp->chgBit(oldp+11758,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__repeater__DOT__full));
        bufp->chgCData(oldp+11759,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__repeater__DOT__saved_opcode),3);
        bufp->chgCData(oldp+11760,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__repeater__DOT__saved_param),3);
        bufp->chgCData(oldp+11761,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__repeater__DOT__saved_size),3);
        bufp->chgCData(oldp+11762,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__repeater__DOT__saved_source),7);
        bufp->chgIData(oldp+11763,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__repeater__DOT__saved_address),17);
        bufp->chgCData(oldp+11764,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__repeater__DOT__saved_mask),8);
        bufp->chgBit(oldp+11765,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__repeater__DOT__saved_corrupt));
        bufp->chgCData(oldp+11766,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__acknum),3);
        bufp->chgCData(oldp+11767,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__dOrig),3);
        bufp->chgBit(oldp+11768,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__dToggle));
        bufp->chgBit(oldp+11769,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__acknum))));
        bufp->chgCData(oldp+11770,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__gennum),3);
        bufp->chgBit(oldp+11771,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__gennum))));
        bufp->chgBit(oldp+11772,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__aToggle_r));
        bufp->chgCData(oldp+11773,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__a_first_counter),3);
        bufp->chgCData(oldp+11774,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__opcode),3);
        bufp->chgCData(oldp+11775,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__param),3);
        bufp->chgCData(oldp+11776,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__size),3);
        bufp->chgCData(oldp+11777,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__source),7);
        bufp->chgIData(oldp+11778,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__address),26);
        bufp->chgCData(oldp+11779,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__d_first_counter),3);
        bufp->chgCData(oldp+11780,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__opcode_1),3);
        bufp->chgCData(oldp+11781,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__param_1),2);
        bufp->chgCData(oldp+11782,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__size_1),3);
        bufp->chgCData(oldp+11783,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__source_1),7);
        bufp->chgBit(oldp+11784,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__sink));
        bufp->chgBit(oldp+11785,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__denied));
        bufp->chgWData(oldp+11786,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight),65);
        bufp->chgWData(oldp+11789,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes),260);
        bufp->chgWData(oldp+11798,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes),260);
        bufp->chgCData(oldp+11807,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1),3);
        bufp->chgBit(oldp+11808,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1))));
        bufp->chgCData(oldp+11809,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1),3);
        bufp->chgBit(oldp+11810,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1))));
        bufp->chgIData(oldp+11811,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__watchdog),32);
        bufp->chgCData(oldp+11812,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2),3);
        bufp->chgBit(oldp+11813,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2))));
        bufp->chgBit(oldp+11814,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__repeater__DOT__full));
        bufp->chgCData(oldp+11815,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__repeater__DOT__saved_opcode),3);
        bufp->chgCData(oldp+11816,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__repeater__DOT__saved_param),3);
        bufp->chgCData(oldp+11817,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__repeater__DOT__saved_size),3);
        bufp->chgCData(oldp+11818,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__repeater__DOT__saved_source),7);
        bufp->chgIData(oldp+11819,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__repeater__DOT__saved_address),26);
        bufp->chgCData(oldp+11820,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__repeater__DOT__saved_mask),8);
        bufp->chgBit(oldp+11821,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__repeater__DOT__saved_corrupt));
        bufp->chgCData(oldp+11822,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__acknum),3);
        bufp->chgCData(oldp+11823,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__dOrig),3);
        bufp->chgBit(oldp+11824,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__dToggle));
        bufp->chgBit(oldp+11825,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__acknum))));
        bufp->chgCData(oldp+11826,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__gennum),3);
        bufp->chgBit(oldp+11827,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__gennum))));
        bufp->chgBit(oldp+11828,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__aToggle_r));
        bufp->chgCData(oldp+11829,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__a_first_counter),3);
        bufp->chgCData(oldp+11830,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__opcode),3);
        bufp->chgCData(oldp+11831,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__param),3);
        bufp->chgCData(oldp+11832,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__size),3);
        bufp->chgCData(oldp+11833,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__source),7);
        bufp->chgSData(oldp+11834,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__address),12);
        bufp->chgCData(oldp+11835,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__d_first_counter),3);
        bufp->chgCData(oldp+11836,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__opcode_1),3);
        bufp->chgCData(oldp+11837,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__param_1),2);
        bufp->chgCData(oldp+11838,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__size_1),3);
        bufp->chgCData(oldp+11839,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__source_1),7);
        bufp->chgBit(oldp+11840,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__sink));
        bufp->chgBit(oldp+11841,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__denied));
        bufp->chgWData(oldp+11842,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight),65);
        bufp->chgWData(oldp+11845,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes),260);
        bufp->chgWData(oldp+11854,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes),260);
        bufp->chgCData(oldp+11863,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1),3);
        bufp->chgBit(oldp+11864,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1))));
        bufp->chgCData(oldp+11865,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1),3);
        bufp->chgBit(oldp+11866,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1))));
        bufp->chgIData(oldp+11867,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__watchdog),32);
        bufp->chgCData(oldp+11868,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2),3);
        bufp->chgBit(oldp+11869,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2))));
        bufp->chgCData(oldp+11870,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT__saved_opcode),3);
        bufp->chgCData(oldp+11871,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT__saved_size),3);
        bufp->chgCData(oldp+11872,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT__saved_source),7);
        bufp->chgSData(oldp+11873,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT__saved_address),12);
        bufp->chgCData(oldp+11874,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT__saved_mask),8);
        bufp->chgBit(oldp+11875,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_enq_ready_output));
        bufp->chgBit(oldp+11876,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__bundleIn_0_d_valid));
        bufp->chgCData(oldp+11877,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                    [0U][0U])),3);
        bufp->chgCData(oldp+11878,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                          [0U][0U] 
                                          >> 3U))),2);
        bufp->chgCData(oldp+11879,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__bundleIn_0_d_bits_size),3);
        bufp->chgCData(oldp+11880,((0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                             [0U][0U] 
                                             >> 0xbU))),7);
        bufp->chgBit(oldp+11881,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                        [0U][0U] >> 0x12U))));
        bufp->chgBit(oldp+11882,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                        [0U][0U] >> 0x13U))));
        bufp->chgQData(oldp+11883,((((QData)((IData)(
                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                                     [0U][2U])) 
                                     << 0x2cU) | (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                                                   [0U][1U])) 
                                                   << 0xcU) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                                                     [0U][0U])) 
                                                     >> 0x14U)))),64);
        bufp->chgBit(oldp+11885,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                        [0U][2U] >> 0x14U))));
        bufp->chgBit(oldp+11886,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__maybe_full)))));
        bufp->chgBit(oldp+11887,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__maybe_full));
        bufp->chgCData(oldp+11888,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                          [0U][0U] 
                                          >> 5U))),2);
        bufp->chgSData(oldp+11889,((0x7ffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                              [0U][0U] 
                                              >> 7U))),11);
        bufp->chgBit(oldp+11890,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_enq));
        VL_EXTEND_WQ(65,64, __Vtemp_h56c6a7bd__0, (
                                                   (1U 
                                                    & ((2U 
                                                        | ((8U 
                                                            & ((~ (IData)(
                                                                          (0U 
                                                                           != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___GEN_2)))) 
                                                               << 3U)) 
                                                           | ((4U 
                                                               & ((~ (IData)(
                                                                             (0U 
                                                                              != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___GEN_2)))) 
                                                                  << 2U)) 
                                                              | (1U 
                                                                 & (~ (IData)(
                                                                              (0U 
                                                                               != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___GEN_2)))))))) 
                                                       >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex)))
                                                    ? 
                                                   (((QData)((IData)(
                                                                     VTestHarness__ConstPool__CONST_h4e4f723a_0[
                                                                     (((IData)(0x3fU) 
                                                                       + 
                                                                       (0xffU 
                                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex) 
                                                                           << 6U))) 
                                                                      >> 5U)])) 
                                                     << 
                                                     ((0U 
                                                       == 
                                                       (0x1fU 
                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex) 
                                                           << 6U)))
                                                       ? 0x20U
                                                       : 
                                                      ((IData)(0x40U) 
                                                       - 
                                                       (0x1fU 
                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex) 
                                                           << 6U))))) 
                                                    | (((0U 
                                                         == 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex) 
                                                             << 6U)))
                                                         ? 0ULL
                                                         : 
                                                        ((QData)((IData)(
                                                                         VTestHarness__ConstPool__CONST_h4e4f723a_0[
                                                                         (((IData)(0x1fU) 
                                                                           + 
                                                                           (0xffU 
                                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex) 
                                                                               << 6U))) 
                                                                          >> 5U)])) 
                                                         << 
                                                         ((IData)(0x20U) 
                                                          - 
                                                          (0x1fU 
                                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex) 
                                                              << 6U))))) 
                                                       | ((QData)((IData)(
                                                                          VTestHarness__ConstPool__CONST_h4e4f723a_0[
                                                                          (6U 
                                                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex) 
                                                                              << 1U))])) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex) 
                                                              << 6U)))))
                                                    : 0ULL));
        __Vtemp_hc92888ee__0[0U] = ((__Vtemp_h56c6a7bd__0[0U] 
                                     << 0x14U) | ((0x3ff80U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_back__DOT__ram_ext__DOT__Memory
                                                      [0U][2U] 
                                                      >> 0xbU)) 
                                                  | ((0x60U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_back__DOT__ram_ext__DOT__Memory
                                                         [0U][2U] 
                                                         >> 0x18U)) 
                                                     | (1U 
                                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_back__DOT__ram_ext__DOT__Memory
                                                        [0U][0U]))));
        __Vtemp_hc92888ee__0[1U] = ((__Vtemp_h56c6a7bd__0[0U] 
                                     >> 0xcU) | (__Vtemp_h56c6a7bd__0[1U] 
                                                 << 0x14U));
        __Vtemp_hc92888ee__0[2U] = ((__Vtemp_h56c6a7bd__0[1U] 
                                     >> 0xcU) | (__Vtemp_h56c6a7bd__0[2U] 
                                                 << 0x14U));
        bufp->chgWData(oldp+11891,(__Vtemp_hc92888ee__0),85);
        __Vtemp_hb2c720f9__9[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
            [0U][0U];
        __Vtemp_hb2c720f9__9[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
            [0U][1U];
        __Vtemp_hb2c720f9__9[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
            [0U][2U];
        bufp->chgWData(oldp+11894,(__Vtemp_hb2c720f9__9),85);
        bufp->chgWData(oldp+11897,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[0]),85);
        bufp->chgWData(oldp+11900,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__inflight),1040);
        bufp->chgWData(oldp+11933,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__inflight_opcodes),4160);
        bufp->chgWData(oldp+12063,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__inflight_sizes),4160);
        bufp->chgBit(oldp+12193,((6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                         [0U][0U]))));
        bufp->chgIData(oldp+12194,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__watchdog),32);
        __Vtemp_h14e110c9__8[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
            [0U][0U];
        __Vtemp_h14e110c9__8[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
            [0U][1U];
        __Vtemp_h14e110c9__8[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
            [0U][2U];
        __Vtemp_h14e110c9__8[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
            [0U][3U];
        bufp->chgWData(oldp+12195,(__Vtemp_h14e110c9__8),118);
        bufp->chgWData(oldp+12199,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[0]),118);
        bufp->chgCData(oldp+12203,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__acknum),3);
        bufp->chgCData(oldp+12204,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__dOrig),3);
        bufp->chgBit(oldp+12205,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__dToggle));
        bufp->chgBit(oldp+12206,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__acknum))));
        bufp->chgCData(oldp+12207,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__dFirst_size),3);
        bufp->chgBit(oldp+12208,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__drop));
        bufp->chgCData(oldp+12209,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__gennum),3);
        bufp->chgBit(oldp+12210,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__gennum))));
        bufp->chgBit(oldp+12211,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__aToggle_r));
        bufp->chgCData(oldp+12212,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__a_first_counter),3);
        bufp->chgCData(oldp+12213,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__opcode),3);
        bufp->chgCData(oldp+12214,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__param),3);
        bufp->chgCData(oldp+12215,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__size),3);
        bufp->chgCData(oldp+12216,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__source),7);
        bufp->chgIData(oldp+12217,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__address),26);
        bufp->chgCData(oldp+12218,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__d_first_counter),3);
        bufp->chgCData(oldp+12219,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__opcode_1),3);
        bufp->chgCData(oldp+12220,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__param_1),2);
        bufp->chgCData(oldp+12221,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__size_1),3);
        bufp->chgCData(oldp+12222,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__source_1),7);
        bufp->chgBit(oldp+12223,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__sink));
        bufp->chgBit(oldp+12224,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__denied));
        bufp->chgWData(oldp+12225,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__inflight),65);
        bufp->chgWData(oldp+12228,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes),260);
        bufp->chgWData(oldp+12237,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes),260);
        bufp->chgCData(oldp+12246,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1),3);
        bufp->chgBit(oldp+12247,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1))));
        bufp->chgCData(oldp+12248,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1),3);
        bufp->chgBit(oldp+12249,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1))));
        bufp->chgIData(oldp+12250,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__watchdog),32);
        bufp->chgCData(oldp+12251,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2),3);
        bufp->chgBit(oldp+12252,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2))));
        bufp->chgBit(oldp+12253,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__source_ok_1));
        bufp->chgBit(oldp+12254,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__full));
        bufp->chgCData(oldp+12255,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__saved_opcode),3);
        bufp->chgCData(oldp+12256,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__saved_param),3);
        bufp->chgCData(oldp+12257,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__saved_size),3);
        bufp->chgCData(oldp+12258,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__saved_source),7);
        bufp->chgIData(oldp+12259,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__saved_address),26);
        bufp->chgCData(oldp+12260,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__saved_mask),8);
        bufp->chgBit(oldp+12261,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__saved_corrupt));
        bufp->chgBit(oldp+12262,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_enq_ready_output));
        bufp->chgCData(oldp+12263,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__acknum),3);
        bufp->chgCData(oldp+12264,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__dOrig),3);
        bufp->chgBit(oldp+12265,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__dToggle));
        bufp->chgBit(oldp+12266,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__acknum))));
        bufp->chgCData(oldp+12267,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__gennum),3);
        bufp->chgBit(oldp+12268,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__gennum))));
        bufp->chgBit(oldp+12269,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__aToggle_r));
        bufp->chgCData(oldp+12270,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__a_first_counter),3);
        bufp->chgCData(oldp+12271,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__opcode),3);
        bufp->chgCData(oldp+12272,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__param),3);
        bufp->chgCData(oldp+12273,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__size),3);
        bufp->chgCData(oldp+12274,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__source),7);
        bufp->chgIData(oldp+12275,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__address),28);
        bufp->chgCData(oldp+12276,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__d_first_counter),3);
        bufp->chgCData(oldp+12277,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__opcode_1),3);
        bufp->chgCData(oldp+12278,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__param_1),2);
        bufp->chgCData(oldp+12279,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__size_1),3);
        bufp->chgCData(oldp+12280,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__source_1),7);
        bufp->chgBit(oldp+12281,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__sink));
        bufp->chgBit(oldp+12282,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__denied));
        bufp->chgWData(oldp+12283,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__inflight),65);
        bufp->chgWData(oldp+12286,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes),260);
        bufp->chgWData(oldp+12295,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes),260);
        bufp->chgCData(oldp+12304,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1),3);
        bufp->chgBit(oldp+12305,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1))));
        bufp->chgCData(oldp+12306,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1),3);
        bufp->chgBit(oldp+12307,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1))));
        bufp->chgIData(oldp+12308,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__watchdog),32);
        bufp->chgCData(oldp+12309,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2),3);
        bufp->chgBit(oldp+12310,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2))));
        bufp->chgBit(oldp+12311,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT__full));
        bufp->chgCData(oldp+12312,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT__saved_opcode),3);
        bufp->chgCData(oldp+12313,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT__saved_param),3);
        bufp->chgCData(oldp+12314,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT__saved_size),3);
        bufp->chgCData(oldp+12315,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT__saved_source),7);
        bufp->chgIData(oldp+12316,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT__saved_address),28);
        bufp->chgCData(oldp+12317,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT__saved_mask),8);
        bufp->chgBit(oldp+12318,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT__saved_corrupt));
        bufp->chgBit(oldp+12319,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_enq_ready_output));
        bufp->chgBit(oldp+12320,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__bundleIn_0_d_valid));
        bufp->chgCData(oldp+12321,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])),3);
        bufp->chgCData(oldp+12322,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 3U))),2);
        bufp->chgCData(oldp+12323,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__bundleIn_0_d_bits_size),3);
        bufp->chgCData(oldp+12324,((0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xbU))),7);
        bufp->chgBit(oldp+12325,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                        >> 0x12U))));
        bufp->chgBit(oldp+12326,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                        >> 0x13U))));
        bufp->chgQData(oldp+12327,((((QData)((IData)(
                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                     << 0x2cU) | (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                   << 0xcU) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                     >> 0x14U)))),64);
        bufp->chgBit(oldp+12329,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                        >> 0x14U))));
        bufp->chgBit(oldp+12330,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__full)))));
        bufp->chgBit(oldp+12331,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)))));
        bufp->chgCData(oldp+12332,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 5U))),2);
        bufp->chgSData(oldp+12333,((0x7ffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                              >> 7U))),11);
        bufp->chgBit(oldp+12334,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value));
        bufp->chgBit(oldp+12335,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value));
        bufp->chgBit(oldp+12336,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__maybe_full));
        bufp->chgBit(oldp+12337,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ptr_match));
        bufp->chgBit(oldp+12338,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty));
        bufp->chgBit(oldp+12339,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full));
        bufp->chgBit(oldp+12340,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_enq));
        bufp->chgWData(oldp+12341,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data),85);
        bufp->chgWData(oldp+12344,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[0]),85);
        bufp->chgWData(oldp+12347,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[1]),85);
        bufp->chgWData(oldp+12350,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__inflight),1040);
        bufp->chgWData(oldp+12383,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__inflight_opcodes),4160);
        bufp->chgWData(oldp+12513,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__inflight_sizes),4160);
        bufp->chgBit(oldp+12643,((6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))));
        bufp->chgIData(oldp+12644,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__watchdog),32);
        bufp->chgBit(oldp+12645,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value));
        bufp->chgBit(oldp+12646,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value));
        bufp->chgBit(oldp+12647,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__maybe_full));
        bufp->chgBit(oldp+12648,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__ptr_match));
        bufp->chgBit(oldp+12649,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__empty));
        bufp->chgBit(oldp+12650,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__full));
        bufp->chgWData(oldp+12651,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[0]),113);
        bufp->chgWData(oldp+12655,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[1]),113);
        bufp->chgCData(oldp+12659,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__acknum),3);
        bufp->chgCData(oldp+12660,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__dOrig),3);
        bufp->chgBit(oldp+12661,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__dToggle));
        bufp->chgBit(oldp+12662,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__acknum))));
        bufp->chgCData(oldp+12663,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__dFirst_size),3);
        bufp->chgBit(oldp+12664,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__drop));
        bufp->chgCData(oldp+12665,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__gennum),3);
        bufp->chgBit(oldp+12666,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__gennum))));
        bufp->chgBit(oldp+12667,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__aToggle_r));
        bufp->chgCData(oldp+12668,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__a_first_counter),3);
        bufp->chgCData(oldp+12669,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__opcode),3);
        bufp->chgCData(oldp+12670,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__param),3);
        bufp->chgCData(oldp+12671,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__size),3);
        bufp->chgCData(oldp+12672,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__source),7);
        bufp->chgIData(oldp+12673,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__address),21);
        bufp->chgCData(oldp+12674,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__d_first_counter),3);
        bufp->chgCData(oldp+12675,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__opcode_1),3);
        bufp->chgCData(oldp+12676,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__param_1),2);
        bufp->chgCData(oldp+12677,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__size_1),3);
        bufp->chgCData(oldp+12678,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__source_1),7);
        bufp->chgBit(oldp+12679,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__sink));
        bufp->chgBit(oldp+12680,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__denied));
        bufp->chgWData(oldp+12681,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight),65);
        bufp->chgWData(oldp+12684,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes),260);
        bufp->chgWData(oldp+12693,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes),260);
        bufp->chgCData(oldp+12702,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1),3);
        bufp->chgBit(oldp+12703,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1))));
        bufp->chgCData(oldp+12704,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1),3);
        bufp->chgBit(oldp+12705,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1))));
        bufp->chgIData(oldp+12706,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__watchdog),32);
        bufp->chgCData(oldp+12707,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2),3);
        bufp->chgBit(oldp+12708,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2))));
        bufp->chgBit(oldp+12709,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__source_ok_1));
        bufp->chgBit(oldp+12710,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__full));
        bufp->chgCData(oldp+12711,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__saved_opcode),3);
        bufp->chgCData(oldp+12712,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__saved_param),3);
        bufp->chgCData(oldp+12713,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__saved_size),3);
        bufp->chgCData(oldp+12714,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__saved_source),7);
        bufp->chgIData(oldp+12715,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__saved_address),21);
        bufp->chgCData(oldp+12716,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__saved_mask),8);
        bufp->chgBit(oldp+12717,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__saved_corrupt));
        bufp->chgBit(oldp+12718,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_enq_ready_output));
        bufp->chgBit(oldp+12719,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__bundleIn_0_d_valid));
        bufp->chgCData(oldp+12720,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])),3);
        bufp->chgCData(oldp+12721,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 3U))),2);
        bufp->chgCData(oldp+12722,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__bundleIn_0_d_bits_size),3);
        bufp->chgCData(oldp+12723,((0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xbU))),7);
        bufp->chgBit(oldp+12724,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                        >> 0x12U))));
        bufp->chgBit(oldp+12725,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                        >> 0x13U))));
        bufp->chgQData(oldp+12726,((((QData)((IData)(
                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                     << 0x2cU) | (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                   << 0xcU) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                     >> 0x14U)))),64);
        bufp->chgBit(oldp+12728,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                        >> 0x14U))));
        bufp->chgBit(oldp+12729,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__full)))));
        bufp->chgBit(oldp+12730,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)))));
        bufp->chgCData(oldp+12731,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 5U))),2);
        bufp->chgSData(oldp+12732,((0x7ffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                              >> 7U))),11);
        bufp->chgBit(oldp+12733,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value));
        bufp->chgBit(oldp+12734,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value));
        bufp->chgBit(oldp+12735,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__maybe_full));
        bufp->chgBit(oldp+12736,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ptr_match));
        bufp->chgBit(oldp+12737,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty));
        bufp->chgBit(oldp+12738,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full));
        bufp->chgBit(oldp+12739,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_enq));
        bufp->chgWData(oldp+12740,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data),85);
        bufp->chgWData(oldp+12743,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[0]),85);
        bufp->chgWData(oldp+12746,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[1]),85);
        bufp->chgWData(oldp+12749,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__inflight),1040);
        bufp->chgWData(oldp+12782,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__inflight_opcodes),4160);
        bufp->chgWData(oldp+12912,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__inflight_sizes),4160);
        bufp->chgBit(oldp+13042,((6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))));
        bufp->chgIData(oldp+13043,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__watchdog),32);
        bufp->chgBit(oldp+13044,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value));
        bufp->chgBit(oldp+13045,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value));
        bufp->chgBit(oldp+13046,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__maybe_full));
        bufp->chgBit(oldp+13047,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__ptr_match));
        bufp->chgBit(oldp+13048,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__empty));
        bufp->chgBit(oldp+13049,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__full));
        bufp->chgWData(oldp+13050,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[0]),113);
        bufp->chgWData(oldp+13054,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[1]),113);
        bufp->chgCData(oldp+13058,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__acknum),3);
        bufp->chgCData(oldp+13059,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__dOrig),3);
        bufp->chgBit(oldp+13060,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__dToggle));
        bufp->chgBit(oldp+13061,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__acknum))));
        bufp->chgCData(oldp+13062,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__dFirst_size),3);
        bufp->chgBit(oldp+13063,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__drop));
        bufp->chgCData(oldp+13064,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__gennum),3);
        bufp->chgBit(oldp+13065,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__gennum))));
        bufp->chgBit(oldp+13066,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__aToggle_r));
        bufp->chgCData(oldp+13067,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__a_first_counter),3);
        bufp->chgCData(oldp+13068,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__opcode),3);
        bufp->chgCData(oldp+13069,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__param),3);
        bufp->chgCData(oldp+13070,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__size),3);
        bufp->chgCData(oldp+13071,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__source),7);
        bufp->chgIData(oldp+13072,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__address),21);
        bufp->chgCData(oldp+13073,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__d_first_counter),3);
        bufp->chgCData(oldp+13074,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__opcode_1),3);
        bufp->chgCData(oldp+13075,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__param_1),2);
        bufp->chgCData(oldp+13076,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__size_1),3);
        bufp->chgCData(oldp+13077,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__source_1),7);
        bufp->chgBit(oldp+13078,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__sink));
        bufp->chgBit(oldp+13079,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__denied));
        bufp->chgWData(oldp+13080,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight),65);
        bufp->chgWData(oldp+13083,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes),260);
        bufp->chgWData(oldp+13092,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes),260);
        bufp->chgCData(oldp+13101,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1),3);
        bufp->chgBit(oldp+13102,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1))));
        bufp->chgCData(oldp+13103,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1),3);
        bufp->chgBit(oldp+13104,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1))));
        bufp->chgIData(oldp+13105,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__watchdog),32);
        bufp->chgCData(oldp+13106,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2),3);
        bufp->chgBit(oldp+13107,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2))));
        bufp->chgBit(oldp+13108,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__source_ok_1));
        bufp->chgBit(oldp+13109,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT__full));
        bufp->chgCData(oldp+13110,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT__saved_opcode),3);
        bufp->chgCData(oldp+13111,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT__saved_param),3);
        bufp->chgCData(oldp+13112,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT__saved_size),3);
        bufp->chgCData(oldp+13113,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT__saved_source),7);
        bufp->chgIData(oldp+13114,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT__saved_address),21);
        bufp->chgCData(oldp+13115,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT__saved_mask),8);
        bufp->chgBit(oldp+13116,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT__saved_corrupt));
        bufp->chgSData(oldp+13117,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__a_first_counter),9);
        bufp->chgCData(oldp+13118,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__opcode),3);
        bufp->chgCData(oldp+13119,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__param),3);
        bufp->chgCData(oldp+13120,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__size),4);
        bufp->chgCData(oldp+13121,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__source),7);
        bufp->chgIData(oldp+13122,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__address),31);
        bufp->chgSData(oldp+13123,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter),9);
        bufp->chgCData(oldp+13124,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__opcode_1),3);
        bufp->chgCData(oldp+13125,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__param_1),2);
        bufp->chgCData(oldp+13126,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__size_1),4);
        bufp->chgCData(oldp+13127,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__source_1),7);
        bufp->chgBit(oldp+13128,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__sink));
        bufp->chgBit(oldp+13129,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__denied));
        bufp->chgWData(oldp+13130,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight),65);
        bufp->chgWData(oldp+13133,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes),260);
        bufp->chgWData(oldp+13142,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes),520);
        bufp->chgSData(oldp+13159,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__a_first_counter_1),9);
        bufp->chgBit(oldp+13160,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__a_first_counter_1))));
        bufp->chgSData(oldp+13161,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_1),9);
        bufp->chgBit(oldp+13162,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_1))));
        bufp->chgIData(oldp+13163,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__watchdog),32);
        bufp->chgSData(oldp+13164,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_2),9);
        bufp->chgBit(oldp+13165,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_2))));
        bufp->chgIData(oldp+13166,(((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__state))
                                     ? 0x4000U : 0x2000000U)),31);
        bufp->chgQData(oldp+13167,(((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__state))
                                     ? 0x80000000ULL
                                     : 1ULL)),64);
        bufp->chgBit(oldp+13169,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__out_10_valid));
        bufp->chgBit(oldp+13170,((0x40U == (0x7fU & 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                             >> 9U)))));
        bufp->chgSData(oldp+13171,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__beatsLeft),9);
        bufp->chgBit(oldp+13172,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__beatsLeft))));
        bufp->chgCData(oldp+13173,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__readys_mask),2);
        bufp->chgBit(oldp+13174,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__state_0));
        bufp->chgBit(oldp+13175,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__state_1));
        bufp->chgSData(oldp+13176,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__a_first_counter),9);
        bufp->chgCData(oldp+13177,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__opcode),3);
        bufp->chgCData(oldp+13178,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__param),3);
        bufp->chgCData(oldp+13179,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__size),4);
        bufp->chgCData(oldp+13180,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__source),6);
        bufp->chgIData(oldp+13181,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__address),31);
        bufp->chgSData(oldp+13182,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__d_first_counter),9);
        bufp->chgCData(oldp+13183,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__opcode_1),3);
        bufp->chgCData(oldp+13184,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__param_1),2);
        bufp->chgCData(oldp+13185,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__size_1),4);
        bufp->chgCData(oldp+13186,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__source_1),6);
        bufp->chgBit(oldp+13187,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__sink));
        bufp->chgBit(oldp+13188,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__denied));
        bufp->chgQData(oldp+13189,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__inflight),33);
        bufp->chgWData(oldp+13191,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__inflight_opcodes),132);
        bufp->chgWData(oldp+13196,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__inflight_sizes),264);
        bufp->chgSData(oldp+13205,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__a_first_counter_1),9);
        bufp->chgBit(oldp+13206,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__a_first_counter_1))));
        bufp->chgSData(oldp+13207,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__d_first_counter_1),9);
        bufp->chgBit(oldp+13208,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__d_first_counter_1))));
        bufp->chgIData(oldp+13209,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__watchdog),32);
        bufp->chgSData(oldp+13210,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__d_first_counter_2),9);
        bufp->chgBit(oldp+13211,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__d_first_counter_2))));
        bufp->chgBit(oldp+13212,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__source_ok_1));
        bufp->chgSData(oldp+13213,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__d_first_counter),9);
        bufp->chgCData(oldp+13214,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__opcode_1),3);
        bufp->chgCData(oldp+13215,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__param_1),2);
        bufp->chgCData(oldp+13216,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__size_1),4);
        bufp->chgBit(oldp+13217,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__source_1));
        bufp->chgBit(oldp+13218,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__sink));
        bufp->chgBit(oldp+13219,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__denied));
        bufp->chgBit(oldp+13220,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__inflight));
        bufp->chgCData(oldp+13221,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__inflight_opcodes),4);
        bufp->chgCData(oldp+13222,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__inflight_sizes),8);
        bufp->chgSData(oldp+13223,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__d_first_counter_1),9);
        bufp->chgBit(oldp+13224,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__d_first_counter_1))));
        bufp->chgIData(oldp+13225,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__watchdog),32);
        bufp->chgSData(oldp+13226,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__d_first_counter_2),9);
        bufp->chgBit(oldp+13227,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__d_first_counter_2))));
        bufp->chgBit(oldp+13228,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__d_clr));
        bufp->chgBit(oldp+13229,((1U & ((~ (((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__state))
                                              ? 0x4000U
                                              : 0x2000000U) 
                                            >> 2U)) 
                                        & (~ (((1U 
                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__state))
                                                ? 0x4000U
                                                : 0x2000000U) 
                                              >> 1U))))));
        bufp->chgBit(oldp+13230,((1U & ((~ (((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__state))
                                              ? 0x4000U
                                              : 0x2000000U) 
                                            >> 2U)) 
                                        & (((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__state))
                                             ? 0x4000U
                                             : 0x2000000U) 
                                           >> 1U)))));
        bufp->chgBit(oldp+13231,((1U & ((((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__state))
                                           ? 0x4000U
                                           : 0x2000000U) 
                                         >> 2U) & (~ 
                                                   (((1U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__state))
                                                      ? 0x4000U
                                                      : 0x2000000U) 
                                                    >> 1U))))));
        bufp->chgBit(oldp+13232,((1U & ((((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__state))
                                           ? 0x4000U
                                           : 0x2000000U) 
                                         >> 2U) & (
                                                   ((1U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__state))
                                                     ? 0x4000U
                                                     : 0x2000000U) 
                                                   >> 1U)))));
        bufp->chgBit(oldp+13233,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__full)))));
        bufp->chgBit(oldp+13234,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)))));
        bufp->chgCData(oldp+13235,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])),3);
        bufp->chgCData(oldp+13236,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 3U))),2);
        bufp->chgCData(oldp+13237,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                            >> 5U))),4);
        bufp->chgCData(oldp+13238,((0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                             >> 9U))),7);
        bufp->chgBit(oldp+13239,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                        >> 0x10U))));
        bufp->chgBit(oldp+13240,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                        >> 0x11U))));
        bufp->chgQData(oldp+13241,((((QData)((IData)(
                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                     << 0x2eU) | (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                   << 0xeU) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                     >> 0x12U)))),64);
        bufp->chgBit(oldp+13243,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                        >> 0x12U))));
        bufp->chgSData(oldp+13244,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__beatsLeft),9);
        bufp->chgBit(oldp+13245,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__beatsLeft))));
        bufp->chgSData(oldp+13246,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__readys_mask),9);
        bufp->chgBit(oldp+13247,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__state_0));
        bufp->chgBit(oldp+13248,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__state_1));
        bufp->chgBit(oldp+13249,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__state_2));
        bufp->chgBit(oldp+13250,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__state_3));
        bufp->chgBit(oldp+13251,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__state_4));
        bufp->chgBit(oldp+13252,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__state_5));
        bufp->chgBit(oldp+13253,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__state_6));
        bufp->chgBit(oldp+13254,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__state_7));
        bufp->chgBit(oldp+13255,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__state_8));
        bufp->chgBit(oldp+13256,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__latch));
        bufp->chgSData(oldp+13257,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__a_first_counter),9);
        bufp->chgCData(oldp+13258,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__opcode),3);
        bufp->chgCData(oldp+13259,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__param),3);
        bufp->chgCData(oldp+13260,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__size),4);
        bufp->chgCData(oldp+13261,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__source),7);
        bufp->chgIData(oldp+13262,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__address),31);
        bufp->chgSData(oldp+13263,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__d_first_counter),9);
        bufp->chgCData(oldp+13264,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__opcode_1),3);
        bufp->chgCData(oldp+13265,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__param_1),2);
        bufp->chgCData(oldp+13266,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__size_1),4);
        bufp->chgCData(oldp+13267,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__source_1),7);
        bufp->chgBit(oldp+13268,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__sink));
        bufp->chgBit(oldp+13269,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__denied));
        bufp->chgWData(oldp+13270,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight),65);
        bufp->chgWData(oldp+13273,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight_opcodes),260);
        bufp->chgWData(oldp+13282,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight_sizes),520);
        bufp->chgSData(oldp+13299,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__a_first_counter_1),9);
        bufp->chgBit(oldp+13300,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__a_first_counter_1))));
        bufp->chgSData(oldp+13301,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__d_first_counter_1),9);
        bufp->chgBit(oldp+13302,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__d_first_counter_1))));
        bufp->chgIData(oldp+13303,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__watchdog),32);
        bufp->chgSData(oldp+13304,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__d_first_counter_2),9);
        bufp->chgBit(oldp+13305,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__d_first_counter_2))));
        bufp->chgBit(oldp+13306,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__maybe_full)))));
        bufp->chgBit(oldp+13307,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__da_valid));
        bufp->chgCData(oldp+13308,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__da_bits_opcode),3);
        bufp->chgCData(oldp+13309,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__ram_ext__DOT__Memory
                                            [0U][0U] 
                                            >> 6U))),4);
        bufp->chgCData(oldp+13310,((0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__ram_ext__DOT__Memory
                                             [0U][0U] 
                                             >> 0xaU))),7);
        bufp->chgBit(oldp+13311,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__da_bits_opcode))));
        bufp->chgBit(oldp+13312,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__empty)))));
        bufp->chgCData(oldp+13313,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])),3);
        bufp->chgCData(oldp+13314,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                          >> 3U))),3);
        bufp->chgCData(oldp+13315,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                            >> 6U))),4);
        bufp->chgCData(oldp+13316,((0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0xaU))),7);
        bufp->chgSData(oldp+13317,((0x3fffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                               >> 0x11U))),14);
        bufp->chgCData(oldp+13318,((0xffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                              << 1U) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0x1fU)))),8);
        bufp->chgQData(oldp+13319,((((QData)((IData)(
                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                     << 0x39U) | (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                   << 0x19U) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                     >> 7U)))),64);
        bufp->chgBit(oldp+13321,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                        >> 7U))));
        bufp->chgBit(oldp+13322,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full)))));
        bufp->chgBit(oldp+13323,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value));
        bufp->chgBit(oldp+13324,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value));
        bufp->chgBit(oldp+13325,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__maybe_full));
        bufp->chgBit(oldp+13326,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ptr_match));
        bufp->chgBit(oldp+13327,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty));
        bufp->chgBit(oldp+13328,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full));
        bufp->chgBit(oldp+13329,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_enq));
        VL_EXTEND_WI(82,18, __Vtemp_hcd24d8a3__0, (0x20000U 
                                                   | ((0xfe00U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__ram_ext__DOT__Memory
                                                          [0U][0U] 
                                                          >> 1U)) 
                                                      | ((0x1e0U 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__ram_ext__DOT__Memory
                                                             [0U][0U] 
                                                             >> 1U)) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__da_bits_opcode)))));
        __Vtemp_h95b49b13__0[0U] = __Vtemp_hcd24d8a3__0[0U];
        __Vtemp_h95b49b13__0[1U] = __Vtemp_hcd24d8a3__0[1U];
        __Vtemp_h95b49b13__0[2U] = ((0x40000U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__da_bits_opcode) 
                                                 << 0x12U)) 
                                    | __Vtemp_hcd24d8a3__0[2U]);
        bufp->chgWData(oldp+13330,(__Vtemp_h95b49b13__0),83);
        bufp->chgWData(oldp+13333,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data),83);
        bufp->chgWData(oldp+13336,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[0]),83);
        bufp->chgWData(oldp+13339,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[1]),83);
        bufp->chgSData(oldp+13342,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__a_first_counter),9);
        bufp->chgCData(oldp+13343,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__opcode),3);
        bufp->chgCData(oldp+13344,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__param),3);
        bufp->chgCData(oldp+13345,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__size),4);
        bufp->chgCData(oldp+13346,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__source),7);
        bufp->chgSData(oldp+13347,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__address),14);
        bufp->chgSData(oldp+13348,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__d_first_counter),9);
        bufp->chgCData(oldp+13349,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__opcode_1),3);
        bufp->chgCData(oldp+13350,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__param_1),2);
        bufp->chgCData(oldp+13351,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__size_1),4);
        bufp->chgCData(oldp+13352,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__source_1),7);
        bufp->chgBit(oldp+13353,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__sink));
        bufp->chgBit(oldp+13354,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__denied));
        bufp->chgWData(oldp+13355,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight),65);
        bufp->chgWData(oldp+13358,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_opcodes),260);
        bufp->chgWData(oldp+13367,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes),520);
        bufp->chgSData(oldp+13384,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__a_first_counter_1),9);
        bufp->chgBit(oldp+13385,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__a_first_counter_1))));
        bufp->chgSData(oldp+13386,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__d_first_counter_1),9);
        bufp->chgBit(oldp+13387,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__d_first_counter_1))));
        bufp->chgBit(oldp+13388,((6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))));
        bufp->chgIData(oldp+13389,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__watchdog),32);
        bufp->chgSData(oldp+13390,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__d_first_counter_2),9);
        bufp->chgBit(oldp+13391,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__d_first_counter_2))));
        bufp->chgBit(oldp+13392,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__source_ok_1));
        bufp->chgBit(oldp+13393,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value));
        bufp->chgBit(oldp+13394,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value));
        bufp->chgBit(oldp+13395,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__maybe_full));
        bufp->chgBit(oldp+13396,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__ptr_match));
        bufp->chgBit(oldp+13397,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__empty));
        bufp->chgBit(oldp+13398,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__full));
        bufp->chgBit(oldp+13399,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__do_deq));
        bufp->chgWData(oldp+13400,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data),104);
        bufp->chgWData(oldp+13404,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[0]),104);
        bufp->chgWData(oldp+13408,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[1]),104);
        bufp->chgSData(oldp+13412,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a_last_counter),9);
        bufp->chgBit(oldp+13413,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a_last));
        bufp->chgSData(oldp+13414,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__counter),9);
        bufp->chgBit(oldp+13415,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT___a_io_deq_ready_T_3));
        bufp->chgBit(oldp+13416,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__maybe_full));
        bufp->chgCData(oldp+13417,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__ram_ext__DOT__Memory
                                    [0U][0U])),3);
        bufp->chgBit(oldp+13418,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__do_enq));
        __Vtemp_h353c8118__5[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__ram_ext__DOT__Memory
            [0U][0U];
        __Vtemp_h353c8118__5[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__ram_ext__DOT__Memory
            [0U][1U];
        __Vtemp_h353c8118__5[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__ram_ext__DOT__Memory
            [0U][2U];
        __Vtemp_h353c8118__5[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__ram_ext__DOT__Memory
            [0U][3U];
        bufp->chgWData(oldp+13419,(__Vtemp_h353c8118__5),104);
        bufp->chgWData(oldp+13423,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__ram_ext__DOT__Memory[0]),104);
        bufp->chgSData(oldp+13427,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__a_first_counter),9);
        bufp->chgCData(oldp+13428,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__opcode),3);
        bufp->chgCData(oldp+13429,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__param),3);
        bufp->chgCData(oldp+13430,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__size),4);
        bufp->chgCData(oldp+13431,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__source),7);
        bufp->chgSData(oldp+13432,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__address),14);
        bufp->chgSData(oldp+13433,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__d_first_counter),9);
        bufp->chgCData(oldp+13434,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__opcode_1),3);
        bufp->chgCData(oldp+13435,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__param_1),2);
        bufp->chgCData(oldp+13436,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__size_1),4);
        bufp->chgCData(oldp+13437,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__source_1),7);
        bufp->chgBit(oldp+13438,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__sink));
        bufp->chgBit(oldp+13439,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__denied));
        bufp->chgWData(oldp+13440,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__inflight),65);
        bufp->chgWData(oldp+13443,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__inflight_opcodes),260);
        bufp->chgWData(oldp+13452,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__inflight_sizes),520);
        bufp->chgSData(oldp+13469,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__a_first_counter_1),9);
        bufp->chgBit(oldp+13470,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__a_first_counter_1))));
        bufp->chgSData(oldp+13471,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__d_first_counter_1),9);
        bufp->chgBit(oldp+13472,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__d_first_counter_1))));
        bufp->chgBit(oldp+13473,((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__da_bits_opcode))));
        bufp->chgIData(oldp+13474,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__watchdog),32);
        bufp->chgSData(oldp+13475,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__d_first_counter_2),9);
        bufp->chgBit(oldp+13476,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__d_first_counter_2))));
        bufp->chgBit(oldp+13477,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__source_ok));
        bufp->chgBit(oldp+13478,((2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                               >> 6U)))));
        bufp->chgBit(oldp+13479,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+13480,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+13481,((1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                               >> 6U)))));
        bufp->chgBit(oldp+13482,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+13483,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+13484,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+13485,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+13486,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+13487,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+13488,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+13489,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+13490,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc_5) 
                                      << 7U) | (0x3fff80U 
                                                & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_eq_5) 
                                                    << 7U) 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0xaU)))) 
                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc_5) 
                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_eq_5) 
                                            & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 0x11U)))) 
                                        << 6U) | ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc_4) 
                                                    << 5U) 
                                                   | (0xfffe0U 
                                                      & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_eq_4) 
                                                          << 5U) 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                            >> 0xcU)))) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_eq_4) 
                                                          & (~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                              >> 0x11U)))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc_3) 
                                                          << 3U) 
                                                         | (0x3fff8U 
                                                            & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_eq_3) 
                                                                << 3U) 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0xeU)))) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_eq_3) 
                                                                & (~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                    >> 0x11U)))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc_2) 
                                                                << 1U) 
                                                               | (0xfffeU 
                                                                  & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_eq_2) 
                                                                      << 1U) 
                                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                        >> 0x10U)))) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_eq_2) 
                                                                    & (~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                        >> 0x11U)))))))))))),8);
        bufp->chgBit(oldp+13491,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__source_ok_1));
        __Vtemp_hc961d23f__0[0U] = 1U;
        __Vtemp_hc961d23f__0[1U] = 0U;
        __Vtemp_hc961d23f__0[2U] = 0U;
        __Vtemp_hc961d23f__0[3U] = 0U;
        VL_EXTEND_WI(128,7, __Vtemp_h5510ccc3__0, (0x7fU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0xaU)));
        VL_SHIFTL_WWW(128,128,128, __Vtemp_h0bf3af22__0, __Vtemp_hc961d23f__0, __Vtemp_h5510ccc3__0);
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT___same_cycle_resp_T_1) {
            __Vtemp_he55d0783__0[0U] = __Vtemp_h0bf3af22__0[0U];
            __Vtemp_he55d0783__0[1U] = __Vtemp_h0bf3af22__0[1U];
            __Vtemp_he55d0783__0[2U] = (1U & __Vtemp_h0bf3af22__0[2U]);
        } else {
            __Vtemp_he55d0783__0[0U] = 0U;
            __Vtemp_he55d0783__0[1U] = 0U;
            __Vtemp_he55d0783__0[2U] = 0U;
        }
        bufp->chgWData(oldp+13492,(__Vtemp_he55d0783__0),65);
        bufp->chgBit(oldp+13495,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+13496,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__empty)))));
        bufp->chgCData(oldp+13497,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])),3);
        bufp->chgCData(oldp+13498,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                          >> 3U))),3);
        bufp->chgCData(oldp+13499,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                            >> 6U))),4);
        bufp->chgBit(oldp+13500,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                        >> 0xaU))));
        bufp->chgIData(oldp+13501,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                     << 0x15U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 0xbU))),32);
        bufp->chgCData(oldp+13502,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                             >> 0xbU))),8);
        bufp->chgQData(oldp+13503,((((QData)((IData)(
                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                     << 0x2dU) | (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                   << 0xdU) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                     >> 0x13U)))),64);
        bufp->chgBit(oldp+13505,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                        >> 0x13U))));
        bufp->chgBit(oldp+13506,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full)))));
        bufp->chgBit(oldp+13507,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_24_valid));
        bufp->chgCData(oldp+13508,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_24_bits_opcode),3);
        bufp->chgCData(oldp+13509,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_24_bits_param),2);
        bufp->chgCData(oldp+13510,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_24_bits_size),4);
        bufp->chgCData(oldp+13511,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_24_bits_sink),3);
        bufp->chgBit(oldp+13512,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_24_bits_denied));
        bufp->chgQData(oldp+13513,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_4_0)
                                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_in_d_bits_data
                                      : 0ULL) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_4_1)
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_l2_wrapper_auto_coherent_jbar_in_d_bits_data
                                                  : 0ULL))),64);
        bufp->chgBit(oldp+13515,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_4_0) 
                                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__bundleIn_0_d_bits_corrupt)) 
                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_4_1) 
                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_corrupt)))));
        bufp->chgBit(oldp+13516,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__full)))));
        bufp->chgBit(oldp+13517,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__empty)))));
        bufp->chgCData(oldp+13518,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])),3);
        bufp->chgCData(oldp+13519,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 3U))),2);
        bufp->chgCData(oldp+13520,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                            >> 5U))),4);
        bufp->chgCData(oldp+13521,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 0xaU))),3);
        bufp->chgBit(oldp+13522,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                        >> 0xdU))));
        bufp->chgQData(oldp+13523,((((QData)((IData)(
                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                     << 0x32U) | (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                   << 0x12U) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                     >> 0xeU)))),64);
        bufp->chgBit(oldp+13525,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                        >> 0xeU))));
        bufp->chgBit(oldp+13526,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__empty)))));
        bufp->chgCData(oldp+13527,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])),3);
        bufp->chgCData(oldp+13528,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                          >> 3U))),3);
        bufp->chgCData(oldp+13529,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                            >> 6U))),4);
        bufp->chgBit(oldp+13530,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                        >> 0xaU))));
        bufp->chgIData(oldp+13531,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                     << 0x15U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 0xbU))),32);
        bufp->chgCData(oldp+13532,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                             >> 0xbU))),8);
        bufp->chgQData(oldp+13533,((((QData)((IData)(
                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                     << 0x2dU) | (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                   << 0xdU) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                     >> 0x13U)))),64);
        bufp->chgBit(oldp+13535,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                        >> 0x13U))));
        bufp->chgBit(oldp+13536,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__full)))));
        bufp->chgBit(oldp+13537,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                        >> 9U))));
        bufp->chgBit(oldp+13538,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value));
        bufp->chgBit(oldp+13539,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value));
        bufp->chgBit(oldp+13540,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__maybe_full));
        bufp->chgBit(oldp+13541,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__ptr_match));
        bufp->chgBit(oldp+13542,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__empty));
        bufp->chgBit(oldp+13543,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__full));
        bufp->chgBit(oldp+13544,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__do_enq));
        bufp->chgBit(oldp+13545,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__do_deq));
        __Vtemp_h50fe2c8b__0[0U] = (((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_4_0)
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_in_d_bits_data
                                                : 0ULL) 
                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_4_1)
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_l2_wrapper_auto_coherent_jbar_in_d_bits_data
                                                  : 0ULL))) 
                                     << 0xeU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_24_bits_denied) 
                                                  << 0xdU) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_24_bits_sink) 
                                                     << 0xaU) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_24_bits_size) 
                                                        << 5U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_24_bits_param) 
                                                           << 3U) 
                                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_24_bits_opcode))))));
        __Vtemp_h50fe2c8b__0[1U] = (((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_4_0)
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_in_d_bits_data
                                                : 0ULL) 
                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_4_1)
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_l2_wrapper_auto_coherent_jbar_in_d_bits_data
                                                  : 0ULL))) 
                                     >> 0x12U) | ((IData)(
                                                          ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_4_0)
                                                              ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_in_d_bits_data
                                                              : 0ULL) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_4_1)
                                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_l2_wrapper_auto_coherent_jbar_in_d_bits_data
                                                                : 0ULL)) 
                                                           >> 0x20U)) 
                                                  << 0xeU));
        __Vtemp_h50fe2c8b__0[2U] = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_4_0) 
                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__bundleIn_0_d_bits_corrupt)) 
                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_4_1) 
                                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_corrupt))) 
                                     << 0xeU) | ((IData)(
                                                         ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_4_0)
                                                             ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_in_d_bits_data
                                                             : 0ULL) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_4_1)
                                                               ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_l2_wrapper_auto_coherent_jbar_in_d_bits_data
                                                               : 0ULL)) 
                                                          >> 0x20U)) 
                                                 >> 0x12U));
        bufp->chgWData(oldp+13546,(__Vtemp_h50fe2c8b__0),79);
        bufp->chgWData(oldp+13549,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data),79);
        bufp->chgWData(oldp+13552,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[0]),79);
        bufp->chgWData(oldp+13555,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[1]),79);
        bufp->chgSData(oldp+13558,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__a_first_counter),9);
        bufp->chgCData(oldp+13559,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__opcode),3);
        bufp->chgCData(oldp+13560,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__param),3);
        bufp->chgCData(oldp+13561,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__size),4);
        bufp->chgBit(oldp+13562,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__source));
        bufp->chgIData(oldp+13563,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__address),32);
        bufp->chgSData(oldp+13564,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__d_first_counter),9);
        bufp->chgCData(oldp+13565,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__opcode_1),3);
        bufp->chgCData(oldp+13566,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__param_1),2);
        bufp->chgCData(oldp+13567,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__size_1),4);
        bufp->chgBit(oldp+13568,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__source_1));
        bufp->chgCData(oldp+13569,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__sink),3);
        bufp->chgBit(oldp+13570,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__denied));
        bufp->chgBit(oldp+13571,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__inflight));
        bufp->chgCData(oldp+13572,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__inflight_opcodes),4);
        bufp->chgCData(oldp+13573,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__inflight_sizes),8);
        bufp->chgSData(oldp+13574,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__a_first_counter_1),9);
        bufp->chgBit(oldp+13575,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__a_first_counter_1))));
        bufp->chgSData(oldp+13576,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__d_first_counter_1),9);
        bufp->chgBit(oldp+13577,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__d_first_counter_1))));
        bufp->chgBit(oldp+13578,((6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))));
        bufp->chgIData(oldp+13579,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__watchdog),32);
        bufp->chgSData(oldp+13580,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__d_first_counter_2),9);
        bufp->chgBit(oldp+13581,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__d_first_counter_2))));
        bufp->chgBit(oldp+13582,((2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                               >> 6U)))));
        bufp->chgBit(oldp+13583,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+13584,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+13585,((1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                               >> 6U)))));
        bufp->chgBit(oldp+13586,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+13587,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+13588,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+13589,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+13590,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+13591,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+13592,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+13593,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+13594,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc_5) 
                                      << 7U) | (0xfffff80U 
                                                & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_eq_5) 
                                                    << 7U) 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 4U)))) 
                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc_5) 
                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_eq_5) 
                                            & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 0xbU)))) 
                                        << 6U) | ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc_4) 
                                                    << 5U) 
                                                   | (0x3ffffe0U 
                                                      & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_eq_4) 
                                                          << 5U) 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                            >> 6U)))) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_eq_4) 
                                                          & (~ 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                              >> 0xbU)))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc_3) 
                                                          << 3U) 
                                                         | (0xfffff8U 
                                                            & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_eq_3) 
                                                                << 3U) 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 8U)))) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_eq_3) 
                                                                & (~ 
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                    >> 0xbU)))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc_2) 
                                                                << 1U) 
                                                               | (0x3ffffeU 
                                                                  & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                      << 1U) 
                                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                        >> 0xaU)))) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                    & (~ 
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                        >> 0xbU)))))))))))),8);
        bufp->chgBit(oldp+13595,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT___same_cycle_resp_T_1) 
                                  & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                        >> 0xaU)))));
        bufp->chgBit(oldp+13596,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+13597,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__enq_ptr_value));
        bufp->chgBit(oldp+13598,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__deq_ptr_value));
        bufp->chgBit(oldp+13599,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__maybe_full));
        bufp->chgBit(oldp+13600,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__ptr_match));
        bufp->chgBit(oldp+13601,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__empty));
        bufp->chgBit(oldp+13602,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__full));
        bufp->chgBit(oldp+13603,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__do_enq));
        bufp->chgWData(oldp+13604,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data),116);
        bufp->chgWData(oldp+13608,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data),116);
        bufp->chgWData(oldp+13612,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[0]),116);
        bufp->chgWData(oldp+13616,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[1]),116);
        bufp->chgBit(oldp+13620,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tsi_domain_auto_serdesser_client_out_a_valid));
        bufp->chgCData(oldp+13621,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                          >> 0x15U))),3);
        bufp->chgCData(oldp+13622,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                          >> 0x12U))),3);
        bufp->chgCData(oldp+13623,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                            >> 0xeU))),4);
        bufp->chgBit(oldp+13624,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                        >> 0xaU))));
        bufp->chgIData(oldp+13625,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tsi_domain_auto_serdesser_client_out_a_bits_address),32);
        bufp->chgCData(oldp+13626,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_0 
                                             >> 1U))),8);
        bufp->chgQData(oldp+13627,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT___inDes_io_out_bits_data),64);
        bufp->chgBit(oldp+13629,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_0 
                                        >> 9U))));
        bufp->chgBit(oldp+13630,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT___outArb_io_in_1_ready));
        bufp->chgBit(oldp+13631,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__full)))));
        bufp->chgBit(oldp+13632,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)))));
        bufp->chgCData(oldp+13633,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])),3);
        bufp->chgCData(oldp+13634,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 3U))),2);
        bufp->chgCData(oldp+13635,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                            >> 5U))),4);
        bufp->chgBit(oldp+13636,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                        >> 9U))));
        bufp->chgCData(oldp+13637,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 0xaU))),3);
        bufp->chgBit(oldp+13638,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                        >> 0xdU))));
        bufp->chgQData(oldp+13639,((((QData)((IData)(
                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                     << 0x32U) | (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                   << 0x12U) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                     >> 0xeU)))),64);
        bufp->chgBit(oldp+13641,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                        >> 0xeU))));
        bufp->chgBit(oldp+13642,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value));
        bufp->chgBit(oldp+13643,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value));
        bufp->chgBit(oldp+13644,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__maybe_full));
        bufp->chgBit(oldp+13645,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ptr_match));
        bufp->chgBit(oldp+13646,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty));
        bufp->chgBit(oldp+13647,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full));
        bufp->chgBit(oldp+13648,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_enq));
        bufp->chgBit(oldp+13649,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_deq));
        __Vtemp_hfbbb1fa2__0[0U] = (((IData)((((QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                               << 0x32U) 
                                              | (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                  << 0x12U) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                    >> 0xeU)))) 
                                     << 0xeU) | ((0x2000U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]) 
                                                 | ((0x1c00U 
                                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]) 
                                                    | (0x1ffU 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))));
        __Vtemp_hfbbb1fa2__0[1U] = (((IData)((((QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                               << 0x32U) 
                                              | (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                  << 0x12U) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                    >> 0xeU)))) 
                                     >> 0x12U) | ((IData)(
                                                          ((((QData)((IData)(
                                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                                             << 0x32U) 
                                                            | (((QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                                << 0x12U) 
                                                               | ((QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                                  >> 0xeU))) 
                                                           >> 0x20U)) 
                                                  << 0xeU));
        __Vtemp_hfbbb1fa2__0[2U] = ((0x4000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U]) 
                                    | ((IData)(((((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                                  << 0x32U) 
                                                 | (((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                     << 0x12U) 
                                                    | ((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                       >> 0xeU))) 
                                                >> 0x20U)) 
                                       >> 0x12U));
        bufp->chgWData(oldp+13650,(__Vtemp_hfbbb1fa2__0),79);
        bufp->chgWData(oldp+13653,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data),79);
        bufp->chgWData(oldp+13656,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[0]),79);
        bufp->chgWData(oldp+13659,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[1]),79);
        bufp->chgSData(oldp+13662,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__a_first_counter),9);
        bufp->chgCData(oldp+13663,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__opcode),3);
        bufp->chgCData(oldp+13664,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__param),3);
        bufp->chgCData(oldp+13665,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__size),4);
        bufp->chgBit(oldp+13666,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__source));
        bufp->chgIData(oldp+13667,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__address),32);
        bufp->chgSData(oldp+13668,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__d_first_counter),9);
        bufp->chgCData(oldp+13669,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__opcode_1),3);
        bufp->chgCData(oldp+13670,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__param_1),2);
        bufp->chgCData(oldp+13671,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__size_1),4);
        bufp->chgBit(oldp+13672,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__source_1));
        bufp->chgCData(oldp+13673,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__sink),3);
        bufp->chgBit(oldp+13674,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__denied));
        bufp->chgBit(oldp+13675,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__inflight));
        bufp->chgCData(oldp+13676,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__inflight_opcodes),4);
        bufp->chgCData(oldp+13677,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__inflight_sizes),8);
        bufp->chgSData(oldp+13678,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__a_first_counter_1),9);
        bufp->chgBit(oldp+13679,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__a_first_counter_1))));
        bufp->chgSData(oldp+13680,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__d_first_counter_1),9);
        bufp->chgBit(oldp+13681,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__d_first_counter_1))));
        bufp->chgBit(oldp+13682,((6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))));
        bufp->chgIData(oldp+13683,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__watchdog),32);
        bufp->chgSData(oldp+13684,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__d_first_counter_2),9);
        bufp->chgBit(oldp+13685,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__d_first_counter_2))));
        bufp->chgBit(oldp+13686,((2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                               >> 0xeU)))));
        bufp->chgBit(oldp+13687,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+13688,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+13689,((1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                               >> 0xeU)))));
        bufp->chgBit(oldp+13690,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+13691,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+13692,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+13693,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+13694,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+13695,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+13696,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+13697,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+13698,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                         & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tsi_domain_auto_serdesser_client_out_a_bits_address)) 
                                     << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                                    & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tsi_domain_auto_serdesser_client_out_a_bits_address))) 
                                                << 6U) 
                                               | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tsi_domain_auto_serdesser_client_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tsi_domain_auto_serdesser_client_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tsi_domain_auto_serdesser_client_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tsi_domain_auto_serdesser_client_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tsi_domain_auto_serdesser_client_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tsi_domain_auto_serdesser_client_out_a_bits_address))))))))))),8);
        bufp->chgBit(oldp+13699,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT___same_cycle_resp_T_1) 
                                  & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                        >> 0xaU)))));
        bufp->chgBit(oldp+13700,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+13701,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value));
        bufp->chgBit(oldp+13702,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value));
        bufp->chgBit(oldp+13703,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__maybe_full));
        bufp->chgBit(oldp+13704,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ptr_match));
        bufp->chgBit(oldp+13705,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__empty));
        bufp->chgBit(oldp+13706,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__full));
        bufp->chgBit(oldp+13707,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__do_enq));
        bufp->chgBit(oldp+13708,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__do_deq));
        __Vtemp_hcffc7c87__0[0U] = (IData)((((QData)((IData)(
                                                             (0xffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_0 
                                                                 >> 1U)))) 
                                             << 0x2bU) 
                                            | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tsi_domain_auto_serdesser_client_out_a_bits_address)) 
                                                << 0xbU) 
                                               | (QData)((IData)(
                                                                 ((0x400U 
                                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3) 
                                                                  | ((0x3c0U 
                                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                                         >> 8U)) 
                                                                     | ((0x38U 
                                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                                            >> 0xfU)) 
                                                                        | (7U 
                                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                                              >> 0x15U))))))))));
        __Vtemp_hcffc7c87__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT___inDes_io_out_bits_data) 
                                     << 0x13U) | (IData)(
                                                         ((((QData)((IData)(
                                                                            (0xffU 
                                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_0 
                                                                                >> 1U)))) 
                                                            << 0x2bU) 
                                                           | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tsi_domain_auto_serdesser_client_out_a_bits_address)) 
                                                               << 0xbU) 
                                                              | (QData)((IData)(
                                                                                ((0x400U 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3) 
                                                                                | ((0x3c0U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                                                >> 8U)) 
                                                                                | ((0x38U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                                                >> 0xfU)) 
                                                                                | (7U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                                                >> 0x15U))))))))) 
                                                          >> 0x20U)));
        __Vtemp_hcffc7c87__0[2U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT___inDes_io_out_bits_data) 
                                     >> 0xdU) | ((IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT___inDes_io_out_bits_data 
                                                          >> 0x20U)) 
                                                 << 0x13U));
        __Vtemp_hcffc7c87__0[3U] = ((0x80000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_0 
                                                 << 0xaU)) 
                                    | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT___inDes_io_out_bits_data 
                                                >> 0x20U)) 
                                       >> 0xdU));
        bufp->chgWData(oldp+13709,(__Vtemp_hcffc7c87__0),116);
        bufp->chgWData(oldp+13713,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[0]),116);
        bufp->chgWData(oldp+13717,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[1]),116);
        bufp->chgBit(oldp+13721,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT___portsAOI_in_0_a_ready_WIRE));
        bufp->chgBit(oldp+13722,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__out_9_valid));
        bufp->chgCData(oldp+13723,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__out_9_bits_opcode),3);
        bufp->chgCData(oldp+13724,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__out_9_bits_param),2);
        bufp->chgCData(oldp+13725,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__out_9_bits_size),3);
        bufp->chgCData(oldp+13726,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__out_9_bits_source),4);
        bufp->chgBit(oldp+13727,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__out_9_bits_sink));
        bufp->chgBit(oldp+13728,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__out_9_bits_denied));
        bufp->chgQData(oldp+13729,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__muxStateEarly_0)
                                      ? vlSelf->TestHarness__DOT__simdram__DOT_____05Fr_data_reg
                                      : 0ULL) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__muxStateEarly_1)
                                                  ? 
                                                 (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                                   << 0x32U) 
                                                  | (((QData)((IData)(
                                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                      << 0x12U) 
                                                     | ((QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                        >> 0xeU)))
                                                  : 0ULL))),64);
        bufp->chgBit(oldp+13731,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__muxStateEarly_0) 
                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__r_wins) 
                                      & ((0U != (IData)(vlSelf->TestHarness__DOT__simdram__DOT_____05Fr_resp_reg)) 
                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__r_d_denied)))) 
                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__muxStateEarly_1) 
                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                        >> 0xeU)))));
        bufp->chgBit(oldp+13732,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_2_valid));
        bufp->chgCData(oldp+13733,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode),3);
        bufp->chgCData(oldp+13734,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_param),3);
        bufp->chgCData(oldp+13735,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size),3);
        bufp->chgCData(oldp+13736,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source),4);
        bufp->chgIData(oldp+13737,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address),32);
        bufp->chgCData(oldp+13738,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_mask),8);
        bufp->chgQData(oldp+13739,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_data),64);
        bufp->chgBit(oldp+13741,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_0) 
                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[3U] 
                                      >> 0xcU)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1) 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[3U] 
                                                      >> 0x14U)))));
        bufp->chgBit(oldp+13742,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_d_ready));
        bufp->chgBit(oldp+13743,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__maybe_full)))));
        bufp->chgBit(oldp+13744,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceB__DOT__b_valid));
        bufp->chgCData(oldp+13745,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_param),2);
        bufp->chgCData(oldp+13746,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source),6);
        bufp->chgIData(oldp+13747,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address),32);
        bufp->chgBit(oldp+13748,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__c__DOT__full)))));
        bufp->chgBit(oldp+13749,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output));
        bufp->chgCData(oldp+13750,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode),3);
        bufp->chgCData(oldp+13751,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_param),2);
        bufp->chgCData(oldp+13752,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_size),3);
        bufp->chgCData(oldp+13753,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source),6);
        bufp->chgCData(oldp+13754,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_sink),3);
        bufp->chgBit(oldp+13755,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_denied));
        bufp->chgQData(oldp+13756,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_l2_wrapper_auto_coherent_jbar_in_d_bits_data),64);
        bufp->chgBit(oldp+13758,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_corrupt));
        bufp->chgBit(oldp+13759,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s3_valid_d));
        bufp->chgCData(oldp+13760,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__d_bits_opcode),3);
        bufp->chgCData(oldp+13761,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_d_bits_param),2);
        bufp->chgCData(oldp+13762,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s3_req_size),3);
        bufp->chgCData(oldp+13763,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s3_req_source),6);
        bufp->chgCData(oldp+13764,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s3_req_sink),3);
        bufp->chgBit(oldp+13765,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s3_req_bad));
        bufp->chgQData(oldp+13766,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_in_d_bits_data),64);
        bufp->chgBit(oldp+13768,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_d_bits_corrupt));
        bufp->chgBit(oldp+13769,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT__maybe_full)))));
        bufp->chgBit(oldp+13770,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT__maybe_full));
        __Vtemp_h07fba5f3__0[0U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_in_d_bits_data) 
                                     << 0x12U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s3_req_bad) 
                                                   << 0x11U) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s3_req_sink) 
                                                      << 0xeU) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s3_req_source) 
                                                         << 8U) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s3_req_size) 
                                                            << 5U) 
                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_d_bits_param) 
                                                               << 3U) 
                                                              | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__d_bits_opcode)))))));
        __Vtemp_h07fba5f3__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_in_d_bits_data) 
                                     >> 0xeU) | ((IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_in_d_bits_data 
                                                          >> 0x20U)) 
                                                 << 0x12U));
        __Vtemp_h07fba5f3__0[2U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_d_bits_corrupt) 
                                     << 0x12U) | ((IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_in_d_bits_data 
                                                           >> 0x20U)) 
                                                  >> 0xeU));
        bufp->chgWData(oldp+13771,(__Vtemp_h07fba5f3__0),83);
        __Vtemp_haf83fa31__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
            [0U][0U];
        __Vtemp_haf83fa31__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
            [0U][1U];
        __Vtemp_haf83fa31__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
            [0U][2U];
        bufp->chgWData(oldp+13774,(__Vtemp_haf83fa31__0),83);
        bufp->chgWData(oldp+13777,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[0]),83);
        bufp->chgCData(oldp+13780,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__a_first_counter),3);
        bufp->chgCData(oldp+13781,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__opcode),3);
        bufp->chgCData(oldp+13782,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__param),3);
        bufp->chgCData(oldp+13783,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__size),3);
        bufp->chgCData(oldp+13784,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__source),6);
        bufp->chgIData(oldp+13785,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__address),32);
        bufp->chgCData(oldp+13786,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter),3);
        bufp->chgCData(oldp+13787,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__opcode_1),3);
        bufp->chgCData(oldp+13788,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__param_1),2);
        bufp->chgCData(oldp+13789,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__size_1),3);
        bufp->chgCData(oldp+13790,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__source_1),6);
        bufp->chgCData(oldp+13791,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__sink),3);
        bufp->chgBit(oldp+13792,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__denied));
        bufp->chgCData(oldp+13793,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__c_first_counter),3);
        bufp->chgCData(oldp+13794,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__opcode_3),3);
        bufp->chgCData(oldp+13795,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__param_3),3);
        bufp->chgCData(oldp+13796,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__size_3),3);
        bufp->chgCData(oldp+13797,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__source_3),6);
        bufp->chgIData(oldp+13798,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__address_2),32);
        bufp->chgQData(oldp+13799,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__inflight),33);
        bufp->chgWData(oldp+13801,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__inflight_opcodes),132);
        bufp->chgWData(oldp+13806,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__inflight_sizes),132);
        bufp->chgCData(oldp+13811,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__a_first_counter_1),3);
        bufp->chgBit(oldp+13812,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__a_first_counter_1))));
        bufp->chgCData(oldp+13813,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter_1),3);
        bufp->chgBit(oldp+13814,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter_1))));
        bufp->chgBit(oldp+13815,((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))));
        bufp->chgIData(oldp+13816,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__watchdog),32);
        bufp->chgQData(oldp+13817,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__inflight_1),33);
        bufp->chgWData(oldp+13819,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__inflight_sizes_1),132);
        bufp->chgCData(oldp+13824,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__c_first_counter_1),3);
        bufp->chgBit(oldp+13825,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__c_first_counter_1))));
        bufp->chgCData(oldp+13826,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter_2),3);
        bufp->chgBit(oldp+13827,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter_2))));
        bufp->chgIData(oldp+13828,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__watchdog_1),32);
        bufp->chgCData(oldp+13829,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__inflight_2),7);
        bufp->chgCData(oldp+13830,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter_3),3);
        bufp->chgBit(oldp+13831,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter_3))));
        bufp->chgBit(oldp+13832,((((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source)) 
                                           | (IData)(
                                                     ((0U 
                                                       == 
                                                       (0x38U 
                                                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source))) 
                                                      & (5U 
                                                         > 
                                                         (7U 
                                                          & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source)))))) 
                                          | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source))) 
                                         | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source))) 
                                        | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source))) 
                                       | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source))) 
                                      | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source))) 
                                     | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source))) 
                                    | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source))) 
                                   | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source))) 
                                  | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source)))));
        bufp->chgBit(oldp+13833,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__maybe_full));
        __Vtemp_h6b530f7d__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
            [0U][0U];
        __Vtemp_h6b530f7d__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
            [0U][1U];
        __Vtemp_h6b530f7d__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
            [0U][2U];
        __Vtemp_h6b530f7d__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
            [0U][3U];
        bufp->chgWData(oldp+13834,(__Vtemp_h6b530f7d__0),120);
        bufp->chgWData(oldp+13838,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[0]),120);
        bufp->chgCData(oldp+13842,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__a_first_counter),3);
        bufp->chgCData(oldp+13843,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__opcode),3);
        bufp->chgCData(oldp+13844,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__param),3);
        bufp->chgCData(oldp+13845,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__size),3);
        bufp->chgCData(oldp+13846,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__source),4);
        bufp->chgIData(oldp+13847,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__address),32);
        bufp->chgCData(oldp+13848,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__d_first_counter),3);
        bufp->chgCData(oldp+13849,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__opcode_1),3);
        bufp->chgCData(oldp+13850,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__param_1),2);
        bufp->chgCData(oldp+13851,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__size_1),3);
        bufp->chgCData(oldp+13852,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__source_1),4);
        bufp->chgBit(oldp+13853,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__sink));
        bufp->chgBit(oldp+13854,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__denied));
        bufp->chgSData(oldp+13855,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__inflight),10);
        bufp->chgQData(oldp+13856,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__inflight_opcodes),40);
        bufp->chgQData(oldp+13858,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__inflight_sizes),40);
        bufp->chgCData(oldp+13860,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__a_first_counter_1),3);
        bufp->chgBit(oldp+13861,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__a_first_counter_1))));
        bufp->chgCData(oldp+13862,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__d_first_counter_1),3);
        bufp->chgBit(oldp+13863,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__d_first_counter_1))));
        bufp->chgBit(oldp+13864,((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__out_9_bits_opcode))));
        bufp->chgIData(oldp+13865,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__watchdog),32);
        bufp->chgCData(oldp+13866,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__d_first_counter_2),3);
        bufp->chgBit(oldp+13867,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__d_first_counter_2))));
        bufp->chgBit(oldp+13868,((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size)))));
        bufp->chgBit(oldp+13869,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+13870,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+13871,((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size)))));
        bufp->chgBit(oldp+13872,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+13873,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+13874,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+13875,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+13876,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+13877,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+13878,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+13879,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+13880,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_acc_5) 
                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_eq_5) 
                                         & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                     << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_acc_5) 
                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_eq_5) 
                                                    & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                                << 6U) 
                                               | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))))))))))),8);
        bufp->chgSData(oldp+13881,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT___same_cycle_resp_T_1)
                                     ? ((0xfU >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source))
                                         ? (0x3ffU 
                                            & ((IData)(1U) 
                                               << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source)))
                                         : 0U) : 0U)),10);
        bufp->chgBit(oldp+13882,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+13883,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT__empty)))));
        bufp->chgCData(oldp+13884,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[0U])),3);
        bufp->chgCData(oldp+13885,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[0U] 
                                          >> 3U))),3);
        bufp->chgCData(oldp+13886,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[0U] 
                                          >> 6U))),3);
        bufp->chgCData(oldp+13887,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[0U] 
                                          >> 9U))),3);
        bufp->chgIData(oldp+13888,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_out_a_bits_address),32);
        bufp->chgCData(oldp+13889,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[1U] 
                                             >> 0xcU))),8);
        bufp->chgQData(oldp+13890,((((QData)((IData)(
                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[3U])) 
                                     << 0x2cU) | (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[2U])) 
                                                   << 0xcU) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[1U])) 
                                                     >> 0x14U)))),64);
        bufp->chgBit(oldp+13892,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[3U] 
                                        >> 0x14U))));
        bufp->chgBit(oldp+13893,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT__empty)))));
        bufp->chgCData(oldp+13894,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U])),3);
        bufp->chgCData(oldp+13895,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U] 
                                          >> 3U))),3);
        bufp->chgCData(oldp+13896,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U] 
                                          >> 6U))),3);
        bufp->chgCData(oldp+13897,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U] 
                                          >> 9U))),3);
        bufp->chgIData(oldp+13898,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_out_c_bits_address),32);
        bufp->chgQData(oldp+13899,((((QData)((IData)(
                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[3U])) 
                                     << 0x34U) | (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[2U])) 
                                                   << 0x14U) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[1U])) 
                                                     >> 0xcU)))),64);
        bufp->chgBit(oldp+13901,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[3U] 
                                        >> 0xcU))));
        bufp->chgBit(oldp+13902,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkD__DOT__d__DOT__full)))));
        bufp->chgBit(oldp+13903,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceE__DOT__io_e_q__DOT__empty)))));
        bufp->chgCData(oldp+13904,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_out_e_bits_sink),3);
        bufp->chgBit(oldp+13905,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__bundleIn_0_a_ready));
        bufp->chgBit(oldp+13906,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__bundleIn_0_c_ready));
        bufp->chgBit(oldp+13907,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__bundleIn_0_d_valid));
        bufp->chgCData(oldp+13908,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_6_bits_opcode),3);
        bufp->chgCData(oldp+13909,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_6_bits_param),2);
        bufp->chgCData(oldp+13910,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_6_bits_size),3);
        bufp->chgCData(oldp+13911,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_6_bits_source),3);
        bufp->chgCData(oldp+13912,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__bundleIn_0_d_bits_sink),3);
        bufp->chgBit(oldp+13913,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_6_bits_denied));
        bufp->chgQData(oldp+13914,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1_0)
                                       ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__muxStateEarly_0)
                                            ? vlSelf->TestHarness__DOT__simdram__DOT_____05Fr_data_reg
                                            : 0ULL) 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__muxStateEarly_1)
                                              ? (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                                  << 0x32U) 
                                                 | (((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                     << 0x12U) 
                                                    | ((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                       >> 0xeU)))
                                              : 0ULL))
                                       : 0ULL) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1_1)
                                                   ? 
                                                  (((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[2U])) 
                                                    << 0x31U) 
                                                   | (((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[1U])) 
                                                       << 0x11U) 
                                                      | ((QData)((IData)(
                                                                         vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[0U])) 
                                                         >> 0xfU)))
                                                   : 0ULL)) 
                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1_2)
                                        ? (((QData)((IData)(
                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[2U])) 
                                            << 0x31U) 
                                           | (((QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[1U])) 
                                               << 0x11U) 
                                              | ((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[0U])) 
                                                 >> 0xfU)))
                                        : 0ULL))),64);
        bufp->chgBit(oldp+13916,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1_0) 
                                    & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__muxStateEarly_0) 
                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__r_wins) 
                                           & ((0U != (IData)(vlSelf->TestHarness__DOT__simdram__DOT_____05Fr_resp_reg)) 
                                              | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__r_d_denied)))) 
                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__muxStateEarly_1) 
                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                             >> 0xeU)))) 
                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1_1) 
                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[2U] 
                                         >> 0xfU))) 
                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1_2) 
                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[2U] 
                                        >> 0xfU)))));
        bufp->chgBit(oldp+13917,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_6_valid));
        bufp->chgBit(oldp+13918,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT___portsAOI_in_0_a_ready_WIRE) 
                                  & ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__beatsLeft))
                                      ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__winnerQual_0))
                                      : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__state_1)))));
        bufp->chgBit(oldp+13919,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT___portsAOI_in_0_a_ready_WIRE) 
                                  & ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__beatsLeft)) 
                                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__state_0)))));
        bufp->chgBit(oldp+13920,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__toD));
        bufp->chgBit(oldp+13921,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_1_earlyValid));
        bufp->chgCData(oldp+13922,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_1_bits_opcode),3);
        bufp->chgBit(oldp+13923,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__winnerQual_0));
        bufp->chgBit(oldp+13924,((2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U] 
                                               >> 6U)))));
        bufp->chgBit(oldp+13925,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__c_a_bits_a_mask_acc));
        bufp->chgBit(oldp+13926,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__c_a_bits_a_mask_acc_1));
        bufp->chgBit(oldp+13927,((1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U] 
                                               >> 6U)))));
        bufp->chgBit(oldp+13928,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__c_a_bits_a_mask_eq_2));
        bufp->chgBit(oldp+13929,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__c_a_bits_a_mask_acc_2));
        bufp->chgBit(oldp+13930,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__c_a_bits_a_mask_eq_3));
        bufp->chgBit(oldp+13931,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__c_a_bits_a_mask_acc_3));
        bufp->chgBit(oldp+13932,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__c_a_bits_a_mask_eq_4));
        bufp->chgBit(oldp+13933,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__c_a_bits_a_mask_acc_4));
        bufp->chgBit(oldp+13934,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__c_a_bits_a_mask_eq_5));
        bufp->chgBit(oldp+13935,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__c_a_bits_a_mask_acc_5));
        bufp->chgCData(oldp+13936,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__d_first_counter),3);
        bufp->chgBit(oldp+13937,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__d_grant));
        bufp->chgBit(oldp+13938,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_6_ready));
        bufp->chgCData(oldp+13939,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__bundleIn_0_d_bits_sink_r),3);
        bufp->chgBit(oldp+13940,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__wSourceVec_0));
        bufp->chgBit(oldp+13941,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__wSourceVec_1));
        bufp->chgBit(oldp+13942,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__wSourceVec_2));
        bufp->chgBit(oldp+13943,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__wSourceVec_3));
        bufp->chgBit(oldp+13944,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__wSourceVec_4));
        bufp->chgBit(oldp+13945,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__dWHeld_r));
        bufp->chgCData(oldp+13946,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_3_bits_opcode),3);
        bufp->chgCData(oldp+13947,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__beatsLeft),3);
        bufp->chgBit(oldp+13948,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__beatsLeft))));
        bufp->chgBit(oldp+13949,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__winnerQual_0)) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_1_earlyValid))));
        bufp->chgBit(oldp+13950,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__state_0));
        bufp->chgBit(oldp+13951,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__state_1));
        bufp->chgBit(oldp+13952,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_0));
        bufp->chgBit(oldp+13953,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1));
        bufp->chgCData(oldp+13954,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__beatsLeft_1),3);
        bufp->chgBit(oldp+13955,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__beatsLeft_1))));
        bufp->chgBit(oldp+13956,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__out_9_valid)) 
                                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__empty))))));
        bufp->chgBit(oldp+13957,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT___GEN_1)) 
                                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__empty))))));
        bufp->chgBit(oldp+13958,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__state_1_0));
        bufp->chgBit(oldp+13959,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__state_1_1));
        bufp->chgBit(oldp+13960,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__state_1_2));
        bufp->chgBit(oldp+13961,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1_0));
        bufp->chgBit(oldp+13962,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1_1));
        bufp->chgBit(oldp+13963,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1_2));
        bufp->chgBit(oldp+13964,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__winnerQual_1));
        bufp->chgBit(oldp+13965,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__aWOk));
        bufp->chgCData(oldp+13966,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__a_first_counter),3);
        bufp->chgCData(oldp+13967,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__opcode),3);
        bufp->chgCData(oldp+13968,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__param),3);
        bufp->chgCData(oldp+13969,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__size),3);
        bufp->chgCData(oldp+13970,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__source),3);
        bufp->chgIData(oldp+13971,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__address),32);
        bufp->chgCData(oldp+13972,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__d_first_counter),3);
        bufp->chgCData(oldp+13973,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__opcode_1),3);
        bufp->chgCData(oldp+13974,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__param_1),2);
        bufp->chgCData(oldp+13975,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__size_1),3);
        bufp->chgCData(oldp+13976,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__source_1),3);
        bufp->chgCData(oldp+13977,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__sink),3);
        bufp->chgBit(oldp+13978,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__denied));
        bufp->chgCData(oldp+13979,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__c_first_counter),3);
        bufp->chgCData(oldp+13980,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__opcode_3),3);
        bufp->chgCData(oldp+13981,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__param_3),3);
        bufp->chgCData(oldp+13982,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__size_3),3);
        bufp->chgCData(oldp+13983,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__source_3),3);
        bufp->chgIData(oldp+13984,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__address_2),32);
        bufp->chgCData(oldp+13985,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__inflight),5);
        bufp->chgIData(oldp+13986,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__inflight_opcodes),20);
        bufp->chgIData(oldp+13987,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__inflight_sizes),20);
        bufp->chgCData(oldp+13988,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__a_first_counter_1),3);
        bufp->chgBit(oldp+13989,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__a_first_counter_1))));
        bufp->chgCData(oldp+13990,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__d_first_counter_1),3);
        bufp->chgBit(oldp+13991,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__d_first_counter_1))));
        bufp->chgBit(oldp+13992,((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_6_bits_opcode))));
        bufp->chgIData(oldp+13993,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__watchdog),32);
        bufp->chgCData(oldp+13994,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__inflight_1),5);
        bufp->chgIData(oldp+13995,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__inflight_sizes_1),20);
        bufp->chgCData(oldp+13996,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__c_first_counter_1),3);
        bufp->chgBit(oldp+13997,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__c_first_counter_1))));
        bufp->chgCData(oldp+13998,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__d_first_counter_2),3);
        bufp->chgBit(oldp+13999,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__d_first_counter_2))));
        bufp->chgIData(oldp+14000,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__watchdog_1),32);
        bufp->chgCData(oldp+14001,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__inflight_2),8);
        bufp->chgCData(oldp+14002,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__d_first_counter_3),3);
        bufp->chgBit(oldp+14003,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__d_first_counter_3))));
        bufp->chgCData(oldp+14004,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__d_set),8);
        bufp->chgBit(oldp+14005,((2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[0U] 
                                               >> 6U)))));
        bufp->chgBit(oldp+14006,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+14007,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+14008,((1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[0U] 
                                               >> 6U)))));
        bufp->chgBit(oldp+14009,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+14010,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+14011,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+14012,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+14013,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+14014,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+14015,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+14016,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+14017,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_acc_5) 
                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_eq_5) 
                                         & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_out_a_bits_address)) 
                                     << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_acc_5) 
                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_eq_5) 
                                                    & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_out_a_bits_address))) 
                                                << 6U) 
                                               | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_out_a_bits_address))))))))))),8);
        bufp->chgBit(oldp+14018,((((8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_out_c_bits_address 
                                           >> 0x1cU)) 
                                   | (0x10000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_out_c_bits_address 
                                                   >> 0xcU))) 
                                  | (2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_out_c_bits_address 
                                            >> 0x10U)))));
        bufp->chgCData(oldp+14019,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT___same_cycle_resp_T_1)
                                     ? ((7U >= (7U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 9U)))
                                         ? (0x1fU & 
                                            ((IData)(1U) 
                                             << (7U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 9U))))
                                         : 0U) : 0U)),5);
        bufp->chgBit(oldp+14020,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgCData(oldp+14021,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT___same_cycle_resp_T_3) 
                                     & (6U == (6U & 
                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U])))
                                     ? ((7U >= (7U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U] 
                                                   >> 9U)))
                                         ? (0x1fU & 
                                            ((IData)(1U) 
                                             << (7U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U] 
                                                    >> 9U))))
                                         : 0U) : 0U)),5);
        bufp->chgBit(oldp+14022,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT___same_cycle_resp_T_3) 
                                   & (6U == (6U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U]))) 
                                  & ((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U] 
                                            >> 9U)) 
                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_6_bits_source)))));
        bufp->chgBit(oldp+14023,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT____Vcellinp__pool__io_alloc_ready));
        bufp->chgBit(oldp+14024,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__pool__DOT__valid));
        bufp->chgCData(oldp+14025,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__pool__DOT__select),3);
        bufp->chgCData(oldp+14026,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__pool__DOT__bitmap),8);
        bufp->chgCData(oldp+14027,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__pool__DOT__taken),8);
        bufp->chgBit(oldp+14028,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__pool__DOT__REG));
        bufp->chgCData(oldp+14029,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__pool__DOT__bitmap1),8);
        bufp->chgBit(oldp+14030,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT__empty)) 
                                  & (6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U])))));
        bufp->chgBit(oldp+14031,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_6_ready) 
                                  & ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__beatsLeft_1))
                                      ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__out_9_valid))
                                      : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__state_1_1)))));
        bufp->chgBit(oldp+14032,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__full)))));
        bufp->chgBit(oldp+14033,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__empty)))));
        bufp->chgCData(oldp+14034,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[0U])),3);
        bufp->chgCData(oldp+14035,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[0U] 
                                          >> 3U))),2);
        bufp->chgCData(oldp+14036,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[0U] 
                                          >> 5U))),3);
        bufp->chgCData(oldp+14037,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[0U] 
                                          >> 8U))),3);
        bufp->chgCData(oldp+14038,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[0U] 
                                          >> 0xbU))),3);
        bufp->chgBit(oldp+14039,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[0U] 
                                        >> 0xeU))));
        bufp->chgQData(oldp+14040,((((QData)((IData)(
                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[2U])) 
                                     << 0x31U) | (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[1U])) 
                                                   << 0x11U) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[0U])) 
                                                     >> 0xfU)))),64);
        bufp->chgBit(oldp+14042,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[2U] 
                                        >> 0xfU))));
        bufp->chgBit(oldp+14043,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__enq_ptr_value));
        bufp->chgBit(oldp+14044,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__deq_ptr_value));
        bufp->chgBit(oldp+14045,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__maybe_full));
        bufp->chgBit(oldp+14046,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__ptr_match));
        bufp->chgBit(oldp+14047,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__empty));
        bufp->chgBit(oldp+14048,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__full));
        bufp->chgBit(oldp+14049,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__do_enq));
        bufp->chgBit(oldp+14050,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__do_deq));
        VL_EXTEND_WI(80,11, __Vtemp_h6d4f267c__0, (6U 
                                                   | ((0x700U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U] 
                                                          >> 1U)) 
                                                      | (0xe0U 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U] 
                                                            >> 1U)))));
        bufp->chgWData(oldp+14051,(__Vtemp_h6d4f267c__0),80);
        bufp->chgWData(oldp+14054,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data),80);
        bufp->chgWData(oldp+14057,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__ram_ext__DOT__Memory[0]),80);
        bufp->chgWData(oldp+14060,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__ram_ext__DOT__Memory[1]),80);
        bufp->chgBit(oldp+14063,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT__empty)) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__toD))));
        bufp->chgBit(oldp+14064,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_6_ready) 
                                  & ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__beatsLeft_1))
                                      ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT___GEN_1))
                                      : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__state_1_2)))));
        bufp->chgBit(oldp+14065,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__full)))));
        bufp->chgBit(oldp+14066,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__empty)))));
        bufp->chgCData(oldp+14067,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[0U])),3);
        bufp->chgCData(oldp+14068,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[0U] 
                                          >> 3U))),2);
        bufp->chgCData(oldp+14069,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[0U] 
                                          >> 5U))),3);
        bufp->chgCData(oldp+14070,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[0U] 
                                          >> 8U))),3);
        bufp->chgCData(oldp+14071,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[0U] 
                                          >> 0xbU))),3);
        bufp->chgBit(oldp+14072,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[0U] 
                                        >> 0xeU))));
        bufp->chgQData(oldp+14073,((((QData)((IData)(
                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[2U])) 
                                     << 0x31U) | (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[1U])) 
                                                   << 0x11U) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[0U])) 
                                                     >> 0xfU)))),64);
        bufp->chgBit(oldp+14075,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[2U] 
                                        >> 0xfU))));
        bufp->chgBit(oldp+14076,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__enq_ptr_value));
        bufp->chgBit(oldp+14077,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__deq_ptr_value));
        bufp->chgBit(oldp+14078,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__maybe_full));
        bufp->chgBit(oldp+14079,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__ptr_match));
        bufp->chgBit(oldp+14080,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__empty));
        bufp->chgBit(oldp+14081,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__full));
        bufp->chgBit(oldp+14082,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__do_enq));
        bufp->chgBit(oldp+14083,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__do_deq));
        VL_EXTEND_WI(80,11, __Vtemp_h5462a164__0, (4U 
                                                   | ((0x700U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 1U)) 
                                                      | (0xe0U 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[0U] 
                                                            >> 1U)))));
        bufp->chgWData(oldp+14084,(__Vtemp_h5462a164__0),80);
        bufp->chgWData(oldp+14087,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data),80);
        bufp->chgWData(oldp+14090,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__ram_ext__DOT__Memory[0]),80);
        bufp->chgWData(oldp+14093,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__ram_ext__DOT__Memory[1]),80);
        bufp->chgBit(oldp+14096,((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___GEN_4))));
        bufp->chgBit(oldp+14097,((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___GEN_4))));
        bufp->chgBit(oldp+14098,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__flushInValid));
        bufp->chgQData(oldp+14099,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__flushInAddress),64);
        bufp->chgBit(oldp+14101,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__flushOutValid));
        bufp->chgBit(oldp+14102,((4U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                         [0U][0U]))));
        bufp->chgQData(oldp+14103,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_frontMask),64);
        bufp->chgQData(oldp+14105,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_backMask),64);
        bufp->chgCData(oldp+14107,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex),2);
        bufp->chgBit(oldp+14108,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_iready));
        bufp->chgBit(oldp+14109,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oready));
        bufp->chgBit(oldp+14110,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__flushSelect));
        bufp->chgBit(oldp+14111,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_f_wivalid_4));
        bufp->chgBit(oldp+14112,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_f_wivalid_5));
        bufp->chgBit(oldp+14113,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__flushInValid) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__flushSelect))));
        bufp->chgIData(oldp+14114,((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__flushInAddress)),32);
        bufp->chgBit(oldp+14115,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__flushOutValid)))));
        bufp->chgIData(oldp+14116,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_address),32);
        bufp->chgIData(oldp+14117,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[1U] 
                                     << 0x14U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 0xcU))),32);
        bufp->chgIData(oldp+14118,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[1U] 
                                     << 0x14U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U] 
                                                  >> 0xcU))),32);
        bufp->chgBit(oldp+14119,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkX__DOT__x__DOT__maybe_full)))));
        bufp->chgBit(oldp+14120,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceX__DOT__io_x_q__DOT__maybe_full));
        bufp->chgCData(oldp+14121,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_request),7);
        bufp->chgCData(oldp+14122,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__robin_filter),7);
        bufp->chgCData(oldp+14123,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH),7);
        bufp->chgCData(oldp+14124,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__schedule_d_bits_sink),3);
        bufp->chgSData(oldp+14125,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__scheduleTag),13);
        bufp->chgSData(oldp+14126,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__nestedwb_set),10);
        bufp->chgSData(oldp+14127,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__nestedwb_tag),13);
        bufp->chgBit(oldp+14128,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__nestedwb_b_clr_dirty));
        bufp->chgBit(oldp+14129,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__nestedwb_b_toN));
        bufp->chgBit(oldp+14130,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__nestedwb_b_toB));
        bufp->chgBit(oldp+14131,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__nestedwb_c_set_dirty));
        bufp->chgCData(oldp+14132,((3U & (- (IData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___sinkC_io_req_valid))))),2);
        bufp->chgCData(oldp+14133,((0x1fU | (0x60U 
                                             & ((- (IData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___sinkC_io_req_valid))) 
                                                << 5U)))),7);
        bufp->chgIData(oldp+14134,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__selected_requests),21);
        bufp->chgBit(oldp+14135,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__may_pop));
        bufp->chgBit(oldp+14136,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__lb_tag_mismatch));
        bufp->chgBit(oldp+14137,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_uses_directory_assuming_no_bypass));
        bufp->chgCData(oldp+14138,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_insertOH),8);
        bufp->chgCData(oldp+14139,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directoryFanout),8);
        bufp->chgBit(oldp+14140,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directoryFanout))));
        bufp->chgBit(oldp+14141,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___directory_io_result_bits_dirty));
        bufp->chgCData(oldp+14142,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___directory_io_result_bits_state),2);
        bufp->chgCData(oldp+14143,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___directory_io_result_bits_clients),5);
        bufp->chgSData(oldp+14144,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___directory_io_result_bits_tag),13);
        bufp->chgBit(oldp+14145,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___directory_io_result_bits_hit));
        bufp->chgCData(oldp+14146,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___directory_io_result_bits_way),3);
        bufp->chgBit(oldp+14147,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH))));
        bufp->chgBit(oldp+14148,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_0__io_sinkc_valid));
        bufp->chgBit(oldp+14149,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__last));
        bufp->chgSData(oldp+14150,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__tag),13);
        bufp->chgCData(oldp+14151,((0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__c__DOT___ram_ext_R0_data[0U] 
                                             >> 9U))),6);
        bufp->chgCData(oldp+14152,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__c__DOT___ram_ext_R0_data[0U] 
                                          >> 3U))),3);
        bufp->chgBit(oldp+14153,((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__c__DOT___ram_ext_R0_data[0U])));
        bufp->chgBit(oldp+14154,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_0__io_sinkd_valid));
        bufp->chgBit(oldp+14155,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkD__DOT__last));
        bufp->chgCData(oldp+14156,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkD__DOT__d__DOT___ram_ext_R0_data[0U])),3);
        bufp->chgCData(oldp+14157,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkD__DOT__d__DOT___ram_ext_R0_data[0U] 
                                          >> 3U))),3);
        bufp->chgCData(oldp+14158,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkD__DOT__d__DOT___ram_ext_R0_data[0U] 
                                          >> 0xbU))),3);
        bufp->chgBit(oldp+14159,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkD__DOT__d__DOT___ram_ext_R0_data[0U] 
                                        >> 0xeU))));
        bufp->chgBit(oldp+14160,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_valid));
        bufp->chgSData(oldp+14161,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_set),10);
        bufp->chgSData(oldp+14162,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_tag),13);
        bufp->chgCData(oldp+14163,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_way),3);
        bufp->chgBit(oldp+14164,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_valid)))));
        bufp->chgBit(oldp+14165,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_valid) 
                                  & (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_rprobeackfirst)) 
                                      | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_pprobeackfirst))) 
                                     | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_grantfirst))))));
        bufp->chgBit(oldp+14166,((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_a_valid_output) 
                                       | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_b_valid_output)) 
                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_c_valid_output)) 
                                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_d_valid_output)) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_e_valid_output)) 
                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_x_valid_output)) 
                                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_valid_output))));
        bufp->chgBit(oldp+14167,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_a_valid_output));
        bufp->chgCData(oldp+14168,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__req_needT)
                                     ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
                                         ? 2U : 1U)
                                     : 0U)),3);
        bufp->chgBit(oldp+14169,((1U & ((6U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_size)) 
                                        | (~ ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_opcode)) 
                                              | (7U 
                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_opcode))))))));
    }
}
