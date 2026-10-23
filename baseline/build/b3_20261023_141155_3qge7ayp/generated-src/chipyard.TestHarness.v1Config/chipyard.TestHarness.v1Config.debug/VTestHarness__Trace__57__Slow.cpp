// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "VTestHarness__Syms.h"


extern const VlWide<8>/*255:0*/ VTestHarness__ConstPool__CONST_h5b889007_0;

VL_ATTR_COLD void VTestHarness___024root__trace_full_sub_34(VTestHarness___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root__trace_full_sub_34\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<4>/*127:0*/ __Vtemp_h734a3fd7__0;
    VlWide<4>/*127:0*/ __Vtemp_h30b2a9a8__0;
    VlWide<4>/*127:0*/ __Vtemp_h2c3c2a30__0;
    VlWide<4>/*127:0*/ __Vtemp_h540bf809__0;
    VlWide<4>/*127:0*/ __Vtemp_h32ee9402__0;
    VlWide<4>/*127:0*/ __Vtemp_h26aa32e8__0;
    VlWide<6>/*191:0*/ __Vtemp_h01528036__0;
    VlWide<6>/*191:0*/ __Vtemp_ha428ae90__0;
    VlWide<8>/*255:0*/ __Vtemp_h86d15f1c__0;
    VlWide<8>/*255:0*/ __Vtemp_h860b9f1e__89;
    VlWide<20>/*639:0*/ __Vtemp_hfcdbafcc__17;
    VlWide<4>/*127:0*/ __Vtemp_h9acaeb9e__0;
    VlWide<4>/*127:0*/ __Vtemp_h9d2b6528__0;
    VlWide<38>/*1215:0*/ __Vtemp_h97de8984__69;
    VlWide<3>/*95:0*/ __Vtemp_hf1b6c900__0;
    VlWide<14>/*447:0*/ __Vtemp_hc02632b9__0;
    VlWide<8>/*255:0*/ __Vtemp_ha8838ae6__0;
    VlWide<4>/*127:0*/ __Vtemp_he033613f__0;
    VlWide<5>/*159:0*/ __Vtemp_h44069745__0;
    VlWide<5>/*159:0*/ __Vtemp_hd0209713__0;
    // Body
    bufp->fullBit(oldp+98208,((((((IData)((0x63U == 
                                           (0x207fU 
                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT____Vcellinp__bpd_decoder0_1__io_inst))) 
                                  | (IData)((0x4063U 
                                             == (0x407fU 
                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT____Vcellinp__bpd_decoder0_1__io_inst)))) 
                                 & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT____Vcellinp__bpd_decoder0_1__io_inst 
                                       >> 0x1fU))) 
                                & (IData)((0U != (0x7e000f80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT____Vcellinp__bpd_decoder0_1__io_inst)))) 
                               & (0U == ((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT____Vcellinp__bpd_decoder0_1__io_inst 
                                                   >> 2U)) 
                                         | (0x1fU & 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT____Vcellinp__bpd_decoder0_1__io_inst 
                                             >> 0x1aU)))))));
    bufp->fullCData(oldp+98209,(((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT____Vcellinp__bpd_decoder0_1__io_inst 
                                           >> 0x14U)) 
                                 | (0x1eU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT____Vcellinp__bpd_decoder0_1__io_inst 
                                             >> 7U)))),6);
    bufp->fullBit(oldp+98210,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder0_1_io_out_shadowable));
    bufp->fullBit(oldp+98211,((IData)((((0x1ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder0b__DOT___bpd_csignals_decoded_T_14)) 
                                        & (0U == (0xf80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b))) 
                                       & (1U == ((0xcU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b 
                                                     >> 0x10U)) 
                                                 | (3U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b 
                                                       >> 0xfU))))))));
    bufp->fullBit(oldp+98212,((IData)(((0x80U == (0xf80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b)) 
                                       & ((0x7fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder0b__DOT___bpd_csignals_decoded_T_16)) 
                                          | (0x1ffU 
                                             == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder0b__DOT___bpd_csignals_decoded_T_14)))))));
    bufp->fullQData(oldp+98213,(((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder0b__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6))
                                  ? (0xfffffffffeULL 
                                     & (6ULL + ((~ 
                                                 (7ULL 
                                                  | (~ 
                                                     (((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                       [0U][1U])) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                        [0U][0U])))))) 
                                                + (
                                                   ((QData)((IData)(
                                                                    (0xfffffffU 
                                                                     & (- (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b 
                                                                                >> 0x1fU)))))) 
                                                    << 0xcU) 
                                                   | (QData)((IData)(
                                                                     ((0x800U 
                                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b 
                                                                          << 4U)) 
                                                                      | ((0x7e0U 
                                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b 
                                                                             >> 0x14U)) 
                                                                         | (0x1eU 
                                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b 
                                                                               >> 7U))))))))))
                                  : (0xfffffffffeULL 
                                     & (6ULL + ((~ 
                                                 (7ULL 
                                                  | (~ 
                                                     (((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                       [0U][1U])) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                        [0U][0U])))))) 
                                                + (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b 
                                                                                >> 0x1fU)))))) 
                                                    << 0x14U) 
                                                   | (QData)((IData)(
                                                                     ((0xff000U 
                                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b) 
                                                                      | ((0x800U 
                                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b 
                                                                             >> 9U)) 
                                                                         | (0x7feU 
                                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b 
                                                                               >> 0x14U)))))))))))),40);
    bufp->fullCData(oldp+98215,(((0x1ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder0b__DOT___bpd_csignals_decoded_T_14))
                                  ? 3U : ((0x7fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder0b__DOT___bpd_csignals_decoded_T_16))
                                           ? 2U : (0U 
                                                   != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder0b__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6))))),3);
    bufp->fullBit(oldp+98216,(((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder0b__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6)) 
                                 & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b 
                                       >> 0x1fU))) 
                                & (IData)((0U != (0x7e000f80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b)))) 
                               & (0U == ((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b 
                                                   >> 2U)) 
                                         | (0x1fU & 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b 
                                             >> 0x1aU)))))));
    bufp->fullCData(oldp+98217,(((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b 
                                           >> 0x14U)) 
                                 | (0x1eU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b 
                                             >> 7U)))),6);
    bufp->fullBit(oldp+98218,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder0b_io_out_shadowable));
    bufp->fullBit(oldp+98219,((IData)((((0x1ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder1__DOT___bpd_csignals_decoded_T_14)) 
                                        & (0U == (0xf80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1))) 
                                       & (1U == ((0xcU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1 
                                                     >> 0x10U)) 
                                                 | (3U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1 
                                                       >> 0xfU))))))));
    bufp->fullBit(oldp+98220,((IData)(((0x80U == (0xf80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1)) 
                                       & ((0x7fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder1__DOT___bpd_csignals_decoded_T_16)) 
                                          | (0x1ffU 
                                             == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder1__DOT___bpd_csignals_decoded_T_14)))))));
    bufp->fullQData(oldp+98221,(((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder1__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6))
                                  ? (0xfffffffffeULL 
                                     & ((~ (7ULL | 
                                            (~ (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                 [0U][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                  [0U][0U])))))) 
                                        + (((QData)((IData)(
                                                            (0xfffffffU 
                                                             & (- (IData)(
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1 
                                                                           >> 0x1fU)))))) 
                                            << 0xcU) 
                                           | (QData)((IData)(
                                                             ((0x800U 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1 
                                                                  << 4U)) 
                                                              | ((0x7e0U 
                                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1 
                                                                     >> 0x14U)) 
                                                                 | (0x1eU 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1 
                                                                       >> 7U)))))))))
                                  : (0xfffffffffeULL 
                                     & ((~ (7ULL | 
                                            (~ (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                 [0U][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                  [0U][0U])))))) 
                                        + (((QData)((IData)(
                                                            (0xfffffU 
                                                             & (- (IData)(
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1 
                                                                           >> 0x1fU)))))) 
                                            << 0x14U) 
                                           | (QData)((IData)(
                                                             ((0xff000U 
                                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1) 
                                                              | ((0x800U 
                                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1 
                                                                     >> 9U)) 
                                                                 | (0x7feU 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1 
                                                                       >> 0x14U))))))))))),40);
    bufp->fullCData(oldp+98223,(((0x1ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder1__DOT___bpd_csignals_decoded_T_14))
                                  ? 3U : ((0x7fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder1__DOT___bpd_csignals_decoded_T_16))
                                           ? 2U : (0U 
                                                   != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder1__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6))))),3);
    bufp->fullBit(oldp+98224,(((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder1__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6)) 
                                 & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1 
                                       >> 0x1fU))) 
                                & (IData)((0U != (0x7e000f80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1)))) 
                               & (0U == ((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1 
                                                   >> 2U)) 
                                         | (0x1fU & 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1 
                                             >> 0x1aU)))))));
    bufp->fullCData(oldp+98225,(((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1 
                                           >> 0x14U)) 
                                 | (0x1eU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1 
                                             >> 7U)))),6);
    bufp->fullBit(oldp+98226,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder1_io_out_shadowable));
    bufp->fullQData(oldp+98227,((0xffffffffffULL & 
                                 (8ULL + (~ (7ULL | 
                                             (~ (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                  [0U][1U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                   [0U][0U]))))))))),40);
    bufp->fullBit(oldp+98229,((IData)((((0x1ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder1_1__DOT___bpd_csignals_decoded_T_14)) 
                                        & (0U == (0xf80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1))) 
                                       & (1U == ((0xcU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1 
                                                     >> 0x10U)) 
                                                 | (3U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1 
                                                       >> 0xfU))))))));
    bufp->fullBit(oldp+98230,((IData)(((0x80U == (0xf80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1)) 
                                       & ((0x7fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder1_1__DOT___bpd_csignals_decoded_T_16)) 
                                          | (0x1ffU 
                                             == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder1_1__DOT___bpd_csignals_decoded_T_14)))))));
    bufp->fullQData(oldp+98231,(((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder1_1__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6))
                                  ? (0xfffffffffeULL 
                                     & (8ULL + ((~ 
                                                 (7ULL 
                                                  | (~ 
                                                     (((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                       [0U][1U])) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                        [0U][0U])))))) 
                                                + (
                                                   ((QData)((IData)(
                                                                    (0xfffffffU 
                                                                     & (- (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1 
                                                                                >> 0x1fU)))))) 
                                                    << 0xcU) 
                                                   | (QData)((IData)(
                                                                     ((0x800U 
                                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1 
                                                                          << 4U)) 
                                                                      | ((0x7e0U 
                                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1 
                                                                             >> 0x14U)) 
                                                                         | (0x1eU 
                                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1 
                                                                               >> 7U))))))))))
                                  : (0xfffffffffeULL 
                                     & (8ULL + ((~ 
                                                 (7ULL 
                                                  | (~ 
                                                     (((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                       [0U][1U])) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                        [0U][0U])))))) 
                                                + (
                                                   ((QData)((IData)(
                                                                    (0xfffffU 
                                                                     & (- (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1 
                                                                                >> 0x1fU)))))) 
                                                    << 0x14U) 
                                                   | (QData)((IData)(
                                                                     ((0xff000U 
                                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1) 
                                                                      | ((0x800U 
                                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1 
                                                                             >> 9U)) 
                                                                         | (0x7feU 
                                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1 
                                                                               >> 0x14U)))))))))))),40);
    bufp->fullCData(oldp+98233,(((0x1ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder1_1__DOT___bpd_csignals_decoded_T_14))
                                  ? 3U : ((0x7fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder1_1__DOT___bpd_csignals_decoded_T_16))
                                           ? 2U : (0U 
                                                   != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder1_1__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6))))),3);
    bufp->fullBit(oldp+98234,(((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder1_1__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6)) 
                                 & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1 
                                       >> 0x1fU))) 
                                & (IData)((0U != (0x7e000f80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1)))) 
                               & (0U == ((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1 
                                                   >> 2U)) 
                                         | (0x1fU & 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1 
                                             >> 0x1aU)))))));
    bufp->fullCData(oldp+98235,(((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1 
                                           >> 0x14U)) 
                                 | (0x1eU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1 
                                             >> 7U)))),6);
    bufp->fullBit(oldp+98236,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder1_1_io_out_shadowable));
    bufp->fullQData(oldp+98237,((0xffffffffffULL & 
                                 (4ULL + (~ (7ULL | 
                                             (~ (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                  [0U][1U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                   [0U][0U]))))))))),40);
    bufp->fullBit(oldp+98239,((IData)((((0x1ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_1__DOT___bpd_csignals_decoded_T_14)) 
                                        & (0U == (0xf80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_2))) 
                                       & (1U == ((0xcU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_2 
                                                     >> 0x10U)) 
                                                 | (3U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_2 
                                                       >> 0xfU))))))));
    bufp->fullBit(oldp+98240,((IData)(((0x80U == (0xf80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_2)) 
                                       & ((0x7fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_1__DOT___bpd_csignals_decoded_T_16)) 
                                          | (0x1ffU 
                                             == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_1__DOT___bpd_csignals_decoded_T_14)))))));
    bufp->fullQData(oldp+98241,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_1_io_out_target),40);
    bufp->fullCData(oldp+98243,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_1_io_out_cfi_type),3);
    bufp->fullBit(oldp+98244,(((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_1__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6)) 
                                 & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_2 
                                       >> 0x1fU))) 
                                & (IData)((0U != (0x7e000f80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_2)))) 
                               & (0U == ((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_2 
                                                   >> 2U)) 
                                         | (0x1fU & 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_2 
                                             >> 0x1aU)))))));
    bufp->fullCData(oldp+98245,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_1_io_out_sfb_offset_bits),6);
    bufp->fullBit(oldp+98246,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_1_io_out_shadowable));
    bufp->fullBit(oldp+98247,((IData)((((0x1ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_2__DOT___bpd_csignals_decoded_T_14)) 
                                        & (0U == (0xf80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_3))) 
                                       & (1U == ((0xcU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_3 
                                                     >> 0x10U)) 
                                                 | (3U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_3 
                                                       >> 0xfU))))))));
    bufp->fullBit(oldp+98248,((IData)(((0x80U == (0xf80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_3)) 
                                       & ((0x7fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_2__DOT___bpd_csignals_decoded_T_16)) 
                                          | (0x1ffU 
                                             == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_2__DOT___bpd_csignals_decoded_T_14)))))));
    bufp->fullQData(oldp+98249,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_2_io_out_target),40);
    bufp->fullCData(oldp+98251,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_2_io_out_cfi_type),3);
    bufp->fullBit(oldp+98252,(((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_2__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6)) 
                                 & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_3 
                                       >> 0x1fU))) 
                                & (IData)((0U != (0x7e000f80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_3)))) 
                               & (0U == ((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_3 
                                                   >> 2U)) 
                                         | (0x1fU & 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_3 
                                             >> 0x1aU)))))));
    bufp->fullCData(oldp+98253,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_2_io_out_sfb_offset_bits),6);
    bufp->fullBit(oldp+98254,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_2_io_out_shadowable));
    bufp->fullQData(oldp+98255,((0xffffffffffULL & 
                                 (0xaULL + (~ (7ULL 
                                               | (~ 
                                                  (((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                    [0U][1U])) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                     [0U][0U]))))))))),40);
    bufp->fullBit(oldp+98257,((IData)((((0x1ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_3__DOT___bpd_csignals_decoded_T_14)) 
                                        & (0U == (0xf80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_5))) 
                                       & (1U == ((0xcU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_5 
                                                     >> 0x10U)) 
                                                 | (3U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_5 
                                                       >> 0xfU))))))));
    bufp->fullBit(oldp+98258,((IData)(((0x80U == (0xf80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_5)) 
                                       & ((0x7fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_3__DOT___bpd_csignals_decoded_T_16)) 
                                          | (0x1ffU 
                                             == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_3__DOT___bpd_csignals_decoded_T_14)))))));
    bufp->fullQData(oldp+98259,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_3_io_out_target),40);
    bufp->fullCData(oldp+98261,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_3_io_out_cfi_type),3);
    bufp->fullBit(oldp+98262,(((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_3__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6)) 
                                 & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_5 
                                       >> 0x1fU))) 
                                & (IData)((0U != (0x7e000f80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_5)))) 
                               & (0U == ((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_5 
                                                   >> 2U)) 
                                         | (0x1fU & 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_5 
                                             >> 0x1aU)))))));
    bufp->fullCData(oldp+98263,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_3_io_out_sfb_offset_bits),6);
    bufp->fullBit(oldp+98264,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_3_io_out_shadowable));
    bufp->fullQData(oldp+98265,((0xffffffffffULL & 
                                 (0xcULL + (~ (7ULL 
                                               | (~ 
                                                  (((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                    [0U][1U])) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                     [0U][0U]))))))))),40);
    bufp->fullBit(oldp+98267,((IData)((((0x1ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_4__DOT___bpd_csignals_decoded_T_14)) 
                                        & (0U == (0xf80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_6))) 
                                       & (1U == ((0xcU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_6 
                                                     >> 0x10U)) 
                                                 | (3U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_6 
                                                       >> 0xfU))))))));
    bufp->fullBit(oldp+98268,((IData)(((0x80U == (0xf80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_6)) 
                                       & ((0x7fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_4__DOT___bpd_csignals_decoded_T_16)) 
                                          | (0x1ffU 
                                             == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_4__DOT___bpd_csignals_decoded_T_14)))))));
    bufp->fullQData(oldp+98269,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_4_io_out_target),40);
    bufp->fullCData(oldp+98271,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_4_io_out_cfi_type),3);
    bufp->fullBit(oldp+98272,(((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_4__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6)) 
                                 & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_6 
                                       >> 0x1fU))) 
                                & (IData)((0U != (0x7e000f80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_6)))) 
                               & (0U == ((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_6 
                                                   >> 2U)) 
                                         | (0x1fU & 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_6 
                                             >> 0x1aU)))))));
    bufp->fullCData(oldp+98273,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_4_io_out_sfb_offset_bits),6);
    bufp->fullBit(oldp+98274,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_4_io_out_shadowable));
    bufp->fullQData(oldp+98275,((0xffffffffffULL & 
                                 (0xeULL + (~ (7ULL 
                                               | (~ 
                                                  (((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                    [0U][1U])) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                     [0U][0U]))))))))),40);
    bufp->fullBit(oldp+98277,((IData)((((0x1ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_5__DOT___bpd_csignals_decoded_T_14)) 
                                        & (0U == (0xf80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_7))) 
                                       & (1U == ((0xcU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_7 
                                                     >> 0x10U)) 
                                                 | (3U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_7 
                                                       >> 0xfU))))))));
    bufp->fullBit(oldp+98278,((IData)(((0x80U == (0xf80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_7)) 
                                       & ((0x7fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_5__DOT___bpd_csignals_decoded_T_16)) 
                                          | (0x1ffU 
                                             == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_5__DOT___bpd_csignals_decoded_T_14)))))));
    bufp->fullQData(oldp+98279,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_5_io_out_target),40);
    bufp->fullCData(oldp+98281,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_5_io_out_cfi_type),3);
    bufp->fullBit(oldp+98282,(((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_5__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6)) 
                                 & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_7 
                                       >> 0x1fU))) 
                                & (IData)((0U != (0x7e000f80U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_7)))) 
                               & (0U == ((0x20U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_7 
                                                   >> 2U)) 
                                         | (0x1fU & 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_7 
                                             >> 0x1aU)))))));
    bufp->fullCData(oldp+98283,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_5_io_out_sfb_offset_bits),6);
    bufp->fullBit(oldp+98284,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_5_io_out_shadowable));
    bufp->fullBit(oldp+98285,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___ftq_io_bpdupdate_valid));
    bufp->fullBit(oldp+98286,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__io_bpdupdate_bits_is_mispredict_update_REG));
    bufp->fullBit(oldp+98287,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__io_bpdupdate_bits_is_repair_update_REG));
    bufp->fullQData(oldp+98288,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_pc),40);
    bufp->fullCData(oldp+98290,(((((- (IData)((1U & 
                                               (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_entry_cfi_idx_valid))))) 
                                   | ((7U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_entry_cfi_idx_bits))
                                       ? ((IData)(1U) 
                                          << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_entry_cfi_idx_bits))
                                       : 0U)) | (((7U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_entry_cfi_idx_bits)) 
                                                  << 6U) 
                                                 | ((0x20U 
                                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_10)) 
                                                    | ((0x10U 
                                                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_11)) 
                                                       | ((8U 
                                                           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_12)) 
                                                          | ((4U 
                                                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_13)) 
                                                             | ((2U 
                                                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_14)) 
                                                                | (1U 
                                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_14) 
                                                                      | (7U 
                                                                         == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_entry_cfi_idx_bits))))))))))) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_entry_br_mask))),8);
    bufp->fullBit(oldp+98291,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_entry_cfi_idx_valid));
    bufp->fullCData(oldp+98292,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_entry_cfi_idx_bits),3);
    bufp->fullBit(oldp+98293,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_entry_cfi_taken));
    bufp->fullBit(oldp+98294,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_entry_cfi_mispredicted));
    bufp->fullBit(oldp+98295,(((7U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_entry_cfi_idx_bits))
                                ? (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_entry_br_mask) 
                                         >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_entry_cfi_idx_bits)))
                                : 0U)));
    bufp->fullBit(oldp+98296,(((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_entry_cfi_type)) 
                               | (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_entry_cfi_type)))));
    bufp->fullQData(oldp+98297,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram_R_0_data[1U])) 
                                  << 0x20U) | (QData)((IData)(
                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram_R_0_data[0U])))),64);
    bufp->fullBit(oldp+98299,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram_R_0_data[2U] 
                                     >> 1U))));
    bufp->fullBit(oldp+98300,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram_R_0_data[2U] 
                                     >> 2U))));
    bufp->fullQData(oldp+98301,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_target),40);
    __Vtemp_h734a3fd7__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram_R_0_data[0U];
    __Vtemp_h734a3fd7__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram_R_0_data[1U];
    __Vtemp_h734a3fd7__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram_R_0_data[2U];
    __Vtemp_h734a3fd7__0[3U] = (0xffffffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram_R_0_data[3U]);
    bufp->fullWData(oldp+98303,(__Vtemp_h734a3fd7__0),120);
    __Vtemp_h30b2a9a8__0[0U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram_R_0_data[4U] 
                                 << 8U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram_R_0_data[3U] 
                                           >> 0x18U));
    __Vtemp_h30b2a9a8__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram_R_0_data[5U] 
                                 << 8U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram_R_0_data[4U] 
                                           >> 0x18U));
    __Vtemp_h30b2a9a8__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram_R_0_data[6U] 
                                 << 8U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram_R_0_data[5U] 
                                           >> 0x18U));
    __Vtemp_h30b2a9a8__0[3U] = (0xffffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram_R_0_data[7U] 
                                              << 8U) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram_R_0_data[6U] 
                                                >> 0x18U)));
    bufp->fullWData(oldp+98307,(__Vtemp_h30b2a9a8__0),120);
    bufp->fullBit(oldp+98311,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT__empty)))));
    bufp->fullBit(oldp+98312,((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[0U])));
    bufp->fullBit(oldp+98313,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[0U] 
                                     >> 1U))));
    bufp->fullCData(oldp+98314,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[0U] 
                                          >> 2U))),8);
    bufp->fullQData(oldp+98315,((0xffffffffffULL & 
                                 (((QData)((IData)(
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[1U])) 
                                   << 0x16U) | ((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[0U])) 
                                                >> 0xaU)))),40);
    bufp->fullCData(oldp+98317,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[1U] 
                                          >> 0x12U))),8);
    bufp->fullBit(oldp+98318,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[1U] 
                                     >> 0x1aU))));
    bufp->fullCData(oldp+98319,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[1U] 
                                       >> 0x1bU))),3);
    bufp->fullBit(oldp+98320,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[1U] 
                                     >> 0x1eU))));
    bufp->fullBit(oldp+98321,((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[1U] 
                               >> 0x1fU)));
    bufp->fullBit(oldp+98322,((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[2U])));
    bufp->fullBit(oldp+98323,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[2U] 
                                     >> 1U))));
    bufp->fullQData(oldp+98324,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[4U])) 
                                  << 0x3dU) | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[3U])) 
                                                << 0x1dU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[2U])) 
                                                  >> 3U)))),64);
    bufp->fullBit(oldp+98326,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[4U] 
                                     >> 4U))));
    bufp->fullBit(oldp+98327,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[4U] 
                                     >> 5U))));
    bufp->fullQData(oldp+98328,((0xffffffffffULL & 
                                 (((QData)((IData)(
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[5U])) 
                                   << 0x13U) | ((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[4U])) 
                                                >> 0xdU)))),40);
    __Vtemp_h2c3c2a30__0[0U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[6U] 
                                 << 0xbU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[5U] 
                                             >> 0x15U));
    __Vtemp_h2c3c2a30__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[7U] 
                                 << 0xbU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[6U] 
                                             >> 0x15U));
    __Vtemp_h2c3c2a30__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[8U] 
                                 << 0xbU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[7U] 
                                             >> 0x15U));
    __Vtemp_h2c3c2a30__0[3U] = (0xffffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[9U] 
                                              << 0xbU) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[8U] 
                                                >> 0x15U)));
    bufp->fullWData(oldp+98330,(__Vtemp_h2c3c2a30__0),120);
    __Vtemp_h540bf809__0[0U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[0xaU] 
                                 << 0x13U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[9U] 
                                              >> 0xdU));
    __Vtemp_h540bf809__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[0xbU] 
                                 << 0x13U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[0xaU] 
                                              >> 0xdU));
    __Vtemp_h540bf809__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[0xcU] 
                                 << 0x13U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[0xbU] 
                                              >> 0xdU));
    __Vtemp_h540bf809__0[3U] = (0xffffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[0xdU] 
                                              << 0x13U) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data[0xcU] 
                                                >> 0xdU)));
    bufp->fullWData(oldp+98334,(__Vtemp_h540bf809__0),120);
    bufp->fullBit(oldp+98338,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___ftq_io_bpdupdate_valid)))));
    bufp->fullIData(oldp+98339,((((((((((0x1fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2)) 
                                        | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))) 
                                       | (0x1dU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))) 
                                      | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))) 
                                     | (0x1bU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))) 
                                    | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))) 
                                   | (0x19U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))) 
                                  | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2)))
                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0
                                  : ((0x17U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))
                                      ? (0x13023U | 
                                         ((0x1c000000U 
                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0 
                                              << 0x13U)) 
                                          | ((0x2000000U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0 
                                                 << 0xdU)) 
                                             | ((0x1f00000U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0 
                                                    << 0x12U)) 
                                                | (0xc00U 
                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0)))))
                                      : ((0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))
                                          ? (0x12023U 
                                             | ((0xc000000U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0 
                                                    << 0x13U)) 
                                                | ((0x2000000U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0 
                                                       << 0xdU)) 
                                                   | ((0x1f00000U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0 
                                                          << 0x12U)) 
                                                      | (0xe00U 
                                                         & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0)))))
                                          : ((0x15U 
                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))
                                              ? (0x13027U 
                                                 | ((0x1c000000U 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0 
                                                        << 0x13U)) 
                                                    | ((0x2000000U 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0 
                                                           << 0xdU)) 
                                                       | ((0x1f00000U 
                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0 
                                                              << 0x12U)) 
                                                          | (0xc00U 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0)))))
                                              : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_42_bits))))),32);
    bufp->fullCData(oldp+98340,(((0x9fU >= (0xffU & 
                                            ((IData)(5U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))))
                                  ? (0x1fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))))
                                                ? 0U
                                                : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___GEN_2[
                                                   (((IData)(4U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(5U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2)))))) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___GEN_2[
                                                 (7U 
                                                  & (((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))))))
                                  : 0U)),5);
    bufp->fullCData(oldp+98341,(((0x9fU >= (0xffU & 
                                            ((IData)(5U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))))
                                  ? (0x1fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))))
                                                ? 0U
                                                : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___GEN_3[
                                                   (((IData)(4U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(5U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2)))))) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___GEN_3[
                                                 (7U 
                                                  & (((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))))))
                                  : 0U)),5);
    bufp->fullCData(oldp+98342,((0x1fU & (((((((((0x1fU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2)) 
                                                 | (0x1eU 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))) 
                                                | (0x1dU 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))) 
                                               | (0x1cU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))) 
                                              | (0x1bU 
                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))) 
                                             | (0x1aU 
                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))) 
                                            | (0x19U 
                                               == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))) 
                                           | (0x18U 
                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2)))
                                           ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0 
                                              >> 0x14U)
                                           : ((((((
                                                   (((0x17U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2)) 
                                                     | (0x16U 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))) 
                                                    | (0x15U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))) 
                                                   | (0x14U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))) 
                                                  | (0x13U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))) 
                                                 | (0x12U 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))) 
                                                | (0x11U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2))) 
                                               | (0x10U 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2)))
                                               ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0 
                                                  >> 2U)
                                               : ((
                                                   (0xfU 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2)) 
                                                   | (0xeU 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp__DOT___io_out_T_2)))
                                                   ? 0U
                                                   : 
                                                  (8U 
                                                   | (7U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0 
                                                         >> 2U)))))))),5);
    bufp->fullCData(oldp+98343,((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0 
                                 >> 0x1bU)),5);
    bufp->fullBit(oldp+98344,((3U != (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0))));
    bufp->fullCData(oldp+98345,((8U | (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0 
                                             >> 2U)))),5);
    bufp->fullCData(oldp+98346,(((0U != (0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0 
                                                  >> 7U)))
                                  ? 3U : 0x1fU)),7);
    bufp->fullIData(oldp+98347,((((((((((0x1fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2)) 
                                        | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))) 
                                       | (0x1dU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))) 
                                      | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))) 
                                     | (0x1bU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))) 
                                    | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))) 
                                   | (0x19U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))) 
                                  | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2)))
                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0_1
                                  : ((0x17U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))
                                      ? (0x13023U | 
                                         ((0x1c000000U 
                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0_1 
                                              << 0x13U)) 
                                          | ((0x2000000U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0_1 
                                                 << 0xdU)) 
                                             | ((0x1f00000U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0_1 
                                                    << 0x12U)) 
                                                | (0xc00U 
                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0_1)))))
                                      : ((0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))
                                          ? (0x12023U 
                                             | ((0xc000000U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0_1 
                                                    << 0x13U)) 
                                                | ((0x2000000U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0_1 
                                                       << 0xdU)) 
                                                   | ((0x1f00000U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0_1 
                                                          << 0x12U)) 
                                                      | (0xe00U 
                                                         & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0_1)))))
                                          : ((0x15U 
                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))
                                              ? (0x13027U 
                                                 | ((0x1c000000U 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0_1 
                                                        << 0x13U)) 
                                                    | ((0x2000000U 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0_1 
                                                           << 0xdU)) 
                                                       | ((0x1f00000U 
                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0_1 
                                                              << 0x12U)) 
                                                          | (0xc00U 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0_1)))))
                                              : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_42_bits))))),32);
    bufp->fullCData(oldp+98348,(((0x9fU >= (0xffU & 
                                            ((IData)(5U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))))
                                  ? (0x1fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))))
                                                ? 0U
                                                : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___GEN_2[
                                                   (((IData)(4U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(5U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2)))))) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___GEN_2[
                                                 (7U 
                                                  & (((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))))))
                                  : 0U)),5);
    bufp->fullCData(oldp+98349,(((0x9fU >= (0xffU & 
                                            ((IData)(5U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))))
                                  ? (0x1fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))))
                                                ? 0U
                                                : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___GEN_3[
                                                   (((IData)(4U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(5U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2)))))) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___GEN_3[
                                                 (7U 
                                                  & (((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))))))
                                  : 0U)),5);
    bufp->fullCData(oldp+98350,((0x1fU & (((((((((0x1fU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2)) 
                                                 | (0x1eU 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))) 
                                                | (0x1dU 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))) 
                                               | (0x1cU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))) 
                                              | (0x1bU 
                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))) 
                                             | (0x1aU 
                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))) 
                                            | (0x19U 
                                               == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))) 
                                           | (0x18U 
                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2)))
                                           ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0_1 
                                              >> 0x14U)
                                           : ((((((
                                                   (((0x17U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2)) 
                                                     | (0x16U 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))) 
                                                    | (0x15U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))) 
                                                   | (0x14U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))) 
                                                  | (0x13U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))) 
                                                 | (0x12U 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))) 
                                                | (0x11U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2))) 
                                               | (0x10U 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2)))
                                               ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0_1 
                                                  >> 2U)
                                               : ((
                                                   (0xfU 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2)) 
                                                   | (0xeU 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0_rvc_exp_1__DOT___io_out_T_2)))
                                                   ? 0U
                                                   : 
                                                  (8U 
                                                   | (7U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0_1 
                                                         >> 2U)))))))),5);
    bufp->fullCData(oldp+98351,((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0_1 
                                 >> 0x1bU)),5);
    bufp->fullBit(oldp+98352,((3U != (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0_1))));
    bufp->fullCData(oldp+98353,((8U | (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0_1 
                                             >> 2U)))),5);
    bufp->fullCData(oldp+98354,(((0U != (0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__inst0_1 
                                                  >> 7U)))
                                  ? 3U : 0x1fU)),7);
    bufp->fullIData(oldp+98355,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                  [0U][3U] << 8U) | 
                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                  [0U][2U] >> 0x18U))),32);
    bufp->fullIData(oldp+98356,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___exp_inst0b_rvc_exp_io_out_bits),32);
    bufp->fullCData(oldp+98357,(((0x9fU >= (0xffU & 
                                            ((IData)(5U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2))))
                                  ? (0x1fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2))))
                                                ? 0U
                                                : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___GEN_2[
                                                   (((IData)(4U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(5U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2)))))) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___GEN_2[
                                                 (7U 
                                                  & (((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2))))))
                                  : 0U)),5);
    bufp->fullCData(oldp+98358,(((0x9fU >= (0xffU & 
                                            ((IData)(5U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2))))
                                  ? (0x1fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2))))
                                                ? 0U
                                                : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___GEN_3[
                                                   (((IData)(4U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(5U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2)))))) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___GEN_3[
                                                 (7U 
                                                  & (((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2))))))
                                  : 0U)),5);
    bufp->fullCData(oldp+98359,((0x1fU & (((((((((0x1fU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2)) 
                                                 | (0x1eU 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2))) 
                                                | (0x1dU 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2))) 
                                               | (0x1cU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2))) 
                                              | (0x1bU 
                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2))) 
                                             | (0x1aU 
                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2))) 
                                            | (0x19U 
                                               == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2))) 
                                           | (0x18U 
                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2)))
                                           ? ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                               [0U][3U] 
                                               << 0x14U) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                 [0U][3U] 
                                                 >> 0xcU))
                                           : ((((((
                                                   (((0x17U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2)) 
                                                     | (0x16U 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2))) 
                                                    | (0x15U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2))) 
                                                   | (0x14U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2))) 
                                                  | (0x13U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2))) 
                                                 | (0x12U 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2))) 
                                                | (0x11U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2))) 
                                               | (0x10U 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2)))
                                               ? ((
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                   [0U][2U] 
                                                   << 6U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                     [0U][2U] 
                                                     >> 0x1aU))
                                               : ((
                                                   (0xfU 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2)) 
                                                   | (0xeU 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b_rvc_exp__DOT___io_out_T_2)))
                                                   ? 0U
                                                   : 
                                                  (8U 
                                                   | (7U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                         [0U][2U] 
                                                         >> 0x1aU)))))))),5);
    bufp->fullCData(oldp+98360,((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                          [0U][3U] 
                                          >> 0x13U))),5);
    bufp->fullBit(oldp+98361,((3U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                            [0U][2U] 
                                            >> 0x18U)))));
    bufp->fullCData(oldp+98362,((8U | (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                             [0U][2U] 
                                             >> 0x1aU)))),5);
    bufp->fullCData(oldp+98363,(((0U != (0x1fU & ((
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                   [0U][3U] 
                                                   << 1U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                     [0U][2U] 
                                                     >> 0x1fU))))
                                  ? 3U : 0x1fU)),7);
    bufp->fullIData(oldp+98364,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                  [0U][2U] << 0x18U) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                    [0U][1U] >> 8U))),32);
    bufp->fullIData(oldp+98365,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___exp_inst1_rvc_exp_io_out_bits),32);
    bufp->fullCData(oldp+98366,(((0x9fU >= (0xffU & 
                                            ((IData)(5U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2))))
                                  ? (0x1fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2))))
                                                ? 0U
                                                : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___GEN_2[
                                                   (((IData)(4U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(5U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2)))))) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___GEN_2[
                                                 (7U 
                                                  & (((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2))))))
                                  : 0U)),5);
    bufp->fullCData(oldp+98367,(((0x9fU >= (0xffU & 
                                            ((IData)(5U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2))))
                                  ? (0x1fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2))))
                                                ? 0U
                                                : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___GEN_3[
                                                   (((IData)(4U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(5U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2)))))) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___GEN_3[
                                                 (7U 
                                                  & (((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2))))))
                                  : 0U)),5);
    bufp->fullCData(oldp+98368,((0x1fU & (((((((((0x1fU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2)) 
                                                 | (0x1eU 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2))) 
                                                | (0x1dU 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2))) 
                                               | (0x1cU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2))) 
                                              | (0x1bU 
                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2))) 
                                             | (0x1aU 
                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2))) 
                                            | (0x19U 
                                               == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2))) 
                                           | (0x18U 
                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2)))
                                           ? ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                               [0U][2U] 
                                               << 4U) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                 [0U][1U] 
                                                 >> 0x1cU))
                                           : ((((((
                                                   (((0x17U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2)) 
                                                     | (0x16U 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2))) 
                                                    | (0x15U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2))) 
                                                   | (0x14U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2))) 
                                                  | (0x13U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2))) 
                                                 | (0x12U 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2))) 
                                                | (0x11U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2))) 
                                               | (0x10U 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2)))
                                               ? ((
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                   [0U][1U] 
                                                   << 0x16U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                     [0U][1U] 
                                                     >> 0xaU))
                                               : ((
                                                   (0xfU 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2)) 
                                                   | (0xeU 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp__DOT___io_out_T_2)))
                                                   ? 0U
                                                   : 
                                                  (8U 
                                                   | (7U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                         [0U][1U] 
                                                         >> 0xaU)))))))),5);
    bufp->fullCData(oldp+98369,((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                          [0U][2U] 
                                          >> 3U))),5);
    bufp->fullBit(oldp+98370,((3U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                            [0U][1U] 
                                            >> 8U)))));
    bufp->fullCData(oldp+98371,((8U | (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                             [0U][1U] 
                                             >> 0xaU)))),5);
    bufp->fullCData(oldp+98372,(((0U != (0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                  [0U][1U] 
                                                  >> 0xfU)))
                                  ? 3U : 0x1fU)),7);
    bufp->fullIData(oldp+98373,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                  [0U][4U] << 0x18U) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                    [0U][3U] >> 8U))),32);
    bufp->fullIData(oldp+98374,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___exp_inst1_rvc_exp_1_io_out_bits),32);
    bufp->fullCData(oldp+98375,(((0x9fU >= (0xffU & 
                                            ((IData)(5U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2))))
                                  ? (0x1fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2))))
                                                ? 0U
                                                : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___GEN_2[
                                                   (((IData)(4U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(5U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2)))))) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___GEN_2[
                                                 (7U 
                                                  & (((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2))))))
                                  : 0U)),5);
    bufp->fullCData(oldp+98376,(((0x9fU >= (0xffU & 
                                            ((IData)(5U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2))))
                                  ? (0x1fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2))))
                                                ? 0U
                                                : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___GEN_3[
                                                   (((IData)(4U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(5U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2)))))) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___GEN_3[
                                                 (7U 
                                                  & (((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2))))))
                                  : 0U)),5);
    bufp->fullCData(oldp+98377,((0x1fU & (((((((((0x1fU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2)) 
                                                 | (0x1eU 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2))) 
                                                | (0x1dU 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2))) 
                                               | (0x1cU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2))) 
                                              | (0x1bU 
                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2))) 
                                             | (0x1aU 
                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2))) 
                                            | (0x19U 
                                               == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2))) 
                                           | (0x18U 
                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2)))
                                           ? ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                               [0U][4U] 
                                               << 4U) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                 [0U][3U] 
                                                 >> 0x1cU))
                                           : ((((((
                                                   (((0x17U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2)) 
                                                     | (0x16U 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2))) 
                                                    | (0x15U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2))) 
                                                   | (0x14U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2))) 
                                                  | (0x13U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2))) 
                                                 | (0x12U 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2))) 
                                                | (0x11U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2))) 
                                               | (0x10U 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2)))
                                               ? ((
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                   [0U][3U] 
                                                   << 0x16U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                     [0U][3U] 
                                                     >> 0xaU))
                                               : ((
                                                   (0xfU 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2)) 
                                                   | (0xeU 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_rvc_exp_1__DOT___io_out_T_2)))
                                                   ? 0U
                                                   : 
                                                  (8U 
                                                   | (7U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                         [0U][3U] 
                                                         >> 0xaU)))))))),5);
    bufp->fullCData(oldp+98378,((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                          [0U][4U] 
                                          >> 3U))),5);
    bufp->fullBit(oldp+98379,((3U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                            [0U][3U] 
                                            >> 8U)))));
    bufp->fullCData(oldp+98380,((8U | (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                             [0U][3U] 
                                             >> 0xaU)))),5);
    bufp->fullCData(oldp+98381,(((0U != (0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                  [0U][3U] 
                                                  >> 0xfU)))
                                  ? 3U : 0x1fU)),7);
    bufp->fullIData(oldp+98382,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___exp_inst_rvc_exp_io_out_bits),32);
    bufp->fullCData(oldp+98383,(((0x9fU >= (0xffU & 
                                            ((IData)(5U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2))))
                                  ? (0x1fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2))))
                                                ? 0U
                                                : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___GEN_2[
                                                   (((IData)(4U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(5U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2)))))) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___GEN_2[
                                                 (7U 
                                                  & (((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2))))))
                                  : 0U)),5);
    bufp->fullCData(oldp+98384,(((0x9fU >= (0xffU & 
                                            ((IData)(5U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2))))
                                  ? (0x1fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2))))
                                                ? 0U
                                                : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___GEN_3[
                                                   (((IData)(4U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(5U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2)))))) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___GEN_3[
                                                 (7U 
                                                  & (((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2))))))
                                  : 0U)),5);
    bufp->fullCData(oldp+98385,((0x1fU & (((((((((0x1fU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2)) 
                                                 | (0x1eU 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2))) 
                                                | (0x1dU 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2))) 
                                               | (0x1cU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2))) 
                                              | (0x1bU 
                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2))) 
                                             | (0x1aU 
                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2))) 
                                            | (0x19U 
                                               == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2))) 
                                           | (0x18U 
                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2)))
                                           ? ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                               [0U][2U] 
                                               << 0x14U) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                 [0U][2U] 
                                                 >> 0xcU))
                                           : ((((((
                                                   (((0x17U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2)) 
                                                     | (0x16U 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2))) 
                                                    | (0x15U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2))) 
                                                   | (0x14U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2))) 
                                                  | (0x13U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2))) 
                                                 | (0x12U 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2))) 
                                                | (0x11U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2))) 
                                               | (0x10U 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2)))
                                               ? ((
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                   [0U][1U] 
                                                   << 6U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                     [0U][1U] 
                                                     >> 0x1aU))
                                               : ((
                                                   (0xfU 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2)) 
                                                   | (0xeU 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp__DOT___io_out_T_2)))
                                                   ? 0U
                                                   : 
                                                  (8U 
                                                   | (7U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                         [0U][1U] 
                                                         >> 0x1aU)))))))),5);
    bufp->fullCData(oldp+98386,((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                          [0U][2U] 
                                          >> 0x13U))),5);
    bufp->fullBit(oldp+98387,((3U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                            [0U][1U] 
                                            >> 0x18U)))));
    bufp->fullCData(oldp+98388,((8U | (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                             [0U][1U] 
                                             >> 0x1aU)))),5);
    bufp->fullCData(oldp+98389,(((0U != (0x1fU & ((
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                   [0U][2U] 
                                                   << 1U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                     [0U][1U] 
                                                     >> 0x1fU))))
                                  ? 3U : 0x1fU)),7);
    bufp->fullIData(oldp+98390,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___exp_inst_rvc_exp_1_io_out_bits),32);
    bufp->fullCData(oldp+98391,(((0x9fU >= (0xffU & 
                                            ((IData)(5U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2))))
                                  ? (0x1fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2))))
                                                ? 0U
                                                : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___GEN_2[
                                                   (((IData)(4U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(5U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2)))))) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___GEN_2[
                                                 (7U 
                                                  & (((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2))))))
                                  : 0U)),5);
    bufp->fullCData(oldp+98392,(((0x9fU >= (0xffU & 
                                            ((IData)(5U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2))))
                                  ? (0x1fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2))))
                                                ? 0U
                                                : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___GEN_3[
                                                   (((IData)(4U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(5U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2)))))) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___GEN_3[
                                                 (7U 
                                                  & (((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2))))))
                                  : 0U)),5);
    bufp->fullCData(oldp+98393,((0x1fU & (((((((((0x1fU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2)) 
                                                 | (0x1eU 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2))) 
                                                | (0x1dU 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2))) 
                                               | (0x1cU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2))) 
                                              | (0x1bU 
                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2))) 
                                             | (0x1aU 
                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2))) 
                                            | (0x19U 
                                               == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2))) 
                                           | (0x18U 
                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2)))
                                           ? ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                               [0U][3U] 
                                               << 4U) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                 [0U][2U] 
                                                 >> 0x1cU))
                                           : ((((((
                                                   (((0x17U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2)) 
                                                     | (0x16U 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2))) 
                                                    | (0x15U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2))) 
                                                   | (0x14U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2))) 
                                                  | (0x13U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2))) 
                                                 | (0x12U 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2))) 
                                                | (0x11U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2))) 
                                               | (0x10U 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2)))
                                               ? ((
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                   [0U][2U] 
                                                   << 0x16U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                     [0U][2U] 
                                                     >> 0xaU))
                                               : ((
                                                   (0xfU 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2)) 
                                                   | (0xeU 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_1__DOT___io_out_T_2)))
                                                   ? 0U
                                                   : 
                                                  (8U 
                                                   | (7U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                         [0U][2U] 
                                                         >> 0xaU)))))))),5);
    bufp->fullCData(oldp+98394,((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                          [0U][3U] 
                                          >> 3U))),5);
    bufp->fullBit(oldp+98395,((3U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                            [0U][2U] 
                                            >> 8U)))));
    bufp->fullCData(oldp+98396,((8U | (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                             [0U][2U] 
                                             >> 0xaU)))),5);
    bufp->fullCData(oldp+98397,(((0U != (0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                  [0U][2U] 
                                                  >> 0xfU)))
                                  ? 3U : 0x1fU)),7);
    bufp->fullIData(oldp+98398,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___exp_inst_rvc_exp_2_io_out_bits),32);
    bufp->fullCData(oldp+98399,(((0x9fU >= (0xffU & 
                                            ((IData)(5U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2))))
                                  ? (0x1fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2))))
                                                ? 0U
                                                : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___GEN_2[
                                                   (((IData)(4U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(5U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2)))))) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___GEN_2[
                                                 (7U 
                                                  & (((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2))))))
                                  : 0U)),5);
    bufp->fullCData(oldp+98400,(((0x9fU >= (0xffU & 
                                            ((IData)(5U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2))))
                                  ? (0x1fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2))))
                                                ? 0U
                                                : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___GEN_3[
                                                   (((IData)(4U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(5U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2)))))) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___GEN_3[
                                                 (7U 
                                                  & (((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2))))))
                                  : 0U)),5);
    bufp->fullCData(oldp+98401,((((((((((0x1fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2)) 
                                        | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2))) 
                                       | (0x1dU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2))) 
                                      | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2))) 
                                     | (0x1bU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2))) 
                                    | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2))) 
                                   | (0x19U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2))) 
                                  | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2)))
                                  ? 0U : (0x1fU & (
                                                   ((((((((0x17U 
                                                           == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2)) 
                                                          | (0x16U 
                                                             == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2))) 
                                                         | (0x15U 
                                                            == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2))) 
                                                        | (0x14U 
                                                           == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2))) 
                                                       | (0x13U 
                                                          == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2))) 
                                                      | (0x12U 
                                                         == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2))) 
                                                     | (0x11U 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2))) 
                                                    | (0x10U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2)))
                                                    ? 
                                                   (0x3fffU 
                                                    & ((0x3fffffc0U 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                           [0U][3U] 
                                                           << 6U)) 
                                                       | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                          [0U][2U] 
                                                          >> 0x1aU)))
                                                    : 
                                                   (((0xfU 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2)) 
                                                     | (0xeU 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_2__DOT___io_out_T_2)))
                                                     ? 0U
                                                     : 
                                                    (8U 
                                                     | (7U 
                                                        & ((0x3fffffc0U 
                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                               [0U][3U] 
                                                               << 6U)) 
                                                           | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                              [0U][2U] 
                                                              >> 0x1aU))))))))),5);
    bufp->fullCData(oldp+98402,(0U),5);
    bufp->fullBit(oldp+98403,((3U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                            [0U][2U] 
                                            >> 0x18U)))));
    bufp->fullCData(oldp+98404,((8U | (7U & ((0x3fffffc0U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                 [0U][3U] 
                                                 << 6U)) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                [0U][2U] 
                                                >> 0x1aU))))),5);
    bufp->fullCData(oldp+98405,(((0U != (0x1fU & ((0x1fffffeU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                      [0U][3U] 
                                                      << 1U)) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                     [0U][2U] 
                                                     >> 0x1fU))))
                                  ? 3U : 0x1fU)),7);
    bufp->fullIData(oldp+98406,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___exp_inst_rvc_exp_3_io_out_bits),32);
    bufp->fullCData(oldp+98407,(((0x9fU >= (0xffU & 
                                            ((IData)(5U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2))))
                                  ? (0x1fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2))))
                                                ? 0U
                                                : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___GEN_2[
                                                   (((IData)(4U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(5U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2)))))) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___GEN_2[
                                                 (7U 
                                                  & (((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2))))))
                                  : 0U)),5);
    bufp->fullCData(oldp+98408,(((0x9fU >= (0xffU & 
                                            ((IData)(5U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2))))
                                  ? (0x1fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2))))
                                                ? 0U
                                                : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___GEN_3[
                                                   (((IData)(4U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(5U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2)))))) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___GEN_3[
                                                 (7U 
                                                  & (((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2))))))
                                  : 0U)),5);
    bufp->fullCData(oldp+98409,((0x1fU & (((((((((0x1fU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2)) 
                                                 | (0x1eU 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2))) 
                                                | (0x1dU 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2))) 
                                               | (0x1cU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2))) 
                                              | (0x1bU 
                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2))) 
                                             | (0x1aU 
                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2))) 
                                            | (0x19U 
                                               == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2))) 
                                           | (0x18U 
                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2)))
                                           ? ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                               [0U][4U] 
                                               << 0x14U) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                 [0U][4U] 
                                                 >> 0xcU))
                                           : ((((((
                                                   (((0x17U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2)) 
                                                     | (0x16U 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2))) 
                                                    | (0x15U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2))) 
                                                   | (0x14U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2))) 
                                                  | (0x13U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2))) 
                                                 | (0x12U 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2))) 
                                                | (0x11U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2))) 
                                               | (0x10U 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2)))
                                               ? ((
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                   [0U][3U] 
                                                   << 6U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                     [0U][3U] 
                                                     >> 0x1aU))
                                               : ((
                                                   (0xfU 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2)) 
                                                   | (0xeU 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_3__DOT___io_out_T_2)))
                                                   ? 0U
                                                   : 
                                                  (8U 
                                                   | (7U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                         [0U][3U] 
                                                         >> 0x1aU)))))))),5);
    bufp->fullCData(oldp+98410,((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                          [0U][4U] 
                                          >> 0x13U))),5);
    bufp->fullBit(oldp+98411,((3U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                            [0U][3U] 
                                            >> 0x18U)))));
    bufp->fullCData(oldp+98412,((8U | (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                             [0U][3U] 
                                             >> 0x1aU)))),5);
    bufp->fullCData(oldp+98413,(((0U != (0x1fU & ((
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                   [0U][4U] 
                                                   << 1U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                     [0U][3U] 
                                                     >> 0x1fU))))
                                  ? 3U : 0x1fU)),7);
    bufp->fullIData(oldp+98414,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___exp_inst_rvc_exp_4_io_out_bits),32);
    bufp->fullCData(oldp+98415,(((0x9fU >= (0xffU & 
                                            ((IData)(5U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2))))
                                  ? (0x1fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2))))
                                                ? 0U
                                                : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___GEN_2[
                                                   (((IData)(4U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(5U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2)))))) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___GEN_2[
                                                 (7U 
                                                  & (((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2))))))
                                  : 0U)),5);
    bufp->fullCData(oldp+98416,(((0x9fU >= (0xffU & 
                                            ((IData)(5U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2))))
                                  ? (0x1fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2))))
                                                ? 0U
                                                : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___GEN_3[
                                                   (((IData)(4U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(5U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2)))))) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___GEN_3[
                                                 (7U 
                                                  & (((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2))))))
                                  : 0U)),5);
    bufp->fullCData(oldp+98417,((0x1fU & (((((((((0x1fU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2)) 
                                                 | (0x1eU 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2))) 
                                                | (0x1dU 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2))) 
                                               | (0x1cU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2))) 
                                              | (0x1bU 
                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2))) 
                                             | (0x1aU 
                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2))) 
                                            | (0x19U 
                                               == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2))) 
                                           | (0x18U 
                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2)))
                                           ? ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                               [0U][5U] 
                                               << 4U) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                 [0U][4U] 
                                                 >> 0x1cU))
                                           : ((((((
                                                   (((0x17U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2)) 
                                                     | (0x16U 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2))) 
                                                    | (0x15U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2))) 
                                                   | (0x14U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2))) 
                                                  | (0x13U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2))) 
                                                 | (0x12U 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2))) 
                                                | (0x11U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2))) 
                                               | (0x10U 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2)))
                                               ? ((
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                   [0U][4U] 
                                                   << 0x16U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                     [0U][4U] 
                                                     >> 0xaU))
                                               : ((
                                                   (0xfU 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2)) 
                                                   | (0xeU 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_4__DOT___io_out_T_2)))
                                                   ? 0U
                                                   : 
                                                  (8U 
                                                   | (7U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                         [0U][4U] 
                                                         >> 0xaU)))))))),5);
    bufp->fullCData(oldp+98418,((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                          [0U][5U] 
                                          >> 3U))),5);
    bufp->fullBit(oldp+98419,((3U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                            [0U][4U] 
                                            >> 8U)))));
    bufp->fullCData(oldp+98420,((8U | (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                             [0U][4U] 
                                             >> 0xaU)))),5);
    bufp->fullCData(oldp+98421,(((0U != (0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                  [0U][4U] 
                                                  >> 0xfU)))
                                  ? 3U : 0x1fU)),7);
    bufp->fullIData(oldp+98422,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___exp_inst_rvc_exp_5_io_out_bits),32);
    bufp->fullCData(oldp+98423,(((0x9fU >= (0xffU & 
                                            ((IData)(5U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2))))
                                  ? (0x1fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2))))
                                                ? 0U
                                                : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___GEN_2[
                                                   (((IData)(4U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(5U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2)))))) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___GEN_2[
                                                 (7U 
                                                  & (((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2))))))
                                  : 0U)),5);
    bufp->fullCData(oldp+98424,(((0x9fU >= (0xffU & 
                                            ((IData)(5U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2))))
                                  ? (0x1fU & (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(5U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2))))
                                                ? 0U
                                                : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___GEN_3[
                                                   (((IData)(4U) 
                                                     + 
                                                     (0xffU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2)))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(5U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2)))))) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___GEN_3[
                                                 (7U 
                                                  & (((IData)(5U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2)) 
                                                     >> 5U))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(5U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2))))))
                                  : 0U)),5);
    bufp->fullCData(oldp+98425,((((((((((0x1fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2)) 
                                        | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2))) 
                                       | (0x1dU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2))) 
                                      | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2))) 
                                     | (0x1bU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2))) 
                                    | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2))) 
                                   | (0x19U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2))) 
                                  | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2)))
                                  ? 0U : (0x1fU & (
                                                   ((((((((0x17U 
                                                           == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2)) 
                                                          | (0x16U 
                                                             == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2))) 
                                                         | (0x15U 
                                                            == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2))) 
                                                        | (0x14U 
                                                           == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2))) 
                                                       | (0x13U 
                                                          == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2))) 
                                                      | (0x12U 
                                                         == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2))) 
                                                     | (0x11U 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2))) 
                                                    | (0x10U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2)))
                                                    ? 
                                                   (0x3fffU 
                                                    & ((0x3fffffc0U 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                           [0U][5U] 
                                                           << 6U)) 
                                                       | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                          [0U][4U] 
                                                          >> 0x1aU)))
                                                    : 
                                                   (((0xfU 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2)) 
                                                     | (0xeU 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst_rvc_exp_5__DOT___io_out_T_2)))
                                                     ? 0U
                                                     : 
                                                    (8U 
                                                     | (7U 
                                                        & ((0x3fffffc0U 
                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                               [0U][5U] 
                                                               << 6U)) 
                                                           | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                              [0U][4U] 
                                                              >> 0x1aU))))))))),5);
    bufp->fullCData(oldp+98426,(0U),5);
    bufp->fullBit(oldp+98427,((3U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                            [0U][4U] 
                                            >> 0x18U)))));
    bufp->fullCData(oldp+98428,((8U | (7U & ((0x3fffffc0U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                 [0U][5U] 
                                                 << 6U)) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                [0U][4U] 
                                                >> 0x1aU))))),5);
    bufp->fullCData(oldp+98429,(((0U != (0x1fU & ((0x1fffffeU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                      [0U][5U] 
                                                      << 1U)) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                     [0U][4U] 
                                                     >> 0x1fU))))
                                  ? 3U : 0x1fU)),7);
    bufp->fullBit(oldp+98430,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_io_enq_valid_T_6));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_xcpt) {
        __Vtemp_h32ee9402__0[0U] = 0U;
        __Vtemp_h32ee9402__0[1U] = 0U;
        __Vtemp_h32ee9402__0[2U] = 0U;
        __Vtemp_h32ee9402__0[3U] = 0U;
    } else if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_bankid) {
        __Vtemp_h32ee9402__0[0U] = (IData)((((QData)((IData)(
                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[3U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[2U]))));
        __Vtemp_h32ee9402__0[1U] = (IData)(((((QData)((IData)(
                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[3U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[2U]))) 
                                            >> 0x20U));
        __Vtemp_h32ee9402__0[2U] = (IData)((((QData)((IData)(
                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[1U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[0U]))));
        __Vtemp_h32ee9402__0[3U] = (IData)(((((QData)((IData)(
                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[1U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[0U]))) 
                                            >> 0x20U));
    } else {
        __Vtemp_h32ee9402__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[0U];
        __Vtemp_h32ee9402__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[1U];
        __Vtemp_h32ee9402__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[2U];
        __Vtemp_h32ee9402__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[3U];
    }
    bufp->fullWData(oldp+98431,(__Vtemp_h32ee9402__0),128);
    bufp->fullCData(oldp+98435,((0x7ffU & (((IData)(0xffU) 
                                            << (3U 
                                                & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_vpc 
                                                           >> 1U)))) 
                                           & ((7U == 
                                               (7U 
                                                & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_vpc 
                                                           >> 3U))))
                                               ? 0xfU
                                               : 0xffU)))),8);
    bufp->fullQData(oldp+98436,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_153)
                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_predicted_ghist_old_history
                                  : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_ghist_old_history)),64);
    bufp->fullBit(oldp+98438,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_153)) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_ghist_current_saw_branch_not_taken))));
    bufp->fullBit(oldp+98439,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_153)
                                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_predicted_ghist_new_saw_branch_not_taken)
                                : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_ghist_new_saw_branch_not_taken))));
    bufp->fullBit(oldp+98440,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_153)
                                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_predicted_ghist_new_saw_branch_taken)
                                : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_ghist_new_saw_branch_taken))));
    bufp->fullCData(oldp+98441,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN),5);
    bufp->fullCData(oldp+98442,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___T_11)
                                  ? 0U : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_31))),2);
    bufp->fullBit(oldp+98443,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT___io_enq_ready_output));
    bufp->fullBit(oldp+98444,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT___io_enq_ready_output));
    bufp->fullBit(oldp+98445,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__maybe_full));
    bufp->fullQData(oldp+98446,((0xffffffffffULL & 
                                 (((QData)((IData)(
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                   [0U][1U])) 
                                   << 0x20U) | (QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                               [0U][0U]))))),40);
    __Vtemp_h26aa32e8__0[0U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                 [0U][2U] << 0x18U) 
                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                   [0U][1U] >> 8U));
    __Vtemp_h26aa32e8__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                 [0U][3U] << 0x18U) 
                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                   [0U][2U] >> 8U));
    __Vtemp_h26aa32e8__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                 [0U][4U] << 0x18U) 
                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                   [0U][3U] >> 8U));
    __Vtemp_h26aa32e8__0[3U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                 [0U][5U] << 0x18U) 
                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                   [0U][4U] >> 8U));
    bufp->fullWData(oldp+98448,(__Vtemp_h26aa32e8__0),128);
    bufp->fullCData(oldp+98452,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                          [0U][5U] 
                                          >> 8U))),8);
    bufp->fullBit(oldp+98453,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                     [0U][5U] >> 0x10U))));
    bufp->fullBit(oldp+98454,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                     [0U][5U] >> 0x12U))));
    bufp->fullQData(oldp+98455,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                  [0U][7U])) 
                                  << 0x2dU) | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                [0U][6U])) 
                                                << 0xdU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                  [0U][5U])) 
                                                  >> 0x13U)))),64);
    bufp->fullBit(oldp+98457,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                     [0U][7U] >> 0x13U))));
    bufp->fullBit(oldp+98458,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                     [0U][7U] >> 0x14U))));
    bufp->fullBit(oldp+98459,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                     [0U][7U] >> 0x15U))));
    bufp->fullCData(oldp+98460,((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                          [0U][7U] 
                                          >> 0x16U))),5);
    bufp->fullCData(oldp+98461,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                       [0U][7U] >> 0x1bU))),2);
    bufp->fullCData(oldp+98462,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                       [0U][7U] >> 0x1dU))),2);
    bufp->fullBit(oldp+98463,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__do_enq));
    __Vtemp_h01528036__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_vpc);
    __Vtemp_h01528036__0[1U] = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_xcpt)
                                   ? 0U : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_bankid)
                                            ? (IData)(
                                                      (((QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[3U])) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(
                                                                         vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[2U]))))
                                            : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[0U])) 
                                 << 8U) | (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_vpc 
                                                   >> 0x20U)));
    __Vtemp_h01528036__0[2U] = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_xcpt)
                                   ? 0U : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_bankid)
                                            ? (IData)(
                                                      (((QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[3U])) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(
                                                                         vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[2U]))))
                                            : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[0U])) 
                                 >> 0x18U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_xcpt)
                                                ? 0U
                                                : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_bankid)
                                                    ? (IData)(
                                                              ((((QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[3U])) 
                                                                 << 0x20U) 
                                                                | (QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[2U]))) 
                                                               >> 0x20U))
                                                    : 
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[1U])) 
                                              << 8U));
    __Vtemp_h01528036__0[3U] = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_xcpt)
                                   ? 0U : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_bankid)
                                            ? (IData)(
                                                      ((((QData)((IData)(
                                                                         vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[3U])) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[2U]))) 
                                                       >> 0x20U))
                                            : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[1U])) 
                                 >> 0x18U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_xcpt)
                                                ? 0U
                                                : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_bankid)
                                                    ? (IData)(
                                                              (((QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[1U])) 
                                                                << 0x20U) 
                                                               | (QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[0U]))))
                                                    : 
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[2U])) 
                                              << 8U));
    __Vtemp_h01528036__0[4U] = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_xcpt)
                                   ? 0U : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_bankid)
                                            ? (IData)(
                                                      (((QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[1U])) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(
                                                                         vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[0U]))))
                                            : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[2U])) 
                                 >> 0x18U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_xcpt)
                                                ? 0U
                                                : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_bankid)
                                                    ? (IData)(
                                                              ((((QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[1U])) 
                                                                 << 0x20U) 
                                                                | (QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[0U]))) 
                                                               >> 0x20U))
                                                    : 
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[3U])) 
                                              << 8U));
    __Vtemp_h01528036__0[5U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_tlb_resp_pf_inst) 
                                 << 0x10U) | ((0x7ff00U 
                                               & ((((IData)(0xffU) 
                                                    << 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_vpc 
                                                                >> 1U)))) 
                                                   & ((7U 
                                                       == 
                                                       (7U 
                                                        & (IData)(
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_vpc 
                                                                   >> 3U))))
                                                       ? 0xfU
                                                       : 0xffU)) 
                                                  << 8U)) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_xcpt)
                                                   ? 0U
                                                   : 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_bankid)
                                                    ? (IData)(
                                                              ((((QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[1U])) 
                                                                 << 0x20U) 
                                                                | (QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[0U]))) 
                                                               >> 0x20U))
                                                    : 
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[3U])) 
                                                 >> 0x18U)));
    VL_EXTEND_WW(178,177, __Vtemp_ha428ae90__0, __Vtemp_h01528036__0);
    __Vtemp_h86d15f1c__0[0U] = __Vtemp_ha428ae90__0[0U];
    __Vtemp_h86d15f1c__0[1U] = __Vtemp_ha428ae90__0[1U];
    __Vtemp_h86d15f1c__0[2U] = __Vtemp_ha428ae90__0[2U];
    __Vtemp_h86d15f1c__0[3U] = __Vtemp_ha428ae90__0[3U];
    __Vtemp_h86d15f1c__0[4U] = __Vtemp_ha428ae90__0[4U];
    __Vtemp_h86d15f1c__0[5U] = (((IData)(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_153)
                                           ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_predicted_ghist_old_history
                                           : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_ghist_old_history)) 
                                 << 0x13U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_tlb_resp_ae_inst) 
                                               << 0x12U) 
                                              | __Vtemp_ha428ae90__0[5U]));
    __Vtemp_h86d15f1c__0[6U] = (((IData)(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_153)
                                           ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_predicted_ghist_old_history
                                           : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_ghist_old_history)) 
                                 >> 0xdU) | ((IData)(
                                                     (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_153)
                                                        ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_predicted_ghist_old_history
                                                        : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_ghist_old_history) 
                                                      >> 0x20U)) 
                                             << 0x13U));
    __Vtemp_h86d15f1c__0[7U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_tsrc) 
                                 << 0x1dU) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___T_11)
                                                 ? 0U
                                                 : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_31)) 
                                               << 0x1bU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN) 
                                                  << 0x16U) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_153)
                                                       ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_predicted_ghist_new_saw_branch_taken)
                                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_ghist_new_saw_branch_taken)) 
                                                     << 0x15U) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_153)
                                                          ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_predicted_ghist_new_saw_branch_not_taken)
                                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_ghist_new_saw_branch_not_taken)) 
                                                        << 0x14U) 
                                                       | ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_153)) 
                                                            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_ghist_current_saw_branch_not_taken)) 
                                                           << 0x13U) 
                                                          | ((IData)(
                                                                     (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_153)
                                                                        ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_predicted_ghist_old_history
                                                                        : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_ghist_old_history) 
                                                                      >> 0x20U)) 
                                                             >> 0xdU)))))));
    bufp->fullWData(oldp+98464,(__Vtemp_h86d15f1c__0),255);
    __Vtemp_h860b9f1e__89[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
        [0U][0U];
    __Vtemp_h860b9f1e__89[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
        [0U][1U];
    __Vtemp_h860b9f1e__89[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
        [0U][2U];
    __Vtemp_h860b9f1e__89[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
        [0U][3U];
    __Vtemp_h860b9f1e__89[4U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
        [0U][4U];
    __Vtemp_h860b9f1e__89[5U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
        [0U][5U];
    __Vtemp_h860b9f1e__89[6U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
        [0U][6U];
    __Vtemp_h860b9f1e__89[7U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
        [0U][7U];
    bufp->fullWData(oldp+98472,(__Vtemp_h860b9f1e__89),255);
    bufp->fullWData(oldp+98480,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory[0]),255);
    bufp->fullBit(oldp+98488,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_enq_valid_T));
    bufp->fullBit(oldp+98489,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT___io_enq_ready_output));
    bufp->fullQData(oldp+98490,((0xffffffffffULL & 
                                 ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__maybe_full)
                                   ? (((QData)((IData)(
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
                                                       [0U][1U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
                                                                   [0U][0U])))
                                   : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__io_resp_f3_pc_REG))),40);
    bufp->fullBit(oldp+98492,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__maybe_full)
                                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
                                         [0U][1U] >> 8U)
                                      : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_io_resp_f3_preds_0_taken)))));
    bufp->fullBit(oldp+98493,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__maybe_full)
                                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
                                         [0U][1U] >> 0xbU)
                                      : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_io_resp_f3_preds_0_predicted_pc_valid)))));
    bufp->fullQData(oldp+98494,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_preds_0_predicted_pc_bits),40);
    bufp->fullBit(oldp+98496,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__maybe_full)
                                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
                                         [0U][2U] >> 0x14U)
                                      : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_io_resp_f3_preds_1_taken)))));
    bufp->fullBit(oldp+98497,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__maybe_full)
                                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
                                         [0U][2U] >> 0x17U)
                                      : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_io_resp_f3_preds_1_predicted_pc_valid)))));
    bufp->fullQData(oldp+98498,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_preds_1_predicted_pc_bits),40);
    bufp->fullBit(oldp+98500,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__maybe_full)
                                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
                                     [0U][4U] : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_io_resp_f3_preds_2_taken)))));
    bufp->fullBit(oldp+98501,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__maybe_full)
                                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
                                         [0U][4U] >> 3U)
                                      : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_io_resp_f3_preds_2_predicted_pc_valid)))));
    bufp->fullQData(oldp+98502,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_preds_2_predicted_pc_bits),40);
    bufp->fullBit(oldp+98504,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__maybe_full)
                                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
                                         [0U][5U] >> 0xcU)
                                      : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_io_resp_f3_preds_3_taken)))));
    bufp->fullBit(oldp+98505,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__maybe_full)
                                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
                                         [0U][5U] >> 0xfU)
                                      : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_io_resp_f3_preds_3_predicted_pc_valid)))));
    bufp->fullQData(oldp+98506,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_preds_3_predicted_pc_bits),40);
    bufp->fullBit(oldp+98508,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__maybe_full)
                                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
                                         [0U][6U] >> 0x18U)
                                      : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_io_resp_f3_preds_4_taken)))));
    bufp->fullBit(oldp+98509,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__maybe_full)
                                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
                                         [0U][6U] >> 0x1bU)
                                      : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_io_resp_f3_preds_4_predicted_pc_valid)))));
    bufp->fullQData(oldp+98510,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_preds_4_predicted_pc_bits),40);
    bufp->fullBit(oldp+98512,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__maybe_full)
                                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
                                         [0U][8U] >> 4U)
                                      : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_io_resp_f3_preds_5_taken)))));
    bufp->fullBit(oldp+98513,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__maybe_full)
                                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
                                         [0U][8U] >> 7U)
                                      : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_io_resp_f3_preds_5_predicted_pc_valid)))));
    bufp->fullQData(oldp+98514,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_preds_5_predicted_pc_bits),40);
    bufp->fullBit(oldp+98516,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__maybe_full)
                                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
                                         [0U][9U] >> 0x10U)
                                      : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_io_resp_f3_preds_6_taken)))));
    bufp->fullBit(oldp+98517,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__maybe_full)
                                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
                                         [0U][9U] >> 0x13U)
                                      : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_io_resp_f3_preds_6_predicted_pc_valid)))));
    bufp->fullQData(oldp+98518,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_preds_6_predicted_pc_bits),40);
    bufp->fullBit(oldp+98520,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__maybe_full)
                                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
                                         [0U][0xaU] 
                                         >> 0x1cU) : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_io_resp_f3_preds_7_taken)))));
    bufp->fullBit(oldp+98521,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__maybe_full)
                                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
                                         [0U][0xaU] 
                                         >> 0x1fU) : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_io_resp_f3_preds_7_predicted_pc_valid)))));
    bufp->fullQData(oldp+98522,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_preds_7_predicted_pc_bits),40);
    bufp->fullWData(oldp+98524,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_0),120);
    bufp->fullWData(oldp+98528,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_1),120);
    bufp->fullBit(oldp+98532,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_lhist_0));
    bufp->fullBit(oldp+98533,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_lhist_1));
    bufp->fullBit(oldp+98534,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__maybe_full));
    bufp->fullBit(oldp+98535,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__do_enq));
    bufp->fullWData(oldp+98536,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT____Vcellinp__ram_ext__W0_data),634);
    __Vtemp_hfcdbafcc__17[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
        [0U][0U];
    __Vtemp_hfcdbafcc__17[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
        [0U][1U];
    __Vtemp_hfcdbafcc__17[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
        [0U][2U];
    __Vtemp_hfcdbafcc__17[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
        [0U][3U];
    __Vtemp_hfcdbafcc__17[4U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
        [0U][4U];
    __Vtemp_hfcdbafcc__17[5U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
        [0U][5U];
    __Vtemp_hfcdbafcc__17[6U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
        [0U][6U];
    __Vtemp_hfcdbafcc__17[7U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
        [0U][7U];
    __Vtemp_hfcdbafcc__17[8U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
        [0U][8U];
    __Vtemp_hfcdbafcc__17[9U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
        [0U][9U];
    __Vtemp_hfcdbafcc__17[0xaU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
        [0U][0xaU];
    __Vtemp_hfcdbafcc__17[0xbU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
        [0U][0xbU];
    __Vtemp_hfcdbafcc__17[0xcU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
        [0U][0xcU];
    __Vtemp_hfcdbafcc__17[0xdU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
        [0U][0xdU];
    __Vtemp_hfcdbafcc__17[0xeU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
        [0U][0xeU];
    __Vtemp_hfcdbafcc__17[0xfU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
        [0U][0xfU];
    __Vtemp_hfcdbafcc__17[0x10U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
        [0U][0x10U];
    __Vtemp_hfcdbafcc__17[0x11U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
        [0U][0x11U];
    __Vtemp_hfcdbafcc__17[0x12U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
        [0U][0x12U];
    __Vtemp_hfcdbafcc__17[0x13U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory
        [0U][0x13U];
    bufp->fullWData(oldp+98556,(__Vtemp_hfcdbafcc__17),634);
    bufp->fullWData(oldp+98576,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_bpd_resp__DOT__ram_ext__DOT__Memory[0]),634);
    bufp->fullBit(oldp+98596,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f4_io_enq_valid_T_1));
    bufp->fullBit(oldp+98597,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___T_42));
    bufp->fullIData(oldp+98598,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_prev_is_half)
                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0
                                  : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1)),32);
    bufp->fullIData(oldp+98599,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___T_42)
                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b
                                  : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1)),32);
    bufp->fullBit(oldp+98600,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_0) 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_prev_is_half)
                                    ? ((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder0__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6)) 
                                         & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0 
                                               >> 0x1fU))) 
                                        & (IData)((0U 
                                                   != 
                                                   (0x7e000f80U 
                                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0)))) 
                                       & (0U == ((0x20U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0 
                                                     >> 2U)) 
                                                 | (0x1fU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0 
                                                       >> 0x1aU)))))
                                    : ((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder1__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6)) 
                                         & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1 
                                               >> 0x1fU))) 
                                        & (IData)((0U 
                                                   != 
                                                   (0x7e000f80U 
                                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1)))) 
                                       & (0U == ((0x20U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1 
                                                     >> 2U)) 
                                                 | (0x1fU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1 
                                                       >> 0x1aU))))))) 
                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__offset_from_aligned_pc) 
                                  <= ((7U == (7U & 
                                              (~ (IData)(
                                                         (0x1fffffffffULL 
                                                          & ((~ 
                                                              (((QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                                [0U][1U])) 
                                                                << 0x20U) 
                                                               | (QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                                [0U][0U])))) 
                                                             >> 3U))))))
                                       ? 0x18U : 0x20U)))));
    bufp->fullBit(oldp+98601,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_1) 
                                & ((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6)) 
                                     & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_1 
                                           >> 0x1fU))) 
                                    & (IData)((0U != 
                                               (0x7e000f80U 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_1)))) 
                                   & (0U == ((0x20U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_1 
                                                 >> 2U)) 
                                             | (0x1fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_1 
                                                   >> 0x1aU)))))) 
                               & ((0x7fU & ((IData)(2U) 
                                            + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_io_out_sfb_offset_bits))) 
                                  <= ((7U == (7U & 
                                              (~ (IData)(
                                                         (0x1fffffffffULL 
                                                          & ((~ 
                                                              (((QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                                [0U][1U])) 
                                                                << 0x20U) 
                                                               | (QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                                [0U][0U])))) 
                                                             >> 3U))))))
                                       ? 0x18U : 0x20U)))));
    bufp->fullBit(oldp+98602,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_2) 
                                & ((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_1__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6)) 
                                     & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_2 
                                           >> 0x1fU))) 
                                    & (IData)((0U != 
                                               (0x7e000f80U 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_2)))) 
                                   & (0U == ((0x20U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_2 
                                                 >> 2U)) 
                                             | (0x1fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_2 
                                                   >> 0x1aU)))))) 
                               & ((0x7fU & ((IData)(4U) 
                                            + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_1_io_out_sfb_offset_bits))) 
                                  <= ((7U == (7U & 
                                              (~ (IData)(
                                                         (0x1fffffffffULL 
                                                          & ((~ 
                                                              (((QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                                [0U][1U])) 
                                                                << 0x20U) 
                                                               | (QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                                [0U][0U])))) 
                                                             >> 3U))))))
                                       ? 0x18U : 0x20U)))));
    bufp->fullBit(oldp+98603,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_3) 
                                & ((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_2__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6)) 
                                     & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_3 
                                           >> 0x1fU))) 
                                    & (IData)((0U != 
                                               (0x7e000f80U 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_3)))) 
                                   & (0U == ((0x20U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_3 
                                                 >> 2U)) 
                                             | (0x1fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_3 
                                                   >> 0x1aU)))))) 
                               & ((0x7fU & ((IData)(6U) 
                                            + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_2_io_out_sfb_offset_bits))) 
                                  <= ((7U == (7U & 
                                              (~ (IData)(
                                                         (0x1fffffffffULL 
                                                          & ((~ 
                                                              (((QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                                [0U][1U])) 
                                                                << 0x20U) 
                                                               | (QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                                [0U][0U])))) 
                                                             >> 3U))))))
                                       ? 0x18U : 0x20U)))));
    bufp->fullBit(oldp+98604,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_4) 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___T_42)
                                    ? ((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder0b__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6)) 
                                         & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b 
                                               >> 0x1fU))) 
                                        & (IData)((0U 
                                                   != 
                                                   (0x7e000f80U 
                                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b)))) 
                                       & (0U == ((0x20U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b 
                                                     >> 2U)) 
                                                 | (0x1fU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst0b 
                                                       >> 0x1aU)))))
                                    : ((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder1_1__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6)) 
                                         & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1 
                                               >> 0x1fU))) 
                                        & (IData)((0U 
                                                   != 
                                                   (0x7e000f80U 
                                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1)))) 
                                       & (0U == ((0x20U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1 
                                                     >> 2U)) 
                                                 | (0x1fU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__exp_inst1_1 
                                                       >> 0x1aU))))))) 
                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__offset_from_aligned_pc_4) 
                                  <= ((7U == (7U & 
                                              (~ (IData)(
                                                         (0x1fffffffffULL 
                                                          & ((~ 
                                                              (((QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                                [0U][1U])) 
                                                                << 0x20U) 
                                                               | (QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                                [0U][0U])))) 
                                                             >> 3U))))))
                                       ? 0x18U : 0x20U)))));
    bufp->fullBit(oldp+98605,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_5) 
                                & ((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_3__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6)) 
                                     & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_5 
                                           >> 0x1fU))) 
                                    & (IData)((0U != 
                                               (0x7e000f80U 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_5)))) 
                                   & (0U == ((0x20U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_5 
                                                 >> 2U)) 
                                             | (0x1fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_5 
                                                   >> 0x1aU)))))) 
                               & ((0x7fU & ((IData)(0xaU) 
                                            + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_3_io_out_sfb_offset_bits))) 
                                  <= ((7U == (7U & 
                                              (~ (IData)(
                                                         (0x1fffffffffULL 
                                                          & ((~ 
                                                              (((QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                                [0U][1U])) 
                                                                << 0x20U) 
                                                               | (QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                                [0U][0U])))) 
                                                             >> 3U))))))
                                       ? 0x18U : 0x20U)))));
    bufp->fullBit(oldp+98606,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_6) 
                                & ((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_4__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6)) 
                                     & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_6 
                                           >> 0x1fU))) 
                                    & (IData)((0U != 
                                               (0x7e000f80U 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_6)))) 
                                   & (0U == ((0x20U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_6 
                                                 >> 2U)) 
                                             | (0x1fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_6 
                                                   >> 0x1aU)))))) 
                               & ((0x7fU & ((IData)(0xcU) 
                                            + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_4_io_out_sfb_offset_bits))) 
                                  <= ((7U == (7U & 
                                              (~ (IData)(
                                                         (0x1fffffffffULL 
                                                          & ((~ 
                                                              (((QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                                [0U][1U])) 
                                                                << 0x20U) 
                                                               | (QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                                [0U][0U])))) 
                                                             >> 3U))))))
                                       ? 0x18U : 0x20U)))));
    bufp->fullBit(oldp+98607,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_7) 
                                & ((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd_decoder_5__DOT___bpd_csignals_decoded_orMatrixOutputs_T_6)) 
                                     & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_7 
                                           >> 0x1fU))) 
                                    & (IData)((0U != 
                                               (0x7e000f80U 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_7)))) 
                                   & (0U == ((0x20U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_7 
                                                 >> 2U)) 
                                             | (0x1fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_exp_insts_7 
                                                   >> 0x1aU)))))) 
                               & ((0x7fU & ((IData)(0xeU) 
                                            + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_5_io_out_sfb_offset_bits))) 
                                  <= ((7U == (7U & 
                                              (~ (IData)(
                                                         (0x1fffffffffULL 
                                                          & ((~ 
                                                              (((QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                                [0U][1U])) 
                                                                << 0x20U) 
                                                               | (QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                                [0U][0U])))) 
                                                             >> 3U))))))
                                       ? 0x18U : 0x20U)))));
    bufp->fullSData(oldp+98608,((0xfffeU & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_3) 
                                               | ((0x8000U 
                                                   & ((0xffff8000U 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_46) 
                                                          << 0xeU)) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_3) 
                                                         << 0xfU))) 
                                                  | ((0x4000U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_46) 
                                                         << 0xeU)) 
                                                     | ((0x2000U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_45) 
                                                            << 0xdU)) 
                                                        | ((0x1000U 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_44) 
                                                               << 0xcU)) 
                                                           | ((0x800U 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_43) 
                                                                  << 0xbU)) 
                                                              | ((0x400U 
                                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_42) 
                                                                     << 0xaU)) 
                                                                 | ((0x200U 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_41) 
                                                                        << 9U)) 
                                                                    | ((0x100U 
                                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_40) 
                                                                           << 8U)) 
                                                                       | ((0x80U 
                                                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_39) 
                                                                              << 7U)) 
                                                                          | ((0x40U 
                                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_38) 
                                                                                << 6U)) 
                                                                             | ((0x20U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_37) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_36) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_35) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_34) 
                                                                                << 2U)) 
                                                                                | (2U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_3) 
                                                                                << 1U)))))))))))))))))))),16);
    bufp->fullSData(oldp+98609,((0xfffcU & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_7) 
                                               | ((0x8000U 
                                                   & ((0xffff8000U 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_59) 
                                                          << 0xeU)) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_7) 
                                                         << 0xfU))) 
                                                  | ((0x4000U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_59) 
                                                         << 0xeU)) 
                                                     | ((0x2000U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_58) 
                                                            << 0xdU)) 
                                                        | ((0x1000U 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_57) 
                                                               << 0xcU)) 
                                                           | ((0x800U 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_56) 
                                                                  << 0xbU)) 
                                                              | ((0x400U 
                                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_55) 
                                                                     << 0xaU)) 
                                                                 | ((0x200U 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_54) 
                                                                        << 9U)) 
                                                                    | ((0x100U 
                                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_53) 
                                                                           << 8U)) 
                                                                       | ((0x80U 
                                                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_52) 
                                                                              << 7U)) 
                                                                          | ((0x40U 
                                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_51) 
                                                                                << 6U)) 
                                                                             | ((0x20U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_50) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_49) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_48) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_47) 
                                                                                << 2U)) 
                                                                                | (2U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_7) 
                                                                                << 1U)))))))))))))))))))),16);
    bufp->fullSData(oldp+98610,((0xfff8U & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_11) 
                                               | ((0x8000U 
                                                   & ((0xffff8000U 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_72) 
                                                          << 0xeU)) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_11) 
                                                         << 0xfU))) 
                                                  | ((0x4000U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_72) 
                                                         << 0xeU)) 
                                                     | ((0x2000U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_71) 
                                                            << 0xdU)) 
                                                        | ((0x1000U 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_70) 
                                                               << 0xcU)) 
                                                           | ((0x800U 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_69) 
                                                                  << 0xbU)) 
                                                              | ((0x400U 
                                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_68) 
                                                                     << 0xaU)) 
                                                                 | ((0x200U 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_67) 
                                                                        << 9U)) 
                                                                    | ((0x100U 
                                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_66) 
                                                                           << 8U)) 
                                                                       | ((0x80U 
                                                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_65) 
                                                                              << 7U)) 
                                                                          | ((0x40U 
                                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_64) 
                                                                                << 6U)) 
                                                                             | ((0x20U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_63) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_62) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_61) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_60) 
                                                                                << 2U)) 
                                                                                | (2U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_11) 
                                                                                << 1U)))))))))))))))))))),16);
    bufp->fullSData(oldp+98611,((0xfff0U & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_15) 
                                               | ((0x8000U 
                                                   & ((0xffff8000U 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_85) 
                                                          << 0xeU)) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_15) 
                                                         << 0xfU))) 
                                                  | ((0x4000U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_85) 
                                                         << 0xeU)) 
                                                     | ((0x2000U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_84) 
                                                            << 0xdU)) 
                                                        | ((0x1000U 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_83) 
                                                               << 0xcU)) 
                                                           | ((0x800U 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_82) 
                                                                  << 0xbU)) 
                                                              | ((0x400U 
                                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_81) 
                                                                     << 0xaU)) 
                                                                 | ((0x200U 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_80) 
                                                                        << 9U)) 
                                                                    | ((0x100U 
                                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_79) 
                                                                           << 8U)) 
                                                                       | ((0x80U 
                                                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_78) 
                                                                              << 7U)) 
                                                                          | ((0x40U 
                                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_77) 
                                                                                << 6U)) 
                                                                             | ((0x20U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_76) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_75) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_74) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_73) 
                                                                                << 2U)) 
                                                                                | (2U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_15) 
                                                                                << 1U)))))))))))))))))))),16);
    bufp->fullSData(oldp+98612,((0xffe0U & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_19) 
                                               | ((0x8000U 
                                                   & ((0xffff8000U 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_98) 
                                                          << 0xeU)) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_19) 
                                                         << 0xfU))) 
                                                  | ((0x4000U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_98) 
                                                         << 0xeU)) 
                                                     | ((0x2000U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_97) 
                                                            << 0xdU)) 
                                                        | ((0x1000U 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_96) 
                                                               << 0xcU)) 
                                                           | ((0x800U 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_95) 
                                                                  << 0xbU)) 
                                                              | ((0x400U 
                                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_94) 
                                                                     << 0xaU)) 
                                                                 | ((0x200U 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_93) 
                                                                        << 9U)) 
                                                                    | ((0x100U 
                                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_92) 
                                                                           << 8U)) 
                                                                       | ((0x80U 
                                                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_91) 
                                                                              << 7U)) 
                                                                          | ((0x40U 
                                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_90) 
                                                                                << 6U)) 
                                                                             | ((0x20U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_89) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_88) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_87) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_86) 
                                                                                << 2U)) 
                                                                                | (2U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_19) 
                                                                                << 1U)))))))))))))))))))),16);
    bufp->fullSData(oldp+98613,((0xffc0U & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_23) 
                                               | ((0x8000U 
                                                   & ((0xffff8000U 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_111) 
                                                          << 0xeU)) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_23) 
                                                         << 0xfU))) 
                                                  | ((0x4000U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_111) 
                                                         << 0xeU)) 
                                                     | ((0x2000U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_110) 
                                                            << 0xdU)) 
                                                        | ((0x1000U 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_109) 
                                                               << 0xcU)) 
                                                           | ((0x800U 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_108) 
                                                                  << 0xbU)) 
                                                              | ((0x400U 
                                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_107) 
                                                                     << 0xaU)) 
                                                                 | ((0x200U 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_106) 
                                                                        << 9U)) 
                                                                    | ((0x100U 
                                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_105) 
                                                                           << 8U)) 
                                                                       | ((0x80U 
                                                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_104) 
                                                                              << 7U)) 
                                                                          | ((0x40U 
                                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_103) 
                                                                                << 6U)) 
                                                                             | ((0x20U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_102) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_101) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_100) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_99) 
                                                                                << 2U)) 
                                                                                | (2U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_23) 
                                                                                << 1U)))))))))))))))))))),16);
    bufp->fullSData(oldp+98614,((0xff80U & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_27) 
                                               | ((0x8000U 
                                                   & ((0xffff8000U 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_124) 
                                                          << 0xeU)) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_27) 
                                                         << 0xfU))) 
                                                  | ((0x4000U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_124) 
                                                         << 0xeU)) 
                                                     | ((0x2000U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_123) 
                                                            << 0xdU)) 
                                                        | ((0x1000U 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_122) 
                                                               << 0xcU)) 
                                                           | ((0x800U 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_121) 
                                                                  << 0xbU)) 
                                                              | ((0x400U 
                                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_120) 
                                                                     << 0xaU)) 
                                                                 | ((0x200U 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_119) 
                                                                        << 9U)) 
                                                                    | ((0x100U 
                                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_118) 
                                                                           << 8U)) 
                                                                       | ((0x80U 
                                                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_117) 
                                                                              << 7U)) 
                                                                          | ((0x40U 
                                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_116) 
                                                                                << 6U)) 
                                                                             | ((0x20U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_115) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_114) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_113) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_112) 
                                                                                << 2U)) 
                                                                                | (2U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_27) 
                                                                                << 1U)))))))))))))))))))),16);
    bufp->fullSData(oldp+98615,((0xff00U & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_31) 
                                               | ((0x8000U 
                                                   & ((0xffff8000U 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_137) 
                                                          << 0xeU)) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_31) 
                                                         << 0xfU))) 
                                                  | ((0x4000U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_137) 
                                                         << 0xeU)) 
                                                     | ((0x2000U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_136) 
                                                            << 0xdU)) 
                                                        | ((0x1000U 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_135) 
                                                               << 0xcU)) 
                                                           | ((0x800U 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_134) 
                                                                  << 0xbU)) 
                                                              | ((0x400U 
                                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_133) 
                                                                     << 0xaU)) 
                                                                 | ((0x200U 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_132) 
                                                                        << 9U)) 
                                                                    | ((0x100U 
                                                                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_131) 
                                                                           << 8U)) 
                                                                       | ((0x80U 
                                                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_130) 
                                                                              << 7U)) 
                                                                          | ((0x40U 
                                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_129) 
                                                                                << 6U)) 
                                                                             | ((0x20U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_128) 
                                                                                << 5U)) 
                                                                                | ((0x10U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_127) 
                                                                                << 4U)) 
                                                                                | ((8U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_126) 
                                                                                << 3U)) 
                                                                                | ((4U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_125) 
                                                                                << 2U)) 
                                                                                | (2U 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_31) 
                                                                                << 1U)))))))))))))))))))),16);
    bufp->fullCData(oldp+98616,((0x1fU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__offset_from_aligned_pc))),5);
    bufp->fullCData(oldp+98617,((0x1fU & ((IData)(2U) 
                                          + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_io_out_sfb_offset_bits)))),5);
    bufp->fullCData(oldp+98618,((0x1fU & ((IData)(4U) 
                                          + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_1_io_out_sfb_offset_bits)))),5);
    bufp->fullCData(oldp+98619,((0x1fU & ((IData)(6U) 
                                          + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_2_io_out_sfb_offset_bits)))),5);
    bufp->fullCData(oldp+98620,((0x1fU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__offset_from_aligned_pc_4))),5);
    bufp->fullCData(oldp+98621,((0x1fU & ((IData)(0xaU) 
                                          + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_3_io_out_sfb_offset_bits)))),5);
    bufp->fullCData(oldp+98622,((0x1fU & ((IData)(0xcU) 
                                          + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_4_io_out_sfb_offset_bits)))),5);
    bufp->fullCData(oldp+98623,((0x1fU & ((IData)(0xeU) 
                                          + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_5_io_out_sfb_offset_bits)))),5);
    bufp->fullBit(oldp+98624,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___s0_valid_T_11)) 
                                     & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_prev_is_half)
                                          ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder0_io_out_shadowable)
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder1_io_out_shadowable)) 
                                        | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_0)))))));
    bufp->fullBit(oldp+98625,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___s0_valid_T_11)) 
                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_io_out_shadowable) 
                                        | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_1)))))));
    bufp->fullBit(oldp+98626,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___s0_valid_T_11)) 
                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_1_io_out_shadowable) 
                                        | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_2)))))));
    bufp->fullBit(oldp+98627,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___s0_valid_T_11)) 
                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_2_io_out_shadowable) 
                                        | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_3)))))));
    bufp->fullBit(oldp+98628,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___s0_valid_T_11)) 
                                & (7U != (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                [0U][0U] 
                                                >> 3U)))) 
                               & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___T_42)
                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder0b_io_out_shadowable)
                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder1_1_io_out_shadowable)) 
                                  | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_4))))));
    bufp->fullBit(oldp+98629,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___s0_valid_T_11)) 
                                & (7U != (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                [0U][0U] 
                                                >> 3U)))) 
                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_3_io_out_shadowable) 
                                  | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_5))))));
    bufp->fullBit(oldp+98630,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___s0_valid_T_11)) 
                                & (7U != (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                [0U][0U] 
                                                >> 3U)))) 
                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_4_io_out_shadowable) 
                                  | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_6))))));
    bufp->fullBit(oldp+98631,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___s0_valid_T_11)) 
                                & (7U != (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                [0U][0U] 
                                                >> 3U)))) 
                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_5_io_out_shadowable) 
                                  | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_7))))));
    bufp->fullCData(oldp+98632,(((0x17U >= (0x1fU & 
                                            ((IData)(3U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_cfi_idx_bits))))
                                  ? (7U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_5_io_out_cfi_type) 
                                             << 0x15U) 
                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_4_io_out_cfi_type) 
                                                << 0x12U) 
                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_3_io_out_cfi_type) 
                                                   << 0xfU) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__brsigs_4_cfi_type) 
                                                      << 0xcU) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_2_io_out_cfi_type) 
                                                         << 9U) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_1_io_out_cfi_type) 
                                                            << 6U) 
                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___bpd_decoder_io_out_cfi_type) 
                                                               << 3U) 
                                                              | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__brsigs_cfi_type)))))))) 
                                           >> (0x1fU 
                                               & ((IData)(3U) 
                                                  * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_fetch_bundle_cfi_idx_bits)))))
                                  : 0U)),3);
    bufp->fullQData(oldp+98633,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___ras_io_read_addr),40);
    bufp->fullCData(oldp+98635,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_7) 
                                  << 7U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_6) 
                                             << 6U) 
                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_5) 
                                                << 5U) 
                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_4) 
                                                   << 4U) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_3) 
                                                      << 3U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_2) 
                                                         << 2U) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_1) 
                                                            << 1U) 
                                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_0))))))))),8);
    bufp->fullSData(oldp+98636,((0xffffU & ((7U != 
                                             (7U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                               [0U][0U] 
                                               >> 3U)))
                                             ? ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                 [0U][5U] 
                                                 << 8U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                   [0U][4U] 
                                                   >> 0x18U))
                                             : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                 [0U][3U] 
                                                 << 8U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                   [0U][2U] 
                                                   >> 0x18U))))),16);
    bufp->fullCData(oldp+98637,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_155)
                                  ? (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                           [0U][7U] 
                                           >> 0x1bU))
                                  : 2U)),2);
    bufp->fullBit(oldp+98638,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT____Vcellinp__f4__io_deq_ready));
    bufp->fullBit(oldp+98639,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__maybe_full));
    bufp->fullQData(oldp+98640,((0xffffffffffULL & 
                                 (((QData)((IData)(
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                   [0U][1U])) 
                                   << 0x20U) | (QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                               [0U][0U]))))),40);
    bufp->fullBit(oldp+98642,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][2U] >> 0x10U))));
    bufp->fullBit(oldp+98643,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][2U] >> 0x11U))));
    bufp->fullIData(oldp+98644,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                  [0U][3U] << 0xeU) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][2U] >> 0x12U))),32);
    bufp->fullIData(oldp+98645,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                  [0U][4U] << 0xeU) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][3U] >> 0x12U))),32);
    bufp->fullIData(oldp+98646,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                  [0U][5U] << 0xeU) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][4U] >> 0x12U))),32);
    bufp->fullIData(oldp+98647,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                  [0U][6U] << 0xeU) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][5U] >> 0x12U))),32);
    bufp->fullIData(oldp+98648,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                  [0U][7U] << 0xeU) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][6U] >> 0x12U))),32);
    bufp->fullIData(oldp+98649,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                  [0U][8U] << 0xeU) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][7U] >> 0x12U))),32);
    bufp->fullIData(oldp+98650,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                  [0U][9U] << 0xeU) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][8U] >> 0x12U))),32);
    bufp->fullIData(oldp+98651,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                  [0U][0xaU] << 0xeU) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][9U] >> 0x12U))),32);
    bufp->fullIData(oldp+98652,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                  [0U][0xbU] << 0xeU) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][0xaU] >> 0x12U))),32);
    bufp->fullIData(oldp+98653,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                  [0U][0xcU] << 0xeU) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][0xbU] >> 0x12U))),32);
    bufp->fullIData(oldp+98654,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                  [0U][0xdU] << 0xeU) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][0xcU] >> 0x12U))),32);
    bufp->fullIData(oldp+98655,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                  [0U][0xeU] << 0xeU) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][0xdU] >> 0x12U))),32);
    bufp->fullIData(oldp+98656,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                  [0U][0xfU] << 0xeU) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][0xeU] >> 0x12U))),32);
    bufp->fullIData(oldp+98657,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                  [0U][0x10U] << 0xeU) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][0xfU] >> 0x12U))),32);
    bufp->fullIData(oldp+98658,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                  [0U][0x11U] << 0xeU) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][0x10U] >> 0x12U))),32);
    bufp->fullIData(oldp+98659,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                  [0U][0x12U] << 0xeU) 
                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][0x11U] >> 0x12U))),32);
    bufp->fullBit(oldp+98660,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x12U] >> 0x12U))));
    bufp->fullBit(oldp+98661,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x12U] >> 0x13U))));
    bufp->fullBit(oldp+98662,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x12U] >> 0x14U))));
    bufp->fullBit(oldp+98663,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x12U] >> 0x15U))));
    bufp->fullBit(oldp+98664,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x12U] >> 0x16U))));
    bufp->fullBit(oldp+98665,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x12U] >> 0x17U))));
    bufp->fullBit(oldp+98666,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x12U] >> 0x18U))));
    bufp->fullBit(oldp+98667,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x12U] >> 0x19U))));
    bufp->fullBit(oldp+98668,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x18U] >> 0xaU))));
    bufp->fullBit(oldp+98669,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x18U] >> 0xbU))));
    bufp->fullBit(oldp+98670,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x18U] >> 0xcU))));
    bufp->fullBit(oldp+98671,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x18U] >> 0xdU))));
    bufp->fullBit(oldp+98672,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x18U] >> 0xeU))));
    bufp->fullBit(oldp+98673,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x18U] >> 0xfU))));
    bufp->fullBit(oldp+98674,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x18U] >> 0x10U))));
    bufp->fullBit(oldp+98675,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x18U] >> 0x11U))));
    bufp->fullBit(oldp+98676,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x18U] >> 0x12U))));
    bufp->fullCData(oldp+98677,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                       [0U][0x18U] 
                                       >> 0x13U))),3);
    bufp->fullCData(oldp+98678,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                       [0U][0x18U] 
                                       >> 0x16U))),3);
    bufp->fullBit(oldp+98679,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x18U] >> 0x19U))));
    bufp->fullBit(oldp+98680,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x18U] >> 0x1aU))));
    bufp->fullQData(oldp+98681,((0xffffffffffULL & 
                                 (((QData)((IData)(
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                   [0U][0x1aU])) 
                                   << 0x24U) | (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                                 [0U][0x19U])) 
                                                 << 4U) 
                                                | ((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                                   [0U][0x18U])) 
                                                   >> 0x1cU))))),40);
    bufp->fullCData(oldp+98683,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                          [0U][0x1aU] 
                                          >> 9U))),8);
    bufp->fullCData(oldp+98684,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                          [0U][0x1aU] 
                                          >> 0x11U))),8);
    bufp->fullQData(oldp+98685,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                  [0U][0x1cU])) 
                                  << 0x27U) | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                                [0U][0x1bU])) 
                                                << 7U) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                                  [0U][0x1aU])) 
                                                  >> 0x19U)))),64);
    bufp->fullBit(oldp+98687,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x1cU] >> 0x19U))));
    bufp->fullBit(oldp+98688,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x1cU] >> 0x1aU))));
    bufp->fullBit(oldp+98689,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x1cU] >> 0x1bU))));
    bufp->fullCData(oldp+98690,((0x1fU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                           [0U][0x1dU] 
                                           << 4U) | 
                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                           [0U][0x1cU] 
                                           >> 0x1cU)))),5);
    bufp->fullBit(oldp+98691,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x1dU] >> 3U))));
    bufp->fullBit(oldp+98692,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x1dU] >> 4U))));
    bufp->fullBit(oldp+98693,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x1dU] >> 5U))));
    bufp->fullBit(oldp+98694,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x1dU] >> 6U))));
    bufp->fullBit(oldp+98695,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x1dU] >> 7U))));
    bufp->fullBit(oldp+98696,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x1dU] >> 8U))));
    bufp->fullBit(oldp+98697,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x1dU] >> 9U))));
    bufp->fullBit(oldp+98698,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x1dU] >> 0xaU))));
    bufp->fullBit(oldp+98699,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x1dU] >> 0xbU))));
    bufp->fullBit(oldp+98700,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x1dU] >> 0xcU))));
    bufp->fullBit(oldp+98701,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x1dU] >> 0xdU))));
    bufp->fullBit(oldp+98702,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x1dU] >> 0xeU))));
    bufp->fullBit(oldp+98703,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x1dU] >> 0xfU))));
    bufp->fullBit(oldp+98704,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x1dU] >> 0x10U))));
    bufp->fullBit(oldp+98705,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x1dU] >> 0x11U))));
    bufp->fullBit(oldp+98706,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x1dU] >> 0x12U))));
    bufp->fullBit(oldp+98707,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x1dU] >> 0x13U))));
    bufp->fullBit(oldp+98708,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                     [0U][0x1dU] >> 0x14U))));
    __Vtemp_h9acaeb9e__0[0U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                 [0U][0x1fU] << 0x1aU) 
                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                   [0U][0x1eU] >> 6U));
    __Vtemp_h9acaeb9e__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                 [0U][0x20U] << 0x1aU) 
                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                   [0U][0x1fU] >> 6U));
    __Vtemp_h9acaeb9e__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                 [0U][0x21U] << 0x1aU) 
                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                   [0U][0x20U] >> 6U));
    __Vtemp_h9acaeb9e__0[3U] = (0xffffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                             [0U][0x21U] 
                                             >> 6U));
    bufp->fullWData(oldp+98709,(__Vtemp_h9acaeb9e__0),120);
    __Vtemp_h9d2b6528__0[0U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                 [0U][0x22U] << 2U) 
                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                   [0U][0x21U] >> 0x1eU));
    __Vtemp_h9d2b6528__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                 [0U][0x23U] << 2U) 
                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                   [0U][0x22U] >> 0x1eU));
    __Vtemp_h9d2b6528__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                 [0U][0x24U] << 2U) 
                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                   [0U][0x23U] >> 0x1eU));
    __Vtemp_h9d2b6528__0[3U] = (0xffffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                              [0U][0x25U] 
                                              << 2U) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                [0U][0x24U] 
                                                >> 0x1eU)));
    bufp->fullWData(oldp+98713,(__Vtemp_h9d2b6528__0),120);
    bufp->fullCData(oldp+98717,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                       [0U][0x25U] 
                                       >> 0x16U))),2);
    bufp->fullBit(oldp+98718,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__do_enq));
    bufp->fullWData(oldp+98719,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT____Vcellinp__ram_ext__W0_data),1210);
    __Vtemp_h97de8984__69[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0U];
    __Vtemp_h97de8984__69[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][1U];
    __Vtemp_h97de8984__69[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][2U];
    __Vtemp_h97de8984__69[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][3U];
    __Vtemp_h97de8984__69[4U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][4U];
    __Vtemp_h97de8984__69[5U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][5U];
    __Vtemp_h97de8984__69[6U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][6U];
    __Vtemp_h97de8984__69[7U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][7U];
    __Vtemp_h97de8984__69[8U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][8U];
    __Vtemp_h97de8984__69[9U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][9U];
    __Vtemp_h97de8984__69[0xaU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0xaU];
    __Vtemp_h97de8984__69[0xbU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0xbU];
    __Vtemp_h97de8984__69[0xcU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0xcU];
    __Vtemp_h97de8984__69[0xdU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0xdU];
    __Vtemp_h97de8984__69[0xeU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0xeU];
    __Vtemp_h97de8984__69[0xfU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0xfU];
    __Vtemp_h97de8984__69[0x10U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0x10U];
    __Vtemp_h97de8984__69[0x11U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0x11U];
    __Vtemp_h97de8984__69[0x12U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0x12U];
    __Vtemp_h97de8984__69[0x13U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0x13U];
    __Vtemp_h97de8984__69[0x14U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0x14U];
    __Vtemp_h97de8984__69[0x15U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0x15U];
    __Vtemp_h97de8984__69[0x16U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0x16U];
    __Vtemp_h97de8984__69[0x17U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0x17U];
    __Vtemp_h97de8984__69[0x18U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0x18U];
    __Vtemp_h97de8984__69[0x19U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0x19U];
    __Vtemp_h97de8984__69[0x1aU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0x1aU];
    __Vtemp_h97de8984__69[0x1bU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0x1bU];
    __Vtemp_h97de8984__69[0x1cU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0x1cU];
    __Vtemp_h97de8984__69[0x1dU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0x1dU];
    __Vtemp_h97de8984__69[0x1eU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0x1eU];
    __Vtemp_h97de8984__69[0x1fU] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0x1fU];
    __Vtemp_h97de8984__69[0x20U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0x20U];
    __Vtemp_h97de8984__69[0x21U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0x21U];
    __Vtemp_h97de8984__69[0x22U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0x22U];
    __Vtemp_h97de8984__69[0x23U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0x23U];
    __Vtemp_h97de8984__69[0x24U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0x24U];
    __Vtemp_h97de8984__69[0x25U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
        [0U][0x25U];
    bufp->fullWData(oldp+98757,(__Vtemp_h97de8984__69),1210);
    bufp->fullWData(oldp+98795,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory[0]),1210);
    bufp->fullBit(oldp+98833,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f4_btb_corrections_io_enq_valid_T) 
                               & ((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_0) 
                                        | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_1)) 
                                       | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_2)) 
                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_3)) 
                                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_4)) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_5)) 
                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_6)) 
                                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_7)))));
    bufp->fullCData(oldp+98834,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_7) 
                                  << 7U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_6) 
                                             << 6U) 
                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_5) 
                                                << 5U) 
                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_4) 
                                                   << 4U) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_3) 
                                                      << 3U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_2) 
                                                         << 2U) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_1) 
                                                            << 1U) 
                                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_0))))))))),8);
    bufp->fullBit(oldp+98835,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT__enq_ptr_value));
    bufp->fullBit(oldp+98836,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT__deq_ptr_value));
    bufp->fullBit(oldp+98837,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT__maybe_full));
    bufp->fullBit(oldp+98838,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT__ptr_match));
    bufp->fullBit(oldp+98839,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT__empty));
    bufp->fullBit(oldp+98840,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT__do_enq));
    bufp->fullBit(oldp+98841,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT__do_deq));
    VL_EXTEND_WQ(67,50, __Vtemp_hf1b6c900__0, ((0x3fffffffffc00ULL 
                                                & (((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                    [0U][1U])) 
                                                    << 0x2aU) 
                                                   | ((QData)((IData)(
                                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                      [0U][0U])) 
                                                      << 0xaU))) 
                                               | (QData)((IData)(
                                                                 (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_7) 
                                                                   << 9U) 
                                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_6) 
                                                                      << 8U) 
                                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_5) 
                                                                         << 7U) 
                                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_4) 
                                                                            << 6U) 
                                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_3) 
                                                                               << 5U) 
                                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_2) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_1) 
                                                                                << 3U) 
                                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_btb_mispredicts_0) 
                                                                                << 2U))))))))))));
    __Vtemp_hc02632b9__0[0U] = __Vtemp_hf1b6c900__0[0U];
    __Vtemp_hc02632b9__0[1U] = __Vtemp_hf1b6c900__0[1U];
    __Vtemp_hc02632b9__0[2U] = (((IData)((((QData)((IData)(
                                                           vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                           [0U][7U])) 
                                           << 0x2dU) 
                                          | (((QData)((IData)(
                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                              [0U][6U])) 
                                              << 0xdU) 
                                             | ((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                [0U][5U])) 
                                                >> 0x13U)))) 
                                 << 3U) | __Vtemp_hf1b6c900__0[2U]);
    __Vtemp_hc02632b9__0[3U] = (((IData)((((QData)((IData)(
                                                           vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                           [0U][7U])) 
                                           << 0x2dU) 
                                          | (((QData)((IData)(
                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                              [0U][6U])) 
                                              << 0xdU) 
                                             | ((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                [0U][5U])) 
                                                >> 0x13U)))) 
                                 >> 0x1dU) | ((IData)(
                                                      ((((QData)((IData)(
                                                                         vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                         [0U][7U])) 
                                                         << 0x2dU) 
                                                        | (((QData)((IData)(
                                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                            [0U][6U])) 
                                                            << 0xdU) 
                                                           | ((QData)((IData)(
                                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                              [0U][5U])) 
                                                              >> 0x13U))) 
                                                       >> 0x20U)) 
                                              << 3U));
    __Vtemp_hc02632b9__0[4U] = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_lhist_1) 
                                  << 0xcU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_lhist_0) 
                                               << 0xbU) 
                                              | (0x7e0U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                    [0U][7U] 
                                                    >> 0x10U)))) 
                                | ((0x10U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                             [0U][7U] 
                                             >> 0x10U)) 
                                   | ((8U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                             [0U][7U] 
                                             >> 0x10U)) 
                                      | ((IData)(((
                                                   ((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                    [0U][7U])) 
                                                    << 0x2dU) 
                                                   | (((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                       [0U][6U])) 
                                                       << 0xdU) 
                                                      | ((QData)((IData)(
                                                                         vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                                                                         [0U][5U])) 
                                                         >> 0x13U))) 
                                                  >> 0x20U)) 
                                         >> 0x1dU))));
    __Vtemp_hc02632b9__0[5U] = ((0x1fU & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_lhist_1) 
                                           >> 0x14U) 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_lhist_0) 
                                             >> 0x15U))) 
                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_0[0U] 
                                   << 0x15U));
    __Vtemp_hc02632b9__0[6U] = ((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_0[0U] 
                                          >> 0xbU)) 
                                | ((0x1fe0U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_0[0U] 
                                               >> 0xbU)) 
                                   | ((0x1fe000U & 
                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_0[0U] 
                                        >> 0xbU)) | 
                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_0[1U] 
                                       << 0x15U))));
    __Vtemp_hc02632b9__0[7U] = ((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_0[1U] 
                                          >> 0xbU)) 
                                | ((0x1fe0U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_0[1U] 
                                               >> 0xbU)) 
                                   | ((0x1fe000U & 
                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_0[1U] 
                                        >> 0xbU)) | 
                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_0[2U] 
                                       << 0x15U))));
    __Vtemp_hc02632b9__0[8U] = ((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_0[2U] 
                                          >> 0xbU)) 
                                | ((0x1fe0U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_0[2U] 
                                               >> 0xbU)) 
                                   | ((0x1fe000U & 
                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_0[2U] 
                                        >> 0xbU)) | 
                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_0[3U] 
                                       << 0x15U))));
    __Vtemp_hc02632b9__0[9U] = ((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_0[3U] 
                                          >> 0xbU)) 
                                | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_1[0U] 
                                    << 0xdU) | (0x1fe0U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_0[3U] 
                                                   >> 0xbU))));
    __Vtemp_hc02632b9__0[0xaU] = ((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_1[0U] 
                                            >> 0x13U)) 
                                  | ((0x1fe0U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_1[0U] 
                                                 >> 0x13U)) 
                                     | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_1[1U] 
                                        << 0xdU)));
    __Vtemp_hc02632b9__0[0xbU] = ((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_1[1U] 
                                            >> 0x13U)) 
                                  | ((0x1fe0U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_1[1U] 
                                                 >> 0x13U)) 
                                     | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_1[2U] 
                                        << 0xdU)));
    __Vtemp_hc02632b9__0[0xcU] = ((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_1[2U] 
                                            >> 0x13U)) 
                                  | ((0x1fe0U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_1[2U] 
                                                 >> 0x13U)) 
                                     | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_1[3U] 
                                        << 0xdU)));
    __Vtemp_hc02632b9__0[0xdU] = (0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___f3_bpd_resp_io_deq_bits_meta_1[3U] 
                                           >> 0x13U));
    bufp->fullWData(oldp+98842,(__Vtemp_hc02632b9__0),421);
    bufp->fullWData(oldp+98856,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT___ram_ext_R0_data),421);
    bufp->fullWData(oldp+98870,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT__ram_ext__DOT__Memory[0]),421);
    bufp->fullWData(oldp+98884,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT__ram_ext__DOT__Memory[1]),421);
    bufp->fullBit(oldp+98898,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT____Vcellinp__fb__io_enq_valid));
    bufp->fullCData(oldp+98899,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__enq_ptr),5);
    bufp->fullBit(oldp+98900,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___do_enq_T_1)))));
    bufp->fullIData(oldp+98901,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_inst),32);
    bufp->fullIData(oldp+98902,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_debug_inst),32);
    bufp->fullBit(oldp+98903,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_is_rvc));
    bufp->fullQData(oldp+98904,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_debug_pc),40);
    bufp->fullCData(oldp+98906,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_ctrl_br_type),4);
    bufp->fullCData(oldp+98907,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_ctrl_op1_sel),2);
    bufp->fullCData(oldp+98908,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_ctrl_op2_sel),3);
    bufp->fullCData(oldp+98909,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_ctrl_op_fcn),4);
    bufp->fullBit(oldp+98910,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_ctrl_fcn_dw));
    bufp->fullBit(oldp+98911,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_ctrl_is_load));
    bufp->fullBit(oldp+98912,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_ctrl_is_sta));
    bufp->fullBit(oldp+98913,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_ctrl_is_std));
    bufp->fullCData(oldp+98914,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_iw_state),2);
    bufp->fullBit(oldp+98915,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_iw_p1_poisoned));
    bufp->fullBit(oldp+98916,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_iw_p2_poisoned));
    bufp->fullBit(oldp+98917,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_is_sfb));
    bufp->fullCData(oldp+98918,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_ftq_idx),5);
    bufp->fullBit(oldp+98919,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_edge_inst));
    bufp->fullCData(oldp+98920,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_pc_lob),6);
    bufp->fullBit(oldp+98921,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_taken));
    bufp->fullBit(oldp+98922,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_xcpt_pf_if));
    bufp->fullBit(oldp+98923,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_xcpt_ae_if));
    bufp->fullBit(oldp+98924,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_xcpt_ma_if));
    bufp->fullBit(oldp+98925,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_bp_debug_if));
    bufp->fullBit(oldp+98926,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_bp_xcpt_if));
    bufp->fullCData(oldp+98927,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_debug_fsrc),2);
    bufp->fullCData(oldp+98928,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_debug_tsrc),2);
    bufp->fullIData(oldp+98929,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_inst),32);
    bufp->fullIData(oldp+98930,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_debug_inst),32);
    bufp->fullBit(oldp+98931,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_is_rvc));
    bufp->fullQData(oldp+98932,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_debug_pc),40);
    bufp->fullCData(oldp+98934,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_ctrl_br_type),4);
    bufp->fullCData(oldp+98935,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_ctrl_op1_sel),2);
    bufp->fullCData(oldp+98936,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_ctrl_op2_sel),3);
    bufp->fullCData(oldp+98937,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_ctrl_op_fcn),4);
    bufp->fullBit(oldp+98938,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_ctrl_fcn_dw));
    bufp->fullBit(oldp+98939,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_ctrl_is_load));
    bufp->fullBit(oldp+98940,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_ctrl_is_sta));
    bufp->fullBit(oldp+98941,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_ctrl_is_std));
    bufp->fullCData(oldp+98942,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_iw_state),2);
    bufp->fullBit(oldp+98943,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_iw_p1_poisoned));
    bufp->fullBit(oldp+98944,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_iw_p2_poisoned));
    bufp->fullBit(oldp+98945,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_is_sfb));
    bufp->fullCData(oldp+98946,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_ftq_idx),5);
    bufp->fullBit(oldp+98947,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_edge_inst));
    bufp->fullCData(oldp+98948,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_pc_lob),6);
    bufp->fullBit(oldp+98949,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_taken));
    bufp->fullBit(oldp+98950,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_xcpt_pf_if));
    bufp->fullBit(oldp+98951,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_xcpt_ae_if));
    bufp->fullBit(oldp+98952,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_xcpt_ma_if));
    bufp->fullBit(oldp+98953,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_bp_debug_if));
    bufp->fullBit(oldp+98954,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_bp_xcpt_if));
    bufp->fullCData(oldp+98955,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_debug_fsrc),2);
    bufp->fullCData(oldp+98956,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_debug_tsrc),2);
    bufp->fullIData(oldp+98957,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_inst),32);
    bufp->fullIData(oldp+98958,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_debug_inst),32);
    bufp->fullBit(oldp+98959,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_is_rvc));
    bufp->fullQData(oldp+98960,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_debug_pc),40);
    bufp->fullCData(oldp+98962,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_ctrl_br_type),4);
    bufp->fullCData(oldp+98963,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_ctrl_op1_sel),2);
    bufp->fullCData(oldp+98964,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_ctrl_op2_sel),3);
    bufp->fullCData(oldp+98965,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_ctrl_op_fcn),4);
    bufp->fullBit(oldp+98966,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_ctrl_fcn_dw));
    bufp->fullBit(oldp+98967,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_ctrl_is_load));
    bufp->fullBit(oldp+98968,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_ctrl_is_sta));
    bufp->fullBit(oldp+98969,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_ctrl_is_std));
    bufp->fullCData(oldp+98970,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_iw_state),2);
    bufp->fullBit(oldp+98971,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_iw_p1_poisoned));
    bufp->fullBit(oldp+98972,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_iw_p2_poisoned));
    bufp->fullBit(oldp+98973,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_is_sfb));
    bufp->fullCData(oldp+98974,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_ftq_idx),5);
    bufp->fullBit(oldp+98975,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_edge_inst));
    bufp->fullCData(oldp+98976,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_pc_lob),6);
    bufp->fullBit(oldp+98977,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_taken));
    bufp->fullBit(oldp+98978,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_xcpt_pf_if));
    bufp->fullBit(oldp+98979,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_xcpt_ae_if));
    bufp->fullBit(oldp+98980,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_xcpt_ma_if));
    bufp->fullBit(oldp+98981,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_bp_debug_if));
    bufp->fullBit(oldp+98982,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_bp_xcpt_if));
    bufp->fullCData(oldp+98983,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_debug_fsrc),2);
    bufp->fullCData(oldp+98984,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_debug_tsrc),2);
    bufp->fullIData(oldp+98985,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_inst),32);
    bufp->fullIData(oldp+98986,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_debug_inst),32);
    bufp->fullBit(oldp+98987,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_is_rvc));
    bufp->fullQData(oldp+98988,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_debug_pc),40);
    bufp->fullCData(oldp+98990,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_ctrl_br_type),4);
    bufp->fullCData(oldp+98991,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_ctrl_op1_sel),2);
    bufp->fullCData(oldp+98992,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_ctrl_op2_sel),3);
    bufp->fullCData(oldp+98993,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_ctrl_op_fcn),4);
    bufp->fullBit(oldp+98994,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_ctrl_fcn_dw));
    bufp->fullBit(oldp+98995,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_ctrl_is_load));
    bufp->fullBit(oldp+98996,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_ctrl_is_sta));
    bufp->fullBit(oldp+98997,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_ctrl_is_std));
    bufp->fullCData(oldp+98998,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_iw_state),2);
    bufp->fullBit(oldp+98999,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_iw_p1_poisoned));
    bufp->fullBit(oldp+99000,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_iw_p2_poisoned));
    bufp->fullBit(oldp+99001,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_is_sfb));
    bufp->fullCData(oldp+99002,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_ftq_idx),5);
    bufp->fullBit(oldp+99003,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_edge_inst));
    bufp->fullCData(oldp+99004,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_pc_lob),6);
    bufp->fullBit(oldp+99005,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_taken));
    bufp->fullBit(oldp+99006,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_xcpt_pf_if));
    bufp->fullBit(oldp+99007,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_xcpt_ae_if));
    bufp->fullBit(oldp+99008,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_xcpt_ma_if));
    bufp->fullBit(oldp+99009,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_bp_debug_if));
    bufp->fullBit(oldp+99010,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_bp_xcpt_if));
    bufp->fullCData(oldp+99011,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_debug_fsrc),2);
    bufp->fullCData(oldp+99012,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_debug_tsrc),2);
    bufp->fullIData(oldp+99013,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_inst),32);
    bufp->fullIData(oldp+99014,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_debug_inst),32);
    bufp->fullBit(oldp+99015,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_is_rvc));
    bufp->fullQData(oldp+99016,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_debug_pc),40);
    bufp->fullCData(oldp+99018,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_ctrl_br_type),4);
    bufp->fullCData(oldp+99019,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_ctrl_op1_sel),2);
    bufp->fullCData(oldp+99020,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_ctrl_op2_sel),3);
    bufp->fullCData(oldp+99021,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_ctrl_op_fcn),4);
    bufp->fullBit(oldp+99022,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_ctrl_fcn_dw));
    bufp->fullBit(oldp+99023,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_ctrl_is_load));
    bufp->fullBit(oldp+99024,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_ctrl_is_sta));
    bufp->fullBit(oldp+99025,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_ctrl_is_std));
    bufp->fullCData(oldp+99026,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_iw_state),2);
    bufp->fullBit(oldp+99027,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_iw_p1_poisoned));
    bufp->fullBit(oldp+99028,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_iw_p2_poisoned));
    bufp->fullBit(oldp+99029,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_is_sfb));
    bufp->fullCData(oldp+99030,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_ftq_idx),5);
    bufp->fullBit(oldp+99031,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_edge_inst));
    bufp->fullCData(oldp+99032,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_pc_lob),6);
    bufp->fullBit(oldp+99033,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_taken));
    bufp->fullBit(oldp+99034,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_xcpt_pf_if));
    bufp->fullBit(oldp+99035,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_xcpt_ae_if));
    bufp->fullBit(oldp+99036,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_xcpt_ma_if));
    bufp->fullBit(oldp+99037,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_bp_debug_if));
    bufp->fullBit(oldp+99038,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_bp_xcpt_if));
    bufp->fullCData(oldp+99039,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_debug_fsrc),2);
    bufp->fullCData(oldp+99040,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_debug_tsrc),2);
    bufp->fullIData(oldp+99041,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_inst),32);
    bufp->fullIData(oldp+99042,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_debug_inst),32);
    bufp->fullBit(oldp+99043,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_is_rvc));
    bufp->fullQData(oldp+99044,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_debug_pc),40);
    bufp->fullCData(oldp+99046,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_ctrl_br_type),4);
    bufp->fullCData(oldp+99047,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_ctrl_op1_sel),2);
    bufp->fullCData(oldp+99048,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_ctrl_op2_sel),3);
    bufp->fullCData(oldp+99049,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_ctrl_op_fcn),4);
    bufp->fullBit(oldp+99050,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_ctrl_fcn_dw));
    bufp->fullBit(oldp+99051,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_ctrl_is_load));
    bufp->fullBit(oldp+99052,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_ctrl_is_sta));
    bufp->fullBit(oldp+99053,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_ctrl_is_std));
    bufp->fullCData(oldp+99054,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_iw_state),2);
    bufp->fullBit(oldp+99055,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_iw_p1_poisoned));
    bufp->fullBit(oldp+99056,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_iw_p2_poisoned));
    bufp->fullBit(oldp+99057,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_is_sfb));
    bufp->fullCData(oldp+99058,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_ftq_idx),5);
    bufp->fullBit(oldp+99059,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_edge_inst));
    bufp->fullCData(oldp+99060,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_pc_lob),6);
    bufp->fullBit(oldp+99061,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_taken));
    bufp->fullBit(oldp+99062,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_xcpt_pf_if));
    bufp->fullBit(oldp+99063,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_xcpt_ae_if));
    bufp->fullBit(oldp+99064,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_xcpt_ma_if));
    bufp->fullBit(oldp+99065,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_bp_debug_if));
    bufp->fullBit(oldp+99066,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_bp_xcpt_if));
    bufp->fullCData(oldp+99067,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_debug_fsrc),2);
    bufp->fullCData(oldp+99068,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_debug_tsrc),2);
    bufp->fullIData(oldp+99069,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_inst),32);
    bufp->fullIData(oldp+99070,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_debug_inst),32);
    bufp->fullBit(oldp+99071,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_is_rvc));
    bufp->fullQData(oldp+99072,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_debug_pc),40);
    bufp->fullCData(oldp+99074,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_ctrl_br_type),4);
    bufp->fullCData(oldp+99075,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_ctrl_op1_sel),2);
    bufp->fullCData(oldp+99076,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_ctrl_op2_sel),3);
    bufp->fullCData(oldp+99077,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_ctrl_op_fcn),4);
    bufp->fullBit(oldp+99078,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_ctrl_fcn_dw));
    bufp->fullBit(oldp+99079,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_ctrl_is_load));
    bufp->fullBit(oldp+99080,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_ctrl_is_sta));
    bufp->fullBit(oldp+99081,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_ctrl_is_std));
    bufp->fullCData(oldp+99082,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_iw_state),2);
    bufp->fullBit(oldp+99083,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_iw_p1_poisoned));
    bufp->fullBit(oldp+99084,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_iw_p2_poisoned));
    bufp->fullBit(oldp+99085,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_is_sfb));
    bufp->fullCData(oldp+99086,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_ftq_idx),5);
    bufp->fullBit(oldp+99087,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_edge_inst));
    bufp->fullCData(oldp+99088,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_pc_lob),6);
    bufp->fullBit(oldp+99089,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_taken));
    bufp->fullBit(oldp+99090,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_xcpt_pf_if));
    bufp->fullBit(oldp+99091,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_xcpt_ae_if));
    bufp->fullBit(oldp+99092,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_xcpt_ma_if));
    bufp->fullBit(oldp+99093,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_bp_debug_if));
    bufp->fullBit(oldp+99094,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_bp_xcpt_if));
    bufp->fullCData(oldp+99095,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_debug_fsrc),2);
    bufp->fullCData(oldp+99096,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_debug_tsrc),2);
    bufp->fullIData(oldp+99097,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_inst),32);
    bufp->fullIData(oldp+99098,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_debug_inst),32);
    bufp->fullBit(oldp+99099,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_is_rvc));
    bufp->fullQData(oldp+99100,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_debug_pc),40);
    bufp->fullCData(oldp+99102,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_ctrl_br_type),4);
    bufp->fullCData(oldp+99103,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_ctrl_op1_sel),2);
    bufp->fullCData(oldp+99104,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_ctrl_op2_sel),3);
    bufp->fullCData(oldp+99105,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_ctrl_op_fcn),4);
    bufp->fullBit(oldp+99106,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_ctrl_fcn_dw));
    bufp->fullBit(oldp+99107,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_ctrl_is_load));
    bufp->fullBit(oldp+99108,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_ctrl_is_sta));
    bufp->fullBit(oldp+99109,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_ctrl_is_std));
    bufp->fullCData(oldp+99110,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_iw_state),2);
    bufp->fullBit(oldp+99111,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_iw_p1_poisoned));
    bufp->fullBit(oldp+99112,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_iw_p2_poisoned));
    bufp->fullBit(oldp+99113,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_is_sfb));
    bufp->fullCData(oldp+99114,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_ftq_idx),5);
    bufp->fullBit(oldp+99115,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_edge_inst));
    bufp->fullCData(oldp+99116,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_pc_lob),6);
    bufp->fullBit(oldp+99117,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_taken));
    bufp->fullBit(oldp+99118,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_xcpt_pf_if));
    bufp->fullBit(oldp+99119,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_xcpt_ae_if));
    bufp->fullBit(oldp+99120,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_xcpt_ma_if));
    bufp->fullBit(oldp+99121,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_bp_debug_if));
    bufp->fullBit(oldp+99122,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_bp_xcpt_if));
    bufp->fullCData(oldp+99123,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_debug_fsrc),2);
    bufp->fullCData(oldp+99124,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_debug_tsrc),2);
    bufp->fullIData(oldp+99125,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_inst),32);
    bufp->fullIData(oldp+99126,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_debug_inst),32);
    bufp->fullBit(oldp+99127,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_is_rvc));
    bufp->fullQData(oldp+99128,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_debug_pc),40);
    bufp->fullCData(oldp+99130,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_ctrl_br_type),4);
    bufp->fullCData(oldp+99131,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_ctrl_op1_sel),2);
    bufp->fullCData(oldp+99132,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_ctrl_op2_sel),3);
    bufp->fullCData(oldp+99133,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_ctrl_op_fcn),4);
    bufp->fullBit(oldp+99134,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_ctrl_fcn_dw));
    bufp->fullBit(oldp+99135,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_ctrl_is_load));
    bufp->fullBit(oldp+99136,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_ctrl_is_sta));
    bufp->fullBit(oldp+99137,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_ctrl_is_std));
    bufp->fullCData(oldp+99138,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_iw_state),2);
    bufp->fullBit(oldp+99139,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_iw_p1_poisoned));
    bufp->fullBit(oldp+99140,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_iw_p2_poisoned));
    bufp->fullBit(oldp+99141,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_is_sfb));
    bufp->fullCData(oldp+99142,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_ftq_idx),5);
    bufp->fullBit(oldp+99143,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_edge_inst));
    bufp->fullCData(oldp+99144,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_pc_lob),6);
    bufp->fullBit(oldp+99145,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_taken));
    bufp->fullBit(oldp+99146,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_xcpt_pf_if));
    bufp->fullBit(oldp+99147,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_xcpt_ae_if));
    bufp->fullBit(oldp+99148,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_xcpt_ma_if));
    bufp->fullBit(oldp+99149,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_bp_debug_if));
    bufp->fullBit(oldp+99150,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_bp_xcpt_if));
    bufp->fullCData(oldp+99151,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_debug_fsrc),2);
    bufp->fullCData(oldp+99152,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_debug_tsrc),2);
    bufp->fullIData(oldp+99153,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_inst),32);
    bufp->fullIData(oldp+99154,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_debug_inst),32);
    bufp->fullBit(oldp+99155,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_is_rvc));
    bufp->fullQData(oldp+99156,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_debug_pc),40);
    bufp->fullCData(oldp+99158,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_ctrl_br_type),4);
    bufp->fullCData(oldp+99159,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_ctrl_op1_sel),2);
    bufp->fullCData(oldp+99160,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_ctrl_op2_sel),3);
    bufp->fullCData(oldp+99161,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_ctrl_op_fcn),4);
    bufp->fullBit(oldp+99162,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_ctrl_fcn_dw));
    bufp->fullBit(oldp+99163,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_ctrl_is_load));
    bufp->fullBit(oldp+99164,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_ctrl_is_sta));
    bufp->fullBit(oldp+99165,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_ctrl_is_std));
    bufp->fullCData(oldp+99166,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_iw_state),2);
    bufp->fullBit(oldp+99167,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_iw_p1_poisoned));
    bufp->fullBit(oldp+99168,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_iw_p2_poisoned));
    bufp->fullBit(oldp+99169,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_is_sfb));
    bufp->fullCData(oldp+99170,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_ftq_idx),5);
    bufp->fullBit(oldp+99171,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_edge_inst));
    bufp->fullCData(oldp+99172,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_pc_lob),6);
    bufp->fullBit(oldp+99173,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_taken));
    bufp->fullBit(oldp+99174,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_xcpt_pf_if));
    bufp->fullBit(oldp+99175,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_xcpt_ae_if));
    bufp->fullBit(oldp+99176,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_xcpt_ma_if));
    bufp->fullBit(oldp+99177,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_bp_debug_if));
    bufp->fullBit(oldp+99178,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_bp_xcpt_if));
    bufp->fullCData(oldp+99179,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_debug_fsrc),2);
    bufp->fullCData(oldp+99180,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_debug_tsrc),2);
    bufp->fullIData(oldp+99181,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_inst),32);
    bufp->fullIData(oldp+99182,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_debug_inst),32);
    bufp->fullBit(oldp+99183,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_is_rvc));
    bufp->fullQData(oldp+99184,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_debug_pc),40);
    bufp->fullCData(oldp+99186,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_ctrl_br_type),4);
    bufp->fullCData(oldp+99187,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_ctrl_op1_sel),2);
    bufp->fullCData(oldp+99188,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_ctrl_op2_sel),3);
    bufp->fullCData(oldp+99189,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_ctrl_op_fcn),4);
    bufp->fullBit(oldp+99190,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_ctrl_fcn_dw));
    bufp->fullBit(oldp+99191,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_ctrl_is_load));
    bufp->fullBit(oldp+99192,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_ctrl_is_sta));
    bufp->fullBit(oldp+99193,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_ctrl_is_std));
    bufp->fullCData(oldp+99194,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_iw_state),2);
    bufp->fullBit(oldp+99195,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_iw_p1_poisoned));
    bufp->fullBit(oldp+99196,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_iw_p2_poisoned));
    bufp->fullBit(oldp+99197,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_is_sfb));
    bufp->fullCData(oldp+99198,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_ftq_idx),5);
    bufp->fullBit(oldp+99199,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_edge_inst));
    bufp->fullCData(oldp+99200,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_pc_lob),6);
    bufp->fullBit(oldp+99201,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_taken));
    bufp->fullBit(oldp+99202,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_xcpt_pf_if));
    bufp->fullBit(oldp+99203,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_xcpt_ae_if));
    bufp->fullBit(oldp+99204,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_xcpt_ma_if));
    bufp->fullBit(oldp+99205,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_bp_debug_if));
    bufp->fullBit(oldp+99206,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_bp_xcpt_if));
    bufp->fullCData(oldp+99207,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_debug_fsrc),2);
    bufp->fullCData(oldp+99208,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_debug_tsrc),2);
    bufp->fullIData(oldp+99209,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_inst),32);
    bufp->fullIData(oldp+99210,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_debug_inst),32);
    bufp->fullBit(oldp+99211,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_is_rvc));
    bufp->fullQData(oldp+99212,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_debug_pc),40);
    bufp->fullCData(oldp+99214,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_ctrl_br_type),4);
    bufp->fullCData(oldp+99215,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_ctrl_op1_sel),2);
    bufp->fullCData(oldp+99216,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_ctrl_op2_sel),3);
    bufp->fullCData(oldp+99217,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_ctrl_op_fcn),4);
    bufp->fullBit(oldp+99218,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_ctrl_fcn_dw));
    bufp->fullBit(oldp+99219,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_ctrl_is_load));
    bufp->fullBit(oldp+99220,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_ctrl_is_sta));
    bufp->fullBit(oldp+99221,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_ctrl_is_std));
    bufp->fullCData(oldp+99222,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_iw_state),2);
    bufp->fullBit(oldp+99223,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_iw_p1_poisoned));
    bufp->fullBit(oldp+99224,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_iw_p2_poisoned));
    bufp->fullBit(oldp+99225,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_is_sfb));
    bufp->fullCData(oldp+99226,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_ftq_idx),5);
    bufp->fullBit(oldp+99227,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_edge_inst));
    bufp->fullCData(oldp+99228,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_pc_lob),6);
    bufp->fullBit(oldp+99229,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_taken));
    bufp->fullBit(oldp+99230,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_xcpt_pf_if));
    bufp->fullBit(oldp+99231,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_xcpt_ae_if));
    bufp->fullBit(oldp+99232,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_xcpt_ma_if));
    bufp->fullBit(oldp+99233,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_bp_debug_if));
    bufp->fullBit(oldp+99234,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_bp_xcpt_if));
    bufp->fullCData(oldp+99235,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_debug_fsrc),2);
    bufp->fullCData(oldp+99236,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_debug_tsrc),2);
    bufp->fullIData(oldp+99237,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_inst),32);
    bufp->fullIData(oldp+99238,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_debug_inst),32);
    bufp->fullBit(oldp+99239,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_is_rvc));
    bufp->fullQData(oldp+99240,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_debug_pc),40);
    bufp->fullCData(oldp+99242,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_ctrl_br_type),4);
    bufp->fullCData(oldp+99243,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_ctrl_op1_sel),2);
    bufp->fullCData(oldp+99244,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_ctrl_op2_sel),3);
    bufp->fullCData(oldp+99245,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_ctrl_op_fcn),4);
    bufp->fullBit(oldp+99246,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_ctrl_fcn_dw));
    bufp->fullBit(oldp+99247,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_ctrl_is_load));
    bufp->fullBit(oldp+99248,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_ctrl_is_sta));
    bufp->fullBit(oldp+99249,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_ctrl_is_std));
    bufp->fullCData(oldp+99250,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_iw_state),2);
    bufp->fullBit(oldp+99251,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_iw_p1_poisoned));
    bufp->fullBit(oldp+99252,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_iw_p2_poisoned));
    bufp->fullBit(oldp+99253,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_is_sfb));
    bufp->fullCData(oldp+99254,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_ftq_idx),5);
    bufp->fullBit(oldp+99255,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_edge_inst));
    bufp->fullCData(oldp+99256,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_pc_lob),6);
    bufp->fullBit(oldp+99257,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_taken));
    bufp->fullBit(oldp+99258,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_xcpt_pf_if));
    bufp->fullBit(oldp+99259,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_xcpt_ae_if));
    bufp->fullBit(oldp+99260,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_xcpt_ma_if));
    bufp->fullBit(oldp+99261,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_bp_debug_if));
    bufp->fullBit(oldp+99262,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_bp_xcpt_if));
    bufp->fullCData(oldp+99263,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_debug_fsrc),2);
    bufp->fullCData(oldp+99264,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_debug_tsrc),2);
    bufp->fullIData(oldp+99265,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_inst),32);
    bufp->fullIData(oldp+99266,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_debug_inst),32);
    bufp->fullBit(oldp+99267,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_is_rvc));
    bufp->fullQData(oldp+99268,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_debug_pc),40);
    bufp->fullCData(oldp+99270,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_ctrl_br_type),4);
    bufp->fullCData(oldp+99271,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_ctrl_op1_sel),2);
    bufp->fullCData(oldp+99272,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_ctrl_op2_sel),3);
    bufp->fullCData(oldp+99273,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_ctrl_op_fcn),4);
    bufp->fullBit(oldp+99274,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_ctrl_fcn_dw));
    bufp->fullBit(oldp+99275,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_ctrl_is_load));
    bufp->fullBit(oldp+99276,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_ctrl_is_sta));
    bufp->fullBit(oldp+99277,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_ctrl_is_std));
    bufp->fullCData(oldp+99278,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_iw_state),2);
    bufp->fullBit(oldp+99279,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_iw_p1_poisoned));
    bufp->fullBit(oldp+99280,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_iw_p2_poisoned));
    bufp->fullBit(oldp+99281,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_is_sfb));
    bufp->fullCData(oldp+99282,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_ftq_idx),5);
    bufp->fullBit(oldp+99283,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_edge_inst));
    bufp->fullCData(oldp+99284,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_pc_lob),6);
    bufp->fullBit(oldp+99285,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_taken));
    bufp->fullBit(oldp+99286,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_xcpt_pf_if));
    bufp->fullBit(oldp+99287,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_xcpt_ae_if));
    bufp->fullBit(oldp+99288,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_xcpt_ma_if));
    bufp->fullBit(oldp+99289,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_bp_debug_if));
    bufp->fullBit(oldp+99290,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_bp_xcpt_if));
    bufp->fullCData(oldp+99291,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_debug_fsrc),2);
    bufp->fullCData(oldp+99292,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_debug_tsrc),2);
    bufp->fullIData(oldp+99293,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_inst),32);
    bufp->fullIData(oldp+99294,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_debug_inst),32);
    bufp->fullBit(oldp+99295,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_is_rvc));
    bufp->fullQData(oldp+99296,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_debug_pc),40);
    bufp->fullCData(oldp+99298,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_ctrl_br_type),4);
    bufp->fullCData(oldp+99299,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_ctrl_op1_sel),2);
    bufp->fullCData(oldp+99300,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_ctrl_op2_sel),3);
    bufp->fullCData(oldp+99301,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_ctrl_op_fcn),4);
    bufp->fullBit(oldp+99302,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_ctrl_fcn_dw));
    bufp->fullBit(oldp+99303,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_ctrl_is_load));
    bufp->fullBit(oldp+99304,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_ctrl_is_sta));
    bufp->fullBit(oldp+99305,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_ctrl_is_std));
    bufp->fullCData(oldp+99306,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_iw_state),2);
    bufp->fullBit(oldp+99307,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_iw_p1_poisoned));
    bufp->fullBit(oldp+99308,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_iw_p2_poisoned));
    bufp->fullBit(oldp+99309,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_is_sfb));
    bufp->fullCData(oldp+99310,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_ftq_idx),5);
    bufp->fullBit(oldp+99311,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_edge_inst));
    bufp->fullCData(oldp+99312,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_pc_lob),6);
    bufp->fullBit(oldp+99313,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_taken));
    bufp->fullBit(oldp+99314,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_xcpt_pf_if));
    bufp->fullBit(oldp+99315,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_xcpt_ae_if));
    bufp->fullBit(oldp+99316,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_xcpt_ma_if));
    bufp->fullBit(oldp+99317,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_bp_debug_if));
    bufp->fullBit(oldp+99318,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_bp_xcpt_if));
    bufp->fullCData(oldp+99319,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_debug_fsrc),2);
    bufp->fullCData(oldp+99320,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_debug_tsrc),2);
    bufp->fullIData(oldp+99321,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_inst),32);
    bufp->fullIData(oldp+99322,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_debug_inst),32);
    bufp->fullBit(oldp+99323,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_is_rvc));
    bufp->fullQData(oldp+99324,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_debug_pc),40);
    bufp->fullCData(oldp+99326,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_ctrl_br_type),4);
    bufp->fullCData(oldp+99327,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_ctrl_op1_sel),2);
    bufp->fullCData(oldp+99328,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_ctrl_op2_sel),3);
    bufp->fullCData(oldp+99329,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_ctrl_op_fcn),4);
    bufp->fullBit(oldp+99330,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_ctrl_fcn_dw));
    bufp->fullBit(oldp+99331,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_ctrl_is_load));
    bufp->fullBit(oldp+99332,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_ctrl_is_sta));
    bufp->fullBit(oldp+99333,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_ctrl_is_std));
    bufp->fullCData(oldp+99334,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_iw_state),2);
    bufp->fullBit(oldp+99335,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_iw_p1_poisoned));
    bufp->fullBit(oldp+99336,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_iw_p2_poisoned));
    bufp->fullBit(oldp+99337,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_is_sfb));
    bufp->fullCData(oldp+99338,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_ftq_idx),5);
    bufp->fullBit(oldp+99339,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_edge_inst));
    bufp->fullCData(oldp+99340,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_pc_lob),6);
    bufp->fullBit(oldp+99341,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_taken));
    bufp->fullBit(oldp+99342,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_xcpt_pf_if));
    bufp->fullBit(oldp+99343,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_xcpt_ae_if));
    bufp->fullBit(oldp+99344,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_xcpt_ma_if));
    bufp->fullBit(oldp+99345,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_bp_debug_if));
    bufp->fullBit(oldp+99346,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_bp_xcpt_if));
    bufp->fullCData(oldp+99347,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_debug_fsrc),2);
    bufp->fullCData(oldp+99348,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_debug_tsrc),2);
    bufp->fullIData(oldp+99349,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_inst),32);
    bufp->fullIData(oldp+99350,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_debug_inst),32);
    bufp->fullBit(oldp+99351,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_is_rvc));
    bufp->fullQData(oldp+99352,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_debug_pc),40);
    bufp->fullCData(oldp+99354,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_ctrl_br_type),4);
    bufp->fullCData(oldp+99355,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_ctrl_op1_sel),2);
    bufp->fullCData(oldp+99356,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_ctrl_op2_sel),3);
    bufp->fullCData(oldp+99357,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_ctrl_op_fcn),4);
    bufp->fullBit(oldp+99358,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_ctrl_fcn_dw));
    bufp->fullBit(oldp+99359,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_ctrl_is_load));
    bufp->fullBit(oldp+99360,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_ctrl_is_sta));
    bufp->fullBit(oldp+99361,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_ctrl_is_std));
    bufp->fullCData(oldp+99362,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_iw_state),2);
    bufp->fullBit(oldp+99363,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_iw_p1_poisoned));
    bufp->fullBit(oldp+99364,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_iw_p2_poisoned));
    bufp->fullBit(oldp+99365,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_is_sfb));
    bufp->fullCData(oldp+99366,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_ftq_idx),5);
    bufp->fullBit(oldp+99367,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_edge_inst));
    bufp->fullCData(oldp+99368,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_pc_lob),6);
    bufp->fullBit(oldp+99369,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_taken));
    bufp->fullBit(oldp+99370,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_xcpt_pf_if));
    bufp->fullBit(oldp+99371,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_xcpt_ae_if));
    bufp->fullBit(oldp+99372,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_xcpt_ma_if));
    bufp->fullBit(oldp+99373,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_bp_debug_if));
    bufp->fullBit(oldp+99374,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_bp_xcpt_if));
    bufp->fullCData(oldp+99375,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_debug_fsrc),2);
    bufp->fullCData(oldp+99376,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_debug_tsrc),2);
    bufp->fullIData(oldp+99377,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_inst),32);
    bufp->fullIData(oldp+99378,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_debug_inst),32);
    bufp->fullBit(oldp+99379,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_is_rvc));
    bufp->fullQData(oldp+99380,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_debug_pc),40);
    bufp->fullCData(oldp+99382,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_ctrl_br_type),4);
    bufp->fullCData(oldp+99383,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_ctrl_op1_sel),2);
    bufp->fullCData(oldp+99384,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_ctrl_op2_sel),3);
    bufp->fullCData(oldp+99385,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_ctrl_op_fcn),4);
    bufp->fullBit(oldp+99386,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_ctrl_fcn_dw));
    bufp->fullBit(oldp+99387,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_ctrl_is_load));
    bufp->fullBit(oldp+99388,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_ctrl_is_sta));
    bufp->fullBit(oldp+99389,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_ctrl_is_std));
    bufp->fullCData(oldp+99390,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_iw_state),2);
    bufp->fullBit(oldp+99391,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_iw_p1_poisoned));
    bufp->fullBit(oldp+99392,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_iw_p2_poisoned));
    bufp->fullBit(oldp+99393,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_is_sfb));
    bufp->fullCData(oldp+99394,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_ftq_idx),5);
    bufp->fullBit(oldp+99395,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_edge_inst));
    bufp->fullCData(oldp+99396,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_pc_lob),6);
    bufp->fullBit(oldp+99397,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_taken));
    bufp->fullBit(oldp+99398,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_xcpt_pf_if));
    bufp->fullBit(oldp+99399,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_xcpt_ae_if));
    bufp->fullBit(oldp+99400,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_xcpt_ma_if));
    bufp->fullBit(oldp+99401,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_bp_debug_if));
    bufp->fullBit(oldp+99402,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_bp_xcpt_if));
    bufp->fullCData(oldp+99403,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_debug_fsrc),2);
    bufp->fullCData(oldp+99404,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_debug_tsrc),2);
    bufp->fullIData(oldp+99405,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_inst),32);
    bufp->fullIData(oldp+99406,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_debug_inst),32);
    bufp->fullBit(oldp+99407,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_is_rvc));
    bufp->fullQData(oldp+99408,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_debug_pc),40);
    bufp->fullCData(oldp+99410,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_ctrl_br_type),4);
    bufp->fullCData(oldp+99411,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_ctrl_op1_sel),2);
    bufp->fullCData(oldp+99412,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_ctrl_op2_sel),3);
    bufp->fullCData(oldp+99413,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_ctrl_op_fcn),4);
    bufp->fullBit(oldp+99414,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_ctrl_fcn_dw));
    bufp->fullBit(oldp+99415,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_ctrl_is_load));
    bufp->fullBit(oldp+99416,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_ctrl_is_sta));
    bufp->fullBit(oldp+99417,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_ctrl_is_std));
    bufp->fullCData(oldp+99418,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_iw_state),2);
    bufp->fullBit(oldp+99419,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_iw_p1_poisoned));
    bufp->fullBit(oldp+99420,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_iw_p2_poisoned));
    bufp->fullBit(oldp+99421,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_is_sfb));
    bufp->fullCData(oldp+99422,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_ftq_idx),5);
    bufp->fullBit(oldp+99423,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_edge_inst));
    bufp->fullCData(oldp+99424,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_pc_lob),6);
    bufp->fullBit(oldp+99425,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_taken));
    bufp->fullBit(oldp+99426,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_xcpt_pf_if));
    bufp->fullBit(oldp+99427,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_xcpt_ae_if));
    bufp->fullBit(oldp+99428,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_xcpt_ma_if));
    bufp->fullBit(oldp+99429,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_bp_debug_if));
    bufp->fullBit(oldp+99430,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_bp_xcpt_if));
    bufp->fullCData(oldp+99431,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_debug_fsrc),2);
    bufp->fullCData(oldp+99432,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_debug_tsrc),2);
    bufp->fullIData(oldp+99433,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_inst),32);
    bufp->fullIData(oldp+99434,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_debug_inst),32);
    bufp->fullBit(oldp+99435,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_is_rvc));
    bufp->fullQData(oldp+99436,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_debug_pc),40);
    bufp->fullCData(oldp+99438,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_ctrl_br_type),4);
    bufp->fullCData(oldp+99439,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_ctrl_op1_sel),2);
    bufp->fullCData(oldp+99440,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_ctrl_op2_sel),3);
    bufp->fullCData(oldp+99441,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_ctrl_op_fcn),4);
    bufp->fullBit(oldp+99442,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_ctrl_fcn_dw));
    bufp->fullBit(oldp+99443,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_ctrl_is_load));
    bufp->fullBit(oldp+99444,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_ctrl_is_sta));
    bufp->fullBit(oldp+99445,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_ctrl_is_std));
    bufp->fullCData(oldp+99446,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_iw_state),2);
    bufp->fullBit(oldp+99447,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_iw_p1_poisoned));
    bufp->fullBit(oldp+99448,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_iw_p2_poisoned));
    bufp->fullBit(oldp+99449,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_is_sfb));
    bufp->fullCData(oldp+99450,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_ftq_idx),5);
    bufp->fullBit(oldp+99451,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_edge_inst));
    bufp->fullCData(oldp+99452,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_pc_lob),6);
    bufp->fullBit(oldp+99453,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_taken));
    bufp->fullBit(oldp+99454,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_xcpt_pf_if));
    bufp->fullBit(oldp+99455,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_xcpt_ae_if));
    bufp->fullBit(oldp+99456,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_xcpt_ma_if));
    bufp->fullBit(oldp+99457,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_bp_debug_if));
    bufp->fullBit(oldp+99458,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_bp_xcpt_if));
    bufp->fullCData(oldp+99459,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_debug_fsrc),2);
    bufp->fullCData(oldp+99460,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_debug_tsrc),2);
    bufp->fullIData(oldp+99461,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_inst),32);
    bufp->fullIData(oldp+99462,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_debug_inst),32);
    bufp->fullBit(oldp+99463,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_is_rvc));
    bufp->fullQData(oldp+99464,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_debug_pc),40);
    bufp->fullCData(oldp+99466,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_ctrl_br_type),4);
    bufp->fullCData(oldp+99467,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_ctrl_op1_sel),2);
    bufp->fullCData(oldp+99468,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_ctrl_op2_sel),3);
    bufp->fullCData(oldp+99469,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_ctrl_op_fcn),4);
    bufp->fullBit(oldp+99470,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_ctrl_fcn_dw));
    bufp->fullBit(oldp+99471,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_ctrl_is_load));
    bufp->fullBit(oldp+99472,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_ctrl_is_sta));
    bufp->fullBit(oldp+99473,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_ctrl_is_std));
    bufp->fullCData(oldp+99474,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_iw_state),2);
    bufp->fullBit(oldp+99475,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_iw_p1_poisoned));
    bufp->fullBit(oldp+99476,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_iw_p2_poisoned));
    bufp->fullBit(oldp+99477,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_is_sfb));
    bufp->fullCData(oldp+99478,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_ftq_idx),5);
    bufp->fullBit(oldp+99479,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_edge_inst));
    bufp->fullCData(oldp+99480,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_pc_lob),6);
    bufp->fullBit(oldp+99481,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_taken));
    bufp->fullBit(oldp+99482,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_xcpt_pf_if));
    bufp->fullBit(oldp+99483,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_xcpt_ae_if));
    bufp->fullBit(oldp+99484,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_xcpt_ma_if));
    bufp->fullBit(oldp+99485,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_bp_debug_if));
    bufp->fullBit(oldp+99486,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_bp_xcpt_if));
    bufp->fullCData(oldp+99487,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_debug_fsrc),2);
    bufp->fullCData(oldp+99488,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_debug_tsrc),2);
    bufp->fullIData(oldp+99489,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_inst),32);
    bufp->fullIData(oldp+99490,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_debug_inst),32);
    bufp->fullBit(oldp+99491,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_is_rvc));
    bufp->fullQData(oldp+99492,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_debug_pc),40);
    bufp->fullCData(oldp+99494,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_ctrl_br_type),4);
    bufp->fullCData(oldp+99495,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_ctrl_op1_sel),2);
    bufp->fullCData(oldp+99496,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_ctrl_op2_sel),3);
    bufp->fullCData(oldp+99497,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_ctrl_op_fcn),4);
    bufp->fullBit(oldp+99498,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_ctrl_fcn_dw));
    bufp->fullBit(oldp+99499,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_ctrl_is_load));
    bufp->fullBit(oldp+99500,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_ctrl_is_sta));
    bufp->fullBit(oldp+99501,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_ctrl_is_std));
    bufp->fullCData(oldp+99502,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_iw_state),2);
    bufp->fullBit(oldp+99503,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_iw_p1_poisoned));
    bufp->fullBit(oldp+99504,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_iw_p2_poisoned));
    bufp->fullBit(oldp+99505,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_is_sfb));
    bufp->fullCData(oldp+99506,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_ftq_idx),5);
    bufp->fullBit(oldp+99507,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_edge_inst));
    bufp->fullCData(oldp+99508,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_pc_lob),6);
    bufp->fullBit(oldp+99509,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_taken));
    bufp->fullBit(oldp+99510,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_xcpt_pf_if));
    bufp->fullBit(oldp+99511,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_xcpt_ae_if));
    bufp->fullBit(oldp+99512,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_xcpt_ma_if));
    bufp->fullBit(oldp+99513,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_bp_debug_if));
    bufp->fullBit(oldp+99514,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_bp_xcpt_if));
    bufp->fullCData(oldp+99515,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_debug_fsrc),2);
    bufp->fullCData(oldp+99516,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_debug_tsrc),2);
    bufp->fullIData(oldp+99517,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_inst),32);
    bufp->fullIData(oldp+99518,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_debug_inst),32);
    bufp->fullBit(oldp+99519,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_is_rvc));
    bufp->fullQData(oldp+99520,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_debug_pc),40);
    bufp->fullCData(oldp+99522,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_ctrl_br_type),4);
    bufp->fullCData(oldp+99523,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_ctrl_op1_sel),2);
    bufp->fullCData(oldp+99524,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_ctrl_op2_sel),3);
    bufp->fullCData(oldp+99525,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_ctrl_op_fcn),4);
    bufp->fullBit(oldp+99526,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_ctrl_fcn_dw));
    bufp->fullBit(oldp+99527,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_ctrl_is_load));
    bufp->fullBit(oldp+99528,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_ctrl_is_sta));
    bufp->fullBit(oldp+99529,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_ctrl_is_std));
    bufp->fullCData(oldp+99530,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_iw_state),2);
    bufp->fullBit(oldp+99531,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_iw_p1_poisoned));
    bufp->fullBit(oldp+99532,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_iw_p2_poisoned));
    bufp->fullBit(oldp+99533,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_is_sfb));
    bufp->fullCData(oldp+99534,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_ftq_idx),5);
    bufp->fullBit(oldp+99535,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_edge_inst));
    bufp->fullCData(oldp+99536,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_pc_lob),6);
    bufp->fullBit(oldp+99537,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_taken));
    bufp->fullBit(oldp+99538,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_xcpt_pf_if));
    bufp->fullBit(oldp+99539,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_xcpt_ae_if));
    bufp->fullBit(oldp+99540,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_xcpt_ma_if));
    bufp->fullBit(oldp+99541,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_bp_debug_if));
    bufp->fullBit(oldp+99542,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_bp_xcpt_if));
    bufp->fullCData(oldp+99543,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_debug_fsrc),2);
    bufp->fullCData(oldp+99544,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_debug_tsrc),2);
    bufp->fullIData(oldp+99545,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_inst),32);
    bufp->fullIData(oldp+99546,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_debug_inst),32);
    bufp->fullBit(oldp+99547,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_is_rvc));
    bufp->fullQData(oldp+99548,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_debug_pc),40);
    bufp->fullCData(oldp+99550,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_ctrl_br_type),4);
    bufp->fullCData(oldp+99551,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_ctrl_op1_sel),2);
    bufp->fullCData(oldp+99552,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_ctrl_op2_sel),3);
    bufp->fullCData(oldp+99553,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_ctrl_op_fcn),4);
    bufp->fullBit(oldp+99554,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_ctrl_fcn_dw));
    bufp->fullBit(oldp+99555,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_ctrl_is_load));
    bufp->fullBit(oldp+99556,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_ctrl_is_sta));
    bufp->fullBit(oldp+99557,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_ctrl_is_std));
    bufp->fullCData(oldp+99558,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_iw_state),2);
    bufp->fullBit(oldp+99559,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_iw_p1_poisoned));
    bufp->fullBit(oldp+99560,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_iw_p2_poisoned));
    bufp->fullBit(oldp+99561,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_is_sfb));
    bufp->fullCData(oldp+99562,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_ftq_idx),5);
    bufp->fullBit(oldp+99563,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_edge_inst));
    bufp->fullCData(oldp+99564,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_pc_lob),6);
    bufp->fullBit(oldp+99565,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_taken));
    bufp->fullBit(oldp+99566,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_xcpt_pf_if));
    bufp->fullBit(oldp+99567,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_xcpt_ae_if));
    bufp->fullBit(oldp+99568,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_xcpt_ma_if));
    bufp->fullBit(oldp+99569,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_bp_debug_if));
    bufp->fullBit(oldp+99570,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_bp_xcpt_if));
    bufp->fullCData(oldp+99571,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_debug_fsrc),2);
    bufp->fullCData(oldp+99572,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_debug_tsrc),2);
    bufp->fullCData(oldp+99573,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__head),8);
    bufp->fullIData(oldp+99574,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__tail),24);
    bufp->fullBit(oldp+99575,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__maybe_full));
    bufp->fullIData(oldp+99576,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__tail_collisions),24);
    bufp->fullCData(oldp+99577,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__slot_will_hit_tail),3);
    bufp->fullBit(oldp+99578,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__in_mask_0));
    bufp->fullBit(oldp+99579,((3U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                            [0U][2U] 
                                            >> 0x12U)))));
    bufp->fullBit(oldp+99580,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__in_uops_0_taken));
    bufp->fullQData(oldp+99581,((0xffffffffffULL & 
                                 (2ULL + (~ (7ULL | 
                                             (~ (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                                  [0U][1U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                                   [0U][0U]))))))))),40);
    bufp->fullBit(oldp+99583,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__in_mask_1));
    bufp->fullBit(oldp+99584,((3U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                            [0U][3U] 
                                            >> 0x12U)))));
    bufp->fullBit(oldp+99585,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__in_uops_1_taken));
    bufp->fullQData(oldp+99586,((0xffffffffffULL & 
                                 (4ULL + (~ (7ULL | 
                                             (~ (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                                  [0U][1U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                                   [0U][0U]))))))))),40);
    bufp->fullBit(oldp+99588,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__in_mask_2));
    bufp->fullBit(oldp+99589,((3U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                            [0U][4U] 
                                            >> 0x12U)))));
    bufp->fullBit(oldp+99590,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__in_uops_2_taken));
    bufp->fullQData(oldp+99591,((0xffffffffffULL & 
                                 (6ULL + (~ (7ULL | 
                                             (~ (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                                  [0U][1U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                                   [0U][0U]))))))))),40);
    bufp->fullBit(oldp+99593,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__in_mask_3));
    bufp->fullBit(oldp+99594,((3U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                            [0U][5U] 
                                            >> 0x12U)))));
    bufp->fullBit(oldp+99595,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__in_uops_3_taken));
    bufp->fullQData(oldp+99596,((0xffffffffffULL & 
                                 (8ULL + (~ (7ULL | 
                                             (~ (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                                  [0U][1U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                                   [0U][0U]))))))))),40);
    bufp->fullBit(oldp+99598,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__in_mask_4));
    bufp->fullBit(oldp+99599,((3U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                            [0U][6U] 
                                            >> 0x12U)))));
    bufp->fullBit(oldp+99600,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__in_uops_4_taken));
    bufp->fullQData(oldp+99601,((0xffffffffffULL & 
                                 (0xaULL + (~ (7ULL 
                                               | (~ 
                                                  (((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                                    [0U][1U])) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                                     [0U][0U]))))))))),40);
    bufp->fullBit(oldp+99603,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__in_mask_5));
    bufp->fullBit(oldp+99604,((3U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                            [0U][7U] 
                                            >> 0x12U)))));
    bufp->fullBit(oldp+99605,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__in_uops_5_taken));
    bufp->fullQData(oldp+99606,((0xffffffffffULL & 
                                 (0xcULL + (~ (7ULL 
                                               | (~ 
                                                  (((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                                    [0U][1U])) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                                     [0U][0U]))))))))),40);
    bufp->fullBit(oldp+99608,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__in_mask_6));
    bufp->fullBit(oldp+99609,((3U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                            [0U][8U] 
                                            >> 0x12U)))));
    bufp->fullBit(oldp+99610,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__in_uops_6_taken));
    bufp->fullQData(oldp+99611,((0xffffffffffULL & 
                                 (0xeULL + (~ (7ULL 
                                               | (~ 
                                                  (((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                                    [0U][1U])) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                                     [0U][0U]))))))))),40);
    bufp->fullBit(oldp+99613,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__in_mask_7));
    bufp->fullBit(oldp+99614,((3U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                            [0U][9U] 
                                            >> 0x12U)))));
    bufp->fullBit(oldp+99615,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__in_uops_7_taken));
    bufp->fullIData(oldp+99616,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_1),24);
    bufp->fullIData(oldp+99617,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_2),24);
    bufp->fullIData(oldp+99618,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_3),24);
    bufp->fullIData(oldp+99619,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_4),24);
    bufp->fullIData(oldp+99620,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_5),24);
    bufp->fullIData(oldp+99621,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_6),24);
    bufp->fullIData(oldp+99622,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7),24);
    bufp->fullBit(oldp+99623,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__maybe_full) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___do_enq_T_1))) 
                               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_delay)))));
    bufp->fullBit(oldp+99624,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__io_enq_ready_REG));
    bufp->fullBit(oldp+99625,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__io_ras_update_REG));
    bufp->fullCData(oldp+99626,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__io_ras_update_idx_REG),5);
    bufp->fullQData(oldp+99627,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__io_ras_update_pc_REG),40);
    bufp->fullCData(oldp+99629,((0x1fU & ((0x2000000U 
                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                           [0U][0x1cU])
                                           ? ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                               [0U][0x1dU] 
                                               << 4U) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                 [0U][0x1cU] 
                                                 >> 0x1cU))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___new_ghist_new_history_ras_idx_T)
                                               ? ((IData)(1U) 
                                                  + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_ghist_ras_idx))
                                               : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___new_ghist_new_history_ras_idx_T_4)
                                                   ? 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_ghist_ras_idx) 
                                                   - (IData)(1U))
                                                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_ghist_ras_idx)))))),5);
    bufp->fullBit(oldp+99630,((1U & ((0x2000000U & 
                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                      [0U][0x1cU]) ? 
                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                      [0U][0x1cU] >> 0x1bU)
                                      : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__new_ghist_ignore_second_bank)
                                          ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___new_ghist_new_history_new_saw_branch_taken_T)
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___new_ghist_new_history_new_saw_branch_taken_T_4))))));
    bufp->fullBit(oldp+99631,((1U & ((0x2000000U & 
                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                      [0U][0x1cU]) ? 
                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                      [0U][0x1cU] >> 0x1aU)
                                      : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__new_ghist_ignore_second_bank)
                                          ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__new_ghist_first_bank_saw_not_taken)
                                          : (0U != 
                                             (0xfU 
                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__new_ghist_not_taken_branches) 
                                                 >> 4U))))))));
    bufp->fullQData(oldp+99632,(((0x2000000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                  [0U][0x1cU]) ? (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                                   [0U][0x1cU])) 
                                                   << 0x27U) 
                                                  | (((QData)((IData)(
                                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                                      [0U][0x1bU])) 
                                                      << 7U) 
                                                     | ((QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                                                        [0U][0x1aU])) 
                                                        >> 0x19U)))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__new_ghist_ignore_second_bank)
                                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_6
                                      : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN_8))),64);
    bufp->fullCData(oldp+99634,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_ptr),5);
    bufp->fullCData(oldp+99635,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__deq_ptr),5);
    bufp->fullQData(oldp+99636,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_0),40);
    bufp->fullQData(oldp+99638,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_1),40);
    bufp->fullQData(oldp+99640,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_2),40);
    bufp->fullQData(oldp+99642,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_3),40);
    bufp->fullQData(oldp+99644,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_4),40);
    bufp->fullQData(oldp+99646,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_5),40);
    bufp->fullQData(oldp+99648,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_6),40);
    bufp->fullQData(oldp+99650,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_7),40);
    bufp->fullQData(oldp+99652,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_8),40);
    bufp->fullQData(oldp+99654,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_9),40);
    bufp->fullQData(oldp+99656,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_10),40);
    bufp->fullQData(oldp+99658,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_11),40);
    bufp->fullQData(oldp+99660,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_12),40);
    bufp->fullQData(oldp+99662,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_13),40);
    bufp->fullQData(oldp+99664,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_14),40);
    bufp->fullQData(oldp+99666,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_15),40);
    bufp->fullQData(oldp+99668,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_16),40);
    bufp->fullQData(oldp+99670,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_17),40);
    bufp->fullQData(oldp+99672,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_18),40);
    bufp->fullQData(oldp+99674,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_19),40);
    bufp->fullQData(oldp+99676,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_20),40);
    bufp->fullQData(oldp+99678,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_21),40);
    bufp->fullQData(oldp+99680,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_22),40);
    bufp->fullQData(oldp+99682,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_23),40);
    bufp->fullQData(oldp+99684,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_24),40);
    bufp->fullQData(oldp+99686,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_25),40);
    bufp->fullQData(oldp+99688,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_26),40);
    bufp->fullQData(oldp+99690,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_27),40);
    bufp->fullQData(oldp+99692,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_28),40);
    bufp->fullQData(oldp+99694,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_29),40);
    bufp->fullQData(oldp+99696,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_30),40);
    bufp->fullQData(oldp+99698,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__pcs_31),40);
    bufp->fullBit(oldp+99700,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_0_cfi_idx_valid));
    bufp->fullCData(oldp+99701,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_0_cfi_idx_bits),3);
    bufp->fullBit(oldp+99702,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_0_cfi_taken));
    bufp->fullBit(oldp+99703,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_0_cfi_mispredicted));
    bufp->fullCData(oldp+99704,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_0_cfi_type),3);
    bufp->fullCData(oldp+99705,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_0_br_mask),8);
    bufp->fullBit(oldp+99706,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_0_cfi_is_call));
    bufp->fullBit(oldp+99707,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_0_cfi_is_ret));
    bufp->fullQData(oldp+99708,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_0_ras_top),40);
    bufp->fullCData(oldp+99710,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_0_ras_idx),5);
    bufp->fullBit(oldp+99711,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_0_start_bank));
    bufp->fullBit(oldp+99712,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_1_cfi_idx_valid));
    bufp->fullCData(oldp+99713,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_1_cfi_idx_bits),3);
    bufp->fullBit(oldp+99714,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_1_cfi_taken));
    bufp->fullBit(oldp+99715,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_1_cfi_mispredicted));
    bufp->fullCData(oldp+99716,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_1_cfi_type),3);
    bufp->fullCData(oldp+99717,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_1_br_mask),8);
    bufp->fullBit(oldp+99718,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_1_cfi_is_call));
    bufp->fullBit(oldp+99719,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_1_cfi_is_ret));
    bufp->fullQData(oldp+99720,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_1_ras_top),40);
    bufp->fullCData(oldp+99722,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_1_ras_idx),5);
    bufp->fullBit(oldp+99723,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_1_start_bank));
    bufp->fullBit(oldp+99724,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_2_cfi_idx_valid));
    bufp->fullCData(oldp+99725,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_2_cfi_idx_bits),3);
    bufp->fullBit(oldp+99726,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_2_cfi_taken));
    bufp->fullBit(oldp+99727,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_2_cfi_mispredicted));
    bufp->fullCData(oldp+99728,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_2_cfi_type),3);
    bufp->fullCData(oldp+99729,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_2_br_mask),8);
    bufp->fullBit(oldp+99730,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_2_cfi_is_call));
    bufp->fullBit(oldp+99731,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_2_cfi_is_ret));
    bufp->fullQData(oldp+99732,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_2_ras_top),40);
    bufp->fullCData(oldp+99734,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_2_ras_idx),5);
    bufp->fullBit(oldp+99735,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_2_start_bank));
    bufp->fullBit(oldp+99736,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_3_cfi_idx_valid));
    bufp->fullCData(oldp+99737,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_3_cfi_idx_bits),3);
    bufp->fullBit(oldp+99738,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_3_cfi_taken));
    bufp->fullBit(oldp+99739,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_3_cfi_mispredicted));
    bufp->fullCData(oldp+99740,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_3_cfi_type),3);
    bufp->fullCData(oldp+99741,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_3_br_mask),8);
    bufp->fullBit(oldp+99742,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_3_cfi_is_call));
    bufp->fullBit(oldp+99743,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_3_cfi_is_ret));
    bufp->fullQData(oldp+99744,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_3_ras_top),40);
    bufp->fullCData(oldp+99746,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_3_ras_idx),5);
    bufp->fullBit(oldp+99747,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_3_start_bank));
    bufp->fullBit(oldp+99748,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_4_cfi_idx_valid));
    bufp->fullCData(oldp+99749,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_4_cfi_idx_bits),3);
    bufp->fullBit(oldp+99750,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_4_cfi_taken));
    bufp->fullBit(oldp+99751,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_4_cfi_mispredicted));
    bufp->fullCData(oldp+99752,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_4_cfi_type),3);
    bufp->fullCData(oldp+99753,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_4_br_mask),8);
    bufp->fullBit(oldp+99754,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_4_cfi_is_call));
    bufp->fullBit(oldp+99755,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_4_cfi_is_ret));
    bufp->fullQData(oldp+99756,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_4_ras_top),40);
    bufp->fullCData(oldp+99758,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_4_ras_idx),5);
    bufp->fullBit(oldp+99759,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_4_start_bank));
    bufp->fullBit(oldp+99760,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_5_cfi_idx_valid));
    bufp->fullCData(oldp+99761,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_5_cfi_idx_bits),3);
    bufp->fullBit(oldp+99762,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_5_cfi_taken));
    bufp->fullBit(oldp+99763,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_5_cfi_mispredicted));
    bufp->fullCData(oldp+99764,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_5_cfi_type),3);
    bufp->fullCData(oldp+99765,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_5_br_mask),8);
    bufp->fullBit(oldp+99766,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_5_cfi_is_call));
    bufp->fullBit(oldp+99767,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_5_cfi_is_ret));
    bufp->fullQData(oldp+99768,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_5_ras_top),40);
    bufp->fullCData(oldp+99770,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_5_ras_idx),5);
    bufp->fullBit(oldp+99771,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_5_start_bank));
    bufp->fullBit(oldp+99772,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_6_cfi_idx_valid));
    bufp->fullCData(oldp+99773,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_6_cfi_idx_bits),3);
    bufp->fullBit(oldp+99774,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_6_cfi_taken));
    bufp->fullBit(oldp+99775,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_6_cfi_mispredicted));
    bufp->fullCData(oldp+99776,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_6_cfi_type),3);
    bufp->fullCData(oldp+99777,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_6_br_mask),8);
    bufp->fullBit(oldp+99778,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_6_cfi_is_call));
    bufp->fullBit(oldp+99779,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_6_cfi_is_ret));
    bufp->fullQData(oldp+99780,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_6_ras_top),40);
    bufp->fullCData(oldp+99782,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_6_ras_idx),5);
    bufp->fullBit(oldp+99783,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_6_start_bank));
    bufp->fullBit(oldp+99784,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_7_cfi_idx_valid));
    bufp->fullCData(oldp+99785,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_7_cfi_idx_bits),3);
    bufp->fullBit(oldp+99786,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_7_cfi_taken));
    bufp->fullBit(oldp+99787,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_7_cfi_mispredicted));
    bufp->fullCData(oldp+99788,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_7_cfi_type),3);
    bufp->fullCData(oldp+99789,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_7_br_mask),8);
    bufp->fullBit(oldp+99790,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_7_cfi_is_call));
    bufp->fullBit(oldp+99791,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_7_cfi_is_ret));
    bufp->fullQData(oldp+99792,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_7_ras_top),40);
    bufp->fullCData(oldp+99794,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_7_ras_idx),5);
    bufp->fullBit(oldp+99795,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_7_start_bank));
    bufp->fullBit(oldp+99796,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_8_cfi_idx_valid));
    bufp->fullCData(oldp+99797,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_8_cfi_idx_bits),3);
    bufp->fullBit(oldp+99798,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_8_cfi_taken));
    bufp->fullBit(oldp+99799,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_8_cfi_mispredicted));
    bufp->fullCData(oldp+99800,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_8_cfi_type),3);
    bufp->fullCData(oldp+99801,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_8_br_mask),8);
    bufp->fullBit(oldp+99802,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_8_cfi_is_call));
    bufp->fullBit(oldp+99803,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_8_cfi_is_ret));
    bufp->fullQData(oldp+99804,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_8_ras_top),40);
    bufp->fullCData(oldp+99806,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_8_ras_idx),5);
    bufp->fullBit(oldp+99807,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_8_start_bank));
    bufp->fullBit(oldp+99808,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_9_cfi_idx_valid));
    bufp->fullCData(oldp+99809,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_9_cfi_idx_bits),3);
    bufp->fullBit(oldp+99810,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_9_cfi_taken));
    bufp->fullBit(oldp+99811,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_9_cfi_mispredicted));
    bufp->fullCData(oldp+99812,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_9_cfi_type),3);
    bufp->fullCData(oldp+99813,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_9_br_mask),8);
    bufp->fullBit(oldp+99814,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_9_cfi_is_call));
    bufp->fullBit(oldp+99815,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_9_cfi_is_ret));
    bufp->fullQData(oldp+99816,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_9_ras_top),40);
    bufp->fullCData(oldp+99818,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_9_ras_idx),5);
    bufp->fullBit(oldp+99819,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_9_start_bank));
    bufp->fullBit(oldp+99820,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_10_cfi_idx_valid));
    bufp->fullCData(oldp+99821,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_10_cfi_idx_bits),3);
    bufp->fullBit(oldp+99822,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_10_cfi_taken));
    bufp->fullBit(oldp+99823,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_10_cfi_mispredicted));
    bufp->fullCData(oldp+99824,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_10_cfi_type),3);
    bufp->fullCData(oldp+99825,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_10_br_mask),8);
    bufp->fullBit(oldp+99826,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_10_cfi_is_call));
    bufp->fullBit(oldp+99827,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_10_cfi_is_ret));
    bufp->fullQData(oldp+99828,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_10_ras_top),40);
    bufp->fullCData(oldp+99830,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_10_ras_idx),5);
    bufp->fullBit(oldp+99831,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_10_start_bank));
    bufp->fullBit(oldp+99832,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_11_cfi_idx_valid));
    bufp->fullCData(oldp+99833,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_11_cfi_idx_bits),3);
    bufp->fullBit(oldp+99834,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_11_cfi_taken));
    bufp->fullBit(oldp+99835,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_11_cfi_mispredicted));
    bufp->fullCData(oldp+99836,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_11_cfi_type),3);
    bufp->fullCData(oldp+99837,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_11_br_mask),8);
    bufp->fullBit(oldp+99838,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_11_cfi_is_call));
    bufp->fullBit(oldp+99839,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_11_cfi_is_ret));
    bufp->fullQData(oldp+99840,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_11_ras_top),40);
    bufp->fullCData(oldp+99842,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_11_ras_idx),5);
    bufp->fullBit(oldp+99843,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_11_start_bank));
    bufp->fullBit(oldp+99844,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_12_cfi_idx_valid));
    bufp->fullCData(oldp+99845,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_12_cfi_idx_bits),3);
    bufp->fullBit(oldp+99846,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_12_cfi_taken));
    bufp->fullBit(oldp+99847,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_12_cfi_mispredicted));
    bufp->fullCData(oldp+99848,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_12_cfi_type),3);
    bufp->fullCData(oldp+99849,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_12_br_mask),8);
    bufp->fullBit(oldp+99850,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_12_cfi_is_call));
    bufp->fullBit(oldp+99851,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_12_cfi_is_ret));
    bufp->fullQData(oldp+99852,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_12_ras_top),40);
    bufp->fullCData(oldp+99854,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_12_ras_idx),5);
    bufp->fullBit(oldp+99855,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_12_start_bank));
    bufp->fullBit(oldp+99856,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_13_cfi_idx_valid));
    bufp->fullCData(oldp+99857,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_13_cfi_idx_bits),3);
    bufp->fullBit(oldp+99858,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_13_cfi_taken));
    bufp->fullBit(oldp+99859,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_13_cfi_mispredicted));
    bufp->fullCData(oldp+99860,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_13_cfi_type),3);
    bufp->fullCData(oldp+99861,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_13_br_mask),8);
    bufp->fullBit(oldp+99862,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_13_cfi_is_call));
    bufp->fullBit(oldp+99863,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_13_cfi_is_ret));
    bufp->fullQData(oldp+99864,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_13_ras_top),40);
    bufp->fullCData(oldp+99866,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_13_ras_idx),5);
    bufp->fullBit(oldp+99867,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_13_start_bank));
    bufp->fullBit(oldp+99868,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_14_cfi_idx_valid));
    bufp->fullCData(oldp+99869,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_14_cfi_idx_bits),3);
    bufp->fullBit(oldp+99870,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_14_cfi_taken));
    bufp->fullBit(oldp+99871,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_14_cfi_mispredicted));
    bufp->fullCData(oldp+99872,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_14_cfi_type),3);
    bufp->fullCData(oldp+99873,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_14_br_mask),8);
    bufp->fullBit(oldp+99874,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_14_cfi_is_call));
    bufp->fullBit(oldp+99875,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_14_cfi_is_ret));
    bufp->fullQData(oldp+99876,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_14_ras_top),40);
    bufp->fullCData(oldp+99878,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_14_ras_idx),5);
    bufp->fullBit(oldp+99879,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_14_start_bank));
    bufp->fullBit(oldp+99880,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_15_cfi_idx_valid));
    bufp->fullCData(oldp+99881,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_15_cfi_idx_bits),3);
    bufp->fullBit(oldp+99882,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_15_cfi_taken));
    bufp->fullBit(oldp+99883,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_15_cfi_mispredicted));
    bufp->fullCData(oldp+99884,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_15_cfi_type),3);
    bufp->fullCData(oldp+99885,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_15_br_mask),8);
    bufp->fullBit(oldp+99886,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_15_cfi_is_call));
    bufp->fullBit(oldp+99887,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_15_cfi_is_ret));
    bufp->fullQData(oldp+99888,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_15_ras_top),40);
    bufp->fullCData(oldp+99890,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_15_ras_idx),5);
    bufp->fullBit(oldp+99891,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_15_start_bank));
    bufp->fullBit(oldp+99892,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_16_cfi_idx_valid));
    bufp->fullCData(oldp+99893,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_16_cfi_idx_bits),3);
    bufp->fullBit(oldp+99894,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_16_cfi_taken));
    bufp->fullBit(oldp+99895,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_16_cfi_mispredicted));
    bufp->fullCData(oldp+99896,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_16_cfi_type),3);
    bufp->fullCData(oldp+99897,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_16_br_mask),8);
    bufp->fullBit(oldp+99898,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_16_cfi_is_call));
    bufp->fullBit(oldp+99899,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_16_cfi_is_ret));
    bufp->fullQData(oldp+99900,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_16_ras_top),40);
    bufp->fullCData(oldp+99902,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_16_ras_idx),5);
    bufp->fullBit(oldp+99903,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_16_start_bank));
    bufp->fullBit(oldp+99904,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_17_cfi_idx_valid));
    bufp->fullCData(oldp+99905,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_17_cfi_idx_bits),3);
    bufp->fullBit(oldp+99906,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_17_cfi_taken));
    bufp->fullBit(oldp+99907,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_17_cfi_mispredicted));
    bufp->fullCData(oldp+99908,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_17_cfi_type),3);
    bufp->fullCData(oldp+99909,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_17_br_mask),8);
    bufp->fullBit(oldp+99910,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_17_cfi_is_call));
    bufp->fullBit(oldp+99911,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_17_cfi_is_ret));
    bufp->fullQData(oldp+99912,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_17_ras_top),40);
    bufp->fullCData(oldp+99914,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_17_ras_idx),5);
    bufp->fullBit(oldp+99915,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_17_start_bank));
    bufp->fullBit(oldp+99916,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_18_cfi_idx_valid));
    bufp->fullCData(oldp+99917,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_18_cfi_idx_bits),3);
    bufp->fullBit(oldp+99918,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_18_cfi_taken));
    bufp->fullBit(oldp+99919,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_18_cfi_mispredicted));
    bufp->fullCData(oldp+99920,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_18_cfi_type),3);
    bufp->fullCData(oldp+99921,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_18_br_mask),8);
    bufp->fullBit(oldp+99922,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_18_cfi_is_call));
    bufp->fullBit(oldp+99923,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_18_cfi_is_ret));
    bufp->fullQData(oldp+99924,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_18_ras_top),40);
    bufp->fullCData(oldp+99926,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_18_ras_idx),5);
    bufp->fullBit(oldp+99927,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_18_start_bank));
    bufp->fullBit(oldp+99928,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_19_cfi_idx_valid));
    bufp->fullCData(oldp+99929,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_19_cfi_idx_bits),3);
    bufp->fullBit(oldp+99930,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_19_cfi_taken));
    bufp->fullBit(oldp+99931,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_19_cfi_mispredicted));
    bufp->fullCData(oldp+99932,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_19_cfi_type),3);
    bufp->fullCData(oldp+99933,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_19_br_mask),8);
    bufp->fullBit(oldp+99934,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_19_cfi_is_call));
    bufp->fullBit(oldp+99935,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_19_cfi_is_ret));
    bufp->fullQData(oldp+99936,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_19_ras_top),40);
    bufp->fullCData(oldp+99938,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_19_ras_idx),5);
    bufp->fullBit(oldp+99939,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_19_start_bank));
    bufp->fullBit(oldp+99940,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_20_cfi_idx_valid));
    bufp->fullCData(oldp+99941,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_20_cfi_idx_bits),3);
    bufp->fullBit(oldp+99942,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_20_cfi_taken));
    bufp->fullBit(oldp+99943,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_20_cfi_mispredicted));
    bufp->fullCData(oldp+99944,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_20_cfi_type),3);
    bufp->fullCData(oldp+99945,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_20_br_mask),8);
    bufp->fullBit(oldp+99946,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_20_cfi_is_call));
    bufp->fullBit(oldp+99947,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_20_cfi_is_ret));
    bufp->fullQData(oldp+99948,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_20_ras_top),40);
    bufp->fullCData(oldp+99950,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_20_ras_idx),5);
    bufp->fullBit(oldp+99951,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_20_start_bank));
    bufp->fullBit(oldp+99952,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_21_cfi_idx_valid));
    bufp->fullCData(oldp+99953,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_21_cfi_idx_bits),3);
    bufp->fullBit(oldp+99954,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_21_cfi_taken));
    bufp->fullBit(oldp+99955,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_21_cfi_mispredicted));
    bufp->fullCData(oldp+99956,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_21_cfi_type),3);
    bufp->fullCData(oldp+99957,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_21_br_mask),8);
    bufp->fullBit(oldp+99958,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_21_cfi_is_call));
    bufp->fullBit(oldp+99959,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_21_cfi_is_ret));
    bufp->fullQData(oldp+99960,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_21_ras_top),40);
    bufp->fullCData(oldp+99962,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_21_ras_idx),5);
    bufp->fullBit(oldp+99963,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_21_start_bank));
    bufp->fullBit(oldp+99964,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_22_cfi_idx_valid));
    bufp->fullCData(oldp+99965,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_22_cfi_idx_bits),3);
    bufp->fullBit(oldp+99966,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_22_cfi_taken));
    bufp->fullBit(oldp+99967,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_22_cfi_mispredicted));
    bufp->fullCData(oldp+99968,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_22_cfi_type),3);
    bufp->fullCData(oldp+99969,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_22_br_mask),8);
    bufp->fullBit(oldp+99970,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_22_cfi_is_call));
    bufp->fullBit(oldp+99971,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_22_cfi_is_ret));
    bufp->fullQData(oldp+99972,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_22_ras_top),40);
    bufp->fullCData(oldp+99974,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_22_ras_idx),5);
    bufp->fullBit(oldp+99975,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_22_start_bank));
    bufp->fullBit(oldp+99976,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_23_cfi_idx_valid));
    bufp->fullCData(oldp+99977,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_23_cfi_idx_bits),3);
    bufp->fullBit(oldp+99978,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_23_cfi_taken));
    bufp->fullBit(oldp+99979,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_23_cfi_mispredicted));
    bufp->fullCData(oldp+99980,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_23_cfi_type),3);
    bufp->fullCData(oldp+99981,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_23_br_mask),8);
    bufp->fullBit(oldp+99982,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_23_cfi_is_call));
    bufp->fullBit(oldp+99983,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_23_cfi_is_ret));
    bufp->fullQData(oldp+99984,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_23_ras_top),40);
    bufp->fullCData(oldp+99986,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_23_ras_idx),5);
    bufp->fullBit(oldp+99987,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_23_start_bank));
    bufp->fullBit(oldp+99988,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_24_cfi_idx_valid));
    bufp->fullCData(oldp+99989,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_24_cfi_idx_bits),3);
    bufp->fullBit(oldp+99990,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_24_cfi_taken));
    bufp->fullBit(oldp+99991,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_24_cfi_mispredicted));
    bufp->fullCData(oldp+99992,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_24_cfi_type),3);
    bufp->fullCData(oldp+99993,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_24_br_mask),8);
    bufp->fullBit(oldp+99994,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_24_cfi_is_call));
    bufp->fullBit(oldp+99995,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_24_cfi_is_ret));
    bufp->fullQData(oldp+99996,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_24_ras_top),40);
    bufp->fullCData(oldp+99998,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_24_ras_idx),5);
    bufp->fullBit(oldp+99999,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_24_start_bank));
    bufp->fullBit(oldp+100000,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_25_cfi_idx_valid));
    bufp->fullCData(oldp+100001,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_25_cfi_idx_bits),3);
    bufp->fullBit(oldp+100002,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_25_cfi_taken));
    bufp->fullBit(oldp+100003,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_25_cfi_mispredicted));
    bufp->fullCData(oldp+100004,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_25_cfi_type),3);
    bufp->fullCData(oldp+100005,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_25_br_mask),8);
    bufp->fullBit(oldp+100006,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_25_cfi_is_call));
    bufp->fullBit(oldp+100007,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_25_cfi_is_ret));
    bufp->fullQData(oldp+100008,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_25_ras_top),40);
    bufp->fullCData(oldp+100010,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_25_ras_idx),5);
    bufp->fullBit(oldp+100011,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_25_start_bank));
    bufp->fullBit(oldp+100012,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_26_cfi_idx_valid));
    bufp->fullCData(oldp+100013,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_26_cfi_idx_bits),3);
    bufp->fullBit(oldp+100014,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_26_cfi_taken));
    bufp->fullBit(oldp+100015,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_26_cfi_mispredicted));
    bufp->fullCData(oldp+100016,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_26_cfi_type),3);
    bufp->fullCData(oldp+100017,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_26_br_mask),8);
    bufp->fullBit(oldp+100018,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_26_cfi_is_call));
    bufp->fullBit(oldp+100019,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_26_cfi_is_ret));
    bufp->fullQData(oldp+100020,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_26_ras_top),40);
    bufp->fullCData(oldp+100022,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_26_ras_idx),5);
    bufp->fullBit(oldp+100023,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_26_start_bank));
    bufp->fullBit(oldp+100024,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_27_cfi_idx_valid));
    bufp->fullCData(oldp+100025,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_27_cfi_idx_bits),3);
    bufp->fullBit(oldp+100026,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_27_cfi_taken));
    bufp->fullBit(oldp+100027,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_27_cfi_mispredicted));
    bufp->fullCData(oldp+100028,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_27_cfi_type),3);
    bufp->fullCData(oldp+100029,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_27_br_mask),8);
    bufp->fullBit(oldp+100030,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_27_cfi_is_call));
    bufp->fullBit(oldp+100031,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_27_cfi_is_ret));
    bufp->fullQData(oldp+100032,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_27_ras_top),40);
    bufp->fullCData(oldp+100034,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_27_ras_idx),5);
    bufp->fullBit(oldp+100035,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_27_start_bank));
    bufp->fullBit(oldp+100036,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_28_cfi_idx_valid));
    bufp->fullCData(oldp+100037,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_28_cfi_idx_bits),3);
    bufp->fullBit(oldp+100038,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_28_cfi_taken));
    bufp->fullBit(oldp+100039,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_28_cfi_mispredicted));
    bufp->fullCData(oldp+100040,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_28_cfi_type),3);
    bufp->fullCData(oldp+100041,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_28_br_mask),8);
    bufp->fullBit(oldp+100042,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_28_cfi_is_call));
    bufp->fullBit(oldp+100043,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_28_cfi_is_ret));
    bufp->fullQData(oldp+100044,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_28_ras_top),40);
    bufp->fullCData(oldp+100046,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_28_ras_idx),5);
    bufp->fullBit(oldp+100047,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_28_start_bank));
    bufp->fullBit(oldp+100048,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_29_cfi_idx_valid));
    bufp->fullCData(oldp+100049,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_29_cfi_idx_bits),3);
    bufp->fullBit(oldp+100050,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_29_cfi_taken));
    bufp->fullBit(oldp+100051,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_29_cfi_mispredicted));
    bufp->fullCData(oldp+100052,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_29_cfi_type),3);
    bufp->fullCData(oldp+100053,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_29_br_mask),8);
    bufp->fullBit(oldp+100054,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_29_cfi_is_call));
    bufp->fullBit(oldp+100055,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_29_cfi_is_ret));
    bufp->fullQData(oldp+100056,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_29_ras_top),40);
    bufp->fullCData(oldp+100058,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_29_ras_idx),5);
    bufp->fullBit(oldp+100059,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_29_start_bank));
    bufp->fullBit(oldp+100060,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_30_cfi_idx_valid));
    bufp->fullCData(oldp+100061,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_30_cfi_idx_bits),3);
    bufp->fullBit(oldp+100062,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_30_cfi_taken));
    bufp->fullBit(oldp+100063,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_30_cfi_mispredicted));
    bufp->fullCData(oldp+100064,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_30_cfi_type),3);
    bufp->fullCData(oldp+100065,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_30_br_mask),8);
    bufp->fullBit(oldp+100066,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_30_cfi_is_call));
    bufp->fullBit(oldp+100067,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_30_cfi_is_ret));
    bufp->fullQData(oldp+100068,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_30_ras_top),40);
    bufp->fullCData(oldp+100070,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_30_ras_idx),5);
    bufp->fullBit(oldp+100071,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_30_start_bank));
    bufp->fullBit(oldp+100072,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_31_cfi_idx_valid));
    bufp->fullCData(oldp+100073,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_31_cfi_idx_bits),3);
    bufp->fullBit(oldp+100074,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_31_cfi_taken));
    bufp->fullBit(oldp+100075,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_31_cfi_mispredicted));
    bufp->fullCData(oldp+100076,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_31_cfi_type),3);
    bufp->fullCData(oldp+100077,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_31_br_mask),8);
    bufp->fullBit(oldp+100078,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_31_cfi_is_call));
    bufp->fullBit(oldp+100079,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_31_cfi_is_ret));
    bufp->fullQData(oldp+100080,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_31_ras_top),40);
    bufp->fullCData(oldp+100082,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_31_ras_idx),5);
    bufp->fullBit(oldp+100083,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_31_start_bank));
    bufp->fullBit(oldp+100084,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1_MPORT_1_en));
    bufp->fullQData(oldp+100085,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_ghist_old_history),64);
    bufp->fullBit(oldp+100087,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_ghist_current_saw_branch_not_taken));
    bufp->fullBit(oldp+100088,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_ghist_new_saw_branch_not_taken));
    bufp->fullBit(oldp+100089,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_ghist_new_saw_branch_taken));
    bufp->fullCData(oldp+100090,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_ghist_ras_idx),5);
    bufp->fullBit(oldp+100091,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_entry_cfi_idx_valid));
    bufp->fullCData(oldp+100092,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_entry_cfi_idx_bits),3);
    bufp->fullBit(oldp+100093,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_entry_cfi_taken));
    bufp->fullCData(oldp+100094,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_entry_br_mask),8);
    bufp->fullBit(oldp+100095,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_entry_cfi_is_call));
    bufp->fullBit(oldp+100096,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_entry_cfi_is_ret));
    bufp->fullQData(oldp+100097,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_pc),40);
    bufp->fullCData(oldp+100099,(((7U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_entry_cfi_idx_bits))
                                   ? (0xffU & ((IData)(1U) 
                                               << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_entry_cfi_idx_bits)))
                                   : 0U)),8);
    bufp->fullCData(oldp+100100,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__new_ghist_not_taken_branches),8);
    bufp->fullBit(oldp+100101,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__new_ghist_cfi_in_bank_0));
    bufp->fullBit(oldp+100102,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__new_ghist_ignore_second_bank));
    bufp->fullBit(oldp+100103,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__new_ghist_first_bank_saw_not_taken));
    bufp->fullBit(oldp+100104,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__first_empty));
    bufp->fullBit(oldp+100105,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_update_mispredict));
    bufp->fullBit(oldp+100106,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_update_repair));
    bufp->fullCData(oldp+100107,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_repair_idx),5);
    bufp->fullCData(oldp+100108,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_end_idx),5);
    bufp->fullQData(oldp+100109,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_repair_pc),40);
    bufp->fullCData(oldp+100111,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_entry_cfi_type),3);
    bufp->fullCData(oldp+100112,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_entry_br_mask),8);
    bufp->fullBit(oldp+100113,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__REG));
    bufp->fullCData(oldp+100114,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_repair_idx_REG),5);
    bufp->fullCData(oldp+100115,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_end_idx_REG),5);
    bufp->fullBit(oldp+100116,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__REG_1));
    bufp->fullBit(oldp+100117,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__do_commit_update_REG));
    bufp->fullBit(oldp+100118,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__REG_2));
    bufp->fullBit(oldp+100119,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__io_bpdupdate_valid_REG));
    bufp->fullBit(oldp+100120,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__REG_3));
    bufp->fullBit(oldp+100121,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_entry_REG_cfi_idx_valid));
    bufp->fullCData(oldp+100122,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_entry_REG_cfi_idx_bits),3);
    bufp->fullBit(oldp+100123,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_entry_REG_cfi_taken));
    bufp->fullCData(oldp+100124,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_entry_REG_br_mask),8);
    bufp->fullBit(oldp+100125,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_entry_REG_cfi_is_call));
    bufp->fullBit(oldp+100126,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__prev_entry_REG_cfi_is_ret));
    bufp->fullCData(oldp+100127,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__REG_4),5);
    bufp->fullBit(oldp+100128,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_REG_cfi_idx_valid));
    bufp->fullCData(oldp+100129,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_REG_cfi_idx_bits),3);
    bufp->fullBit(oldp+100130,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_REG_cfi_taken));
    bufp->fullBit(oldp+100131,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_REG_cfi_mispredicted));
    bufp->fullCData(oldp+100132,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_REG_cfi_type),3);
    bufp->fullCData(oldp+100133,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_REG_br_mask),8);
    bufp->fullBit(oldp+100134,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_REG_cfi_is_call));
    bufp->fullBit(oldp+100135,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_REG_cfi_is_ret));
    bufp->fullQData(oldp+100136,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_REG_ras_top),40);
    bufp->fullCData(oldp+100138,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_REG_ras_idx),5);
    bufp->fullBit(oldp+100139,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ram_REG_start_bank));
    bufp->fullCData(oldp+100140,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__new_entry_br_mask),8);
    bufp->fullBit(oldp+100141,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__do_commit_update));
    bufp->fullCData(oldp+100142,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__redirect_new_entry_br_mask),8);
    bufp->fullQData(oldp+100143,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__redirect_new_entry_ras_top),40);
    bufp->fullCData(oldp+100145,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__redirect_new_entry_ras_idx),5);
    bufp->fullBit(oldp+100146,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__redirect_new_entry_start_bank));
    bufp->fullCData(oldp+100147,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__new_cfi_idx),3);
    bufp->fullBit(oldp+100148,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__redirect_new_entry_cfi_idx_valid));
    bufp->fullBit(oldp+100149,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__redirect_new_entry_cfi_is_call));
    bufp->fullBit(oldp+100150,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__redirect_new_entry_cfi_is_ret));
    bufp->fullCData(oldp+100151,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___bpd_meta_T_1),5);
    bufp->fullWData(oldp+100152,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT___GEN),72);
    bufp->fullWData(oldp+100155,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram_R_0_data),72);
    bufp->fullWData(oldp+100158,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[0]),72);
    bufp->fullWData(oldp+100161,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[1]),72);
    bufp->fullWData(oldp+100164,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[2]),72);
    bufp->fullWData(oldp+100167,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[3]),72);
    bufp->fullWData(oldp+100170,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[4]),72);
    bufp->fullWData(oldp+100173,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[5]),72);
    bufp->fullWData(oldp+100176,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[6]),72);
    bufp->fullWData(oldp+100179,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[7]),72);
    bufp->fullWData(oldp+100182,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[8]),72);
    bufp->fullWData(oldp+100185,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[9]),72);
    bufp->fullWData(oldp+100188,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[10]),72);
    bufp->fullWData(oldp+100191,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[11]),72);
    bufp->fullWData(oldp+100194,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[12]),72);
    bufp->fullWData(oldp+100197,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[13]),72);
    bufp->fullWData(oldp+100200,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[14]),72);
    bufp->fullWData(oldp+100203,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[15]),72);
    bufp->fullWData(oldp+100206,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[16]),72);
    bufp->fullWData(oldp+100209,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[17]),72);
    bufp->fullWData(oldp+100212,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[18]),72);
    bufp->fullWData(oldp+100215,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[19]),72);
    bufp->fullWData(oldp+100218,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[20]),72);
    bufp->fullWData(oldp+100221,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[21]),72);
    bufp->fullWData(oldp+100224,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[22]),72);
    bufp->fullWData(oldp+100227,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[23]),72);
    bufp->fullWData(oldp+100230,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[24]),72);
    bufp->fullWData(oldp+100233,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[25]),72);
    bufp->fullWData(oldp+100236,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[26]),72);
    bufp->fullWData(oldp+100239,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[27]),72);
    bufp->fullWData(oldp+100242,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[28]),72);
    bufp->fullWData(oldp+100245,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[29]),72);
    bufp->fullWData(oldp+100248,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[30]),72);
    bufp->fullWData(oldp+100251,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[31]),72);
    bufp->fullBit(oldp+100254,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram_R_0_en_pipe_0));
    bufp->fullCData(oldp+100255,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram_R_0_addr_pipe_0),5);
    bufp->fullWData(oldp+100256,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram_R_0_data),72);
    bufp->fullWData(oldp+100259,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[0]),72);
    bufp->fullWData(oldp+100262,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[1]),72);
    bufp->fullWData(oldp+100265,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[2]),72);
    bufp->fullWData(oldp+100268,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[3]),72);
    bufp->fullWData(oldp+100271,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[4]),72);
    bufp->fullWData(oldp+100274,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[5]),72);
    bufp->fullWData(oldp+100277,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[6]),72);
    bufp->fullWData(oldp+100280,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[7]),72);
    bufp->fullWData(oldp+100283,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[8]),72);
    bufp->fullWData(oldp+100286,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[9]),72);
    bufp->fullWData(oldp+100289,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[10]),72);
    bufp->fullWData(oldp+100292,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[11]),72);
    bufp->fullWData(oldp+100295,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[12]),72);
    bufp->fullWData(oldp+100298,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[13]),72);
    bufp->fullWData(oldp+100301,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[14]),72);
    bufp->fullWData(oldp+100304,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[15]),72);
    bufp->fullWData(oldp+100307,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[16]),72);
    bufp->fullWData(oldp+100310,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[17]),72);
    bufp->fullWData(oldp+100313,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[18]),72);
    bufp->fullWData(oldp+100316,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[19]),72);
    bufp->fullWData(oldp+100319,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[20]),72);
    bufp->fullWData(oldp+100322,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[21]),72);
    bufp->fullWData(oldp+100325,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[22]),72);
    bufp->fullWData(oldp+100328,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[23]),72);
    bufp->fullWData(oldp+100331,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[24]),72);
    bufp->fullWData(oldp+100334,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[25]),72);
    bufp->fullWData(oldp+100337,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[26]),72);
    bufp->fullWData(oldp+100340,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[27]),72);
    bufp->fullWData(oldp+100343,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[28]),72);
    bufp->fullWData(oldp+100346,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[29]),72);
    bufp->fullWData(oldp+100349,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[30]),72);
    bufp->fullWData(oldp+100352,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram[31]),72);
    bufp->fullBit(oldp+100355,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram_R_0_en_pipe_0));
    bufp->fullCData(oldp+100356,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram_R_0_addr_pipe_0),5);
    __Vtemp_ha8838ae6__0[0U] = (VTestHarness__ConstPool__CONST_h5b889007_0[0U] 
                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][0x1fU] << 0x1aU) 
                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                      [0U][0x1eU] >> 6U)));
    __Vtemp_ha8838ae6__0[1U] = (VTestHarness__ConstPool__CONST_h5b889007_0[1U] 
                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][0x20U] << 0x1aU) 
                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                      [0U][0x1fU] >> 6U)));
    __Vtemp_ha8838ae6__0[2U] = (VTestHarness__ConstPool__CONST_h5b889007_0[2U] 
                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][0x21U] << 0x1aU) 
                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                      [0U][0x20U] >> 6U)));
    __Vtemp_ha8838ae6__0[3U] = (VTestHarness__ConstPool__CONST_h5b889007_0[3U] 
                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][0x22U] << 0x1aU) 
                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                      [0U][0x21U] >> 6U)));
    __Vtemp_ha8838ae6__0[4U] = (VTestHarness__ConstPool__CONST_h5b889007_0[4U] 
                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][0x23U] << 0x1aU) 
                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                      [0U][0x22U] >> 6U)));
    __Vtemp_ha8838ae6__0[5U] = (VTestHarness__ConstPool__CONST_h5b889007_0[5U] 
                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][0x24U] << 0x1aU) 
                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                      [0U][0x23U] >> 6U)));
    __Vtemp_ha8838ae6__0[6U] = (VTestHarness__ConstPool__CONST_h5b889007_0[6U] 
                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                    [0U][0x25U] << 0x1aU) 
                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                      [0U][0x24U] >> 6U)));
    __Vtemp_ha8838ae6__0[7U] = (VTestHarness__ConstPool__CONST_h5b889007_0[7U] 
                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory
                                   [0U][0x25U] >> 6U));
    bufp->fullWData(oldp+100357,(__Vtemp_ha8838ae6__0),240);
    bufp->fullWData(oldp+100365,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram_R_0_data),240);
    bufp->fullWData(oldp+100373,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[0]),240);
    bufp->fullWData(oldp+100381,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[1]),240);
    bufp->fullWData(oldp+100389,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[2]),240);
    bufp->fullWData(oldp+100397,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[3]),240);
    bufp->fullWData(oldp+100405,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[4]),240);
    bufp->fullWData(oldp+100413,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[5]),240);
    bufp->fullWData(oldp+100421,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[6]),240);
    bufp->fullWData(oldp+100429,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[7]),240);
    bufp->fullWData(oldp+100437,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[8]),240);
    bufp->fullWData(oldp+100445,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[9]),240);
    bufp->fullWData(oldp+100453,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[10]),240);
    bufp->fullWData(oldp+100461,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[11]),240);
    bufp->fullWData(oldp+100469,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[12]),240);
    bufp->fullWData(oldp+100477,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[13]),240);
    bufp->fullWData(oldp+100485,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[14]),240);
    bufp->fullWData(oldp+100493,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[15]),240);
    bufp->fullWData(oldp+100501,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[16]),240);
    bufp->fullWData(oldp+100509,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[17]),240);
    bufp->fullWData(oldp+100517,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[18]),240);
    bufp->fullWData(oldp+100525,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[19]),240);
    bufp->fullWData(oldp+100533,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[20]),240);
    bufp->fullWData(oldp+100541,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[21]),240);
    bufp->fullWData(oldp+100549,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[22]),240);
    bufp->fullWData(oldp+100557,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[23]),240);
    bufp->fullWData(oldp+100565,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[24]),240);
    bufp->fullWData(oldp+100573,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[25]),240);
    bufp->fullWData(oldp+100581,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[26]),240);
    bufp->fullWData(oldp+100589,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[27]),240);
    bufp->fullWData(oldp+100597,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[28]),240);
    bufp->fullWData(oldp+100605,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[29]),240);
    bufp->fullWData(oldp+100613,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[30]),240);
    bufp->fullWData(oldp+100621,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram[31]),240);
    bufp->fullBit(oldp+100629,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram_R_0_en_pipe_0));
    bufp->fullCData(oldp+100630,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram_R_0_addr_pipe_0),5);
    bufp->fullIData(oldp+100631,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT____Vcellinp__icache__io_s1_paddr),32);
    bufp->fullBit(oldp+100632,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___tlb_io_resp_miss) 
                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f1_clear))));
    bufp->fullBit(oldp+100633,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___icache_io_resp_valid));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_bankid) {
        __Vtemp_he033613f__0[0U] = (IData)((((QData)((IData)(
                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[3U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[2U]))));
        __Vtemp_he033613f__0[1U] = (IData)(((((QData)((IData)(
                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[3U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[2U]))) 
                                            >> 0x20U));
        __Vtemp_he033613f__0[2U] = (IData)((((QData)((IData)(
                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[1U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[0U]))));
        __Vtemp_he033613f__0[3U] = (IData)(((((QData)((IData)(
                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[1U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[0U]))) 
                                            >> 0x20U));
    } else {
        __Vtemp_he033613f__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[0U];
        __Vtemp_he033613f__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[1U];
        __Vtemp_he033613f__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[2U];
        __Vtemp_he033613f__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data[3U];
    }
    bufp->fullWData(oldp+100634,(__Vtemp_he033613f__0),128);
    bufp->fullBit(oldp+100638,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__writeEnable));
    bufp->fullBit(oldp+100639,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__writeEnable_0));
    bufp->fullBit(oldp+100640,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__writeEnable_1));
    bufp->fullBit(oldp+100641,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__writeEnable_2));
    bufp->fullBit(oldp+100642,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__writeEnable_3));
    bufp->fullBit(oldp+100643,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__writeEnable_4));
    bufp->fullBit(oldp+100644,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__writeEnable_5));
    bufp->fullBit(oldp+100645,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__writeEnable_6));
    bufp->fullBit(oldp+100646,((7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way))));
    bufp->fullBit(oldp+100647,((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way))));
    bufp->fullBit(oldp+100648,((5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way))));
    bufp->fullBit(oldp+100649,((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way))));
    bufp->fullBit(oldp+100650,((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way))));
    bufp->fullBit(oldp+100651,((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way))));
    bufp->fullBit(oldp+100652,((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way))));
    bufp->fullBit(oldp+100653,((1U & (~ (IData)((0U 
                                                 != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way)))))));
    bufp->fullBit(oldp+100654,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s1_valid));
    bufp->fullBit(oldp+100655,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_valid));
    bufp->fullBit(oldp+100656,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_hit));
    bufp->fullBit(oldp+100657,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__invalidated));
    bufp->fullBit(oldp+100658,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__refill_valid));
    bufp->fullBit(oldp+100659,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__refill_fire));
    bufp->fullBit(oldp+100660,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_miss_REG));
    bufp->fullBit(oldp+100661,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_miss));
    bufp->fullIData(oldp+100662,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__refill_paddr),32);
    bufp->fullBit(oldp+100663,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__refill_one_beat));
    bufp->fullCData(oldp+100664,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__beats1),8);
    bufp->fullCData(oldp+100665,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__counter),8);
    bufp->fullCData(oldp+100666,((0xffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__counter) 
                                           - (IData)(1U)))),8);
    bufp->fullCData(oldp+100667,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__refill_cnt),8);
    bufp->fullBit(oldp+100668,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array_MPORT_en));
    bufp->fullCData(oldp+100669,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way),3);
    bufp->fullWData(oldp+100670,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array),512);
    bufp->fullBit(oldp+100686,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s1_tag_hit_0));
    bufp->fullBit(oldp+100687,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s1_tag_hit_1));
    bufp->fullBit(oldp+100688,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s1_tag_hit_2));
    bufp->fullBit(oldp+100689,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s1_tag_hit_3));
    bufp->fullBit(oldp+100690,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s1_tag_hit_4));
    bufp->fullBit(oldp+100691,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s1_tag_hit_5));
    bufp->fullBit(oldp+100692,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s1_tag_hit_6));
    bufp->fullBit(oldp+100693,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s1_tag_hit_7));
    bufp->fullBit(oldp+100694,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s1_bankid_REG));
    bufp->fullWData(oldp+100695,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_dout_0_REG),128);
    bufp->fullWData(oldp+100699,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_dout_1_REG),128);
    bufp->fullWData(oldp+100703,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_dout_2_REG),128);
    bufp->fullWData(oldp+100707,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_dout_3_REG),128);
    bufp->fullWData(oldp+100711,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_dout_4_REG),128);
    bufp->fullWData(oldp+100715,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_dout_5_REG),128);
    bufp->fullWData(oldp+100719,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_dout_6_REG),128);
    bufp->fullWData(oldp+100723,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_dout_7_REG),128);
    bufp->fullBit(oldp+100727,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_tag_hit_0));
    bufp->fullBit(oldp+100728,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_tag_hit_1));
    bufp->fullBit(oldp+100729,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_tag_hit_2));
    bufp->fullBit(oldp+100730,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_tag_hit_3));
    bufp->fullBit(oldp+100731,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_tag_hit_4));
    bufp->fullBit(oldp+100732,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_tag_hit_5));
    bufp->fullBit(oldp+100733,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_tag_hit_6));
    bufp->fullBit(oldp+100734,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_tag_hit_7));
    bufp->fullBit(oldp+100735,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_bankid));
    bufp->fullWData(oldp+100736,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s2_unbanked_data),128);
    bufp->fullQData(oldp+100740,((((QData)((IData)(
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___widget_1_auto_in_d_bits_data[1U])) 
                                   << 0x20U) | (QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___widget_1_auto_in_d_bits_data[0U])))),64);
    bufp->fullQData(oldp+100742,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_0__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_0__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0]),64);
    bufp->fullBit(oldp+100744,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_0__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100745,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_0__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0),8);
    bufp->fullQData(oldp+100746,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_1__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_1__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0]),64);
    bufp->fullBit(oldp+100748,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_1__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100749,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_1__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0),8);
    bufp->fullQData(oldp+100750,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_2__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_2__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0]),64);
    bufp->fullBit(oldp+100752,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_2__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100753,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_2__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0),8);
    bufp->fullQData(oldp+100754,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_3__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_3__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0]),64);
    bufp->fullBit(oldp+100756,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_3__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100757,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_3__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0),8);
    bufp->fullQData(oldp+100758,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_4__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_4__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0]),64);
    bufp->fullBit(oldp+100760,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_4__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100761,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_4__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0),8);
    bufp->fullQData(oldp+100762,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_5__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_5__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0]),64);
    bufp->fullBit(oldp+100764,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_5__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100765,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_5__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0),8);
    bufp->fullQData(oldp+100766,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_6__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_6__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0]),64);
    bufp->fullBit(oldp+100768,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_6__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100769,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_6__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0),8);
    bufp->fullQData(oldp+100770,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_7__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_7__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0]),64);
    bufp->fullBit(oldp+100772,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_7__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100773,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_7__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0),8);
    bufp->fullQData(oldp+100774,((((QData)((IData)(
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___widget_1_auto_in_d_bits_data[3U])) 
                                   << 0x20U) | (QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___widget_1_auto_in_d_bits_data[2U])))),64);
    bufp->fullQData(oldp+100776,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_0__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_0__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0]),64);
    bufp->fullBit(oldp+100778,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_0__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100779,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_0__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0),8);
    bufp->fullQData(oldp+100780,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_1__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_1__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0]),64);
    bufp->fullBit(oldp+100782,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_1__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100783,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_1__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0),8);
    bufp->fullQData(oldp+100784,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_2__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_2__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0]),64);
    bufp->fullBit(oldp+100786,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_2__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100787,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_2__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0),8);
    bufp->fullQData(oldp+100788,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_3__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_3__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0]),64);
    bufp->fullBit(oldp+100790,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_3__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100791,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_3__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0),8);
    bufp->fullQData(oldp+100792,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_4__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_4__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0]),64);
    bufp->fullBit(oldp+100794,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_4__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100795,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_4__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0),8);
    bufp->fullQData(oldp+100796,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_5__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_5__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0]),64);
    bufp->fullBit(oldp+100798,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_5__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100799,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_5__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0),8);
    bufp->fullQData(oldp+100800,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_6__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_6__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0]),64);
    bufp->fullBit(oldp+100802,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_6__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100803,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_6__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0),8);
    bufp->fullQData(oldp+100804,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_7__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_7__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0]),64);
    bufp->fullBit(oldp+100806,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_7__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100807,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_7__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0),8);
    bufp->fullBit(oldp+100808,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_0));
    bufp->fullBit(oldp+100809,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_1));
    bufp->fullBit(oldp+100810,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_2));
    bufp->fullBit(oldp+100811,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_3));
    bufp->fullBit(oldp+100812,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_4));
    bufp->fullBit(oldp+100813,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_5));
    bufp->fullBit(oldp+100814,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_6));
    bufp->fullBit(oldp+100815,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_7));
    bufp->fullBit(oldp+100816,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_8));
    bufp->fullBit(oldp+100817,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_9));
    bufp->fullBit(oldp+100818,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_10));
    bufp->fullBit(oldp+100819,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_11));
    bufp->fullBit(oldp+100820,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_12));
    bufp->fullBit(oldp+100821,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_13));
    bufp->fullBit(oldp+100822,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_14));
    bufp->fullBit(oldp+100823,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_15));
    __Vtemp_h44069745__0[0U] = ((0xfff00000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                << 8U)) 
                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                   >> 0xcU));
    __Vtemp_h44069745__0[1U] = ((0xf0000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                << 0x10U)) 
                                | ((0xfffff00U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                  >> 4U)) 
                                   | (0xfffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                  >> 0x18U))));
    __Vtemp_h44069745__0[2U] = ((0xffff0000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                << 4U)) 
                                | (0xfffffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                 >> 0x10U)));
    __Vtemp_h44069745__0[3U] = ((0xff000000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                << 0xcU)) 
                                | ((0xfffff0U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                 >> 8U)) 
                                   | (0xffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                 >> 0x1cU))));
    __Vtemp_h44069745__0[4U] = ((0xfffff000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__refill_paddr) 
                                | (0xffffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                >> 0x14U)));
    bufp->fullWData(oldp+100824,(__Vtemp_h44069745__0),160);
    bufp->fullCData(oldp+100829,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wmask),8);
    bufp->fullWData(oldp+100830,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT___tag_array_RW0_rdata),160);
    bufp->fullIData(oldp+100835,((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                  >> 0xcU)),20);
    bufp->fullIData(oldp+100836,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_0__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0]),20);
    bufp->fullBit(oldp+100837,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wmask))));
    bufp->fullIData(oldp+100838,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_1__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_1__DOT__ram_RW_0_r_addr_pipe_0]),20);
    bufp->fullBit(oldp+100839,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wmask) 
                                      >> 1U))));
    bufp->fullIData(oldp+100840,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_2__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_2__DOT__ram_RW_0_r_addr_pipe_0]),20);
    bufp->fullBit(oldp+100841,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wmask) 
                                      >> 2U))));
    bufp->fullIData(oldp+100842,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_3__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_3__DOT__ram_RW_0_r_addr_pipe_0]),20);
    bufp->fullBit(oldp+100843,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wmask) 
                                      >> 3U))));
    bufp->fullIData(oldp+100844,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_4__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_4__DOT__ram_RW_0_r_addr_pipe_0]),20);
    bufp->fullBit(oldp+100845,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wmask) 
                                      >> 4U))));
    bufp->fullIData(oldp+100846,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_5__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_5__DOT__ram_RW_0_r_addr_pipe_0]),20);
    bufp->fullBit(oldp+100847,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wmask) 
                                      >> 5U))));
    bufp->fullIData(oldp+100848,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_6__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_6__DOT__ram_RW_0_r_addr_pipe_0]),20);
    bufp->fullBit(oldp+100849,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wmask) 
                                      >> 6U))));
    bufp->fullIData(oldp+100850,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_7__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_7__DOT__ram_RW_0_r_addr_pipe_0]),20);
    bufp->fullBit(oldp+100851,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wmask) 
                                      >> 7U))));
    __Vtemp_hd0209713__0[0U] = (IData)((((QData)((IData)(
                                                         vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_2__DOT__ram
                                                         [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_2__DOT__ram_RW_0_r_addr_pipe_0])) 
                                         << 0x28U) 
                                        | (((QData)((IData)(
                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_1__DOT__ram
                                                            [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_1__DOT__ram_RW_0_r_addr_pipe_0])) 
                                            << 0x14U) 
                                           | (QData)((IData)(
                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_0__DOT__ram
                                                             [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0])))));
    __Vtemp_hd0209713__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_3__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_3__DOT__ram_RW_0_r_addr_pipe_0] 
                                 << 0x1cU) | (IData)(
                                                     ((((QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_2__DOT__ram
                                                                        [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_2__DOT__ram_RW_0_r_addr_pipe_0])) 
                                                        << 0x28U) 
                                                       | (((QData)((IData)(
                                                                           vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_1__DOT__ram
                                                                           [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_1__DOT__ram_RW_0_r_addr_pipe_0])) 
                                                           << 0x14U) 
                                                          | (QData)((IData)(
                                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_0__DOT__ram
                                                                            [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0])))) 
                                                      >> 0x20U)));
    __Vtemp_hd0209713__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_4__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_4__DOT__ram_RW_0_r_addr_pipe_0] 
                                 << 0x10U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_3__DOT__ram
                                              [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_3__DOT__ram_RW_0_r_addr_pipe_0] 
                                              >> 4U));
    __Vtemp_hd0209713__0[3U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_6__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_6__DOT__ram_RW_0_r_addr_pipe_0] 
                                 << 0x18U) | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_5__DOT__ram
                                               [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_5__DOT__ram_RW_0_r_addr_pipe_0] 
                                               << 4U) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_4__DOT__ram
                                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_4__DOT__ram_RW_0_r_addr_pipe_0] 
                                                 >> 0x10U)));
    __Vtemp_hd0209713__0[4U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_7__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_7__DOT__ram_RW_0_r_addr_pipe_0] 
                                 << 0xcU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_6__DOT__ram
                                             [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_6__DOT__ram_RW_0_r_addr_pipe_0] 
                                             >> 8U));
    bufp->fullWData(oldp+100852,(__Vtemp_hd0209713__0),160);
    bufp->fullBit(oldp+100857,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100858,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0),6);
    bufp->fullBit(oldp+100859,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_1__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100860,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_1__DOT__ram_RW_0_r_addr_pipe_0),6);
    bufp->fullBit(oldp+100861,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_2__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100862,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_2__DOT__ram_RW_0_r_addr_pipe_0),6);
    bufp->fullBit(oldp+100863,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_3__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100864,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_3__DOT__ram_RW_0_r_addr_pipe_0),6);
    bufp->fullBit(oldp+100865,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_4__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100866,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_4__DOT__ram_RW_0_r_addr_pipe_0),6);
    bufp->fullBit(oldp+100867,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_5__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100868,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_5__DOT__ram_RW_0_r_addr_pipe_0),6);
    bufp->fullBit(oldp+100869,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_6__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100870,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_6__DOT__ram_RW_0_r_addr_pipe_0),6);
    bufp->fullBit(oldp+100871,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_7__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullCData(oldp+100872,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_7__DOT__ram_RW_0_r_addr_pipe_0),6);
    bufp->fullCData(oldp+100873,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT____Vcellinp__ras__io_read_idx),5);
    bufp->fullBit(oldp+100874,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT____Vcellinp__ras__io_write_valid));
    bufp->fullCData(oldp+100875,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT____Vcellinp__ras__io_write_idx),5);
    bufp->fullQData(oldp+100876,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT____Vcellinp__ras__io_write_addr),40);
    bufp->fullQData(oldp+100878,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_0),40);
    bufp->fullQData(oldp+100880,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_1),40);
    bufp->fullQData(oldp+100882,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_2),40);
    bufp->fullQData(oldp+100884,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_3),40);
    bufp->fullQData(oldp+100886,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_4),40);
    bufp->fullQData(oldp+100888,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_5),40);
    bufp->fullQData(oldp+100890,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_6),40);
    bufp->fullQData(oldp+100892,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_7),40);
    bufp->fullQData(oldp+100894,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_8),40);
    bufp->fullQData(oldp+100896,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_9),40);
    bufp->fullQData(oldp+100898,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_10),40);
    bufp->fullQData(oldp+100900,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_11),40);
    bufp->fullQData(oldp+100902,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_12),40);
    bufp->fullQData(oldp+100904,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_13),40);
    bufp->fullQData(oldp+100906,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_14),40);
    bufp->fullQData(oldp+100908,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_15),40);
    bufp->fullQData(oldp+100910,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_16),40);
    bufp->fullQData(oldp+100912,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_17),40);
    bufp->fullQData(oldp+100914,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_18),40);
    bufp->fullQData(oldp+100916,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_19),40);
    bufp->fullQData(oldp+100918,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_20),40);
    bufp->fullQData(oldp+100920,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_21),40);
    bufp->fullQData(oldp+100922,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_22),40);
    bufp->fullQData(oldp+100924,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_23),40);
    bufp->fullQData(oldp+100926,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_24),40);
    bufp->fullQData(oldp+100928,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_25),40);
    bufp->fullQData(oldp+100930,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_26),40);
    bufp->fullQData(oldp+100932,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_27),40);
    bufp->fullQData(oldp+100934,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_28),40);
    bufp->fullQData(oldp+100936,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_29),40);
    bufp->fullQData(oldp+100938,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_30),40);
    bufp->fullQData(oldp+100940,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__ras_31),40);
    bufp->fullBit(oldp+100942,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__io_read_addr_REG));
    bufp->fullQData(oldp+100943,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__io_read_addr_REG_1),40);
    bufp->fullQData(oldp+100945,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ras__DOT__io_read_addr_REG_2),40);
    bufp->fullBit(oldp+100947,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT____Vcellinp__tlb__io_req_valid));
    bufp->fullBit(oldp+100948,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___tlb_io_resp_miss));
    bufp->fullIData(oldp+100949,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___tlb_io_resp_paddr),32);
    bufp->fullBit(oldp+100950,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___tlb_io_resp_pf_inst));
    bufp->fullBit(oldp+100951,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___tlb_io_resp_ae_inst));
    bufp->fullIData(oldp+100952,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_0_tag_vpn),27);
    bufp->fullBit(oldp+100953,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_0_tag_v));
    bufp->fullQData(oldp+100954,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_0_data_0),41);
    bufp->fullQData(oldp+100956,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_0_data_1),41);
    bufp->fullQData(oldp+100958,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_0_data_2),41);
    bufp->fullQData(oldp+100960,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_0_data_3),41);
    bufp->fullBit(oldp+100962,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_0_valid_0));
    bufp->fullBit(oldp+100963,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_0_valid_1));
    bufp->fullBit(oldp+100964,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_0_valid_2));
    bufp->fullBit(oldp+100965,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_0_valid_3));
    bufp->fullIData(oldp+100966,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_1_tag_vpn),27);
    bufp->fullBit(oldp+100967,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_1_tag_v));
    bufp->fullQData(oldp+100968,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_1_data_0),41);
    bufp->fullQData(oldp+100970,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_1_data_1),41);
    bufp->fullQData(oldp+100972,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_1_data_2),41);
    bufp->fullQData(oldp+100974,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_1_data_3),41);
    bufp->fullBit(oldp+100976,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_1_valid_0));
    bufp->fullBit(oldp+100977,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_1_valid_1));
    bufp->fullBit(oldp+100978,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_1_valid_2));
    bufp->fullBit(oldp+100979,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_1_valid_3));
    bufp->fullIData(oldp+100980,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_2_tag_vpn),27);
    bufp->fullBit(oldp+100981,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_2_tag_v));
    bufp->fullQData(oldp+100982,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_2_data_0),41);
    bufp->fullQData(oldp+100984,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_2_data_1),41);
    bufp->fullQData(oldp+100986,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_2_data_2),41);
    bufp->fullQData(oldp+100988,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_2_data_3),41);
    bufp->fullBit(oldp+100990,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_2_valid_0));
    bufp->fullBit(oldp+100991,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_2_valid_1));
    bufp->fullBit(oldp+100992,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_2_valid_2));
    bufp->fullBit(oldp+100993,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_2_valid_3));
    bufp->fullIData(oldp+100994,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_3_tag_vpn),27);
    bufp->fullBit(oldp+100995,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_3_tag_v));
    bufp->fullQData(oldp+100996,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_3_data_0),41);
    bufp->fullQData(oldp+100998,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_3_data_1),41);
    bufp->fullQData(oldp+101000,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_3_data_2),41);
    bufp->fullQData(oldp+101002,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_3_data_3),41);
    bufp->fullBit(oldp+101004,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_3_valid_0));
    bufp->fullBit(oldp+101005,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_3_valid_1));
    bufp->fullBit(oldp+101006,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_3_valid_2));
    bufp->fullBit(oldp+101007,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_3_valid_3));
    bufp->fullIData(oldp+101008,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_4_tag_vpn),27);
    bufp->fullBit(oldp+101009,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_4_tag_v));
    bufp->fullQData(oldp+101010,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_4_data_0),41);
    bufp->fullQData(oldp+101012,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_4_data_1),41);
    bufp->fullQData(oldp+101014,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_4_data_2),41);
    bufp->fullQData(oldp+101016,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_4_data_3),41);
    bufp->fullBit(oldp+101018,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_4_valid_0));
    bufp->fullBit(oldp+101019,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_4_valid_1));
    bufp->fullBit(oldp+101020,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_4_valid_2));
    bufp->fullBit(oldp+101021,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_4_valid_3));
    bufp->fullIData(oldp+101022,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_5_tag_vpn),27);
    bufp->fullBit(oldp+101023,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_5_tag_v));
    bufp->fullQData(oldp+101024,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_5_data_0),41);
    bufp->fullQData(oldp+101026,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_5_data_1),41);
    bufp->fullQData(oldp+101028,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_5_data_2),41);
    bufp->fullQData(oldp+101030,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_5_data_3),41);
    bufp->fullBit(oldp+101032,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_5_valid_0));
    bufp->fullBit(oldp+101033,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_5_valid_1));
    bufp->fullBit(oldp+101034,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_5_valid_2));
    bufp->fullBit(oldp+101035,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_5_valid_3));
    bufp->fullIData(oldp+101036,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_6_tag_vpn),27);
    bufp->fullBit(oldp+101037,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_6_tag_v));
    bufp->fullQData(oldp+101038,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_6_data_0),41);
    bufp->fullQData(oldp+101040,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_6_data_1),41);
    bufp->fullQData(oldp+101042,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_6_data_2),41);
    bufp->fullQData(oldp+101044,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_6_data_3),41);
    bufp->fullBit(oldp+101046,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_6_valid_0));
    bufp->fullBit(oldp+101047,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_6_valid_1));
    bufp->fullBit(oldp+101048,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_6_valid_2));
    bufp->fullBit(oldp+101049,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_6_valid_3));
    bufp->fullIData(oldp+101050,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_7_tag_vpn),27);
    bufp->fullBit(oldp+101051,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_7_tag_v));
    bufp->fullQData(oldp+101052,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_7_data_0),41);
    bufp->fullQData(oldp+101054,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_7_data_1),41);
    bufp->fullQData(oldp+101056,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_7_data_2),41);
    bufp->fullQData(oldp+101058,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_7_data_3),41);
    bufp->fullBit(oldp+101060,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_7_valid_0));
    bufp->fullBit(oldp+101061,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_7_valid_1));
    bufp->fullBit(oldp+101062,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_7_valid_2));
    bufp->fullBit(oldp+101063,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_7_valid_3));
    bufp->fullCData(oldp+101064,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_0_level),2);
    bufp->fullIData(oldp+101065,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_0_tag_vpn),27);
    bufp->fullBit(oldp+101066,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_0_tag_v));
    bufp->fullQData(oldp+101067,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_0_data_0),41);
    bufp->fullBit(oldp+101069,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_0_valid_0));
    bufp->fullCData(oldp+101070,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_1_level),2);
    bufp->fullIData(oldp+101071,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_1_tag_vpn),27);
    bufp->fullBit(oldp+101072,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_1_tag_v));
    bufp->fullQData(oldp+101073,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_1_data_0),41);
    bufp->fullBit(oldp+101075,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_1_valid_0));
    bufp->fullCData(oldp+101076,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_level),2);
    bufp->fullIData(oldp+101077,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_tag_vpn),27);
    bufp->fullBit(oldp+101078,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_tag_v));
    bufp->fullQData(oldp+101079,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_data_0),41);
    bufp->fullBit(oldp+101081,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_valid_0));
    bufp->fullCData(oldp+101082,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_level),2);
    bufp->fullIData(oldp+101083,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_tag_vpn),27);
    bufp->fullBit(oldp+101084,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_tag_v));
    bufp->fullQData(oldp+101085,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_data_0),41);
    bufp->fullBit(oldp+101087,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_valid_0));
    bufp->fullCData(oldp+101088,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__special_entry_level),2);
    bufp->fullIData(oldp+101089,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__special_entry_tag_vpn),27);
    bufp->fullBit(oldp+101090,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__special_entry_tag_v));
    bufp->fullQData(oldp+101091,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__special_entry_data_0),41);
    bufp->fullBit(oldp+101093,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__special_entry_valid_0));
    bufp->fullCData(oldp+101094,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__state),2);
    bufp->fullCData(oldp+101095,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__r_superpage_repl_addr),2);
    bufp->fullCData(oldp+101096,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__r_sectored_repl_addr),3);
    bufp->fullBit(oldp+101097,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__r_sectored_hit_valid));
    bufp->fullCData(oldp+101098,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__r_sectored_hit_bits),3);
    bufp->fullBit(oldp+101099,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__special_entry_level))));
    bufp->fullIData(oldp+101100,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn),28);
    bufp->fullCData(oldp+101101,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_priv),3);
    bufp->fullBit(oldp+101102,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__legal_address));
    bufp->fullBit(oldp+101103,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__deny_access_to_debug));
    bufp->fullBit(oldp+101104,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__newEntry_px));
    bufp->fullBit(oldp+101105,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_0_level))));
    bufp->fullBit(oldp+101106,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_1_level))));
    bufp->fullBit(oldp+101107,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_level))));
    bufp->fullBit(oldp+101108,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_level))));
    bufp->fullBit(oldp+101109,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_0));
    bufp->fullBit(oldp+101110,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_1));
    bufp->fullBit(oldp+101111,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_2));
    bufp->fullBit(oldp+101112,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_3));
    bufp->fullBit(oldp+101113,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_4));
    bufp->fullBit(oldp+101114,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_5));
    bufp->fullBit(oldp+101115,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_6));
    bufp->fullBit(oldp+101116,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_7));
    bufp->fullBit(oldp+101117,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_8));
    bufp->fullBit(oldp+101118,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_9));
    bufp->fullBit(oldp+101119,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_10));
    bufp->fullBit(oldp+101120,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_11));
    bufp->fullBit(oldp+101121,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_12));
    bufp->fullSData(oldp+101122,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__real_hits),13);
    bufp->fullBit(oldp+101123,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__bad_va));
    bufp->fullBit(oldp+101124,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__tlb_miss));
    bufp->fullCData(oldp+101125,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__state_vec_0),7);
    bufp->fullCData(oldp+101126,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__state_reg_1),3);
    bufp->fullBit(oldp+101127,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_1));
    bufp->fullBit(oldp+101128,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_leftOne_2));
    bufp->fullBit(oldp+101129,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_3));
    bufp->fullBit(oldp+101130,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_4));
    bufp->fullBit(oldp+101131,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_6));
    bufp->fullBit(oldp+101132,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_leftOne_8));
    bufp->fullBit(oldp+101133,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_leftOne_10));
    bufp->fullBit(oldp+101134,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_9));
    bufp->fullBit(oldp+101135,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_10));
    bufp->fullBit(oldp+101136,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__multipleHits));
    bufp->fullBit(oldp+101137,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_hits_1));
    bufp->fullBit(oldp+101138,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_hits_2));
    bufp->fullBit(oldp+101139,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_hits_3));
    bufp->fullCData(oldp+101140,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__hi_4),2);
    bufp->fullBit(oldp+101141,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__invalidate_refill));
    bufp->fullBit(oldp+101142,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__newEntry_c));
    bufp->fullBit(oldp+101143,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__newEntry_pr));
    bufp->fullBit(oldp+101144,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__newEntry_pw));
    bufp->fullBit(oldp+101145,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__newEntry_ppp));
    bufp->fullBit(oldp+101146,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__newEntry_pal));
    bufp->fullBit(oldp+101147,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__newEntry_paa));
    bufp->fullBit(oldp+101148,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__newEntry_eff));
    bufp->fullBit(oldp+101149,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sector_hits_0));
    bufp->fullBit(oldp+101150,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sector_hits_1));
    bufp->fullBit(oldp+101151,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sector_hits_2));
    bufp->fullBit(oldp+101152,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sector_hits_3));
    bufp->fullBit(oldp+101153,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sector_hits_4));
    bufp->fullBit(oldp+101154,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sector_hits_5));
    bufp->fullBit(oldp+101155,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sector_hits_6));
    bufp->fullBit(oldp+101156,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__sector_hits_7));
    bufp->fullBit(oldp+101157,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__refill_v));
    bufp->fullBit(oldp+101158,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__newEntry_g));
    bufp->fullBit(oldp+101159,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__newEntry_sr));
    bufp->fullBit(oldp+101160,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__newEntry_sw));
    bufp->fullBit(oldp+101161,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__newEntry_sx));
    bufp->fullCData(oldp+101162,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__waddr_1),3);
    bufp->fullCData(oldp+101163,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__hi_1),4);
    bufp->fullIData(oldp+101164,((0xfffffU & (IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_1 
                                                      >> 0x15U)))),20);
    bufp->fullBit(oldp+101165,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_1 
                                              >> 0x14U)))));
    bufp->fullBit(oldp+101166,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_1 
                                              >> 0x12U)))));
    bufp->fullBit(oldp+101167,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_1 
                                              >> 0x11U)))));
    bufp->fullBit(oldp+101168,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_1 
                                              >> 0x10U)))));
    bufp->fullBit(oldp+101169,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_1 
                                              >> 0xfU)))));
    bufp->fullBit(oldp+101170,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_1 
                                              >> 0xeU)))));
    bufp->fullBit(oldp+101171,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_1 
                                              >> 0xdU)))));
    bufp->fullBit(oldp+101172,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_1 
                                              >> 0xcU)))));
    bufp->fullBit(oldp+101173,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_1 
                                              >> 8U)))));
    bufp->fullBit(oldp+101174,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_1 
                                              >> 7U)))));
    bufp->fullBit(oldp+101175,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_1 
                                              >> 6U)))));
    bufp->fullBit(oldp+101176,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_1 
                                              >> 5U)))));
    bufp->fullBit(oldp+101177,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_1 
                                              >> 4U)))));
    bufp->fullBit(oldp+101178,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_1 
                                              >> 3U)))));
    bufp->fullBit(oldp+101179,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_1 
                                              >> 2U)))));
    bufp->fullBit(oldp+101180,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_1 
                                              >> 1U)))));
    bufp->fullIData(oldp+101181,((0xfffffU & (IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_3 
                                                      >> 0x15U)))),20);
    bufp->fullBit(oldp+101182,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_3 
                                              >> 0x14U)))));
    bufp->fullBit(oldp+101183,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_3 
                                              >> 0x12U)))));
    bufp->fullBit(oldp+101184,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_3 
                                              >> 0x11U)))));
    bufp->fullBit(oldp+101185,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_3 
                                              >> 0x10U)))));
    bufp->fullBit(oldp+101186,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_3 
                                              >> 0xfU)))));
    bufp->fullBit(oldp+101187,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_3 
                                              >> 0xeU)))));
    bufp->fullBit(oldp+101188,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_3 
                                              >> 0xdU)))));
    bufp->fullBit(oldp+101189,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_3 
                                              >> 0xcU)))));
    bufp->fullBit(oldp+101190,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_3 
                                              >> 8U)))));
    bufp->fullBit(oldp+101191,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_3 
                                              >> 7U)))));
    bufp->fullBit(oldp+101192,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_3 
                                              >> 6U)))));
    bufp->fullBit(oldp+101193,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_3 
                                              >> 5U)))));
    bufp->fullBit(oldp+101194,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_3 
                                              >> 4U)))));
    bufp->fullBit(oldp+101195,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_3 
                                              >> 3U)))));
    bufp->fullBit(oldp+101196,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_3 
                                              >> 2U)))));
    bufp->fullBit(oldp+101197,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___entries_WIRE_3 
                                              >> 1U)))));
    bufp->fullIData(oldp+101198,((0xfffffU & (IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_data_0 
                                                      >> 0x15U)))),20);
    bufp->fullBit(oldp+101199,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_data_0 
                                              >> 0x14U)))));
    bufp->fullBit(oldp+101200,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_data_0 
                                              >> 0x12U)))));
    bufp->fullBit(oldp+101201,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_data_0 
                                              >> 0x11U)))));
    bufp->fullBit(oldp+101202,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_data_0 
                                              >> 0x10U)))));
    bufp->fullBit(oldp+101203,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_data_0 
                                              >> 0xfU)))));
    bufp->fullBit(oldp+101204,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_data_0 
                                              >> 0xeU)))));
    bufp->fullBit(oldp+101205,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_data_0 
                                              >> 0xdU)))));
    bufp->fullBit(oldp+101206,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_data_0 
                                              >> 0xcU)))));
    bufp->fullBit(oldp+101207,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_data_0 
                                              >> 8U)))));
    bufp->fullBit(oldp+101208,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_data_0 
                                              >> 7U)))));
    bufp->fullBit(oldp+101209,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_data_0 
                                              >> 6U)))));
    bufp->fullBit(oldp+101210,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_data_0 
                                              >> 5U)))));
    bufp->fullBit(oldp+101211,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_data_0 
                                              >> 4U)))));
    bufp->fullBit(oldp+101212,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_data_0 
                                              >> 3U)))));
    bufp->fullBit(oldp+101213,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_data_0 
                                              >> 2U)))));
    bufp->fullBit(oldp+101214,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_2_data_0 
                                              >> 1U)))));
    bufp->fullIData(oldp+101215,((0xfffffU & (IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_data_0 
                                                      >> 0x15U)))),20);
    bufp->fullBit(oldp+101216,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_data_0 
                                              >> 0x14U)))));
    bufp->fullBit(oldp+101217,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_data_0 
                                              >> 0x12U)))));
    bufp->fullBit(oldp+101218,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_data_0 
                                              >> 0x11U)))));
    bufp->fullBit(oldp+101219,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_data_0 
                                              >> 0x10U)))));
    bufp->fullBit(oldp+101220,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_data_0 
                                              >> 0xfU)))));
    bufp->fullBit(oldp+101221,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_data_0 
                                              >> 0xeU)))));
    bufp->fullBit(oldp+101222,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_data_0 
                                              >> 0xdU)))));
    bufp->fullBit(oldp+101223,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_data_0 
                                              >> 0xcU)))));
    bufp->fullBit(oldp+101224,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_data_0 
                                              >> 8U)))));
    bufp->fullBit(oldp+101225,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_data_0 
                                              >> 7U)))));
    bufp->fullBit(oldp+101226,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_data_0 
                                              >> 6U)))));
    bufp->fullBit(oldp+101227,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_data_0 
                                              >> 5U)))));
    bufp->fullBit(oldp+101228,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_data_0 
                                              >> 4U)))));
    bufp->fullBit(oldp+101229,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_data_0 
                                              >> 3U)))));
    bufp->fullBit(oldp+101230,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_data_0 
                                              >> 2U)))));
    bufp->fullBit(oldp+101231,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__superpage_entries_3_data_0 
                                              >> 1U)))));
    bufp->fullIData(oldp+101232,((0xfffffU & (IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__special_entry_data_0 
                                                      >> 0x15U)))),20);
    bufp->fullBit(oldp+101233,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__special_entry_data_0 
                                              >> 0x14U)))));
}
